/*********************************************************************************************
 *
 * gglx.h
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

#ifndef __GGLX_H__
#define __GGLX_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef GLX_ARB_get_proc_address
#endif

#ifndef GLX_ARB_multisample
#define GLX_SAMPLE_BUFFERS_ARB                               100000
#define GLX_SAMPLES_ARB                                      100001
#endif

#ifndef GLX_ARB_vertex_buffer_object
#define GLX_CONTEXT_ALLOW_BUFFER_BYTE_ORDER_MISMATCH_ARB     0x2095
#endif

#ifndef GLX_ARB_fbconfig_float
#define GLX_RGBA_FLOAT_TYPE_ARB                              0x20B9
#define GLX_RGBA_FLOAT_BIT_ARB                               0x00000004
#endif

#ifndef GLX_ARB_framebuffer_sRGB
#define GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB                     0x20B2
#endif

#ifndef GLX_ARB_create_context
#define GLX_CONTEXT_DEBUG_BIT_ARB                            0x00000001
#define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB               0x00000002
#define GLX_CONTEXT_MAJOR_VERSION_ARB                        0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB                        0x2092
#define GLX_CONTEXT_FLAGS_ARB                                0x2094
#endif

#ifndef GLX_ARB_create_context_profile
#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB                     0x00000001
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB            0x00000002
#define GLX_CONTEXT_PROFILE_MASK_ARB                         0x9126
#endif

#ifndef GLX_ARB_create_context_robustness
#define GLX_CONTEXT_ROBUST_ACCESS_BIT_ARB                    0x00000004
#define GLX_LOSE_CONTEXT_ON_RESET_ARB                        0x8252
#define GLX_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB          0x8256
#define GLX_NO_RESET_NOTIFICATION_ARB                        0x8261
#endif

#ifndef GLX_SGIS_multisample
#define GLX_SAMPLE_BUFFERS_SGIS                              100000
#define GLX_SAMPLES_SGIS                                     100001
#endif

#ifndef GLX_EXT_visual_info
#define GLX_X_VISUAL_TYPE_EXT                                0x22
#define GLX_TRANSPARENT_TYPE_EXT                             0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT                      0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT                        0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT                      0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT                       0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT                      0x28
#define GLX_NONE_EXT                                         0x8000
#define GLX_TRUE_COLOR_EXT                                   0x8002
#define GLX_DIRECT_COLOR_EXT                                 0x8003
#define GLX_PSEUDO_COLOR_EXT                                 0x8004
#define GLX_STATIC_COLOR_EXT                                 0x8005
#define GLX_GRAY_SCALE_EXT                                   0x8006
#define GLX_STATIC_GRAY_EXT                                  0x8007
#define GLX_TRANSPARENT_RGB_EXT                              0x8008
#define GLX_TRANSPARENT_INDEX_EXT                            0x8009
#endif

#ifndef GLX_SGI_swap_control
#endif

#ifndef GLX_SGI_video_sync
#endif

#ifndef GLX_SGI_make_current_read
#endif

#ifndef GLX_SGIX_video_source
#endif

#ifndef GLX_EXT_visual_rating
#define GLX_VISUAL_CAVEAT_EXT                                0x20
#define GLX_SLOW_VISUAL_EXT                                  0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT                        0x800D
/* reuse GLX_NONE_EXT */
#endif

#ifndef GLX_EXT_import_context
#define GLX_SHARE_CONTEXT_EXT                                0x800A
#define GLX_VISUAL_ID_EXT                                    0x800B
#define GLX_SCREEN_EXT                                       0x800C
#endif

#ifndef GLX_SGIX_fbconfig
#define GLX_WINDOW_BIT_SGIX                                  0x00000001
#define GLX_PIXMAP_BIT_SGIX                                  0x00000002
#define GLX_RGBA_BIT_SGIX                                    0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX                             0x00000002
#define GLX_DRAWABLE_TYPE_SGIX                               0x8010
#define GLX_RENDER_TYPE_SGIX                                 0x8011
#define GLX_X_RENDERABLE_SGIX                                0x8012
#define GLX_FBCONFIG_ID_SGIX                                 0x8013
#define GLX_RGBA_TYPE_SGIX                                   0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX                            0x8015
/* reuse GLX_SCREEN_EXT */
#endif

#ifndef GLX_SGIX_pbuffer
#define GLX_PBUFFER_BIT_SGIX                                 0x00000004
#define GLX_BUFFER_CLOBBER_MASK_SGIX                         0x08000000
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX                       0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX                      0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX                        0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX                       0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX                             0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX                            0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX                          0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX                            0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX                          0x00000100
#define GLX_MAX_PBUFFER_WIDTH_SGIX                           0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX                          0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX                          0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX                       0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX                      0x801A
#define GLX_PRESERVED_CONTENTS_SGIX                          0x801B
#define GLX_LARGEST_PBUFFER_SGIX                             0x801C
#define GLX_WIDTH_SGIX                                       0x801D
#define GLX_HEIGHT_SGIX                                      0x801E
#define GLX_EVENT_MASK_SGIX                                  0x801F
#define GLX_DAMAGED_SGIX                                     0x8020
#define GLX_SAVED_SGIX                                       0x8021
#define GLX_WINDOW_SGIX                                      0x8022
#define GLX_PBUFFER_SGIX                                     0x8023
#endif

#ifndef GLX_SGI_cushion
#endif

#ifndef GLX_SGIX_video_resize
#define GLX_SYNC_FRAME_SGIX                                  0x00000000
#define GLX_SYNC_SWAP_SGIX                                   0x00000001
#endif

#ifndef GLX_SGIX_dmbuffer
#define GLX_DIGITAL_MEDIA_PBUFFER_SGIX                       0x8024
#endif

#ifndef GLX_SGIX_swap_group
#endif

#ifndef GLX_SGIX_swap_barrier
#endif

#ifndef GLX_SGIS_blended_overlay
#define GLX_BLENDED_RGBA_SGIS                                0x8025
#endif

#ifndef GLX_SGIS_shared_multisample
#define GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS                  0x8026
#define GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS                 0x8027
#endif

#ifndef GLX_SUN_get_transparent_index
#endif

#ifndef GLX_3DFX_multisample
#define GLX_SAMPLE_BUFFERS_3DFX                              0x8050
#define GLX_SAMPLES_3DFX                                     0x8051
#endif

#ifndef GLX_MESA_copy_sub_buffer
#endif

#ifndef GLX_MESA_pixmap_colormap
#endif

#ifndef GLX_MESA_release_buffers
#endif

#ifndef GLX_MESA_set_3dfx_mode
#define GLX_3DFX_WINDOW_MODE_MESA                            0x1
#define GLX_3DFX_FULLSCREEN_MODE_MESA                        0x2
#endif

#ifndef GLX_SGIX_visual_select_group
#define GLX_VISUAL_SELECT_GROUP_SGIX                         0x8028
#endif

#ifndef GLX_OML_swap_method
#define GLX_SWAP_METHOD_OML                                  0x8060
#define GLX_SWAP_EXCHANGE_OML                                0x8061
#define GLX_SWAP_COPY_OML                                    0x8062
#define GLX_SWAP_UNDEFINED_OML                               0x8063
#endif

#ifndef GLX_OML_sync_control
#endif

#ifndef GLX_NV_float_buffer
#define GLX_FLOAT_COMPONENTS_NV                              0x20B0
#endif

#ifndef GLX_SGIX_hyperpipe
#define GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX                  80
#define GLX_BAD_HYPERPIPE_CONFIG_SGIX                        91
#define GLX_BAD_HYPERPIPE_SGIX                               92
#define GLX_HYPERPIPE_DISPLAY_PIPE_SGIX                      0x00000001
#define GLX_HYPERPIPE_RENDER_PIPE_SGIX                       0x00000002
#define GLX_PIPE_RECT_SGIX                                   0x00000001
#define GLX_PIPE_RECT_LIMITS_SGIX                            0x00000002
#define GLX_HYPERPIPE_STEREO_SGIX                            0x00000003
#define GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX                     0x00000004
#define GLX_HYPERPIPE_ID_SGIX                                0x8030
#endif

#ifndef GLX_MESA_agp_offset
#endif

#ifndef GLX_EXT_fbconfig_packed_float
#define GLX_RGBA_UNSIGNED_FLOAT_TYPE_EXT                     0x20B1
#define GLX_RGBA_UNSIGNED_FLOAT_BIT_EXT                      0x00000008
#endif

#ifndef GLX_EXT_framebuffer_sRGB
#define GLX_FRAMEBUFFER_SRGB_CAPABLE_EXT                     0x20B2
#endif

#ifndef GLX_EXT_texture_from_pixmap
#define GLX_TEXTURE_1D_BIT_EXT                               0x00000001
#define GLX_TEXTURE_2D_BIT_EXT                               0x00000002
#define GLX_TEXTURE_RECTANGLE_BIT_EXT                        0x00000004
#define GLX_BIND_TO_TEXTURE_RGB_EXT                          0x20D0
#define GLX_BIND_TO_TEXTURE_RGBA_EXT                         0x20D1
#define GLX_BIND_TO_MIPMAP_TEXTURE_EXT                       0x20D2
#define GLX_BIND_TO_TEXTURE_TARGETS_EXT                      0x20D3
#define GLX_Y_INVERTED_EXT                                   0x20D4
#define GLX_TEXTURE_FORMAT_EXT                               0x20D5
#define GLX_TEXTURE_TARGET_EXT                               0x20D6
#define GLX_MIPMAP_TEXTURE_EXT                               0x20D7
#define GLX_TEXTURE_FORMAT_NONE_EXT                          0x20D8
#define GLX_TEXTURE_FORMAT_RGB_EXT                           0x20D9
#define GLX_TEXTURE_FORMAT_RGBA_EXT                          0x20DA
#define GLX_TEXTURE_1D_EXT                                   0x20DB
#define GLX_TEXTURE_2D_EXT                                   0x20DC
#define GLX_TEXTURE_RECTANGLE_EXT                            0x20DD
#define GLX_FRONT_LEFT_EXT                                   0x20DE
#define GLX_FRONT_RIGHT_EXT                                  0x20DF
#define GLX_BACK_LEFT_EXT                                    0x20E0
#define GLX_BACK_RIGHT_EXT                                   0x20E1
#define GLX_FRONT_EXT                                        GLX_FRONT_LEFT_EXT
#define GLX_BACK_EXT                                         GLX_BACK_LEFT_EXT
#define GLX_AUX0_EXT                                         0x20E2
#define GLX_AUX1_EXT                                         0x20E3
#define GLX_AUX2_EXT                                         0x20E4
#define GLX_AUX3_EXT                                         0x20E5
#define GLX_AUX4_EXT                                         0x20E6
#define GLX_AUX5_EXT                                         0x20E7
#define GLX_AUX6_EXT                                         0x20E8
#define GLX_AUX7_EXT                                         0x20E9
#define GLX_AUX8_EXT                                         0x20EA
#define GLX_AUX9_EXT                                         0x20EB
#endif

#ifndef GLX_NV_present_video
#define GLX_NUM_VIDEO_SLOTS_NV                               0x20F0
#endif

#ifndef GLX_NV_video_out
#define GLX_VIDEO_OUT_COLOR_NV                               0x20C3
#define GLX_VIDEO_OUT_ALPHA_NV                               0x20C4
#define GLX_VIDEO_OUT_DEPTH_NV                               0x20C5
#define GLX_VIDEO_OUT_COLOR_AND_ALPHA_NV                     0x20C6
#define GLX_VIDEO_OUT_COLOR_AND_DEPTH_NV                     0x20C7
#define GLX_VIDEO_OUT_FRAME_NV                               0x20C8
#define GLX_VIDEO_OUT_FIELD_1_NV                             0x20C9
#define GLX_VIDEO_OUT_FIELD_2_NV                             0x20CA
#define GLX_VIDEO_OUT_STACKED_FIELDS_1_2_NV                  0x20CB
#define GLX_VIDEO_OUT_STACKED_FIELDS_2_1_NV                  0x20CC
#endif

#ifndef GLX_NV_swap_group
#endif

#ifndef GLX_NV_video_capture
#define GLX_DEVICE_ID_NV                                     0x20CD
#define GLX_UNIQUE_ID_NV                                     0x20CE
#define GLX_NUM_VIDEO_CAPTURE_SLOTS_NV                       0x20CF
#endif

#ifndef GLX_EXT_swap_control
#define GLX_SWAP_INTERVAL_EXT                                0x20F1
#define GLX_MAX_SWAP_INTERVAL_EXT                            0x20F2
#endif

#ifndef GLX_NV_copy_image
#endif

#ifndef GLX_INTEL_swap_event
#define GLX_BUFFER_SWAP_COMPLETE_INTEL_MASK                  0x04000000
#define GLX_EXCHANGE_COMPLETE_INTEL                          0x8180
#define GLX_COPY_COMPLETE_INTEL                              0x8181
#define GLX_FLIP_COMPLETE_INTEL                              0x8182
#endif

#ifndef GLX_NV_multisample_coverage
#define GLX_COVERAGE_SAMPLES_NV                              100001
#define GLX_COLOR_SAMPLES_NV                                 0x20B3
#endif

#ifndef GLX_AMD_gpu_association
#define GLX_GPU_VENDOR_AMD                                   0x1F00
#define GLX_GPU_RENDERER_STRING_AMD                          0x1F01
#define GLX_GPU_OPENGL_VERSION_STRING_AMD                    0x1F02
#define GLX_GPU_FASTEST_TARGET_GPUS_AMD                      0x21A2
#define GLX_GPU_RAM_AMD                                      0x21A3
#define GLX_GPU_CLOCK_AMD                                    0x21A4
#define GLX_GPU_NUM_PIPES_AMD                                0x21A5
#define GLX_GPU_NUM_SIMD_AMD                                 0x21A6
#define GLX_GPU_NUM_RB_AMD                                   0x21A7
#define GLX_GPU_NUM_SPI_AMD                                  0x21A8
#endif

#ifndef GLX_EXT_create_context_es2_profile
#define GLX_CONTEXT_ES2_PROFILE_BIT_EXT                      0x00000004
#endif

#ifndef GLX_EXT_swap_control_tear
#define GLX_LATE_SWAPS_TEAR_EXT                              0x20F3
#endif

#ifndef GLX_EXT_buffer_age
#define GLX_BACK_BUFFER_AGE_EXT                              0x20F4
#endif

#ifndef GLX_ARB_get_proc_address
typedef void (*__GLXextFuncPtr)(void);
#endif

#ifndef GLX_SGIX_video_source
typedef XID GLXVideoSourceSGIX;
#endif

#ifndef GLX_SGIX_fbconfig
typedef XID GLXFBConfigIDSGIX;
typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;
#endif

#ifndef GLX_SGIX_pbuffer
typedef XID GLXPbufferSGIX;
typedef struct {
    int type;
    unsigned long serial;	  /* # of last request processed by server */
    Bool send_event;		  /* true if this came for SendEvent request */
    Display *display;		  /* display the event was read from */
    GLXDrawable drawable;	  /* i.d. of Drawable */
    int event_type;		  /* GLX_DAMAGED_SGIX or GLX_SAVED_SGIX */
    int draw_type;		  /* GLX_WINDOW_SGIX or GLX_PBUFFER_SGIX */
    unsigned int mask;	  /* mask indicating which buffers are affected*/
    int x, y;
    int width, height;
    int count;		  /* if nonzero, at least this many more */
} GLXBufferClobberEventSGIX;
#endif

#ifndef GLX_NV_video_output
typedef unsigned int GLXVideoDeviceNV;
#endif

#ifndef GLX_NV_video_capture
typedef XID GLXVideoCaptureDeviceNV;
#endif

#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GLX_OML_sync_control extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <inttypes.h>     /* Fallback option */
#endif
#endif


/* GLX_ARB_get_proc_address */
extern __GLXextFuncPtr (APIENTRY *gglXGetProcAddressARB)(const GLubyte* procName);

/* GLX_ARB_multisample */

/* GLX_ARB_fbconfig_float */

/* GLX_ARB_framebuffer_sRGB */

/* GLX_ARB_create_context */
extern GLXContext (APIENTRY *gglXCreateContextAttribsARB)(Display* dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int* attrib_list);

/* GLX_ARB_create_context_profile */

/* GLX_ARB_create_context_robustness */

/* GLX_SGIS_multisample */

/* GLX_EXT_visual_info */

/* GLX_SGI_swap_control */
extern int (APIENTRY *gglXSwapIntervalSGI)(int interval);

/* GLX_SGI_video_sync */
extern int (APIENTRY *gglXGetVideoSyncSGI)(unsigned int* count);
extern int (APIENTRY *gglXWaitVideoSyncSGI)(int divisor, int remainder, unsigned int* count);

/* GLX_SGI_make_current_read */
extern Bool (APIENTRY *gglXMakeCurrentReadSGI)(Display* dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
extern GLXDrawable (APIENTRY *gglXGetCurrentReadDrawableSGI)();

/* GLX_SGIX_video_source */
#ifdef _VL_H
extern GLXVideoSourceSGIX (APIENTRY *gglXCreateGLXVideoSourceSGIX)(Display* display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
extern void (APIENTRY *gglXDestroyGLXVideoSourceSGIX)(Display* dpy, GLXVideoSourceSGIX glxvideosource);
#endif /* _VL_H */

/* GLX_EXT_visual_rating */

/* GLX_EXT_import_context */
extern Display * (APIENTRY *gglXGetCurrentDisplayEXT)();
extern int (APIENTRY *gglXQueryContextInfoEXT)(Display* dpy, GLXContext context, int attribute, int* value);
extern GLXContextID (APIENTRY *gglXGetContextIDEXT)(const GLXContext context);
extern GLXContext (APIENTRY *gglXImportContextEXT)(Display* dpy, GLXContextID contextID);
extern void (APIENTRY *gglXFreeContextEXT)(Display* dpy, GLXContext context);

/* GLX_SGIX_fbconfig */
extern int (APIENTRY *gglXGetFBConfigAttribSGIX)(Display* dpy, GLXFBConfigSGIX config, int attribute, int* value);
extern GLXFBConfigSGIX * (APIENTRY *gglXChooseFBConfigSGIX)(Display* dpy, int screen, int* attrib_list, int* nelements);
extern GLXPixmap (APIENTRY *gglXCreateGLXPixmapWithConfigSGIX)(Display* dpy, GLXFBConfigSGIX config, Pixmap pixmap);
extern GLXContext (APIENTRY *gglXCreateContextWithConfigSGIX)(Display* dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
extern XVisualInfo * (APIENTRY *gglXGetVisualFromFBConfigSGIX)(Display* dpy, GLXFBConfigSGIX config);
extern GLXFBConfigSGIX (APIENTRY *gglXGetFBConfigFromVisualSGIX)(Display* dpy, XVisualInfo* vis);

/* GLX_SGIX_pbuffer */
extern GLXPbufferSGIX (APIENTRY *gglXCreateGLXPbufferSGIX)(Display* dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int* attrib_list);
extern void (APIENTRY *gglXDestroyGLXPbufferSGIX)(Display* dpy, GLXPbufferSGIX pbuf);
extern int (APIENTRY *gglXQueryGLXPbufferSGIX)(Display* dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int* value);
extern void (APIENTRY *gglXSelectEventSGIX)(Display* dpy, GLXDrawable drawable, unsigned long mask);
extern void (APIENTRY *gglXGetSelectedEventSGIX)(Display* dpy, GLXDrawable drawable, unsigned long* mask);

/* GLX_SGI_cushion */
extern void (APIENTRY *gglXCushionSGI)(Display* dpy, Window window, float cushion);

/* GLX_SGIX_video_resize */
extern int (APIENTRY *gglXBindChannelToWindowSGIX)(Display* display, int screen, int channel, Window window);
extern int (APIENTRY *gglXChannelRectSGIX)(Display* display, int screen, int channel, int x, int y, int w, int h);
extern int (APIENTRY *gglXQueryChannelRectSGIX)(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh);
extern int (APIENTRY *gglXQueryChannelDeltasSGIX)(Display* display, int screen, int channel, int* x, int* y, int* w, int* h);
extern int (APIENTRY *gglXChannelRectSyncSGIX)(Display* display, int screen, int channel, GLenum synctype);

/* GLX_SGIX_dmbuffer */
#ifdef _DM_BUFFER_H_
extern Bool (APIENTRY *gglXAssociateDMPbufferSGIX)(Display* dpy, GLXPbufferSGIX pbuffer, DMparams* params, DMbuffer dmbuffer);
#endif /* _DM_BUFFER_H_ */

/* GLX_SGIX_swap_group */
extern void (APIENTRY *gglXJoinSwapGroupSGIX)(Display* dpy, GLXDrawable drawable, GLXDrawable member);

/* GLX_SGIX_swap_barrier */
extern void (APIENTRY *gglXBindSwapBarrierSGIX)(Display* dpy, GLXDrawable drawable, int barrier);
extern Bool (APIENTRY *gglXQueryMaxSwapBarriersSGIX)(Display* dpy, int screen, int* max);

/* GLX_SUN_get_transparent_index */
extern Status (APIENTRY *gglXGetTransparentIndexSUN)(Display* dpy, Window overlay, Window underlay, long* pTransparentIndex);

/* GLX_MESA_copy_sub_buffer */
extern void (APIENTRY *gglXCopySubBufferMESA)(Display* dpy, GLXDrawable drawable, int x, int y, int width, int height);

/* GLX_MESA_pixmap_colormap */
extern GLXPixmap (APIENTRY *gglXCreateGLXPixmapMESA)(Display* dpy, XVisualInfo* visual, Pixmap pixmap, Colormap cmap);

/* GLX_MESA_release_buffers */
extern Bool (APIENTRY *gglXReleaseBuffersMESA)(Display* dpy, GLXDrawable drawable);

/* GLX_MESA_set_3dfx_mode */
extern Bool (APIENTRY *gglXSet3DfxModeMESA)(int mode);

/* GLX_SGIX_visual_select_group */

/* GLX_OML_swap_method */

/* GLX_OML_sync_control */
extern Bool (APIENTRY *gglXGetSyncValuesOML)(Display* dpy, GLXDrawable drawable, int64_t* ust, int64_t* msc, int64_t* sbc);
extern Bool (APIENTRY *gglXGetMscRateOML)(Display* dpy, GLXDrawable drawable, int32_t* numerator, int32_t* denominator);
extern int64_t (APIENTRY *gglXSwapBuffersMscOML)(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
extern Bool (APIENTRY *gglXWaitForMscOML)(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t* ust, int64_t* msc, int64_t* sbc);
extern Bool (APIENTRY *gglXWaitForSbcOML)(Display* dpy, GLXDrawable drawable, int64_t target_sbc, int64_t* ust, int64_t* msc, int64_t* sbc);

/* GLX_NV_float_buffer */

/* GLX_SGIX_hyperpipe */

typedef struct {
    char    pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int     networkId;
} GLXHyperpipeNetworkSGIX;

typedef struct {
    char    pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int     channel;
    unsigned int
	      participationType;
    int     timeSlice;
} GLXHyperpipeConfigSGIX;

typedef struct {
    char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int srcXOrigin, srcYOrigin, srcWidth, srcHeight;
    int destXOrigin, destYOrigin, destWidth, destHeight;
} GLXPipeRect;

typedef struct {
    char pipeName[GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX];
    int XOrigin, YOrigin, maxHeight, maxWidth;
} GLXPipeRectLimits;

extern GLXHyperpipeNetworkSGIX * (APIENTRY *gglXQueryHyperpipeNetworkSGIX)(Display* dpy, int* npipes);
extern int (APIENTRY *gglXHyperpipeConfigSGIX)(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpId);
extern GLXHyperpipeConfigSGIX * (APIENTRY *gglXQueryHyperpipeConfigSGIX)(Display* dpy, int hpId, int* npipes);
extern int (APIENTRY *gglXDestroyHyperpipeConfigSGIX)(Display* dpy, int hpId);
extern int (APIENTRY *gglXBindHyperpipeSGIX)(Display* dpy, int hpId);
extern int (APIENTRY *gglXQueryHyperpipeBestAttribSGIX)(Display* dpy, int timeSlice, int attrib, int size, void* attribList, void* returnAttribList);
extern int (APIENTRY *gglXHyperpipeAttribSGIX)(Display* dpy, int timeSlice, int attrib, int size, void* attribList);
extern int (APIENTRY *gglXQueryHyperpipeAttribSGIX)(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList);

/* GLX_MESA_agp_offset */
extern unsigned int (APIENTRY *gglXGetAGPOffsetMESA)(const void* pointer);

/* GLX_EXT_fbconfig_packed_float */

/* GLX_EXT_framebuffer_sRGB */

/* GLX_EXT_texture_from_pixmap */
extern void (APIENTRY *gglXBindTexImageEXT)(Display* dpy, GLXDrawable drawable, int buffer, const int* attrib_list);
extern void (APIENTRY *gglXReleaseTexImageEXT)(Display* dpy, GLXDrawable drawable, int buffer);

/* GLX_NV_present_video */
extern unsigned int * (APIENTRY *gglXEnumerateVideoDevicesNV)(Display* dpy, int screen, int* nelements);
extern int (APIENTRY *gglXBindVideoDeviceNV)(Display* dpy, unsigned int video_slot, unsigned int video_device, const int* attrib_list);

/* GLX_NV_video_output */
extern int (APIENTRY *gglXGetVideoDeviceNV)(Display* dpy, int screen, int numVideoDevices, GLXVideoDeviceNV* pVideoDevice);
extern int (APIENTRY *gglXReleaseVideoDeviceNV)(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice);
extern int (APIENTRY *gglXBindVideoImageNV)(Display* dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
extern int (APIENTRY *gglXReleaseVideoImageNV)(Display* dpy, GLXPbuffer pbuf);
extern int (APIENTRY *gglXSendPbufferToVideoNV)(Display* dpy, GLXPbuffer pbuf, int iBufferType, unsigned long* pulCounterPbuffer, GLboolean bBlock);
extern int (APIENTRY *gglXGetVideoInfoNV)(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo);

/* GLX_NV_swap_group */
extern Bool (APIENTRY *gglXJoinSwapGroupNV)(Display* dpy, GLXDrawable drawable, GLuint group);
extern Bool (APIENTRY *gglXBindSwapBarrierNV)(Display* dpy, GLuint group, GLuint barrier);
extern Bool (APIENTRY *gglXQuerySwapGroupNV)(Display* dpy, GLXDrawable drawable, GLuint* group, GLuint* barrier);
extern Bool (APIENTRY *gglXQueryMaxSwapGroupsNV)(Display* dpy, int screen, GLuint* maxGroups, GLuint* maxBarriers);
extern Bool (APIENTRY *gglXQueryFrameCountNV)(Display* dpy, int screen, GLuint* count);
extern Bool (APIENTRY *gglXResetFrameCountNV)(Display* dpy, int screen);

/* GLX_NV_video_capture */
extern int (APIENTRY *gglXBindVideoCaptureDeviceNV)(Display* dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
extern GLXVideoCaptureDeviceNV * (APIENTRY *gglXEnumerateVideoCaptureDevicesNV)(Display* dpy, int screen, int* nelements);
extern void (APIENTRY *gglXLockVideoCaptureDeviceNV)(Display* dpy, GLXVideoCaptureDeviceNV device);
extern int (APIENTRY *gglXQueryVideoCaptureDeviceNV)(Display* dpy, GLXVideoCaptureDeviceNV device, int attribute, int* value);
extern void (APIENTRY *gglXReleaseVideoCaptureDeviceNV)(Display* dpy, GLXVideoCaptureDeviceNV device);

/* GLX_EXT_swap_control */
extern void (APIENTRY *gglXSwapIntervalEXT)(Display* dpy, GLXDrawable drawable, int interval);

/* GLX_NV_copy_image */
extern void (APIENTRY *gglXCopyImageSubDataNV)(Display* dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

/* GLX_INTEL_swap_event */

/* GLX_NV_multisample_coverage */

/* GLX_EXT_swap_control_tear */

/* GLX_EXT_buffer_age */

typedef struct {
	int _GLX_ARB_create_context : 1;
	int _GLX_ARB_create_context_profile : 1;
	int _GLX_ARB_create_context_robustness : 1;
	int _GLX_ARB_fbconfig_float : 1;
	int _GLX_ARB_framebuffer_sRGB : 1;
	int _GLX_ARB_get_proc_address : 1;
	int _GLX_ARB_multisample : 1;
	int _GLX_EXT_buffer_age : 1;
	int _GLX_EXT_fbconfig_packed_float : 1;
	int _GLX_EXT_framebuffer_sRGB : 1;
	int _GLX_EXT_import_context : 1;
	int _GLX_EXT_swap_control : 1;
	int _GLX_EXT_swap_control_tear : 1;
	int _GLX_EXT_texture_compression_s3tc : 1;
	int _GLX_EXT_texture_from_pixmap : 1;
	int _GLX_EXT_visual_info : 1;
	int _GLX_EXT_visual_rating : 1;
	int _GLX_INTEL_swap_event : 1;
	int _GLX_MESA_agp_offset : 1;
	int _GLX_MESA_copy_sub_buffer : 1;
	int _GLX_MESA_pixmap_colormap : 1;
	int _GLX_MESA_release_buffers : 1;
	int _GLX_MESA_set_3dfx_mode : 1;
	int _GLX_NV_copy_image : 1;
	int _GLX_NV_float_buffer : 1;
	int _GLX_NV_multisample_coverage : 1;
	int _GLX_NV_present_video : 1;
	int _GLX_NV_swap_group : 1;
	int _GLX_NV_video_capture : 1;
	int _GLX_NV_video_output : 1;
	int _GLX_OML_swap_method : 1;
	int _GLX_OML_sync_control : 1;
	int _GLX_SGIS_multisample : 1;
	int _GLX_SGIX_dmbuffer : 1;
	int _GLX_SGIX_fbconfig : 1;
	int _GLX_SGIX_hyperpipe : 1;
	int _GLX_SGIX_pbuffer : 1;
	int _GLX_SGIX_swap_barrier : 1;
	int _GLX_SGIX_swap_group : 1;
	int _GLX_SGIX_video_resize : 1;
	int _GLX_SGIX_video_source : 1;
	int _GLX_SGIX_visual_select_group : 1;
	int _GLX_SGI_cushion : 1;
	int _GLX_SGI_make_current_read : 1;
	int _GLX_SGI_swap_control : 1;
	int _GLX_SGI_video_sync : 1;
	int _GLX_SUN_get_transparent_index : 1;
} gglxext_t;

extern gglxext_t gglxext;

extern void gglx_init(int enableDebug);
extern void gglx_rebind(int enableDebug);
extern void gglx_check_extensions();

#ifdef __cplusplus
}
#endif

#endif /* __GGLX_H__ */
