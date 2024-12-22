$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/headless/vulkan_implementation_headless.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/headless/vulkan_implementation_headless.cc
@@ -118,7 +118,7 @@ VulkanImplementationHeadless::ExportVkFe
 
 VkExternalSemaphoreHandleTypeFlagBits
 VulkanImplementationHeadless::GetExternalSemaphoreHandleType() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT;
 #else
   return VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT;
@@ -128,7 +128,7 @@ VulkanImplementationHeadless::GetExterna
 bool VulkanImplementationHeadless::CanImportGpuMemoryBuffer(
     gpu::VulkanDeviceQueue* device_queue,
     gfx::GpuMemoryBufferType memory_buffer_type) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const auto& enabled_extensions = device_queue->enabled_extensions();
   return gfx::HasExtension(enabled_extensions,
                            VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME) &&
@@ -151,7 +151,7 @@ VulkanImplementationHeadless::CreateImag
       VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT |
       VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
   auto tiling = VK_IMAGE_TILING_OPTIMAL;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (gmb_handle.native_pixmap_handle.modifier !=
       gfx::NativePixmapHandle::kNoModifier) {
     tiling = VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT;
