$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_connection.cc.orig	2024-12-03 23:30:51.861617600 +0000
+++ ui/ozone/platform/wayland/host/wayland_connection.cc
@@ -541,7 +541,7 @@ bool WaylandConnection::ShouldUseOverlay
   // isn't present on any non-exo Wayland compositors.
   bool should_use_overlay_delegation =
       IsWaylandOverlayDelegationEnabled() && !fractional_scale_manager_v1();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Overlay delegation also requires a single-pixel-buffer protocol, which
   // allows creation of non-backed solid color buffers. Even though only video
   // overlays can be supported on Linux, these color buffers are still needed
