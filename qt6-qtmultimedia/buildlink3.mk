# $NetBSD$

BUILDLINK_TREE+=	qt6-qtmultimedia

.if !defined(QT6_QTMULTIMEDIA_BUILDLINK3_MK)
QT6_QTMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtmultimedia+=	qt6-qtmultimedia>=6.3.1
BUILDLINK_PKGSRCDIR.qt6-qtmultimedia?=		../../wip/qt6-qtmultimedia

pkgbase := qt6-qtmultimedia
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.qt6-qtmultimedia:Mgstreamer)
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.qt6-qtmultimedia:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.endif	# QT6_QTMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtmultimedia
