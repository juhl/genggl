/*********************************************************************************************
 *
 * gglx.c
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

#include "gglx.h"
#include <string.h>

extern void CheckGLError(const char *msg);
static int _gglBeginStarted = 0;

/* GLX_ARB_get_proc_address */
typedef __GLXextFuncPtr (APIENTRY *PFNGLXGETPROCADDRESSARB)(const GLubyte* procName);
PFNGLXGETPROCADDRESSARB gglXGetProcAddressARB;
static PFNGLXGETPROCADDRESSARB _glXGetProcAddressARB;
static __GLXextFuncPtr APIENTRY d_glXGetProcAddressARB(const GLubyte* procName) {
	__GLXextFuncPtr ret = _glXGetProcAddressARB(procName);
	if (!_gglBeginStarted) { CheckGLError("glXGetProcAddressARB"); }
	return ret;
}

/* GLX_ARB_create_context */
typedef GLXContext (APIENTRY *PFNGLXCREATECONTEXTATTRIBSARB)(Display* dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int* attrib_list);
PFNGLXCREATECONTEXTATTRIBSARB gglXCreateContextAttribsARB;
static PFNGLXCREATECONTEXTATTRIBSARB _glXCreateContextAttribsARB;
static GLXContext APIENTRY d_glXCreateContextAttribsARB(Display* dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int* attrib_list) {
	GLXContext ret = _glXCreateContextAttribsARB(dpy, config, share_context, direct, attrib_list);
	if (!_gglBeginStarted) { CheckGLError("glXCreateContextAttribsARB"); }
	return ret;
}

/* GLX_SGI_swap_control */
typedef int (APIENTRY *PFNGLXSWAPINTERVALSGI)(int interval);
PFNGLXSWAPINTERVALSGI gglXSwapIntervalSGI;
static PFNGLXSWAPINTERVALSGI _glXSwapIntervalSGI;
static int APIENTRY d_glXSwapIntervalSGI(int interval) {
	int ret = _glXSwapIntervalSGI(interval);
	if (!_gglBeginStarted) { CheckGLError("glXSwapIntervalSGI"); }
	return ret;
}

/* GLX_SGI_video_sync */
typedef int (APIENTRY *PFNGLXGETVIDEOSYNCSGI)(unsigned int* count);
PFNGLXGETVIDEOSYNCSGI gglXGetVideoSyncSGI;
static PFNGLXGETVIDEOSYNCSGI _glXGetVideoSyncSGI;
static int APIENTRY d_glXGetVideoSyncSGI(unsigned int* count) {
	int ret = _glXGetVideoSyncSGI(count);
	if (!_gglBeginStarted) { CheckGLError("glXGetVideoSyncSGI"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXWAITVIDEOSYNCSGI)(int divisor, int remainder, unsigned int* count);
PFNGLXWAITVIDEOSYNCSGI gglXWaitVideoSyncSGI;
static PFNGLXWAITVIDEOSYNCSGI _glXWaitVideoSyncSGI;
static int APIENTRY d_glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int* count) {
	int ret = _glXWaitVideoSyncSGI(divisor, remainder, count);
	if (!_gglBeginStarted) { CheckGLError("glXWaitVideoSyncSGI"); }
	return ret;
}

/* GLX_SGI_make_current_read */
typedef Bool (APIENTRY *PFNGLXMAKECURRENTREADSGI)(Display* dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
PFNGLXMAKECURRENTREADSGI gglXMakeCurrentReadSGI;
static PFNGLXMAKECURRENTREADSGI _glXMakeCurrentReadSGI;
static Bool APIENTRY d_glXMakeCurrentReadSGI(Display* dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
	Bool ret = _glXMakeCurrentReadSGI(dpy, draw, read, ctx);
	if (!_gglBeginStarted) { CheckGLError("glXMakeCurrentReadSGI"); }
	return ret;
}
typedef GLXDrawable (APIENTRY *PFNGLXGETCURRENTREADDRAWABLESGI)();
PFNGLXGETCURRENTREADDRAWABLESGI gglXGetCurrentReadDrawableSGI;
static PFNGLXGETCURRENTREADDRAWABLESGI _glXGetCurrentReadDrawableSGI;
static GLXDrawable APIENTRY d_glXGetCurrentReadDrawableSGI() {
	GLXDrawable ret = _glXGetCurrentReadDrawableSGI();
	if (!_gglBeginStarted) { CheckGLError("glXGetCurrentReadDrawableSGI"); }
	return ret;
}

/* GLX_SGIX_video_source */
typedef GLXVideoSourceSGIX (APIENTRY *PFNGLXCREATEGLXVIDEOSOURCESGIX)(Display* display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
PFNGLXCREATEGLXVIDEOSOURCESGIX gglXCreateGLXVideoSourceSGIX;
static PFNGLXCREATEGLXVIDEOSOURCESGIX _glXCreateGLXVideoSourceSGIX;
static GLXVideoSourceSGIX APIENTRY d_glXCreateGLXVideoSourceSGIX(Display* display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode) {
	GLXVideoSourceSGIX ret = _glXCreateGLXVideoSourceSGIX(display, screen, server, path, nodeClass, drainNode);
	if (!_gglBeginStarted) { CheckGLError("glXCreateGLXVideoSourceSGIX"); }
	return ret;
}
typedef void (APIENTRY *PFNGLXDESTROYGLXVIDEOSOURCESGIX)(Display* dpy, GLXVideoSourceSGIX glxvideosource);
PFNGLXDESTROYGLXVIDEOSOURCESGIX gglXDestroyGLXVideoSourceSGIX;
static PFNGLXDESTROYGLXVIDEOSOURCESGIX _glXDestroyGLXVideoSourceSGIX;
static void APIENTRY d_glXDestroyGLXVideoSourceSGIX(Display* dpy, GLXVideoSourceSGIX glxvideosource) {
	_glXDestroyGLXVideoSourceSGIX(dpy, glxvideosource);
	if (!_gglBeginStarted) { CheckGLError("glXDestroyGLXVideoSourceSGIX"); }
}

/* GLX_EXT_import_context */
typedef Display * (APIENTRY *PFNGLXGETCURRENTDISPLAYEXT)();
PFNGLXGETCURRENTDISPLAYEXT gglXGetCurrentDisplayEXT;
static PFNGLXGETCURRENTDISPLAYEXT _glXGetCurrentDisplayEXT;
static Display * APIENTRY d_glXGetCurrentDisplayEXT() {
	Display * ret = _glXGetCurrentDisplayEXT();
	if (!_gglBeginStarted) { CheckGLError("glXGetCurrentDisplayEXT"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXQUERYCONTEXTINFOEXT)(Display* dpy, GLXContext context, int attribute, int* value);
PFNGLXQUERYCONTEXTINFOEXT gglXQueryContextInfoEXT;
static PFNGLXQUERYCONTEXTINFOEXT _glXQueryContextInfoEXT;
static int APIENTRY d_glXQueryContextInfoEXT(Display* dpy, GLXContext context, int attribute, int* value) {
	int ret = _glXQueryContextInfoEXT(dpy, context, attribute, value);
	if (!_gglBeginStarted) { CheckGLError("glXQueryContextInfoEXT"); }
	return ret;
}
typedef GLXContextID (APIENTRY *PFNGLXGETCONTEXTIDEXT)(const GLXContext context);
PFNGLXGETCONTEXTIDEXT gglXGetContextIDEXT;
static PFNGLXGETCONTEXTIDEXT _glXGetContextIDEXT;
static GLXContextID APIENTRY d_glXGetContextIDEXT(const GLXContext context) {
	GLXContextID ret = _glXGetContextIDEXT(context);
	if (!_gglBeginStarted) { CheckGLError("glXGetContextIDEXT"); }
	return ret;
}
typedef GLXContext (APIENTRY *PFNGLXIMPORTCONTEXTEXT)(Display* dpy, GLXContextID contextID);
PFNGLXIMPORTCONTEXTEXT gglXImportContextEXT;
static PFNGLXIMPORTCONTEXTEXT _glXImportContextEXT;
static GLXContext APIENTRY d_glXImportContextEXT(Display* dpy, GLXContextID contextID) {
	GLXContext ret = _glXImportContextEXT(dpy, contextID);
	if (!_gglBeginStarted) { CheckGLError("glXImportContextEXT"); }
	return ret;
}
typedef void (APIENTRY *PFNGLXFREECONTEXTEXT)(Display* dpy, GLXContext context);
PFNGLXFREECONTEXTEXT gglXFreeContextEXT;
static PFNGLXFREECONTEXTEXT _glXFreeContextEXT;
static void APIENTRY d_glXFreeContextEXT(Display* dpy, GLXContext context) {
	_glXFreeContextEXT(dpy, context);
	if (!_gglBeginStarted) { CheckGLError("glXFreeContextEXT"); }
}

/* GLX_SGIX_fbconfig */
typedef int (APIENTRY *PFNGLXGETFBCONFIGATTRIBSGIX)(Display* dpy, GLXFBConfigSGIX config, int attribute, int* value);
PFNGLXGETFBCONFIGATTRIBSGIX gglXGetFBConfigAttribSGIX;
static PFNGLXGETFBCONFIGATTRIBSGIX _glXGetFBConfigAttribSGIX;
static int APIENTRY d_glXGetFBConfigAttribSGIX(Display* dpy, GLXFBConfigSGIX config, int attribute, int* value) {
	int ret = _glXGetFBConfigAttribSGIX(dpy, config, attribute, value);
	if (!_gglBeginStarted) { CheckGLError("glXGetFBConfigAttribSGIX"); }
	return ret;
}
typedef GLXFBConfigSGIX * (APIENTRY *PFNGLXCHOOSEFBCONFIGSGIX)(Display* dpy, int screen, int* attrib_list, int* nelements);
PFNGLXCHOOSEFBCONFIGSGIX gglXChooseFBConfigSGIX;
static PFNGLXCHOOSEFBCONFIGSGIX _glXChooseFBConfigSGIX;
static GLXFBConfigSGIX * APIENTRY d_glXChooseFBConfigSGIX(Display* dpy, int screen, int* attrib_list, int* nelements) {
	GLXFBConfigSGIX * ret = _glXChooseFBConfigSGIX(dpy, screen, attrib_list, nelements);
	if (!_gglBeginStarted) { CheckGLError("glXChooseFBConfigSGIX"); }
	return ret;
}
typedef GLXPixmap (APIENTRY *PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIX)(Display* dpy, GLXFBConfigSGIX config, Pixmap pixmap);
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIX gglXCreateGLXPixmapWithConfigSGIX;
static PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIX _glXCreateGLXPixmapWithConfigSGIX;
static GLXPixmap APIENTRY d_glXCreateGLXPixmapWithConfigSGIX(Display* dpy, GLXFBConfigSGIX config, Pixmap pixmap) {
	GLXPixmap ret = _glXCreateGLXPixmapWithConfigSGIX(dpy, config, pixmap);
	if (!_gglBeginStarted) { CheckGLError("glXCreateGLXPixmapWithConfigSGIX"); }
	return ret;
}
typedef GLXContext (APIENTRY *PFNGLXCREATECONTEXTWITHCONFIGSGIX)(Display* dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
PFNGLXCREATECONTEXTWITHCONFIGSGIX gglXCreateContextWithConfigSGIX;
static PFNGLXCREATECONTEXTWITHCONFIGSGIX _glXCreateContextWithConfigSGIX;
static GLXContext APIENTRY d_glXCreateContextWithConfigSGIX(Display* dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct) {
	GLXContext ret = _glXCreateContextWithConfigSGIX(dpy, config, render_type, share_list, direct);
	if (!_gglBeginStarted) { CheckGLError("glXCreateContextWithConfigSGIX"); }
	return ret;
}
typedef XVisualInfo * (APIENTRY *PFNGLXGETVISUALFROMFBCONFIGSGIX)(Display* dpy, GLXFBConfigSGIX config);
PFNGLXGETVISUALFROMFBCONFIGSGIX gglXGetVisualFromFBConfigSGIX;
static PFNGLXGETVISUALFROMFBCONFIGSGIX _glXGetVisualFromFBConfigSGIX;
static XVisualInfo * APIENTRY d_glXGetVisualFromFBConfigSGIX(Display* dpy, GLXFBConfigSGIX config) {
	XVisualInfo * ret = _glXGetVisualFromFBConfigSGIX(dpy, config);
	if (!_gglBeginStarted) { CheckGLError("glXGetVisualFromFBConfigSGIX"); }
	return ret;
}
typedef GLXFBConfigSGIX (APIENTRY *PFNGLXGETFBCONFIGFROMVISUALSGIX)(Display* dpy, XVisualInfo* vis);
PFNGLXGETFBCONFIGFROMVISUALSGIX gglXGetFBConfigFromVisualSGIX;
static PFNGLXGETFBCONFIGFROMVISUALSGIX _glXGetFBConfigFromVisualSGIX;
static GLXFBConfigSGIX APIENTRY d_glXGetFBConfigFromVisualSGIX(Display* dpy, XVisualInfo* vis) {
	GLXFBConfigSGIX ret = _glXGetFBConfigFromVisualSGIX(dpy, vis);
	if (!_gglBeginStarted) { CheckGLError("glXGetFBConfigFromVisualSGIX"); }
	return ret;
}

/* GLX_SGIX_pbuffer */
typedef GLXPbufferSGIX (APIENTRY *PFNGLXCREATEGLXPBUFFERSGIX)(Display* dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int* attrib_list);
PFNGLXCREATEGLXPBUFFERSGIX gglXCreateGLXPbufferSGIX;
static PFNGLXCREATEGLXPBUFFERSGIX _glXCreateGLXPbufferSGIX;
static GLXPbufferSGIX APIENTRY d_glXCreateGLXPbufferSGIX(Display* dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int* attrib_list) {
	GLXPbufferSGIX ret = _glXCreateGLXPbufferSGIX(dpy, config, width, height, attrib_list);
	if (!_gglBeginStarted) { CheckGLError("glXCreateGLXPbufferSGIX"); }
	return ret;
}
typedef void (APIENTRY *PFNGLXDESTROYGLXPBUFFERSGIX)(Display* dpy, GLXPbufferSGIX pbuf);
PFNGLXDESTROYGLXPBUFFERSGIX gglXDestroyGLXPbufferSGIX;
static PFNGLXDESTROYGLXPBUFFERSGIX _glXDestroyGLXPbufferSGIX;
static void APIENTRY d_glXDestroyGLXPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuf) {
	_glXDestroyGLXPbufferSGIX(dpy, pbuf);
	if (!_gglBeginStarted) { CheckGLError("glXDestroyGLXPbufferSGIX"); }
}
typedef int (APIENTRY *PFNGLXQUERYGLXPBUFFERSGIX)(Display* dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int* value);
PFNGLXQUERYGLXPBUFFERSGIX gglXQueryGLXPbufferSGIX;
static PFNGLXQUERYGLXPBUFFERSGIX _glXQueryGLXPbufferSGIX;
static int APIENTRY d_glXQueryGLXPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int* value) {
	int ret = _glXQueryGLXPbufferSGIX(dpy, pbuf, attribute, value);
	if (!_gglBeginStarted) { CheckGLError("glXQueryGLXPbufferSGIX"); }
	return ret;
}
typedef void (APIENTRY *PFNGLXSELECTEVENTSGIX)(Display* dpy, GLXDrawable drawable, unsigned long mask);
PFNGLXSELECTEVENTSGIX gglXSelectEventSGIX;
static PFNGLXSELECTEVENTSGIX _glXSelectEventSGIX;
static void APIENTRY d_glXSelectEventSGIX(Display* dpy, GLXDrawable drawable, unsigned long mask) {
	_glXSelectEventSGIX(dpy, drawable, mask);
	if (!_gglBeginStarted) { CheckGLError("glXSelectEventSGIX"); }
}
typedef void (APIENTRY *PFNGLXGETSELECTEDEVENTSGIX)(Display* dpy, GLXDrawable drawable, unsigned long* mask);
PFNGLXGETSELECTEDEVENTSGIX gglXGetSelectedEventSGIX;
static PFNGLXGETSELECTEDEVENTSGIX _glXGetSelectedEventSGIX;
static void APIENTRY d_glXGetSelectedEventSGIX(Display* dpy, GLXDrawable drawable, unsigned long* mask) {
	_glXGetSelectedEventSGIX(dpy, drawable, mask);
	if (!_gglBeginStarted) { CheckGLError("glXGetSelectedEventSGIX"); }
}

/* GLX_SGI_cushion */
typedef void (APIENTRY *PFNGLXCUSHIONSGI)(Display* dpy, Window window, float cushion);
PFNGLXCUSHIONSGI gglXCushionSGI;
static PFNGLXCUSHIONSGI _glXCushionSGI;
static void APIENTRY d_glXCushionSGI(Display* dpy, Window window, float cushion) {
	_glXCushionSGI(dpy, window, cushion);
	if (!_gglBeginStarted) { CheckGLError("glXCushionSGI"); }
}

/* GLX_SGIX_video_resize */
typedef int (APIENTRY *PFNGLXBINDCHANNELTOWINDOWSGIX)(Display* display, int screen, int channel, Window window);
PFNGLXBINDCHANNELTOWINDOWSGIX gglXBindChannelToWindowSGIX;
static PFNGLXBINDCHANNELTOWINDOWSGIX _glXBindChannelToWindowSGIX;
static int APIENTRY d_glXBindChannelToWindowSGIX(Display* display, int screen, int channel, Window window) {
	int ret = _glXBindChannelToWindowSGIX(display, screen, channel, window);
	if (!_gglBeginStarted) { CheckGLError("glXBindChannelToWindowSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXCHANNELRECTSGIX)(Display* display, int screen, int channel, int x, int y, int w, int h);
PFNGLXCHANNELRECTSGIX gglXChannelRectSGIX;
static PFNGLXCHANNELRECTSGIX _glXChannelRectSGIX;
static int APIENTRY d_glXChannelRectSGIX(Display* display, int screen, int channel, int x, int y, int w, int h) {
	int ret = _glXChannelRectSGIX(display, screen, channel, x, y, w, h);
	if (!_gglBeginStarted) { CheckGLError("glXChannelRectSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXQUERYCHANNELRECTSGIX)(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh);
PFNGLXQUERYCHANNELRECTSGIX gglXQueryChannelRectSGIX;
static PFNGLXQUERYCHANNELRECTSGIX _glXQueryChannelRectSGIX;
static int APIENTRY d_glXQueryChannelRectSGIX(Display* display, int screen, int channel, int* dx, int* dy, int* dw, int* dh) {
	int ret = _glXQueryChannelRectSGIX(display, screen, channel, dx, dy, dw, dh);
	if (!_gglBeginStarted) { CheckGLError("glXQueryChannelRectSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXQUERYCHANNELDELTASSGIX)(Display* display, int screen, int channel, int* x, int* y, int* w, int* h);
PFNGLXQUERYCHANNELDELTASSGIX gglXQueryChannelDeltasSGIX;
static PFNGLXQUERYCHANNELDELTASSGIX _glXQueryChannelDeltasSGIX;
static int APIENTRY d_glXQueryChannelDeltasSGIX(Display* display, int screen, int channel, int* x, int* y, int* w, int* h) {
	int ret = _glXQueryChannelDeltasSGIX(display, screen, channel, x, y, w, h);
	if (!_gglBeginStarted) { CheckGLError("glXQueryChannelDeltasSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXCHANNELRECTSYNCSGIX)(Display* display, int screen, int channel, GLenum synctype);
PFNGLXCHANNELRECTSYNCSGIX gglXChannelRectSyncSGIX;
static PFNGLXCHANNELRECTSYNCSGIX _glXChannelRectSyncSGIX;
static int APIENTRY d_glXChannelRectSyncSGIX(Display* display, int screen, int channel, GLenum synctype) {
	int ret = _glXChannelRectSyncSGIX(display, screen, channel, synctype);
	if (!_gglBeginStarted) { CheckGLError("glXChannelRectSyncSGIX"); }
	return ret;
}

/* GLX_SGIX_dmbuffer */
typedef Bool (APIENTRY *PFNGLXASSOCIATEDMPBUFFERSGIX)(Display* dpy, GLXPbufferSGIX pbuffer, DMparams* params, DMbuffer dmbuffer);
PFNGLXASSOCIATEDMPBUFFERSGIX gglXAssociateDMPbufferSGIX;
static PFNGLXASSOCIATEDMPBUFFERSGIX _glXAssociateDMPbufferSGIX;
static Bool APIENTRY d_glXAssociateDMPbufferSGIX(Display* dpy, GLXPbufferSGIX pbuffer, DMparams* params, DMbuffer dmbuffer) {
	Bool ret = _glXAssociateDMPbufferSGIX(dpy, pbuffer, params, dmbuffer);
	if (!_gglBeginStarted) { CheckGLError("glXAssociateDMPbufferSGIX"); }
	return ret;
}

/* GLX_SGIX_swap_group */
typedef void (APIENTRY *PFNGLXJOINSWAPGROUPSGIX)(Display* dpy, GLXDrawable drawable, GLXDrawable member);
PFNGLXJOINSWAPGROUPSGIX gglXJoinSwapGroupSGIX;
static PFNGLXJOINSWAPGROUPSGIX _glXJoinSwapGroupSGIX;
static void APIENTRY d_glXJoinSwapGroupSGIX(Display* dpy, GLXDrawable drawable, GLXDrawable member) {
	_glXJoinSwapGroupSGIX(dpy, drawable, member);
	if (!_gglBeginStarted) { CheckGLError("glXJoinSwapGroupSGIX"); }
}

/* GLX_SGIX_swap_barrier */
typedef void (APIENTRY *PFNGLXBINDSWAPBARRIERSGIX)(Display* dpy, GLXDrawable drawable, int barrier);
PFNGLXBINDSWAPBARRIERSGIX gglXBindSwapBarrierSGIX;
static PFNGLXBINDSWAPBARRIERSGIX _glXBindSwapBarrierSGIX;
static void APIENTRY d_glXBindSwapBarrierSGIX(Display* dpy, GLXDrawable drawable, int barrier) {
	_glXBindSwapBarrierSGIX(dpy, drawable, barrier);
	if (!_gglBeginStarted) { CheckGLError("glXBindSwapBarrierSGIX"); }
}
typedef Bool (APIENTRY *PFNGLXQUERYMAXSWAPBARRIERSSGIX)(Display* dpy, int screen, int* max);
PFNGLXQUERYMAXSWAPBARRIERSSGIX gglXQueryMaxSwapBarriersSGIX;
static PFNGLXQUERYMAXSWAPBARRIERSSGIX _glXQueryMaxSwapBarriersSGIX;
static Bool APIENTRY d_glXQueryMaxSwapBarriersSGIX(Display* dpy, int screen, int* max) {
	Bool ret = _glXQueryMaxSwapBarriersSGIX(dpy, screen, max);
	if (!_gglBeginStarted) { CheckGLError("glXQueryMaxSwapBarriersSGIX"); }
	return ret;
}

/* GLX_SUN_get_transparent_index */
typedef Status (APIENTRY *PFNGLXGETTRANSPARENTINDEXSUN)(Display* dpy, Window overlay, Window underlay, long* pTransparentIndex);
PFNGLXGETTRANSPARENTINDEXSUN gglXGetTransparentIndexSUN;
static PFNGLXGETTRANSPARENTINDEXSUN _glXGetTransparentIndexSUN;
static Status APIENTRY d_glXGetTransparentIndexSUN(Display* dpy, Window overlay, Window underlay, long* pTransparentIndex) {
	Status ret = _glXGetTransparentIndexSUN(dpy, overlay, underlay, pTransparentIndex);
	if (!_gglBeginStarted) { CheckGLError("glXGetTransparentIndexSUN"); }
	return ret;
}

/* GLX_MESA_copy_sub_buffer */
typedef void (APIENTRY *PFNGLXCOPYSUBBUFFERMESA)(Display* dpy, GLXDrawable drawable, int x, int y, int width, int height);
PFNGLXCOPYSUBBUFFERMESA gglXCopySubBufferMESA;
static PFNGLXCOPYSUBBUFFERMESA _glXCopySubBufferMESA;
static void APIENTRY d_glXCopySubBufferMESA(Display* dpy, GLXDrawable drawable, int x, int y, int width, int height) {
	_glXCopySubBufferMESA(dpy, drawable, x, y, width, height);
	if (!_gglBeginStarted) { CheckGLError("glXCopySubBufferMESA"); }
}

/* GLX_MESA_pixmap_colormap */
typedef GLXPixmap (APIENTRY *PFNGLXCREATEGLXPIXMAPMESA)(Display* dpy, XVisualInfo* visual, Pixmap pixmap, Colormap cmap);
PFNGLXCREATEGLXPIXMAPMESA gglXCreateGLXPixmapMESA;
static PFNGLXCREATEGLXPIXMAPMESA _glXCreateGLXPixmapMESA;
static GLXPixmap APIENTRY d_glXCreateGLXPixmapMESA(Display* dpy, XVisualInfo* visual, Pixmap pixmap, Colormap cmap) {
	GLXPixmap ret = _glXCreateGLXPixmapMESA(dpy, visual, pixmap, cmap);
	if (!_gglBeginStarted) { CheckGLError("glXCreateGLXPixmapMESA"); }
	return ret;
}

/* GLX_MESA_release_buffers */
typedef Bool (APIENTRY *PFNGLXRELEASEBUFFERSMESA)(Display* dpy, GLXDrawable drawable);
PFNGLXRELEASEBUFFERSMESA gglXReleaseBuffersMESA;
static PFNGLXRELEASEBUFFERSMESA _glXReleaseBuffersMESA;
static Bool APIENTRY d_glXReleaseBuffersMESA(Display* dpy, GLXDrawable drawable) {
	Bool ret = _glXReleaseBuffersMESA(dpy, drawable);
	if (!_gglBeginStarted) { CheckGLError("glXReleaseBuffersMESA"); }
	return ret;
}

/* GLX_MESA_set_3dfx_mode */
typedef Bool (APIENTRY *PFNGLXSET3DFXMODEMESA)(int mode);
PFNGLXSET3DFXMODEMESA gglXSet3DfxModeMESA;
static PFNGLXSET3DFXMODEMESA _glXSet3DfxModeMESA;
static Bool APIENTRY d_glXSet3DfxModeMESA(int mode) {
	Bool ret = _glXSet3DfxModeMESA(mode);
	if (!_gglBeginStarted) { CheckGLError("glXSet3DfxModeMESA"); }
	return ret;
}

/* GLX_OML_sync_control */
typedef Bool (APIENTRY *PFNGLXGETSYNCVALUESOML)(Display* dpy, GLXDrawable drawable, int64_t* ust, int64_t* msc, int64_t* sbc);
PFNGLXGETSYNCVALUESOML gglXGetSyncValuesOML;
static PFNGLXGETSYNCVALUESOML _glXGetSyncValuesOML;
static Bool APIENTRY d_glXGetSyncValuesOML(Display* dpy, GLXDrawable drawable, int64_t* ust, int64_t* msc, int64_t* sbc) {
	Bool ret = _glXGetSyncValuesOML(dpy, drawable, ust, msc, sbc);
	if (!_gglBeginStarted) { CheckGLError("glXGetSyncValuesOML"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXGETMSCRATEOML)(Display* dpy, GLXDrawable drawable, int32_t* numerator, int32_t* denominator);
PFNGLXGETMSCRATEOML gglXGetMscRateOML;
static PFNGLXGETMSCRATEOML _glXGetMscRateOML;
static Bool APIENTRY d_glXGetMscRateOML(Display* dpy, GLXDrawable drawable, int32_t* numerator, int32_t* denominator) {
	Bool ret = _glXGetMscRateOML(dpy, drawable, numerator, denominator);
	if (!_gglBeginStarted) { CheckGLError("glXGetMscRateOML"); }
	return ret;
}
typedef int64_t (APIENTRY *PFNGLXSWAPBUFFERSMSCOML)(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
PFNGLXSWAPBUFFERSMSCOML gglXSwapBuffersMscOML;
static PFNGLXSWAPBUFFERSMSCOML _glXSwapBuffersMscOML;
static int64_t APIENTRY d_glXSwapBuffersMscOML(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder) {
	int64_t ret = _glXSwapBuffersMscOML(dpy, drawable, target_msc, divisor, remainder);
	if (!_gglBeginStarted) { CheckGLError("glXSwapBuffersMscOML"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXWAITFORMSCOML)(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t* ust, int64_t* msc, int64_t* sbc);
PFNGLXWAITFORMSCOML gglXWaitForMscOML;
static PFNGLXWAITFORMSCOML _glXWaitForMscOML;
static Bool APIENTRY d_glXWaitForMscOML(Display* dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t* ust, int64_t* msc, int64_t* sbc) {
	Bool ret = _glXWaitForMscOML(dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc);
	if (!_gglBeginStarted) { CheckGLError("glXWaitForMscOML"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXWAITFORSBCOML)(Display* dpy, GLXDrawable drawable, int64_t target_sbc, int64_t* ust, int64_t* msc, int64_t* sbc);
PFNGLXWAITFORSBCOML gglXWaitForSbcOML;
static PFNGLXWAITFORSBCOML _glXWaitForSbcOML;
static Bool APIENTRY d_glXWaitForSbcOML(Display* dpy, GLXDrawable drawable, int64_t target_sbc, int64_t* ust, int64_t* msc, int64_t* sbc) {
	Bool ret = _glXWaitForSbcOML(dpy, drawable, target_sbc, ust, msc, sbc);
	if (!_gglBeginStarted) { CheckGLError("glXWaitForSbcOML"); }
	return ret;
}

/* GLX_SGIX_hyperpipe */
typedef GLXHyperpipeNetworkSGIX * (APIENTRY *PFNGLXQUERYHYPERPIPENETWORKSGIX)(Display* dpy, int* npipes);
PFNGLXQUERYHYPERPIPENETWORKSGIX gglXQueryHyperpipeNetworkSGIX;
static PFNGLXQUERYHYPERPIPENETWORKSGIX _glXQueryHyperpipeNetworkSGIX;
static GLXHyperpipeNetworkSGIX * APIENTRY d_glXQueryHyperpipeNetworkSGIX(Display* dpy, int* npipes) {
	GLXHyperpipeNetworkSGIX * ret = _glXQueryHyperpipeNetworkSGIX(dpy, npipes);
	if (!_gglBeginStarted) { CheckGLError("glXQueryHyperpipeNetworkSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXHYPERPIPECONFIGSGIX)(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpId);
PFNGLXHYPERPIPECONFIGSGIX gglXHyperpipeConfigSGIX;
static PFNGLXHYPERPIPECONFIGSGIX _glXHyperpipeConfigSGIX;
static int APIENTRY d_glXHyperpipeConfigSGIX(Display* dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX* cfg, int* hpId) {
	int ret = _glXHyperpipeConfigSGIX(dpy, networkId, npipes, cfg, hpId);
	if (!_gglBeginStarted) { CheckGLError("glXHyperpipeConfigSGIX"); }
	return ret;
}
typedef GLXHyperpipeConfigSGIX * (APIENTRY *PFNGLXQUERYHYPERPIPECONFIGSGIX)(Display* dpy, int hpId, int* npipes);
PFNGLXQUERYHYPERPIPECONFIGSGIX gglXQueryHyperpipeConfigSGIX;
static PFNGLXQUERYHYPERPIPECONFIGSGIX _glXQueryHyperpipeConfigSGIX;
static GLXHyperpipeConfigSGIX * APIENTRY d_glXQueryHyperpipeConfigSGIX(Display* dpy, int hpId, int* npipes) {
	GLXHyperpipeConfigSGIX * ret = _glXQueryHyperpipeConfigSGIX(dpy, hpId, npipes);
	if (!_gglBeginStarted) { CheckGLError("glXQueryHyperpipeConfigSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXDESTROYHYPERPIPECONFIGSGIX)(Display* dpy, int hpId);
PFNGLXDESTROYHYPERPIPECONFIGSGIX gglXDestroyHyperpipeConfigSGIX;
static PFNGLXDESTROYHYPERPIPECONFIGSGIX _glXDestroyHyperpipeConfigSGIX;
static int APIENTRY d_glXDestroyHyperpipeConfigSGIX(Display* dpy, int hpId) {
	int ret = _glXDestroyHyperpipeConfigSGIX(dpy, hpId);
	if (!_gglBeginStarted) { CheckGLError("glXDestroyHyperpipeConfigSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXBINDHYPERPIPESGIX)(Display* dpy, int hpId);
PFNGLXBINDHYPERPIPESGIX gglXBindHyperpipeSGIX;
static PFNGLXBINDHYPERPIPESGIX _glXBindHyperpipeSGIX;
static int APIENTRY d_glXBindHyperpipeSGIX(Display* dpy, int hpId) {
	int ret = _glXBindHyperpipeSGIX(dpy, hpId);
	if (!_gglBeginStarted) { CheckGLError("glXBindHyperpipeSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXQUERYHYPERPIPEBESTATTRIBSGIX)(Display* dpy, int timeSlice, int attrib, int size, void* attribList, void* returnAttribList);
PFNGLXQUERYHYPERPIPEBESTATTRIBSGIX gglXQueryHyperpipeBestAttribSGIX;
static PFNGLXQUERYHYPERPIPEBESTATTRIBSGIX _glXQueryHyperpipeBestAttribSGIX;
static int APIENTRY d_glXQueryHyperpipeBestAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList, void* returnAttribList) {
	int ret = _glXQueryHyperpipeBestAttribSGIX(dpy, timeSlice, attrib, size, attribList, returnAttribList);
	if (!_gglBeginStarted) { CheckGLError("glXQueryHyperpipeBestAttribSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXHYPERPIPEATTRIBSGIX)(Display* dpy, int timeSlice, int attrib, int size, void* attribList);
PFNGLXHYPERPIPEATTRIBSGIX gglXHyperpipeAttribSGIX;
static PFNGLXHYPERPIPEATTRIBSGIX _glXHyperpipeAttribSGIX;
static int APIENTRY d_glXHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* attribList) {
	int ret = _glXHyperpipeAttribSGIX(dpy, timeSlice, attrib, size, attribList);
	if (!_gglBeginStarted) { CheckGLError("glXHyperpipeAttribSGIX"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXQUERYHYPERPIPEATTRIBSGIX)(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList);
PFNGLXQUERYHYPERPIPEATTRIBSGIX gglXQueryHyperpipeAttribSGIX;
static PFNGLXQUERYHYPERPIPEATTRIBSGIX _glXQueryHyperpipeAttribSGIX;
static int APIENTRY d_glXQueryHyperpipeAttribSGIX(Display* dpy, int timeSlice, int attrib, int size, void* returnAttribList) {
	int ret = _glXQueryHyperpipeAttribSGIX(dpy, timeSlice, attrib, size, returnAttribList);
	if (!_gglBeginStarted) { CheckGLError("glXQueryHyperpipeAttribSGIX"); }
	return ret;
}

/* GLX_MESA_agp_offset */
typedef unsigned int (APIENTRY *PFNGLXGETAGPOFFSETMESA)(const void* pointer);
PFNGLXGETAGPOFFSETMESA gglXGetAGPOffsetMESA;
static PFNGLXGETAGPOFFSETMESA _glXGetAGPOffsetMESA;
static unsigned int APIENTRY d_glXGetAGPOffsetMESA(const void* pointer) {
	unsigned int ret = _glXGetAGPOffsetMESA(pointer);
	if (!_gglBeginStarted) { CheckGLError("glXGetAGPOffsetMESA"); }
	return ret;
}

/* GLX_EXT_texture_from_pixmap */
typedef void (APIENTRY *PFNGLXBINDTEXIMAGEEXT)(Display* dpy, GLXDrawable drawable, int buffer, const int* attrib_list);
PFNGLXBINDTEXIMAGEEXT gglXBindTexImageEXT;
static PFNGLXBINDTEXIMAGEEXT _glXBindTexImageEXT;
static void APIENTRY d_glXBindTexImageEXT(Display* dpy, GLXDrawable drawable, int buffer, const int* attrib_list) {
	_glXBindTexImageEXT(dpy, drawable, buffer, attrib_list);
	if (!_gglBeginStarted) { CheckGLError("glXBindTexImageEXT"); }
}
typedef void (APIENTRY *PFNGLXRELEASETEXIMAGEEXT)(Display* dpy, GLXDrawable drawable, int buffer);
PFNGLXRELEASETEXIMAGEEXT gglXReleaseTexImageEXT;
static PFNGLXRELEASETEXIMAGEEXT _glXReleaseTexImageEXT;
static void APIENTRY d_glXReleaseTexImageEXT(Display* dpy, GLXDrawable drawable, int buffer) {
	_glXReleaseTexImageEXT(dpy, drawable, buffer);
	if (!_gglBeginStarted) { CheckGLError("glXReleaseTexImageEXT"); }
}

/* GLX_NV_present_video */
typedef unsigned int * (APIENTRY *PFNGLXENUMERATEVIDEODEVICESNV)(Display* dpy, int screen, int* nelements);
PFNGLXENUMERATEVIDEODEVICESNV gglXEnumerateVideoDevicesNV;
static PFNGLXENUMERATEVIDEODEVICESNV _glXEnumerateVideoDevicesNV;
static unsigned int * APIENTRY d_glXEnumerateVideoDevicesNV(Display* dpy, int screen, int* nelements) {
	unsigned int * ret = _glXEnumerateVideoDevicesNV(dpy, screen, nelements);
	if (!_gglBeginStarted) { CheckGLError("glXEnumerateVideoDevicesNV"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXBINDVIDEODEVICENV)(Display* dpy, unsigned int video_slot, unsigned int video_device, const int* attrib_list);
PFNGLXBINDVIDEODEVICENV gglXBindVideoDeviceNV;
static PFNGLXBINDVIDEODEVICENV _glXBindVideoDeviceNV;
static int APIENTRY d_glXBindVideoDeviceNV(Display* dpy, unsigned int video_slot, unsigned int video_device, const int* attrib_list) {
	int ret = _glXBindVideoDeviceNV(dpy, video_slot, video_device, attrib_list);
	if (!_gglBeginStarted) { CheckGLError("glXBindVideoDeviceNV"); }
	return ret;
}

/* GLX_NV_video_output */
typedef int (APIENTRY *PFNGLXGETVIDEODEVICENV)(Display* dpy, int screen, int numVideoDevices, GLXVideoDeviceNV* pVideoDevice);
PFNGLXGETVIDEODEVICENV gglXGetVideoDeviceNV;
static PFNGLXGETVIDEODEVICENV _glXGetVideoDeviceNV;
static int APIENTRY d_glXGetVideoDeviceNV(Display* dpy, int screen, int numVideoDevices, GLXVideoDeviceNV* pVideoDevice) {
	int ret = _glXGetVideoDeviceNV(dpy, screen, numVideoDevices, pVideoDevice);
	if (!_gglBeginStarted) { CheckGLError("glXGetVideoDeviceNV"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXRELEASEVIDEODEVICENV)(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice);
PFNGLXRELEASEVIDEODEVICENV gglXReleaseVideoDeviceNV;
static PFNGLXRELEASEVIDEODEVICENV _glXReleaseVideoDeviceNV;
static int APIENTRY d_glXReleaseVideoDeviceNV(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice) {
	int ret = _glXReleaseVideoDeviceNV(dpy, screen, VideoDevice);
	if (!_gglBeginStarted) { CheckGLError("glXReleaseVideoDeviceNV"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXBINDVIDEOIMAGENV)(Display* dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
PFNGLXBINDVIDEOIMAGENV gglXBindVideoImageNV;
static PFNGLXBINDVIDEOIMAGENV _glXBindVideoImageNV;
static int APIENTRY d_glXBindVideoImageNV(Display* dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer) {
	int ret = _glXBindVideoImageNV(dpy, VideoDevice, pbuf, iVideoBuffer);
	if (!_gglBeginStarted) { CheckGLError("glXBindVideoImageNV"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXRELEASEVIDEOIMAGENV)(Display* dpy, GLXPbuffer pbuf);
PFNGLXRELEASEVIDEOIMAGENV gglXReleaseVideoImageNV;
static PFNGLXRELEASEVIDEOIMAGENV _glXReleaseVideoImageNV;
static int APIENTRY d_glXReleaseVideoImageNV(Display* dpy, GLXPbuffer pbuf) {
	int ret = _glXReleaseVideoImageNV(dpy, pbuf);
	if (!_gglBeginStarted) { CheckGLError("glXReleaseVideoImageNV"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXSENDPBUFFERTOVIDEONV)(Display* dpy, GLXPbuffer pbuf, int iBufferType, unsigned long* pulCounterPbuffer, GLboolean bBlock);
PFNGLXSENDPBUFFERTOVIDEONV gglXSendPbufferToVideoNV;
static PFNGLXSENDPBUFFERTOVIDEONV _glXSendPbufferToVideoNV;
static int APIENTRY d_glXSendPbufferToVideoNV(Display* dpy, GLXPbuffer pbuf, int iBufferType, unsigned long* pulCounterPbuffer, GLboolean bBlock) {
	int ret = _glXSendPbufferToVideoNV(dpy, pbuf, iBufferType, pulCounterPbuffer, bBlock);
	if (!_gglBeginStarted) { CheckGLError("glXSendPbufferToVideoNV"); }
	return ret;
}
typedef int (APIENTRY *PFNGLXGETVIDEOINFONV)(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo);
PFNGLXGETVIDEOINFONV gglXGetVideoInfoNV;
static PFNGLXGETVIDEOINFONV _glXGetVideoInfoNV;
static int APIENTRY d_glXGetVideoInfoNV(Display* dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo) {
	int ret = _glXGetVideoInfoNV(dpy, screen, VideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
	if (!_gglBeginStarted) { CheckGLError("glXGetVideoInfoNV"); }
	return ret;
}

/* GLX_NV_swap_group */
typedef Bool (APIENTRY *PFNGLXJOINSWAPGROUPNV)(Display* dpy, GLXDrawable drawable, GLuint group);
PFNGLXJOINSWAPGROUPNV gglXJoinSwapGroupNV;
static PFNGLXJOINSWAPGROUPNV _glXJoinSwapGroupNV;
static Bool APIENTRY d_glXJoinSwapGroupNV(Display* dpy, GLXDrawable drawable, GLuint group) {
	Bool ret = _glXJoinSwapGroupNV(dpy, drawable, group);
	if (!_gglBeginStarted) { CheckGLError("glXJoinSwapGroupNV"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXBINDSWAPBARRIERNV)(Display* dpy, GLuint group, GLuint barrier);
PFNGLXBINDSWAPBARRIERNV gglXBindSwapBarrierNV;
static PFNGLXBINDSWAPBARRIERNV _glXBindSwapBarrierNV;
static Bool APIENTRY d_glXBindSwapBarrierNV(Display* dpy, GLuint group, GLuint barrier) {
	Bool ret = _glXBindSwapBarrierNV(dpy, group, barrier);
	if (!_gglBeginStarted) { CheckGLError("glXBindSwapBarrierNV"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXQUERYSWAPGROUPNV)(Display* dpy, GLXDrawable drawable, GLuint* group, GLuint* barrier);
PFNGLXQUERYSWAPGROUPNV gglXQuerySwapGroupNV;
static PFNGLXQUERYSWAPGROUPNV _glXQuerySwapGroupNV;
static Bool APIENTRY d_glXQuerySwapGroupNV(Display* dpy, GLXDrawable drawable, GLuint* group, GLuint* barrier) {
	Bool ret = _glXQuerySwapGroupNV(dpy, drawable, group, barrier);
	if (!_gglBeginStarted) { CheckGLError("glXQuerySwapGroupNV"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXQUERYMAXSWAPGROUPSNV)(Display* dpy, int screen, GLuint* maxGroups, GLuint* maxBarriers);
PFNGLXQUERYMAXSWAPGROUPSNV gglXQueryMaxSwapGroupsNV;
static PFNGLXQUERYMAXSWAPGROUPSNV _glXQueryMaxSwapGroupsNV;
static Bool APIENTRY d_glXQueryMaxSwapGroupsNV(Display* dpy, int screen, GLuint* maxGroups, GLuint* maxBarriers) {
	Bool ret = _glXQueryMaxSwapGroupsNV(dpy, screen, maxGroups, maxBarriers);
	if (!_gglBeginStarted) { CheckGLError("glXQueryMaxSwapGroupsNV"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXQUERYFRAMECOUNTNV)(Display* dpy, int screen, GLuint* count);
PFNGLXQUERYFRAMECOUNTNV gglXQueryFrameCountNV;
static PFNGLXQUERYFRAMECOUNTNV _glXQueryFrameCountNV;
static Bool APIENTRY d_glXQueryFrameCountNV(Display* dpy, int screen, GLuint* count) {
	Bool ret = _glXQueryFrameCountNV(dpy, screen, count);
	if (!_gglBeginStarted) { CheckGLError("glXQueryFrameCountNV"); }
	return ret;
}
typedef Bool (APIENTRY *PFNGLXRESETFRAMECOUNTNV)(Display* dpy, int screen);
PFNGLXRESETFRAMECOUNTNV gglXResetFrameCountNV;
static PFNGLXRESETFRAMECOUNTNV _glXResetFrameCountNV;
static Bool APIENTRY d_glXResetFrameCountNV(Display* dpy, int screen) {
	Bool ret = _glXResetFrameCountNV(dpy, screen);
	if (!_gglBeginStarted) { CheckGLError("glXResetFrameCountNV"); }
	return ret;
}

/* GLX_NV_video_capture */
typedef int (APIENTRY *PFNGLXBINDVIDEOCAPTUREDEVICENV)(Display* dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
PFNGLXBINDVIDEOCAPTUREDEVICENV gglXBindVideoCaptureDeviceNV;
static PFNGLXBINDVIDEOCAPTUREDEVICENV _glXBindVideoCaptureDeviceNV;
static int APIENTRY d_glXBindVideoCaptureDeviceNV(Display* dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device) {
	int ret = _glXBindVideoCaptureDeviceNV(dpy, video_capture_slot, device);
	if (!_gglBeginStarted) { CheckGLError("glXBindVideoCaptureDeviceNV"); }
	return ret;
}
typedef GLXVideoCaptureDeviceNV * (APIENTRY *PFNGLXENUMERATEVIDEOCAPTUREDEVICESNV)(Display* dpy, int screen, int* nelements);
PFNGLXENUMERATEVIDEOCAPTUREDEVICESNV gglXEnumerateVideoCaptureDevicesNV;
static PFNGLXENUMERATEVIDEOCAPTUREDEVICESNV _glXEnumerateVideoCaptureDevicesNV;
static GLXVideoCaptureDeviceNV * APIENTRY d_glXEnumerateVideoCaptureDevicesNV(Display* dpy, int screen, int* nelements) {
	GLXVideoCaptureDeviceNV * ret = _glXEnumerateVideoCaptureDevicesNV(dpy, screen, nelements);
	if (!_gglBeginStarted) { CheckGLError("glXEnumerateVideoCaptureDevicesNV"); }
	return ret;
}
typedef void (APIENTRY *PFNGLXLOCKVIDEOCAPTUREDEVICENV)(Display* dpy, GLXVideoCaptureDeviceNV device);
PFNGLXLOCKVIDEOCAPTUREDEVICENV gglXLockVideoCaptureDeviceNV;
static PFNGLXLOCKVIDEOCAPTUREDEVICENV _glXLockVideoCaptureDeviceNV;
static void APIENTRY d_glXLockVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device) {
	_glXLockVideoCaptureDeviceNV(dpy, device);
	if (!_gglBeginStarted) { CheckGLError("glXLockVideoCaptureDeviceNV"); }
}
typedef int (APIENTRY *PFNGLXQUERYVIDEOCAPTUREDEVICENV)(Display* dpy, GLXVideoCaptureDeviceNV device, int attribute, int* value);
PFNGLXQUERYVIDEOCAPTUREDEVICENV gglXQueryVideoCaptureDeviceNV;
static PFNGLXQUERYVIDEOCAPTUREDEVICENV _glXQueryVideoCaptureDeviceNV;
static int APIENTRY d_glXQueryVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device, int attribute, int* value) {
	int ret = _glXQueryVideoCaptureDeviceNV(dpy, device, attribute, value);
	if (!_gglBeginStarted) { CheckGLError("glXQueryVideoCaptureDeviceNV"); }
	return ret;
}
typedef void (APIENTRY *PFNGLXRELEASEVIDEOCAPTUREDEVICENV)(Display* dpy, GLXVideoCaptureDeviceNV device);
PFNGLXRELEASEVIDEOCAPTUREDEVICENV gglXReleaseVideoCaptureDeviceNV;
static PFNGLXRELEASEVIDEOCAPTUREDEVICENV _glXReleaseVideoCaptureDeviceNV;
static void APIENTRY d_glXReleaseVideoCaptureDeviceNV(Display* dpy, GLXVideoCaptureDeviceNV device) {
	_glXReleaseVideoCaptureDeviceNV(dpy, device);
	if (!_gglBeginStarted) { CheckGLError("glXReleaseVideoCaptureDeviceNV"); }
}

/* GLX_EXT_swap_control */
typedef void (APIENTRY *PFNGLXSWAPINTERVALEXT)(Display* dpy, GLXDrawable drawable, int interval);
PFNGLXSWAPINTERVALEXT gglXSwapIntervalEXT;
static PFNGLXSWAPINTERVALEXT _glXSwapIntervalEXT;
static void APIENTRY d_glXSwapIntervalEXT(Display* dpy, GLXDrawable drawable, int interval) {
	_glXSwapIntervalEXT(dpy, drawable, interval);
	if (!_gglBeginStarted) { CheckGLError("glXSwapIntervalEXT"); }
}

/* GLX_NV_copy_image */
typedef void (APIENTRY *PFNGLXCOPYIMAGESUBDATANV)(Display* dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
PFNGLXCOPYIMAGESUBDATANV gglXCopyImageSubDataNV;
static PFNGLXCOPYIMAGESUBDATANV _glXCopyImageSubDataNV;
static void APIENTRY d_glXCopyImageSubDataNV(Display* dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
	_glXCopyImageSubDataNV(dpy, srcCtx, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstCtx, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
	if (!_gglBeginStarted) { CheckGLError("glXCopyImageSubDataNV"); }
}

#ifdef _WIN32
#define GPA(a) wglGetProcAddress(#a)
#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#define GPA(a) mglGetProcAddress(#a)
extern void *mglGetProcAddress(const char *name);
#elif defined(__linux__)
#define GPA(a) glXGetProcAddressARB((const GLubyte *)#a)
#endif

gglxext_t gglxext;

void gglx_init(int enableDebug) {
	/* GLX_ARB_get_proc_address */
	_glXGetProcAddressARB = (PFNGLXGETPROCADDRESSARB)GPA(glXGetProcAddressARB);
	/* GLX_ARB_create_context */
	_glXCreateContextAttribsARB = (PFNGLXCREATECONTEXTATTRIBSARB)GPA(glXCreateContextAttribsARB);
	/* GLX_SGI_swap_control */
	_glXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGI)GPA(glXSwapIntervalSGI);
	/* GLX_SGI_video_sync */
	_glXGetVideoSyncSGI = (PFNGLXGETVIDEOSYNCSGI)GPA(glXGetVideoSyncSGI);
	_glXWaitVideoSyncSGI = (PFNGLXWAITVIDEOSYNCSGI)GPA(glXWaitVideoSyncSGI);
	/* GLX_SGI_make_current_read */
	_glXMakeCurrentReadSGI = (PFNGLXMAKECURRENTREADSGI)GPA(glXMakeCurrentReadSGI);
	_glXGetCurrentReadDrawableSGI = (PFNGLXGETCURRENTREADDRAWABLESGI)GPA(glXGetCurrentReadDrawableSGI);
	/* GLX_SGIX_video_source */
	_glXCreateGLXVideoSourceSGIX = (PFNGLXCREATEGLXVIDEOSOURCESGIX)GPA(glXCreateGLXVideoSourceSGIX);
	_glXDestroyGLXVideoSourceSGIX = (PFNGLXDESTROYGLXVIDEOSOURCESGIX)GPA(glXDestroyGLXVideoSourceSGIX);
	/* GLX_EXT_import_context */
	_glXGetCurrentDisplayEXT = (PFNGLXGETCURRENTDISPLAYEXT)GPA(glXGetCurrentDisplayEXT);
	_glXQueryContextInfoEXT = (PFNGLXQUERYCONTEXTINFOEXT)GPA(glXQueryContextInfoEXT);
	_glXGetContextIDEXT = (PFNGLXGETCONTEXTIDEXT)GPA(glXGetContextIDEXT);
	_glXImportContextEXT = (PFNGLXIMPORTCONTEXTEXT)GPA(glXImportContextEXT);
	_glXFreeContextEXT = (PFNGLXFREECONTEXTEXT)GPA(glXFreeContextEXT);
	/* GLX_SGIX_fbconfig */
	_glXGetFBConfigAttribSGIX = (PFNGLXGETFBCONFIGATTRIBSGIX)GPA(glXGetFBConfigAttribSGIX);
	_glXChooseFBConfigSGIX = (PFNGLXCHOOSEFBCONFIGSGIX)GPA(glXChooseFBConfigSGIX);
	_glXCreateGLXPixmapWithConfigSGIX = (PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIX)GPA(glXCreateGLXPixmapWithConfigSGIX);
	_glXCreateContextWithConfigSGIX = (PFNGLXCREATECONTEXTWITHCONFIGSGIX)GPA(glXCreateContextWithConfigSGIX);
	_glXGetVisualFromFBConfigSGIX = (PFNGLXGETVISUALFROMFBCONFIGSGIX)GPA(glXGetVisualFromFBConfigSGIX);
	_glXGetFBConfigFromVisualSGIX = (PFNGLXGETFBCONFIGFROMVISUALSGIX)GPA(glXGetFBConfigFromVisualSGIX);
	/* GLX_SGIX_pbuffer */
	_glXCreateGLXPbufferSGIX = (PFNGLXCREATEGLXPBUFFERSGIX)GPA(glXCreateGLXPbufferSGIX);
	_glXDestroyGLXPbufferSGIX = (PFNGLXDESTROYGLXPBUFFERSGIX)GPA(glXDestroyGLXPbufferSGIX);
	_glXQueryGLXPbufferSGIX = (PFNGLXQUERYGLXPBUFFERSGIX)GPA(glXQueryGLXPbufferSGIX);
	_glXSelectEventSGIX = (PFNGLXSELECTEVENTSGIX)GPA(glXSelectEventSGIX);
	_glXGetSelectedEventSGIX = (PFNGLXGETSELECTEDEVENTSGIX)GPA(glXGetSelectedEventSGIX);
	/* GLX_SGI_cushion */
	_glXCushionSGI = (PFNGLXCUSHIONSGI)GPA(glXCushionSGI);
	/* GLX_SGIX_video_resize */
	_glXBindChannelToWindowSGIX = (PFNGLXBINDCHANNELTOWINDOWSGIX)GPA(glXBindChannelToWindowSGIX);
	_glXChannelRectSGIX = (PFNGLXCHANNELRECTSGIX)GPA(glXChannelRectSGIX);
	_glXQueryChannelRectSGIX = (PFNGLXQUERYCHANNELRECTSGIX)GPA(glXQueryChannelRectSGIX);
	_glXQueryChannelDeltasSGIX = (PFNGLXQUERYCHANNELDELTASSGIX)GPA(glXQueryChannelDeltasSGIX);
	_glXChannelRectSyncSGIX = (PFNGLXCHANNELRECTSYNCSGIX)GPA(glXChannelRectSyncSGIX);
	/* GLX_SGIX_dmbuffer */
	_glXAssociateDMPbufferSGIX = (PFNGLXASSOCIATEDMPBUFFERSGIX)GPA(glXAssociateDMPbufferSGIX);
	/* GLX_SGIX_swap_group */
	_glXJoinSwapGroupSGIX = (PFNGLXJOINSWAPGROUPSGIX)GPA(glXJoinSwapGroupSGIX);
	/* GLX_SGIX_swap_barrier */
	_glXBindSwapBarrierSGIX = (PFNGLXBINDSWAPBARRIERSGIX)GPA(glXBindSwapBarrierSGIX);
	_glXQueryMaxSwapBarriersSGIX = (PFNGLXQUERYMAXSWAPBARRIERSSGIX)GPA(glXQueryMaxSwapBarriersSGIX);
	/* GLX_SUN_get_transparent_index */
	_glXGetTransparentIndexSUN = (PFNGLXGETTRANSPARENTINDEXSUN)GPA(glXGetTransparentIndexSUN);
	/* GLX_MESA_copy_sub_buffer */
	_glXCopySubBufferMESA = (PFNGLXCOPYSUBBUFFERMESA)GPA(glXCopySubBufferMESA);
	/* GLX_MESA_pixmap_colormap */
	_glXCreateGLXPixmapMESA = (PFNGLXCREATEGLXPIXMAPMESA)GPA(glXCreateGLXPixmapMESA);
	/* GLX_MESA_release_buffers */
	_glXReleaseBuffersMESA = (PFNGLXRELEASEBUFFERSMESA)GPA(glXReleaseBuffersMESA);
	/* GLX_MESA_set_3dfx_mode */
	_glXSet3DfxModeMESA = (PFNGLXSET3DFXMODEMESA)GPA(glXSet3DfxModeMESA);
	/* GLX_OML_sync_control */
	_glXGetSyncValuesOML = (PFNGLXGETSYNCVALUESOML)GPA(glXGetSyncValuesOML);
	_glXGetMscRateOML = (PFNGLXGETMSCRATEOML)GPA(glXGetMscRateOML);
	_glXSwapBuffersMscOML = (PFNGLXSWAPBUFFERSMSCOML)GPA(glXSwapBuffersMscOML);
	_glXWaitForMscOML = (PFNGLXWAITFORMSCOML)GPA(glXWaitForMscOML);
	_glXWaitForSbcOML = (PFNGLXWAITFORSBCOML)GPA(glXWaitForSbcOML);
	/* GLX_SGIX_hyperpipe */
	_glXQueryHyperpipeNetworkSGIX = (PFNGLXQUERYHYPERPIPENETWORKSGIX)GPA(glXQueryHyperpipeNetworkSGIX);
	_glXHyperpipeConfigSGIX = (PFNGLXHYPERPIPECONFIGSGIX)GPA(glXHyperpipeConfigSGIX);
	_glXQueryHyperpipeConfigSGIX = (PFNGLXQUERYHYPERPIPECONFIGSGIX)GPA(glXQueryHyperpipeConfigSGIX);
	_glXDestroyHyperpipeConfigSGIX = (PFNGLXDESTROYHYPERPIPECONFIGSGIX)GPA(glXDestroyHyperpipeConfigSGIX);
	_glXBindHyperpipeSGIX = (PFNGLXBINDHYPERPIPESGIX)GPA(glXBindHyperpipeSGIX);
	_glXQueryHyperpipeBestAttribSGIX = (PFNGLXQUERYHYPERPIPEBESTATTRIBSGIX)GPA(glXQueryHyperpipeBestAttribSGIX);
	_glXHyperpipeAttribSGIX = (PFNGLXHYPERPIPEATTRIBSGIX)GPA(glXHyperpipeAttribSGIX);
	_glXQueryHyperpipeAttribSGIX = (PFNGLXQUERYHYPERPIPEATTRIBSGIX)GPA(glXQueryHyperpipeAttribSGIX);
	/* GLX_MESA_agp_offset */
	_glXGetAGPOffsetMESA = (PFNGLXGETAGPOFFSETMESA)GPA(glXGetAGPOffsetMESA);
	/* GLX_EXT_texture_from_pixmap */
	_glXBindTexImageEXT = (PFNGLXBINDTEXIMAGEEXT)GPA(glXBindTexImageEXT);
	_glXReleaseTexImageEXT = (PFNGLXRELEASETEXIMAGEEXT)GPA(glXReleaseTexImageEXT);
	/* GLX_NV_present_video */
	_glXEnumerateVideoDevicesNV = (PFNGLXENUMERATEVIDEODEVICESNV)GPA(glXEnumerateVideoDevicesNV);
	_glXBindVideoDeviceNV = (PFNGLXBINDVIDEODEVICENV)GPA(glXBindVideoDeviceNV);
	/* GLX_NV_video_output */
	_glXGetVideoDeviceNV = (PFNGLXGETVIDEODEVICENV)GPA(glXGetVideoDeviceNV);
	_glXReleaseVideoDeviceNV = (PFNGLXRELEASEVIDEODEVICENV)GPA(glXReleaseVideoDeviceNV);
	_glXBindVideoImageNV = (PFNGLXBINDVIDEOIMAGENV)GPA(glXBindVideoImageNV);
	_glXReleaseVideoImageNV = (PFNGLXRELEASEVIDEOIMAGENV)GPA(glXReleaseVideoImageNV);
	_glXSendPbufferToVideoNV = (PFNGLXSENDPBUFFERTOVIDEONV)GPA(glXSendPbufferToVideoNV);
	_glXGetVideoInfoNV = (PFNGLXGETVIDEOINFONV)GPA(glXGetVideoInfoNV);
	/* GLX_NV_swap_group */
	_glXJoinSwapGroupNV = (PFNGLXJOINSWAPGROUPNV)GPA(glXJoinSwapGroupNV);
	_glXBindSwapBarrierNV = (PFNGLXBINDSWAPBARRIERNV)GPA(glXBindSwapBarrierNV);
	_glXQuerySwapGroupNV = (PFNGLXQUERYSWAPGROUPNV)GPA(glXQuerySwapGroupNV);
	_glXQueryMaxSwapGroupsNV = (PFNGLXQUERYMAXSWAPGROUPSNV)GPA(glXQueryMaxSwapGroupsNV);
	_glXQueryFrameCountNV = (PFNGLXQUERYFRAMECOUNTNV)GPA(glXQueryFrameCountNV);
	_glXResetFrameCountNV = (PFNGLXRESETFRAMECOUNTNV)GPA(glXResetFrameCountNV);
	/* GLX_NV_video_capture */
	_glXBindVideoCaptureDeviceNV = (PFNGLXBINDVIDEOCAPTUREDEVICENV)GPA(glXBindVideoCaptureDeviceNV);
	_glXEnumerateVideoCaptureDevicesNV = (PFNGLXENUMERATEVIDEOCAPTUREDEVICESNV)GPA(glXEnumerateVideoCaptureDevicesNV);
	_glXLockVideoCaptureDeviceNV = (PFNGLXLOCKVIDEOCAPTUREDEVICENV)GPA(glXLockVideoCaptureDeviceNV);
	_glXQueryVideoCaptureDeviceNV = (PFNGLXQUERYVIDEOCAPTUREDEVICENV)GPA(glXQueryVideoCaptureDeviceNV);
	_glXReleaseVideoCaptureDeviceNV = (PFNGLXRELEASEVIDEOCAPTUREDEVICENV)GPA(glXReleaseVideoCaptureDeviceNV);
	/* GLX_EXT_swap_control */
	_glXSwapIntervalEXT = (PFNGLXSWAPINTERVALEXT)GPA(glXSwapIntervalEXT);
	/* GLX_NV_copy_image */
	_glXCopyImageSubDataNV = (PFNGLXCOPYIMAGESUBDATANV)GPA(glXCopyImageSubDataNV);
	gglx_rebind(enableDebug);
}

void gglx_rebind(int enableDebug) {
	if (!enableDebug) {
		gglXGetProcAddressARB = _glXGetProcAddressARB;
		gglXCreateContextAttribsARB = _glXCreateContextAttribsARB;
		gglXSwapIntervalSGI = _glXSwapIntervalSGI;
		gglXGetVideoSyncSGI = _glXGetVideoSyncSGI;
		gglXWaitVideoSyncSGI = _glXWaitVideoSyncSGI;
		gglXMakeCurrentReadSGI = _glXMakeCurrentReadSGI;
		gglXGetCurrentReadDrawableSGI = _glXGetCurrentReadDrawableSGI;
		gglXCreateGLXVideoSourceSGIX = _glXCreateGLXVideoSourceSGIX;
		gglXDestroyGLXVideoSourceSGIX = _glXDestroyGLXVideoSourceSGIX;
		gglXGetCurrentDisplayEXT = _glXGetCurrentDisplayEXT;
		gglXQueryContextInfoEXT = _glXQueryContextInfoEXT;
		gglXGetContextIDEXT = _glXGetContextIDEXT;
		gglXImportContextEXT = _glXImportContextEXT;
		gglXFreeContextEXT = _glXFreeContextEXT;
		gglXGetFBConfigAttribSGIX = _glXGetFBConfigAttribSGIX;
		gglXChooseFBConfigSGIX = _glXChooseFBConfigSGIX;
		gglXCreateGLXPixmapWithConfigSGIX = _glXCreateGLXPixmapWithConfigSGIX;
		gglXCreateContextWithConfigSGIX = _glXCreateContextWithConfigSGIX;
		gglXGetVisualFromFBConfigSGIX = _glXGetVisualFromFBConfigSGIX;
		gglXGetFBConfigFromVisualSGIX = _glXGetFBConfigFromVisualSGIX;
		gglXCreateGLXPbufferSGIX = _glXCreateGLXPbufferSGIX;
		gglXDestroyGLXPbufferSGIX = _glXDestroyGLXPbufferSGIX;
		gglXQueryGLXPbufferSGIX = _glXQueryGLXPbufferSGIX;
		gglXSelectEventSGIX = _glXSelectEventSGIX;
		gglXGetSelectedEventSGIX = _glXGetSelectedEventSGIX;
		gglXCushionSGI = _glXCushionSGI;
		gglXBindChannelToWindowSGIX = _glXBindChannelToWindowSGIX;
		gglXChannelRectSGIX = _glXChannelRectSGIX;
		gglXQueryChannelRectSGIX = _glXQueryChannelRectSGIX;
		gglXQueryChannelDeltasSGIX = _glXQueryChannelDeltasSGIX;
		gglXChannelRectSyncSGIX = _glXChannelRectSyncSGIX;
		gglXAssociateDMPbufferSGIX = _glXAssociateDMPbufferSGIX;
		gglXJoinSwapGroupSGIX = _glXJoinSwapGroupSGIX;
		gglXBindSwapBarrierSGIX = _glXBindSwapBarrierSGIX;
		gglXQueryMaxSwapBarriersSGIX = _glXQueryMaxSwapBarriersSGIX;
		gglXGetTransparentIndexSUN = _glXGetTransparentIndexSUN;
		gglXCopySubBufferMESA = _glXCopySubBufferMESA;
		gglXCreateGLXPixmapMESA = _glXCreateGLXPixmapMESA;
		gglXReleaseBuffersMESA = _glXReleaseBuffersMESA;
		gglXSet3DfxModeMESA = _glXSet3DfxModeMESA;
		gglXGetSyncValuesOML = _glXGetSyncValuesOML;
		gglXGetMscRateOML = _glXGetMscRateOML;
		gglXSwapBuffersMscOML = _glXSwapBuffersMscOML;
		gglXWaitForMscOML = _glXWaitForMscOML;
		gglXWaitForSbcOML = _glXWaitForSbcOML;
		gglXQueryHyperpipeNetworkSGIX = _glXQueryHyperpipeNetworkSGIX;
		gglXHyperpipeConfigSGIX = _glXHyperpipeConfigSGIX;
		gglXQueryHyperpipeConfigSGIX = _glXQueryHyperpipeConfigSGIX;
		gglXDestroyHyperpipeConfigSGIX = _glXDestroyHyperpipeConfigSGIX;
		gglXBindHyperpipeSGIX = _glXBindHyperpipeSGIX;
		gglXQueryHyperpipeBestAttribSGIX = _glXQueryHyperpipeBestAttribSGIX;
		gglXHyperpipeAttribSGIX = _glXHyperpipeAttribSGIX;
		gglXQueryHyperpipeAttribSGIX = _glXQueryHyperpipeAttribSGIX;
		gglXGetAGPOffsetMESA = _glXGetAGPOffsetMESA;
		gglXBindTexImageEXT = _glXBindTexImageEXT;
		gglXReleaseTexImageEXT = _glXReleaseTexImageEXT;
		gglXEnumerateVideoDevicesNV = _glXEnumerateVideoDevicesNV;
		gglXBindVideoDeviceNV = _glXBindVideoDeviceNV;
		gglXGetVideoDeviceNV = _glXGetVideoDeviceNV;
		gglXReleaseVideoDeviceNV = _glXReleaseVideoDeviceNV;
		gglXBindVideoImageNV = _glXBindVideoImageNV;
		gglXReleaseVideoImageNV = _glXReleaseVideoImageNV;
		gglXSendPbufferToVideoNV = _glXSendPbufferToVideoNV;
		gglXGetVideoInfoNV = _glXGetVideoInfoNV;
		gglXJoinSwapGroupNV = _glXJoinSwapGroupNV;
		gglXBindSwapBarrierNV = _glXBindSwapBarrierNV;
		gglXQuerySwapGroupNV = _glXQuerySwapGroupNV;
		gglXQueryMaxSwapGroupsNV = _glXQueryMaxSwapGroupsNV;
		gglXQueryFrameCountNV = _glXQueryFrameCountNV;
		gglXResetFrameCountNV = _glXResetFrameCountNV;
		gglXBindVideoCaptureDeviceNV = _glXBindVideoCaptureDeviceNV;
		gglXEnumerateVideoCaptureDevicesNV = _glXEnumerateVideoCaptureDevicesNV;
		gglXLockVideoCaptureDeviceNV = _glXLockVideoCaptureDeviceNV;
		gglXQueryVideoCaptureDeviceNV = _glXQueryVideoCaptureDeviceNV;
		gglXReleaseVideoCaptureDeviceNV = _glXReleaseVideoCaptureDeviceNV;
		gglXSwapIntervalEXT = _glXSwapIntervalEXT;
		gglXCopyImageSubDataNV = _glXCopyImageSubDataNV;
	}
	else {
		gglXGetProcAddressARB = d_glXGetProcAddressARB;
		gglXCreateContextAttribsARB = d_glXCreateContextAttribsARB;
		gglXSwapIntervalSGI = d_glXSwapIntervalSGI;
		gglXGetVideoSyncSGI = d_glXGetVideoSyncSGI;
		gglXWaitVideoSyncSGI = d_glXWaitVideoSyncSGI;
		gglXMakeCurrentReadSGI = d_glXMakeCurrentReadSGI;
		gglXGetCurrentReadDrawableSGI = d_glXGetCurrentReadDrawableSGI;
		gglXCreateGLXVideoSourceSGIX = d_glXCreateGLXVideoSourceSGIX;
		gglXDestroyGLXVideoSourceSGIX = d_glXDestroyGLXVideoSourceSGIX;
		gglXGetCurrentDisplayEXT = d_glXGetCurrentDisplayEXT;
		gglXQueryContextInfoEXT = d_glXQueryContextInfoEXT;
		gglXGetContextIDEXT = d_glXGetContextIDEXT;
		gglXImportContextEXT = d_glXImportContextEXT;
		gglXFreeContextEXT = d_glXFreeContextEXT;
		gglXGetFBConfigAttribSGIX = d_glXGetFBConfigAttribSGIX;
		gglXChooseFBConfigSGIX = d_glXChooseFBConfigSGIX;
		gglXCreateGLXPixmapWithConfigSGIX = d_glXCreateGLXPixmapWithConfigSGIX;
		gglXCreateContextWithConfigSGIX = d_glXCreateContextWithConfigSGIX;
		gglXGetVisualFromFBConfigSGIX = d_glXGetVisualFromFBConfigSGIX;
		gglXGetFBConfigFromVisualSGIX = d_glXGetFBConfigFromVisualSGIX;
		gglXCreateGLXPbufferSGIX = d_glXCreateGLXPbufferSGIX;
		gglXDestroyGLXPbufferSGIX = d_glXDestroyGLXPbufferSGIX;
		gglXQueryGLXPbufferSGIX = d_glXQueryGLXPbufferSGIX;
		gglXSelectEventSGIX = d_glXSelectEventSGIX;
		gglXGetSelectedEventSGIX = d_glXGetSelectedEventSGIX;
		gglXCushionSGI = d_glXCushionSGI;
		gglXBindChannelToWindowSGIX = d_glXBindChannelToWindowSGIX;
		gglXChannelRectSGIX = d_glXChannelRectSGIX;
		gglXQueryChannelRectSGIX = d_glXQueryChannelRectSGIX;
		gglXQueryChannelDeltasSGIX = d_glXQueryChannelDeltasSGIX;
		gglXChannelRectSyncSGIX = d_glXChannelRectSyncSGIX;
		gglXAssociateDMPbufferSGIX = d_glXAssociateDMPbufferSGIX;
		gglXJoinSwapGroupSGIX = d_glXJoinSwapGroupSGIX;
		gglXBindSwapBarrierSGIX = d_glXBindSwapBarrierSGIX;
		gglXQueryMaxSwapBarriersSGIX = d_glXQueryMaxSwapBarriersSGIX;
		gglXGetTransparentIndexSUN = d_glXGetTransparentIndexSUN;
		gglXCopySubBufferMESA = d_glXCopySubBufferMESA;
		gglXCreateGLXPixmapMESA = d_glXCreateGLXPixmapMESA;
		gglXReleaseBuffersMESA = d_glXReleaseBuffersMESA;
		gglXSet3DfxModeMESA = d_glXSet3DfxModeMESA;
		gglXGetSyncValuesOML = d_glXGetSyncValuesOML;
		gglXGetMscRateOML = d_glXGetMscRateOML;
		gglXSwapBuffersMscOML = d_glXSwapBuffersMscOML;
		gglXWaitForMscOML = d_glXWaitForMscOML;
		gglXWaitForSbcOML = d_glXWaitForSbcOML;
		gglXQueryHyperpipeNetworkSGIX = d_glXQueryHyperpipeNetworkSGIX;
		gglXHyperpipeConfigSGIX = d_glXHyperpipeConfigSGIX;
		gglXQueryHyperpipeConfigSGIX = d_glXQueryHyperpipeConfigSGIX;
		gglXDestroyHyperpipeConfigSGIX = d_glXDestroyHyperpipeConfigSGIX;
		gglXBindHyperpipeSGIX = d_glXBindHyperpipeSGIX;
		gglXQueryHyperpipeBestAttribSGIX = d_glXQueryHyperpipeBestAttribSGIX;
		gglXHyperpipeAttribSGIX = d_glXHyperpipeAttribSGIX;
		gglXQueryHyperpipeAttribSGIX = d_glXQueryHyperpipeAttribSGIX;
		gglXGetAGPOffsetMESA = d_glXGetAGPOffsetMESA;
		gglXBindTexImageEXT = d_glXBindTexImageEXT;
		gglXReleaseTexImageEXT = d_glXReleaseTexImageEXT;
		gglXEnumerateVideoDevicesNV = d_glXEnumerateVideoDevicesNV;
		gglXBindVideoDeviceNV = d_glXBindVideoDeviceNV;
		gglXGetVideoDeviceNV = d_glXGetVideoDeviceNV;
		gglXReleaseVideoDeviceNV = d_glXReleaseVideoDeviceNV;
		gglXBindVideoImageNV = d_glXBindVideoImageNV;
		gglXReleaseVideoImageNV = d_glXReleaseVideoImageNV;
		gglXSendPbufferToVideoNV = d_glXSendPbufferToVideoNV;
		gglXGetVideoInfoNV = d_glXGetVideoInfoNV;
		gglXJoinSwapGroupNV = d_glXJoinSwapGroupNV;
		gglXBindSwapBarrierNV = d_glXBindSwapBarrierNV;
		gglXQuerySwapGroupNV = d_glXQuerySwapGroupNV;
		gglXQueryMaxSwapGroupsNV = d_glXQueryMaxSwapGroupsNV;
		gglXQueryFrameCountNV = d_glXQueryFrameCountNV;
		gglXResetFrameCountNV = d_glXResetFrameCountNV;
		gglXBindVideoCaptureDeviceNV = d_glXBindVideoCaptureDeviceNV;
		gglXEnumerateVideoCaptureDevicesNV = d_glXEnumerateVideoCaptureDevicesNV;
		gglXLockVideoCaptureDeviceNV = d_glXLockVideoCaptureDeviceNV;
		gglXQueryVideoCaptureDeviceNV = d_glXQueryVideoCaptureDeviceNV;
		gglXReleaseVideoCaptureDeviceNV = d_glXReleaseVideoCaptureDeviceNV;
		gglXSwapIntervalEXT = d_glXSwapIntervalEXT;
		gglXCopyImageSubDataNV = d_glXCopyImageSubDataNV;
	}
}
void gglx_check_extensions() {
	const char *extensionString = (const char *)glGetString(GL_EXTENSIONS);
	memset(&gglxext, 0, sizeof(gglxext));
	if (strstr(extensionString, "GLX_ARB_create_context")) gglxext._GLX_ARB_create_context = 1;
	if (strstr(extensionString, "GLX_ARB_create_context_profile")) gglxext._GLX_ARB_create_context_profile = 1;
	if (strstr(extensionString, "GLX_ARB_create_context_robustness")) gglxext._GLX_ARB_create_context_robustness = 1;
	if (strstr(extensionString, "GLX_ARB_fbconfig_float")) gglxext._GLX_ARB_fbconfig_float = 1;
	if (strstr(extensionString, "GLX_ARB_framebuffer_sRGB")) gglxext._GLX_ARB_framebuffer_sRGB = 1;
	if (strstr(extensionString, "GLX_ARB_get_proc_address")) gglxext._GLX_ARB_get_proc_address = 1;
	if (strstr(extensionString, "GLX_ARB_multisample")) gglxext._GLX_ARB_multisample = 1;
	if (strstr(extensionString, "GLX_EXT_buffer_age")) gglxext._GLX_EXT_buffer_age = 1;
	if (strstr(extensionString, "GLX_EXT_fbconfig_packed_float")) gglxext._GLX_EXT_fbconfig_packed_float = 1;
	if (strstr(extensionString, "GLX_EXT_framebuffer_sRGB")) gglxext._GLX_EXT_framebuffer_sRGB = 1;
	if (strstr(extensionString, "GLX_EXT_import_context")) gglxext._GLX_EXT_import_context = 1;
	if (strstr(extensionString, "GLX_EXT_swap_control")) gglxext._GLX_EXT_swap_control = 1;
	if (strstr(extensionString, "GLX_EXT_swap_control_tear")) gglxext._GLX_EXT_swap_control_tear = 1;
	if (strstr(extensionString, "GLX_EXT_texture_compression_s3tc")) gglxext._GLX_EXT_texture_compression_s3tc = 1;
	if (strstr(extensionString, "GLX_EXT_texture_from_pixmap")) gglxext._GLX_EXT_texture_from_pixmap = 1;
	if (strstr(extensionString, "GLX_EXT_visual_info")) gglxext._GLX_EXT_visual_info = 1;
	if (strstr(extensionString, "GLX_EXT_visual_rating")) gglxext._GLX_EXT_visual_rating = 1;
	if (strstr(extensionString, "GLX_INTEL_swap_event")) gglxext._GLX_INTEL_swap_event = 1;
	if (strstr(extensionString, "GLX_MESA_agp_offset")) gglxext._GLX_MESA_agp_offset = 1;
	if (strstr(extensionString, "GLX_MESA_copy_sub_buffer")) gglxext._GLX_MESA_copy_sub_buffer = 1;
	if (strstr(extensionString, "GLX_MESA_pixmap_colormap")) gglxext._GLX_MESA_pixmap_colormap = 1;
	if (strstr(extensionString, "GLX_MESA_release_buffers")) gglxext._GLX_MESA_release_buffers = 1;
	if (strstr(extensionString, "GLX_MESA_set_3dfx_mode")) gglxext._GLX_MESA_set_3dfx_mode = 1;
	if (strstr(extensionString, "GLX_NV_copy_image")) gglxext._GLX_NV_copy_image = 1;
	if (strstr(extensionString, "GLX_NV_float_buffer")) gglxext._GLX_NV_float_buffer = 1;
	if (strstr(extensionString, "GLX_NV_multisample_coverage")) gglxext._GLX_NV_multisample_coverage = 1;
	if (strstr(extensionString, "GLX_NV_present_video")) gglxext._GLX_NV_present_video = 1;
	if (strstr(extensionString, "GLX_NV_swap_group")) gglxext._GLX_NV_swap_group = 1;
	if (strstr(extensionString, "GLX_NV_video_capture")) gglxext._GLX_NV_video_capture = 1;
	if (strstr(extensionString, "GLX_NV_video_output")) gglxext._GLX_NV_video_output = 1;
	if (strstr(extensionString, "GLX_OML_swap_method")) gglxext._GLX_OML_swap_method = 1;
	if (strstr(extensionString, "GLX_OML_sync_control")) gglxext._GLX_OML_sync_control = 1;
	if (strstr(extensionString, "GLX_SGIS_multisample")) gglxext._GLX_SGIS_multisample = 1;
	if (strstr(extensionString, "GLX_SGIX_dmbuffer")) gglxext._GLX_SGIX_dmbuffer = 1;
	if (strstr(extensionString, "GLX_SGIX_fbconfig")) gglxext._GLX_SGIX_fbconfig = 1;
	if (strstr(extensionString, "GLX_SGIX_hyperpipe")) gglxext._GLX_SGIX_hyperpipe = 1;
	if (strstr(extensionString, "GLX_SGIX_pbuffer")) gglxext._GLX_SGIX_pbuffer = 1;
	if (strstr(extensionString, "GLX_SGIX_swap_barrier")) gglxext._GLX_SGIX_swap_barrier = 1;
	if (strstr(extensionString, "GLX_SGIX_swap_group")) gglxext._GLX_SGIX_swap_group = 1;
	if (strstr(extensionString, "GLX_SGIX_video_resize")) gglxext._GLX_SGIX_video_resize = 1;
	if (strstr(extensionString, "GLX_SGIX_video_source")) gglxext._GLX_SGIX_video_source = 1;
	if (strstr(extensionString, "GLX_SGIX_visual_select_group")) gglxext._GLX_SGIX_visual_select_group = 1;
	if (strstr(extensionString, "GLX_SGI_cushion")) gglxext._GLX_SGI_cushion = 1;
	if (strstr(extensionString, "GLX_SGI_make_current_read")) gglxext._GLX_SGI_make_current_read = 1;
	if (strstr(extensionString, "GLX_SGI_swap_control")) gglxext._GLX_SGI_swap_control = 1;
	if (strstr(extensionString, "GLX_SGI_video_sync")) gglxext._GLX_SGI_video_sync = 1;
	if (strstr(extensionString, "GLX_SUN_get_transparent_index")) gglxext._GLX_SUN_get_transparent_index = 1;
}
