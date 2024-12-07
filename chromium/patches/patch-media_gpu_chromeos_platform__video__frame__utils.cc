$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/platform_video_frame_utils.cc.orig	2024-12-03 23:30:23.192054000 +0000
+++ media/gpu/chromeos/platform_video_frame_utils.cc
@@ -67,7 +67,7 @@ static std::unique_ptr<ui::GbmDevice> Cr
     const base::FilePath dev_path(FILE_PATH_LITERAL(
         base::StrCat({drm_node_file_prefix, base::NumberToString(i)})));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
     const bool is_render_node = base::Contains(drm_node_file_prefix, "render");
 
     // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
