$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc.orig	2024-12-03 23:30:11.947048400 +0000
+++ chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc
@@ -162,7 +162,7 @@ CertificateManagerPageHandler::GetCertSo
             "distrusted_certs",
             cert_verifier::mojom::CertificateTrust::kDistrusted);
         break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       case certificate_manager_v2::mojom::CertificateSource::
           kProvisionedClientCert:
         source_ptr = CreateProvisionedClientCertSource(profile_);
