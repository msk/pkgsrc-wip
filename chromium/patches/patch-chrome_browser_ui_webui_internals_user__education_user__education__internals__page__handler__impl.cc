$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/internals/user_education/user_education_internals_page_handler_impl.cc.orig	2024-12-03 23:30:11.972050700 +0000
+++ chrome/browser/ui/webui/internals/user_education/user_education_internals_page_handler_impl.cc
@@ -44,7 +44,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/resource_path.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_navigator_params.h"
 #include "net/base/url_util.h"
@@ -84,7 +84,7 @@ user_education::NewBadgeRegistry* GetNew
 }
 
 whats_new::WhatsNewRegistry* GetWhatsNewRegistry() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process->GetFeatures()->whats_new_registry();
 #else
   return nullptr;
@@ -767,7 +767,7 @@ void UserEducationInternalsPageHandlerIm
 }
 
 void UserEducationInternalsPageHandlerImpl::LaunchWhatsNewStaging() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GURL url = net::AppendQueryParameter(GURL(chrome::kChromeUIWhatsNewURL),
                                        "staging", "true");
   NavigateParams params(profile_, url, ui::PAGE_TRANSITION_TYPED);
