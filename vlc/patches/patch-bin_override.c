$NetBSD: patch-bin_override.c,v 1.2 2015/07/05 12:38:39 idleroux Exp $

--- bin/override.c.orig	2014-06-14 15:14:12.000000000 +0000
+++ bin/override.c
@@ -27,7 +27,7 @@
 
 void vlc_enable_override (void);
 
-#if defined (__GNUC__) \
+#if 0 && defined (__GNUC__) \
  && (defined (__ELF__) && !defined (__sun__))
 /* Solaris crashes on printf("%s", NULL); which is legal, but annoying. */
 
