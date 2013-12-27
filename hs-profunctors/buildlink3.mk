# $NetBSD: buildlink3.mk,v 1.3 2013/12/27 22:08:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-profunctors

.if !defined(HS_PROFUNCTORS_BUILDLINK3_MK)
HS_PROFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-profunctors+=	hs-profunctors>=4.0.2
BUILDLINK_PKGSRCDIR.hs-profunctors?=	../../wip/hs-profunctors

.include "../../wip/hs-comonad/buildlink3.mk"
.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_PROFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-profunctors
