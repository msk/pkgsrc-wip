$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/live_caption/caption_util.cc.orig	2024-12-03 23:30:15.903402300 +0000
+++ components/live_caption/caption_util.cc
@@ -139,7 +139,7 @@ std::string GetCaptionSettingsUrl() {
   return "chrome://os-settings/audioAndCaptions";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "chrome://settings/captions";
 #endif  // BUILDFLAG(IS_LINUX)
 
