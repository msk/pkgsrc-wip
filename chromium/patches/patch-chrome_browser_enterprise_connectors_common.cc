$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/common.cc.orig	2024-12-03 23:30:09.064790700 +0000
+++ chrome/browser/enterprise/connectors/common.cc
@@ -23,7 +23,7 @@
 #include "components/policy/core/common/policy_loader_lacros.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -266,7 +266,7 @@ std::string GetProfileEmail(Profile* pro
   std::string email =
       GetProfileEmail(IdentityManagerFactory::GetForProfile(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (email.empty()) {
     email = profile->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserEmail);
