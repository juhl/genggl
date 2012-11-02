/*********************************************************************************************
 *
 * gwgl.h
 * ggl (OpenGL glue code library)
 * Version: 0.1.1
 *
 * Copyright 2011 Ju Hyung Lee. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list
 *        of conditions and the following disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY JU HYUNG LEE ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL JU HYUNG LEE OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Ju Hyung Lee.
 *
 ***********************************************************************************************/

#ifndef __GWGL_H__
#define __GWGL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>
#include <gl/gl.h>

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef WGL_ARB_buffer_region
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB                   0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB                    0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB                         0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB                       0x00000008
#endif

#ifndef WGL_ARB_multisample
#define WGL_SAMPLE_BUFFERS_ARB                           0x2041
#define WGL_SAMPLES_ARB                                  0x2042
#endif

#ifndef WGL_ARB_extensions_string
#endif

#ifndef WGL_ARB_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_ARB                     0x2000
#define WGL_DRAW_TO_WINDOW_ARB                           0x2001
#define WGL_DRAW_TO_BITMAP_ARB                           0x2002
#define WGL_ACCELERATION_ARB                             0x2003
#define WGL_NEED_PALETTE_ARB                             0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB                      0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB                       0x2006
#define WGL_SWAP_METHOD_ARB                              0x2007
#define WGL_NUMBER_OVERLAYS_ARB                          0x2008
#define WGL_NUMBER_UNDERLAYS_ARB                         0x2009
#define WGL_TRANSPARENT_ARB                              0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB                    0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB                  0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB                   0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB                  0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB                  0x203B
#define WGL_SHARE_DEPTH_ARB                              0x200C
#define WGL_SHARE_STENCIL_ARB                            0x200D
#define WGL_SHARE_ACCUM_ARB                              0x200E
#define WGL_SUPPORT_GDI_ARB                              0x200F
#define WGL_SUPPORT_OPENGL_ARB                           0x2010
#define WGL_DOUBLE_BUFFER_ARB                            0x2011
#define WGL_STEREO_ARB                                   0x2012
#define WGL_PIXEL_TYPE_ARB                               0x2013
#define WGL_COLOR_BITS_ARB                               0x2014
#define WGL_RED_BITS_ARB                                 0x2015
#define WGL_RED_SHIFT_ARB                                0x2016
#define WGL_GREEN_BITS_ARB                               0x2017
#define WGL_GREEN_SHIFT_ARB                              0x2018
#define WGL_BLUE_BITS_ARB                                0x2019
#define WGL_BLUE_SHIFT_ARB                               0x201A
#define WGL_ALPHA_BITS_ARB                               0x201B
#define WGL_ALPHA_SHIFT_ARB                              0x201C
#define WGL_ACCUM_BITS_ARB                               0x201D
#define WGL_ACCUM_RED_BITS_ARB                           0x201E
#define WGL_ACCUM_GREEN_BITS_ARB                         0x201F
#define WGL_ACCUM_BLUE_BITS_ARB                          0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB                         0x2021
#define WGL_DEPTH_BITS_ARB                               0x2022
#define WGL_STENCIL_BITS_ARB                             0x2023
#define WGL_AUX_BUFFERS_ARB                              0x2024
#define WGL_NO_ACCELERATION_ARB                          0x2025
#define WGL_GENERIC_ACCELERATION_ARB                     0x2026
#define WGL_FULL_ACCELERATION_ARB                        0x2027
#define WGL_SWAP_EXCHANGE_ARB                            0x2028
#define WGL_SWAP_COPY_ARB                                0x2029
#define WGL_SWAP_UNDEFINED_ARB                           0x202A
#define WGL_TYPE_RGBA_ARB                                0x202B
#define WGL_TYPE_COLORINDEX_ARB                          0x202C
#endif

#ifndef WGL_ARB_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_ARB                     0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB           0x2054
#endif

#ifndef WGL_ARB_pbuffer
#define WGL_DRAW_TO_PBUFFER_ARB                          0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB                       0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB                        0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB                       0x2030
#define WGL_PBUFFER_LARGEST_ARB                          0x2033
#define WGL_PBUFFER_WIDTH_ARB                            0x2034
#define WGL_PBUFFER_HEIGHT_ARB                           0x2035
#define WGL_PBUFFER_LOST_ARB                             0x2036
#define WGL_TRANSPARENT_RED_VALUE_ARB                    0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB                  0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB                   0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB                  0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB                  0x203B
#endif

#ifndef WGL_ARB_render_texture
#define WGL_BIND_TO_TEXTURE_RGB_ARB                      0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB                     0x2071
#define WGL_TEXTURE_FORMAT_ARB                           0x2072
#define WGL_TEXTURE_TARGET_ARB                           0x2073
#define WGL_MIPMAP_TEXTURE_ARB                           0x2074
#define WGL_TEXTURE_RGB_ARB                              0x2075
#define WGL_TEXTURE_RGBA_ARB                             0x2076
#define WGL_NO_TEXTURE_ARB                               0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB                         0x2078
#define WGL_TEXTURE_1D_ARB                               0x2079
#define WGL_TEXTURE_2D_ARB                               0x207A
#define WGL_MIPMAP_LEVEL_ARB                             0x207B
#define WGL_CUBE_MAP_FACE_ARB                            0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB              0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB              0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB              0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB              0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB              0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB              0x2082
#define WGL_FRONT_LEFT_ARB                               0x2083
#define WGL_FRONT_RIGHT_ARB                              0x2084
#define WGL_BACK_LEFT_ARB                                0x2085
#define WGL_BACK_RIGHT_ARB                               0x2086
#define WGL_AUX0_ARB                                     0x2087
#define WGL_AUX1_ARB                                     0x2088
#define WGL_AUX2_ARB                                     0x2089
#define WGL_AUX3_ARB                                     0x208A
#define WGL_AUX4_ARB                                     0x208B
#define WGL_AUX5_ARB                                     0x208C
#define WGL_AUX6_ARB                                     0x208D
#define WGL_AUX7_ARB                                     0x208E
#define WGL_AUX8_ARB                                     0x208F
#define WGL_AUX9_ARB                                     0x2090
#endif

#ifndef WGL_ARB_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ARB                          0x21A0
#endif

#ifndef WGL_ARB_framebuffer_sRGB
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB                 0x20A9
#endif

#ifndef WGL_ARB_create_context
#define WGL_CONTEXT_DEBUG_BIT_ARB                        0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB           0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB                    0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB                    0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB                      0x2093
#define WGL_CONTEXT_FLAGS_ARB                            0x2094
#define ERROR_INVALID_VERSION_ARB                        0x2095
#endif

#ifndef WGL_ARB_create_context_profile
#define WGL_CONTEXT_PROFILE_MASK_ARB                     0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB                 0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB        0x00000002
#define ERROR_INVALID_PROFILE_ARB                        0x2096
#endif

#ifndef WGL_ARB_create_context_robustness
#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB                0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB                    0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB      0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB                    0x8261
#endif

#ifndef WGL_EXT_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_EXT                     0x2043
#endif

#ifndef WGL_EXT_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_EXT                     0x2000
#define WGL_DRAW_TO_WINDOW_EXT                           0x2001
#define WGL_DRAW_TO_BITMAP_EXT                           0x2002
#define WGL_ACCELERATION_EXT                             0x2003
#define WGL_NEED_PALETTE_EXT                             0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT                      0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT                       0x2006
#define WGL_SWAP_METHOD_EXT                              0x2007
#define WGL_NUMBER_OVERLAYS_EXT                          0x2008
#define WGL_NUMBER_UNDERLAYS_EXT                         0x2009
#define WGL_TRANSPARENT_EXT                              0x200A
#define WGL_TRANSPARENT_VALUE_EXT                        0x200B
#define WGL_SHARE_DEPTH_EXT                              0x200C
#define WGL_SHARE_STENCIL_EXT                            0x200D
#define WGL_SHARE_ACCUM_EXT                              0x200E
#define WGL_SUPPORT_GDI_EXT                              0x200F
#define WGL_SUPPORT_OPENGL_EXT                           0x2010
#define WGL_DOUBLE_BUFFER_EXT                            0x2011
#define WGL_STEREO_EXT                                   0x2012
#define WGL_PIXEL_TYPE_EXT                               0x2013
#define WGL_COLOR_BITS_EXT                               0x2014
#define WGL_RED_BITS_EXT                                 0x2015
#define WGL_RED_SHIFT_EXT                                0x2016
#define WGL_GREEN_BITS_EXT                               0x2017
#define WGL_GREEN_SHIFT_EXT                              0x2018
#define WGL_BLUE_BITS_EXT                                0x2019
#define WGL_BLUE_SHIFT_EXT                               0x201A
#define WGL_ALPHA_BITS_EXT                               0x201B
#define WGL_ALPHA_SHIFT_EXT                              0x201C
#define WGL_ACCUM_BITS_EXT                               0x201D
#define WGL_ACCUM_RED_BITS_EXT                           0x201E
#define WGL_ACCUM_GREEN_BITS_EXT                         0x201F
#define WGL_ACCUM_BLUE_BITS_EXT                          0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT                         0x2021
#define WGL_DEPTH_BITS_EXT                               0x2022
#define WGL_STENCIL_BITS_EXT                             0x2023
#define WGL_AUX_BUFFERS_EXT                              0x2024
#define WGL_NO_ACCELERATION_EXT                          0x2025
#define WGL_GENERIC_ACCELERATION_EXT                     0x2026
#define WGL_FULL_ACCELERATION_EXT                        0x2027
#define WGL_SWAP_EXCHANGE_EXT                            0x2028
#define WGL_SWAP_COPY_EXT                                0x2029
#define WGL_SWAP_UNDEFINED_EXT                           0x202A
#define WGL_TYPE_RGBA_EXT                                0x202B
#define WGL_TYPE_COLORINDEX_EXT                          0x202C
#endif

#ifndef WGL_EXT_pbuffer
#define WGL_DRAW_TO_PBUFFER_EXT                          0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT                       0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT                        0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT                       0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT                    0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT                   0x2032
#define WGL_PBUFFER_LARGEST_EXT                          0x2033
#define WGL_PBUFFER_WIDTH_EXT                            0x2034
#define WGL_PBUFFER_HEIGHT_EXT                           0x2035
#endif

#ifndef WGL_EXT_depth_float
#define WGL_DEPTH_FLOAT_EXT                              0x2040
#endif

#ifndef WGL_3DFX_multisample
#define WGL_SAMPLE_BUFFERS_3DFX                          0x2060
#define WGL_SAMPLES_3DFX                                 0x2061
#endif

#ifndef WGL_EXT_multisample
#define WGL_SAMPLE_BUFFERS_EXT                           0x2041
#define WGL_SAMPLES_EXT                                  0x2042
#endif

#ifndef WGL_I3D_digital_video_control
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D   0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D         0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D            0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D            0x2053
#endif

#ifndef WGL_I3D_gamma
#define WGL_GAMMA_TABLE_SIZE_I3D                         0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D                    0x204F
#endif

#ifndef WGL_I3D_genlock
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D                 0x2044
#define WGL_GENLOCK_SOURCE_EXTENAL_SYNC_I3D              0x2045
#define WGL_GENLOCK_SOURCE_EXTENAL_FIELD_I3D             0x2046
#define WGL_GENLOCK_SOURCE_EXTENAL_TTL_I3D               0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D              0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D             0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D              0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D               0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D                 0x204C
#endif

#ifndef WGL_I3D_image_buffer
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D                  0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D                        0x00000002
#endif

#ifndef WGL_I3D_swap_frame_lock
#endif

#ifndef WGL_NV_render_depth_texture
#define WGL_BIND_TO_TEXTURE_DEPTH_NV                     0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV           0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV                      0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV                   0x20A6
#define WGL_DEPTH_COMPONENT_NV                           0x20A7
#endif

#ifndef WGL_NV_render_texture_rectangle
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV             0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV            0x20A1
#define WGL_TEXTURE_RECTANGLE_NV                         0x20A2
#endif

#ifndef WGL_ATI_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ATI                          0x21A0
#endif

#ifndef WGL_NV_float_buffer
#define WGL_FLOAT_COMPONENTS_NV                          0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV         0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV        0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV       0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV      0x20B4
#define WGL_TEXTURE_FLOAT_R_NV                           0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV                          0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV                         0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV                        0x20B8
#endif

#ifndef WGL_3DL_stereo_control
#define WGL_STEREO_EMITTER_ENABLE_3DL                    0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL                   0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL                   0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL                   0x2058
#endif

#ifndef WGL_EXT_pixel_format_packed_float
#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT                 0x20A8
#endif

#ifndef WGL_EXT_framebuffer_sRGB
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT                 0x20A9
#endif

#ifndef WGL_NV_present_video
#define WGL_NUM_VIDEO_SLOTS_NV                           0x20F0
#endif

#ifndef WGL_NV_video_out
#define WGL_BIND_TO_VIDEO_RGB_NV                         0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV                        0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV               0x20C2
#define WGL_VIDEO_OUT_COLOR_NV                           0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV                           0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV                           0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV                 0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV                 0x20C7
#define WGL_VIDEO_OUT_FRAME                              0x20C8
#define WGL_VIDEO_OUT_FIELD_1                            0x20C9
#define WGL_VIDEO_OUT_FIELD_2                            0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2                 0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1                 0x20CC
#endif

#ifndef WGL_NV_swap_group
#endif

#ifndef WGL_NV_gpu_affinity
#define WGL_ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV         0x20D0
#define WGL_ERROR_MISSING_AFFINITY_MASK_NV               0x20D1
#endif

#ifndef WGL_AMD_gpu_association
#define WGL_GPU_VENDOR_AMD                               0x1F00
#define WGL_GPU_RENDERER_STRING_AMD                      0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD                0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD                  0x21A2
#define WGL_GPU_RAM_AMD                                  0x21A3
#define WGL_GPU_CLOCK_AMD                                0x21A4
#define WGL_GPU_NUM_PIPES_AMD                            0x21A5
#define WGL_GPU_NUM_SIMD_AMD                             0x21A6
#define WGL_GPU_NUM_RB_AMD                               0x21A7
#define WGL_GPU_NUM_SPI_AMD                              0x21A8
#endif

#ifndef WGL_NV_video_capture
#define WGL_UNIQUE_ID_NV                                 0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV                   0x20CF
#endif

#ifndef WGL_NV_copy_image
#endif

#ifndef WGL_NV_multisample_coverage
#define WGL_COVERAGE_SAMPLES_NV                          0x2042
#define WGL_COLOR_SAMPLES_NV                             0x20B9
#endif

#ifndef WGL_EXT_create_context_es2_profile
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT                  0x00000004
#endif

#ifndef WGL_NV_DX_interop
#define WGL_ACCESS_READ_ONLY_NV                          0x00000000
#define WGL_ACCESS_READ_WRITE_NV                         0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV                      0x00000002
#endif

#ifndef WGL_NV_DX_interop2
#endif

#ifndef WGL_EXT_swap_control_tear
#endif

#ifndef WGL_ARB_pbuffer
DECLARE_HANDLE(HPBUFFERARB);
#endif
#ifndef WGL_EXT_pbuffer
DECLARE_HANDLE(HPBUFFEREXT);
#endif
#ifndef WGL_NV_present_video
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#endif
#ifndef WGL_NV_video_output
DECLARE_HANDLE(HPVIDEODEV);
#endif
#ifndef WGL_NV_gpu_affinity
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);

typedef struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
} GPU_DEVICE, *PGPU_DEVICE;
#endif
#ifndef WGL_NV_video_capture
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#endif


/* WGL_ARB_buffer_region */
extern HANDLE (APIENTRY *gwglCreateBufferRegionARB)(HDC hDC, int iLayerPlane, UINT uType);
extern VOID (APIENTRY *gwglDeleteBufferRegionARB)(HANDLE hRegion);
extern BOOL (APIENTRY *gwglSaveBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height);
extern BOOL (APIENTRY *gwglRestoreBufferRegionARB)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

/* WGL_ARB_multisample */

/* WGL_ARB_extensions_string */
extern const char * (APIENTRY *gwglGetExtensionsStringARB)(HDC hdc);

/* WGL_ARB_pixel_format */
extern BOOL (APIENTRY *gwglGetPixelFormatAttribivARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues);
extern BOOL (APIENTRY *gwglGetPixelFormatAttribfvARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues);
extern BOOL (APIENTRY *gwglChoosePixelFormatARB)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);

/* WGL_ARB_make_current_read */
extern BOOL (APIENTRY *gwglMakeContextCurrentARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
extern HDC (APIENTRY *gwglGetCurrentReadDCARB)();

/* WGL_ARB_pbuffer */
extern HPBUFFERARB (APIENTRY *gwglCreatePbufferARB)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
extern HDC (APIENTRY *gwglGetPbufferDCARB)(HPBUFFERARB hPbuffer);
extern int (APIENTRY *gwglReleasePbufferDCARB)(HPBUFFERARB hPbuffer, HDC hDC);
extern BOOL (APIENTRY *gwglDestroyPbufferARB)(HPBUFFERARB hPbuffer);
extern BOOL (APIENTRY *gwglQueryPbufferARB)(HPBUFFERARB hPbuffer, int iAttribute, int* piValue);

/* WGL_ARB_render_texture */
extern BOOL (APIENTRY *gwglBindTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
extern BOOL (APIENTRY *gwglReleaseTexImageARB)(HPBUFFERARB hPbuffer, int iBuffer);
extern BOOL (APIENTRY *gwglSetPbufferAttribARB)(HPBUFFERARB hPbuffer, const int* piAttribList);

/* WGL_ARB_pixel_format_float */

/* WGL_ARB_framebuffer_sRGB */

/* WGL_ARB_create_context */
extern HGLRC (APIENTRY *gwglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int* attribList);

/* WGL_ARB_create_context_profile */

/* WGL_ARB_create_context_robustness */

/* WGL_EXT_display_color_table */
extern GLboolean (APIENTRY *gwglCreateDisplayColorTableEXT)(GLushort id);
extern GLboolean (APIENTRY *gwglLoadDisplayColorTableEXT)(const GLushort* table, GLuint length);
extern GLboolean (APIENTRY *gwglBindDisplayColorTableEXT)(GLushort id);
extern VOID (APIENTRY *gwglDestroyDisplayColorTableEXT)(GLushort id);

/* WGL_EXT_extensions_string */
extern const char * (APIENTRY *gwglGetExtensionsStringEXT)();

/* WGL_EXT_make_current_read */
extern BOOL (APIENTRY *gwglMakeContextCurrentEXT)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
extern HDC (APIENTRY *gwglGetCurrentReadDCEXT)();

/* WGL_EXT_pbuffer */
extern HPBUFFEREXT (APIENTRY *gwglCreatePbufferEXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
extern HDC (APIENTRY *gwglGetPbufferDCEXT)(HPBUFFEREXT hPbuffer);
extern int (APIENTRY *gwglReleasePbufferDCEXT)(HPBUFFEREXT hPbuffer, HDC hDC);
extern BOOL (APIENTRY *gwglDestroyPbufferEXT)(HPBUFFEREXT hPbuffer);
extern BOOL (APIENTRY *gwglQueryPbufferEXT)(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue);

/* WGL_EXT_pixel_format */
extern BOOL (APIENTRY *gwglGetPixelFormatAttribivEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues);
extern BOOL (APIENTRY *gwglGetPixelFormatAttribfvEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues);
extern BOOL (APIENTRY *gwglChoosePixelFormatEXT)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);

/* WGL_EXT_swap_control */
extern BOOL (APIENTRY *gwglSwapIntervalEXT)(int interval);
extern int (APIENTRY *gwglGetSwapIntervalEXT)();

/* WGL_EXT_depth_float */

/* WGL_NV_vertex_array_range */
extern void* (APIENTRY *gwglAllocateMemoryNV)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
extern void (APIENTRY *gwglFreeMemoryNV)(void* pointer);

/* WGL_3DFX_multisample */

/* WGL_EXT_multisample */

/* WGL_OML_sync_control */
extern BOOL (APIENTRY *gwglGetSyncValuesOML)(HDC hdc, INT64* ust, INT64* msc, INT64* sbc);
extern BOOL (APIENTRY *gwglGetMscRateOML)(HDC hdc, INT32* numerator, INT32* denominator);
extern INT64 (APIENTRY *gwglSwapBuffersMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
extern INT64 (APIENTRY *gwglSwapLayerBuffersMscOML)(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
extern BOOL (APIENTRY *gwglWaitForMscOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc);
extern BOOL (APIENTRY *gwglWaitForSbcOML)(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc);

/* WGL_I3D_digital_video_control */
extern BOOL (APIENTRY *gwglGetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, int* piValue);
extern BOOL (APIENTRY *gwglSetDigitalVideoParametersI3D)(HDC hDC, int iAttribute, const int* piValue);

/* WGL_I3D_gamma */
extern BOOL (APIENTRY *gwglGetGammaTableParametersI3D)(HDC hDC, int iAttribute, int* piValue);
extern BOOL (APIENTRY *gwglSetGammaTableParametersI3D)(HDC hDC, int iAttribute, const int* piValue);
extern BOOL (APIENTRY *gwglGetGammaTableI3D)(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue);
extern BOOL (APIENTRY *gwglSetGammaTableI3D)(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue);

/* WGL_I3D_genlock */
extern BOOL (APIENTRY *gwglEnableGenlockI3D)(HDC hDC);
extern BOOL (APIENTRY *gwglDisableGenlockI3D)(HDC hDC);
extern BOOL (APIENTRY *gwglIsEnabledGenlockI3D)(HDC hDC, BOOL* pFlag);
extern BOOL (APIENTRY *gwglGenlockSourceI3D)(HDC hDC, UINT uSource);
extern BOOL (APIENTRY *gwglGetGenlockSourceI3D)(HDC hDC, UINT* uSource);
extern BOOL (APIENTRY *gwglGenlockSourceEdgeI3D)(HDC hDC, UINT uEdge);
extern BOOL (APIENTRY *gwglGetGenlockSourceEdgeI3D)(HDC hDC, UINT* uEdge);
extern BOOL (APIENTRY *gwglGenlockSampleRateI3D)(HDC hDC, UINT uRate);
extern BOOL (APIENTRY *gwglGetGenlockSampleRateI3D)(HDC hDC, UINT* uRate);
extern BOOL (APIENTRY *gwglGenlockSourceDelayI3D)(HDC hDC, UINT uDelay);
extern BOOL (APIENTRY *gwglGetGenlockSourceDelayI3D)(HDC hDC, UINT* uDelay);
extern BOOL (APIENTRY *gwglQueryGenlockMaxSourceDelayI3D)(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay);

/* WGL_I3D_image_buffer */
extern LPVOID (APIENTRY *gwglCreateImageBufferI3D)(HDC hDC, DWORD dwSize, UINT uFlags);
extern BOOL (APIENTRY *gwglDestroyImageBufferI3D)(HDC hDC, LPVOID pAddress);
extern BOOL (APIENTRY *gwglAssociateImageBufferEventsI3D)(HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count);
extern BOOL (APIENTRY *gwglReleaseImageBufferEventsI3D)(HDC hDC, const LPVOID* pAddress, UINT count);

/* WGL_I3D_swap_frame_lock */
extern BOOL (APIENTRY *gwglEnableFrameLockI3D)();
extern BOOL (APIENTRY *gwglDisableFrameLockI3D)();
extern BOOL (APIENTRY *gwglIsEnabledFrameLockI3D)(BOOL* pFlag);
extern BOOL (APIENTRY *gwglQueryFrameLockMasterI3D)(BOOL* pFlag);

/* WGL_I3D_swap_frame_usage */
extern BOOL (APIENTRY *gwglGetFrameUsageI3D)(float* pUsage);
extern BOOL (APIENTRY *gwglBeginFrameTrackingI3D)();
extern BOOL (APIENTRY *gwglEndFrameTrackingI3D)();
extern BOOL (APIENTRY *gwglQueryFrameTrackingI3D)(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage);

/* WGL_ATI_pixel_format_float */

/* WGL_NV_float_buffer */

/* WGL_3DL_stereo_control */
extern BOOL (APIENTRY *gwglSetStereoEmitterState3DL)(HDC hDC, UINT uState);

/* WGL_EXT_pixel_format_packed_float */

/* WGL_EXT_framebuffer_sRGB */

/* WGL_NV_present_video */
extern int (APIENTRY *gwglEnumerateVideoDevicesNV)(HDC hDC, HVIDEOOUTPUTDEVICENV* phDeviceList);
extern BOOL (APIENTRY *gwglBindVideoDeviceNV)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList);
extern BOOL (APIENTRY *gwglQueryCurrentContextNV)(int iAttribute, int* piValue);

/* WGL_NV_video_output */
extern BOOL (APIENTRY *gwglGetVideoDeviceNV)(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice);
extern BOOL (APIENTRY *gwglReleaseVideoDeviceNV)(HPVIDEODEV hVideoDevice);
extern BOOL (APIENTRY *gwglBindVideoImageNV)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
extern BOOL (APIENTRY *gwglReleaseVideoImageNV)(HPBUFFERARB hPbuffer, int iVideoBuffer);
extern BOOL (APIENTRY *gwglSendPbufferToVideoNV)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock);
extern BOOL (APIENTRY *gwglGetVideoInfoNV)(HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo);

/* WGL_NV_swap_group */
extern BOOL (APIENTRY *gwglJoinSwapGroupNV)(HDC hDC, GLuint group);
extern BOOL (APIENTRY *gwglBindSwapBarrierNV)(GLuint group, GLuint barrier);
extern BOOL (APIENTRY *gwglQuerySwapGroupNV)(HDC hDC, GLuint* group, GLuint* barrier);
extern BOOL (APIENTRY *gwglQueryMaxSwapGroupsNV)(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers);
extern BOOL (APIENTRY *gwglQueryFrameCountNV)(HDC hDC, GLuint* count);
extern BOOL (APIENTRY *gwglResetFrameCountNV)(HDC hDC);

/* WGL_NV_gpu_affinity */
extern BOOL (APIENTRY *gwglEnumGpusNV)(UINT iGpuIndex, HGPUNV* phGpu);
extern BOOL (APIENTRY *gwglEnumGpuDevicesNV)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
extern HDC (APIENTRY *gwglCreateAffinityDCNV)(const HGPUNV* phGpuList);
extern BOOL (APIENTRY *gwglEnumGpusFromAffinityDCNV)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu);
extern BOOL (APIENTRY *gwglDeleteDCNV)(HDC hdc);

/* WGL_AMD_gpu_association */
extern UINT (APIENTRY *gwglGetGPUIDsAMD)(UINT maxCount, UINT* ids);
extern INT (APIENTRY *gwglGetGPUInfoAMD)(UINT id, int property, GLenum dataType, UINT size, void* data);
extern UINT (APIENTRY *gwglGetContextGPUIDAMD)(HGLRC hglrc);
extern HGLRC (APIENTRY *gwglCreateAssociatedContextAMD)(UINT id);
extern HGLRC (APIENTRY *gwglCreateAssociatedContextAttribsAMD)(UINT id, HGLRC hShareContext, const int* attribList);
extern BOOL (APIENTRY *gwglDeleteAssociatedContextAMD)(HGLRC hglrc);
extern BOOL (APIENTRY *gwglMakeAssociatedContextCurrentAMD)(HGLRC hglrc);
extern HGLRC (APIENTRY *gwglGetCurrentAssociatedContextAMD)();
extern VOID (APIENTRY *gwglBlitContextFramebufferAMD)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

/* WGL_NV_video_capture */
extern BOOL (APIENTRY *gwglBindVideoCaptureDeviceNV)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
extern UINT (APIENTRY *gwglEnumerateVideoCaptureDevicesNV)(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList);
extern BOOL (APIENTRY *gwglLockVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
extern BOOL (APIENTRY *gwglQueryVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue);
extern BOOL (APIENTRY *gwglReleaseVideoCaptureDeviceNV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);

/* WGL_NV_copy_image */
extern BOOL (APIENTRY *gwglCopyImageSubDataNV)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

/* WGL_NV_multisample_coverage */

/* WGL_NV_DX_interop */
extern BOOL (APIENTRY *gwglDXSetResourceShareHandleNV)(void* dxObject, HANDLE shareHandle);
extern HANDLE (APIENTRY *gwglDXOpenDeviceNV)(void* dxDevice);
extern BOOL (APIENTRY *gwglDXCloseDeviceNV)(HANDLE hDevice);
extern HANDLE (APIENTRY *gwglDXRegisterObjectNV)(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access);
extern BOOL (APIENTRY *gwglDXUnregisterObjectNV)(HANDLE hDevice, HANDLE hObject);
extern BOOL (APIENTRY *gwglDXObjectAccessNV)(HANDLE hObject, GLenum access);
extern BOOL (APIENTRY *gwglDXLockObjectsNV)(HANDLE hDevice, GLint count, HANDLE* hObjects);
extern BOOL (APIENTRY *gwglDXUnlockObjectsNV)(HANDLE hDevice, GLint count, HANDLE* hObjects);

/* WGL_NV_DX_interop2 */

/* WGL_EXT_swap_control_tear */

typedef struct {
	int _WGL_3DFX_multisample : 1;
	int _WGL_3DL_stereo_control : 1;
	int _WGL_AMD_gpu_association : 1;
	int _WGL_ARB_buffer_region : 1;
	int _WGL_ARB_create_context : 1;
	int _WGL_ARB_create_context_profile : 1;
	int _WGL_ARB_create_context_robustness : 1;
	int _WGL_ARB_extensions_string : 1;
	int _WGL_ARB_framebuffer_sRGB : 1;
	int _WGL_ARB_make_current_read : 1;
	int _WGL_ARB_multisample : 1;
	int _WGL_ARB_pbuffer : 1;
	int _WGL_ARB_pixel_format : 1;
	int _WGL_ARB_pixel_format_float : 1;
	int _WGL_ARB_render_texture : 1;
	int _WGL_ATI_pixel_format_float : 1;
	int _WGL_EXT_depth_float : 1;
	int _WGL_EXT_display_color_table : 1;
	int _WGL_EXT_extensions_string : 1;
	int _WGL_EXT_framebuffer_sRGB : 1;
	int _WGL_EXT_make_current_read : 1;
	int _WGL_EXT_multisample : 1;
	int _WGL_EXT_pbuffer : 1;
	int _WGL_EXT_pixel_format : 1;
	int _WGL_EXT_pixel_format_packed_float : 1;
	int _WGL_EXT_swap_control : 1;
	int _WGL_EXT_swap_control_tear : 1;
	int _WGL_EXT_texture_compression_s3tc : 1;
	int _WGL_I3D_digital_video_control : 1;
	int _WGL_I3D_gamma : 1;
	int _WGL_I3D_genlock : 1;
	int _WGL_I3D_image_buffer : 1;
	int _WGL_I3D_swap_frame_lock : 1;
	int _WGL_I3D_swap_frame_usage : 1;
	int _WGL_NV_DX_interop : 1;
	int _WGL_NV_DX_interop2 : 1;
	int _WGL_NV_copy_image : 1;
	int _WGL_NV_float_buffer : 1;
	int _WGL_NV_gpu_affinity : 1;
	int _WGL_NV_multisample_coverage : 1;
	int _WGL_NV_present_video : 1;
	int _WGL_NV_swap_group : 1;
	int _WGL_NV_vertex_array_range : 1;
	int _WGL_NV_video_capture : 1;
	int _WGL_NV_video_output : 1;
	int _WGL_OML_sync_control : 1;
} gwglext_t;

extern gwglext_t gwglext;

extern void gwgl_init(int enableDebug);
extern void gwgl_rebind(int enableDebug);
extern void gwgl_check_extensions(HDC hdc);

#ifdef __cplusplus
}
#endif

#endif /* __GWGL_H__ */
