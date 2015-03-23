#----------------------------------------------------------------------------------------------
#
# old_glspec.rb
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

require 'net/http'

class GLCommandParam
  attr_reader :name, :typename, :pointer, :const
  attr_writer :name, :typename, :pointer, :const

  def to_s
    (const ? "const " : "") + typename + (pointer ? "* " : " ") + name
  end
end

class GLCommand
  attr_reader :name, :category, :vectorequiv, :alias, :original, :return_type, :params, :deprecated
  attr_writer :name, :category, :vectorequiv, :alias, :original, :return_type, :params, :deprecated

  def initialize(name, spec)
    @name = name
    @params = Array.new
    @spec = spec
  end

  def core?
    @category =~ /^VERSION_/ ? true : false
  end

  def core_version
    @category =~ /^VERSION_(\d+_\d+)/ ? $1.sub('_', '.').to_f : nil
  end

  def core_extension? # 코어화된 extension (non post-fix)
    @category !~ /^VERSION_/ && @name !~ /(#{@spec.extension_group_names.join('|')})$/ ? true : false
  end

  def extension? # 일반적인 extension
    @category !~ /^VERSION_/ && @name =~ /(#{@spec.extension_group_names.join('|')})$/ ? true : false
  end

  def valid?(version)
    return true if core? && core_version <= version
    return true if core_extension?
    return true if extension? && (!(a_command = aliased) || !a_command.core? || (a_command.core? && a_command.core_version > version))
    return false
  end

  def aliased
    alias_name = self.alias
    command = nil

    # alias might be recursive
    while alias_name do
      command = @spec.command_array.find { |x| x.name == alias_name }
      puts "WARNING: alias \"#{alias_name}\" not found" if !command
      alias_name = command.alias
    end

    return command
  end
end

class GLDefine
  attr_reader :name, :value

  def initialize(name, value)
    @name = name
    @value = value
  end
end

class GLSpecElement
  attr_reader :name, :data

  def initialize(name, data)
    @name = name
    @data = data
  end
end

class GLSpec
  attr_reader :versions, :enumext_elements, :glspec_elements, :type_hash, :categories, :extension_group_names, :command_array

  def initialize(url)
    @enumext_elements = []
    @glspec_elements = []
    @type_hash = {}
    @command_array = []
    @command_hash = {}
    @categories = []

    puts "parsing #{url[:typemap]}..."
    parse_typemap_url(url[:typemap])

    puts "parsing #{url[:enumext]}..."
    parse_enumext_url(url[:enumext])

    puts "parsing #{url[:glspec]}..."
    parse_glspec_url(url[:glspec])
  end

  def new_command(command_name)
    if !@command_hash[command_name]
      @command_array << command = GLCommand.new(command_name, self)
      @command_hash[command_name] = command
    end
  end

  def del_command(command_name)
    if command = @command_hash[command_name]
      @command_array.delete(command)
      @command_hash[command_name] = nil
    end
  end

  def find_command(command_name)
    @command_hash[command_name]
  end

  def typemap(typename)
    return "void" if typename == "void"
    @type_hash[typename]
  end

  def parse_typemap_url(url)
    parse_url_each_line(url) do |line|
      ar = line.split(',')
      @type_hash[ar[0]] = ar[3].to_s.strip
    end
  end

  def parse_enumext_url(url)
    parse_url_each_line(url) do |line|
      if line =~ /(^pass(thru|end)):/
        @enumext_elements << GLSpecElement.new($1.to_sym, line.sub(/^\w+: ?/, ''))
      elsif line =~ /(^\w+)\senum:/
        @enumext_elements << GLSpecElement.new(:enum, $1)
      elsif line =~ /^\s+(\w+)\s+\=\s+(\-?\w+)/
        @enumext_elements << GLSpecElement.new(:define, GLDefine.new($1, $2))
      elsif line =~ /^\s+use\s+\w+\s+(\w+)/
        @enumext_elements << GLSpecElement.new(:use, $1)
      end
    end
  end

  def parse_glspec_url(url)
    command = nil
    parse_url_each_line(url) do |line|
      if line =~ /^category:\s+/
        @categories.concat(line.sub(/^category:\s+/, '').split)
      elsif line =~ /(^pass(thru|end)):/
        @glspec_elements << GLSpecElement.new($1.to_sym, line.sub(/^\w+: ?/, ''))
      elsif line =~ /^newcategory:\s+(\w+)/
        @categories << $1
        @glspec_elements << GLSpecElement.new(:newcategory, $1)
      elsif line =~ /^version:\s+/
        @versions = line.sub(/^version:\s+/, '').split
      elsif line =~ /(^\w+?)\(.*\)/ # command
        @command_array << command = GLCommand.new($1, self)
        @command_hash[$1] = command
        @glspec_elements << GLSpecElement.new(:command, command)
      elsif line =~ /\s+(\w+)\s+(.*)/ # command property
        case $1
        when 'return'
          command.return_type = typemap($2)
        when 'param'
          x = $2
          puts "WARNING: unmatched \"#{x}\"" if (x =~ /(\w+)\s+(\w+)\s+/) == nil
          param_name = $1
          # prevent using C keywords
          param_name = "z#{param_name}" if param_name == "near" || param_name == "far"
          param_type = $2
          x.sub!($&, '')
          #param_type.sub!(/\w+\b/, "PixelInternalFormat") if command.name =~ /^TexImage(1|2|3)D/ && param_name == "internalformat"
          puts "WARNING: unmatched \"#{x}\"" if (x =~ /(in|out)\s+(value|reference|array)/) == nil

          param = GLCommandParam.new
          param.name = param_name
          param.typename = typemap(param_type)
          if $2 == "reference" || $2 == "array"
            param.pointer = true
            param.const = true if $1 == "in"
          end
          command.params << param
        when 'category'
          command.category = $2
        when 'deprecated'
          command.deprecated = $2
        when 'vectorequiv'
          command.vectorequiv = $2
        when 'alias'
          command.alias = $2
          command.alias << 's' if command.alias == 'GenVertexArray' # 's' is omitted in spec file
        end
      end
    end

    # EXT_texture_compression_s3tc is omitted in spec file
    @categories << "EXT_texture_compression_s3tc"

    @categories.uniq!.sort!
    @extension_group_names = @categories.grep(/(^[A-Z0-9]+?)_/) { |x| $1 }.reject { |x| x =~ /^VERSION/ }.uniq

    @command_array.each do |command|
      if command.alias
        @command_hash[command.alias].original = command
      elsif !command.core? && command.vectorequiv
        ve_command = @command_hash[command.vectorequiv]
        if ve_command.core?
          command.alias = command.vectorequiv.chop
          @command_hash[command.alias].original = command
        end
      end
    end
  end

  def parse_url_each_line(url)
    Net::HTTP.get_response(URI.parse(url)) do |resp|
      resp.body.each_line do |line|
        if line !~ /^pass(thru|end):/
          line.sub!(/#.*/, '')
          line.rstrip!
        end
        yield line
      end
    end
  end
end
