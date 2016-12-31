#----------------------------------------------------------------------------------------------
#
# glspec.rb
# GenGGL (OpenGL extension glue code generator in C)
# Version: 0.3.3
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

require 'open-uri'
require 'nokogiri'

class GLBase
  attr_reader :required, :reused
  attr_writer :required, :reused

  def initialize
    @required = false
    @reused = false
  end
end

class GLType < GLBase
  attr_reader :name, :api, :content
  attr_writer :content

  def initialize(name, api)
    super()
    @name = name
    @api = api
  end
end

class GLGroup < GLBase
  attr_reader :name, :enums

  def initialize(name)
    super()
    @name = name
    @nums = []
  end
end

class GLEnum < GLBase
  attr_reader :name, :value, :alias_name

  def initialize(name, value, alias_name)
    super()
    @name = name
    @value = value
    @alias_name = alias_name
    @reused = false
  end
end

class GLCommandParam
  attr_reader :name, :content, :group_name

  def initialize(name, content, group_name)
    @name = name
    @content = content
    @group_name = group_name
  end

  def to_s
    @content
  end
end

class GLCommand < GLBase
  attr_reader :name, :return_type, :alias_name, :params
  attr_writer :alias_name, :params

  def initialize(name, return_type)
    super()
    @return_type = return_type
    @name = name
    @params = []
  end
end

class GLFeature
  attr_reader :name, :api, :version, :enums, :types, :commands
  attr_writer :enums, :types, :commands

  def initialize(name, api, version)
    @name = name
    @api = api
    @version = version
    @enums = []
    @types = []
    @commands = []
  end
end

class GLExtension
  attr_reader :name, :enums, :types, :commands
  attr_writer :enums, :types, :commands

  def initialize(name)
    @name = name
    @enums = []
    @types = []
    @commands = []
  end
end

class GLSpec
  attr_reader :api, :profile, :version, :types, :groups, :enums, :commands, :features, :extensions

  def initialize(config)
    @api = config[:api]
    @profile = config[:profile]
    @version = config[:version]
    @types = []
    @groups = []
    @enums = []
    @commands = []
    @features = []
    @extensions = []

    parse_xml(config[:url])
  end

  def match_api_profile(api, profile)
    if (api)
      return @api == api
    end

    if (profile && @profile != 'common')
      return @profile == profile
    end

    return true
  end

  def parse_xml(url)
    puts "parsing #{url}..."
    doc = Nokogiri::XML(open(url))

    parse_types(doc)
    parse_groups(doc)
    parse_enums(doc)
    parse_commands(doc)
    parse_features(doc)
    parse_extensions(doc)

    # remove #include <KHR/khrplatform.h> by hand
    @types.delete_if { |x| x.name == 'khrplatform' }
  end

  def parse_types(doc)
    doc.xpath("registry/types/type").each do |type_tag|
      type_name = type_tag['name']
      if !type_name
        type_name = type_tag.at('name').content
      end

      type_api = type_tag['api']
      type_requires = type_tag['requires']

      next if @profile != 'common' && type_name == 'khrplatform'
      next if type_requires && !@types.find { |x| x.name == type_requires }
      next if !match_api_profile(type_api, nil)

      type = @types.find { |x| x.name == type_name }
      if !type
        @types << type = GLType.new(type_name, type_api)
      end

      apientry_displaced = type_tag.to_s.sub(/<apientry\/>/, 'APIENTRY')
      newdoc = Nokogiri::XML(apientry_displaced)
      type.content = newdoc.at('type').content
    end
  end

  def parse_groups(doc)
    doc.xpath("registry/groups/group").each do |group_tag|
      @groups << group = GLGroup.new(group_tag['name'])

      group_tag.xpath("/enum").each do |enum_tag|
        group.enum_names << enum_tag['name']
      end
    end
  end

  def parse_enums(doc)
    doc.xpath("registry/enums/enum").each do |enum_tag|
      enum_name = enum_tag['name']
      enum_value = enum_tag['value']
      enum_alias = enum_tag['alias']
      @enums << enum = GLEnum.new(enum_name, enum_value, enum_alias)
    end
  end

  def parse_commands(doc)
    doc.xpath("registry/commands/command").each do |command_tag|
      proto_tag = command_tag.at('proto')
      name_stripped = proto_tag.to_s.sub(/<name[^>]*>.*?<\/name>/, '')
      newdoc = Nokogiri::XML(name_stripped)

      command_return_type = newdoc.content.strip
      command_name = proto_tag.at('name').content

      @commands << command = GLCommand.new(command_name, command_return_type)

      command_tag.xpath("param").each do |param_tag|
        param_group_name = param_tag['group']
        param_name = param_tag.at('name').content
        param_content = param_tag.content

        if param_name == 'near' || param_name == 'far'
          param_name = 'z' + param_name
          param_content.sub!(/\bnear\b/, 'znear')
          param_content.sub!(/\bfar\b/, 'zfar')
        end

        param = GLCommandParam.new(param_name, param_content, param_group_name)
        command.params << param
      end

      alias_tag = command_tag.at('alias')
      if (alias_tag)
        command.alias_name = alias_tag['name']
      end
    end
  end

  def parse_features(doc)
    doc.xpath("registry/feature").each do |feature_tag|
      feature_api = feature_tag['api']
      feature_name = feature_tag['name']
      feature_version = feature_tag['number'].to_f

      next if !match_api_profile(feature_api, nil)
      next if feature_version > @version

      @features << feature = GLFeature.new(feature_name, feature_api, feature_version)

      feature_tag.xpath("require").each do |require_tag|
        require_profile = require_tag['profile']
        require_comment = require_tag['comment']

        next if !match_api_profile(nil, require_profile)

        require_tag.xpath("enum").each do |enum_tag|
          enum_name = enum_tag['name']
          enum = @enums.find { |x| x.name == enum_name }
          enum.required = true
          feature.enums << enum if !feature.enums.find { |x| x.name == enum_name }
        end

        require_tag.xpath("command").each do |command_tag|
          command_name = command_tag['name']
          command = @commands.find { |x| x.name == command_name }
          command.required = true
          feature.commands << command if !feature.commands.find { |x| x.name == command_name }
        end
      end

      feature_tag.xpath("remove").each do |remove_tag|
        remove_profile = remove_tag['profile']
        remove_comment = remove_tag['comment']

        next if !match_api_profile(nil, remove_profile)

        remove_tag.xpath("enum").each do |enum_tag|
          enum_name = enum_tag['name']
          enum = @enums.find { |x| x.name == enum_name }
          enum.required = false
        end

        remove_tag.xpath("command").each do |command_tag|
          command_name = command_tag['name']
          command = @commands.find { |x| x.name == command_name }
          command.required = false
        end
      end
    end
  end

  def parse_extensions(doc)
    doc.xpath("registry/extensions/extension").each do |extension_tag|
      extension_name = extension_tag['name']
      extension_supported = extension_tag['supported']

      supported_array = extension_supported.split('|')
      next if !supported_array.include?(@api)

      # Skip if extension is not supported by core profile
      #supported_glcore = supported_array.find { |x| x == 'glcore' }
      #next if @profile == 'core' && !supported_glcore

      @extensions << extension = GLExtension.new(extension_name)

      extension_tag.xpath("require").each do |require_tag|
        require_api = require_tag['api']
        require_comment = require_tag['comment']

        next if !match_api_profile(require_api, nil)

        require_tag.xpath("enum").each do |enum_tag|
          enum_name = enum_tag['name']
          enum = @enums.find { |x| x.name == enum_name }
          if enum.required
            enum = enum.clone
            enum.reused = true
          end
          enum.required = true
          extension.enums << enum
        end

        require_tag.xpath("command").each do |command_tag|
          command_name = command_tag['name']
          command = @commands.find { |x| x.name == command_name }
          if command.required
            command = command.clone
            command.reused = true
          end
          command.required = true
          extension.commands << command
        end
      end
    end
  end
end
