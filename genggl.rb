#----------------------------------------------------------------------------------------------
#
# genggl.rb
# GenGGL (OpenGL extension glue code generator in C)
#
# Copyright 2010 Ju Hyung Lee. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are
# permitted provided that the following conditions are met:
#
#    1. Redistributions of source code must retain the above copyright notice, this list of
#       conditions and the following disclaimer.
#
#    2. Redistributions in binary form must reproduce the above copyright notice, this list
#       of conditions and the following disclaimer in the documentation and/or other materials
#       provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY JU HYUNG LEE ``AS IS'' AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
# FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL JU HYUNG LEE OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
# ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# The views and conclusions contained in the software and documentation are those of the
# authors and should not be interpreted as representing official policies, either expressed
# or implied, of Ju Hyung Lee.
#
#----------------------------------------------------------------------------------------------

$genggl_version_string = "0.5"
$genggl_prefix = "g"

$gl_platform_text = <<TEXT
#ifdef _WIN32
#include <windows.h>
#include <gl/gl.h>
#endif

#if defined(__APPLE__)
#define GL_GLEXT_LEGACY
#include <OpenGL/gl.h>
#endif

#if defined(__linux__)
#include <gl/gl.h>
#endif
TEXT

$wgl_platform_text = <<TEXT
#include <windows.h>
#include <gl/gl.h>
TEXT

$gles1_platform_text = <<TEXT
#if defined(_WIN32)
#include "GLES/gl.h"
#elif defined(__APPLE__)
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include "KHR/khrplatform.h"
#elif defined(ANDROID)
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <GLES/glplatform.h>
#endif
TEXT

$gles2_platform_text = <<TEXT
#if defined(_WIN32)
#include "GLES2/gl2.h"
#elif defined(__APPLE__)
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "KHR/khrplatform.h"
#elif defined(ANDROID)
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>
#endif
TEXT

$gles3_platform_text = <<TEXT
#if defined(_WIN32)
#include "GLES3/gl3.h"
#elif defined(__APPLE__)
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include "KHR/khrplatform.h"
#elif defined(ANDROID)
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <GLES3/gl3platform.h>
#endif
TEXT

$egl_platform_text = <<TEXT
#include "EGL/egl.h"
TEXT

$gl_gpa_text = <<TEXT
#ifdef _WIN32
#define GPA(a) wglGetProcAddress(#a)
#elif defined(__APPLE__)
#define GPA(a) nsglGetProcAddress(#a)
#include <CoreFoundation/CoreFoundation.h>
void *nsglGetProcAddress(const char *procname) {
    static CFBundleRef openGLFramework = nil;
    if (openGLFramework == nil) {
        openGLFramework = CFBundleGetBundleWithIdentifier(CFSTR("com.apple.opengl"));
    }

    CFStringRef symbolName = CFStringCreateWithCString(kCFAllocatorDefault, procname, kCFStringEncodingASCII);
    void *symbol = CFBundleGetFunctionPointerForName(openGLFramework, symbolName);
    CFRelease(symbolName);
    
    return symbol;
}
#elif defined(__linux__)
#define GPA(a) glXGetProcAddressARB((const GLubyte *)#a)
#endif
TEXT

$gles_gpa_text = <<TEXT
#if defined(ANDROID) || defined(__linux__)
#include <EGL/egl.h>
#define GPA(a) eglGetProcAddress(#a)
#elif defined(__APPLE__)
#define GPA(a) a
#endif
TEXT

$egl_gpa_text = <<TEXT
#include <EGL/egl.h>
#define GPA(a) eglGetProcAddress(#a)
TEXT

#require 'profile'
require 'rbconfig'
require './glspec.rb'

include RbConfig

class GGLGenerator
  attr_reader :spec, :has_glBegin, :has_GL_NUM_EXTENSIONS

  def initialize(spec)
    @spec = spec

    # glBegin/glEnd deprecated in version core 3.1
    @has_glBegin = @spec.commands.find { |x| x.name == "glBegin" && x.required }
    # GL_NUM_EXTENSIONS
    @has_GL_NUM_EXTENSIONS = @spec.enums.find { |x| x.name == "GL_NUM_EXTENSIONS" && x.required }
  end

  def write_license_comment(f, filename)
    text = <<TEXT
/*********************************************************************************************
 *
 * #{filename}
 * #{$genggl_prefix}gl (OpenGL glue code library)
 * Version: #{$genggl_version_string}
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
TEXT
    f << text
  end

  def generate_header_and_source_file(dirname, filename, basename)
    Dir.mkdir(dirname) unless File.exists?(dirname)

    generate_header_file(dirname, filename, basename)
    generate_source_file(dirname, filename, basename)
  end

  def generate_header_file(dirname, filename, basename)
    File.open("#{dirname}/#{filename}.h", "w") do |f|
      write_license_comment(f, "#{filename}.h")

      f << "\n#ifndef __#{filename.upcase}_H__\n"
      f << "#define __#{filename.upcase}_H__\n\n"
      f << "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n"

      if @spec.api == "gl"
        f << $gl_platform_text
      elsif @spec.api == "wgl"
        f << $wgl_platform_text
      elsif @spec.api =~ /^gles/
        if $user_version < 2.0
          f << $gles1_platform_text
        elsif $user_version < 3.0
          f << $gles2_platform_text
        else
          f << $gles3_platform_text
        end
      elsif @spec.api == "egl"
        f << $egl_platform_text
      end

      f << "#ifndef APIENTRY\n"
      f << "#define APIENTRY\n"
      f << "#endif\n"
      f << "#ifndef APIENTRYP\n"
      f << "#define APIENTRYP APIENTRY *\n"
      f << "#endif\n"
      f << "#ifndef GLAPI\n"
      f << "#define GLAPI extern\n"
      f << "#endif\n\n"

      write_header_types(f)
      write_header_features(f)
      write_header_extensions(f)

      f << "/* #{@spec.extensions.count} extensions */\n"
      f << "typedef struct {\n"

      @spec.extensions.each do |extension|
        f << "\tint _#{extension.name} : 1;\n"
      end

      f << "} #{basename}ext_t;\n\n";

      f << "extern #{basename}ext_t #{basename}ext;\n\n"

      if @spec.api == "wgl"
        f << "extern void #{basename}_init(HDC hdc, int enableDebug);\n"
      elsif @spec.api == "egl"
        f << "extern void #{basename}_init(EGLDisplay display, int enableDebug);\n"        
      else
        f << "extern void #{basename}_init(int enableDebug);\n"
      end
      f << "extern void #{basename}_rebind(int enableDebug);\n"

      f << "\n#ifdef __cplusplus\n}\n#endif\n\n"
      f << "#endif /* __#{filename.upcase}_H__ */\n"
    end

    puts "#{dirname}/#{filename}.h generated"
  end

  def write_header_types(f)
    @spec.types.each do |type|
      next if type.content.empty?

      f << "#{type.content}\n"      
    end

    f << "\n"
  end

  def write_header_features(f)
    @spec.features.each do |feature|
      next if @spec.api == "wgl" && feature.version <= 1.0
      next if @spec.api == "glx" && feature.version <= 1.2

      f << "#ifndef #{feature.name}\n"
      f << "#define #{feature.name}\n"

      feature.enums.each do |enum|
        next if !enum.required
        f << "#define #{enum.name} #{enum.value}\n"
      end

      f << "#endif\n"

      feature.commands.each do |command|
        next if !command.required
        f << "extern #{command.return_type} (APIENTRYP #{$genggl_prefix}#{command.name})(#{command.params.join(", ")});\n"
      end

      f << "\n"
    end
  end

  def write_header_extensions(f)
    @spec.extensions.each do |extension|
      f << "#ifndef #{extension.name}\n"
      f << "#define #{extension.name}\n" if @spec.api !~ /^gles/

      extension.enums.each do |enum|
        next if !enum.required
        if enum.reused
          f << "/* reuse #{enum.name} */\n"
        else
          f << "#define #{enum.name} #{enum.value}\n"
        end
      end

      f << "#endif\n"

      extension.commands.each do |command|
        next if !command.required
        if command.reused
          f << "/* reuse #{command.return_type} (APIENTRYP #{$genggl_prefix}#{command.name})(#{command.params.join(", ")}) */\n"
        else
          f << "extern #{command.return_type} (APIENTRYP #{$genggl_prefix}#{command.name})(#{command.params.join(", ")});\n"
        end
      end

      f << "\n"
    end
  end

  def generate_source_file(dirname, filename, basename)
    File.open("#{dirname}/#{filename}.c", "w") do |f|
      write_license_comment(f, "#{filename}.c")

      f << "\n#include \"#{filename}.h\"\n"
      f << "#include <string.h>\n\n"
      f << "extern void CheckGLError(const char *msg);\n\n"

      if has_glBegin
        f << "static int _#{$genggl_prefix}glBeginStarted = 0;\n"
      end

      write_source_gl_functions(f)

      if @spec.api =~ /^(gl|wgl|glx)$/
        f << "\n"
        f << $gl_gpa_text
        f << "\n"
      elsif @spec.api =~ /^gles/
        f << "\n"
        f << $gles_gpa_text
        f << "\n"
      else @spec.api =~ /^egl/
        f << "\n"
        f << $egl_gpa_text
        f << "\n"
      end

      f << "#{basename}ext_t #{basename}ext;\n"

      write_source_func_init(basename, f)
      write_source_func_rebind(basename, f)
    end

    puts "#{dirname}/#{filename}.c generated"
  end

  def write_source_gl_functions(f)
    @spec.commands.each do |command|
      next if !command.required
      next if command.reused

      # ggl function pointer
      f << "typedef #{command.return_type} (APIENTRYP PFN#{command.name.upcase})(#{command.params.join(", ")});\n"
      f << "PFN#{command.name.upcase} #{$genggl_prefix}#{command.name};\n"
      f << "static PFN#{command.name.upcase} _#{command.name};\n"
      call_name = "_" + command.name

      # debug ggl function
      f << "static #{command.return_type} APIENTRY d_#{command.name}(#{command.params.join(", ")}) {\n"

      if command.return_type.casecmp("void") == 0
        f << "\t#{call_name}("
      else
        f << "\t#{command.return_type} ret = #{call_name}("
      end

      command.params.each_index do |i|
        f << ", " if i > 0
        f << command.params[i].name
      end

      f << ");\n"

      if @has_glBegin
        if command.name == "glBegin"
          f << "\t_#{$genggl_prefix}glBeginStarted++;\n"
        elsif command.name == "glEnd"
          f << "\t_#{$genggl_prefix}glBeginStarted--;\n"
        end

        f << "\tif (!_#{$genggl_prefix}glBeginStarted) { CheckGLError(\"#{command.name}\"); }\n"
      else
        f << "\tCheckGLError(\"#{command.name}\");\n"
      end

      f << "\treturn ret;\n" if command.return_type.casecmp("void") != 0
      f << "}\n"
    end
  end

  def write_source_func_init(basename, f)
    if @spec.api == "wgl" || !@has_GL_NUM_EXTENSIONS
      f << "static const char *#{basename}ext_str = NULL;\n"
    else
      f << "static GLint #{basename}ext_count = 0;\n"
      f << "static const char *#{basename}ext_strings[512];\n"
    end

    f << "\nstatic int #{basename}_check_extension(const char *ext) {\n"

    if @spec.api == "wgl" || !@has_GL_NUM_EXTENSIONS
      f << "\treturn strstr(#{basename}ext_str, ext) ? 1 : 0;\n"
    else
      f << "\tGLint i = 0;\n"
      f << "\tfor (; i < #{basename}ext_count; i++) {\n"
      f << "\t\tif (!strcmp(#{basename}ext_strings[i], ext)) {\n";
      f << "\t\t\treturn 1;\n"
      f << "\t\t}\n"
      f << "\t}\n"
      f << "\treturn 0;\n"
    end

    f << "}\n"

    if @spec.api == "wgl"
      f << "\nvoid #{basename}_init(HDC hdc, int enableDebug) {\n"
    elsif @spec.api == "egl"
      f << "\nvoid #{basename}_init(EGLDisplay display, int enableDebug) {\n"
    else
      f << "\nvoid #{basename}_init(int enableDebug) {\n"
    end

    @spec.features.each do |feature|
      if feature.commands.count > 0
        f << "\t/* #{feature.name} */\n" 
      end

      feature.commands.each do |command|
        next if !command.required

        if (@spec.api == 'gl' && feature.version <= 1.1)
          f << "\t_#{command.name} = #{command.name};\n"
        else
          f << "\t_#{command.name} = (PFN#{command.name.upcase})GPA(#{command.name});\n"
        end
      end

      if feature.commands.count > 0
        f << "\n"
      end
    end

    @spec.extensions.each do |extension|
      if extension.commands.count > 0
        if @spec.api =~ /^gles/ || @spec.api =~ /^egl/
          f << "#ifdef #{extension.name}\n"
        else
          f << "\t/* #{extension.name} */\n"
        end
      end

      extension.commands.each do |command|
        next if !command.required
    
        f << "\t_#{command.name} = (PFN#{command.name.upcase})GPA(#{command.name});\n"
      end

      if extension.commands.count > 0
        if @spec.api =~ /^gles/ || @spec.api =~ /^egl/
          f << "#endif\n\n"
        else
          f << "\n"
        end
      end
    end

    f << "\t#{basename}_rebind(enableDebug);\n"
    f << "\n"

    if @spec.api == "wgl"
      f << "\t#{basename}ext_str = (const char *)_wglGetExtensionsStringARB(hdc);\n"
    elsif @spec.api == "egl"
      f << "\t#{basename}ext_str = (const char *)_eglQueryString(display, EGL_EXTENSIONS);\n"
    elsif !@has_GL_NUM_EXTENSIONS
      f << "\t#{basename}ext_str = (const char *)_glGetString(GL_EXTENSIONS);\n"
    else
      f << "\t_glGetIntegerv(GL_NUM_EXTENSIONS, &#{basename}ext_count);\n"
      f << "\tfor (int i = 0; i < #{basename}ext_count; i++) {\n"
      f << "\t\t#{basename}ext_strings[i] = (const char *)_glGetStringi(GL_EXTENSIONS, i);\n"
      f << "\t}\n"
    end

    f << "\tmemset(&#{basename}ext, 0, sizeof(#{basename}ext));\n"

    @spec.extensions.each do |extension|
      f << "\tif (#{basename}_check_extension(\"#{extension.name}\")) #{basename}ext._#{extension.name} = 1;\n"
    end

    f << "}\n\n"
  end

  def write_source_func_rebind(basename, f)
    f << "void #{basename}_rebind(int enableDebug) {\n"
    f << "\tif (!enableDebug) {\n"

    @spec.commands.each do |command|
      next if !command.required

      f << "\t\t#{$genggl_prefix}#{command.name} = _#{command.name};\n"
    end

    f << "\t} else {\n"

    @spec.commands.each do |command|
      next if !command.required

      f << "\t\t#{$genggl_prefix}#{command.name} = d_#{command.name};\n"
    end

    f << "\t}\n"
    f << "}\n"
  end
end

#-------------------------------------------------------------------------------

def get_os_type
  case RbConfig::CONFIG['host_os']
  when /mswin|windows/i then 'windows'
  when /linux/i then 'linux'
  when /darwin/i then 'macosx'
  else; nil; end
end

# 3.0 -> 3
# 3.2 -> 32
def version_to_s(version)
  while version.modulo(1) != 0 do
    version = version * 10
  end

  return version.to_i.to_s
end

#-------------------------------------------------------------------------------

valid_profile_strings = ["core", "compatibility", "es"]

STDOUT.sync = true

if ARGV[0] == "--help"
  puts "Usage: genggl <api> <version>"
  puts "profile: one of the #{valid_profile_strings.join(", ")}"
  puts "version: version number"
  exit
end

all_version = 100
$user_version = ARGV[1].to_f

if ARGV[0].casecmp("core") == 0
  $user_profile = "core"
  $user_api = "gl"
  $user_filename = "glcore" + version_to_s($user_version)
elsif ARGV[0].casecmp("compatibility") == 0
  $user_profile = "compatibility"
  $user_api = "gl"
  $user_filename = "gl"
elsif ARGV[0].casecmp("es") == 0
  $user_profile = "common"
  if $user_version < 2.0
    $user_api = "gles1"
    $user_filename = "gles"
  elsif $user_version < 3.0
    $user_api = "gles2"
    $user_filename = "gles2"
  else
    $user_api = "gles2"
    $user_filename = "gles" + version_to_s($user_version)
  end
else
  puts "Invalid profile #{ARGV[0]}"
  exit
end

puts "Trying to generate GGL based on #{$user_api} #{$user_profile} #{$user_version}"

#-------------------------------------------------------------------------------

registry_url = "https://cvs.khronos.org/svn/repos/ogl/trunk/doc/registry/public/api"

spec = GLSpec.new(
  :api => $user_api,
  :profile => $user_profile,
  :version => $user_version,
  :url => "#{registry_url}/gl.xml"
)

gen = GGLGenerator.new(spec)
gen.generate_header_and_source_file("GGL", "#{$genggl_prefix}#{$user_filename}", "#{$genggl_prefix}gl")

if $user_api == "gl"
  spec = GLSpec.new(
    :api => "glx",
    :profile => "common",
    :version => all_version,
    :url => "#{registry_url}/glx.xml"
  )

  gen = GGLGenerator.new(spec)
  gen.generate_header_and_source_file("GGL", "#{$genggl_prefix}glx", "#{$genggl_prefix}glx")

  spec = GLSpec.new(
    :api => "wgl",
    :profile => "common",
    :version => all_version,
    :url => "#{registry_url}/wgl.xml"
  )

  gen = GGLGenerator.new(spec)
  gen.generate_header_and_source_file("GGL", "#{$genggl_prefix}wgl", "#{$genggl_prefix}wgl")
end

if $user_api == "gles1" || $user_api == "gles2"
  spec = GLSpec.new(
    :api => "egl",
    :profile => "common",
    :version => all_version,
    :url => "#{registry_url}/egl.xml"
  )

  gen = GGLGenerator.new(spec)
  gen.generate_header_and_source_file("GGL", "#{$genggl_prefix}egl", "#{$genggl_prefix}egl")
end