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
* ggl_init: ggl initializer. (it should be called after setting current GL context)
* ggl_bind: binding ggl functions (actually you can use ggl functions by calling this function)
* you can check extensions easily with provided struct. (ex. gglcaps._GL_EXT_texture3D)
* there are additional platform dependent version (usage is same as above)

##ggl.h##

	extern gglcaps_t gglcaps;

	extern void ggl_init();
	extern void ggl_bind(int enableDebug);

##gglx.h (for linux extension)##

	extern gglcaps_t gglxcaps;

	extern void gglx_init();
	extern void gglx_bind(int enableDebug);

##zwgl.h (for windows extension)##

	extern gglcaps_t gwglcaps;

	extern void gwgl_init();
	extern void gwgl_bind(int enableDebug);

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
