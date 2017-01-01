require 'net/http'

STDOUT.sync = true

#-------------------------------------------------------------------------------

puts "Downloading GL header files..."

Dir.mkdir("GL") unless File.exists?("GL")
File.write("GL/glext.h", Net::HTTP.get(URI.parse("https://www.opengl.org/registry/api/GL/glext.h")))
File.write("GL/glcorearb.h", Net::HTTP.get(URI.parse("https://www.opengl.org/registry/api/GL/glcorearb.h")))
File.write("GL/glxext.h", Net::HTTP.get(URI.parse("https://www.opengl.org/registry/api/GL/glxext.h")))
File.write("GL/wglext.h", Net::HTTP.get(URI.parse("https://www.opengl.org/registry/api/GL/wglext.h")))

#-------------------------------------------------------------------------------

puts "Downloading GLES header files..."

Dir.mkdir("GLES") unless File.exists?("GLES")
File.write("GLES/gl.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES/gl.h")))
File.write("GLES/glext.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES/glext.h")))
File.write("GLES/glplatform.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES/glplatform.h")))

Dir.mkdir("GLES2") unless File.exists?("GLES2")
File.write("GLES2/gl2.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES2/gl2.h")))
File.write("GLES2/gl2ext.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES2/gl2ext.h")))
File.write("GLES2/gl2platform.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES2/gl2platform.h")))

Dir.mkdir("GLES3") unless File.exists?("GLES3")
File.write("GLES3/gl3.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES3/gl3.h")))
File.write("GLES3/gl31.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES3/gl31.h")))
File.write("GLES3/gl32.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES3/gl32.h")))
File.write("GLES3/gl3platform.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/gles/api/GLES3/gl3platform.h")))

#-------------------------------------------------------------------------------

puts "Downloading KHR header files..."

Dir.mkdir("KHR") unless File.exists?("KHR")
File.write("KHR/khrplatform.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/egl/api/KHR/khrplatform.h")))

#-------------------------------------------------------------------------------

puts "Downloading EGL header files..."

Dir.mkdir("EGL") unless File.exists?("EGL")
File.write("EGL/egl.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/egl/api/EGL/egl.h")))
File.write("EGL/eglext.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/egl/api/EGL/eglext.h")))
File.write("EGL/eglplatform.h", Net::HTTP.get(URI.parse("http://khronos.org/registry/egl/api/EGL/eglplatform.h")))

#-------------------------------------------------------------------------------
