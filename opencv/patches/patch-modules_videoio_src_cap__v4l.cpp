$NetBSD: patch-modules_videoio_src_cap__v4l.cpp,v 1.9 2021/10/16 07:16:29 adam Exp $

Conditionalize settings not available in NetBSD's v4l2 emulation.
Avoid non-standard integer types.

--- modules/videoio/src/cap_v4l.cpp.orig	2022-12-28 14:31:52.000000000 +0000
+++ modules/videoio/src/cap_v4l.cpp
@@ -215,6 +215,14 @@ make & enjoy!
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <inttypes.h>
+#include <stdint.h>
+#ifndef __u32
+#define __u32 uint32_t
+#endif
+#ifndef __s32
+#define __s32 int32_t
+#endif
 #include <sys/types.h>
 #include <sys/mman.h>
 
@@ -241,24 +249,30 @@ typedef uint32_t __u32;
 #endif
 
 // https://github.com/opencv/opencv/issues/13335
+#ifdef V4L2_CID_CAMERA_CLASS_BASE
 #ifndef V4L2_CID_ISO_SENSITIVITY
 #define V4L2_CID_ISO_SENSITIVITY (V4L2_CID_CAMERA_CLASS_BASE+23)
 #endif
+#endif
 
 // https://github.com/opencv/opencv/issues/13929
+#ifdef V4L2_CID_MPEG_BASE
 #ifndef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT
 #define V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT (V4L2_CID_MPEG_BASE+364)
 #endif
 #ifndef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH
 #define V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH (V4L2_CID_MPEG_BASE+365)
 #endif
+#endif
 
 #ifndef V4L2_CID_ROTATE
 #define V4L2_CID_ROTATE (V4L2_CID_BASE+34)
 #endif
+#ifdef V4L2_CID_CAMERA_CLASS_BASE
 #ifndef V4L2_CID_IRIS_ABSOLUTE
 #define V4L2_CID_IRIS_ABSOLUTE (V4L2_CID_CAMERA_CLASS_BASE+17)
 #endif
+#endif
 
 #ifndef V4L2_PIX_FMT_Y10
 #define V4L2_PIX_FMT_Y10 v4l2_fourcc('Y', '1', '0', ' ')
@@ -665,9 +679,13 @@ bool CvCaptureCAM_V4L::convertableToRgb(
     case V4L2_PIX_FMT_UYVY:
     case V4L2_PIX_FMT_SBGGR8:
     case V4L2_PIX_FMT_SN9C10X:
+#ifdef V4L2_PIX_FMT_SGBRG8
     case V4L2_PIX_FMT_SGBRG8:
+#endif
     case V4L2_PIX_FMT_RGB24:
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
+#endif
     case V4L2_PIX_FMT_Y10:
     case V4L2_PIX_FMT_GREY:
     case V4L2_PIX_FMT_BGR24:
@@ -715,7 +733,9 @@ void CvCaptureCAM_V4L::v4l2_create_frame
             channels = 1;
             size.height = size.height * 3 / 2; // "1.5" channels
             break;
+#ifdef V4L2_PIX_FMT_Y16
         case V4L2_PIX_FMT_Y16:
+#endif
         case V4L2_PIX_FMT_Y12:
         case V4L2_PIX_FMT_Y10:
             depth = IPL_DEPTH_16U;
@@ -1729,6 +1749,7 @@ void CvCaptureCAM_V4L::convertToRgb(cons
     case V4L2_PIX_FMT_RGB24:
         cv::cvtColor(cv::Mat(imageSize, CV_8UC3, start), destination, COLOR_RGB2BGR);
         return;
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
     {
         cv::Mat temp(imageSize, CV_8UC1, buffers[MAX_V4L_BUFFERS].memories[MEMORY_RGB].start);
@@ -1750,6 +1771,7 @@ void CvCaptureCAM_V4L::convertToRgb(cons
         cv::cvtColor(temp, destination, COLOR_GRAY2BGR);
         return;
     }
+#endif
     case V4L2_PIX_FMT_GREY:
         cv::cvtColor(cv::Mat(imageSize, CV_8UC1, start), destination, COLOR_GRAY2BGR);
         break;
@@ -1866,8 +1888,10 @@ static inline int capPropertyToV4L2(int 
         return -1;
     case cv::CAP_PROP_FOURCC:
         return -1;
+#ifdef V4L2_CID_MPEG_VIDEO_B_FRAMES
     case cv::CAP_PROP_FRAME_COUNT:
         return V4L2_CID_MPEG_VIDEO_B_FRAMES;
+#endif
     case cv::CAP_PROP_FORMAT:
         return -1;
     case cv::CAP_PROP_MODE:
@@ -1882,8 +1906,10 @@ static inline int capPropertyToV4L2(int 
         return V4L2_CID_HUE;
     case cv::CAP_PROP_GAIN:
         return V4L2_CID_GAIN;
+#ifdef V4L2_CID_EXPOSURE_ABSOLUTE
     case cv::CAP_PROP_EXPOSURE:
         return V4L2_CID_EXPOSURE_ABSOLUTE;
+#endif
     case cv::CAP_PROP_CONVERT_RGB:
         return -1;
     case cv::CAP_PROP_WHITE_BALANCE_BLUE_U:
@@ -1894,8 +1920,10 @@ static inline int capPropertyToV4L2(int 
         return -1;
     case cv::CAP_PROP_SHARPNESS:
         return V4L2_CID_SHARPNESS;
+#ifdef V4L2_CID_EXPOSURE_AUTO
     case cv::CAP_PROP_AUTO_EXPOSURE:
         return V4L2_CID_EXPOSURE_AUTO;
+#endif
     case cv::CAP_PROP_GAMMA:
         return V4L2_CID_GAMMA;
     case cv::CAP_PROP_TEMPERATURE:
@@ -1906,34 +1934,54 @@ static inline int capPropertyToV4L2(int 
         return -1;
     case cv::CAP_PROP_WHITE_BALANCE_RED_V:
         return V4L2_CID_RED_BALANCE;
+#ifdef V4L2_CID_ZOOM_ABSOLUTE
     case cv::CAP_PROP_ZOOM:
         return V4L2_CID_ZOOM_ABSOLUTE;
+#endif
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
     case cv::CAP_PROP_FOCUS:
         return V4L2_CID_FOCUS_ABSOLUTE;
+#endif
     case cv::CAP_PROP_GUID:
         return -1;
+#ifdef V4L2_CID_ISO_SENSITIVITY
     case cv::CAP_PROP_ISO_SPEED:
         return V4L2_CID_ISO_SENSITIVITY;
+#endif
     case cv::CAP_PROP_BACKLIGHT:
         return V4L2_CID_BACKLIGHT_COMPENSATION;
+#ifdef V4L2_CID_PAN_ABSOLUTE
     case cv::CAP_PROP_PAN:
         return V4L2_CID_PAN_ABSOLUTE;
+#endif
+#ifdef V4L2_CID_TILT_ABSOLUTE
     case cv::CAP_PROP_TILT:
         return V4L2_CID_TILT_ABSOLUTE;
+#endif
+#ifdef V4L2_CID_ROTATE
     case cv::CAP_PROP_ROLL:
         return V4L2_CID_ROTATE;
+#endif
+#ifdef V4L2_CID_IRIS_ABSOLUTE
     case cv::CAP_PROP_IRIS:
         return V4L2_CID_IRIS_ABSOLUTE;
+#endif
     case cv::CAP_PROP_SETTINGS:
         return -1;
     case cv::CAP_PROP_BUFFERSIZE:
         return -1;
+#ifdef V4L2_CID_FOCUS_AUTO
     case cv::CAP_PROP_AUTOFOCUS:
         return V4L2_CID_FOCUS_AUTO;
+#endif
+#ifdef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT
     case cv::CAP_PROP_SAR_NUM:
         return V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT;
+#endif
+#ifdef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH
     case cv::CAP_PROP_SAR_DEN:
         return V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH;
+#endif
     case CAP_PROP_AUTO_WB:
         return V4L2_CID_AUTO_WHITE_BALANCE;
     case CAP_PROP_WB_TEMPERATURE:
