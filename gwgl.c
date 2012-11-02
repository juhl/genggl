/*********************************************************************************************
 *
 * gwgl.c
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

#include "gwgl.h"
#include <string.h>

extern void CheckGLError(const char *msg);
static int _gglBeginStarted = 0;

/* WGL_ARB_buffer_region */
typedef HANDLE (APIENTRY *PFNWGLCREATEBUFFERREGIONARB)(HDC hDC, int iLayerPlane, UINT uType);
PFNWGLCREATEBUFFERREGIONARB gwglCreateBufferRegionARB;
static PFNWGLCREATEBUFFERREGIONARB _wglCreateBufferRegionARB;
static HANDLE APIENTRY d_wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType) {
	HANDLE ret = _wglCreateBufferRegionARB(hDC, iLayerPlane, uType);
	if (!_gglBeginStarted) { CheckGLError("wglCreateBufferRegionARB"); }
	return ret;
}
typedef VOID (APIENTRY *PFNWGLDELETEBUFFERREGIONARB)(HANDLE hRegion);
PFNWGLDELETEBUFFERREGIONARB gwglDeleteBufferRegionARB;
static PFNWGLDELETEBUFFERREGIONARB _wglDeleteBufferRegionARB;
static VOID APIENTRY d_wglDeleteBufferRegionARB(HANDLE hRegion) {
	_wglDeleteBufferRegionARB(hRegion);
	if (!_gglBeginStarted) { CheckGLError("wglDeleteBufferRegionARB"); }
}
typedef BOOL (APIENTRY *PFNWGLSAVEBUFFERREGIONARB)(HANDLE hRegion, int x, int y, int width, int height);
PFNWGLSAVEBUFFERREGIONARB gwglSaveBufferRegionARB;
static PFNWGLSAVEBUFFERREGIONARB _wglSaveBufferRegionARB;
static BOOL APIENTRY d_wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height) {
	BOOL ret = _wglSaveBufferRegionARB(hRegion, x, y, width, height);
	if (!_gglBeginStarted) { CheckGLError("wglSaveBufferRegionARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRESTOREBUFFERREGIONARB)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
PFNWGLRESTOREBUFFERREGIONARB gwglRestoreBufferRegionARB;
static PFNWGLRESTOREBUFFERREGIONARB _wglRestoreBufferRegionARB;
static BOOL APIENTRY d_wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc) {
	BOOL ret = _wglRestoreBufferRegionARB(hRegion, x, y, width, height, xSrc, ySrc);
	if (!_gglBeginStarted) { CheckGLError("wglRestoreBufferRegionARB"); }
	return ret;
}

/* WGL_ARB_extensions_string */
typedef const char * (APIENTRY *PFNWGLGETEXTENSIONSSTRINGARB)(HDC hdc);
PFNWGLGETEXTENSIONSSTRINGARB gwglGetExtensionsStringARB;
static PFNWGLGETEXTENSIONSSTRINGARB _wglGetExtensionsStringARB;
static const char * APIENTRY d_wglGetExtensionsStringARB(HDC hdc) {
	const char * ret = _wglGetExtensionsStringARB(hdc);
	if (!_gglBeginStarted) { CheckGLError("wglGetExtensionsStringARB"); }
	return ret;
}

/* WGL_ARB_pixel_format */
typedef BOOL (APIENTRY *PFNWGLGETPIXELFORMATATTRIBIVARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues);
PFNWGLGETPIXELFORMATATTRIBIVARB gwglGetPixelFormatAttribivARB;
static PFNWGLGETPIXELFORMATATTRIBIVARB _wglGetPixelFormatAttribivARB;
static BOOL APIENTRY d_wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues) {
	BOOL ret = _wglGetPixelFormatAttribivARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
	if (!_gglBeginStarted) { CheckGLError("wglGetPixelFormatAttribivARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETPIXELFORMATATTRIBFVARB)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues);
PFNWGLGETPIXELFORMATATTRIBFVARB gwglGetPixelFormatAttribfvARB;
static PFNWGLGETPIXELFORMATATTRIBFVARB _wglGetPixelFormatAttribfvARB;
static BOOL APIENTRY d_wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues) {
	BOOL ret = _wglGetPixelFormatAttribfvARB(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
	if (!_gglBeginStarted) { CheckGLError("wglGetPixelFormatAttribfvARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLCHOOSEPIXELFORMATARB)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
PFNWGLCHOOSEPIXELFORMATARB gwglChoosePixelFormatARB;
static PFNWGLCHOOSEPIXELFORMATARB _wglChoosePixelFormatARB;
static BOOL APIENTRY d_wglChoosePixelFormatARB(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats) {
	BOOL ret = _wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
	if (!_gglBeginStarted) { CheckGLError("wglChoosePixelFormatARB"); }
	return ret;
}

/* WGL_ARB_make_current_read */
typedef BOOL (APIENTRY *PFNWGLMAKECONTEXTCURRENTARB)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
PFNWGLMAKECONTEXTCURRENTARB gwglMakeContextCurrentARB;
static PFNWGLMAKECONTEXTCURRENTARB _wglMakeContextCurrentARB;
static BOOL APIENTRY d_wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc) {
	BOOL ret = _wglMakeContextCurrentARB(hDrawDC, hReadDC, hglrc);
	if (!_gglBeginStarted) { CheckGLError("wglMakeContextCurrentARB"); }
	return ret;
}
typedef HDC (APIENTRY *PFNWGLGETCURRENTREADDCARB)();
PFNWGLGETCURRENTREADDCARB gwglGetCurrentReadDCARB;
static PFNWGLGETCURRENTREADDCARB _wglGetCurrentReadDCARB;
static HDC APIENTRY d_wglGetCurrentReadDCARB() {
	HDC ret = _wglGetCurrentReadDCARB();
	if (!_gglBeginStarted) { CheckGLError("wglGetCurrentReadDCARB"); }
	return ret;
}

/* WGL_ARB_pbuffer */
typedef HPBUFFERARB (APIENTRY *PFNWGLCREATEPBUFFERARB)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
PFNWGLCREATEPBUFFERARB gwglCreatePbufferARB;
static PFNWGLCREATEPBUFFERARB _wglCreatePbufferARB;
static HPBUFFERARB APIENTRY d_wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) {
	HPBUFFERARB ret = _wglCreatePbufferARB(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
	if (!_gglBeginStarted) { CheckGLError("wglCreatePbufferARB"); }
	return ret;
}
typedef HDC (APIENTRY *PFNWGLGETPBUFFERDCARB)(HPBUFFERARB hPbuffer);
PFNWGLGETPBUFFERDCARB gwglGetPbufferDCARB;
static PFNWGLGETPBUFFERDCARB _wglGetPbufferDCARB;
static HDC APIENTRY d_wglGetPbufferDCARB(HPBUFFERARB hPbuffer) {
	HDC ret = _wglGetPbufferDCARB(hPbuffer);
	if (!_gglBeginStarted) { CheckGLError("wglGetPbufferDCARB"); }
	return ret;
}
typedef int (APIENTRY *PFNWGLRELEASEPBUFFERDCARB)(HPBUFFERARB hPbuffer, HDC hDC);
PFNWGLRELEASEPBUFFERDCARB gwglReleasePbufferDCARB;
static PFNWGLRELEASEPBUFFERDCARB _wglReleasePbufferDCARB;
static int APIENTRY d_wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC) {
	int ret = _wglReleasePbufferDCARB(hPbuffer, hDC);
	if (!_gglBeginStarted) { CheckGLError("wglReleasePbufferDCARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDESTROYPBUFFERARB)(HPBUFFERARB hPbuffer);
PFNWGLDESTROYPBUFFERARB gwglDestroyPbufferARB;
static PFNWGLDESTROYPBUFFERARB _wglDestroyPbufferARB;
static BOOL APIENTRY d_wglDestroyPbufferARB(HPBUFFERARB hPbuffer) {
	BOOL ret = _wglDestroyPbufferARB(hPbuffer);
	if (!_gglBeginStarted) { CheckGLError("wglDestroyPbufferARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYPBUFFERARB)(HPBUFFERARB hPbuffer, int iAttribute, int* piValue);
PFNWGLQUERYPBUFFERARB gwglQueryPbufferARB;
static PFNWGLQUERYPBUFFERARB _wglQueryPbufferARB;
static BOOL APIENTRY d_wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int* piValue) {
	BOOL ret = _wglQueryPbufferARB(hPbuffer, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglQueryPbufferARB"); }
	return ret;
}

/* WGL_ARB_render_texture */
typedef BOOL (APIENTRY *PFNWGLBINDTEXIMAGEARB)(HPBUFFERARB hPbuffer, int iBuffer);
PFNWGLBINDTEXIMAGEARB gwglBindTexImageARB;
static PFNWGLBINDTEXIMAGEARB _wglBindTexImageARB;
static BOOL APIENTRY d_wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer) {
	BOOL ret = _wglBindTexImageARB(hPbuffer, iBuffer);
	if (!_gglBeginStarted) { CheckGLError("wglBindTexImageARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRELEASETEXIMAGEARB)(HPBUFFERARB hPbuffer, int iBuffer);
PFNWGLRELEASETEXIMAGEARB gwglReleaseTexImageARB;
static PFNWGLRELEASETEXIMAGEARB _wglReleaseTexImageARB;
static BOOL APIENTRY d_wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer) {
	BOOL ret = _wglReleaseTexImageARB(hPbuffer, iBuffer);
	if (!_gglBeginStarted) { CheckGLError("wglReleaseTexImageARB"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLSETPBUFFERATTRIBARB)(HPBUFFERARB hPbuffer, const int* piAttribList);
PFNWGLSETPBUFFERATTRIBARB gwglSetPbufferAttribARB;
static PFNWGLSETPBUFFERATTRIBARB _wglSetPbufferAttribARB;
static BOOL APIENTRY d_wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int* piAttribList) {
	BOOL ret = _wglSetPbufferAttribARB(hPbuffer, piAttribList);
	if (!_gglBeginStarted) { CheckGLError("wglSetPbufferAttribARB"); }
	return ret;
}

/* WGL_ARB_create_context */
typedef HGLRC (APIENTRY *PFNWGLCREATECONTEXTATTRIBSARB)(HDC hDC, HGLRC hShareContext, const int* attribList);
PFNWGLCREATECONTEXTATTRIBSARB gwglCreateContextAttribsARB;
static PFNWGLCREATECONTEXTATTRIBSARB _wglCreateContextAttribsARB;
static HGLRC APIENTRY d_wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int* attribList) {
	HGLRC ret = _wglCreateContextAttribsARB(hDC, hShareContext, attribList);
	if (!_gglBeginStarted) { CheckGLError("wglCreateContextAttribsARB"); }
	return ret;
}

/* WGL_EXT_display_color_table */
typedef GLboolean (APIENTRY *PFNWGLCREATEDISPLAYCOLORTABLEEXT)(GLushort id);
PFNWGLCREATEDISPLAYCOLORTABLEEXT gwglCreateDisplayColorTableEXT;
static PFNWGLCREATEDISPLAYCOLORTABLEEXT _wglCreateDisplayColorTableEXT;
static GLboolean APIENTRY d_wglCreateDisplayColorTableEXT(GLushort id) {
	GLboolean ret = _wglCreateDisplayColorTableEXT(id);
	if (!_gglBeginStarted) { CheckGLError("wglCreateDisplayColorTableEXT"); }
	return ret;
}
typedef GLboolean (APIENTRY *PFNWGLLOADDISPLAYCOLORTABLEEXT)(const GLushort* table, GLuint length);
PFNWGLLOADDISPLAYCOLORTABLEEXT gwglLoadDisplayColorTableEXT;
static PFNWGLLOADDISPLAYCOLORTABLEEXT _wglLoadDisplayColorTableEXT;
static GLboolean APIENTRY d_wglLoadDisplayColorTableEXT(const GLushort* table, GLuint length) {
	GLboolean ret = _wglLoadDisplayColorTableEXT(table, length);
	if (!_gglBeginStarted) { CheckGLError("wglLoadDisplayColorTableEXT"); }
	return ret;
}
typedef GLboolean (APIENTRY *PFNWGLBINDDISPLAYCOLORTABLEEXT)(GLushort id);
PFNWGLBINDDISPLAYCOLORTABLEEXT gwglBindDisplayColorTableEXT;
static PFNWGLBINDDISPLAYCOLORTABLEEXT _wglBindDisplayColorTableEXT;
static GLboolean APIENTRY d_wglBindDisplayColorTableEXT(GLushort id) {
	GLboolean ret = _wglBindDisplayColorTableEXT(id);
	if (!_gglBeginStarted) { CheckGLError("wglBindDisplayColorTableEXT"); }
	return ret;
}
typedef VOID (APIENTRY *PFNWGLDESTROYDISPLAYCOLORTABLEEXT)(GLushort id);
PFNWGLDESTROYDISPLAYCOLORTABLEEXT gwglDestroyDisplayColorTableEXT;
static PFNWGLDESTROYDISPLAYCOLORTABLEEXT _wglDestroyDisplayColorTableEXT;
static VOID APIENTRY d_wglDestroyDisplayColorTableEXT(GLushort id) {
	_wglDestroyDisplayColorTableEXT(id);
	if (!_gglBeginStarted) { CheckGLError("wglDestroyDisplayColorTableEXT"); }
}

/* WGL_EXT_extensions_string */
typedef const char * (APIENTRY *PFNWGLGETEXTENSIONSSTRINGEXT)();
PFNWGLGETEXTENSIONSSTRINGEXT gwglGetExtensionsStringEXT;
static PFNWGLGETEXTENSIONSSTRINGEXT _wglGetExtensionsStringEXT;
static const char * APIENTRY d_wglGetExtensionsStringEXT() {
	const char * ret = _wglGetExtensionsStringEXT();
	if (!_gglBeginStarted) { CheckGLError("wglGetExtensionsStringEXT"); }
	return ret;
}

/* WGL_EXT_make_current_read */
typedef BOOL (APIENTRY *PFNWGLMAKECONTEXTCURRENTEXT)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
PFNWGLMAKECONTEXTCURRENTEXT gwglMakeContextCurrentEXT;
static PFNWGLMAKECONTEXTCURRENTEXT _wglMakeContextCurrentEXT;
static BOOL APIENTRY d_wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc) {
	BOOL ret = _wglMakeContextCurrentEXT(hDrawDC, hReadDC, hglrc);
	if (!_gglBeginStarted) { CheckGLError("wglMakeContextCurrentEXT"); }
	return ret;
}
typedef HDC (APIENTRY *PFNWGLGETCURRENTREADDCEXT)();
PFNWGLGETCURRENTREADDCEXT gwglGetCurrentReadDCEXT;
static PFNWGLGETCURRENTREADDCEXT _wglGetCurrentReadDCEXT;
static HDC APIENTRY d_wglGetCurrentReadDCEXT() {
	HDC ret = _wglGetCurrentReadDCEXT();
	if (!_gglBeginStarted) { CheckGLError("wglGetCurrentReadDCEXT"); }
	return ret;
}

/* WGL_EXT_pbuffer */
typedef HPBUFFEREXT (APIENTRY *PFNWGLCREATEPBUFFEREXT)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
PFNWGLCREATEPBUFFEREXT gwglCreatePbufferEXT;
static PFNWGLCREATEPBUFFEREXT _wglCreatePbufferEXT;
static HPBUFFEREXT APIENTRY d_wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList) {
	HPBUFFEREXT ret = _wglCreatePbufferEXT(hDC, iPixelFormat, iWidth, iHeight, piAttribList);
	if (!_gglBeginStarted) { CheckGLError("wglCreatePbufferEXT"); }
	return ret;
}
typedef HDC (APIENTRY *PFNWGLGETPBUFFERDCEXT)(HPBUFFEREXT hPbuffer);
PFNWGLGETPBUFFERDCEXT gwglGetPbufferDCEXT;
static PFNWGLGETPBUFFERDCEXT _wglGetPbufferDCEXT;
static HDC APIENTRY d_wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer) {
	HDC ret = _wglGetPbufferDCEXT(hPbuffer);
	if (!_gglBeginStarted) { CheckGLError("wglGetPbufferDCEXT"); }
	return ret;
}
typedef int (APIENTRY *PFNWGLRELEASEPBUFFERDCEXT)(HPBUFFEREXT hPbuffer, HDC hDC);
PFNWGLRELEASEPBUFFERDCEXT gwglReleasePbufferDCEXT;
static PFNWGLRELEASEPBUFFERDCEXT _wglReleasePbufferDCEXT;
static int APIENTRY d_wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC) {
	int ret = _wglReleasePbufferDCEXT(hPbuffer, hDC);
	if (!_gglBeginStarted) { CheckGLError("wglReleasePbufferDCEXT"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDESTROYPBUFFEREXT)(HPBUFFEREXT hPbuffer);
PFNWGLDESTROYPBUFFEREXT gwglDestroyPbufferEXT;
static PFNWGLDESTROYPBUFFEREXT _wglDestroyPbufferEXT;
static BOOL APIENTRY d_wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer) {
	BOOL ret = _wglDestroyPbufferEXT(hPbuffer);
	if (!_gglBeginStarted) { CheckGLError("wglDestroyPbufferEXT"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYPBUFFEREXT)(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue);
PFNWGLQUERYPBUFFEREXT gwglQueryPbufferEXT;
static PFNWGLQUERYPBUFFEREXT _wglQueryPbufferEXT;
static BOOL APIENTRY d_wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int* piValue) {
	BOOL ret = _wglQueryPbufferEXT(hPbuffer, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglQueryPbufferEXT"); }
	return ret;
}

/* WGL_EXT_pixel_format */
typedef BOOL (APIENTRY *PFNWGLGETPIXELFORMATATTRIBIVEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues);
PFNWGLGETPIXELFORMATATTRIBIVEXT gwglGetPixelFormatAttribivEXT;
static PFNWGLGETPIXELFORMATATTRIBIVEXT _wglGetPixelFormatAttribivEXT;
static BOOL APIENTRY d_wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues) {
	BOOL ret = _wglGetPixelFormatAttribivEXT(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues);
	if (!_gglBeginStarted) { CheckGLError("wglGetPixelFormatAttribivEXT"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETPIXELFORMATATTRIBFVEXT)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues);
PFNWGLGETPIXELFORMATATTRIBFVEXT gwglGetPixelFormatAttribfvEXT;
static PFNWGLGETPIXELFORMATATTRIBFVEXT _wglGetPixelFormatAttribfvEXT;
static BOOL APIENTRY d_wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues) {
	BOOL ret = _wglGetPixelFormatAttribfvEXT(hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues);
	if (!_gglBeginStarted) { CheckGLError("wglGetPixelFormatAttribfvEXT"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLCHOOSEPIXELFORMATEXT)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
PFNWGLCHOOSEPIXELFORMATEXT gwglChoosePixelFormatEXT;
static PFNWGLCHOOSEPIXELFORMATEXT _wglChoosePixelFormatEXT;
static BOOL APIENTRY d_wglChoosePixelFormatEXT(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats) {
	BOOL ret = _wglChoosePixelFormatEXT(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
	if (!_gglBeginStarted) { CheckGLError("wglChoosePixelFormatEXT"); }
	return ret;
}

/* WGL_EXT_swap_control */
typedef BOOL (APIENTRY *PFNWGLSWAPINTERVALEXT)(int interval);
PFNWGLSWAPINTERVALEXT gwglSwapIntervalEXT;
static PFNWGLSWAPINTERVALEXT _wglSwapIntervalEXT;
static BOOL APIENTRY d_wglSwapIntervalEXT(int interval) {
	BOOL ret = _wglSwapIntervalEXT(interval);
	if (!_gglBeginStarted) { CheckGLError("wglSwapIntervalEXT"); }
	return ret;
}
typedef int (APIENTRY *PFNWGLGETSWAPINTERVALEXT)();
PFNWGLGETSWAPINTERVALEXT gwglGetSwapIntervalEXT;
static PFNWGLGETSWAPINTERVALEXT _wglGetSwapIntervalEXT;
static int APIENTRY d_wglGetSwapIntervalEXT() {
	int ret = _wglGetSwapIntervalEXT();
	if (!_gglBeginStarted) { CheckGLError("wglGetSwapIntervalEXT"); }
	return ret;
}

/* WGL_NV_vertex_array_range */
typedef void* (APIENTRY *PFNWGLALLOCATEMEMORYNV)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
PFNWGLALLOCATEMEMORYNV gwglAllocateMemoryNV;
static PFNWGLALLOCATEMEMORYNV _wglAllocateMemoryNV;
static void* APIENTRY d_wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority) {
	void* ret = _wglAllocateMemoryNV(size, readfreq, writefreq, priority);
	if (!_gglBeginStarted) { CheckGLError("wglAllocateMemoryNV"); }
	return ret;
}
typedef void (APIENTRY *PFNWGLFREEMEMORYNV)(void* pointer);
PFNWGLFREEMEMORYNV gwglFreeMemoryNV;
static PFNWGLFREEMEMORYNV _wglFreeMemoryNV;
static void APIENTRY d_wglFreeMemoryNV(void* pointer) {
	_wglFreeMemoryNV(pointer);
	if (!_gglBeginStarted) { CheckGLError("wglFreeMemoryNV"); }
}

/* WGL_OML_sync_control */
typedef BOOL (APIENTRY *PFNWGLGETSYNCVALUESOML)(HDC hdc, INT64* ust, INT64* msc, INT64* sbc);
PFNWGLGETSYNCVALUESOML gwglGetSyncValuesOML;
static PFNWGLGETSYNCVALUESOML _wglGetSyncValuesOML;
static BOOL APIENTRY d_wglGetSyncValuesOML(HDC hdc, INT64* ust, INT64* msc, INT64* sbc) {
	BOOL ret = _wglGetSyncValuesOML(hdc, ust, msc, sbc);
	if (!_gglBeginStarted) { CheckGLError("wglGetSyncValuesOML"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETMSCRATEOML)(HDC hdc, INT32* numerator, INT32* denominator);
PFNWGLGETMSCRATEOML gwglGetMscRateOML;
static PFNWGLGETMSCRATEOML _wglGetMscRateOML;
static BOOL APIENTRY d_wglGetMscRateOML(HDC hdc, INT32* numerator, INT32* denominator) {
	BOOL ret = _wglGetMscRateOML(hdc, numerator, denominator);
	if (!_gglBeginStarted) { CheckGLError("wglGetMscRateOML"); }
	return ret;
}
typedef INT64 (APIENTRY *PFNWGLSWAPBUFFERSMSCOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
PFNWGLSWAPBUFFERSMSCOML gwglSwapBuffersMscOML;
static PFNWGLSWAPBUFFERSMSCOML _wglSwapBuffersMscOML;
static INT64 APIENTRY d_wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder) {
	INT64 ret = _wglSwapBuffersMscOML(hdc, target_msc, divisor, remainder);
	if (!_gglBeginStarted) { CheckGLError("wglSwapBuffersMscOML"); }
	return ret;
}
typedef INT64 (APIENTRY *PFNWGLSWAPLAYERBUFFERSMSCOML)(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
PFNWGLSWAPLAYERBUFFERSMSCOML gwglSwapLayerBuffersMscOML;
static PFNWGLSWAPLAYERBUFFERSMSCOML _wglSwapLayerBuffersMscOML;
static INT64 APIENTRY d_wglSwapLayerBuffersMscOML(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder) {
	INT64 ret = _wglSwapLayerBuffersMscOML(hdc, fuPlanes, target_msc, divisor, remainder);
	if (!_gglBeginStarted) { CheckGLError("wglSwapLayerBuffersMscOML"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLWAITFORMSCOML)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc);
PFNWGLWAITFORMSCOML gwglWaitForMscOML;
static PFNWGLWAITFORMSCOML _wglWaitForMscOML;
static BOOL APIENTRY d_wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc) {
	BOOL ret = _wglWaitForMscOML(hdc, target_msc, divisor, remainder, ust, msc, sbc);
	if (!_gglBeginStarted) { CheckGLError("wglWaitForMscOML"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLWAITFORSBCOML)(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc);
PFNWGLWAITFORSBCOML gwglWaitForSbcOML;
static PFNWGLWAITFORSBCOML _wglWaitForSbcOML;
static BOOL APIENTRY d_wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc) {
	BOOL ret = _wglWaitForSbcOML(hdc, target_sbc, ust, msc, sbc);
	if (!_gglBeginStarted) { CheckGLError("wglWaitForSbcOML"); }
	return ret;
}

/* WGL_I3D_digital_video_control */
typedef BOOL (APIENTRY *PFNWGLGETDIGITALVIDEOPARAMETERSI3D)(HDC hDC, int iAttribute, int* piValue);
PFNWGLGETDIGITALVIDEOPARAMETERSI3D gwglGetDigitalVideoParametersI3D;
static PFNWGLGETDIGITALVIDEOPARAMETERSI3D _wglGetDigitalVideoParametersI3D;
static BOOL APIENTRY d_wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int* piValue) {
	BOOL ret = _wglGetDigitalVideoParametersI3D(hDC, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglGetDigitalVideoParametersI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLSETDIGITALVIDEOPARAMETERSI3D)(HDC hDC, int iAttribute, const int* piValue);
PFNWGLSETDIGITALVIDEOPARAMETERSI3D gwglSetDigitalVideoParametersI3D;
static PFNWGLSETDIGITALVIDEOPARAMETERSI3D _wglSetDigitalVideoParametersI3D;
static BOOL APIENTRY d_wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int* piValue) {
	BOOL ret = _wglSetDigitalVideoParametersI3D(hDC, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglSetDigitalVideoParametersI3D"); }
	return ret;
}

/* WGL_I3D_gamma */
typedef BOOL (APIENTRY *PFNWGLGETGAMMATABLEPARAMETERSI3D)(HDC hDC, int iAttribute, int* piValue);
PFNWGLGETGAMMATABLEPARAMETERSI3D gwglGetGammaTableParametersI3D;
static PFNWGLGETGAMMATABLEPARAMETERSI3D _wglGetGammaTableParametersI3D;
static BOOL APIENTRY d_wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int* piValue) {
	BOOL ret = _wglGetGammaTableParametersI3D(hDC, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglGetGammaTableParametersI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLSETGAMMATABLEPARAMETERSI3D)(HDC hDC, int iAttribute, const int* piValue);
PFNWGLSETGAMMATABLEPARAMETERSI3D gwglSetGammaTableParametersI3D;
static PFNWGLSETGAMMATABLEPARAMETERSI3D _wglSetGammaTableParametersI3D;
static BOOL APIENTRY d_wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int* piValue) {
	BOOL ret = _wglSetGammaTableParametersI3D(hDC, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglSetGammaTableParametersI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETGAMMATABLEI3D)(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue);
PFNWGLGETGAMMATABLEI3D gwglGetGammaTableI3D;
static PFNWGLGETGAMMATABLEI3D _wglGetGammaTableI3D;
static BOOL APIENTRY d_wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue) {
	BOOL ret = _wglGetGammaTableI3D(hDC, iEntries, puRed, puGreen, puBlue);
	if (!_gglBeginStarted) { CheckGLError("wglGetGammaTableI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLSETGAMMATABLEI3D)(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue);
PFNWGLSETGAMMATABLEI3D gwglSetGammaTableI3D;
static PFNWGLSETGAMMATABLEI3D _wglSetGammaTableI3D;
static BOOL APIENTRY d_wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue) {
	BOOL ret = _wglSetGammaTableI3D(hDC, iEntries, puRed, puGreen, puBlue);
	if (!_gglBeginStarted) { CheckGLError("wglSetGammaTableI3D"); }
	return ret;
}

/* WGL_I3D_genlock */
typedef BOOL (APIENTRY *PFNWGLENABLEGENLOCKI3D)(HDC hDC);
PFNWGLENABLEGENLOCKI3D gwglEnableGenlockI3D;
static PFNWGLENABLEGENLOCKI3D _wglEnableGenlockI3D;
static BOOL APIENTRY d_wglEnableGenlockI3D(HDC hDC) {
	BOOL ret = _wglEnableGenlockI3D(hDC);
	if (!_gglBeginStarted) { CheckGLError("wglEnableGenlockI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDISABLEGENLOCKI3D)(HDC hDC);
PFNWGLDISABLEGENLOCKI3D gwglDisableGenlockI3D;
static PFNWGLDISABLEGENLOCKI3D _wglDisableGenlockI3D;
static BOOL APIENTRY d_wglDisableGenlockI3D(HDC hDC) {
	BOOL ret = _wglDisableGenlockI3D(hDC);
	if (!_gglBeginStarted) { CheckGLError("wglDisableGenlockI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLISENABLEDGENLOCKI3D)(HDC hDC, BOOL* pFlag);
PFNWGLISENABLEDGENLOCKI3D gwglIsEnabledGenlockI3D;
static PFNWGLISENABLEDGENLOCKI3D _wglIsEnabledGenlockI3D;
static BOOL APIENTRY d_wglIsEnabledGenlockI3D(HDC hDC, BOOL* pFlag) {
	BOOL ret = _wglIsEnabledGenlockI3D(hDC, pFlag);
	if (!_gglBeginStarted) { CheckGLError("wglIsEnabledGenlockI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGENLOCKSOURCEI3D)(HDC hDC, UINT uSource);
PFNWGLGENLOCKSOURCEI3D gwglGenlockSourceI3D;
static PFNWGLGENLOCKSOURCEI3D _wglGenlockSourceI3D;
static BOOL APIENTRY d_wglGenlockSourceI3D(HDC hDC, UINT uSource) {
	BOOL ret = _wglGenlockSourceI3D(hDC, uSource);
	if (!_gglBeginStarted) { CheckGLError("wglGenlockSourceI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETGENLOCKSOURCEI3D)(HDC hDC, UINT* uSource);
PFNWGLGETGENLOCKSOURCEI3D gwglGetGenlockSourceI3D;
static PFNWGLGETGENLOCKSOURCEI3D _wglGetGenlockSourceI3D;
static BOOL APIENTRY d_wglGetGenlockSourceI3D(HDC hDC, UINT* uSource) {
	BOOL ret = _wglGetGenlockSourceI3D(hDC, uSource);
	if (!_gglBeginStarted) { CheckGLError("wglGetGenlockSourceI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGENLOCKSOURCEEDGEI3D)(HDC hDC, UINT uEdge);
PFNWGLGENLOCKSOURCEEDGEI3D gwglGenlockSourceEdgeI3D;
static PFNWGLGENLOCKSOURCEEDGEI3D _wglGenlockSourceEdgeI3D;
static BOOL APIENTRY d_wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge) {
	BOOL ret = _wglGenlockSourceEdgeI3D(hDC, uEdge);
	if (!_gglBeginStarted) { CheckGLError("wglGenlockSourceEdgeI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETGENLOCKSOURCEEDGEI3D)(HDC hDC, UINT* uEdge);
PFNWGLGETGENLOCKSOURCEEDGEI3D gwglGetGenlockSourceEdgeI3D;
static PFNWGLGETGENLOCKSOURCEEDGEI3D _wglGetGenlockSourceEdgeI3D;
static BOOL APIENTRY d_wglGetGenlockSourceEdgeI3D(HDC hDC, UINT* uEdge) {
	BOOL ret = _wglGetGenlockSourceEdgeI3D(hDC, uEdge);
	if (!_gglBeginStarted) { CheckGLError("wglGetGenlockSourceEdgeI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGENLOCKSAMPLERATEI3D)(HDC hDC, UINT uRate);
PFNWGLGENLOCKSAMPLERATEI3D gwglGenlockSampleRateI3D;
static PFNWGLGENLOCKSAMPLERATEI3D _wglGenlockSampleRateI3D;
static BOOL APIENTRY d_wglGenlockSampleRateI3D(HDC hDC, UINT uRate) {
	BOOL ret = _wglGenlockSampleRateI3D(hDC, uRate);
	if (!_gglBeginStarted) { CheckGLError("wglGenlockSampleRateI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETGENLOCKSAMPLERATEI3D)(HDC hDC, UINT* uRate);
PFNWGLGETGENLOCKSAMPLERATEI3D gwglGetGenlockSampleRateI3D;
static PFNWGLGETGENLOCKSAMPLERATEI3D _wglGetGenlockSampleRateI3D;
static BOOL APIENTRY d_wglGetGenlockSampleRateI3D(HDC hDC, UINT* uRate) {
	BOOL ret = _wglGetGenlockSampleRateI3D(hDC, uRate);
	if (!_gglBeginStarted) { CheckGLError("wglGetGenlockSampleRateI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGENLOCKSOURCEDELAYI3D)(HDC hDC, UINT uDelay);
PFNWGLGENLOCKSOURCEDELAYI3D gwglGenlockSourceDelayI3D;
static PFNWGLGENLOCKSOURCEDELAYI3D _wglGenlockSourceDelayI3D;
static BOOL APIENTRY d_wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay) {
	BOOL ret = _wglGenlockSourceDelayI3D(hDC, uDelay);
	if (!_gglBeginStarted) { CheckGLError("wglGenlockSourceDelayI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETGENLOCKSOURCEDELAYI3D)(HDC hDC, UINT* uDelay);
PFNWGLGETGENLOCKSOURCEDELAYI3D gwglGetGenlockSourceDelayI3D;
static PFNWGLGETGENLOCKSOURCEDELAYI3D _wglGetGenlockSourceDelayI3D;
static BOOL APIENTRY d_wglGetGenlockSourceDelayI3D(HDC hDC, UINT* uDelay) {
	BOOL ret = _wglGetGenlockSourceDelayI3D(hDC, uDelay);
	if (!_gglBeginStarted) { CheckGLError("wglGetGenlockSourceDelayI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3D)(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay);
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3D gwglQueryGenlockMaxSourceDelayI3D;
static PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3D _wglQueryGenlockMaxSourceDelayI3D;
static BOOL APIENTRY d_wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay) {
	BOOL ret = _wglQueryGenlockMaxSourceDelayI3D(hDC, uMaxLineDelay, uMaxPixelDelay);
	if (!_gglBeginStarted) { CheckGLError("wglQueryGenlockMaxSourceDelayI3D"); }
	return ret;
}

/* WGL_I3D_image_buffer */
typedef LPVOID (APIENTRY *PFNWGLCREATEIMAGEBUFFERI3D)(HDC hDC, DWORD dwSize, UINT uFlags);
PFNWGLCREATEIMAGEBUFFERI3D gwglCreateImageBufferI3D;
static PFNWGLCREATEIMAGEBUFFERI3D _wglCreateImageBufferI3D;
static LPVOID APIENTRY d_wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags) {
	LPVOID ret = _wglCreateImageBufferI3D(hDC, dwSize, uFlags);
	if (!_gglBeginStarted) { CheckGLError("wglCreateImageBufferI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDESTROYIMAGEBUFFERI3D)(HDC hDC, LPVOID pAddress);
PFNWGLDESTROYIMAGEBUFFERI3D gwglDestroyImageBufferI3D;
static PFNWGLDESTROYIMAGEBUFFERI3D _wglDestroyImageBufferI3D;
static BOOL APIENTRY d_wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress) {
	BOOL ret = _wglDestroyImageBufferI3D(hDC, pAddress);
	if (!_gglBeginStarted) { CheckGLError("wglDestroyImageBufferI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3D)(HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count);
PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3D gwglAssociateImageBufferEventsI3D;
static PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3D _wglAssociateImageBufferEventsI3D;
static BOOL APIENTRY d_wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count) {
	BOOL ret = _wglAssociateImageBufferEventsI3D(hDC, pEvent, pAddress, pSize, count);
	if (!_gglBeginStarted) { CheckGLError("wglAssociateImageBufferEventsI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRELEASEIMAGEBUFFEREVENTSI3D)(HDC hDC, const LPVOID* pAddress, UINT count);
PFNWGLRELEASEIMAGEBUFFEREVENTSI3D gwglReleaseImageBufferEventsI3D;
static PFNWGLRELEASEIMAGEBUFFEREVENTSI3D _wglReleaseImageBufferEventsI3D;
static BOOL APIENTRY d_wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID* pAddress, UINT count) {
	BOOL ret = _wglReleaseImageBufferEventsI3D(hDC, pAddress, count);
	if (!_gglBeginStarted) { CheckGLError("wglReleaseImageBufferEventsI3D"); }
	return ret;
}

/* WGL_I3D_swap_frame_lock */
typedef BOOL (APIENTRY *PFNWGLENABLEFRAMELOCKI3D)();
PFNWGLENABLEFRAMELOCKI3D gwglEnableFrameLockI3D;
static PFNWGLENABLEFRAMELOCKI3D _wglEnableFrameLockI3D;
static BOOL APIENTRY d_wglEnableFrameLockI3D() {
	BOOL ret = _wglEnableFrameLockI3D();
	if (!_gglBeginStarted) { CheckGLError("wglEnableFrameLockI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDISABLEFRAMELOCKI3D)();
PFNWGLDISABLEFRAMELOCKI3D gwglDisableFrameLockI3D;
static PFNWGLDISABLEFRAMELOCKI3D _wglDisableFrameLockI3D;
static BOOL APIENTRY d_wglDisableFrameLockI3D() {
	BOOL ret = _wglDisableFrameLockI3D();
	if (!_gglBeginStarted) { CheckGLError("wglDisableFrameLockI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLISENABLEDFRAMELOCKI3D)(BOOL* pFlag);
PFNWGLISENABLEDFRAMELOCKI3D gwglIsEnabledFrameLockI3D;
static PFNWGLISENABLEDFRAMELOCKI3D _wglIsEnabledFrameLockI3D;
static BOOL APIENTRY d_wglIsEnabledFrameLockI3D(BOOL* pFlag) {
	BOOL ret = _wglIsEnabledFrameLockI3D(pFlag);
	if (!_gglBeginStarted) { CheckGLError("wglIsEnabledFrameLockI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYFRAMELOCKMASTERI3D)(BOOL* pFlag);
PFNWGLQUERYFRAMELOCKMASTERI3D gwglQueryFrameLockMasterI3D;
static PFNWGLQUERYFRAMELOCKMASTERI3D _wglQueryFrameLockMasterI3D;
static BOOL APIENTRY d_wglQueryFrameLockMasterI3D(BOOL* pFlag) {
	BOOL ret = _wglQueryFrameLockMasterI3D(pFlag);
	if (!_gglBeginStarted) { CheckGLError("wglQueryFrameLockMasterI3D"); }
	return ret;
}

/* WGL_I3D_swap_frame_usage */
typedef BOOL (APIENTRY *PFNWGLGETFRAMEUSAGEI3D)(float* pUsage);
PFNWGLGETFRAMEUSAGEI3D gwglGetFrameUsageI3D;
static PFNWGLGETFRAMEUSAGEI3D _wglGetFrameUsageI3D;
static BOOL APIENTRY d_wglGetFrameUsageI3D(float* pUsage) {
	BOOL ret = _wglGetFrameUsageI3D(pUsage);
	if (!_gglBeginStarted) { CheckGLError("wglGetFrameUsageI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLBEGINFRAMETRACKINGI3D)();
PFNWGLBEGINFRAMETRACKINGI3D gwglBeginFrameTrackingI3D;
static PFNWGLBEGINFRAMETRACKINGI3D _wglBeginFrameTrackingI3D;
static BOOL APIENTRY d_wglBeginFrameTrackingI3D() {
	BOOL ret = _wglBeginFrameTrackingI3D();
	if (!_gglBeginStarted) { CheckGLError("wglBeginFrameTrackingI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLENDFRAMETRACKINGI3D)();
PFNWGLENDFRAMETRACKINGI3D gwglEndFrameTrackingI3D;
static PFNWGLENDFRAMETRACKINGI3D _wglEndFrameTrackingI3D;
static BOOL APIENTRY d_wglEndFrameTrackingI3D() {
	BOOL ret = _wglEndFrameTrackingI3D();
	if (!_gglBeginStarted) { CheckGLError("wglEndFrameTrackingI3D"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYFRAMETRACKINGI3D)(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage);
PFNWGLQUERYFRAMETRACKINGI3D gwglQueryFrameTrackingI3D;
static PFNWGLQUERYFRAMETRACKINGI3D _wglQueryFrameTrackingI3D;
static BOOL APIENTRY d_wglQueryFrameTrackingI3D(DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage) {
	BOOL ret = _wglQueryFrameTrackingI3D(pFrameCount, pMissedFrames, pLastMissedUsage);
	if (!_gglBeginStarted) { CheckGLError("wglQueryFrameTrackingI3D"); }
	return ret;
}

/* WGL_3DL_stereo_control */
typedef BOOL (APIENTRY *PFNWGLSETSTEREOEMITTERSTATE3DL)(HDC hDC, UINT uState);
PFNWGLSETSTEREOEMITTERSTATE3DL gwglSetStereoEmitterState3DL;
static PFNWGLSETSTEREOEMITTERSTATE3DL _wglSetStereoEmitterState3DL;
static BOOL APIENTRY d_wglSetStereoEmitterState3DL(HDC hDC, UINT uState) {
	BOOL ret = _wglSetStereoEmitterState3DL(hDC, uState);
	if (!_gglBeginStarted) { CheckGLError("wglSetStereoEmitterState3DL"); }
	return ret;
}

/* WGL_NV_present_video */
typedef int (APIENTRY *PFNWGLENUMERATEVIDEODEVICESNV)(HDC hDC, HVIDEOOUTPUTDEVICENV* phDeviceList);
PFNWGLENUMERATEVIDEODEVICESNV gwglEnumerateVideoDevicesNV;
static PFNWGLENUMERATEVIDEODEVICESNV _wglEnumerateVideoDevicesNV;
static int APIENTRY d_wglEnumerateVideoDevicesNV(HDC hDC, HVIDEOOUTPUTDEVICENV* phDeviceList) {
	int ret = _wglEnumerateVideoDevicesNV(hDC, phDeviceList);
	if (!_gglBeginStarted) { CheckGLError("wglEnumerateVideoDevicesNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLBINDVIDEODEVICENV)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList);
PFNWGLBINDVIDEODEVICENV gwglBindVideoDeviceNV;
static PFNWGLBINDVIDEODEVICENV _wglBindVideoDeviceNV;
static BOOL APIENTRY d_wglBindVideoDeviceNV(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList) {
	BOOL ret = _wglBindVideoDeviceNV(hDC, uVideoSlot, hVideoDevice, piAttribList);
	if (!_gglBeginStarted) { CheckGLError("wglBindVideoDeviceNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYCURRENTCONTEXTNV)(int iAttribute, int* piValue);
PFNWGLQUERYCURRENTCONTEXTNV gwglQueryCurrentContextNV;
static PFNWGLQUERYCURRENTCONTEXTNV _wglQueryCurrentContextNV;
static BOOL APIENTRY d_wglQueryCurrentContextNV(int iAttribute, int* piValue) {
	BOOL ret = _wglQueryCurrentContextNV(iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglQueryCurrentContextNV"); }
	return ret;
}

/* WGL_NV_video_output */
typedef BOOL (APIENTRY *PFNWGLGETVIDEODEVICENV)(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice);
PFNWGLGETVIDEODEVICENV gwglGetVideoDeviceNV;
static PFNWGLGETVIDEODEVICENV _wglGetVideoDeviceNV;
static BOOL APIENTRY d_wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice) {
	BOOL ret = _wglGetVideoDeviceNV(hDC, numDevices, hVideoDevice);
	if (!_gglBeginStarted) { CheckGLError("wglGetVideoDeviceNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRELEASEVIDEODEVICENV)(HPVIDEODEV hVideoDevice);
PFNWGLRELEASEVIDEODEVICENV gwglReleaseVideoDeviceNV;
static PFNWGLRELEASEVIDEODEVICENV _wglReleaseVideoDeviceNV;
static BOOL APIENTRY d_wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice) {
	BOOL ret = _wglReleaseVideoDeviceNV(hVideoDevice);
	if (!_gglBeginStarted) { CheckGLError("wglReleaseVideoDeviceNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLBINDVIDEOIMAGENV)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
PFNWGLBINDVIDEOIMAGENV gwglBindVideoImageNV;
static PFNWGLBINDVIDEOIMAGENV _wglBindVideoImageNV;
static BOOL APIENTRY d_wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer) {
	BOOL ret = _wglBindVideoImageNV(hVideoDevice, hPbuffer, iVideoBuffer);
	if (!_gglBeginStarted) { CheckGLError("wglBindVideoImageNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRELEASEVIDEOIMAGENV)(HPBUFFERARB hPbuffer, int iVideoBuffer);
PFNWGLRELEASEVIDEOIMAGENV gwglReleaseVideoImageNV;
static PFNWGLRELEASEVIDEOIMAGENV _wglReleaseVideoImageNV;
static BOOL APIENTRY d_wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer) {
	BOOL ret = _wglReleaseVideoImageNV(hPbuffer, iVideoBuffer);
	if (!_gglBeginStarted) { CheckGLError("wglReleaseVideoImageNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLSENDPBUFFERTOVIDEONV)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock);
PFNWGLSENDPBUFFERTOVIDEONV gwglSendPbufferToVideoNV;
static PFNWGLSENDPBUFFERTOVIDEONV _wglSendPbufferToVideoNV;
static BOOL APIENTRY d_wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock) {
	BOOL ret = _wglSendPbufferToVideoNV(hPbuffer, iBufferType, pulCounterPbuffer, bBlock);
	if (!_gglBeginStarted) { CheckGLError("wglSendPbufferToVideoNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLGETVIDEOINFONV)(HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo);
PFNWGLGETVIDEOINFONV gwglGetVideoInfoNV;
static PFNWGLGETVIDEOINFONV _wglGetVideoInfoNV;
static BOOL APIENTRY d_wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo) {
	BOOL ret = _wglGetVideoInfoNV(hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo);
	if (!_gglBeginStarted) { CheckGLError("wglGetVideoInfoNV"); }
	return ret;
}

/* WGL_NV_swap_group */
typedef BOOL (APIENTRY *PFNWGLJOINSWAPGROUPNV)(HDC hDC, GLuint group);
PFNWGLJOINSWAPGROUPNV gwglJoinSwapGroupNV;
static PFNWGLJOINSWAPGROUPNV _wglJoinSwapGroupNV;
static BOOL APIENTRY d_wglJoinSwapGroupNV(HDC hDC, GLuint group) {
	BOOL ret = _wglJoinSwapGroupNV(hDC, group);
	if (!_gglBeginStarted) { CheckGLError("wglJoinSwapGroupNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLBINDSWAPBARRIERNV)(GLuint group, GLuint barrier);
PFNWGLBINDSWAPBARRIERNV gwglBindSwapBarrierNV;
static PFNWGLBINDSWAPBARRIERNV _wglBindSwapBarrierNV;
static BOOL APIENTRY d_wglBindSwapBarrierNV(GLuint group, GLuint barrier) {
	BOOL ret = _wglBindSwapBarrierNV(group, barrier);
	if (!_gglBeginStarted) { CheckGLError("wglBindSwapBarrierNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYSWAPGROUPNV)(HDC hDC, GLuint* group, GLuint* barrier);
PFNWGLQUERYSWAPGROUPNV gwglQuerySwapGroupNV;
static PFNWGLQUERYSWAPGROUPNV _wglQuerySwapGroupNV;
static BOOL APIENTRY d_wglQuerySwapGroupNV(HDC hDC, GLuint* group, GLuint* barrier) {
	BOOL ret = _wglQuerySwapGroupNV(hDC, group, barrier);
	if (!_gglBeginStarted) { CheckGLError("wglQuerySwapGroupNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYMAXSWAPGROUPSNV)(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers);
PFNWGLQUERYMAXSWAPGROUPSNV gwglQueryMaxSwapGroupsNV;
static PFNWGLQUERYMAXSWAPGROUPSNV _wglQueryMaxSwapGroupsNV;
static BOOL APIENTRY d_wglQueryMaxSwapGroupsNV(HDC hDC, GLuint* maxGroups, GLuint* maxBarriers) {
	BOOL ret = _wglQueryMaxSwapGroupsNV(hDC, maxGroups, maxBarriers);
	if (!_gglBeginStarted) { CheckGLError("wglQueryMaxSwapGroupsNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYFRAMECOUNTNV)(HDC hDC, GLuint* count);
PFNWGLQUERYFRAMECOUNTNV gwglQueryFrameCountNV;
static PFNWGLQUERYFRAMECOUNTNV _wglQueryFrameCountNV;
static BOOL APIENTRY d_wglQueryFrameCountNV(HDC hDC, GLuint* count) {
	BOOL ret = _wglQueryFrameCountNV(hDC, count);
	if (!_gglBeginStarted) { CheckGLError("wglQueryFrameCountNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRESETFRAMECOUNTNV)(HDC hDC);
PFNWGLRESETFRAMECOUNTNV gwglResetFrameCountNV;
static PFNWGLRESETFRAMECOUNTNV _wglResetFrameCountNV;
static BOOL APIENTRY d_wglResetFrameCountNV(HDC hDC) {
	BOOL ret = _wglResetFrameCountNV(hDC);
	if (!_gglBeginStarted) { CheckGLError("wglResetFrameCountNV"); }
	return ret;
}

/* WGL_NV_gpu_affinity */
typedef BOOL (APIENTRY *PFNWGLENUMGPUSNV)(UINT iGpuIndex, HGPUNV* phGpu);
PFNWGLENUMGPUSNV gwglEnumGpusNV;
static PFNWGLENUMGPUSNV _wglEnumGpusNV;
static BOOL APIENTRY d_wglEnumGpusNV(UINT iGpuIndex, HGPUNV* phGpu) {
	BOOL ret = _wglEnumGpusNV(iGpuIndex, phGpu);
	if (!_gglBeginStarted) { CheckGLError("wglEnumGpusNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLENUMGPUDEVICESNV)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
PFNWGLENUMGPUDEVICESNV gwglEnumGpuDevicesNV;
static PFNWGLENUMGPUDEVICESNV _wglEnumGpuDevicesNV;
static BOOL APIENTRY d_wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice) {
	BOOL ret = _wglEnumGpuDevicesNV(hGpu, iDeviceIndex, lpGpuDevice);
	if (!_gglBeginStarted) { CheckGLError("wglEnumGpuDevicesNV"); }
	return ret;
}
typedef HDC (APIENTRY *PFNWGLCREATEAFFINITYDCNV)(const HGPUNV* phGpuList);
PFNWGLCREATEAFFINITYDCNV gwglCreateAffinityDCNV;
static PFNWGLCREATEAFFINITYDCNV _wglCreateAffinityDCNV;
static HDC APIENTRY d_wglCreateAffinityDCNV(const HGPUNV* phGpuList) {
	HDC ret = _wglCreateAffinityDCNV(phGpuList);
	if (!_gglBeginStarted) { CheckGLError("wglCreateAffinityDCNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLENUMGPUSFROMAFFINITYDCNV)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu);
PFNWGLENUMGPUSFROMAFFINITYDCNV gwglEnumGpusFromAffinityDCNV;
static PFNWGLENUMGPUSFROMAFFINITYDCNV _wglEnumGpusFromAffinityDCNV;
static BOOL APIENTRY d_wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu) {
	BOOL ret = _wglEnumGpusFromAffinityDCNV(hAffinityDC, iGpuIndex, hGpu);
	if (!_gglBeginStarted) { CheckGLError("wglEnumGpusFromAffinityDCNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDELETEDCNV)(HDC hdc);
PFNWGLDELETEDCNV gwglDeleteDCNV;
static PFNWGLDELETEDCNV _wglDeleteDCNV;
static BOOL APIENTRY d_wglDeleteDCNV(HDC hdc) {
	BOOL ret = _wglDeleteDCNV(hdc);
	if (!_gglBeginStarted) { CheckGLError("wglDeleteDCNV"); }
	return ret;
}

/* WGL_AMD_gpu_association */
typedef UINT (APIENTRY *PFNWGLGETGPUIDSAMD)(UINT maxCount, UINT* ids);
PFNWGLGETGPUIDSAMD gwglGetGPUIDsAMD;
static PFNWGLGETGPUIDSAMD _wglGetGPUIDsAMD;
static UINT APIENTRY d_wglGetGPUIDsAMD(UINT maxCount, UINT* ids) {
	UINT ret = _wglGetGPUIDsAMD(maxCount, ids);
	if (!_gglBeginStarted) { CheckGLError("wglGetGPUIDsAMD"); }
	return ret;
}
typedef INT (APIENTRY *PFNWGLGETGPUINFOAMD)(UINT id, int property, GLenum dataType, UINT size, void* data);
PFNWGLGETGPUINFOAMD gwglGetGPUInfoAMD;
static PFNWGLGETGPUINFOAMD _wglGetGPUInfoAMD;
static INT APIENTRY d_wglGetGPUInfoAMD(UINT id, int property, GLenum dataType, UINT size, void* data) {
	INT ret = _wglGetGPUInfoAMD(id, property, dataType, size, data);
	if (!_gglBeginStarted) { CheckGLError("wglGetGPUInfoAMD"); }
	return ret;
}
typedef UINT (APIENTRY *PFNWGLGETCONTEXTGPUIDAMD)(HGLRC hglrc);
PFNWGLGETCONTEXTGPUIDAMD gwglGetContextGPUIDAMD;
static PFNWGLGETCONTEXTGPUIDAMD _wglGetContextGPUIDAMD;
static UINT APIENTRY d_wglGetContextGPUIDAMD(HGLRC hglrc) {
	UINT ret = _wglGetContextGPUIDAMD(hglrc);
	if (!_gglBeginStarted) { CheckGLError("wglGetContextGPUIDAMD"); }
	return ret;
}
typedef HGLRC (APIENTRY *PFNWGLCREATEASSOCIATEDCONTEXTAMD)(UINT id);
PFNWGLCREATEASSOCIATEDCONTEXTAMD gwglCreateAssociatedContextAMD;
static PFNWGLCREATEASSOCIATEDCONTEXTAMD _wglCreateAssociatedContextAMD;
static HGLRC APIENTRY d_wglCreateAssociatedContextAMD(UINT id) {
	HGLRC ret = _wglCreateAssociatedContextAMD(id);
	if (!_gglBeginStarted) { CheckGLError("wglCreateAssociatedContextAMD"); }
	return ret;
}
typedef HGLRC (APIENTRY *PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMD)(UINT id, HGLRC hShareContext, const int* attribList);
PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMD gwglCreateAssociatedContextAttribsAMD;
static PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMD _wglCreateAssociatedContextAttribsAMD;
static HGLRC APIENTRY d_wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int* attribList) {
	HGLRC ret = _wglCreateAssociatedContextAttribsAMD(id, hShareContext, attribList);
	if (!_gglBeginStarted) { CheckGLError("wglCreateAssociatedContextAttribsAMD"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDELETEASSOCIATEDCONTEXTAMD)(HGLRC hglrc);
PFNWGLDELETEASSOCIATEDCONTEXTAMD gwglDeleteAssociatedContextAMD;
static PFNWGLDELETEASSOCIATEDCONTEXTAMD _wglDeleteAssociatedContextAMD;
static BOOL APIENTRY d_wglDeleteAssociatedContextAMD(HGLRC hglrc) {
	BOOL ret = _wglDeleteAssociatedContextAMD(hglrc);
	if (!_gglBeginStarted) { CheckGLError("wglDeleteAssociatedContextAMD"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMD)(HGLRC hglrc);
PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMD gwglMakeAssociatedContextCurrentAMD;
static PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMD _wglMakeAssociatedContextCurrentAMD;
static BOOL APIENTRY d_wglMakeAssociatedContextCurrentAMD(HGLRC hglrc) {
	BOOL ret = _wglMakeAssociatedContextCurrentAMD(hglrc);
	if (!_gglBeginStarted) { CheckGLError("wglMakeAssociatedContextCurrentAMD"); }
	return ret;
}
typedef HGLRC (APIENTRY *PFNWGLGETCURRENTASSOCIATEDCONTEXTAMD)();
PFNWGLGETCURRENTASSOCIATEDCONTEXTAMD gwglGetCurrentAssociatedContextAMD;
static PFNWGLGETCURRENTASSOCIATEDCONTEXTAMD _wglGetCurrentAssociatedContextAMD;
static HGLRC APIENTRY d_wglGetCurrentAssociatedContextAMD() {
	HGLRC ret = _wglGetCurrentAssociatedContextAMD();
	if (!_gglBeginStarted) { CheckGLError("wglGetCurrentAssociatedContextAMD"); }
	return ret;
}
typedef VOID (APIENTRY *PFNWGLBLITCONTEXTFRAMEBUFFERAMD)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
PFNWGLBLITCONTEXTFRAMEBUFFERAMD gwglBlitContextFramebufferAMD;
static PFNWGLBLITCONTEXTFRAMEBUFFERAMD _wglBlitContextFramebufferAMD;
static VOID APIENTRY d_wglBlitContextFramebufferAMD(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
	_wglBlitContextFramebufferAMD(dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	if (!_gglBeginStarted) { CheckGLError("wglBlitContextFramebufferAMD"); }
}

/* WGL_NV_video_capture */
typedef BOOL (APIENTRY *PFNWGLBINDVIDEOCAPTUREDEVICENV)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
PFNWGLBINDVIDEOCAPTUREDEVICENV gwglBindVideoCaptureDeviceNV;
static PFNWGLBINDVIDEOCAPTUREDEVICENV _wglBindVideoCaptureDeviceNV;
static BOOL APIENTRY d_wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice) {
	BOOL ret = _wglBindVideoCaptureDeviceNV(uVideoSlot, hDevice);
	if (!_gglBeginStarted) { CheckGLError("wglBindVideoCaptureDeviceNV"); }
	return ret;
}
typedef UINT (APIENTRY *PFNWGLENUMERATEVIDEOCAPTUREDEVICESNV)(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList);
PFNWGLENUMERATEVIDEOCAPTUREDEVICESNV gwglEnumerateVideoCaptureDevicesNV;
static PFNWGLENUMERATEVIDEOCAPTUREDEVICESNV _wglEnumerateVideoCaptureDevicesNV;
static UINT APIENTRY d_wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList) {
	UINT ret = _wglEnumerateVideoCaptureDevicesNV(hDc, phDeviceList);
	if (!_gglBeginStarted) { CheckGLError("wglEnumerateVideoCaptureDevicesNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLLOCKVIDEOCAPTUREDEVICENV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
PFNWGLLOCKVIDEOCAPTUREDEVICENV gwglLockVideoCaptureDeviceNV;
static PFNWGLLOCKVIDEOCAPTUREDEVICENV _wglLockVideoCaptureDeviceNV;
static BOOL APIENTRY d_wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice) {
	BOOL ret = _wglLockVideoCaptureDeviceNV(hDc, hDevice);
	if (!_gglBeginStarted) { CheckGLError("wglLockVideoCaptureDeviceNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLQUERYVIDEOCAPTUREDEVICENV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue);
PFNWGLQUERYVIDEOCAPTUREDEVICENV gwglQueryVideoCaptureDeviceNV;
static PFNWGLQUERYVIDEOCAPTUREDEVICENV _wglQueryVideoCaptureDeviceNV;
static BOOL APIENTRY d_wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue) {
	BOOL ret = _wglQueryVideoCaptureDeviceNV(hDc, hDevice, iAttribute, piValue);
	if (!_gglBeginStarted) { CheckGLError("wglQueryVideoCaptureDeviceNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLRELEASEVIDEOCAPTUREDEVICENV)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
PFNWGLRELEASEVIDEOCAPTUREDEVICENV gwglReleaseVideoCaptureDeviceNV;
static PFNWGLRELEASEVIDEOCAPTUREDEVICENV _wglReleaseVideoCaptureDeviceNV;
static BOOL APIENTRY d_wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice) {
	BOOL ret = _wglReleaseVideoCaptureDeviceNV(hDc, hDevice);
	if (!_gglBeginStarted) { CheckGLError("wglReleaseVideoCaptureDeviceNV"); }
	return ret;
}

/* WGL_NV_copy_image */
typedef BOOL (APIENTRY *PFNWGLCOPYIMAGESUBDATANV)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
PFNWGLCOPYIMAGESUBDATANV gwglCopyImageSubDataNV;
static PFNWGLCOPYIMAGESUBDATANV _wglCopyImageSubDataNV;
static BOOL APIENTRY d_wglCopyImageSubDataNV(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
	BOOL ret = _wglCopyImageSubDataNV(hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
	if (!_gglBeginStarted) { CheckGLError("wglCopyImageSubDataNV"); }
	return ret;
}

/* WGL_NV_DX_interop */
typedef BOOL (APIENTRY *PFNWGLDXSETRESOURCESHAREHANDLENV)(void* dxObject, HANDLE shareHandle);
PFNWGLDXSETRESOURCESHAREHANDLENV gwglDXSetResourceShareHandleNV;
static PFNWGLDXSETRESOURCESHAREHANDLENV _wglDXSetResourceShareHandleNV;
static BOOL APIENTRY d_wglDXSetResourceShareHandleNV(void* dxObject, HANDLE shareHandle) {
	BOOL ret = _wglDXSetResourceShareHandleNV(dxObject, shareHandle);
	if (!_gglBeginStarted) { CheckGLError("wglDXSetResourceShareHandleNV"); }
	return ret;
}
typedef HANDLE (APIENTRY *PFNWGLDXOPENDEVICENV)(void* dxDevice);
PFNWGLDXOPENDEVICENV gwglDXOpenDeviceNV;
static PFNWGLDXOPENDEVICENV _wglDXOpenDeviceNV;
static HANDLE APIENTRY d_wglDXOpenDeviceNV(void* dxDevice) {
	HANDLE ret = _wglDXOpenDeviceNV(dxDevice);
	if (!_gglBeginStarted) { CheckGLError("wglDXOpenDeviceNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDXCLOSEDEVICENV)(HANDLE hDevice);
PFNWGLDXCLOSEDEVICENV gwglDXCloseDeviceNV;
static PFNWGLDXCLOSEDEVICENV _wglDXCloseDeviceNV;
static BOOL APIENTRY d_wglDXCloseDeviceNV(HANDLE hDevice) {
	BOOL ret = _wglDXCloseDeviceNV(hDevice);
	if (!_gglBeginStarted) { CheckGLError("wglDXCloseDeviceNV"); }
	return ret;
}
typedef HANDLE (APIENTRY *PFNWGLDXREGISTEROBJECTNV)(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access);
PFNWGLDXREGISTEROBJECTNV gwglDXRegisterObjectNV;
static PFNWGLDXREGISTEROBJECTNV _wglDXRegisterObjectNV;
static HANDLE APIENTRY d_wglDXRegisterObjectNV(HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access) {
	HANDLE ret = _wglDXRegisterObjectNV(hDevice, dxObject, name, type, access);
	if (!_gglBeginStarted) { CheckGLError("wglDXRegisterObjectNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDXUNREGISTEROBJECTNV)(HANDLE hDevice, HANDLE hObject);
PFNWGLDXUNREGISTEROBJECTNV gwglDXUnregisterObjectNV;
static PFNWGLDXUNREGISTEROBJECTNV _wglDXUnregisterObjectNV;
static BOOL APIENTRY d_wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject) {
	BOOL ret = _wglDXUnregisterObjectNV(hDevice, hObject);
	if (!_gglBeginStarted) { CheckGLError("wglDXUnregisterObjectNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDXOBJECTACCESSNV)(HANDLE hObject, GLenum access);
PFNWGLDXOBJECTACCESSNV gwglDXObjectAccessNV;
static PFNWGLDXOBJECTACCESSNV _wglDXObjectAccessNV;
static BOOL APIENTRY d_wglDXObjectAccessNV(HANDLE hObject, GLenum access) {
	BOOL ret = _wglDXObjectAccessNV(hObject, access);
	if (!_gglBeginStarted) { CheckGLError("wglDXObjectAccessNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDXLOCKOBJECTSNV)(HANDLE hDevice, GLint count, HANDLE* hObjects);
PFNWGLDXLOCKOBJECTSNV gwglDXLockObjectsNV;
static PFNWGLDXLOCKOBJECTSNV _wglDXLockObjectsNV;
static BOOL APIENTRY d_wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects) {
	BOOL ret = _wglDXLockObjectsNV(hDevice, count, hObjects);
	if (!_gglBeginStarted) { CheckGLError("wglDXLockObjectsNV"); }
	return ret;
}
typedef BOOL (APIENTRY *PFNWGLDXUNLOCKOBJECTSNV)(HANDLE hDevice, GLint count, HANDLE* hObjects);
PFNWGLDXUNLOCKOBJECTSNV gwglDXUnlockObjectsNV;
static PFNWGLDXUNLOCKOBJECTSNV _wglDXUnlockObjectsNV;
static BOOL APIENTRY d_wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE* hObjects) {
	BOOL ret = _wglDXUnlockObjectsNV(hDevice, count, hObjects);
	if (!_gglBeginStarted) { CheckGLError("wglDXUnlockObjectsNV"); }
	return ret;
}

#ifdef _WIN32
#define GPA(a) wglGetProcAddress(#a)
#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#define GPA(a) mglGetProcAddress(#a)
extern void *mglGetProcAddress(const char *name);
#elif defined(__linux__)
#define GPA(a) glXGetProcAddressARB((const GLubyte *)#a)
#endif

gwglext_t gwglext;

void gwgl_init(int enableDebug) {
	/* WGL_ARB_buffer_region */
	_wglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARB)GPA(wglCreateBufferRegionARB);
	_wglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARB)GPA(wglDeleteBufferRegionARB);
	_wglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARB)GPA(wglSaveBufferRegionARB);
	_wglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARB)GPA(wglRestoreBufferRegionARB);
	/* WGL_ARB_extensions_string */
	_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARB)GPA(wglGetExtensionsStringARB);
	/* WGL_ARB_pixel_format */
	_wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARB)GPA(wglGetPixelFormatAttribivARB);
	_wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARB)GPA(wglGetPixelFormatAttribfvARB);
	_wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARB)GPA(wglChoosePixelFormatARB);
	/* WGL_ARB_make_current_read */
	_wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARB)GPA(wglMakeContextCurrentARB);
	_wglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARB)GPA(wglGetCurrentReadDCARB);
	/* WGL_ARB_pbuffer */
	_wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARB)GPA(wglCreatePbufferARB);
	_wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARB)GPA(wglGetPbufferDCARB);
	_wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARB)GPA(wglReleasePbufferDCARB);
	_wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARB)GPA(wglDestroyPbufferARB);
	_wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARB)GPA(wglQueryPbufferARB);
	/* WGL_ARB_render_texture */
	_wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARB)GPA(wglBindTexImageARB);
	_wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARB)GPA(wglReleaseTexImageARB);
	_wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARB)GPA(wglSetPbufferAttribARB);
	/* WGL_ARB_create_context */
	_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARB)GPA(wglCreateContextAttribsARB);
	/* WGL_EXT_display_color_table */
	_wglCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXT)GPA(wglCreateDisplayColorTableEXT);
	_wglLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXT)GPA(wglLoadDisplayColorTableEXT);
	_wglBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXT)GPA(wglBindDisplayColorTableEXT);
	_wglDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXT)GPA(wglDestroyDisplayColorTableEXT);
	/* WGL_EXT_extensions_string */
	_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXT)GPA(wglGetExtensionsStringEXT);
	/* WGL_EXT_make_current_read */
	_wglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXT)GPA(wglMakeContextCurrentEXT);
	_wglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXT)GPA(wglGetCurrentReadDCEXT);
	/* WGL_EXT_pbuffer */
	_wglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXT)GPA(wglCreatePbufferEXT);
	_wglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXT)GPA(wglGetPbufferDCEXT);
	_wglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXT)GPA(wglReleasePbufferDCEXT);
	_wglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXT)GPA(wglDestroyPbufferEXT);
	_wglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXT)GPA(wglQueryPbufferEXT);
	/* WGL_EXT_pixel_format */
	_wglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXT)GPA(wglGetPixelFormatAttribivEXT);
	_wglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXT)GPA(wglGetPixelFormatAttribfvEXT);
	_wglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXT)GPA(wglChoosePixelFormatEXT);
	/* WGL_EXT_swap_control */
	_wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXT)GPA(wglSwapIntervalEXT);
	_wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXT)GPA(wglGetSwapIntervalEXT);
	/* WGL_NV_vertex_array_range */
	_wglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNV)GPA(wglAllocateMemoryNV);
	_wglFreeMemoryNV = (PFNWGLFREEMEMORYNV)GPA(wglFreeMemoryNV);
	/* WGL_OML_sync_control */
	_wglGetSyncValuesOML = (PFNWGLGETSYNCVALUESOML)GPA(wglGetSyncValuesOML);
	_wglGetMscRateOML = (PFNWGLGETMSCRATEOML)GPA(wglGetMscRateOML);
	_wglSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOML)GPA(wglSwapBuffersMscOML);
	_wglSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOML)GPA(wglSwapLayerBuffersMscOML);
	_wglWaitForMscOML = (PFNWGLWAITFORMSCOML)GPA(wglWaitForMscOML);
	_wglWaitForSbcOML = (PFNWGLWAITFORSBCOML)GPA(wglWaitForSbcOML);
	/* WGL_I3D_digital_video_control */
	_wglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3D)GPA(wglGetDigitalVideoParametersI3D);
	_wglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3D)GPA(wglSetDigitalVideoParametersI3D);
	/* WGL_I3D_gamma */
	_wglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3D)GPA(wglGetGammaTableParametersI3D);
	_wglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3D)GPA(wglSetGammaTableParametersI3D);
	_wglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3D)GPA(wglGetGammaTableI3D);
	_wglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3D)GPA(wglSetGammaTableI3D);
	/* WGL_I3D_genlock */
	_wglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3D)GPA(wglEnableGenlockI3D);
	_wglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3D)GPA(wglDisableGenlockI3D);
	_wglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3D)GPA(wglIsEnabledGenlockI3D);
	_wglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3D)GPA(wglGenlockSourceI3D);
	_wglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3D)GPA(wglGetGenlockSourceI3D);
	_wglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3D)GPA(wglGenlockSourceEdgeI3D);
	_wglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3D)GPA(wglGetGenlockSourceEdgeI3D);
	_wglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3D)GPA(wglGenlockSampleRateI3D);
	_wglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3D)GPA(wglGetGenlockSampleRateI3D);
	_wglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3D)GPA(wglGenlockSourceDelayI3D);
	_wglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3D)GPA(wglGetGenlockSourceDelayI3D);
	_wglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3D)GPA(wglQueryGenlockMaxSourceDelayI3D);
	/* WGL_I3D_image_buffer */
	_wglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3D)GPA(wglCreateImageBufferI3D);
	_wglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3D)GPA(wglDestroyImageBufferI3D);
	_wglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3D)GPA(wglAssociateImageBufferEventsI3D);
	_wglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3D)GPA(wglReleaseImageBufferEventsI3D);
	/* WGL_I3D_swap_frame_lock */
	_wglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3D)GPA(wglEnableFrameLockI3D);
	_wglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3D)GPA(wglDisableFrameLockI3D);
	_wglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3D)GPA(wglIsEnabledFrameLockI3D);
	_wglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3D)GPA(wglQueryFrameLockMasterI3D);
	/* WGL_I3D_swap_frame_usage */
	_wglGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3D)GPA(wglGetFrameUsageI3D);
	_wglBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3D)GPA(wglBeginFrameTrackingI3D);
	_wglEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3D)GPA(wglEndFrameTrackingI3D);
	_wglQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3D)GPA(wglQueryFrameTrackingI3D);
	/* WGL_3DL_stereo_control */
	_wglSetStereoEmitterState3DL = (PFNWGLSETSTEREOEMITTERSTATE3DL)GPA(wglSetStereoEmitterState3DL);
	/* WGL_NV_present_video */
	_wglEnumerateVideoDevicesNV = (PFNWGLENUMERATEVIDEODEVICESNV)GPA(wglEnumerateVideoDevicesNV);
	_wglBindVideoDeviceNV = (PFNWGLBINDVIDEODEVICENV)GPA(wglBindVideoDeviceNV);
	_wglQueryCurrentContextNV = (PFNWGLQUERYCURRENTCONTEXTNV)GPA(wglQueryCurrentContextNV);
	/* WGL_NV_video_output */
	_wglGetVideoDeviceNV = (PFNWGLGETVIDEODEVICENV)GPA(wglGetVideoDeviceNV);
	_wglReleaseVideoDeviceNV = (PFNWGLRELEASEVIDEODEVICENV)GPA(wglReleaseVideoDeviceNV);
	_wglBindVideoImageNV = (PFNWGLBINDVIDEOIMAGENV)GPA(wglBindVideoImageNV);
	_wglReleaseVideoImageNV = (PFNWGLRELEASEVIDEOIMAGENV)GPA(wglReleaseVideoImageNV);
	_wglSendPbufferToVideoNV = (PFNWGLSENDPBUFFERTOVIDEONV)GPA(wglSendPbufferToVideoNV);
	_wglGetVideoInfoNV = (PFNWGLGETVIDEOINFONV)GPA(wglGetVideoInfoNV);
	/* WGL_NV_swap_group */
	_wglJoinSwapGroupNV = (PFNWGLJOINSWAPGROUPNV)GPA(wglJoinSwapGroupNV);
	_wglBindSwapBarrierNV = (PFNWGLBINDSWAPBARRIERNV)GPA(wglBindSwapBarrierNV);
	_wglQuerySwapGroupNV = (PFNWGLQUERYSWAPGROUPNV)GPA(wglQuerySwapGroupNV);
	_wglQueryMaxSwapGroupsNV = (PFNWGLQUERYMAXSWAPGROUPSNV)GPA(wglQueryMaxSwapGroupsNV);
	_wglQueryFrameCountNV = (PFNWGLQUERYFRAMECOUNTNV)GPA(wglQueryFrameCountNV);
	_wglResetFrameCountNV = (PFNWGLRESETFRAMECOUNTNV)GPA(wglResetFrameCountNV);
	/* WGL_NV_gpu_affinity */
	_wglEnumGpusNV = (PFNWGLENUMGPUSNV)GPA(wglEnumGpusNV);
	_wglEnumGpuDevicesNV = (PFNWGLENUMGPUDEVICESNV)GPA(wglEnumGpuDevicesNV);
	_wglCreateAffinityDCNV = (PFNWGLCREATEAFFINITYDCNV)GPA(wglCreateAffinityDCNV);
	_wglEnumGpusFromAffinityDCNV = (PFNWGLENUMGPUSFROMAFFINITYDCNV)GPA(wglEnumGpusFromAffinityDCNV);
	_wglDeleteDCNV = (PFNWGLDELETEDCNV)GPA(wglDeleteDCNV);
	/* WGL_AMD_gpu_association */
	_wglGetGPUIDsAMD = (PFNWGLGETGPUIDSAMD)GPA(wglGetGPUIDsAMD);
	_wglGetGPUInfoAMD = (PFNWGLGETGPUINFOAMD)GPA(wglGetGPUInfoAMD);
	_wglGetContextGPUIDAMD = (PFNWGLGETCONTEXTGPUIDAMD)GPA(wglGetContextGPUIDAMD);
	_wglCreateAssociatedContextAMD = (PFNWGLCREATEASSOCIATEDCONTEXTAMD)GPA(wglCreateAssociatedContextAMD);
	_wglCreateAssociatedContextAttribsAMD = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMD)GPA(wglCreateAssociatedContextAttribsAMD);
	_wglDeleteAssociatedContextAMD = (PFNWGLDELETEASSOCIATEDCONTEXTAMD)GPA(wglDeleteAssociatedContextAMD);
	_wglMakeAssociatedContextCurrentAMD = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMD)GPA(wglMakeAssociatedContextCurrentAMD);
	_wglGetCurrentAssociatedContextAMD = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMD)GPA(wglGetCurrentAssociatedContextAMD);
	_wglBlitContextFramebufferAMD = (PFNWGLBLITCONTEXTFRAMEBUFFERAMD)GPA(wglBlitContextFramebufferAMD);
	/* WGL_NV_video_capture */
	_wglBindVideoCaptureDeviceNV = (PFNWGLBINDVIDEOCAPTUREDEVICENV)GPA(wglBindVideoCaptureDeviceNV);
	_wglEnumerateVideoCaptureDevicesNV = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNV)GPA(wglEnumerateVideoCaptureDevicesNV);
	_wglLockVideoCaptureDeviceNV = (PFNWGLLOCKVIDEOCAPTUREDEVICENV)GPA(wglLockVideoCaptureDeviceNV);
	_wglQueryVideoCaptureDeviceNV = (PFNWGLQUERYVIDEOCAPTUREDEVICENV)GPA(wglQueryVideoCaptureDeviceNV);
	_wglReleaseVideoCaptureDeviceNV = (PFNWGLRELEASEVIDEOCAPTUREDEVICENV)GPA(wglReleaseVideoCaptureDeviceNV);
	/* WGL_NV_copy_image */
	_wglCopyImageSubDataNV = (PFNWGLCOPYIMAGESUBDATANV)GPA(wglCopyImageSubDataNV);
	/* WGL_NV_DX_interop */
	_wglDXSetResourceShareHandleNV = (PFNWGLDXSETRESOURCESHAREHANDLENV)GPA(wglDXSetResourceShareHandleNV);
	_wglDXOpenDeviceNV = (PFNWGLDXOPENDEVICENV)GPA(wglDXOpenDeviceNV);
	_wglDXCloseDeviceNV = (PFNWGLDXCLOSEDEVICENV)GPA(wglDXCloseDeviceNV);
	_wglDXRegisterObjectNV = (PFNWGLDXREGISTEROBJECTNV)GPA(wglDXRegisterObjectNV);
	_wglDXUnregisterObjectNV = (PFNWGLDXUNREGISTEROBJECTNV)GPA(wglDXUnregisterObjectNV);
	_wglDXObjectAccessNV = (PFNWGLDXOBJECTACCESSNV)GPA(wglDXObjectAccessNV);
	_wglDXLockObjectsNV = (PFNWGLDXLOCKOBJECTSNV)GPA(wglDXLockObjectsNV);
	_wglDXUnlockObjectsNV = (PFNWGLDXUNLOCKOBJECTSNV)GPA(wglDXUnlockObjectsNV);
	gwgl_rebind(enableDebug);
}

void gwgl_rebind(int enableDebug) {
	if (!enableDebug) {
		gwglCreateBufferRegionARB = _wglCreateBufferRegionARB;
		gwglDeleteBufferRegionARB = _wglDeleteBufferRegionARB;
		gwglSaveBufferRegionARB = _wglSaveBufferRegionARB;
		gwglRestoreBufferRegionARB = _wglRestoreBufferRegionARB;
		gwglGetExtensionsStringARB = _wglGetExtensionsStringARB;
		gwglGetPixelFormatAttribivARB = _wglGetPixelFormatAttribivARB;
		gwglGetPixelFormatAttribfvARB = _wglGetPixelFormatAttribfvARB;
		gwglChoosePixelFormatARB = _wglChoosePixelFormatARB;
		gwglMakeContextCurrentARB = _wglMakeContextCurrentARB;
		gwglGetCurrentReadDCARB = _wglGetCurrentReadDCARB;
		gwglCreatePbufferARB = _wglCreatePbufferARB;
		gwglGetPbufferDCARB = _wglGetPbufferDCARB;
		gwglReleasePbufferDCARB = _wglReleasePbufferDCARB;
		gwglDestroyPbufferARB = _wglDestroyPbufferARB;
		gwglQueryPbufferARB = _wglQueryPbufferARB;
		gwglBindTexImageARB = _wglBindTexImageARB;
		gwglReleaseTexImageARB = _wglReleaseTexImageARB;
		gwglSetPbufferAttribARB = _wglSetPbufferAttribARB;
		gwglCreateContextAttribsARB = _wglCreateContextAttribsARB;
		gwglCreateDisplayColorTableEXT = _wglCreateDisplayColorTableEXT;
		gwglLoadDisplayColorTableEXT = _wglLoadDisplayColorTableEXT;
		gwglBindDisplayColorTableEXT = _wglBindDisplayColorTableEXT;
		gwglDestroyDisplayColorTableEXT = _wglDestroyDisplayColorTableEXT;
		gwglGetExtensionsStringEXT = _wglGetExtensionsStringEXT;
		gwglMakeContextCurrentEXT = _wglMakeContextCurrentEXT;
		gwglGetCurrentReadDCEXT = _wglGetCurrentReadDCEXT;
		gwglCreatePbufferEXT = _wglCreatePbufferEXT;
		gwglGetPbufferDCEXT = _wglGetPbufferDCEXT;
		gwglReleasePbufferDCEXT = _wglReleasePbufferDCEXT;
		gwglDestroyPbufferEXT = _wglDestroyPbufferEXT;
		gwglQueryPbufferEXT = _wglQueryPbufferEXT;
		gwglGetPixelFormatAttribivEXT = _wglGetPixelFormatAttribivEXT;
		gwglGetPixelFormatAttribfvEXT = _wglGetPixelFormatAttribfvEXT;
		gwglChoosePixelFormatEXT = _wglChoosePixelFormatEXT;
		gwglSwapIntervalEXT = _wglSwapIntervalEXT;
		gwglGetSwapIntervalEXT = _wglGetSwapIntervalEXT;
		gwglAllocateMemoryNV = _wglAllocateMemoryNV;
		gwglFreeMemoryNV = _wglFreeMemoryNV;
		gwglGetSyncValuesOML = _wglGetSyncValuesOML;
		gwglGetMscRateOML = _wglGetMscRateOML;
		gwglSwapBuffersMscOML = _wglSwapBuffersMscOML;
		gwglSwapLayerBuffersMscOML = _wglSwapLayerBuffersMscOML;
		gwglWaitForMscOML = _wglWaitForMscOML;
		gwglWaitForSbcOML = _wglWaitForSbcOML;
		gwglGetDigitalVideoParametersI3D = _wglGetDigitalVideoParametersI3D;
		gwglSetDigitalVideoParametersI3D = _wglSetDigitalVideoParametersI3D;
		gwglGetGammaTableParametersI3D = _wglGetGammaTableParametersI3D;
		gwglSetGammaTableParametersI3D = _wglSetGammaTableParametersI3D;
		gwglGetGammaTableI3D = _wglGetGammaTableI3D;
		gwglSetGammaTableI3D = _wglSetGammaTableI3D;
		gwglEnableGenlockI3D = _wglEnableGenlockI3D;
		gwglDisableGenlockI3D = _wglDisableGenlockI3D;
		gwglIsEnabledGenlockI3D = _wglIsEnabledGenlockI3D;
		gwglGenlockSourceI3D = _wglGenlockSourceI3D;
		gwglGetGenlockSourceI3D = _wglGetGenlockSourceI3D;
		gwglGenlockSourceEdgeI3D = _wglGenlockSourceEdgeI3D;
		gwglGetGenlockSourceEdgeI3D = _wglGetGenlockSourceEdgeI3D;
		gwglGenlockSampleRateI3D = _wglGenlockSampleRateI3D;
		gwglGetGenlockSampleRateI3D = _wglGetGenlockSampleRateI3D;
		gwglGenlockSourceDelayI3D = _wglGenlockSourceDelayI3D;
		gwglGetGenlockSourceDelayI3D = _wglGetGenlockSourceDelayI3D;
		gwglQueryGenlockMaxSourceDelayI3D = _wglQueryGenlockMaxSourceDelayI3D;
		gwglCreateImageBufferI3D = _wglCreateImageBufferI3D;
		gwglDestroyImageBufferI3D = _wglDestroyImageBufferI3D;
		gwglAssociateImageBufferEventsI3D = _wglAssociateImageBufferEventsI3D;
		gwglReleaseImageBufferEventsI3D = _wglReleaseImageBufferEventsI3D;
		gwglEnableFrameLockI3D = _wglEnableFrameLockI3D;
		gwglDisableFrameLockI3D = _wglDisableFrameLockI3D;
		gwglIsEnabledFrameLockI3D = _wglIsEnabledFrameLockI3D;
		gwglQueryFrameLockMasterI3D = _wglQueryFrameLockMasterI3D;
		gwglGetFrameUsageI3D = _wglGetFrameUsageI3D;
		gwglBeginFrameTrackingI3D = _wglBeginFrameTrackingI3D;
		gwglEndFrameTrackingI3D = _wglEndFrameTrackingI3D;
		gwglQueryFrameTrackingI3D = _wglQueryFrameTrackingI3D;
		gwglSetStereoEmitterState3DL = _wglSetStereoEmitterState3DL;
		gwglEnumerateVideoDevicesNV = _wglEnumerateVideoDevicesNV;
		gwglBindVideoDeviceNV = _wglBindVideoDeviceNV;
		gwglQueryCurrentContextNV = _wglQueryCurrentContextNV;
		gwglGetVideoDeviceNV = _wglGetVideoDeviceNV;
		gwglReleaseVideoDeviceNV = _wglReleaseVideoDeviceNV;
		gwglBindVideoImageNV = _wglBindVideoImageNV;
		gwglReleaseVideoImageNV = _wglReleaseVideoImageNV;
		gwglSendPbufferToVideoNV = _wglSendPbufferToVideoNV;
		gwglGetVideoInfoNV = _wglGetVideoInfoNV;
		gwglJoinSwapGroupNV = _wglJoinSwapGroupNV;
		gwglBindSwapBarrierNV = _wglBindSwapBarrierNV;
		gwglQuerySwapGroupNV = _wglQuerySwapGroupNV;
		gwglQueryMaxSwapGroupsNV = _wglQueryMaxSwapGroupsNV;
		gwglQueryFrameCountNV = _wglQueryFrameCountNV;
		gwglResetFrameCountNV = _wglResetFrameCountNV;
		gwglEnumGpusNV = _wglEnumGpusNV;
		gwglEnumGpuDevicesNV = _wglEnumGpuDevicesNV;
		gwglCreateAffinityDCNV = _wglCreateAffinityDCNV;
		gwglEnumGpusFromAffinityDCNV = _wglEnumGpusFromAffinityDCNV;
		gwglDeleteDCNV = _wglDeleteDCNV;
		gwglGetGPUIDsAMD = _wglGetGPUIDsAMD;
		gwglGetGPUInfoAMD = _wglGetGPUInfoAMD;
		gwglGetContextGPUIDAMD = _wglGetContextGPUIDAMD;
		gwglCreateAssociatedContextAMD = _wglCreateAssociatedContextAMD;
		gwglCreateAssociatedContextAttribsAMD = _wglCreateAssociatedContextAttribsAMD;
		gwglDeleteAssociatedContextAMD = _wglDeleteAssociatedContextAMD;
		gwglMakeAssociatedContextCurrentAMD = _wglMakeAssociatedContextCurrentAMD;
		gwglGetCurrentAssociatedContextAMD = _wglGetCurrentAssociatedContextAMD;
		gwglBlitContextFramebufferAMD = _wglBlitContextFramebufferAMD;
		gwglBindVideoCaptureDeviceNV = _wglBindVideoCaptureDeviceNV;
		gwglEnumerateVideoCaptureDevicesNV = _wglEnumerateVideoCaptureDevicesNV;
		gwglLockVideoCaptureDeviceNV = _wglLockVideoCaptureDeviceNV;
		gwglQueryVideoCaptureDeviceNV = _wglQueryVideoCaptureDeviceNV;
		gwglReleaseVideoCaptureDeviceNV = _wglReleaseVideoCaptureDeviceNV;
		gwglCopyImageSubDataNV = _wglCopyImageSubDataNV;
		gwglDXSetResourceShareHandleNV = _wglDXSetResourceShareHandleNV;
		gwglDXOpenDeviceNV = _wglDXOpenDeviceNV;
		gwglDXCloseDeviceNV = _wglDXCloseDeviceNV;
		gwglDXRegisterObjectNV = _wglDXRegisterObjectNV;
		gwglDXUnregisterObjectNV = _wglDXUnregisterObjectNV;
		gwglDXObjectAccessNV = _wglDXObjectAccessNV;
		gwglDXLockObjectsNV = _wglDXLockObjectsNV;
		gwglDXUnlockObjectsNV = _wglDXUnlockObjectsNV;
	}
	else {
		gwglCreateBufferRegionARB = d_wglCreateBufferRegionARB;
		gwglDeleteBufferRegionARB = d_wglDeleteBufferRegionARB;
		gwglSaveBufferRegionARB = d_wglSaveBufferRegionARB;
		gwglRestoreBufferRegionARB = d_wglRestoreBufferRegionARB;
		gwglGetExtensionsStringARB = d_wglGetExtensionsStringARB;
		gwglGetPixelFormatAttribivARB = d_wglGetPixelFormatAttribivARB;
		gwglGetPixelFormatAttribfvARB = d_wglGetPixelFormatAttribfvARB;
		gwglChoosePixelFormatARB = d_wglChoosePixelFormatARB;
		gwglMakeContextCurrentARB = d_wglMakeContextCurrentARB;
		gwglGetCurrentReadDCARB = d_wglGetCurrentReadDCARB;
		gwglCreatePbufferARB = d_wglCreatePbufferARB;
		gwglGetPbufferDCARB = d_wglGetPbufferDCARB;
		gwglReleasePbufferDCARB = d_wglReleasePbufferDCARB;
		gwglDestroyPbufferARB = d_wglDestroyPbufferARB;
		gwglQueryPbufferARB = d_wglQueryPbufferARB;
		gwglBindTexImageARB = d_wglBindTexImageARB;
		gwglReleaseTexImageARB = d_wglReleaseTexImageARB;
		gwglSetPbufferAttribARB = d_wglSetPbufferAttribARB;
		gwglCreateContextAttribsARB = d_wglCreateContextAttribsARB;
		gwglCreateDisplayColorTableEXT = d_wglCreateDisplayColorTableEXT;
		gwglLoadDisplayColorTableEXT = d_wglLoadDisplayColorTableEXT;
		gwglBindDisplayColorTableEXT = d_wglBindDisplayColorTableEXT;
		gwglDestroyDisplayColorTableEXT = d_wglDestroyDisplayColorTableEXT;
		gwglGetExtensionsStringEXT = d_wglGetExtensionsStringEXT;
		gwglMakeContextCurrentEXT = d_wglMakeContextCurrentEXT;
		gwglGetCurrentReadDCEXT = d_wglGetCurrentReadDCEXT;
		gwglCreatePbufferEXT = d_wglCreatePbufferEXT;
		gwglGetPbufferDCEXT = d_wglGetPbufferDCEXT;
		gwglReleasePbufferDCEXT = d_wglReleasePbufferDCEXT;
		gwglDestroyPbufferEXT = d_wglDestroyPbufferEXT;
		gwglQueryPbufferEXT = d_wglQueryPbufferEXT;
		gwglGetPixelFormatAttribivEXT = d_wglGetPixelFormatAttribivEXT;
		gwglGetPixelFormatAttribfvEXT = d_wglGetPixelFormatAttribfvEXT;
		gwglChoosePixelFormatEXT = d_wglChoosePixelFormatEXT;
		gwglSwapIntervalEXT = d_wglSwapIntervalEXT;
		gwglGetSwapIntervalEXT = d_wglGetSwapIntervalEXT;
		gwglAllocateMemoryNV = d_wglAllocateMemoryNV;
		gwglFreeMemoryNV = d_wglFreeMemoryNV;
		gwglGetSyncValuesOML = d_wglGetSyncValuesOML;
		gwglGetMscRateOML = d_wglGetMscRateOML;
		gwglSwapBuffersMscOML = d_wglSwapBuffersMscOML;
		gwglSwapLayerBuffersMscOML = d_wglSwapLayerBuffersMscOML;
		gwglWaitForMscOML = d_wglWaitForMscOML;
		gwglWaitForSbcOML = d_wglWaitForSbcOML;
		gwglGetDigitalVideoParametersI3D = d_wglGetDigitalVideoParametersI3D;
		gwglSetDigitalVideoParametersI3D = d_wglSetDigitalVideoParametersI3D;
		gwglGetGammaTableParametersI3D = d_wglGetGammaTableParametersI3D;
		gwglSetGammaTableParametersI3D = d_wglSetGammaTableParametersI3D;
		gwglGetGammaTableI3D = d_wglGetGammaTableI3D;
		gwglSetGammaTableI3D = d_wglSetGammaTableI3D;
		gwglEnableGenlockI3D = d_wglEnableGenlockI3D;
		gwglDisableGenlockI3D = d_wglDisableGenlockI3D;
		gwglIsEnabledGenlockI3D = d_wglIsEnabledGenlockI3D;
		gwglGenlockSourceI3D = d_wglGenlockSourceI3D;
		gwglGetGenlockSourceI3D = d_wglGetGenlockSourceI3D;
		gwglGenlockSourceEdgeI3D = d_wglGenlockSourceEdgeI3D;
		gwglGetGenlockSourceEdgeI3D = d_wglGetGenlockSourceEdgeI3D;
		gwglGenlockSampleRateI3D = d_wglGenlockSampleRateI3D;
		gwglGetGenlockSampleRateI3D = d_wglGetGenlockSampleRateI3D;
		gwglGenlockSourceDelayI3D = d_wglGenlockSourceDelayI3D;
		gwglGetGenlockSourceDelayI3D = d_wglGetGenlockSourceDelayI3D;
		gwglQueryGenlockMaxSourceDelayI3D = d_wglQueryGenlockMaxSourceDelayI3D;
		gwglCreateImageBufferI3D = d_wglCreateImageBufferI3D;
		gwglDestroyImageBufferI3D = d_wglDestroyImageBufferI3D;
		gwglAssociateImageBufferEventsI3D = d_wglAssociateImageBufferEventsI3D;
		gwglReleaseImageBufferEventsI3D = d_wglReleaseImageBufferEventsI3D;
		gwglEnableFrameLockI3D = d_wglEnableFrameLockI3D;
		gwglDisableFrameLockI3D = d_wglDisableFrameLockI3D;
		gwglIsEnabledFrameLockI3D = d_wglIsEnabledFrameLockI3D;
		gwglQueryFrameLockMasterI3D = d_wglQueryFrameLockMasterI3D;
		gwglGetFrameUsageI3D = d_wglGetFrameUsageI3D;
		gwglBeginFrameTrackingI3D = d_wglBeginFrameTrackingI3D;
		gwglEndFrameTrackingI3D = d_wglEndFrameTrackingI3D;
		gwglQueryFrameTrackingI3D = d_wglQueryFrameTrackingI3D;
		gwglSetStereoEmitterState3DL = d_wglSetStereoEmitterState3DL;
		gwglEnumerateVideoDevicesNV = d_wglEnumerateVideoDevicesNV;
		gwglBindVideoDeviceNV = d_wglBindVideoDeviceNV;
		gwglQueryCurrentContextNV = d_wglQueryCurrentContextNV;
		gwglGetVideoDeviceNV = d_wglGetVideoDeviceNV;
		gwglReleaseVideoDeviceNV = d_wglReleaseVideoDeviceNV;
		gwglBindVideoImageNV = d_wglBindVideoImageNV;
		gwglReleaseVideoImageNV = d_wglReleaseVideoImageNV;
		gwglSendPbufferToVideoNV = d_wglSendPbufferToVideoNV;
		gwglGetVideoInfoNV = d_wglGetVideoInfoNV;
		gwglJoinSwapGroupNV = d_wglJoinSwapGroupNV;
		gwglBindSwapBarrierNV = d_wglBindSwapBarrierNV;
		gwglQuerySwapGroupNV = d_wglQuerySwapGroupNV;
		gwglQueryMaxSwapGroupsNV = d_wglQueryMaxSwapGroupsNV;
		gwglQueryFrameCountNV = d_wglQueryFrameCountNV;
		gwglResetFrameCountNV = d_wglResetFrameCountNV;
		gwglEnumGpusNV = d_wglEnumGpusNV;
		gwglEnumGpuDevicesNV = d_wglEnumGpuDevicesNV;
		gwglCreateAffinityDCNV = d_wglCreateAffinityDCNV;
		gwglEnumGpusFromAffinityDCNV = d_wglEnumGpusFromAffinityDCNV;
		gwglDeleteDCNV = d_wglDeleteDCNV;
		gwglGetGPUIDsAMD = d_wglGetGPUIDsAMD;
		gwglGetGPUInfoAMD = d_wglGetGPUInfoAMD;
		gwglGetContextGPUIDAMD = d_wglGetContextGPUIDAMD;
		gwglCreateAssociatedContextAMD = d_wglCreateAssociatedContextAMD;
		gwglCreateAssociatedContextAttribsAMD = d_wglCreateAssociatedContextAttribsAMD;
		gwglDeleteAssociatedContextAMD = d_wglDeleteAssociatedContextAMD;
		gwglMakeAssociatedContextCurrentAMD = d_wglMakeAssociatedContextCurrentAMD;
		gwglGetCurrentAssociatedContextAMD = d_wglGetCurrentAssociatedContextAMD;
		gwglBlitContextFramebufferAMD = d_wglBlitContextFramebufferAMD;
		gwglBindVideoCaptureDeviceNV = d_wglBindVideoCaptureDeviceNV;
		gwglEnumerateVideoCaptureDevicesNV = d_wglEnumerateVideoCaptureDevicesNV;
		gwglLockVideoCaptureDeviceNV = d_wglLockVideoCaptureDeviceNV;
		gwglQueryVideoCaptureDeviceNV = d_wglQueryVideoCaptureDeviceNV;
		gwglReleaseVideoCaptureDeviceNV = d_wglReleaseVideoCaptureDeviceNV;
		gwglCopyImageSubDataNV = d_wglCopyImageSubDataNV;
		gwglDXSetResourceShareHandleNV = d_wglDXSetResourceShareHandleNV;
		gwglDXOpenDeviceNV = d_wglDXOpenDeviceNV;
		gwglDXCloseDeviceNV = d_wglDXCloseDeviceNV;
		gwglDXRegisterObjectNV = d_wglDXRegisterObjectNV;
		gwglDXUnregisterObjectNV = d_wglDXUnregisterObjectNV;
		gwglDXObjectAccessNV = d_wglDXObjectAccessNV;
		gwglDXLockObjectsNV = d_wglDXLockObjectsNV;
		gwglDXUnlockObjectsNV = d_wglDXUnlockObjectsNV;
	}
}
void gwgl_check_extensions(HDC hdc) {
	const char *extensionString = (const char *)gwglGetExtensionsStringARB(hdc);
	memset(&gwglext, 0, sizeof(gwglext));
	if (strstr(extensionString, "WGL_3DFX_multisample")) gwglext._WGL_3DFX_multisample = 1;
	if (strstr(extensionString, "WGL_3DL_stereo_control")) gwglext._WGL_3DL_stereo_control = 1;
	if (strstr(extensionString, "WGL_AMD_gpu_association")) gwglext._WGL_AMD_gpu_association = 1;
	if (strstr(extensionString, "WGL_ARB_buffer_region")) gwglext._WGL_ARB_buffer_region = 1;
	if (strstr(extensionString, "WGL_ARB_create_context")) gwglext._WGL_ARB_create_context = 1;
	if (strstr(extensionString, "WGL_ARB_create_context_profile")) gwglext._WGL_ARB_create_context_profile = 1;
	if (strstr(extensionString, "WGL_ARB_create_context_robustness")) gwglext._WGL_ARB_create_context_robustness = 1;
	if (strstr(extensionString, "WGL_ARB_extensions_string")) gwglext._WGL_ARB_extensions_string = 1;
	if (strstr(extensionString, "WGL_ARB_framebuffer_sRGB")) gwglext._WGL_ARB_framebuffer_sRGB = 1;
	if (strstr(extensionString, "WGL_ARB_make_current_read")) gwglext._WGL_ARB_make_current_read = 1;
	if (strstr(extensionString, "WGL_ARB_multisample")) gwglext._WGL_ARB_multisample = 1;
	if (strstr(extensionString, "WGL_ARB_pbuffer")) gwglext._WGL_ARB_pbuffer = 1;
	if (strstr(extensionString, "WGL_ARB_pixel_format")) gwglext._WGL_ARB_pixel_format = 1;
	if (strstr(extensionString, "WGL_ARB_pixel_format_float")) gwglext._WGL_ARB_pixel_format_float = 1;
	if (strstr(extensionString, "WGL_ARB_render_texture")) gwglext._WGL_ARB_render_texture = 1;
	if (strstr(extensionString, "WGL_ATI_pixel_format_float")) gwglext._WGL_ATI_pixel_format_float = 1;
	if (strstr(extensionString, "WGL_EXT_depth_float")) gwglext._WGL_EXT_depth_float = 1;
	if (strstr(extensionString, "WGL_EXT_display_color_table")) gwglext._WGL_EXT_display_color_table = 1;
	if (strstr(extensionString, "WGL_EXT_extensions_string")) gwglext._WGL_EXT_extensions_string = 1;
	if (strstr(extensionString, "WGL_EXT_framebuffer_sRGB")) gwglext._WGL_EXT_framebuffer_sRGB = 1;
	if (strstr(extensionString, "WGL_EXT_make_current_read")) gwglext._WGL_EXT_make_current_read = 1;
	if (strstr(extensionString, "WGL_EXT_multisample")) gwglext._WGL_EXT_multisample = 1;
	if (strstr(extensionString, "WGL_EXT_pbuffer")) gwglext._WGL_EXT_pbuffer = 1;
	if (strstr(extensionString, "WGL_EXT_pixel_format")) gwglext._WGL_EXT_pixel_format = 1;
	if (strstr(extensionString, "WGL_EXT_pixel_format_packed_float")) gwglext._WGL_EXT_pixel_format_packed_float = 1;
	if (strstr(extensionString, "WGL_EXT_swap_control")) gwglext._WGL_EXT_swap_control = 1;
	if (strstr(extensionString, "WGL_EXT_swap_control_tear")) gwglext._WGL_EXT_swap_control_tear = 1;
	if (strstr(extensionString, "WGL_EXT_texture_compression_s3tc")) gwglext._WGL_EXT_texture_compression_s3tc = 1;
	if (strstr(extensionString, "WGL_I3D_digital_video_control")) gwglext._WGL_I3D_digital_video_control = 1;
	if (strstr(extensionString, "WGL_I3D_gamma")) gwglext._WGL_I3D_gamma = 1;
	if (strstr(extensionString, "WGL_I3D_genlock")) gwglext._WGL_I3D_genlock = 1;
	if (strstr(extensionString, "WGL_I3D_image_buffer")) gwglext._WGL_I3D_image_buffer = 1;
	if (strstr(extensionString, "WGL_I3D_swap_frame_lock")) gwglext._WGL_I3D_swap_frame_lock = 1;
	if (strstr(extensionString, "WGL_I3D_swap_frame_usage")) gwglext._WGL_I3D_swap_frame_usage = 1;
	if (strstr(extensionString, "WGL_NV_DX_interop")) gwglext._WGL_NV_DX_interop = 1;
	if (strstr(extensionString, "WGL_NV_DX_interop2")) gwglext._WGL_NV_DX_interop2 = 1;
	if (strstr(extensionString, "WGL_NV_copy_image")) gwglext._WGL_NV_copy_image = 1;
	if (strstr(extensionString, "WGL_NV_float_buffer")) gwglext._WGL_NV_float_buffer = 1;
	if (strstr(extensionString, "WGL_NV_gpu_affinity")) gwglext._WGL_NV_gpu_affinity = 1;
	if (strstr(extensionString, "WGL_NV_multisample_coverage")) gwglext._WGL_NV_multisample_coverage = 1;
	if (strstr(extensionString, "WGL_NV_present_video")) gwglext._WGL_NV_present_video = 1;
	if (strstr(extensionString, "WGL_NV_swap_group")) gwglext._WGL_NV_swap_group = 1;
	if (strstr(extensionString, "WGL_NV_vertex_array_range")) gwglext._WGL_NV_vertex_array_range = 1;
	if (strstr(extensionString, "WGL_NV_video_capture")) gwglext._WGL_NV_video_capture = 1;
	if (strstr(extensionString, "WGL_NV_video_output")) gwglext._WGL_NV_video_output = 1;
	if (strstr(extensionString, "WGL_OML_sync_control")) gwglext._WGL_OML_sync_control = 1;
}
