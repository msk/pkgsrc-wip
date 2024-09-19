# $NetBSD: options.mk,v 1.2 2013/06/08 13:07:45 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcsplit
PKG_SUPPORTED_OPTIONS=	nls static wide-curses
PKG_SUGGESTED_OPTIONS+=	nls static wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-shared=no
.else
CONFIGURE_ARGS+=	--enable-shared=yes
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-wide-character-type
.endif
