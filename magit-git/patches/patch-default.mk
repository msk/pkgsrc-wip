$NetBSD$

1. makeinfo unknown option css-ref

2. adjust ELPA package to pkgsrc (DASH_DIR)

3. set INSTALL_INFO

--- default.mk.orig	2024-12-07 07:14:31.000000000 +0900
+++ default.mk	2024-12-30 06:30:25.917649857 +0900
@@ -34,8 +34,10 @@ BATCH       = $(EMACS) -Q --batch $(EMAC
 LISP_EXTRA_TARGETS ?= check-declare
 
 INSTALL_INFO     ?= $(shell command -v ginstall-info || printf install-info)
+INSTALL_INFO	= install-info
 MAKEINFO         ?= makeinfo
 MANUAL_HTML_ARGS ?= --css-ref /assets/page.css
+MANUAL_HTML_ARGS =
 
 GITSTATS      ?= gitstats
 GITSTATS_DIR  ?= $(TOP)docs/stats
@@ -151,6 +153,7 @@ DASH_DIR ?= $(shell \
 ifeq "$(DASH_DIR)" ""
   DASH_DIR = $(TOP)../dash
 endif
+DASH_DIR = @@PREFIX@@/share/emacs/site-lisp/dash
 
 SEQ_DIR ?= $(shell \
   find -L $(ELPA_DIR) -maxdepth 1 -regex '.*/seq-[.0-9]*' 2> /dev/null | \
@@ -172,6 +175,7 @@ WITH_EDITOR_DIR ?= $(shell \
 ifeq "$(WITH_EDITOR_DIR)" ""
   WITH_EDITOR_DIR = $(TOP)../with-editor/lisp
 endif
+WITH_EDITOR_DIR = @@PREFIX@@/share/emacs/site-lisp/with-editor
 
 MAGIT_SECTION_DIR ?= $(shell \
   find -L $(ELPA_DIR) -maxdepth 1 -regex '.*/magit-section-[.0-9]*' 2> /dev/null | \
