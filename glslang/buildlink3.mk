# $NetBSD$

BUILDLINK_TREE+=	glslang

.if !defined(GLSLANG_BUILDLINK3_MK)
GLSLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glslang+=	glslang>=15.0.0
BUILDLINK_PKGSRCDIR.glslang?=	../../wip/glslang

.endif	# GLSLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glslang
