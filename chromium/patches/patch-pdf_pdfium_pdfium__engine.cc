$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdfium/pdfium_engine.cc.orig	2024-12-03 23:30:24.952211400 +0000
+++ pdf/pdfium/pdfium_engine.cc
@@ -99,7 +99,7 @@
 #include "ui/accessibility/ax_features.mojom-features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -528,7 +528,7 @@ void InitializeSDK(bool enable_v8,
 
   FPDF_InitLibraryWithConfig(&config);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   g_font_mapping_mode = font_mapping_mode;
   InitializeLinuxFontMapper();
 #endif
