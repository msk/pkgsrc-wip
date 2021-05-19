# $NetBSD$

BUILDLINK_TREE+=	biolibc

.if !defined(BIOLIBC_BUILDLINK3_MK)
BIOLIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.biolibc+=	biolibc>=0.1.2
BUILDLINK_PKGSRCDIR.biolibc?=	../../wip/biolibc
.endif	# BIOLIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-biolibc
