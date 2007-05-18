# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/05/18 12:28:30 emil_s Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HS_X11_BUILDLINK3_MK:=	${HS_X11_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-x11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-x11}
BUILDLINK_PACKAGES+=	hs-x11
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-x11

.if ${HS_X11_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-x11?=	build
BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11>=1.2
BUILDLINK_PKGSRCDIR.hs-x11?=	../../wip/hs-x11
.endif	# HS_X11_BUILDLINK3_MK

.include "../../lang/ghc/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
