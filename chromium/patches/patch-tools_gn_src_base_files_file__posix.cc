$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/src/base/files/file_posix.cc.orig	2024-12-03 23:45:36.769922700 +0000
+++ tools/gn/src/base/files/file_posix.cc
@@ -359,7 +359,7 @@ void File::DoInitialize(const FilePath& 
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
