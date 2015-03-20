#----------------------------------------------------------------------------------------------
#
# genggl.rb
# GenGGL (OpenGL extension glue code generator in C)
# Version: 0.3.0
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

$genggl_version_string = "0.3.0"
$genggl_prefix = "g"

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

  def generate_header_and_source_file(dirname, basename)
    Dir.mkdir(dirname) unless File.exists?(dirname)

    generate_header_file(dirname, basename)
    generate_source_file(dirname, basename)
  end

  def generate_header_file(dirname, basename)
    File.open("#{dirname}/#{basename}.h", "w") do |f|
      write_license_comment(f, "#{basename}.h")

      f << "\n#ifndef __#{basename.upcase}_H__\n"
      f << "#define __#{basename.upcase}_H__\n\n"
      f << "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n"

      if @spec.api == "gl"
        f << "#ifdef _WIN32\n\n"
        f << "#include <windows.h>\n"
        f << "#include <gl/gl.h>\n\n"
        f << "#elif defined(__APPLE__)\n\n"
        f << "#define GL_GLEXT_LEGACY\n"
        f << "#include <OpenGL/gl.h>\n\n"
        f << "#elif defined(__linux__)\n"
        f << "#include <gl/gl.h>\n\n"
        f << "#endif\n\n"
      elsif @spec.api == "wgl"
        f << "#include <windows.h>\n"
        f << "#include <gl/gl.h>\n\n"
      end

      f << "#ifndef APIENTRY\n#define APIENTRY\n#endif\n"
      f << "#ifndef APIENTRYP\n#define APIENTRYP APIENTRY *\n#endif\n"
      f << "#ifndef GLAPI\n#define GLAPI extern\n#endif\n\n"

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
      else
        f << "extern void #{basename}_init(int enableDebug);\n"
      end
      f << "extern void #{basename}_rebind(int enableDebug);\n"

      f << "\n#ifdef __cplusplus\n}\n#endif\n\n"
      f << "#endif /* __#{basename.upcase}_H__ */\n"
    end

    puts "#{dirname}/#{basename}.h generated"
  end

  def write_header_types(f)
    @spec.types.each do |type|
      next if type.name == "khrplatform"

      if !type.content.empty?
        f << "#{type.content}\n"
      end
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
      f << "#define #{extension.name}\n"

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

  def generate_source_file(dirname, basename)
    File.open("#{dirname}/#{basename}.c", "w") do |f|
      write_license_comment(f, "#{basename}.c")

      f << "\n#include \"#{basename}.h\"\n"
      f << "#include <string.h>\n\n"
      f << "extern void CheckGLError(const char *msg);\n"

      if has_glBegin
        f << "static int _#{$genggl_prefix}glBeginStarted = 0;\n"
      end

      write_source_gl_functions(f)

      f << "\n#ifdef _WIN32\n"
      f << "#define GPA(a) wglGetProcAddress(\#a)\n"
      f << "#elif defined(__APPLE__)\n"
      f << "#define GPA(a) mglGetProcAddress(\#a)\n"
      f << "extern void *mglGetProcAddress(const char *name);\n"
      f << "#elif defined(__linux__)\n"
      f << "#define GPA(a) glXGetProcAddressARB((const GLubyte *)\#a)\n"
      f << "#endif\n\n"

      f << "#{basename}ext_t #{basename}ext;\n"

      write_source_func_init(basename, f)
      write_source_func_rebind(basename, f)
    end

    puts "#{dirname}/#{basename}.c generated"
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
    end

    f << "\nstatic int #{basename}_check_extension(const char *ext) {\n"

    if @spec.api == "wgl" || !@has_GL_NUM_EXTENSIONS
      f << "\treturn strstr(#{basename}ext_str, ext) ? 1 : 0;\n"
    else
      f << "\tfor (GLint i = 0; i < #{basename}ext_count; i++) {\n"
      f << "\t\tif (!strcmp((const char *)_glGetStringi(GL_EXTENSIONS, i), ext)) {\n";
      f << "\t\t\treturn 1;\n"
      f << "\t\t}\n"
      f << "\t}\n"
      f << "\treturn 0;\n"
    end

    f << "}\n"

    if @spec.api == "wgl"
      f << "\nvoid #{basename}_init(HDC hdc, int enableDebug) {\n"
    else
      f << "\nvoid #{basename}_init(int enableDebug) {\n"
    end

    @spec.features.each do |feature|
      f << "\t/* #{feature.name} */\n"

      feature.commands.each do |command|
        next if !command.required

        if feature.version <= 1.1
          f << "\t_#{command.name} = #{command.name};\n"
        else
          f << "\t_#{command.name} = (PFN#{command.name.upcase})GPA(#{command.name});\n"
        end
      end

      f << "\n"
    end

    @spec.extensions.each do |extension|
      f << "\t/* #{extension.name} */\n"

      extension.commands.each do |command|
        next if !command.required

        f << "\t_#{command.name} = (PFN#{command.name.upcase})GPA(#{command.name});\n"
      end

      f << "\n"
    end

    f << "\t#{basename}_rebind(enableDebug);\n"
    f << "\n"

    if @spec.api == "wgl"
      f << "\t#{basename}ext_str = (const char *)_wglGetExtensionsStringARB(hdc);\n"
    elsif !@has_GL_NUM_EXTENSIONS
      f << "\t#{basename}ext_str = (const char *)_glGetString(GL_EXTENSIONS);\n"
    else
      f << "\t_glGetIntegerv(GL_NUM_EXTENSIONS, &#{basename}ext_count);\n"
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

#-------------------------------------------------------------------------------

valid_profile_strings = ["core", "compatibility", "es"]

if ARGV[0] == "--help"
  puts "Usage: genggl <api> <version>"
  puts "profile: one of the #{valid_profile_strings.join(", ")}"
  puts "version: version number"
  exit
end

$all_version = 100
$user_version = ARGV[1].to_f

case ARGV[0]
when "core"
  $user_profile = "core"
  $user_api = "gl"
  $user_dir = "glcore"
when "compatibility"
  $user_profile = "compatibility"
  $user_api = "gl"
  $user_dir = "gl"
when "es"
  $user_profile = "common"
  if $user_version < 2.0
    $user_api = "gles1"
    $user_dir = "es"
  elsif $user_version < 3.0
    $user_api = "gles2"
    $user_dir = "es2"
  else
    $user_api = "gles2"
    $user_dir = "es3"
  end
else
  puts "Invalid profile #{ARGV[0]}"
  exit
end

puts "Trying to generate GGL based on #{$user_api} #{$user_profile} #{$user_version}"

#-------------------------------------------------------------------------------

#registry_url = "http://www.opengl.org/registry/api"
#registry_url = "https://cvs.khronos.org/svn/repos/ogl/trunk/doc/registry/public/oldspecs"
registry_url = "https://cvs.khronos.org/svn/repos/ogl/trunk/doc/registry/public/api"

spec = GLSpec.new(
  :api => $user_api,
  :profile => $user_profile,
  :version => $user_version,
  :url => "#{registry_url}/gl.xml"
)

gen = GGLGenerator.new(spec)
gen.generate_header_and_source_file($user_dir, "#{$genggl_prefix}gl")

if $user_api == "gl"
  spec = GLSpec.new(
    :api => "glx",
    :profile => "common",
    :version => $all_version,
    :url => "#{registry_url}/glx.xml"
  )

  gen = GGLGenerator.new(spec)
  gen.generate_header_and_source_file($user_dir, "#{$genggl_prefix}glx")

  spec = GLSpec.new(
    :api => "wgl",
    :profile => "common",
    :version => $all_version,
    :url => "#{registry_url}/wgl.xml"
  )

  gen = GGLGenerator.new(spec)
  gen.generate_header_and_source_file($user_dir, "#{$genggl_prefix}wgl")
end
