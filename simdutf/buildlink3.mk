# $NetBSD$

BUILDLINK_TREE+=	simdutf

.if !defined(SIMDUTF_BUILDLINK3_MK)
SIMDUTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simdutf+=	simdutf>=4.0.4
BUILDLINK_PKGSRCDIR.simdutf?=	../../wip/simdutf

.endif	# SIMDUTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-simdutf
