#----------------------------------------------------------------------------------------------
#
# glgen.rb
# GLgen (OpenGL C glue code generator)
# Version: 0.1.0
#
# Copyright 2011 Ju Hyung Lee. All rights reserved.
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

$glgen_version_string = "0.1.0"
$glgen_prefix = "g"

#
# there are 4 different cases for binding way of the OpenGL function
#
#   case 1: systemCore -> userCore
#   case 2: systemExtension -> userCore
#   case 3: systemCore -> userExtension 
#   case 4: systemExtension -> userExtension
#

#require 'profile'
require 'rbconfig'
require './glspec.rb'

include Config

class GLGenerator
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
 * #{$glgen_prefix}gl (OpenGL glue code library)
 * Version: 0.1.0
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
        f << "#include <gl/gl.h>\n"
        f << "#include <gl/glu.h>\n\n"
        f << "#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)\n\n"
        f << "#define GL_GLEXT_LEGACY\n"
        f << "#include <OpenGL/CGLTypes.h>\n"
        f << "#include <OpenGL/gl.h>\n"
        f << "#include <OpenGL/glu.h>\n\n"
        f << "#elif defined(__linux__)\n\n"
        f << "#include <gl/gl.h>\n"
        f << "#include <gl/glu.h>\n\n"
        f << "#endif\n\n"
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
      
      f << "} #{basename}caps_t;\n\n";
      
      f << "extern #{basename}caps_t #{basename}caps;\n\n"
      
      f << "extern void #{basename}_init();\n"
      f << "extern void #{basename}_bind(int enableDebug);\n"

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
          v = e.data.sub('_', '.').to_f
          if v <= 1.1 || v > $user_core_version
            current_enum_label = nil
            next
          end
        end

        f << "#ifndef #{@enum_prefix}#{current_enum_label}\n"
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
    
    f << "#endif\n\n"
  end
  
  def write_header_function_prototypes(f)
    current_category = nil
    
    @spec.glspec_elements.each do |e|
      case e.name
      when :passthru, :passend
        f << e.data
      when :newcategory
        f << "\n/* #{@category_prefix}#{e.data} */\n"
        current_category = e.data
      when :command
        command = e.data
        
        next if $user_excluded_extensions.include?(command.category)
        next if !command.valid?($user_core_version)
       
        f << "\n/* #{@category_prefix}#{command.category} */\n" if command.category != current_category
        current_category = command.category

        if command.deprecated && command.deprecated.to_f <= $user_core_version
          f << "/* #{$glgen_prefix}#{@command_prefix}#{command.name} DEPRECATED by #{command.deprecated} */\n"
        else
          f << "extern #{command.return_type} (*#{$glgen_prefix}#{@command_prefix}#{command.name})(#{command.params.join(", ")});\n"
        end
      else
      end
    end
  end

  def generate_source_file(basename)
    File.open("#{basename}.c", "w") do |f|
      write_license_comment(f, "#{basename}.c")
      
      f << "\n#include \"#{basename}.h\"\n"
      f << "#include <string.h>\n\n"
      f << "extern void CheckGLError(const char *msg);\n"
      f << "static int _#{$glgen_prefix}glBeginStarted = 0;\n"

      write_source_gl_functions(f)
      write_source_fake_functions(f)
      
      f << "\n#ifdef _WIN32\n"
      f << "#define GPA(a) wglGetProcAddress(\#a)\n"
      f << "#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)\n"
      f << "#define GPA(a) mglGetProcAddress(\#a)\n"
      f << "extern void *mglGetProcAddress(const char *name);\n"
      f << "#elif defined(__linux__)\n"
      f << "#define GPA(a) glXGetProcAddressARB((const GLubyte *)\#a)\n"
      f << "#endif\n\n"
      
      f << "#{basename}caps_t #{basename}caps;\n"
      
      write_source_func_init(basename, f)
      write_source_func_bind(basename, f)
    end

    puts "#{basename}.c generated"
  end
  
  def write_source_gl_functions(f)
    current_category = nil
    
    @spec.command_array.each do |command|
      next if command.name =~ /^__/
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)
      
      f << "\n/* #{@category_prefix}#{command.category} */\n" if command.category != current_category
      current_category = command.category
      
      func_name = @command_prefix + command.name
      
      if command.deprecated && command.deprecated.to_f <= $user_core_version
        f << "/* #{$glgen_prefix}#{func_name} DEPRECATED by #{command.deprecated} */\n"
      else        
        if command.core? && command.core_version <= 1.1                  
          f << "#{command.return_type} (*#{$glgen_prefix}#{func_name})(#{command.params.join(", ")});\n"
          call_name = func_name
        else
          f << "typedef #{command.return_type} (*PFN#{func_name.upcase})(#{command.params.join(", ")});\n"          
          f << "PFN#{func_name.upcase} #{$glgen_prefix}#{func_name};\n"
          f << "static PFN#{func_name.upcase} _#{func_name};\n"
          call_name = "_" + func_name
        end
        
        f << "static inline #{command.return_type} d_#{func_name}(#{command.params.join(", ")}) {\n"

        if command.return_type == "void"
          f << "\t#{call_name}("
        else
          f << "\t#{command.return_type} ret = #{call_name}("
        end

        command.params.each_index do |i|
          f << ", " if i > 0
          f << command.params[i].name
        end

        f << ");\n"
        
        if func_name == "glBegin"
          f << "\t_#{$glgen_prefix}glBeginStarted++;\n"
        elsif func_name == "glEnd"
          f << "\t_#{$glgen_prefix}glBeginStarted--;\n"
        end

        f << "\tif (!_#{$glgen_prefix}glBeginStarted) { CheckGLError(\"#{func_name}\"); }\n"
        f << "\treturn ret;\n" if command.return_type != "void"
        f << "}\n"
      end
    end
  end
  
  def write_source_fake_functions(f)
    if @category_prefix == "GL_"
      f << "\n#ifdef GL_VERSION_2_0\n"
         
      f << "void gl__DeleteObject(GLhandleARB obj) {\n"
      f << "\tif (glIsShader(obj)) { glDeleteShader(obj); }\n"
      f << "\telse { glDeleteProgram(obj); }\n"
      f << "}\n"
    
      f << "void gl__GetObjectParameteriv(GLuint obj, GLenum pname, GLint* params) {\n"
      f << "\tif (glIsShader(obj)) { glGetShaderiv(obj, pname, params); }\n"
      f << "\telse { glGetProgramiv(obj, pname, params); }\n"
      f << "}\n"
    
      f << "void gl__GetInfoLog(GLuint obj, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {\n"
      f << "\tif (glIsShader(obj)) { glGetShaderInfoLog(obj, bufSize, length, infoLog); }\n"
      f << "\telse { glGetProgramInfoLog(obj, bufSize, length, infoLog); }\n"
      f << "}\n"
    
      f << "#else\n"
    
      f << "void gl__DeleteProgramARB(GLhandleARB program) {\n"
      f << "\tglDeleteObjctARB(program);\n"
      f << "}\n"
    
      f << "void gl__DeleteShaderARB(GLhandleARB shader) {\n"
      f << "\tglDeleteObjectARB(shader);\n"
      f << "}\n"
    
      f << "void gl__GetProgramivARB(GLuint program, GLenum pname, GLint* params) {\n"
      f << "\tglGetObjectParameterivARB(program, pname, params);\n"
      f << "}\n"
    
      f << "void gl__GetShaderivARB(GLuint shader, GLenum pname, GLint* params) {\n"
      f << "\tglGetObjectParameterivARB(shader, pname, params);\n"
      f << "}\n"
    
      f << "void gl__GetProgramInfoLogARB(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {\n"
      f << "\tglGetInfoLogARB(program, bufSize, length, infoLog);\n"
      f << "}\n"
    
      f << "void gl__GetShaderInfoLogARB(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {\n"
      f << "\tglGetInfoLogARB(shader, bufSize, length, infoLog);\n"
      f << "}\n"
    
      f << "#endif\n"
    end
  end
  
  def write_source_func_init(basename, f)
    f << "\nvoid #{basename}_init()\n{\n"
    
    f << "\tconst char *extensionString = (const char *)glGetString(GL_EXTENSIONS);\n"
    f << "\tmemset(&#{basename}caps, 0, sizeof(#{basename}caps));\n"
    
    @spec.categories.sort.each do |category_name|
      next if category_name !~ /^(#{@spec.extension_group_names.join('|')})_/
      f << "\tif (strstr(extensionString, \"#{@category_prefix}#{category_name}\")) #{basename}caps._#{@category_prefix}#{category_name} = 1;\n"
    end

    current_category = nil
    temp_commands = []
    
    print_temp_commands = lambda do
      f << "\n\t/* #{@category_prefix}#{temp_commands[0].category} */\n"
      
      if temp_commands[0].core? && temp_commands[0].core_version > 1.1
        f << "#ifdef #{@category_prefix}VERSION_#{temp_commands[0].core_version.to_s.sub('.', '_')}\n"
        
        temp_commands.each do |c| 
          func_name = @command_prefix + c.name
          f << "\t_#{func_name} = #{@command_prefix}#{c.name};\n"
        end
        
        f << "#else\n"
       
        temp_commands.each do |c|
          func_name = @command_prefix + c.name
          if c.original
            if c.original.name =~ /^__/
              f << "\t_#{func_name} = #{@command_prefix}#{c.original.name};\n"
            else
              f << "\t_#{func_name} = (PFN#{func_name.upcase})GPA(#{@command_prefix}#{c.original.name});\n"
            end
          else
            puts "WARNING: missing original command #{c.name}"
          end
        end
        
        f << "#endif\n"
      elsif temp_commands[0].extension?          
        current_alias_category = nil
        temp_extension_commands = []
        
        print_temp_extension_commands = lambda do
          if (a_command = temp_extension_commands[0].aliased) && a_command.core?
            f << "#ifndef #{@category_prefix}VERSION_#{a_command.core_version.to_s.sub('.', '_')}\n"
            
            temp_extension_commands.each do |c|
              if (a_command = c.aliased)
                func_name = @command_prefix + c.name
                f << "\t_#{func_name} = (PFN#{func_name.upcase})GPA(#{func_name});\n"
              end
            end              
          
            f << "#else\n"
          
            temp_extension_commands.each do |c|
              if (a_command = c.aliased)
                func_name = @command_prefix + c.name
                f << "\t_#{func_name} = #{@command_prefix}#{a_command.name};\n"
              end
            end
          
            f << "#endif\n"
          else            
            temp_extension_commands.each do |c|
             func_name = @command_prefix + c.name
             f << "\t_#{func_name} = (PFN#{func_name.upcase})GPA(#{func_name});\n"
            end
          end
        end # lambda
        
        # sorted by aliased command category
        temp_commands.sort_by { |c| (a_command = c.aliased) ? a_command.category : "" }.each do |c|
          if current_alias_category != ((a_command = c.aliased) ? a_command.category : "")
            print_temp_extension_commands.call if !temp_extension_commands.empty?
            temp_extension_commands.clear
          end
          
          temp_extension_commands << c
          current_alias_category = ((a_command = c.aliased) ? a_command.category : "")
        end
        
        print_temp_extension_commands.call if !temp_extension_commands.empty?                
      elsif temp_commands[0].core_extension?
        temp_commands.each do |c|
          func_name = @command_prefix + c.name
          f << "\t_#{func_name} = (PFN#{func_name.upcase})GPA(#{func_name});\n"
        end
      end
    end # lambda

    @spec.command_array.each do |command|
      next if command.name =~ /^__/
      next if command.core? && command.core_version <= 1.1
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)
      
      if command.category != current_category
        print_temp_commands.call if !temp_commands.empty?
        temp_commands.clear
      end
      
      temp_commands << command
      current_category = command.category
    end
    
    print_temp_commands.call if !temp_commands.empty?    

    f << "}\n\n"
  end
  
  def write_source_func_bind(basename, f)
    f << "void #{basename}_bind(int enableDebug)\n{\n"
    f << "\tif (!enableDebug) {\n"
    
    @spec.command_array.each do |command|
      next if command.name =~ /^__/
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)

      func_name = @command_prefix + command.name
      f << "\t\t#{$glgen_prefix}#{func_name} = %s#{func_name};\n" % (command.core? && command.core_version <= 1.1 ? "" : "_")
    end
    
    f << "\t}\n"
    f << "\telse {\n"
    
    @spec.command_array.each do |command|
      next if command.name =~ /^__/
      next if $user_excluded_extensions.include?(command.category)
      next if !command.valid?($user_core_version)
      
      func_name = @command_prefix + command.name   
      f << "\t\t#{$glgen_prefix}#{func_name} = d_#{func_name};\n"
    end
    
    f << "\t}\n"
    f << "}\n"
  end
end

#-------------------------------------------------------------------------------

def get_os_type
  case CONFIG['host_os']
  when /mswin|windows/i then 'windows'
  when /linux/i then 'linux'
  when /darwin/i then 'macosx'
  else; nil; end
end

#-------------------------------------------------------------------------------

valid_core_version_numbers = [1.1, 1.2, 1.3, 1.4, 1.5, 2.0, 2.1, 3.0, 3.1, 3.2, 3.3, 4.0, 4.1, 4.2, 4.3]

if ARGV[0] == "--help"
  puts "Usage: glgen <core-version>"
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

puts "GLGen Version: #{$glgen_version_string}"
puts "trying to generate OpenGL glue code based on OpenGL version #{$user_core_version}"

#-------------------------------------------------------------------------------

spec = GLSpec.new(
  :typemap => "http://www.opengl.org/registry/api/gl.tm",
  :enumext => "http://www.opengl.org/registry/api/enumext.spec",
  :glspec  => "http://www.opengl.org/registry/api/gl.spec"
)

gen = GLGenerator.new(spec, "GL_", "gl", "GL_")

# we'll ignore this function
gen.spec.del_command("StencilMaskSeparate")

# add fake functions to make all them happy
add_arb_shader_command = lambda do | command_name, o_command_name |
  o_command = gen.spec.find_command(o_command_name)
  command = gen.spec.new_command(command_name)      
  command.category = "ARB_shader_objects"
  command.alias = o_command.name
  command.return_type = o_command.return_type
  command.params = o_command.params
  gen.spec.find_command(command.alias).original = command
end

add_arb_shader_command.call("__DeleteProgramARB", "DeleteProgram")
add_arb_shader_command.call("__DeleteShaderARB", "DeleteShader")
add_arb_shader_command.call("__GetProgramivARB", "GetProgramiv")
add_arb_shader_command.call("__GetShaderivARB", "GetShaderiv")
add_arb_shader_command.call("__GetProgramInfoLogARB", "GetProgramInfoLog")
add_arb_shader_command.call("__GetShaderInfoLogARB", "GetShaderInfoLog")
add_arb_shader_command.call("__IsShaderARB", "IsShader")

add_core_shader_command = lambda do | command_name, o_command_name |
  o_command = gen.spec.find_command(o_command_name)
  command = gen.spec.new_command(command_name)      
  command.category = "VERSION_2_0"
  command.return_type = o_command.return_type
  command.params = o_command.params
  command.original = gen.spec.find_command(o_command_name)
  o_command.alias = command_name
end

add_core_shader_command.call("__DeleteObject", "DeleteObjectARB")    
add_core_shader_command.call("__GetObjectParameteriv", "GetObjectParameterivARB")
add_core_shader_command.call("__GetInfoLog", "GetInfoLogARB")

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

gen.generate_header_and_source_file("#{$glgen_prefix}gl")

spec = GLSpec.new(
  :typemap => "http://www.opengl.org/registry/api/glx.tm",
  :enumext => "http://www.opengl.org/registry/api/glxenumext.spec",
  :glspec  => "http://www.opengl.org/registry/api/glxext.spec"
)

gen = GLGenerator.new(spec, "GLX_", "glX", "GLX_")
gen.generate_header_and_source_file("#{$glgen_prefix}glx")
  
spec = GLSpec.new(
  :typemap => "http://www.opengl.org/registry/api/wgl.tm",
  :enumext => "http://www.opengl.org/registry/api/wglenumext.spec",
  :glspec  => "http://www.opengl.org/registry/api/wglext.spec"
)

gen = GLGenerator.new(spec, "", "wgl", "WGL_")
gen.generate_header_and_source_file("#{$glgen_prefix}wgl")
