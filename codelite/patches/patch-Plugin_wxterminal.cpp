$NetBSD$

--- Plugin/wxterminal.cpp.orig	2016-01-30 10:49:18.000000000 +0000
+++ Plugin/wxterminal.cpp
@@ -39,7 +39,7 @@
 #define SHELL_WRAPPER wxT("")
 #else
 
-#if defined(__WXMAC__) || defined(__FreeBSD__)
+#if defined(__WXMAC__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
@@ -55,6 +55,10 @@
 #include <sys/ioctl.h>
 #include <termios.h>
 #include <libutil.h>
+#elif defined(__NetBSD__)
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <util.h>
 #else
 #include <pty.h>
 #endif
