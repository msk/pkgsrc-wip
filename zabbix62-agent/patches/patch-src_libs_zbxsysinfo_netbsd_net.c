$NetBSD: patch-src_libs_zbxsysinfo_netbsd_net.c,v 1.1 2020/11/03 22:44:43 otis Exp $

Rework interface statistics code from using kvm to using sysctl interface.

--- src/libs/zbxsysinfo/netbsd/net.c.orig	2021-10-25 09:49:27.000000000 +0000
+++ src/libs/zbxsysinfo/netbsd/net.c
@@ -22,14 +22,25 @@
 #include "zbxjson.h"
 #include "log.h"
 
-static struct nlist kernel_symbols[] =
+#include <net/route.h>
+#include <net/if_dl.h>
+
+static void get_rtaddrs(int, struct sockaddr *, struct sockaddr **);
+
+static void
+get_rtaddrs(int addrs, struct sockaddr *sa, struct sockaddr **rti_info)
 {
-	{"_ifnet", N_UNDF, 0, 0, 0},
-	{"_tcbtable", N_UNDF, 0, 0, 0},
-	{NULL, 0, 0, 0, 0}
-};
+	int i;
 
-#define IFNET_ID 0
+	for (i = 0; i < RTAX_MAX; i++) {
+		if (addrs & (1 << i)) {
+			rti_info[i] = sa;
+			sa = (struct sockaddr *)((char *)(sa) +
+					RT_ROUNDUP(sa->sa_len));
+		} else
+			rti_info[i] = NULL;
+	}
+}
 
 static int	get_ifdata(const char *if_name,
 		zbx_uint64_t *ibytes, zbx_uint64_t *ipackets, zbx_uint64_t *ierrors, zbx_uint64_t *idropped,
@@ -37,12 +48,19 @@ static int	get_ifdata(const char *if_nam
 		zbx_uint64_t *tbytes, zbx_uint64_t *tpackets, zbx_uint64_t *terrors,
 		zbx_uint64_t *icollisions, char **error)
 {
-	struct ifnet_head	head;
-	struct ifnet		*ifp;
-	struct ifnet		v;
+	struct  if_msghdr *ifm;
+	int     mib[6] = { CTL_NET, AF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
+	static char *buf;
+	char    *lim, *next;
+	struct  rt_msghdr *rtm;
+	struct  if_data *ifd = NULL;
+	struct  sockaddr *sa, *rti_info[RTAX_MAX];
+	struct  sockaddr_dl *sdl;
 
-	kvm_t	*kp;
+	size_t  len = 0;
+	static size_t olen;
 	int	ret = SYSINFO_RET_FAIL;
+	static char name[IFNAMSIZ];
 
 	if (NULL == if_name || '\0' == *if_name)
 	{
@@ -50,32 +68,60 @@ static int	get_ifdata(const char *if_nam
 		return FAIL;
 	}
 
-	if (NULL == (kp = kvm_open(NULL, NULL, NULL, O_RDONLY, NULL))) /* requires root privileges */
-	{
-		*error = zbx_strdup(NULL, "Cannot obtain a descriptor to access kernel virtual memory.");
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
+		*error = zbx_strdup(NULL, "Failed to read network interfaces data");
 		return FAIL;
 	}
 
-	if (N_UNDF == kernel_symbols[IFNET_ID].n_type)
-		if (0 != kvm_nlist(kp, &kernel_symbols[0]))
-			kernel_symbols[IFNET_ID].n_type = N_UNDF;
-
-	if (N_UNDF != kernel_symbols[IFNET_ID].n_type)
-	{
-		int	len = sizeof(struct ifnet_head);
+	if (len > olen) {
+		if (buf)
+			free(buf);
+		if ((buf = zbx_malloc(NULL, len)) == NULL) {
+			*error = zbx_strdup(NULL, "Failed to allocate buffer for network interfaces data");
+			return FAIL;
+		}
+		olen = len;
+	}
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
+		*error = zbx_strdup(NULL, "Failed to allocate buffer for network interfaces data");
+		return FAIL;
+	}
 
-		if (kvm_read(kp, kernel_symbols[IFNET_ID].n_value, &head, len) >= len)
+	lim = buf + len;
+	for (next = buf; next < lim; next += rtm->rtm_msglen) {
+		rtm = (struct rt_msghdr *)next;
+		if ((rtm->rtm_version == RTM_VERSION) &&
+			(rtm->rtm_type == RTM_IFINFO))
 		{
-			len = sizeof(struct ifnet);
+			ifm = (struct if_msghdr *)next;
+			ifd = &ifm->ifm_data;
+
+			sa = (struct sockaddr *)(ifm + 1);
+			get_rtaddrs(ifm->ifm_addrs, sa, rti_info);
 
-			/* if_ibytes;		total number of octets received */
-			/* if_ipackets;		packets received on interface */
-			/* if_ierrors;		input errors on interface */
-			/* if_iqdrops;		dropped on input, this interface */
-			/* if_obytes;		total number of octets sent */
-			/* if_opackets;		packets sent on interface */
-			/* if_oerrors;		output errors on interface */
-			/* if_collisions;	collisions on csma interfaces */
+			sdl = (struct sockaddr_dl *)rti_info[RTAX_IFP];
+			if (sdl == NULL || sdl->sdl_family != AF_LINK) {
+				continue;
+			}
+			bzero(name, sizeof(name));
+			if (sdl->sdl_nlen >= IFNAMSIZ)
+				memcpy(name, sdl->sdl_data, IFNAMSIZ - 1);
+			else if (sdl->sdl_nlen > 0)
+				memcpy(name, sdl->sdl_data, sdl->sdl_nlen);
+			else
+				continue;
+
+			/* ibytes;		total number of octets received */
+			/* ipackets;		packets received on interface */
+			/* ierrors;		input errors on interface */
+			/* iqdrops;		dropped on input, this interface */
+			/* obytes;		total number of octets sent */
+			/* opackets;		packets sent on interface */
+			/* oerrors;		output errors on interface */
+			/* icollisions;		collisions on csma interfaces */
+			/* tbytes;              total (in+out) bytes */
+			/* tpackets;            total (in+out) packets */
+			/* terrors;             total (in+out) errors */
 
 			if (ibytes)
 				*ibytes = 0;
@@ -100,42 +146,39 @@ static int	get_ifdata(const char *if_nam
 			if (icollisions)
 				*icollisions = 0;
 
-			for (ifp = head.tqh_first; ifp; ifp = v.if_list.tqe_next)
+			if (0 == strcmp(if_name, name))
 			{
-				if (kvm_read(kp, (u_long)ifp, &v, len) < len)
-					break;
+				if (ibytes)
+					*ibytes += ifd->ifi_ibytes;
+				if (ipackets)
+					*ipackets += ifd->ifi_ipackets;
+				if (ierrors)
+					*ierrors += ifd->ifi_ierrors;
+				if (idropped)
+					*idropped += ifd->ifi_iqdrops;
+				if (obytes)
+					*obytes += ifd->ifi_obytes;
+				if (opackets)
+					*opackets += ifd->ifi_opackets;
+				if (oerrors)
+					*oerrors += ifd->ifi_oerrors;
+				if (tbytes)
+					*tbytes += ifd->ifi_ibytes +
+						ifd->ifi_obytes;
+				if (tpackets)
+					*tpackets += ifd->ifi_ipackets +
+						ifd->ifi_opackets;
+				if (terrors)
+					*terrors += ifd->ifi_ierrors +
+						ifd->ifi_oerrors;
+				if (icollisions)
+					*icollisions += ifd->ifi_collisions;
 
-				if (0 == strcmp(if_name, v.if_xname))
-				{
-					if (ibytes)
-						*ibytes += v.if_ibytes;
-					if (ipackets)
-						*ipackets += v.if_ipackets;
-					if (ierrors)
-						*ierrors += v.if_ierrors;
-					if (idropped)
-						*idropped += v.if_iqdrops;
-					if (obytes)
-						*obytes += v.if_obytes;
-					if (opackets)
-						*opackets += v.if_opackets;
-					if (oerrors)
-						*oerrors += v.if_oerrors;
-					if (tbytes)
-						*tbytes += v.if_ibytes + v.if_obytes;
-					if (tpackets)
-						*tpackets += v.if_ipackets + v.if_opackets;
-					if (terrors)
-						*terrors += v.if_ierrors + v.if_oerrors;
-					if (icollisions)
-						*icollisions += v.if_collisions;
-					ret = SYSINFO_RET_OK;
-				}
+				return SYSINFO_RET_OK;
 			}
 		}
 	}
 
-	kvm_close(kp);
 
 	if (SYSINFO_RET_FAIL == ret)
 	{
