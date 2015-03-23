#----------------------------------------------------------------------------------------------
#
# old_genggl.rb
# GenGGL (OpenGL extension glue code generator in C)
# Version: 0.3.2
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

$genggl_version_string = "0.2.2"
$genggl_prefix = "g"

#require 'profile'
require 'rbconfig'
require './old_glspec.rb'

include RbConfig

class GGLGenerator
  attr_reader :spec

  def initialize(spec, enum_prefix, command_prefix, category_prefix)
    @enum_prefix = enum_prefix
    @command_prefix = command_prefix
    @category_prefix = category_prefix
    @spec = spec
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

  def generate_header_and_source_file(basename)
    generate_header_file(basename)
    generate_source_file(basename)
  end

  def generate_header_file(basename)
    File.open("#{basename}.h", "w") do |f|
      write_license_comment(f, "#{basename}.h")

      f << "\n#ifndef __#{basename.upcase}_H__\n"
      f << "#define __#{basename.upcase}_H__\n\n"
      f << "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n"

      if @category_prefix == "GL_"
        f << "#ifdef _WIN32\n\n"
        f << "#include <windows.h>\n"
        f << "#include <gl/gl.h>\n\n"
        f << "#elif defined(__APPLE__)\n\n"
        f << "#define GL_GLEXT_LEGACY\n"
        f << "#include <OpenGL/gl.h>\n\n"
        f << "#elif defined(__linux__)\n"
        f << "#include <gl/gl.h>\n\n"
        f << "#endif\n\n"
      elsif @category_prefix == "WGL_"
        f << "#include <windows.h>\n"
        f << "#include <gl/gl.h>\n\n"
      end

      f << "#ifndef APIENTRY\n#define APIENTRY\n#endif\n"
      f << "#ifndef APIENTRYP\n#define APIENTRYP APIENTRY *\n#endif\n"
      f << "#ifndef GLAPI\n#define GLAPI extern\n#endif\n\n"

      write_header_defines(f)
      write_header_function_prototypes(f)

      f << "\ntypedef struct {\n"

      @spec.categories.sort.each do |category_name|
        next if category_name !~ /^(#{@spec.extension_group_names.join('|')})_/
        f << "\tint _#{@category_prefix}#{category_name} : 1;\n"
      end

      f << "} #{basename}ext_t;\n\n";

      f << "extern #{basename}ext_t #{basename}ext;\n\n"

      if @category_prefix == "WGL_"
        f << "extern void #{basename}_init(HDC hdc, int enableDebug);\n"
      else
        f << "extern void #{basename}_init(int enableDebug);\n"
      end
      f << "extern void #{basename}_rebind(int enableDebug);\n"

      f << "\n#ifdef __cplusplus\n}\n#endif\n\n"
      f << "#endif /* __#{basename.upcase}_H__ */\n"
    end

    puts "#{basename}.h generated"
  end

  def write_header_defines(f)
    current_enum_label = nil

    @spec.enumext_elements.each do |e|
      if e.name == :enum
        f << "#endif\n\n" if current_enum_label
        current_enum_label = e.data

        if e.data =~ /VERSION_(\d+_\d+)/
          if $1.sub('_', '.').to_f > $user_core_version
            current_enum_label = nil
            next
          end
        end

        category_name = "#{@enum_prefix}#{current_enum_label}"

        f << "#ifndef #{category_name}\n"
      elsif current_enum_label
        case e.name
        when :define
          f << "#define #{@enum_prefix}%-48s %s\n" % [e.data.name, e.data.value]
        when :use
          f << "/* reuse #{@enum_prefix}#{e.data} */\n"
        when :passthru, :passend
          f << "\n" + e.data
        end
      end
    end

    f << "#endif\n\n" if current_enum_label
  end

  def write_header_function_prototypes(f)
    current_category = nil

    @spec.glspec_elements.each do |e|
      case e.name
      when :passthru, :passend
        if e.data =~ /^typedef unsigned int GLhandleARB;/
          f << "#ifdef __APPLE__\n"
          f << "typedef void *GLhandleARB;\n"
          f << "#else\n"
          f << "typedef unsigned int GLhandleARB;\n"
          f << "#endif\n"
        else
          f << e.data
        end
      when :newcategory
        current_category = e.data

        category_name = "#{@category_prefix}#{current_category}"

        f << "\n/* #{category_name} */\n"
      when :command
        command = e.data

        next if $user_excluded_extensions.include?(command.category)
        next if !command.valid?($user_core_version)

        if command.category != current_category
          category_name = "#{@category_prefix}#{command.category}"

          f << "\n/* #{category_name} */\n"

          current_category = command.category
        end

        if command.deprecated && command.deprecated.to_f <= $user_core_version
          f << "/* #{$genggl_prefix}#{@command_prefix}#{command.name} DEPRECATED by #{command.deprecated} */\n"
        else
          f << "extern #{command.return_type} (APIENTRY *#{$genggl_prefix}#{@command_prefix}#{command.name})(#{command.params.join(", ")});\n"
        end
      end
    end
  end

  def generate_source_file(basename)
    File.open("#{basename}.c", "w") do |f|
      write_license_comment(f, "#{basename}.c")

      f << "\n#include \"#{basename}.h\"\n"
      f << "#include <string.h>\n\n"
      f << "extern void CheckGLError(const char *msg);\n"

      if $user_core_version < 3.1
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

    puts "#{basename}.c generated"
  end

  def write_source_gl_functions(f)
    current_category = nil

    @spec.command_array.each do |command|
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)

      f << "\n/* #{@category_prefix}#{command.category} */\n" if command.category != current_category
      current_category = command.category

      func_name = @command_prefix + command.name

      if command.deprecated && command.deprecated.to_f <= $user_core_version
        f << "/* #{$genggl_prefix}#{func_name} DEPRECATED by #{command.deprecated} */\n"
      else
        # ggl function pointer
        f << "typedef #{command.return_type} (APIENTRY *PFN#{func_name.upcase})(#{command.params.join(", ")});\n"
        f << "PFN#{func_name.upcase} #{$genggl_prefix}#{func_name};\n"
        f << "static PFN#{func_name.upcase} _#{func_name};\n"
        call_name = "_" + func_name

        # debug ggl function
        f << "static #{command.return_type} APIENTRY d_#{func_name}(#{command.params.join(", ")}) {\n"

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

        # glBegin/glEnd deprecated in version 3.1
        if $user_core_version < 3.1
          if func_name == "glBegin"
            f << "\t_#{$genggl_prefix}glBeginStarted++;\n"
          elsif func_name == "glEnd"
            f << "\t_#{$genggl_prefix}glBeginStarted--;\n"
          end

          f << "\tif (!_#{$genggl_prefix}glBeginStarted) { CheckGLError(\"#{func_name}\"); }\n"
        else
          f << "\tCheckGLError(\"#{func_name}\");\n"
        end

        f << "\treturn ret;\n" if command.return_type.casecmp("void") != 0
        f << "}\n"
      end
    end
  end

  def write_source_func_init(basename, f)
    if @category_prefix == "WGL_" || $user_core_version < 3.1
      f << "static const char *#{basename}ext_str = NULL;\n"
    else
      f << "static GLint #{basename}ext_count = 0;\n"
    end

    f << "\nstatic int #{basename}_check_extension(const char *ext) {\n"

    if @category_prefix == "WGL_" || $user_core_version < 3.1
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

    if @category_prefix == "WGL_"
      f << "\nvoid #{basename}_init(HDC hdc, int enableDebug) {\n"
    else
      f << "\nvoid #{basename}_init(int enableDebug) {\n"
    end

    current_category = nil
    temp_commands = []

    print_temp_commands = lambda do
      f << "\t/* #{@category_prefix}#{temp_commands[0].category} */\n"

      if temp_commands[0].core? && temp_commands[0].core_version == 1.0
        temp_commands.each do |c|
          func_name = @command_prefix + c.name
          f << "\t_#{func_name} = #{@command_prefix}#{c.name};\n"
        end
      elsif temp_commands[0].valid?($user_core_version)
        temp_commands.each do |c|
          func_name = @command_prefix + c.name
          f << "\t_#{func_name} = (PFN#{func_name.upcase})GPA(#{func_name});\n"
        end
      end
    end

    # commands in command_array is already sorted by spec file source
    @spec.command_array.each do |command|
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)
      next if command.deprecated && command.deprecated.to_f <= $user_core_version

      if command.category != current_category
        print_temp_commands.call if !temp_commands.empty?
        temp_commands.clear
      end

      temp_commands << command
      current_category = command.category
    end

    print_temp_commands.call if !temp_commands.empty?

    f << "\t#{basename}_rebind(enableDebug);\n"
    f << "\n"

    if @category_prefix == "WGL_"
      f << "\t#{basename}ext_str = (const char *)_wglGetExtensionsStringARB(hdc);\n"
    elsif $user_core_version < 3.1
      f << "\t#{basename}ext_str = (const char *)_glGetString(GL_EXTENSIONS);\n"
    else
      f << "\t_glGetIntegerv(GL_NUM_EXTENSIONS, &#{basename}ext_count);\n"
    end

    f << "\tmemset(&#{basename}ext, 0, sizeof(#{basename}ext));\n"

    @spec.categories.sort.each do |category_name|
      next if category_name !~ /^(#{@spec.extension_group_names.join('|')})_/
      f << "\tif (#{basename}_check_extension(\"#{@category_prefix}#{category_name}\")) #{basename}ext._#{@category_prefix}#{category_name} = 1;\n"
    end

    f << "}\n\n"
  end

  def write_source_func_rebind(basename, f)
    f << "void #{basename}_rebind(int enableDebug) {\n"
    f << "\tif (!enableDebug) {\n"

    @spec.command_array.each do |command|
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)
      next if command.deprecated && command.deprecated.to_f <= $user_core_version

      func_name = @command_prefix + command.name
      f << "\t\t#{$genggl_prefix}#{func_name} = _#{func_name};\n"
    end

    f << "\t}\n"
    f << "\telse {\n"

    @spec.command_array.each do |command|
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)
      next if command.deprecated && command.deprecated.to_f <= $user_core_version

      func_name = @command_prefix + command.name
      f << "\t\t#{$genggl_prefix}#{func_name} = d_#{func_name};\n"
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

valid_core_version_numbers = [1.1, 1.2, 1.3, 1.4, 1.5, 2.0, 2.1, 3.0, 3.1, 3.2, 3.3, 4.0, 4.1, 4.2, 4.3]

if ARGV[0] == "--help"
  puts "Usage: genggl <core-version>"
  puts "core-version: one of the #{valid_core_version_numbers.join(", ")} (if not specified default is 1.1)"
  exit
end

$user_core_version = (ARGV[0] || "1.1").to_f
if !(valid_core_version_numbers.include?($user_core_version))
  puts "invalid core version #{$user_core_version}"
  exit
end

$user_excluded_extensions = []
if File.exist?("excluded_extensions.txt")
  $user_excluded_extensions = IO.readlines("excluded_extensions.txt").map { |x| x.strip }.uniq
end

puts "GenGGL Version: #{$genggl_version_string}"
puts "trying to generate GGL based on core version #{$user_core_version}"

#-------------------------------------------------------------------------------

#registry_url = "http://www.opengl.org/registry/api"
registry_url = "https://cvs.khronos.org/svn/repos/ogl/trunk/doc/registry/public/oldspecs"

spec = GLSpec.new(
  :typemap => "#{registry_url}/gl.tm",
  :enumext => "#{registry_url}/enumext.spec",
  :glspec  => "#{registry_url}/gl.spec"
)

gen = GGLGenerator.new(spec, "GL_", "gl", "GL_")

# we'll ignore this function
gen.spec.del_command("StencilMaskSeparate")

=begin
[ "FramebufferTextureARB",
  "VertexAttribDivisorARB",
  "GetBufferParameterivARB",
  "GetConvolutionFilterEXT",
  "GetConvolutionParameterfvEXT",
  "GetConvolutionParameterivEXT",
  "GetSeparableFilterEXT",
  "GetHistogramEXT",
  "GetHistogramParameterfvEXT",
  "GetHistogramParameterivEXT",
  "GetMinmaxParameterivEXT",
  "GetMinmaxEXT",
  "GetMinmaxParameterfvEXT",
  "GetMinmaxParameterfiEXT",
  "AreTexturesResidentEXT",
  "BindTextureEXT",
  "DeleteTexturesEXT",
  "GenTexturesEXT",
  "IsTextureEXT",
  "GetColorTableSGI",
  "GetColorTableParameterfvSGI",
  "GetColorTableParameterivSGI"].each do |x|
  if command = spec.find_command(x)
    command.alias = x.sub(/(#{gen.spec.extension_group_names.join('|')})$/, '')
    gen.spec.find_command(command.alias).original = command
  end
end
=end

gen.generate_header_and_source_file("#{$genggl_prefix}gl")

spec = GLSpec.new(
  :typemap => "#{registry_url}/glx.tm",
  :enumext => "#{registry_url}/glxenumext.spec",
  :glspec  => "#{registry_url}/glxext.spec"
)

gen = GGLGenerator.new(spec, "GLX_", "glX", "GLX_")
gen.generate_header_and_source_file("#{$genggl_prefix}glx")

spec = GLSpec.new(
  :typemap => "#{registry_url}/wgl.tm",
  :enumext => "#{registry_url}/wglenumext.spec",
  :glspec  => "#{registry_url}/wglext.spec"
)

gen = GGLGenerator.new(spec, "", "wgl", "WGL_")
gen.generate_header_and_source_file("#{$genggl_prefix}wgl")
