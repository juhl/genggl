About
============================

GLGen is platform independent OpenGL API C glue code generator written in ruby

it will help to write your OpenGL program with no concerning about OpenGL version and platform (not including OpenGL ES)

Features
----------------------------

* platform independent binding to specific OpenGL version (you can specify version as argument)
* it parse [OpenGL registry](http://www.opengl.org/registry) spec files as source for up-to-date API
* there are debug helper per OpenGL function call

Usage
----------------------------
you need ruby in system for use

	$ cd glgen
	$ ruby glgen.rb <core-version>

you can specify OpenGL core version at <core-version> (default: 1.1)

and then, you could get ggl.h, ggl.c, gglx.h, gglx.c, gwgl.h, gwgl.c

Usage about ggl (generated C code)
----------------------------
* ggl_init: initialize ggl function pointers for use.
* ggl_rebind: re-bind ggl function pointers for debug purpose
* ggl_check_extensions: check the extensions
* you can check extensions easily with provided struct. (ex. gglext._GL_EXT_texture3D)
* there are additional platform dependent version (similar as above)

##ggl.h##

	extern gglcaps_t gglcaps;

	extern void ggl_init(int enableDebug);	
	extern void ggl_rebind(int enableDebug);
	extern void ggl_check_extensions();

##gwgl.h (for windows extension)##

	extern gglcaps_t gwglcaps;

	extern void gwgl_init(int enableDebug);	
	extern void gwgl_rebind(int enableDebug);
	extern void gwgl_check_extensions(HDC hdc);

##gglx.h (for linux extension)##

	extern gglcaps_t gglxcaps;

	extern void gglx_init(int enableDebug);	
	extern void gglx_rebind(int enableDebug);
	extern void gglx_check_extensions();

Callback functions
----------------------------
	/* if you want check GL error, you should set enableDebug as true when calling ggl_bind */
	void CheckGLError(const char *msg)
	{
    	... 
	}

	/* you should provide dynamic function getter (just like GetProcAddress in windows) for Mac OS X for now (0.1) */
	void *mglGetProcAddress(const char *name)
	{
    	...
	}
