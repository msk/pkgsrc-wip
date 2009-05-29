# $NetBSD: options.mk,v 1.3 2009/05/29 13:29:21 x400 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.callweaver
PKG_SUPPORTED_OPTIONS=	mysql pgsql sipsecurity

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mysql pgsql sipsecurity

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql5-client/buildlink3.mk"
PLIST.mysql=		yes
CONFIGURE_ARGS+=	--enable-mysql --with-app_sql_mysql --with-cdr_mysql --with-res_config_mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/postgresql83-client/buildlink3.mk"
PLIST.pgsql=		yes
CONFIGURE_ARGS+=	--enable-postgresql --with-app_sql_postgres --with-cdr_pgsql --with-res_config_pgsql
.endif

.if !empty(PKG_OPTIONS:Msipsecurity)
PLIST.sipsecurity=	yes
CONFIGURE_ARGS+=	--enable-sip-tcp-support --enable-srtp
.endif
