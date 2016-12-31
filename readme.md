GenGGL 0.3.3
============================

GenGGL is platform independent OpenGL API C glue code generator written in ruby.

It will help you to write OpenGL C/C++ code without concerning OpenGL versions and platforms.

Features
----------------------------

* Platform independent bindings to specific OpenGL profile and version. (you can specify it with a following argument)
* Parsing [OpenGL registry](http://www.opengl.org/registry) XML files as source to generate up-to-date API.
* There is debug functionalities for OpenGL function calls.

Usage
----------------------------
First off, you need ruby 2.0 in system for use. 

	$ cd genggl
	$ ruby genggl.rb <api> <version>

You can specify the profile that is one of the "CORE", "COMPATIBILITY", "ES" and version. 
After that, you could get ggl.h, ggl.c, gglx.h, gglx.c, gwgl.h, gwgl.c

Issues
----------------------------
SSL connection error on Windows platform -> [Solution](https://gist.github.com/fnichol/867550)

Usage about ggl (generated C code)
----------------------------
* ggl_init: initialize ggl function pointers for use.
* ggl_rebind: re-bind ggl function pointers for debug purpose
* you can check extensions easily with provided extension struct. (ex. gglext._GL_EXT_texture3D)

##ggl.h##

	extern gglext_t gglext;

	extern void ggl_init(int enableDebug);
	extern void ggl_rebind(int enableDebug);

##gwgl.h (for windows extension)##

	extern gwglext_t gwglext;

	extern void gwgl_init(HDC hdc, int enableDebug);
	extern void gwgl_rebind(int enableDebug);

##gglx.h (for linux extension)##

	extern gglxext_t gglxext;

	extern void gglx_init(int enableDebug);
	extern void gglx_rebind(int enableDebug);

Callback functions
----------------------------
	/* if you want check GL error, you should set enableDebug as true when calling ggl_bind */
	void CheckGLError(const char *msg)
	{
    	...
	}
