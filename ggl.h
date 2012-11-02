/*********************************************************************************************
 *
 * ggl.h
 * ggl (OpenGL glue code library)
 * Version: 0.1.1
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

#ifndef __GGL_H__
#define __GGL_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)

#define GL_GLEXT_LEGACY
#include <OpenGL/CGLTypes.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#elif defined(__linux__)

#include <gl/gl.h>
#include <gl/glu.h>

#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef GL_ARB_imaging
#define GL_CONSTANT_COLOR                                   0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR                         0x8002
#define GL_CONSTANT_ALPHA                                   0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA                         0x8004
#define GL_BLEND_COLOR                                      0x8005
#define GL_FUNC_ADD                                         0x8006
#define GL_MIN                                              0x8007
#define GL_MAX                                              0x8008
#define GL_BLEND_EQUATION                                   0x8009
#define GL_FUNC_SUBTRACT                                    0x800A
#define GL_FUNC_REVERSE_SUBTRACT                            0x800B
#define GL_CONVOLUTION_1D                                   0x8010
#define GL_CONVOLUTION_2D                                   0x8011
#define GL_SEPARABLE_2D                                     0x8012
#define GL_CONVOLUTION_BORDER_MODE                          0x8013
#define GL_CONVOLUTION_FILTER_SCALE                         0x8014
#define GL_CONVOLUTION_FILTER_BIAS                          0x8015
#define GL_REDUCE                                           0x8016
#define GL_CONVOLUTION_FORMAT                               0x8017
#define GL_CONVOLUTION_WIDTH                                0x8018
#define GL_CONVOLUTION_HEIGHT                               0x8019
#define GL_MAX_CONVOLUTION_WIDTH                            0x801A
#define GL_MAX_CONVOLUTION_HEIGHT                           0x801B
#define GL_POST_CONVOLUTION_RED_SCALE                       0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE                     0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE                      0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE                     0x801F
#define GL_POST_CONVOLUTION_RED_BIAS                        0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS                      0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS                       0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS                      0x8023
#define GL_HISTOGRAM                                        0x8024
#define GL_PROXY_HISTOGRAM                                  0x8025
#define GL_HISTOGRAM_WIDTH                                  0x8026
#define GL_HISTOGRAM_FORMAT                                 0x8027
#define GL_HISTOGRAM_RED_SIZE                               0x8028
#define GL_HISTOGRAM_GREEN_SIZE                             0x8029
#define GL_HISTOGRAM_BLUE_SIZE                              0x802A
#define GL_HISTOGRAM_ALPHA_SIZE                             0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE                         0x802C
#define GL_HISTOGRAM_SINK                                   0x802D
#define GL_MINMAX                                           0x802E
#define GL_MINMAX_FORMAT                                    0x802F
#define GL_MINMAX_SINK                                      0x8030
#define GL_TABLE_TOO_LARGE                                  0x8031
#define GL_COLOR_MATRIX                                     0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH                         0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH                     0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE                      0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE                    0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE                     0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE                    0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS                       0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS                     0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS                      0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS                     0x80BB
#define GL_COLOR_TABLE                                      0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE                     0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE                    0x80D2
#define GL_PROXY_COLOR_TABLE                                0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE               0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE              0x80D5
#define GL_COLOR_TABLE_SCALE                                0x80D6
#define GL_COLOR_TABLE_BIAS                                 0x80D7
#define GL_COLOR_TABLE_FORMAT                               0x80D8
#define GL_COLOR_TABLE_WIDTH                                0x80D9
#define GL_COLOR_TABLE_RED_SIZE                             0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE                           0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE                            0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE                           0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE                       0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE                       0x80DF
#define GL_CONSTANT_BORDER                                  0x8151
#define GL_REPLICATE_BORDER                                 0x8153
#define GL_CONVOLUTION_BORDER_COLOR                         0x8154
#endif

#ifndef GL_ARB_multitexture
#define GL_TEXTURE0_ARB                                     0x84C0
#define GL_TEXTURE1_ARB                                     0x84C1
#define GL_TEXTURE2_ARB                                     0x84C2
#define GL_TEXTURE3_ARB                                     0x84C3
#define GL_TEXTURE4_ARB                                     0x84C4
#define GL_TEXTURE5_ARB                                     0x84C5
#define GL_TEXTURE6_ARB                                     0x84C6
#define GL_TEXTURE7_ARB                                     0x84C7
#define GL_TEXTURE8_ARB                                     0x84C8
#define GL_TEXTURE9_ARB                                     0x84C9
#define GL_TEXTURE10_ARB                                    0x84CA
#define GL_TEXTURE11_ARB                                    0x84CB
#define GL_TEXTURE12_ARB                                    0x84CC
#define GL_TEXTURE13_ARB                                    0x84CD
#define GL_TEXTURE14_ARB                                    0x84CE
#define GL_TEXTURE15_ARB                                    0x84CF
#define GL_TEXTURE16_ARB                                    0x84D0
#define GL_TEXTURE17_ARB                                    0x84D1
#define GL_TEXTURE18_ARB                                    0x84D2
#define GL_TEXTURE19_ARB                                    0x84D3
#define GL_TEXTURE20_ARB                                    0x84D4
#define GL_TEXTURE21_ARB                                    0x84D5
#define GL_TEXTURE22_ARB                                    0x84D6
#define GL_TEXTURE23_ARB                                    0x84D7
#define GL_TEXTURE24_ARB                                    0x84D8
#define GL_TEXTURE25_ARB                                    0x84D9
#define GL_TEXTURE26_ARB                                    0x84DA
#define GL_TEXTURE27_ARB                                    0x84DB
#define GL_TEXTURE28_ARB                                    0x84DC
#define GL_TEXTURE29_ARB                                    0x84DD
#define GL_TEXTURE30_ARB                                    0x84DE
#define GL_TEXTURE31_ARB                                    0x84DF
#define GL_ACTIVE_TEXTURE_ARB                               0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB                        0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB                            0x84E2
#endif

#ifndef GL_ARB_transpose_matrix
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB                   0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB                  0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB                     0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB                       0x84E6
#endif

#ifndef GL_ARB_multisample
#define GL_MULTISAMPLE_ARB                                  0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB                     0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB                          0x809F
#define GL_SAMPLE_COVERAGE_ARB                              0x80A0
#define GL_SAMPLE_BUFFERS_ARB                               0x80A8
#define GL_SAMPLES_ARB                                      0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB                        0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB                       0x80AB
#define GL_MULTISAMPLE_BIT_ARB                              0x20000000
#endif

#ifndef GL_ARB_texture_env_add
#endif

#ifndef GL_ARB_texture_cube_map
#define GL_NORMAL_MAP_ARB                                   0x8511
#define GL_REFLECTION_MAP_ARB                               0x8512
#define GL_TEXTURE_CUBE_MAP_ARB                             0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB                     0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB                  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB                  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB                  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB                  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB                  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB                  0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB                       0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB                    0x851C
#endif

#ifndef GL_ARB_texture_compression
#define GL_COMPRESSED_ALPHA_ARB                             0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB                         0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB                   0x84EB
#define GL_COMPRESSED_INTENSITY_ARB                         0x84EC
#define GL_COMPRESSED_RGB_ARB                               0x84ED
#define GL_COMPRESSED_RGBA_ARB                              0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB                     0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB                0x86A0
#define GL_TEXTURE_COMPRESSED_ARB                           0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB               0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB                   0x86A3
#endif

#ifndef GL_ARB_texture_border_clamp
#define GL_CLAMP_TO_BORDER_ARB                              0x812D
#endif

#ifndef GL_ARB_point_parameters
#define GL_POINT_SIZE_MIN_ARB                               0x8126
#define GL_POINT_SIZE_MAX_ARB                               0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB                    0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB                   0x8129
#endif

#ifndef GL_ARB_vertex_blend
#define GL_MAX_VERTEX_UNITS_ARB                             0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB                          0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB                             0x86A6
#define GL_VERTEX_BLEND_ARB                                 0x86A7
#define GL_CURRENT_WEIGHT_ARB                               0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB                            0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB                          0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB                            0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB                         0x86AC
#define GL_WEIGHT_ARRAY_ARB                                 0x86AD
#define GL_MODELVIEW0_ARB                                   0x1700
#define GL_MODELVIEW1_ARB                                   0x850A
#define GL_MODELVIEW2_ARB                                   0x8722
#define GL_MODELVIEW3_ARB                                   0x8723
#define GL_MODELVIEW4_ARB                                   0x8724
#define GL_MODELVIEW5_ARB                                   0x8725
#define GL_MODELVIEW6_ARB                                   0x8726
#define GL_MODELVIEW7_ARB                                   0x8727
#define GL_MODELVIEW8_ARB                                   0x8728
#define GL_MODELVIEW9_ARB                                   0x8729
#define GL_MODELVIEW10_ARB                                  0x872A
#define GL_MODELVIEW11_ARB                                  0x872B
#define GL_MODELVIEW12_ARB                                  0x872C
#define GL_MODELVIEW13_ARB                                  0x872D
#define GL_MODELVIEW14_ARB                                  0x872E
#define GL_MODELVIEW15_ARB                                  0x872F
#define GL_MODELVIEW16_ARB                                  0x8730
#define GL_MODELVIEW17_ARB                                  0x8731
#define GL_MODELVIEW18_ARB                                  0x8732
#define GL_MODELVIEW19_ARB                                  0x8733
#define GL_MODELVIEW20_ARB                                  0x8734
#define GL_MODELVIEW21_ARB                                  0x8735
#define GL_MODELVIEW22_ARB                                  0x8736
#define GL_MODELVIEW23_ARB                                  0x8737
#define GL_MODELVIEW24_ARB                                  0x8738
#define GL_MODELVIEW25_ARB                                  0x8739
#define GL_MODELVIEW26_ARB                                  0x873A
#define GL_MODELVIEW27_ARB                                  0x873B
#define GL_MODELVIEW28_ARB                                  0x873C
#define GL_MODELVIEW29_ARB                                  0x873D
#define GL_MODELVIEW30_ARB                                  0x873E
#define GL_MODELVIEW31_ARB                                  0x873F
#endif

#ifndef GL_ARB_matrix_palette
#define GL_MATRIX_PALETTE_ARB                               0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB               0x8841
#define GL_MAX_PALETTE_MATRICES_ARB                         0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB                       0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB                           0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB                         0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB                      0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB                      0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB                    0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB                   0x8849
#endif

#ifndef GL_ARB_texture_env_combine
#define GL_COMBINE_ARB                                      0x8570
#define GL_COMBINE_RGB_ARB                                  0x8571
#define GL_COMBINE_ALPHA_ARB                                0x8572
#define GL_SOURCE0_RGB_ARB                                  0x8580
#define GL_SOURCE1_RGB_ARB                                  0x8581
#define GL_SOURCE2_RGB_ARB                                  0x8582
#define GL_SOURCE0_ALPHA_ARB                                0x8588
#define GL_SOURCE1_ALPHA_ARB                                0x8589
#define GL_SOURCE2_ALPHA_ARB                                0x858A
#define GL_OPERAND0_RGB_ARB                                 0x8590
#define GL_OPERAND1_RGB_ARB                                 0x8591
#define GL_OPERAND2_RGB_ARB                                 0x8592
#define GL_OPERAND0_ALPHA_ARB                               0x8598
#define GL_OPERAND1_ALPHA_ARB                               0x8599
#define GL_OPERAND2_ALPHA_ARB                               0x859A
#define GL_RGB_SCALE_ARB                                    0x8573
#define GL_ADD_SIGNED_ARB                                   0x8574
#define GL_INTERPOLATE_ARB                                  0x8575
#define GL_SUBTRACT_ARB                                     0x84E7
#define GL_CONSTANT_ARB                                     0x8576
#define GL_PRIMARY_COLOR_ARB                                0x8577
#define GL_PREVIOUS_ARB                                     0x8578
#endif

#ifndef GL_ARB_texture_env_crossbar
#endif

#ifndef GL_ARB_texture_env_dot3
#define GL_DOT3_RGB_ARB                                     0x86AE
#define GL_DOT3_RGBA_ARB                                    0x86AF
#endif

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_ARB                              0x8370
#endif

#ifndef GL_ARB_depth_texture
#define GL_DEPTH_COMPONENT16_ARB                            0x81A5
#define GL_DEPTH_COMPONENT24_ARB                            0x81A6
#define GL_DEPTH_COMPONENT32_ARB                            0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB                           0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB                           0x884B
#endif

#ifndef GL_ARB_shadow
#define GL_TEXTURE_COMPARE_MODE_ARB                         0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB                         0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB                         0x884E
#endif

#ifndef GL_ARB_shadow_ambient
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB                   0x80BF
#endif

#ifndef GL_ARB_window_pos
#endif

#ifndef GL_ARB_vertex_program
#define GL_COLOR_SUM_ARB                                    0x8458
#define GL_VERTEX_PROGRAM_ARB                               0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB                  0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                     0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB                   0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                     0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB                        0x8626
#define GL_PROGRAM_LENGTH_ARB                               0x8627
#define GL_PROGRAM_STRING_ARB                               0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB               0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB                         0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB                   0x8640
#define GL_CURRENT_MATRIX_ARB                               0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB                    0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                      0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB                  0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB                       0x864B
#define GL_PROGRAM_BINDING_ARB                              0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB                           0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB               0x886A
#define GL_PROGRAM_ERROR_STRING_ARB                         0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB                         0x8875
#define GL_PROGRAM_FORMAT_ARB                               0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB                         0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB                     0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB                  0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB              0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB                          0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB                      0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB                   0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB               0x88A7
#define GL_PROGRAM_PARAMETERS_ARB                           0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB                       0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB                    0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB                0x88AB
#define GL_PROGRAM_ATTRIBS_ARB                              0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB                          0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB                       0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB                   0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB                    0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB                0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB             0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB         0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB                 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB                   0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB                  0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB                     0x88B7
#define GL_MATRIX0_ARB                                      0x88C0
#define GL_MATRIX1_ARB                                      0x88C1
#define GL_MATRIX2_ARB                                      0x88C2
#define GL_MATRIX3_ARB                                      0x88C3
#define GL_MATRIX4_ARB                                      0x88C4
#define GL_MATRIX5_ARB                                      0x88C5
#define GL_MATRIX6_ARB                                      0x88C6
#define GL_MATRIX7_ARB                                      0x88C7
#define GL_MATRIX8_ARB                                      0x88C8
#define GL_MATRIX9_ARB                                      0x88C9
#define GL_MATRIX10_ARB                                     0x88CA
#define GL_MATRIX11_ARB                                     0x88CB
#define GL_MATRIX12_ARB                                     0x88CC
#define GL_MATRIX13_ARB                                     0x88CD
#define GL_MATRIX14_ARB                                     0x88CE
#define GL_MATRIX15_ARB                                     0x88CF
#define GL_MATRIX16_ARB                                     0x88D0
#define GL_MATRIX17_ARB                                     0x88D1
#define GL_MATRIX18_ARB                                     0x88D2
#define GL_MATRIX19_ARB                                     0x88D3
#define GL_MATRIX20_ARB                                     0x88D4
#define GL_MATRIX21_ARB                                     0x88D5
#define GL_MATRIX22_ARB                                     0x88D6
#define GL_MATRIX23_ARB                                     0x88D7
#define GL_MATRIX24_ARB                                     0x88D8
#define GL_MATRIX25_ARB                                     0x88D9
#define GL_MATRIX26_ARB                                     0x88DA
#define GL_MATRIX27_ARB                                     0x88DB
#define GL_MATRIX28_ARB                                     0x88DC
#define GL_MATRIX29_ARB                                     0x88DD
#define GL_MATRIX30_ARB                                     0x88DE
#define GL_MATRIX31_ARB                                     0x88DF
#endif

#ifndef GL_ARB_fragment_program
#define GL_FRAGMENT_PROGRAM_ARB                             0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB                     0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB                     0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB                     0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB              0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB              0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB              0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB                 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB                 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB                 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB          0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB          0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB          0x8810
#define GL_MAX_TEXTURE_COORDS_ARB                           0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB                      0x8872
#endif

#ifndef GL_ARB_vertex_buffer_object
#define GL_BUFFER_SIZE_ARB                                  0x8764
#define GL_BUFFER_USAGE_ARB                                 0x8765
#define GL_ARRAY_BUFFER_ARB                                 0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB                         0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB                         0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB                 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB                  0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB                  0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB                   0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB                   0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB           0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB               0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB         0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB          0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB                  0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB           0x889F
#define GL_READ_ONLY_ARB                                    0x88B8
#define GL_WRITE_ONLY_ARB                                   0x88B9
#define GL_READ_WRITE_ARB                                   0x88BA
#define GL_BUFFER_ACCESS_ARB                                0x88BB
#define GL_BUFFER_MAPPED_ARB                                0x88BC
#define GL_BUFFER_MAP_POINTER_ARB                           0x88BD
#define GL_STREAM_DRAW_ARB                                  0x88E0
#define GL_STREAM_READ_ARB                                  0x88E1
#define GL_STREAM_COPY_ARB                                  0x88E2
#define GL_STATIC_DRAW_ARB                                  0x88E4
#define GL_STATIC_READ_ARB                                  0x88E5
#define GL_STATIC_COPY_ARB                                  0x88E6
#define GL_DYNAMIC_DRAW_ARB                                 0x88E8
#define GL_DYNAMIC_READ_ARB                                 0x88E9
#define GL_DYNAMIC_COPY_ARB                                 0x88EA
#endif

#ifndef GL_ARB_occlusion_query
#define GL_QUERY_COUNTER_BITS_ARB                           0x8864
#define GL_CURRENT_QUERY_ARB                                0x8865
#define GL_QUERY_RESULT_ARB                                 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB                       0x8867
#define GL_SAMPLES_PASSED_ARB                               0x8914
#endif

#ifndef GL_ARB_shader_objects
#define GL_PROGRAM_OBJECT_ARB                               0x8B40
#define GL_SHADER_OBJECT_ARB                                0x8B48
#define GL_OBJECT_TYPE_ARB                                  0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                               0x8B4F
#define GL_FLOAT_VEC2_ARB                                   0x8B50
#define GL_FLOAT_VEC3_ARB                                   0x8B51
#define GL_FLOAT_VEC4_ARB                                   0x8B52
#define GL_INT_VEC2_ARB                                     0x8B53
#define GL_INT_VEC3_ARB                                     0x8B54
#define GL_INT_VEC4_ARB                                     0x8B55
#define GL_BOOL_ARB                                         0x8B56
#define GL_BOOL_VEC2_ARB                                    0x8B57
#define GL_BOOL_VEC3_ARB                                    0x8B58
#define GL_BOOL_VEC4_ARB                                    0x8B59
#define GL_FLOAT_MAT2_ARB                                   0x8B5A
#define GL_FLOAT_MAT3_ARB                                   0x8B5B
#define GL_FLOAT_MAT4_ARB                                   0x8B5C
#define GL_SAMPLER_1D_ARB                                   0x8B5D
#define GL_SAMPLER_2D_ARB                                   0x8B5E
#define GL_SAMPLER_3D_ARB                                   0x8B5F
#define GL_SAMPLER_CUBE_ARB                                 0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB                            0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB                            0x8B62
#define GL_SAMPLER_2D_RECT_ARB                              0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB                       0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB                         0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB                        0x8B81
#define GL_OBJECT_LINK_STATUS_ARB                           0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB                       0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB                       0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB                      0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB                       0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB             0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB                  0x8B88
#endif

#ifndef GL_ARB_vertex_shader
#define GL_VERTEX_SHADER_ARB                                0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB                0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                           0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB               0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB             0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                     0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB           0x8B8A
#endif

#ifndef GL_ARB_fragment_shader
#define GL_FRAGMENT_SHADER_ARB                              0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB              0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB              0x8B8B
#endif

#ifndef GL_ARB_shading_language_100
#define GL_SHADING_LANGUAGE_VERSION_ARB                     0x8B8C
#endif

#ifndef GL_ARB_texture_non_power_of_two
#endif

#ifndef GL_ARB_point_sprite
#define GL_POINT_SPRITE_ARB                                 0x8861
#define GL_COORD_REPLACE_ARB                                0x8862
#endif

#ifndef GL_ARB_fragment_program_shadow
#endif

#ifndef GL_ARB_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ARB                             0x8824
#define GL_DRAW_BUFFER0_ARB                                 0x8825
#define GL_DRAW_BUFFER1_ARB                                 0x8826
#define GL_DRAW_BUFFER2_ARB                                 0x8827
#define GL_DRAW_BUFFER3_ARB                                 0x8828
#define GL_DRAW_BUFFER4_ARB                                 0x8829
#define GL_DRAW_BUFFER5_ARB                                 0x882A
#define GL_DRAW_BUFFER6_ARB                                 0x882B
#define GL_DRAW_BUFFER7_ARB                                 0x882C
#define GL_DRAW_BUFFER8_ARB                                 0x882D
#define GL_DRAW_BUFFER9_ARB                                 0x882E
#define GL_DRAW_BUFFER10_ARB                                0x882F
#define GL_DRAW_BUFFER11_ARB                                0x8830
#define GL_DRAW_BUFFER12_ARB                                0x8831
#define GL_DRAW_BUFFER13_ARB                                0x8832
#define GL_DRAW_BUFFER14_ARB                                0x8833
#define GL_DRAW_BUFFER15_ARB                                0x8834
#endif

#ifndef GL_ARB_texture_rectangle
#define GL_TEXTURE_RECTANGLE_ARB                            0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB                    0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB                      0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB                   0x84F8
#endif

#ifndef GL_ARB_color_buffer_float
#define GL_RGBA_FLOAT_MODE_ARB                              0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB                           0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB                         0x891B
#define GL_CLAMP_READ_COLOR_ARB                             0x891C
#define GL_FIXED_ONLY_ARB                                   0x891D
#endif

#ifndef GL_ARB_half_float_pixel
#define GL_HALF_FLOAT_ARB                                   0x140B
#endif

#ifndef GL_ARB_texture_float
#define GL_TEXTURE_RED_TYPE_ARB                             0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB                           0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB                            0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB                           0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB                       0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB                       0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB                           0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB                          0x8C17
#define GL_RGBA32F_ARB                                      0x8814
#define GL_RGB32F_ARB                                       0x8815
#define GL_ALPHA32F_ARB                                     0x8816
#define GL_INTENSITY32F_ARB                                 0x8817
#define GL_LUMINANCE32F_ARB                                 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB                           0x8819
#define GL_RGBA16F_ARB                                      0x881A
#define GL_RGB16F_ARB                                       0x881B
#define GL_ALPHA16F_ARB                                     0x881C
#define GL_INTENSITY16F_ARB                                 0x881D
#define GL_LUMINANCE16F_ARB                                 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB                           0x881F
#endif

#ifndef GL_ARB_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_ARB                            0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB                          0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB                    0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB                  0x88EF
#endif

#ifndef GL_ARB_depth_buffer_float
#define GL_DEPTH_COMPONENT32F                               0x8CAC
#define GL_DEPTH32F_STENCIL8                                0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                   0x8DAD
#endif

#ifndef GL_ARB_draw_instanced
#endif

#ifndef GL_ARB_framebuffer_object
#define GL_INVALID_FRAMEBUFFER_OPERATION                    0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING            0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE            0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                  0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE              0x8217
#define GL_FRAMEBUFFER_DEFAULT                              0x8218
#define GL_FRAMEBUFFER_UNDEFINED                            0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT                         0x821A
#define GL_MAX_RENDERBUFFER_SIZE                            0x84E8
#define GL_DEPTH_STENCIL                                    0x84F9
#define GL_UNSIGNED_INT_24_8                                0x84FA
#define GL_DEPTH24_STENCIL8                                 0x88F0
#define GL_TEXTURE_STENCIL_SIZE                             0x88F1
#define GL_TEXTURE_RED_TYPE                                 0x8C10
#define GL_TEXTURE_GREEN_TYPE                               0x8C11
#define GL_TEXTURE_BLUE_TYPE                                0x8C12
#define GL_TEXTURE_ALPHA_TYPE                               0x8C13
#define GL_TEXTURE_DEPTH_TYPE                               0x8C16
#define GL_UNSIGNED_NORMALIZED                              0x8C17
#define GL_FRAMEBUFFER_BINDING                              0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING                         GL_FRAMEBUFFER_BINDING
#define GL_RENDERBUFFER_BINDING                             0x8CA7
#define GL_READ_FRAMEBUFFER                                 0x8CA8
#define GL_DRAW_FRAMEBUFFER                                 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING                         0x8CAA
#define GL_RENDERBUFFER_SAMPLES                             0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE               0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME               0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL             0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE     0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER             0x8CD4
#define GL_FRAMEBUFFER_COMPLETE                             0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT        0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER               0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER               0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED                          0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS                            0x8CDF
#define GL_COLOR_ATTACHMENT0                                0x8CE0
#define GL_COLOR_ATTACHMENT1                                0x8CE1
#define GL_COLOR_ATTACHMENT2                                0x8CE2
#define GL_COLOR_ATTACHMENT3                                0x8CE3
#define GL_COLOR_ATTACHMENT4                                0x8CE4
#define GL_COLOR_ATTACHMENT5                                0x8CE5
#define GL_COLOR_ATTACHMENT6                                0x8CE6
#define GL_COLOR_ATTACHMENT7                                0x8CE7
#define GL_COLOR_ATTACHMENT8                                0x8CE8
#define GL_COLOR_ATTACHMENT9                                0x8CE9
#define GL_COLOR_ATTACHMENT10                               0x8CEA
#define GL_COLOR_ATTACHMENT11                               0x8CEB
#define GL_COLOR_ATTACHMENT12                               0x8CEC
#define GL_COLOR_ATTACHMENT13                               0x8CED
#define GL_COLOR_ATTACHMENT14                               0x8CEE
#define GL_COLOR_ATTACHMENT15                               0x8CEF
#define GL_DEPTH_ATTACHMENT                                 0x8D00
#define GL_STENCIL_ATTACHMENT                               0x8D20
#define GL_FRAMEBUFFER                                      0x8D40
#define GL_RENDERBUFFER                                     0x8D41
#define GL_RENDERBUFFER_WIDTH                               0x8D42
#define GL_RENDERBUFFER_HEIGHT                              0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                     0x8D44
#define GL_STENCIL_INDEX1                                   0x8D46
#define GL_STENCIL_INDEX4                                   0x8D47
#define GL_STENCIL_INDEX8                                   0x8D48
#define GL_STENCIL_INDEX16                                  0x8D49
#define GL_RENDERBUFFER_RED_SIZE                            0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE                          0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE                           0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE                          0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE                          0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE                        0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE               0x8D56
#define GL_MAX_SAMPLES                                      0x8D57
#define GL_INDEX                                            0x8222
#define GL_TEXTURE_LUMINANCE_TYPE                           0x8C14
#define GL_TEXTURE_INTENSITY_TYPE                           0x8C15
#endif

#ifndef GL_ARB_framebuffer_sRGB
#define GL_FRAMEBUFFER_SRGB                                 0x8DB9
#endif

#ifndef GL_ARB_geometry_shader4
#define GL_LINES_ADJACENCY_ARB                              0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB                         0x000B
#define GL_TRIANGLES_ADJACENCY_ARB                          0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB                     0x000D
#define GL_PROGRAM_POINT_SIZE_ARB                           0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB             0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB               0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB         0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB           0x8DA9
#define GL_GEOMETRY_SHADER_ARB                              0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB                        0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB                          0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB                         0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB              0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB                0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB              0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB                 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB         0x8DE1
/* reuse GL_MAX_VARYING_COMPONENTS */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER */
#endif

#ifndef GL_ARB_half_float_vertex
#define GL_HALF_FLOAT                                       0x140B
#endif

#ifndef GL_ARB_instanced_arrays
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB                  0x88FE
#endif

#ifndef GL_ARB_map_buffer_range
#define GL_MAP_READ_BIT                                     0x0001
#define GL_MAP_WRITE_BIT                                    0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT                         0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT                        0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT                           0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT                           0x0020
#endif

#ifndef GL_ARB_texture_buffer_object
#define GL_TEXTURE_BUFFER_ARB                               0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB                      0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB                       0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB            0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB                        0x8C2E
#endif

#ifndef GL_ARB_texture_compression_rgtc
#define GL_COMPRESSED_RED_RGTC1                             0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1                      0x8DBC
#define GL_COMPRESSED_RG_RGTC2                              0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2                       0x8DBE
#endif

#ifndef GL_ARB_texture_rg
#define GL_RG                                               0x8227
#define GL_RG_INTEGER                                       0x8228
#define GL_R8                                               0x8229
#define GL_R16                                              0x822A
#define GL_RG8                                              0x822B
#define GL_RG16                                             0x822C
#define GL_R16F                                             0x822D
#define GL_R32F                                             0x822E
#define GL_RG16F                                            0x822F
#define GL_RG32F                                            0x8230
#define GL_R8I                                              0x8231
#define GL_R8UI                                             0x8232
#define GL_R16I                                             0x8233
#define GL_R16UI                                            0x8234
#define GL_R32I                                             0x8235
#define GL_R32UI                                            0x8236
#define GL_RG8I                                             0x8237
#define GL_RG8UI                                            0x8238
#define GL_RG16I                                            0x8239
#define GL_RG16UI                                           0x823A
#define GL_RG32I                                            0x823B
#define GL_RG32UI                                           0x823C
#endif

#ifndef GL_ARB_vertex_array_object
#define GL_VERTEX_ARRAY_BINDING                             0x85B5
#endif

#ifndef GL_ARB_uniform_buffer_object
#define GL_UNIFORM_BUFFER                                   0x8A11
#define GL_UNIFORM_BUFFER_BINDING                           0x8A28
#define GL_UNIFORM_BUFFER_START                             0x8A29
#define GL_UNIFORM_BUFFER_SIZE                              0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS                        0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS                      0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS                      0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS                      0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS                      0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE                           0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS           0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS         0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS         0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT                  0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH             0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS                            0x8A36
#define GL_UNIFORM_TYPE                                     0x8A37
#define GL_UNIFORM_SIZE                                     0x8A38
#define GL_UNIFORM_NAME_LENGTH                              0x8A39
#define GL_UNIFORM_BLOCK_INDEX                              0x8A3A
#define GL_UNIFORM_OFFSET                                   0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE                             0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE                            0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR                             0x8A3E
#define GL_UNIFORM_BLOCK_BINDING                            0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE                          0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH                        0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                    0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES             0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER        0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER      0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER      0x8A46
#define GL_INVALID_INDEX                                    0xFFFFFFFFu
#endif

#ifndef GL_ARB_compatibility

/* ARB_compatibility just defines tokens from core 3.0 */
#endif

#ifndef GL_ARB_copy_buffer
#define GL_COPY_READ_BUFFER_BINDING                         0x8F36
#define GL_COPY_READ_BUFFER                                 GL_COPY_READ_BUFFER_BINDING
#define GL_COPY_WRITE_BUFFER_BINDING                        0x8F37
#define GL_COPY_WRITE_BUFFER                                GL_COPY_WRITE_BUFFER_BINDING
#endif

#ifndef GL_ARB_shader_texture_lod
#endif

#ifndef GL_ARB_depth_clamp
#define GL_DEPTH_CLAMP                                      0x864F
#endif

#ifndef GL_ARB_draw_elements_base_vertex
#endif

#ifndef GL_ARB_fragment_coord_conventions
#endif

#ifndef GL_ARB_provoking_vertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION         0x8E4C
#define GL_FIRST_VERTEX_CONVENTION                          0x8E4D
#define GL_LAST_VERTEX_CONVENTION                           0x8E4E
#define GL_PROVOKING_VERTEX                                 0x8E4F
#endif

#ifndef GL_ARB_seamless_cube_map
#define GL_TEXTURE_CUBE_MAP_SEAMLESS                        0x884F
#endif

#ifndef GL_ARB_sync
#define GL_MAX_SERVER_WAIT_TIMEOUT                          0x9111
#define GL_OBJECT_TYPE                                      0x9112
#define GL_SYNC_CONDITION                                   0x9113
#define GL_SYNC_STATUS                                      0x9114
#define GL_SYNC_FLAGS                                       0x9115
#define GL_SYNC_FENCE                                       0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE                       0x9117
#define GL_UNSIGNALED                                       0x9118
#define GL_SIGNALED                                         0x9119
#define GL_ALREADY_SIGNALED                                 0x911A
#define GL_TIMEOUT_EXPIRED                                  0x911B
#define GL_CONDITION_SATISFIED                              0x911C
#define GL_WAIT_FAILED                                      0x911D
#define GL_SYNC_FLUSH_COMMANDS_BIT                          0x00000001
#define GL_TIMEOUT_IGNORED                                  0xFFFFFFFFFFFFFFFFull
#endif

#ifndef GL_ARB_texture_multisample
#define GL_SAMPLE_POSITION                                  0x8E50
#define GL_SAMPLE_MASK                                      0x8E51
#define GL_SAMPLE_MASK_VALUE                                0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS                            0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE                           0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE                     0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY                     0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY               0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE                   0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY             0x9105
#define GL_TEXTURE_SAMPLES                                  0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS                   0x9107
#define GL_SAMPLER_2D_MULTISAMPLE                           0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE                       0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE              0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY                     0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY                 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY        0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES                        0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES                        0x910F
#define GL_MAX_INTEGER_SAMPLES                              0x9110
#endif

#ifndef GL_ARB_vertex_array_bgra
/* reuse GL_BGRA */
#endif

#ifndef GL_ARB_draw_buffers_blend
#endif

#ifndef GL_ARB_sample_shading
#define GL_SAMPLE_SHADING_ARB                               0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB                     0x8C37
#endif

#ifndef GL_ARB_texture_cube_map_array
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB                       0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB               0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB                 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB                       0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB                0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB                   0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB          0x900F
#endif

#ifndef GL_ARB_texture_gather
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB            0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB            0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB        0x8F9F
#endif

#ifndef GL_ARB_texture_query_lod
#endif

#ifndef GL_ARB_shading_language_include
#define GL_SHADER_INCLUDE_ARB                               0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB                          0x8DE9
#define GL_NAMED_STRING_TYPE_ARB                            0x8DEA
#endif

#ifndef GL_ARB_texture_compression_bptc
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB                   0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB             0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB             0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB           0x8E8F
#endif

#ifndef GL_ARB_blend_func_extended
#define GL_SRC1_COLOR                                       0x88F9
/* reuse GL_SRC1_ALPHA */
#define GL_ONE_MINUS_SRC1_COLOR                             0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA                             0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS                     0x88FC
#endif

#ifndef GL_ARB_explicit_attrib_location
#endif

#ifndef GL_ARB_occlusion_query2
#define GL_ANY_SAMPLES_PASSED                               0x8C2F
#endif

#ifndef GL_ARB_sampler_objects
#define GL_SAMPLER_BINDING                                  0x8919
#endif

#ifndef GL_ARB_shader_bit_encoding
#endif

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_RGB10_A2UI                                       0x906F
#endif

#ifndef GL_ARB_texture_swizzle
#define GL_TEXTURE_SWIZZLE_R                                0x8E42
#define GL_TEXTURE_SWIZZLE_G                                0x8E43
#define GL_TEXTURE_SWIZZLE_B                                0x8E44
#define GL_TEXTURE_SWIZZLE_A                                0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA                             0x8E46
#endif

#ifndef GL_ARB_timer_query
#define GL_TIME_ELAPSED                                     0x88BF
#define GL_TIMESTAMP                                        0x8E28
#endif

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
/* reuse GL_UNSIGNED_INT_2_10_10_10_REV */
#define GL_INT_2_10_10_10_REV                               0x8D9F
#endif

#ifndef GL_ARB_draw_indirect
#define GL_DRAW_INDIRECT_BUFFER                             0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING                     0x8F43
#endif

#ifndef GL_ARB_gpu_shader5
#define GL_GEOMETRY_SHADER_INVOCATIONS                      0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS                  0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS               0x8E5D
/* reuse GL_MAX_VERTEX_STREAMS */
#endif

#ifndef GL_ARB_gpu_shader_fp64
/* reuse GL_DOUBLE */
#define GL_DOUBLE_VEC2                                      0x8FFC
#define GL_DOUBLE_VEC3                                      0x8FFD
#define GL_DOUBLE_VEC4                                      0x8FFE
#define GL_DOUBLE_MAT2                                      0x8F46
#define GL_DOUBLE_MAT3                                      0x8F47
#define GL_DOUBLE_MAT4                                      0x8F48
#define GL_DOUBLE_MAT2x3                                    0x8F49
#define GL_DOUBLE_MAT2x4                                    0x8F4A
#define GL_DOUBLE_MAT3x2                                    0x8F4B
#define GL_DOUBLE_MAT3x4                                    0x8F4C
#define GL_DOUBLE_MAT4x2                                    0x8F4D
#define GL_DOUBLE_MAT4x3                                    0x8F4E
#endif

#ifndef GL_ARB_shader_subroutine
#define GL_ACTIVE_SUBROUTINES                               0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS                       0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS              0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH                     0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH             0x8E49
#define GL_MAX_SUBROUTINES                                  0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES                       0x8E4A
#define GL_COMPATIBLE_SUBROUTINES                           0x8E4B
/* reuse GL_UNIFORM_SIZE */
/* reuse GL_UNIFORM_NAME_LENGTH */
#endif

#ifndef GL_ARB_tessellation_shader
#define GL_PATCHES                                          0x000E
#define GL_PATCH_VERTICES                                   0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL                        0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL                        0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES                     0x8E75
#define GL_TESS_GEN_MODE                                    0x8E76
#define GL_TESS_GEN_SPACING                                 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER                            0x8E78
#define GL_TESS_GEN_POINT_MODE                              0x8E79
/* reuse GL_TRIANGLES */
/* reuse GL_QUADS */
#define GL_ISOLINES                                         0x8E7A
/* reuse GL_EQUAL */
#define GL_FRACTIONAL_ODD                                   0x8E7B
#define GL_FRACTIONAL_EVEN                                  0x8E7C
/* reuse GL_CCW */
/* reuse GL_CW */
#define GL_MAX_PATCH_VERTICES                               0x8E7D
#define GL_MAX_TESS_GEN_LEVEL                               0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS              0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS           0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS             0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS          0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS               0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS                        0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS         0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS            0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                  0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS               0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS             0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS     0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS  0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER  0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER                           0x8E87
#define GL_TESS_CONTROL_SHADER                              0x8E88
#endif

#ifndef GL_ARB_texture_buffer_object_rgb32
/* reuse GL_RGB32F */
/* reuse GL_RGB32UI */
/* reuse GL_RGB32I */
#endif

#ifndef GL_ARB_transform_feedback2
#define GL_TRANSFORM_FEEDBACK                               0x8E22
#define GL_TRANSFORM_FEEDBACK_PAUSED                        0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                 GL_TRANSFORM_FEEDBACK_PAUSED
#define GL_TRANSFORM_FEEDBACK_ACTIVE                        0x8E24
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                 GL_TRANSFORM_FEEDBACK_ACTIVE
#define GL_TRANSFORM_FEEDBACK_BINDING                       0x8E25
#endif

#ifndef GL_ARB_transform_feedback3
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                   0x8E70
#define GL_MAX_VERTEX_STREAMS                               0x8E71
#endif

#ifndef GL_ARB_ES2_compatibility
#define GL_FIXED                                            0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE                   0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT                 0x8B9B
#define GL_LOW_FLOAT                                        0x8DF0
#define GL_MEDIUM_FLOAT                                     0x8DF1
#define GL_HIGH_FLOAT                                       0x8DF2
#define GL_LOW_INT                                          0x8DF3
#define GL_MEDIUM_INT                                       0x8DF4
#define GL_HIGH_INT                                         0x8DF5
#define GL_SHADER_COMPILER                                  0x8DFA
#define GL_SHADER_BINARY_FORMATS                            0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS                        0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS                       0x8DFB
#define GL_MAX_VARYING_VECTORS                              0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS                     0x8DFD
#define GL_RGB565                                           0x8D62
#endif

#ifndef GL_ARB_get_program_binary
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT                  0x8257
#define GL_PROGRAM_BINARY_LENGTH                            0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS                       0x87FE
#define GL_PROGRAM_BINARY_FORMATS                           0x87FF
#endif

#ifndef GL_ARB_separate_shader_objects
#define GL_VERTEX_SHADER_BIT                                0x00000001
#define GL_FRAGMENT_SHADER_BIT                              0x00000002
#define GL_GEOMETRY_SHADER_BIT                              0x00000004
#define GL_TESS_CONTROL_SHADER_BIT                          0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT                       0x00000010
#define GL_ALL_SHADER_BITS                                  0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE                                0x8258
#define GL_ACTIVE_PROGRAM                                   0x8259
#define GL_PROGRAM_PIPELINE_BINDING                         0x825A
#endif

#ifndef GL_ARB_shader_precision
#endif

#ifndef GL_ARB_vertex_attrib_64bit
/* reuse GL_RGB32I */
/* reuse GL_DOUBLE_VEC2 */
/* reuse GL_DOUBLE_VEC3 */
/* reuse GL_DOUBLE_VEC4 */
/* reuse GL_DOUBLE_MAT2 */
/* reuse GL_DOUBLE_MAT3 */
/* reuse GL_DOUBLE_MAT4 */
/* reuse GL_DOUBLE_MAT2x3 */
/* reuse GL_DOUBLE_MAT2x4 */
/* reuse GL_DOUBLE_MAT3x2 */
/* reuse GL_DOUBLE_MAT3x4 */
/* reuse GL_DOUBLE_MAT4x2 */
/* reuse GL_DOUBLE_MAT4x3 */
#endif

#ifndef GL_ARB_viewport_array
/* reuse GL_SCISSOR_BOX */
/* reuse GL_VIEWPORT */
/* reuse GL_DEPTH_RANGE */
/* reuse GL_SCISSOR_TEST */
#define GL_MAX_VIEWPORTS                                    0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS                           0x825C
#define GL_VIEWPORT_BOUNDS_RANGE                            0x825D
#define GL_LAYER_PROVOKING_VERTEX                           0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX                  0x825F
#define GL_UNDEFINED_VERTEX                                 0x8260
/* reuse GL_FIRST_VERTEX_CONVENTION */
/* reuse GL_LAST_VERTEX_CONVENTION */
/* reuse GL_PROVOKING_VERTEX */
#endif

#ifndef GL_ARB_cl_event
#define GL_SYNC_CL_EVENT_ARB                                0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB                       0x8241
#endif

#ifndef GL_ARB_debug_output
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB                     0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB             0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB                      0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB                    0x8245
#define GL_DEBUG_SOURCE_API_ARB                             0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB                   0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB                 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB                     0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB                     0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB                           0x824B
#define GL_DEBUG_TYPE_ERROR_ARB                             0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB               0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB                0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB                       0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB                       0x8250
#define GL_DEBUG_TYPE_OTHER_ARB                             0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB                     0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB                    0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB                        0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB                          0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB                        0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB                           0x9148
#endif

#ifndef GL_ARB_robustness
/* reuse GL_NO_ERROR */
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB               0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB                        0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB                         0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB                       0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB                        0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB                  0x8256
#define GL_NO_RESET_NOTIFICATION_ARB                        0x8261
#endif

#ifndef GL_ARB_shader_stencil_export
#endif

#ifndef GL_ARB_base_instance
#endif

#ifndef GL_ARB_shading_language_420pack
#endif

#ifndef GL_ARB_transform_feedback_instanced
#endif

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH                    0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT                   0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH                    0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE                     0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH                      0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT                     0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH                      0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE                       0x912E
#endif

#ifndef GL_ARB_conservative_depth
#endif

#ifndef GL_ARB_internalformat_query
#define GL_NUM_SAMPLE_COUNTS                                0x9380
#endif

#ifndef GL_ARB_map_buffer_alignment
#define GL_MIN_MAP_BUFFER_ALIGNMENT                         0x90BC
#endif

#ifndef GL_ARB_shader_atomic_counters
#define GL_ATOMIC_COUNTER_BUFFER                            0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING                    0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START                      0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE                       0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE                  0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS     0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS                0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS          0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS       0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS              0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS              0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS              0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS                       0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS              0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS                     0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS                     0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS                     0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                   0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS               0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                    0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX              0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER                      0x92DB
#endif

#ifndef GL_ARB_shader_image_load_store
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT                  0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT                        0x00000002
#define GL_UNIFORM_BARRIER_BIT                              0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT                        0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT                  0x00000020
#define GL_COMMAND_BARRIER_BIT                              0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT                         0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT                       0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT                        0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT                          0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT                   0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT                       0x00001000
#define GL_ALL_BARRIER_BITS                                 0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                                  0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS    0x8F39
#define GL_IMAGE_BINDING_NAME                               0x8F3A
#define GL_IMAGE_BINDING_LEVEL                              0x8F3B
#define GL_IMAGE_BINDING_LAYERED                            0x8F3C
#define GL_IMAGE_BINDING_LAYER                              0x8F3D
#define GL_IMAGE_BINDING_ACCESS                             0x8F3E
#define GL_IMAGE_1D                                         0x904C
#define GL_IMAGE_2D                                         0x904D
#define GL_IMAGE_3D                                         0x904E
#define GL_IMAGE_2D_RECT                                    0x904F
#define GL_IMAGE_CUBE                                       0x9050
#define GL_IMAGE_BUFFER                                     0x9051
#define GL_IMAGE_1D_ARRAY                                   0x9052
#define GL_IMAGE_2D_ARRAY                                   0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY                             0x9054
#define GL_IMAGE_2D_MULTISAMPLE                             0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY                       0x9056
#define GL_INT_IMAGE_1D                                     0x9057
#define GL_INT_IMAGE_2D                                     0x9058
#define GL_INT_IMAGE_3D                                     0x9059
#define GL_INT_IMAGE_2D_RECT                                0x905A
#define GL_INT_IMAGE_CUBE                                   0x905B
#define GL_INT_IMAGE_BUFFER                                 0x905C
#define GL_INT_IMAGE_1D_ARRAY                               0x905D
#define GL_INT_IMAGE_2D_ARRAY                               0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY                         0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE                         0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY                   0x9061
#define GL_UNSIGNED_INT_IMAGE_1D                            0x9062
#define GL_UNSIGNED_INT_IMAGE_2D                            0x9063
#define GL_UNSIGNED_INT_IMAGE_3D                            0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT                       0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE                          0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER                        0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY                      0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY                      0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY                0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE                0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY          0x906C
#define GL_MAX_IMAGE_SAMPLES                                0x906D
#define GL_IMAGE_BINDING_FORMAT                             0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE                  0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE               0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS              0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS                        0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                  0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS               0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS                      0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS                      0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS                      0x90CF
#endif

#ifndef GL_ARB_shading_language_packing
#endif

#ifndef GL_ARB_texture_storage
#define GL_TEXTURE_IMMUTABLE_FORMAT                         0x912F
#endif

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR                     0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR                     0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR                     0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR                     0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR                     0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR                     0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR                     0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR                     0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR                    0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR                    0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR                    0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR                   0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR                   0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR                   0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR             0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR             0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR             0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR             0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR             0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR             0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR             0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR             0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR            0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR            0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR            0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR           0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR           0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR           0x93DD
#endif

#ifndef GL_KHR_debug
#define GL_DEBUG_OUTPUT_SYNCHRONOUS                         0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION                          0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM                        0x8245
#define GL_DEBUG_SOURCE_API                                 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM                       0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER                     0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY                         0x8249
#define GL_DEBUG_SOURCE_APPLICATION                         0x824A
#define GL_DEBUG_SOURCE_OTHER                               0x824B
#define GL_DEBUG_TYPE_ERROR                                 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                   0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                    0x824E
#define GL_DEBUG_TYPE_PORTABILITY                           0x824F
#define GL_DEBUG_TYPE_PERFORMANCE                           0x8250
#define GL_DEBUG_TYPE_OTHER                                 0x8251
#define GL_DEBUG_TYPE_MARKER                                0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP                            0x8269
#define GL_DEBUG_TYPE_POP_GROUP                             0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION                      0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH                      0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH                          0x826D
#define GL_BUFFER                                           0x82E0
#define GL_SHADER                                           0x82E1
#define GL_PROGRAM                                          0x82E2
#define GL_QUERY                                            0x82E3
#define GL_PROGRAM_PIPELINE                                 0x82E4
#define GL_SAMPLER                                          0x82E6
#define GL_DISPLAY_LIST                                     0x82E7

/* DISPLAY_LIST used in compatibility profile only */
#define GL_MAX_LABEL_LENGTH                                 0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH                         0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES                        0x9144
#define GL_DEBUG_LOGGED_MESSAGES                            0x9145
#define GL_DEBUG_SEVERITY_HIGH                              0x9146
#define GL_DEBUG_SEVERITY_MEDIUM                            0x9147
#define GL_DEBUG_SEVERITY_LOW                               0x9148
#define GL_DEBUG_OUTPUT                                     0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT                           0x00000002
/* reuse GL_STACK_UNDERFLOW */
/* reuse GL_STACK_OVERFLOW */
#endif

#ifndef GL_ARB_arrays_of_arrays
#endif

#ifndef GL_ARB_clear_buffer_object
#endif

#ifndef GL_ARB_compute_shader
#define GL_COMPUTE_SHADER                                   0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS                       0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS                  0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS                       0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                   0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS                   0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS               0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS                      0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS          0x8266
#define GL_MAX_COMPUTE_LOCAL_INVOCATIONS                    0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT                     0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE                      0x91BF
#define GL_COMPUTE_LOCAL_WORK_SIZE                          0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER       0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER                         0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING                 0x90EF
#define GL_COMPUTE_SHADER_BIT                               0x00000020
#endif

#ifndef GL_ARB_copy_image
#endif

#ifndef GL_ARB_texture_view
#define GL_TEXTURE_VIEW_MIN_LEVEL                           0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS                          0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER                           0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS                          0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS                         0x82DF
#endif

#ifndef GL_ARB_vertex_attrib_binding
#define GL_VERTEX_ATTRIB_BINDING                            0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET                    0x82D5
#define GL_VERTEX_BINDING_DIVISOR                           0x82D6
#define GL_VERTEX_BINDING_OFFSET                            0x82D7
#define GL_VERTEX_BINDING_STRIDE                            0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET                0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS                       0x82DA
#endif

#ifndef GL_ARB_robustness_isolation
#endif

#ifndef GL_ARB_ES3_compatibility
#define GL_COMPRESSED_RGB8_ETC2                             0x9274
#define GL_COMPRESSED_SRGB8_ETC2                            0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2         0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2        0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC                        0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC                 0x9279
#define GL_COMPRESSED_R11_EAC                               0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC                        0x9271
#define GL_COMPRESSED_RG11_EAC                              0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC                       0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX                    0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE                  0x8D6A
#define GL_MAX_ELEMENT_INDEX                                0x8D6B
#endif

#ifndef GL_ARB_explicit_uniform_location
#define GL_MAX_UNIFORM_LOCATIONS                            0x826E
#endif

#ifndef GL_ARB_fragment_layer_viewport
#endif

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_FRAMEBUFFER_DEFAULT_WIDTH                        0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT                       0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS                       0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES                      0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS       0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH                            0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT                           0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS                           0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES                          0x9318
#endif

#ifndef GL_ARB_internalformat_query2
/* reuse GL_IMAGE_FORMAT_COMPATIBILITY_TYPE */
/* reuse GL_NUM_SAMPLE_COUNTS */
/* reuse GL_RENDERBUFFER */
/* reuse GL_SAMPLES */
/* reuse GL_TEXTURE_1D */
/* reuse GL_TEXTURE_1D_ARRAY */
/* reuse GL_TEXTURE_2D */
/* reuse GL_TEXTURE_2D_ARRAY */
/* reuse GL_TEXTURE_3D */
/* reuse GL_TEXTURE_CUBE_MAP */
/* reuse GL_TEXTURE_CUBE_MAP_ARRAY */
/* reuse GL_TEXTURE_RECTANGLE */
/* reuse GL_TEXTURE_BUFFER */
/* reuse GL_TEXTURE_2D_MULTISAMPLE */
/* reuse GL_TEXTURE_2D_MULTISAMPLE_ARRAY */
/* reuse GL_TEXTURE_COMPRESSED */
#define GL_INTERNALFORMAT_SUPPORTED                         0x826F
#define GL_INTERNALFORMAT_PREFERRED                         0x8270
#define GL_INTERNALFORMAT_RED_SIZE                          0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE                        0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE                         0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE                        0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE                        0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE                      0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE                       0x8277
#define GL_INTERNALFORMAT_RED_TYPE                          0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE                        0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE                         0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE                        0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE                        0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE                      0x827D
#define GL_MAX_WIDTH                                        0x827E
#define GL_MAX_HEIGHT                                       0x827F
#define GL_MAX_DEPTH                                        0x8280
#define GL_MAX_LAYERS                                       0x8281
#define GL_MAX_COMBINED_DIMENSIONS                          0x8282
#define GL_COLOR_COMPONENTS                                 0x8283
#define GL_DEPTH_COMPONENTS                                 0x8284
#define GL_STENCIL_COMPONENTS                               0x8285
#define GL_COLOR_RENDERABLE                                 0x8286
#define GL_DEPTH_RENDERABLE                                 0x8287
#define GL_STENCIL_RENDERABLE                               0x8288
#define GL_FRAMEBUFFER_RENDERABLE                           0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED                   0x828A
#define GL_FRAMEBUFFER_BLEND                                0x828B
#define GL_READ_PIXELS                                      0x828C
#define GL_READ_PIXELS_FORMAT                               0x828D
#define GL_READ_PIXELS_TYPE                                 0x828E
#define GL_TEXTURE_IMAGE_FORMAT                             0x828F
#define GL_TEXTURE_IMAGE_TYPE                               0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT                         0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE                           0x8292
#define GL_MIPMAP                                           0x8293
#define GL_MANUAL_GENERATE_MIPMAP                           0x8294
#define GL_AUTO_GENERATE_MIPMAP                             0x8295
#define GL_COLOR_ENCODING                                   0x8296
#define GL_SRGB_READ                                        0x8297
#define GL_SRGB_WRITE                                       0x8298
#define GL_SRGB_DECODE_ARB                                  0x8299
#define GL_FILTER                                           0x829A
#define GL_VERTEX_TEXTURE                                   0x829B
#define GL_TESS_CONTROL_TEXTURE                             0x829C
#define GL_TESS_EVALUATION_TEXTURE                          0x829D
#define GL_GEOMETRY_TEXTURE                                 0x829E
#define GL_FRAGMENT_TEXTURE                                 0x829F
#define GL_COMPUTE_TEXTURE                                  0x82A0
#define GL_TEXTURE_SHADOW                                   0x82A1
#define GL_TEXTURE_GATHER                                   0x82A2
#define GL_TEXTURE_GATHER_SHADOW                            0x82A3
#define GL_SHADER_IMAGE_LOAD                                0x82A4
#define GL_SHADER_IMAGE_STORE                               0x82A5
#define GL_SHADER_IMAGE_ATOMIC                              0x82A6
#define GL_IMAGE_TEXEL_SIZE                                 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS                        0x82A8
#define GL_IMAGE_PIXEL_FORMAT                               0x82A9
#define GL_IMAGE_PIXEL_TYPE                                 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST              0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST            0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE             0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE           0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH                   0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT                  0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE                    0x82B3
#define GL_CLEAR_BUFFER                                     0x82B4
#define GL_TEXTURE_VIEW                                     0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS                         0x82B6
#define GL_FULL_SUPPORT                                     0x82B7
#define GL_CAVEAT_SUPPORT                                   0x82B8
#define GL_IMAGE_CLASS_4_X_32                               0x82B9
#define GL_IMAGE_CLASS_2_X_32                               0x82BA
#define GL_IMAGE_CLASS_1_X_32                               0x82BB
#define GL_IMAGE_CLASS_4_X_16                               0x82BC
#define GL_IMAGE_CLASS_2_X_16                               0x82BD
#define GL_IMAGE_CLASS_1_X_16                               0x82BE
#define GL_IMAGE_CLASS_4_X_8                                0x82BF
#define GL_IMAGE_CLASS_2_X_8                                0x82C0
#define GL_IMAGE_CLASS_1_X_8                                0x82C1
#define GL_IMAGE_CLASS_11_11_10                             0x82C2
#define GL_IMAGE_CLASS_10_10_10_2                           0x82C3
#define GL_VIEW_CLASS_128_BITS                              0x82C4
#define GL_VIEW_CLASS_96_BITS                               0x82C5
#define GL_VIEW_CLASS_64_BITS                               0x82C6
#define GL_VIEW_CLASS_48_BITS                               0x82C7
#define GL_VIEW_CLASS_32_BITS                               0x82C8
#define GL_VIEW_CLASS_24_BITS                               0x82C9
#define GL_VIEW_CLASS_16_BITS                               0x82CA
#define GL_VIEW_CLASS_8_BITS                                0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB                         0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA                        0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA                        0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA                        0x82CF
#define GL_VIEW_CLASS_RGTC1_RED                             0x82D0
#define GL_VIEW_CLASS_RGTC2_RG                              0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM                            0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT                            0x82D3
#endif

#ifndef GL_ARB_invalidate_subdata
#endif

#ifndef GL_ARB_multi_draw_indirect
#endif

#ifndef GL_ARB_program_interface_query
#define GL_UNIFORM                                          0x92E1
#define GL_UNIFORM_BLOCK                                    0x92E2
#define GL_PROGRAM_INPUT                                    0x92E3
#define GL_PROGRAM_OUTPUT                                   0x92E4
#define GL_BUFFER_VARIABLE                                  0x92E5
#define GL_SHADER_STORAGE_BLOCK                             0x92E6
/* reuse GL_ATOMIC_COUNTER_BUFFER */
#define GL_VERTEX_SUBROUTINE                                0x92E8
#define GL_TESS_CONTROL_SUBROUTINE                          0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE                       0x92EA
#define GL_GEOMETRY_SUBROUTINE                              0x92EB
#define GL_FRAGMENT_SUBROUTINE                              0x92EC
#define GL_COMPUTE_SUBROUTINE                               0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM                        0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM                  0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM               0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM                      0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM                      0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM                       0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING                       0x92F4
#define GL_ACTIVE_RESOURCES                                 0x92F5
#define GL_MAX_NAME_LENGTH                                  0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES                         0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES                   0x92F8
#define GL_NAME_LENGTH                                      0x92F9
#define GL_TYPE                                             0x92FA
#define GL_ARRAY_SIZE                                       0x92FB
#define GL_OFFSET                                           0x92FC
#define GL_BLOCK_INDEX                                      0x92FD
#define GL_ARRAY_STRIDE                                     0x92FE
#define GL_MATRIX_STRIDE                                    0x92FF
#define GL_IS_ROW_MAJOR                                     0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX                      0x9301
#define GL_BUFFER_BINDING                                   0x9302
#define GL_BUFFER_DATA_SIZE                                 0x9303
#define GL_NUM_ACTIVE_VARIABLES                             0x9304
#define GL_ACTIVE_VARIABLES                                 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER                      0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER                0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER             0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER                    0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER                    0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER                     0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE                             0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE                           0x930D
#define GL_LOCATION                                         0x930E
#define GL_LOCATION_INDEX                                   0x930F
#define GL_IS_PER_PATCH                                     0x92E7
/* reuse GL_NUM_COMPATIBLE_SUBROUTINES */
/* reuse GL_COMPATIBLE_SUBROUTINES */
#endif

#ifndef GL_ARB_robust_buffer_access_behavior
#endif

#ifndef GL_ARB_shader_image_size
#endif

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_SHADER_STORAGE_BUFFER                            0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING                    0x90D3
#define GL_SHADER_STORAGE_BUFFER_START                      0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE                       0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS                 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS               0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS           0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS        0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS               0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS                0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS               0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS               0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE                    0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT           0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT                       0x2000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES             GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
/* reuse GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS */
#endif

#ifndef GL_ARB_stencil_texturing
#define GL_DEPTH_STENCIL_TEXTURE_MODE                       0x90EA
#endif

#ifndef GL_ARB_texture_buffer_range
#define GL_TEXTURE_BUFFER_OFFSET                            0x919D
#define GL_TEXTURE_BUFFER_SIZE                              0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                  0x919F
#endif

#ifndef GL_ARB_texture_query_levels
#endif

#ifndef GL_ARB_texture_storage_multisample
#endif

#ifndef GL_EXT_abgr
#define GL_ABGR_EXT                                         0x8000
#endif

#ifndef GL_EXT_blend_color
#define GL_CONSTANT_COLOR_EXT                               0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT                     0x8002
#define GL_CONSTANT_ALPHA_EXT                               0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT                     0x8004
#define GL_BLEND_COLOR_EXT                                  0x8005
#endif

#ifndef GL_EXT_polygon_offset
#define GL_POLYGON_OFFSET_EXT                               0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT                        0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT                          0x8039
#endif

#ifndef GL_EXT_texture
#define GL_ALPHA4_EXT                                       0x803B
#define GL_ALPHA8_EXT                                       0x803C
#define GL_ALPHA12_EXT                                      0x803D
#define GL_ALPHA16_EXT                                      0x803E
#define GL_LUMINANCE4_EXT                                   0x803F
#define GL_LUMINANCE8_EXT                                   0x8040
#define GL_LUMINANCE12_EXT                                  0x8041
#define GL_LUMINANCE16_EXT                                  0x8042
#define GL_LUMINANCE4_ALPHA4_EXT                            0x8043
#define GL_LUMINANCE6_ALPHA2_EXT                            0x8044
#define GL_LUMINANCE8_ALPHA8_EXT                            0x8045
#define GL_LUMINANCE12_ALPHA4_EXT                           0x8046
#define GL_LUMINANCE12_ALPHA12_EXT                          0x8047
#define GL_LUMINANCE16_ALPHA16_EXT                          0x8048
#define GL_INTENSITY_EXT                                    0x8049
#define GL_INTENSITY4_EXT                                   0x804A
#define GL_INTENSITY8_EXT                                   0x804B
#define GL_INTENSITY12_EXT                                  0x804C
#define GL_INTENSITY16_EXT                                  0x804D
#define GL_RGB2_EXT                                         0x804E
#define GL_RGB4_EXT                                         0x804F
#define GL_RGB5_EXT                                         0x8050
#define GL_RGB8_EXT                                         0x8051
#define GL_RGB10_EXT                                        0x8052
#define GL_RGB12_EXT                                        0x8053
#define GL_RGB16_EXT                                        0x8054
#define GL_RGBA2_EXT                                        0x8055
#define GL_RGBA4_EXT                                        0x8056
#define GL_RGB5_A1_EXT                                      0x8057
#define GL_RGBA8_EXT                                        0x8058
#define GL_RGB10_A2_EXT                                     0x8059
#define GL_RGBA12_EXT                                       0x805A
#define GL_RGBA16_EXT                                       0x805B
#define GL_TEXTURE_RED_SIZE_EXT                             0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT                           0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT                            0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT                           0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT                       0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT                       0x8061
#define GL_REPLACE_EXT                                      0x8062
#define GL_PROXY_TEXTURE_1D_EXT                             0x8063
#define GL_PROXY_TEXTURE_2D_EXT                             0x8064
#define GL_TEXTURE_TOO_LARGE_EXT                            0x8065
#endif

#ifndef GL_EXT_texture3D
#define GL_PACK_SKIP_IMAGES_EXT                             0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT                            0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT                           0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT                          0x806E
#define GL_TEXTURE_3D_EXT                                   0x806F
#define GL_PROXY_TEXTURE_3D_EXT                             0x8070
#define GL_TEXTURE_DEPTH_EXT                                0x8071
#define GL_TEXTURE_WRAP_R_EXT                               0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT                          0x8073
#endif

#ifndef GL_SGIS_texture_filter4
#define GL_FILTER4_SGIS                                     0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS                        0x8147
#endif

#ifndef GL_EXT_subtexture
#endif

#ifndef GL_EXT_copy_texture
#endif

#ifndef GL_EXT_histogram
#define GL_HISTOGRAM_EXT                                    0x8024
#define GL_PROXY_HISTOGRAM_EXT                              0x8025
#define GL_HISTOGRAM_WIDTH_EXT                              0x8026
#define GL_HISTOGRAM_FORMAT_EXT                             0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT                           0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT                         0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT                          0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT                         0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT                     0x802C
#define GL_HISTOGRAM_SINK_EXT                               0x802D
#define GL_MINMAX_EXT                                       0x802E
#define GL_MINMAX_FORMAT_EXT                                0x802F
#define GL_MINMAX_SINK_EXT                                  0x8030
#define GL_TABLE_TOO_LARGE_EXT                              0x8031
#endif

#ifndef GL_EXT_convolution
#define GL_CONVOLUTION_1D_EXT                               0x8010
#define GL_CONVOLUTION_2D_EXT                               0x8011
#define GL_SEPARABLE_2D_EXT                                 0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT                      0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT                     0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT                      0x8015
#define GL_REDUCE_EXT                                       0x8016
#define GL_CONVOLUTION_FORMAT_EXT                           0x8017
#define GL_CONVOLUTION_WIDTH_EXT                            0x8018
#define GL_CONVOLUTION_HEIGHT_EXT                           0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT                        0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT                       0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT                   0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT                 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT                  0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT                 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT                    0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT                  0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT                   0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT                  0x8023
#endif

#ifndef GL_SGI_color_matrix
#define GL_COLOR_MATRIX_SGI                                 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI                     0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI                 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI                  0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI                0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI                 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI                0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI                   0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI                 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI                  0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI                 0x80BB
#endif

#ifndef GL_SGI_color_table
#define GL_COLOR_TABLE_SGI                                  0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI                 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI                0x80D2
#define GL_PROXY_COLOR_TABLE_SGI                            0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI           0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI          0x80D5
#define GL_COLOR_TABLE_SCALE_SGI                            0x80D6
#define GL_COLOR_TABLE_BIAS_SGI                             0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI                           0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI                            0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI                         0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI                       0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI                        0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI                       0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI                   0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI                   0x80DF
#endif

#ifndef GL_SGIS_pixel_texture
#define GL_PIXEL_TEXTURE_SGIS                               0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS                   0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS                 0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS                           0x8356
#endif

#ifndef GL_SGIX_pixel_texture
#define GL_PIXEL_TEX_GEN_SGIX                               0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX                          0x832B
#endif

#ifndef GL_SGIS_texture4D
#define GL_PACK_SKIP_VOLUMES_SGIS                           0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS                            0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS                         0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS                          0x8133
#define GL_TEXTURE_4D_SGIS                                  0x8134
#define GL_PROXY_TEXTURE_4D_SGIS                            0x8135
#define GL_TEXTURE_4DSIZE_SGIS                              0x8136
#define GL_TEXTURE_WRAP_Q_SGIS                              0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS                         0x8138
#define GL_TEXTURE_4D_BINDING_SGIS                          0x814F
#endif

#ifndef GL_SGI_texture_color_table
#define GL_TEXTURE_COLOR_TABLE_SGI                          0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI                    0x80BD
#endif

#ifndef GL_EXT_cmyka
#define GL_CMYK_EXT                                         0x800C
#define GL_CMYKA_EXT                                        0x800D
#define GL_PACK_CMYK_HINT_EXT                               0x800E
#define GL_UNPACK_CMYK_HINT_EXT                             0x800F
#endif

#ifndef GL_EXT_texture_object
#define GL_TEXTURE_PRIORITY_EXT                             0x8066
#define GL_TEXTURE_RESIDENT_EXT                             0x8067
#define GL_TEXTURE_1D_BINDING_EXT                           0x8068
#define GL_TEXTURE_2D_BINDING_EXT                           0x8069
#define GL_TEXTURE_3D_BINDING_EXT                           0x806A
#endif

#ifndef GL_SGIS_detail_texture
#define GL_DETAIL_TEXTURE_2D_SGIS                           0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS                   0x8096
#define GL_LINEAR_DETAIL_SGIS                               0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS                         0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS                         0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS                        0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS                         0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS                  0x809C
#endif

#ifndef GL_SGIS_sharpen_texture
#define GL_LINEAR_SHARPEN_SGIS                              0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS                        0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS                        0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS                 0x80B0
#endif

#ifndef GL_EXT_packed_pixels
#define GL_UNSIGNED_BYTE_3_3_2_EXT                          0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT                       0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT                       0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT                         0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT                      0x8036
#endif

#ifndef GL_SGIS_texture_lod
#define GL_TEXTURE_MIN_LOD_SGIS                             0x813A
#define GL_TEXTURE_MAX_LOD_SGIS                             0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS                          0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS                           0x813D
#endif

#ifndef GL_SGIS_multisample
#define GL_MULTISAMPLE_SGIS                                 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS                        0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS                         0x809F
#define GL_SAMPLE_MASK_SGIS                                 0x80A0
#define GL_1PASS_SGIS                                       0x80A1
#define GL_2PASS_0_SGIS                                     0x80A2
#define GL_2PASS_1_SGIS                                     0x80A3
#define GL_4PASS_0_SGIS                                     0x80A4
#define GL_4PASS_1_SGIS                                     0x80A5
#define GL_4PASS_2_SGIS                                     0x80A6
#define GL_4PASS_3_SGIS                                     0x80A7
#define GL_SAMPLE_BUFFERS_SGIS                              0x80A8
#define GL_SAMPLES_SGIS                                     0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS                           0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS                          0x80AB
#define GL_SAMPLE_PATTERN_SGIS                              0x80AC
#endif

#ifndef GL_EXT_rescale_normal
#define GL_RESCALE_NORMAL_EXT                               0x803A
#endif

#ifndef GL_EXT_vertex_array
#define GL_VERTEX_ARRAY_EXT                                 0x8074
#define GL_NORMAL_ARRAY_EXT                                 0x8075
#define GL_COLOR_ARRAY_EXT                                  0x8076
#define GL_INDEX_ARRAY_EXT                                  0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT                          0x8078
#define GL_EDGE_FLAG_ARRAY_EXT                              0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT                            0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT                            0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT                          0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT                           0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT                            0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT                          0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT                           0x8080
#define GL_COLOR_ARRAY_SIZE_EXT                             0x8081
#define GL_COLOR_ARRAY_TYPE_EXT                             0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT                           0x8083
#define GL_COLOR_ARRAY_COUNT_EXT                            0x8084
#define GL_INDEX_ARRAY_TYPE_EXT                             0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT                           0x8086
#define GL_INDEX_ARRAY_COUNT_EXT                            0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT                     0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT                     0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT                   0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT                    0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT                       0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT                        0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT                         0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT                         0x808F
#define GL_COLOR_ARRAY_POINTER_EXT                          0x8090
#define GL_INDEX_ARRAY_POINTER_EXT                          0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT                  0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT                      0x8093
#endif

#ifndef GL_EXT_misc_attribute
#endif

#ifndef GL_SGIS_generate_mipmap
#define GL_GENERATE_MIPMAP_SGIS                             0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS                        0x8192
#endif

#ifndef GL_SGIX_clipmap
#define GL_LINEAR_CLIPMAP_LINEAR_SGIX                       0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX                      0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX                       0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX                      0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX               0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX                  0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX                       0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX                           0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX                   0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX                     0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX                      0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX                      0x844F
#endif

#ifndef GL_SGIX_shadow
#define GL_TEXTURE_COMPARE_SGIX                             0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX                    0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX                            0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX                            0x819D
#endif

#ifndef GL_SGIS_texture_edge_clamp
#define GL_CLAMP_TO_EDGE_SGIS                               0x812F
#endif

#ifndef GL_SGIS_texture_border_clamp
#define GL_CLAMP_TO_BORDER_SGIS                             0x812D
#endif

#ifndef GL_EXT_blend_minmax
#define GL_FUNC_ADD_EXT                                     0x8006
#define GL_MIN_EXT                                          0x8007
#define GL_MAX_EXT                                          0x8008
#define GL_BLEND_EQUATION_EXT                               0x8009
#endif

#ifndef GL_EXT_blend_subtract
#define GL_FUNC_SUBTRACT_EXT                                0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT                        0x800B
#endif

#ifndef GL_EXT_blend_logic_op
#endif

#ifndef GL_SGIX_interlace
#define GL_INTERLACE_SGIX                                   0x8094
#endif

#ifndef GL_SGIX_pixel_tiles
#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX                   0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX                  0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX                            0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX                           0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX                       0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX                      0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX                       0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX                       0x8145
#endif

#ifndef GL_SGIS_texture_select
#define GL_DUAL_ALPHA4_SGIS                                 0x8110
#define GL_DUAL_ALPHA8_SGIS                                 0x8111
#define GL_DUAL_ALPHA12_SGIS                                0x8112
#define GL_DUAL_ALPHA16_SGIS                                0x8113
#define GL_DUAL_LUMINANCE4_SGIS                             0x8114
#define GL_DUAL_LUMINANCE8_SGIS                             0x8115
#define GL_DUAL_LUMINANCE12_SGIS                            0x8116
#define GL_DUAL_LUMINANCE16_SGIS                            0x8117
#define GL_DUAL_INTENSITY4_SGIS                             0x8118
#define GL_DUAL_INTENSITY8_SGIS                             0x8119
#define GL_DUAL_INTENSITY12_SGIS                            0x811A
#define GL_DUAL_INTENSITY16_SGIS                            0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS                       0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS                       0x811D
#define GL_QUAD_ALPHA4_SGIS                                 0x811E
#define GL_QUAD_ALPHA8_SGIS                                 0x811F
#define GL_QUAD_LUMINANCE4_SGIS                             0x8120
#define GL_QUAD_LUMINANCE8_SGIS                             0x8121
#define GL_QUAD_INTENSITY4_SGIS                             0x8122
#define GL_QUAD_INTENSITY8_SGIS                             0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS                         0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS                         0x8125
#endif

#ifndef GL_SGIX_sprite
#define GL_SPRITE_SGIX                                      0x8148
#define GL_SPRITE_MODE_SGIX                                 0x8149
#define GL_SPRITE_AXIS_SGIX                                 0x814A
#define GL_SPRITE_TRANSLATION_SGIX                          0x814B
#define GL_SPRITE_AXIAL_SGIX                                0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX                       0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX                          0x814E
#endif

#ifndef GL_SGIX_texture_multi_buffer
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX                   0x812E
#endif

#ifndef GL_EXT_point_parameters
#define GL_POINT_SIZE_MIN_EXT                               0x8126
#define GL_POINT_SIZE_MAX_EXT                               0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT                    0x8128
#define GL_DISTANCE_ATTENUATION_EXT                         0x8129
#endif

#ifndef GL_SGIS_point_parameters
#define GL_POINT_SIZE_MIN_SGIS                              0x8126
#define GL_POINT_SIZE_MAX_SGIS                              0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS                   0x8128
#define GL_DISTANCE_ATTENUATION_SGIS                        0x8129
#endif

#ifndef GL_SGIX_instruments
#define GL_INSTRUMENT_BUFFER_POINTER_SGIX                   0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX                     0x8181
#endif

#ifndef GL_SGIX_texture_scale_bias
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX                    0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX                   0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX              0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX             0x817C
#endif

#ifndef GL_SGIX_framezoom
#define GL_FRAMEZOOM_SGIX                                   0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX                            0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX                        0x818D
#endif

#ifndef GL_SGIX_tag_sample_buffer
#endif

#ifndef GL_FfdMaskSGIX
#define GL_TEXTURE_DEFORMATION_BIT_SGIX                     0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX                    0x00000002
#endif

#ifndef GL_SGIX_polynomial_ffd
#define GL_GEOMETRY_DEFORMATION_SGIX                        0x8194
#define GL_TEXTURE_DEFORMATION_SGIX                         0x8195
#define GL_DEFORMATIONS_MASK_SGIX                           0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX                       0x8197
#endif

#ifndef GL_SGIX_reference_plane
#define GL_REFERENCE_PLANE_SGIX                             0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX                    0x817E
#endif

#ifndef GL_SGIX_flush_raster
#endif

#ifndef GL_SGIX_depth_texture
#define GL_DEPTH_COMPONENT16_SGIX                           0x81A5
#define GL_DEPTH_COMPONENT24_SGIX                           0x81A6
#define GL_DEPTH_COMPONENT32_SGIX                           0x81A7
#endif

#ifndef GL_SGIS_fog_function
#define GL_FOG_FUNC_SGIS                                    0x812A
#define GL_FOG_FUNC_POINTS_SGIS                             0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS                         0x812C
#endif

#ifndef GL_SGIX_fog_offset
#define GL_FOG_OFFSET_SGIX                                  0x8198
#define GL_FOG_OFFSET_VALUE_SGIX                            0x8199
#endif

#ifndef GL_HP_image_transform
#define GL_IMAGE_SCALE_X_HP                                 0x8155
#define GL_IMAGE_SCALE_Y_HP                                 0x8156
#define GL_IMAGE_TRANSLATE_X_HP                             0x8157
#define GL_IMAGE_TRANSLATE_Y_HP                             0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP                            0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP                         0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP                         0x815B
#define GL_IMAGE_MAG_FILTER_HP                              0x815C
#define GL_IMAGE_MIN_FILTER_HP                              0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP                            0x815E
#define GL_CUBIC_HP                                         0x815F
#define GL_AVERAGE_HP                                       0x8160
#define GL_IMAGE_TRANSFORM_2D_HP                            0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP              0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP        0x8163
#endif

#ifndef GL_HP_convolution_border_modes
#define GL_IGNORE_BORDER_HP                                 0x8150
#define GL_CONSTANT_BORDER_HP                               0x8151
#define GL_REPLICATE_BORDER_HP                              0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP                      0x8154
#endif

#ifndef GL_INGR_palette_buffer
#endif

#ifndef GL_SGIX_texture_add_env
#define GL_TEXTURE_ENV_BIAS_SGIX                            0x80BE
#endif

#ifndef GL_EXT_color_subtable
#endif

#ifndef GL_PGI_vertex_hints
#define GL_VERTEX_DATA_HINT_PGI                             0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI                       0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI                           0x1A22C
#define GL_MAX_VERTEX_HINT_PGI                              0x1A22D
#define GL_COLOR3_BIT_PGI                                   0x00010000
#define GL_COLOR4_BIT_PGI                                   0x00020000
#define GL_EDGEFLAG_BIT_PGI                                 0x00040000
#define GL_INDEX_BIT_PGI                                    0x00080000
#define GL_MAT_AMBIENT_BIT_PGI                              0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI                  0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI                              0x00400000
#define GL_MAT_EMISSION_BIT_PGI                             0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI                        0x01000000
#define GL_MAT_SHININESS_BIT_PGI                            0x02000000
#define GL_MAT_SPECULAR_BIT_PGI                             0x04000000
#define GL_NORMAL_BIT_PGI                                   0x08000000
#define GL_TEXCOORD1_BIT_PGI                                0x10000000
#define GL_TEXCOORD2_BIT_PGI                                0x20000000
#define GL_TEXCOORD3_BIT_PGI                                0x40000000
#define GL_TEXCOORD4_BIT_PGI                                0x80000000
#define GL_VERTEX23_BIT_PGI                                 0x00000004
#define GL_VERTEX4_BIT_PGI                                  0x00000008
#endif

#ifndef GL_PGI_misc_hints
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI                     0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI                         0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI                          0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI                       0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI                   0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI                     0x1A204
#define GL_ALWAYS_FAST_HINT_PGI                             0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI                             0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI                          0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI                          0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI                          0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI                          0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI                        0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI                         0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI                          0x1A218
#define GL_FULL_STIPPLE_HINT_PGI                            0x1A219
#define GL_CLIP_NEAR_HINT_PGI                               0x1A220
#define GL_CLIP_FAR_HINT_PGI                                0x1A221
#define GL_WIDE_LINE_HINT_PGI                               0x1A222
#define GL_BACK_NORMALS_HINT_PGI                            0x1A223
#endif

#ifndef GL_EXT_paletted_texture
#define GL_COLOR_INDEX1_EXT                                 0x80E2
#define GL_COLOR_INDEX2_EXT                                 0x80E3
#define GL_COLOR_INDEX4_EXT                                 0x80E4
#define GL_COLOR_INDEX8_EXT                                 0x80E5
#define GL_COLOR_INDEX12_EXT                                0x80E6
#define GL_COLOR_INDEX16_EXT                                0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT                           0x80ED
#endif

#ifndef GL_EXT_clip_volume_hint
#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT                    0x80F0
#endif

#ifndef GL_SGIX_list_priority
#define GL_LIST_PRIORITY_SGIX                               0x8182
#endif

#ifndef GL_SGIX_ir_instrument1
#define GL_IR_INSTRUMENT1_SGIX                              0x817F
#endif

#ifndef GL_SGIX_calligraphic_fragment
#define GL_CALLIGRAPHIC_FRAGMENT_SGIX                       0x8183
#endif

#ifndef GL_SGIX_texture_lod_bias
#define GL_TEXTURE_LOD_BIAS_S_SGIX                          0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX                          0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX                          0x8190
#endif

#ifndef GL_SGIX_shadow_ambient
#define GL_SHADOW_AMBIENT_SGIX                              0x80BF
#endif

#ifndef GL_EXT_index_texture
#endif

#ifndef GL_EXT_index_material
#define GL_INDEX_MATERIAL_EXT                               0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT                     0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT                          0x81BA
#endif

#ifndef GL_EXT_index_func
#define GL_INDEX_TEST_EXT                                   0x81B5
#define GL_INDEX_TEST_FUNC_EXT                              0x81B6
#define GL_INDEX_TEST_REF_EXT                               0x81B7
#endif

#ifndef GL_EXT_index_array_formats
#define GL_IUI_V2F_EXT                                      0x81AD
#define GL_IUI_V3F_EXT                                      0x81AE
#define GL_IUI_N3F_V2F_EXT                                  0x81AF
#define GL_IUI_N3F_V3F_EXT                                  0x81B0
#define GL_T2F_IUI_V2F_EXT                                  0x81B1
#define GL_T2F_IUI_V3F_EXT                                  0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT                              0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT                              0x81B4
#endif

#ifndef GL_EXT_compiled_vertex_array
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT                     0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT                     0x81A9
#endif

#ifndef GL_EXT_cull_vertex
#define GL_CULL_VERTEX_EXT                                  0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT                     0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT                  0x81AC
#endif

#ifndef GL_SGIX_ycrcb
#define GL_YCRCB_422_SGIX                                   0x81BB
#define GL_YCRCB_444_SGIX                                   0x81BC
#endif

#ifndef GL_SGIX_fragment_lighting
#define GL_FRAGMENT_LIGHTING_SGIX                           0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX                     0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX                0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX           0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX                         0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX                           0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX                       0x8406
#define GL_LIGHT_ENV_MODE_SGIX                              0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX           0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX               0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX                0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX   0x840B
#define GL_FRAGMENT_LIGHT0_SGIX                             0x840C
#define GL_FRAGMENT_LIGHT1_SGIX                             0x840D
#define GL_FRAGMENT_LIGHT2_SGIX                             0x840E
#define GL_FRAGMENT_LIGHT3_SGIX                             0x840F
#define GL_FRAGMENT_LIGHT4_SGIX                             0x8410
#define GL_FRAGMENT_LIGHT5_SGIX                             0x8411
#define GL_FRAGMENT_LIGHT6_SGIX                             0x8412
#define GL_FRAGMENT_LIGHT7_SGIX                             0x8413
#endif

#ifndef GL_IBM_rasterpos_clip
#define GL_RASTER_POSITION_UNCLIPPED_IBM                    0x19262
#endif

#ifndef GL_HP_texture_lighting
#define GL_TEXTURE_LIGHTING_MODE_HP                         0x8167
#define GL_TEXTURE_POST_SPECULAR_HP                         0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP                          0x8169
#endif

#ifndef GL_EXT_draw_range_elements
#define GL_MAX_ELEMENTS_VERTICES_EXT                        0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT                         0x80E9
#endif

#ifndef GL_WIN_phong_shading
#define GL_PHONG_WIN                                        0x80EA
#define GL_PHONG_HINT_WIN                                   0x80EB
#endif

#ifndef GL_WIN_specular_fog
#define GL_FOG_SPECULAR_TEXTURE_WIN                         0x80EC
#endif

#ifndef GL_EXT_light_texture
#define GL_FRAGMENT_MATERIAL_EXT                            0x8349
#define GL_FRAGMENT_NORMAL_EXT                              0x834A
#define GL_FRAGMENT_COLOR_EXT                               0x834C
#define GL_ATTENUATION_EXT                                  0x834D
#define GL_SHADOW_ATTENUATION_EXT                           0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT                     0x834F
#define GL_TEXTURE_LIGHT_EXT                                0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT                        0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT                   0x8352
/* reuse GL_FRAGMENT_DEPTH_EXT */
#endif

#ifndef GL_SGIX_blend_alpha_minmax
#define GL_ALPHA_MIN_SGIX                                   0x8320
#define GL_ALPHA_MAX_SGIX                                   0x8321
#endif

#ifndef GL_SGIX_impact_pixel_texture
#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX                     0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX                       0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX                       0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX                 0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX              0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX                      0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX                      0x818A
#endif

#ifndef GL_EXT_bgra
#define GL_BGR_EXT                                          0x80E0
#define GL_BGRA_EXT                                         0x80E1
#endif

#ifndef GL_SGIX_async
#define GL_ASYNC_MARKER_SGIX                                0x8329
#endif

#ifndef GL_SGIX_async_pixel
#define GL_ASYNC_TEX_IMAGE_SGIX                             0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX                           0x835D
#define GL_ASYNC_READ_PIXELS_SGIX                           0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX                         0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX                       0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX                       0x8361
#endif

#ifndef GL_SGIX_async_histogram
#define GL_ASYNC_HISTOGRAM_SGIX                             0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX                         0x832D
#endif

#ifndef GL_INTEL_texture_scissor
#endif

#ifndef GL_INTEL_parallel_arrays
#define GL_PARALLEL_ARRAYS_INTEL                            0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL             0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL             0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL              0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL      0x83F8
#endif

#ifndef GL_HP_occlusion_test
#define GL_OCCLUSION_TEST_HP                                0x8165
#define GL_OCCLUSION_TEST_RESULT_HP                         0x8166
#endif

#ifndef GL_EXT_pixel_transform
#define GL_PIXEL_TRANSFORM_2D_EXT                           0x8330
#define GL_PIXEL_MAG_FILTER_EXT                             0x8331
#define GL_PIXEL_MIN_FILTER_EXT                             0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT                           0x8333
#define GL_CUBIC_EXT                                        0x8334
#define GL_AVERAGE_EXT                                      0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT               0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT           0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT                    0x8338
#endif

#ifndef GL_EXT_pixel_transform_color_table
#endif

#ifndef GL_EXT_shared_texture_palette
#define GL_SHARED_TEXTURE_PALETTE_EXT                       0x81FB
#endif

#ifndef GL_EXT_separate_specular_color
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT                    0x81F8
#define GL_SINGLE_COLOR_EXT                                 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT                      0x81FA
#endif

#ifndef GL_EXT_secondary_color
#define GL_COLOR_SUM_EXT                                    0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT                      0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT                   0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT                   0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT                 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT                0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT                        0x845E
#endif

#ifndef GL_EXT_texture_perturb_normal
#define GL_PERTURB_EXT                                      0x85AE
#define GL_TEXTURE_NORMAL_EXT                               0x85AF
#endif

#ifndef GL_EXT_multi_draw_arrays
#endif

#ifndef GL_EXT_fog_coord
#define GL_FOG_COORDINATE_SOURCE_EXT                        0x8450
#define GL_FOG_COORDINATE_EXT                               0x8451
#define GL_FRAGMENT_DEPTH_EXT                               0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT                       0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT                    0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT                  0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT                 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT                         0x8457
#endif

#ifndef GL_REND_screen_coordinates
#define GL_SCREEN_COORDINATES_REND                          0x8490
#define GL_INVERTED_SCREEN_W_REND                           0x8491
#endif

#ifndef GL_EXT_coordinate_frame
#define GL_TANGENT_ARRAY_EXT                                0x8439
#define GL_BINORMAL_ARRAY_EXT                               0x843A
#define GL_CURRENT_TANGENT_EXT                              0x843B
#define GL_CURRENT_BINORMAL_EXT                             0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT                           0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT                         0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT                          0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT                        0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT                        0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT                       0x8443
#define GL_MAP1_TANGENT_EXT                                 0x8444
#define GL_MAP2_TANGENT_EXT                                 0x8445
#define GL_MAP1_BINORMAL_EXT                                0x8446
#define GL_MAP2_BINORMAL_EXT                                0x8447
#endif

#ifndef GL_EXT_texture_env_combine
#define GL_COMBINE_EXT                                      0x8570
#define GL_COMBINE_RGB_EXT                                  0x8571
#define GL_COMBINE_ALPHA_EXT                                0x8572
#define GL_RGB_SCALE_EXT                                    0x8573
#define GL_ADD_SIGNED_EXT                                   0x8574
#define GL_INTERPOLATE_EXT                                  0x8575
#define GL_CONSTANT_EXT                                     0x8576
#define GL_PRIMARY_COLOR_EXT                                0x8577
#define GL_PREVIOUS_EXT                                     0x8578
#define GL_SOURCE0_RGB_EXT                                  0x8580
#define GL_SOURCE1_RGB_EXT                                  0x8581
#define GL_SOURCE2_RGB_EXT                                  0x8582
#define GL_SOURCE0_ALPHA_EXT                                0x8588
#define GL_SOURCE1_ALPHA_EXT                                0x8589
#define GL_SOURCE2_ALPHA_EXT                                0x858A
#define GL_OPERAND0_RGB_EXT                                 0x8590
#define GL_OPERAND1_RGB_EXT                                 0x8591
#define GL_OPERAND2_RGB_EXT                                 0x8592
#define GL_OPERAND0_ALPHA_EXT                               0x8598
#define GL_OPERAND1_ALPHA_EXT                               0x8599
#define GL_OPERAND2_ALPHA_EXT                               0x859A
#endif

#ifndef GL_APPLE_specular_vector
#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE                0x85B0
#endif

#ifndef GL_APPLE_transform_hint
#define GL_TRANSFORM_HINT_APPLE                             0x85B1
#endif

#ifndef GL_SGIX_fog_scale
#define GL_FOG_SCALE_SGIX                                   0x81FC
#define GL_FOG_SCALE_VALUE_SGIX                             0x81FD
#endif

#ifndef GL_SUNX_constant_data
#define GL_UNPACK_CONSTANT_DATA_SUNX                        0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX                       0x81D6
#endif

#ifndef GL_SUN_global_alpha
#define GL_GLOBAL_ALPHA_SUN                                 0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN                          0x81DA
#endif

#ifndef GL_SUN_triangle_list
#define GL_RESTART_SUN                                      0x0001
#define GL_REPLACE_MIDDLE_SUN                               0x0002
#define GL_REPLACE_OLDEST_SUN                               0x0003
#define GL_TRIANGLE_LIST_SUN                                0x81D7
#define GL_REPLACEMENT_CODE_SUN                             0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN                       0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN                  0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN                0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN               0x85C3
#define GL_R1UI_V3F_SUN                                     0x85C4
#define GL_R1UI_C4UB_V3F_SUN                                0x85C5
#define GL_R1UI_C3F_V3F_SUN                                 0x85C6
#define GL_R1UI_N3F_V3F_SUN                                 0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN                             0x85C8
#define GL_R1UI_T2F_V3F_SUN                                 0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN                             0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN                         0x85CB
#endif

#ifndef GL_SUN_vertex
#endif

#ifndef GL_EXT_blend_func_separate
#define GL_BLEND_DST_RGB_EXT                                0x80C8
#define GL_BLEND_SRC_RGB_EXT                                0x80C9
#define GL_BLEND_DST_ALPHA_EXT                              0x80CA
#define GL_BLEND_SRC_ALPHA_EXT                              0x80CB
#endif

#ifndef GL_INGR_color_clamp
#define GL_RED_MIN_CLAMP_INGR                               0x8560
#define GL_GREEN_MIN_CLAMP_INGR                             0x8561
#define GL_BLUE_MIN_CLAMP_INGR                              0x8562
#define GL_ALPHA_MIN_CLAMP_INGR                             0x8563
#define GL_RED_MAX_CLAMP_INGR                               0x8564
#define GL_GREEN_MAX_CLAMP_INGR                             0x8565
#define GL_BLUE_MAX_CLAMP_INGR                              0x8566
#define GL_ALPHA_MAX_CLAMP_INGR                             0x8567
#endif

#ifndef GL_INGR_interlace_read
#define GL_INTERLACE_READ_INGR                              0x8568
#endif

#ifndef GL_EXT_stencil_wrap
#define GL_INCR_WRAP_EXT                                    0x8507
#define GL_DECR_WRAP_EXT                                    0x8508
#endif

#ifndef GL_EXT_422_pixels
#define GL_422_EXT                                          0x80CC
#define GL_422_REV_EXT                                      0x80CD
#define GL_422_AVERAGE_EXT                                  0x80CE
#define GL_422_REV_AVERAGE_EXT                              0x80CF
#endif

#ifndef GL_NV_texgen_reflection
#define GL_NORMAL_MAP_NV                                    0x8511
#define GL_REFLECTION_MAP_NV                                0x8512
#endif

#ifndef GL_EXT_texture_cube_map
#define GL_NORMAL_MAP_EXT                                   0x8511
#define GL_REFLECTION_MAP_EXT                               0x8512
#define GL_TEXTURE_CUBE_MAP_EXT                             0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT                     0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT                  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT                  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT                  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT                  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT                  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT                  0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT                       0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT                    0x851C
#endif

#ifndef GL_SUN_convolution_border_modes
#define GL_WRAP_BORDER_SUN                                  0x81D4
#endif

#ifndef GL_EXT_texture_env_add
#endif

#ifndef GL_EXT_texture_lod_bias
#define GL_MAX_TEXTURE_LOD_BIAS_EXT                         0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT                       0x8500
#define GL_TEXTURE_LOD_BIAS_EXT                             0x8501
#endif

#ifndef GL_EXT_texture_filter_anisotropic
#define GL_TEXTURE_MAX_ANISOTROPY_EXT                       0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT                   0x84FF
#endif

#ifndef GL_EXT_vertex_weighting
#define GL_MODELVIEW0_STACK_DEPTH_EXT                       GL_MODELVIEW_STACK_DEPTH
#define GL_MODELVIEW1_STACK_DEPTH_EXT                       0x8502
#define GL_MODELVIEW0_MATRIX_EXT                            GL_MODELVIEW_MATRIX
#define GL_MODELVIEW1_MATRIX_EXT                            0x8506
#define GL_VERTEX_WEIGHTING_EXT                             0x8509
#define GL_MODELVIEW0_EXT                                   GL_MODELVIEW
#define GL_MODELVIEW1_EXT                                   0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT                        0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT                          0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT                     0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT                     0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT                   0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT                  0x8510
#endif

#ifndef GL_NV_light_max_exponent
#define GL_MAX_SHININESS_NV                                 0x8504
#define GL_MAX_SPOT_EXPONENT_NV                             0x8505
#endif

#ifndef GL_NV_vertex_array_range
#define GL_VERTEX_ARRAY_RANGE_NV                            0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV                     0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV                      0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV                0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV                    0x8521
#endif

#ifndef GL_NV_register_combiners
#define GL_REGISTER_COMBINERS_NV                            0x8522
#define GL_VARIABLE_A_NV                                    0x8523
#define GL_VARIABLE_B_NV                                    0x8524
#define GL_VARIABLE_C_NV                                    0x8525
#define GL_VARIABLE_D_NV                                    0x8526
#define GL_VARIABLE_E_NV                                    0x8527
#define GL_VARIABLE_F_NV                                    0x8528
#define GL_VARIABLE_G_NV                                    0x8529
#define GL_CONSTANT_COLOR0_NV                               0x852A
#define GL_CONSTANT_COLOR1_NV                               0x852B
#define GL_PRIMARY_COLOR_NV                                 0x852C
#define GL_SECONDARY_COLOR_NV                               0x852D
#define GL_SPARE0_NV                                        0x852E
#define GL_SPARE1_NV                                        0x852F
#define GL_DISCARD_NV                                       0x8530
#define GL_E_TIMES_F_NV                                     0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV                   0x8532
#define GL_UNSIGNED_IDENTITY_NV                             0x8536
#define GL_UNSIGNED_INVERT_NV                               0x8537
#define GL_EXPAND_NORMAL_NV                                 0x8538
#define GL_EXPAND_NEGATE_NV                                 0x8539
#define GL_HALF_BIAS_NORMAL_NV                              0x853A
#define GL_HALF_BIAS_NEGATE_NV                              0x853B
#define GL_SIGNED_IDENTITY_NV                               0x853C
#define GL_SIGNED_NEGATE_NV                                 0x853D
#define GL_SCALE_BY_TWO_NV                                  0x853E
#define GL_SCALE_BY_FOUR_NV                                 0x853F
#define GL_SCALE_BY_ONE_HALF_NV                             0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV                     0x8541
#define GL_COMBINER_INPUT_NV                                0x8542
#define GL_COMBINER_MAPPING_NV                              0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV                      0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV                       0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV                       0x8546
#define GL_COMBINER_MUX_SUM_NV                              0x8547
#define GL_COMBINER_SCALE_NV                                0x8548
#define GL_COMBINER_BIAS_NV                                 0x8549
#define GL_COMBINER_AB_OUTPUT_NV                            0x854A
#define GL_COMBINER_CD_OUTPUT_NV                            0x854B
#define GL_COMBINER_SUM_OUTPUT_NV                           0x854C
#define GL_MAX_GENERAL_COMBINERS_NV                         0x854D
#define GL_NUM_GENERAL_COMBINERS_NV                         0x854E
#define GL_COLOR_SUM_CLAMP_NV                               0x854F
#define GL_COMBINER0_NV                                     0x8550
#define GL_COMBINER1_NV                                     0x8551
#define GL_COMBINER2_NV                                     0x8552
#define GL_COMBINER3_NV                                     0x8553
#define GL_COMBINER4_NV                                     0x8554
#define GL_COMBINER5_NV                                     0x8555
#define GL_COMBINER6_NV                                     0x8556
#define GL_COMBINER7_NV                                     0x8557
/* reuse GL_TEXTURE0_ARB */
/* reuse GL_TEXTURE1_ARB */
/* reuse GL_ZERO */
/* reuse GL_NONE */
/* reuse GL_FOG */
#endif

#ifndef GL_NV_fog_distance
#define GL_FOG_DISTANCE_MODE_NV                             0x855A
#define GL_EYE_RADIAL_NV                                    0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV                            0x855C
/* reuse GL_EYE_PLANE */
#endif

#ifndef GL_NV_texgen_emboss
#define GL_EMBOSS_LIGHT_NV                                  0x855D
#define GL_EMBOSS_CONSTANT_NV                               0x855E
#define GL_EMBOSS_MAP_NV                                    0x855F
#endif

#ifndef GL_NV_blend_square
#endif

#ifndef GL_NV_texture_env_combine4
#define GL_COMBINE4_NV                                      0x8503
#define GL_SOURCE3_RGB_NV                                   0x8583
#define GL_SOURCE3_ALPHA_NV                                 0x858B
#define GL_OPERAND3_RGB_NV                                  0x8593
#define GL_OPERAND3_ALPHA_NV                                0x859B
#endif

#ifndef GL_MESA_resize_buffers
#endif

#ifndef GL_MESA_window_pos
#endif

#ifndef GL_EXT_texture_compression_s3tc
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT                     0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT                    0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT                    0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT                    0x83F3
#endif

#ifndef GL_IBM_cull_vertex
#define GL_CULL_VERTEX_IBM                                  103050
#endif

#ifndef GL_IBM_multimode_draw_arrays
#endif

#ifndef GL_IBM_vertex_array_lists
#define GL_VERTEX_ARRAY_LIST_IBM                            103070
#define GL_NORMAL_ARRAY_LIST_IBM                            103071
#define GL_COLOR_ARRAY_LIST_IBM                             103072
#define GL_INDEX_ARRAY_LIST_IBM                             103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM                     103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM                         103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM                    103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM                   103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM                     103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM                     103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM                      103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM                      103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM              103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM                  103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM             103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM            103087
#endif

#ifndef GL_SGIX_subsample
#define GL_PACK_SUBSAMPLE_RATE_SGIX                         0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX                       0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX                        0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX                        0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX                        0x85A4
#endif

#ifndef GL_SGIX_ycrcb_subsample
#define GL_PACK_SUBSAMPLE_RATE_SGIX                         0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX                       0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX                        0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX                        0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX                        0x85A4
#endif

#ifndef GL_SGIX_ycrcba
#define GL_YCRCB_SGIX                                       0x8318
#define GL_YCRCBA_SGIX                                      0x8319
#endif

#ifndef GL_SGI_depth_pass_instrument
#define GL_DEPTH_PASS_INSTRUMENT_SGIX                       0x8310
#define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX              0x8311
#define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX                   0x8312
#endif

#ifndef GL_3DFX_texture_compression_FXT1
#define GL_COMPRESSED_RGB_FXT1_3DFX                         0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX                        0x86B1
#endif

#ifndef GL_3DFX_multisample
#define GL_MULTISAMPLE_3DFX                                 0x86B2
#define GL_SAMPLE_BUFFERS_3DFX                              0x86B3
#define GL_SAMPLES_3DFX                                     0x86B4
#define GL_MULTISAMPLE_BIT_3DFX                             0x20000000
#endif

#ifndef GL_3DFX_tbuffer
#endif

#ifndef GL_EXT_multisample
#define GL_MULTISAMPLE_EXT                                  0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT                         0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT                          0x809F
#define GL_SAMPLE_MASK_EXT                                  0x80A0
#define GL_1PASS_EXT                                        0x80A1
#define GL_2PASS_0_EXT                                      0x80A2
#define GL_2PASS_1_EXT                                      0x80A3
#define GL_4PASS_0_EXT                                      0x80A4
#define GL_4PASS_1_EXT                                      0x80A5
#define GL_4PASS_2_EXT                                      0x80A6
#define GL_4PASS_3_EXT                                      0x80A7
#define GL_SAMPLE_BUFFERS_EXT                               0x80A8
#define GL_SAMPLES_EXT                                      0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT                            0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT                           0x80AB
#define GL_SAMPLE_PATTERN_EXT                               0x80AC
#define GL_MULTISAMPLE_BIT_EXT                              0x20000000
#endif

#ifndef GL_SGIX_vertex_preclip
#define GL_VERTEX_PRECLIP_SGIX                              0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX                         0x83EF
#endif

#ifndef GL_SGIX_convolution_accuracy
#define GL_CONVOLUTION_HINT_SGIX                            0x8316
#endif

#ifndef GL_SGIX_resample
#define GL_PACK_RESAMPLE_SGIX                               0x842C
#define GL_UNPACK_RESAMPLE_SGIX                             0x842D
#define GL_RESAMPLE_REPLICATE_SGIX                          0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX                          0x842F
#define GL_RESAMPLE_DECIMATE_SGIX                           0x8430
#endif

#ifndef GL_SGIS_point_line_texgen
#define GL_EYE_DISTANCE_TO_POINT_SGIS                       0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS                    0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS                        0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS                     0x81F3
#define GL_EYE_POINT_SGIS                                   0x81F4
#define GL_OBJECT_POINT_SGIS                                0x81F5
#define GL_EYE_LINE_SGIS                                    0x81F6
#define GL_OBJECT_LINE_SGIS                                 0x81F7
#endif

#ifndef GL_SGIS_texture_color_mask
#define GL_TEXTURE_COLOR_WRITEMASK_SGIS                     0x81EF
#endif

#ifndef GL_EXT_texture_env_dot3
#define GL_DOT3_RGB_EXT                                     0x8740
#define GL_DOT3_RGBA_EXT                                    0x8741
#endif

#ifndef GL_ATI_texture_mirror_once
#define GL_MIRROR_CLAMP_ATI                                 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI                         0x8743
#endif

#ifndef GL_NV_fence
#define GL_ALL_COMPLETED_NV                                 0x84F2
#define GL_FENCE_STATUS_NV                                  0x84F3
#define GL_FENCE_CONDITION_NV                               0x84F4
#endif

#ifndef GL_IBM_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_IBM                              0x8370
#endif

#ifndef GL_NV_evaluators
#define GL_EVAL_2D_NV                                       0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV                            0x86C1
#define GL_MAP_TESSELLATION_NV                              0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV                            0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV                            0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV                  0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV                           0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV                           0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV                           0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV                           0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV                           0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV                           0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV                           0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV                           0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV                           0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV                           0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV                          0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV                          0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV                          0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV                          0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV                          0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV                          0x86D5
#define GL_MAX_MAP_TESSELLATION_NV                          0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV                       0x86D7
#endif

#ifndef GL_NV_packed_depth_stencil
#define GL_DEPTH_STENCIL_NV                                 0x84F9
#define GL_UNSIGNED_INT_24_8_NV                             0x84FA
#endif

#ifndef GL_NV_register_combiners2
#define GL_PER_STAGE_CONSTANTS_NV                           0x8535
#endif

#ifndef GL_NV_texture_compression_vtc
#endif

#ifndef GL_NV_texture_rectangle
#define GL_TEXTURE_RECTANGLE_NV                             0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV                     0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV                       0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV                    0x84F8
#endif

#ifndef GL_NV_texture_shader
#define GL_OFFSET_TEXTURE_RECTANGLE_NV                      0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV                0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV                 0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV             0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV                        0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV                    0x86DB
#define GL_DSDT_MAG_INTENSITY_NV                            0x86DC
#define GL_SHADER_CONSISTENT_NV                             0x86DD
#define GL_TEXTURE_SHADER_NV                                0x86DE
#define GL_SHADER_OPERATION_NV                              0x86DF
#define GL_CULL_MODES_NV                                    0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV                         0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV                          0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV                           0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV                      GL_OFFSET_TEXTURE_MATRIX_NV
#define GL_OFFSET_TEXTURE_2D_SCALE_NV                       GL_OFFSET_TEXTURE_SCALE_NV
#define GL_OFFSET_TEXTURE_2D_BIAS_NV                        GL_OFFSET_TEXTURE_BIAS_NV
#define GL_PREVIOUS_TEXTURE_INPUT_NV                        0x86E4
#define GL_CONST_EYE_NV                                     0x86E5
#define GL_PASS_THROUGH_NV                                  0x86E6
#define GL_CULL_FRAGMENT_NV                                 0x86E7
#define GL_OFFSET_TEXTURE_2D_NV                             0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV                       0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV                       0x86EA
#define GL_DOT_PRODUCT_NV                                   0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV                     0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV                        0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV                  0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV                  0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV                  0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV        0x86F3
#define GL_HILO_NV                                          0x86F4
#define GL_DSDT_NV                                          0x86F5
#define GL_DSDT_MAG_NV                                      0x86F6
#define GL_DSDT_MAG_VIB_NV                                  0x86F7
#define GL_HILO16_NV                                        0x86F8
#define GL_SIGNED_HILO_NV                                   0x86F9
#define GL_SIGNED_HILO16_NV                                 0x86FA
#define GL_SIGNED_RGBA_NV                                   0x86FB
#define GL_SIGNED_RGBA8_NV                                  0x86FC
#define GL_SIGNED_RGB_NV                                    0x86FE
#define GL_SIGNED_RGB8_NV                                   0x86FF
#define GL_SIGNED_LUMINANCE_NV                              0x8701
#define GL_SIGNED_LUMINANCE8_NV                             0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV                        0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV                      0x8704
#define GL_SIGNED_ALPHA_NV                                  0x8705
#define GL_SIGNED_ALPHA8_NV                                 0x8706
#define GL_SIGNED_INTENSITY_NV                              0x8707
#define GL_SIGNED_INTENSITY8_NV                             0x8708
#define GL_DSDT8_NV                                         0x8709
#define GL_DSDT8_MAG8_NV                                    0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV                         0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV                     0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV                   0x870D
#define GL_HI_SCALE_NV                                      0x870E
#define GL_LO_SCALE_NV                                      0x870F
#define GL_DS_SCALE_NV                                      0x8710
#define GL_DT_SCALE_NV                                      0x8711
#define GL_MAGNITUDE_SCALE_NV                               0x8712
#define GL_VIBRANCE_SCALE_NV                                0x8713
#define GL_HI_BIAS_NV                                       0x8714
#define GL_LO_BIAS_NV                                       0x8715
#define GL_DS_BIAS_NV                                       0x8716
#define GL_DT_BIAS_NV                                       0x8717
#define GL_MAGNITUDE_BIAS_NV                                0x8718
#define GL_VIBRANCE_BIAS_NV                                 0x8719
#define GL_TEXTURE_BORDER_VALUES_NV                         0x871A
#define GL_TEXTURE_HI_SIZE_NV                               0x871B
#define GL_TEXTURE_LO_SIZE_NV                               0x871C
#define GL_TEXTURE_DS_SIZE_NV                               0x871D
#define GL_TEXTURE_DT_SIZE_NV                               0x871E
#define GL_TEXTURE_MAG_SIZE_NV                              0x871F
#endif

#ifndef GL_NV_texture_shader2
#define GL_DOT_PRODUCT_TEXTURE_3D_NV                        0x86EF
#endif

#ifndef GL_NV_vertex_array_range2
#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV              0x8533
#endif

#ifndef GL_NV_vertex_program
#define GL_VERTEX_PROGRAM_NV                                0x8620
#define GL_VERTEX_STATE_PROGRAM_NV                          0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV                             0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV                           0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV                             0x8625
#define GL_CURRENT_ATTRIB_NV                                0x8626
#define GL_PROGRAM_LENGTH_NV                                0x8627
#define GL_PROGRAM_STRING_NV                                0x8628
#define GL_MODELVIEW_PROJECTION_NV                          0x8629
#define GL_IDENTITY_NV                                      0x862A
#define GL_INVERSE_NV                                       0x862B
#define GL_TRANSPOSE_NV                                     0x862C
#define GL_INVERSE_TRANSPOSE_NV                             0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV                  0x862E
#define GL_MAX_TRACK_MATRICES_NV                            0x862F
#define GL_MATRIX0_NV                                       0x8630
#define GL_MATRIX1_NV                                       0x8631
#define GL_MATRIX2_NV                                       0x8632
#define GL_MATRIX3_NV                                       0x8633
#define GL_MATRIX4_NV                                       0x8634
#define GL_MATRIX5_NV                                       0x8635
#define GL_MATRIX6_NV                                       0x8636
#define GL_MATRIX7_NV                                       0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV                    0x8640
#define GL_CURRENT_MATRIX_NV                                0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV                     0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV                       0x8643
#define GL_PROGRAM_PARAMETER_NV                             0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV                          0x8645
#define GL_PROGRAM_TARGET_NV                                0x8646
#define GL_PROGRAM_RESIDENT_NV                              0x8647
#define GL_TRACK_MATRIX_NV                                  0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV                        0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV                        0x864A
#define GL_PROGRAM_ERROR_POSITION_NV                        0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV                          0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV                          0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV                          0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV                          0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV                          0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV                          0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV                          0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV                          0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV                          0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV                          0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV                         0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV                         0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV                         0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV                         0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV                         0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV                         0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV                         0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV                         0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV                         0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV                         0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV                         0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV                         0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV                         0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV                         0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV                         0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV                         0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV                        0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV                        0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV                        0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV                        0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV                        0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV                        0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV                         0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV                         0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV                         0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV                         0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV                         0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV                         0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV                         0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV                         0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV                         0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV                         0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV                        0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV                        0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV                        0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV                        0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV                        0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV                        0x867F
#endif

#ifndef GL_SGIX_texture_coordinate_clamp
#define GL_TEXTURE_MAX_CLAMP_S_SGIX                         0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX                         0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX                         0x836B
#endif

#ifndef GL_SGIX_scalebias_hint
#define GL_SCALEBIAS_HINT_SGIX                              0x8322
#endif

#ifndef GL_OML_interlace
#define GL_INTERLACE_OML                                    0x8980
#define GL_INTERLACE_READ_OML                               0x8981
#endif

#ifndef GL_OML_subsample
#define GL_FORMAT_SUBSAMPLE_24_24_OML                       0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML                     0x8983
#endif

#ifndef GL_OML_resample
#define GL_PACK_RESAMPLE_OML                                0x8984
#define GL_UNPACK_RESAMPLE_OML                              0x8985
#define GL_RESAMPLE_REPLICATE_OML                           0x8986
#define GL_RESAMPLE_ZERO_FILL_OML                           0x8987
#define GL_RESAMPLE_AVERAGE_OML                             0x8988
#define GL_RESAMPLE_DECIMATE_OML                            0x8989
#endif

#ifndef GL_NV_copy_depth_to_color
#define GL_DEPTH_STENCIL_TO_RGBA_NV                         0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV                         0x886F
#endif

#ifndef GL_ATI_envmap_bumpmap
#define GL_BUMP_ROT_MATRIX_ATI                              0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI                         0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI                           0x8777
#define GL_BUMP_TEX_UNITS_ATI                               0x8778
#define GL_DUDV_ATI                                         0x8779
#define GL_DU8DV8_ATI                                       0x877A
#define GL_BUMP_ENVMAP_ATI                                  0x877B
#define GL_BUMP_TARGET_ATI                                  0x877C
#endif

#ifndef GL_ATI_fragment_shader
#define GL_FRAGMENT_SHADER_ATI                              0x8920
#define GL_REG_0_ATI                                        0x8921
#define GL_REG_1_ATI                                        0x8922
#define GL_REG_2_ATI                                        0x8923
#define GL_REG_3_ATI                                        0x8924
#define GL_REG_4_ATI                                        0x8925
#define GL_REG_5_ATI                                        0x8926
#define GL_REG_6_ATI                                        0x8927
#define GL_REG_7_ATI                                        0x8928
#define GL_REG_8_ATI                                        0x8929
#define GL_REG_9_ATI                                        0x892A
#define GL_REG_10_ATI                                       0x892B
#define GL_REG_11_ATI                                       0x892C
#define GL_REG_12_ATI                                       0x892D
#define GL_REG_13_ATI                                       0x892E
#define GL_REG_14_ATI                                       0x892F
#define GL_REG_15_ATI                                       0x8930
#define GL_REG_16_ATI                                       0x8931
#define GL_REG_17_ATI                                       0x8932
#define GL_REG_18_ATI                                       0x8933
#define GL_REG_19_ATI                                       0x8934
#define GL_REG_20_ATI                                       0x8935
#define GL_REG_21_ATI                                       0x8936
#define GL_REG_22_ATI                                       0x8937
#define GL_REG_23_ATI                                       0x8938
#define GL_REG_24_ATI                                       0x8939
#define GL_REG_25_ATI                                       0x893A
#define GL_REG_26_ATI                                       0x893B
#define GL_REG_27_ATI                                       0x893C
#define GL_REG_28_ATI                                       0x893D
#define GL_REG_29_ATI                                       0x893E
#define GL_REG_30_ATI                                       0x893F
#define GL_REG_31_ATI                                       0x8940
#define GL_CON_0_ATI                                        0x8941
#define GL_CON_1_ATI                                        0x8942
#define GL_CON_2_ATI                                        0x8943
#define GL_CON_3_ATI                                        0x8944
#define GL_CON_4_ATI                                        0x8945
#define GL_CON_5_ATI                                        0x8946
#define GL_CON_6_ATI                                        0x8947
#define GL_CON_7_ATI                                        0x8948
#define GL_CON_8_ATI                                        0x8949
#define GL_CON_9_ATI                                        0x894A
#define GL_CON_10_ATI                                       0x894B
#define GL_CON_11_ATI                                       0x894C
#define GL_CON_12_ATI                                       0x894D
#define GL_CON_13_ATI                                       0x894E
#define GL_CON_14_ATI                                       0x894F
#define GL_CON_15_ATI                                       0x8950
#define GL_CON_16_ATI                                       0x8951
#define GL_CON_17_ATI                                       0x8952
#define GL_CON_18_ATI                                       0x8953
#define GL_CON_19_ATI                                       0x8954
#define GL_CON_20_ATI                                       0x8955
#define GL_CON_21_ATI                                       0x8956
#define GL_CON_22_ATI                                       0x8957
#define GL_CON_23_ATI                                       0x8958
#define GL_CON_24_ATI                                       0x8959
#define GL_CON_25_ATI                                       0x895A
#define GL_CON_26_ATI                                       0x895B
#define GL_CON_27_ATI                                       0x895C
#define GL_CON_28_ATI                                       0x895D
#define GL_CON_29_ATI                                       0x895E
#define GL_CON_30_ATI                                       0x895F
#define GL_CON_31_ATI                                       0x8960
#define GL_MOV_ATI                                          0x8961
#define GL_ADD_ATI                                          0x8963
#define GL_MUL_ATI                                          0x8964
#define GL_SUB_ATI                                          0x8965
#define GL_DOT3_ATI                                         0x8966
#define GL_DOT4_ATI                                         0x8967
#define GL_MAD_ATI                                          0x8968
#define GL_LERP_ATI                                         0x8969
#define GL_CND_ATI                                          0x896A
#define GL_CND0_ATI                                         0x896B
#define GL_DOT2_ADD_ATI                                     0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI                       0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI                       0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI                       0x896F
#define GL_NUM_PASSES_ATI                                   0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI                    0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI                       0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI            0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI                      0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI                          0x8975
#define GL_SWIZZLE_STR_ATI                                  0x8976
#define GL_SWIZZLE_STQ_ATI                                  0x8977
#define GL_SWIZZLE_STR_DR_ATI                               0x8978
#define GL_SWIZZLE_STQ_DQ_ATI                               0x8979
#define GL_SWIZZLE_STRQ_ATI                                 0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI                              0x897B
#define GL_RED_BIT_ATI                                      0x00000001
#define GL_GREEN_BIT_ATI                                    0x00000002
#define GL_BLUE_BIT_ATI                                     0x00000004
#define GL_2X_BIT_ATI                                       0x00000001
#define GL_4X_BIT_ATI                                       0x00000002
#define GL_8X_BIT_ATI                                       0x00000004
#define GL_HALF_BIT_ATI                                     0x00000008
#define GL_QUARTER_BIT_ATI                                  0x00000010
#define GL_EIGHTH_BIT_ATI                                   0x00000020
#define GL_SATURATE_BIT_ATI                                 0x00000040
#define GL_2X_BIT_ATI                                       0x00000001
#define GL_COMP_BIT_ATI                                     0x00000002
#define GL_NEGATE_BIT_ATI                                   0x00000004
#define GL_BIAS_BIT_ATI                                     0x00000008
#endif

#ifndef GL_ATI_pn_triangles
#define GL_PN_TRIANGLES_ATI                                 0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI           0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI                      0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI                     0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI               0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI               0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI                0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI              0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI           0x87F8
#endif

#ifndef GL_ATI_vertex_array_object
#define GL_STATIC_ATI                                       0x8760
#define GL_DYNAMIC_ATI                                      0x8761
#define GL_PRESERVE_ATI                                     0x8762
#define GL_DISCARD_ATI                                      0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI                           0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI                          0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI                          0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI                          0x8767
#endif

#ifndef GL_EXT_vertex_shader
#define GL_VERTEX_SHADER_EXT                                0x8780
#define GL_VERTEX_SHADER_BINDING_EXT                        0x8781
#define GL_OP_INDEX_EXT                                     0x8782
#define GL_OP_NEGATE_EXT                                    0x8783
#define GL_OP_DOT3_EXT                                      0x8784
#define GL_OP_DOT4_EXT                                      0x8785
#define GL_OP_MUL_EXT                                       0x8786
#define GL_OP_ADD_EXT                                       0x8787
#define GL_OP_MADD_EXT                                      0x8788
#define GL_OP_FRAC_EXT                                      0x8789
#define GL_OP_MAX_EXT                                       0x878A
#define GL_OP_MIN_EXT                                       0x878B
#define GL_OP_SET_GE_EXT                                    0x878C
#define GL_OP_SET_LT_EXT                                    0x878D
#define GL_OP_CLAMP_EXT                                     0x878E
#define GL_OP_FLOOR_EXT                                     0x878F
#define GL_OP_ROUND_EXT                                     0x8790
#define GL_OP_EXP_BASE_2_EXT                                0x8791
#define GL_OP_LOG_BASE_2_EXT                                0x8792
#define GL_OP_POWER_EXT                                     0x8793
#define GL_OP_RECIP_EXT                                     0x8794
#define GL_OP_RECIP_SQRT_EXT                                0x8795
#define GL_OP_SUB_EXT                                       0x8796
#define GL_OP_CROSS_PRODUCT_EXT                             0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT                           0x8798
#define GL_OP_MOV_EXT                                       0x8799
#define GL_OUTPUT_VERTEX_EXT                                0x879A
#define GL_OUTPUT_COLOR0_EXT                                0x879B
#define GL_OUTPUT_COLOR1_EXT                                0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT                        0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT                        0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT                        0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT                        0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT                        0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT                        0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT                        0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT                        0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT                        0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT                        0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT                       0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT                       0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT                       0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT                       0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT                       0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT                       0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT                       0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT                       0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT                       0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT                       0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT                       0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT                       0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT                       0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT                       0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT                       0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT                       0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT                       0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT                       0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT                       0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT                       0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT                       0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT                       0x87BC
#define GL_OUTPUT_FOG_EXT                                   0x87BD
#define GL_SCALAR_EXT                                       0x87BE
#define GL_VECTOR_EXT                                       0x87BF
#define GL_MATRIX_EXT                                       0x87C0
#define GL_VARIANT_EXT                                      0x87C1
#define GL_INVARIANT_EXT                                    0x87C2
#define GL_LOCAL_CONSTANT_EXT                               0x87C3
#define GL_LOCAL_EXT                                        0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT               0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT                   0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT                 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT            0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT                     0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT     0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT         0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT  0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT       0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT           0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT                   0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT                       0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT                     0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT                0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT                         0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT                      0x87D4
#define GL_X_EXT                                            0x87D5
#define GL_Y_EXT                                            0x87D6
#define GL_Z_EXT                                            0x87D7
#define GL_W_EXT                                            0x87D8
#define GL_NEGATIVE_X_EXT                                   0x87D9
#define GL_NEGATIVE_Y_EXT                                   0x87DA
#define GL_NEGATIVE_Z_EXT                                   0x87DB
#define GL_NEGATIVE_W_EXT                                   0x87DC
#define GL_ZERO_EXT                                         0x87DD
#define GL_ONE_EXT                                          0x87DE
#define GL_NEGATIVE_ONE_EXT                                 0x87DF
#define GL_NORMALIZED_RANGE_EXT                             0x87E0
#define GL_FULL_RANGE_EXT                                   0x87E1
#define GL_CURRENT_VERTEX_EXT                               0x87E2
#define GL_MVP_MATRIX_EXT                                   0x87E3
#define GL_VARIANT_VALUE_EXT                                0x87E4
#define GL_VARIANT_DATATYPE_EXT                             0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT                         0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT                           0x87E7
#define GL_VARIANT_ARRAY_EXT                                0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT                        0x87E9
#define GL_INVARIANT_VALUE_EXT                              0x87EA
#define GL_INVARIANT_DATATYPE_EXT                           0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT                         0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT                      0x87ED
#endif

#ifndef GL_ATI_vertex_streams
#define GL_MAX_VERTEX_STREAMS_ATI                           0x876B
#define GL_VERTEX_STREAM0_ATI                               0x876C
#define GL_VERTEX_STREAM1_ATI                               0x876D
#define GL_VERTEX_STREAM2_ATI                               0x876E
#define GL_VERTEX_STREAM3_ATI                               0x876F
#define GL_VERTEX_STREAM4_ATI                               0x8770
#define GL_VERTEX_STREAM5_ATI                               0x8771
#define GL_VERTEX_STREAM6_ATI                               0x8772
#define GL_VERTEX_STREAM7_ATI                               0x8773
#define GL_VERTEX_SOURCE_ATI                                0x8774
#endif

#ifndef GL_ATI_element_array
#define GL_ELEMENT_ARRAY_ATI                                0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI                           0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI                        0x876A
#endif

#ifndef GL_SUN_mesh_array
#define GL_QUAD_MESH_SUN                                    0x8614
#define GL_TRIANGLE_MESH_SUN                                0x8615
#endif

#ifndef GL_SUN_slice_accum
#define GL_SLICE_ACCUM_SUN                                  0x85CC
#endif

#ifndef GL_NV_multisample_filter_hint
#define GL_MULTISAMPLE_FILTER_HINT_NV                       0x8534
#endif

#ifndef GL_NV_depth_clamp
#define GL_DEPTH_CLAMP_NV                                   0x864F
#endif

#ifndef GL_NV_occlusion_query
#define GL_PIXEL_COUNTER_BITS_NV                            0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV                    0x8865
#define GL_PIXEL_COUNT_NV                                   0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV                         0x8867
#endif

#ifndef GL_NV_point_sprite
#define GL_POINT_SPRITE_NV                                  0x8861
#define GL_COORD_REPLACE_NV                                 0x8862
#define GL_POINT_SPRITE_R_MODE_NV                           0x8863
#endif

#ifndef GL_NV_texture_shader3
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV                  0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV            0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV           0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV     0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV                        0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV                 0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV             0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV      0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV                     0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV                      0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV                0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV                      0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV                        0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV              0x885D
#define GL_HILO8_NV                                         0x885E
#define GL_SIGNED_HILO8_NV                                  0x885F
#define GL_FORCE_BLUE_TO_ONE_NV                             0x8860
#endif

#ifndef GL_NV_vertex_program1_1
#endif

#ifndef GL_EXT_shadow_funcs
#endif

#ifndef GL_EXT_stencil_two_side
#define GL_STENCIL_TEST_TWO_SIDE_EXT                        0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT                          0x8911
#endif

#ifndef GL_ATI_text_fragment_shader
#define GL_TEXT_FRAGMENT_SHADER_ATI                         0x8200
#endif

#ifndef GL_APPLE_client_storage
#define GL_UNPACK_CLIENT_STORAGE_APPLE                      0x85B2
#endif

#ifndef GL_APPLE_element_array
#define GL_ELEMENT_ARRAY_APPLE                              0x8A0C
#define GL_ELEMENT_ARRAY_TYPE_APPLE                         0x8A0D
#define GL_ELEMENT_ARRAY_POINTER_APPLE                      0x8A0E
#endif

#ifndef GL_APPLE_fence
#define GL_DRAW_PIXELS_APPLE                                0x8A0A
#define GL_FENCE_APPLE                                      0x8A0B
#endif

#ifndef GL_APPLE_vertex_array_object
#define GL_VERTEX_ARRAY_BINDING_APPLE                       0x85B5
#endif

#ifndef GL_APPLE_vertex_array_range
#define GL_VERTEX_ARRAY_RANGE_APPLE                         0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE                  0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE                  0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE                 0x8521
#define GL_STORAGE_CLIENT_APPLE                             0x85B4
#define GL_STORAGE_CACHED_APPLE                             0x85BE
#define GL_STORAGE_SHARED_APPLE                             0x85BF
#endif

#ifndef GL_APPLE_ycbcr_422
#define GL_YCBCR_422_APPLE                                  0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE                         0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE                     0x85BB
#endif

#ifndef GL_S3_s3tc
#define GL_RGB_S3TC                                         0x83A0
#define GL_RGB4_S3TC                                        0x83A1
#define GL_RGBA_S3TC                                        0x83A2
#define GL_RGBA4_S3TC                                       0x83A3
#define GL_RGBA_DXT5_S3TC                                   0x83A4
#define GL_RGBA4_DXT5_S3TC                                  0x83A5
#endif

#ifndef GL_ATI_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ATI                             0x8824
#define GL_DRAW_BUFFER0_ATI                                 0x8825
#define GL_DRAW_BUFFER1_ATI                                 0x8826
#define GL_DRAW_BUFFER2_ATI                                 0x8827
#define GL_DRAW_BUFFER3_ATI                                 0x8828
#define GL_DRAW_BUFFER4_ATI                                 0x8829
#define GL_DRAW_BUFFER5_ATI                                 0x882A
#define GL_DRAW_BUFFER6_ATI                                 0x882B
#define GL_DRAW_BUFFER7_ATI                                 0x882C
#define GL_DRAW_BUFFER8_ATI                                 0x882D
#define GL_DRAW_BUFFER9_ATI                                 0x882E
#define GL_DRAW_BUFFER10_ATI                                0x882F
#define GL_DRAW_BUFFER11_ATI                                0x8830
#define GL_DRAW_BUFFER12_ATI                                0x8831
#define GL_DRAW_BUFFER13_ATI                                0x8832
#define GL_DRAW_BUFFER14_ATI                                0x8833
#define GL_DRAW_BUFFER15_ATI                                0x8834
#endif

#ifndef GL_ATI_pixel_format_float
#define GL_RGBA_FLOAT_MODE_ATI                              0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI                  0x8835
#endif

#ifndef GL_ATI_texture_env_combine3
#define GL_MODULATE_ADD_ATI                                 0x8744
#define GL_MODULATE_SIGNED_ADD_ATI                          0x8745
#define GL_MODULATE_SUBTRACT_ATI                            0x8746
#endif

#ifndef GL_ATI_texture_float
#define GL_RGBA_FLOAT32_ATI                                 0x8814
#define GL_RGB_FLOAT32_ATI                                  0x8815
#define GL_ALPHA_FLOAT32_ATI                                0x8816
#define GL_INTENSITY_FLOAT32_ATI                            0x8817
#define GL_LUMINANCE_FLOAT32_ATI                            0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI                      0x8819
#define GL_RGBA_FLOAT16_ATI                                 0x881A
#define GL_RGB_FLOAT16_ATI                                  0x881B
#define GL_ALPHA_FLOAT16_ATI                                0x881C
#define GL_INTENSITY_FLOAT16_ATI                            0x881D
#define GL_LUMINANCE_FLOAT16_ATI                            0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI                      0x881F
#endif

#ifndef GL_NV_float_buffer
#define GL_FLOAT_R_NV                                       0x8880
#define GL_FLOAT_RG_NV                                      0x8881
#define GL_FLOAT_RGB_NV                                     0x8882
#define GL_FLOAT_RGBA_NV                                    0x8883
#define GL_FLOAT_R16_NV                                     0x8884
#define GL_FLOAT_R32_NV                                     0x8885
#define GL_FLOAT_RG16_NV                                    0x8886
#define GL_FLOAT_RG32_NV                                    0x8887
#define GL_FLOAT_RGB16_NV                                   0x8888
#define GL_FLOAT_RGB32_NV                                   0x8889
#define GL_FLOAT_RGBA16_NV                                  0x888A
#define GL_FLOAT_RGBA32_NV                                  0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV                      0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV                       0x888D
#define GL_FLOAT_RGBA_MODE_NV                               0x888E
#endif

#ifndef GL_NV_fragment_program
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV         0x8868
#define GL_FRAGMENT_PROGRAM_NV                              0x8870
#define GL_MAX_TEXTURE_COORDS_NV                            0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV                       0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV                      0x8873
#define GL_PROGRAM_ERROR_STRING_NV                          0x8874
#endif

#ifndef GL_NV_half_float
#define GL_HALF_FLOAT_NV                                    0x140B
#endif

#ifndef GL_NV_pixel_data_range
#define GL_WRITE_PIXEL_DATA_RANGE_NV                        0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV                         0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV                 0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV                  0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV                0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV                 0x887D
#endif

#ifndef GL_NV_primitive_restart
#define GL_PRIMITIVE_RESTART_NV                             0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV                       0x8559
#endif

#ifndef GL_NV_texture_expand_normal
#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV                   0x888F
#endif

#ifndef GL_NV_vertex_program2
#endif

#ifndef GL_ATI_map_object_buffer
#endif

#ifndef GL_ATI_separate_stencil
#define GL_STENCIL_BACK_FUNC_ATI                            0x8800
#define GL_STENCIL_BACK_FAIL_ATI                            0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI                 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI                 0x8803
#endif

#ifndef GL_ATI_vertex_attrib_array_object
#endif

#ifndef GL_OES_read_format
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES               0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES             0x8B9B
#endif

#ifndef GL_EXT_depth_bounds_test
#define GL_DEPTH_BOUNDS_TEST_EXT                            0x8890
#define GL_DEPTH_BOUNDS_EXT                                 0x8891
#endif

#ifndef GL_EXT_texture_mirror_clamp
#define GL_MIRROR_CLAMP_EXT                                 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT                         0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT                       0x8912
#endif

#ifndef GL_EXT_blend_equation_separate
#define GL_BLEND_EQUATION_RGB_EXT                           0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT                         0x883D
#endif

#ifndef GL_MESA_pack_invert
#define GL_PACK_INVERT_MESA                                 0x8758
#endif

#ifndef GL_MESA_ycbcr_texture
#define GL_UNSIGNED_SHORT_8_8_MESA                          0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA                      0x85BB
#define GL_YCBCR_MESA                                       0x8757
#endif

#ifndef GL_EXT_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_EXT                            0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT                          0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT                    0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT                  0x88EF
#endif

#ifndef GL_NV_fragment_program_option
#endif

#ifndef GL_NV_fragment_program2
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV                 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV                        0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV                          0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV                        0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV                        0x88F8
#endif

#ifndef GL_NV_vertex_program2_option
/* reuse GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV */
/* reuse GL_MAX_PROGRAM_CALL_DEPTH_NV */
#endif

#ifndef GL_NV_vertex_program3
/* reuse GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB */
#endif

#ifndef GL_EXT_framebuffer_object
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT                0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT                        0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT                          0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT                         0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT           0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT           0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT         0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT    0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT                         0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT            0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT    0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT            0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT               0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT           0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT           0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                      0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT                        0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT                            0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                            0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                            0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                            0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                            0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                            0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                            0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                            0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                            0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                            0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT                           0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT                           0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT                           0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT                           0x8CED
#define GL_COLOR_ATTACHMENT14_EXT                           0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT                           0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                             0x8D00
#define GL_STENCIL_ATTACHMENT_EXT                           0x8D20
#define GL_FRAMEBUFFER_EXT                                  0x8D40
#define GL_RENDERBUFFER_EXT                                 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT                           0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT                          0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                 0x8D44
#define GL_STENCIL_INDEX1_EXT                               0x8D46
#define GL_STENCIL_INDEX4_EXT                               0x8D47
#define GL_STENCIL_INDEX8_EXT                               0x8D48
#define GL_STENCIL_INDEX16_EXT                              0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT                        0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT                      0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT                       0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT                      0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT                      0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT                    0x8D55
#endif

#ifndef GL_GREMEDY_string_marker
#endif

#ifndef GL_EXT_packed_depth_stencil
#define GL_DEPTH_STENCIL_EXT                                0x84F9
#define GL_UNSIGNED_INT_24_8_EXT                            0x84FA
#define GL_DEPTH24_STENCIL8_EXT                             0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT                         0x88F1
#endif

#ifndef GL_EXT_stencil_clear_tag
#define GL_STENCIL_TAG_BITS_EXT                             0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT                      0x88F3
#endif

#ifndef GL_EXT_texture_sRGB
#define GL_SRGB_EXT                                         0x8C40
#define GL_SRGB8_EXT                                        0x8C41
#define GL_SRGB_ALPHA_EXT                                   0x8C42
#define GL_SRGB8_ALPHA8_EXT                                 0x8C43
#define GL_SLUMINANCE_ALPHA_EXT                             0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT                           0x8C45
#define GL_SLUMINANCE_EXT                                   0x8C46
#define GL_SLUMINANCE8_EXT                                  0x8C47
#define GL_COMPRESSED_SRGB_EXT                              0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT                        0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT                        0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT                  0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT                    0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT              0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT              0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT              0x8C4F
#endif

#ifndef GL_EXT_framebuffer_blit
#define GL_READ_FRAMEBUFFER_EXT                             0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT                             0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT                     GL_FRAMEBUFFER_BINDING_EXT
#define GL_READ_FRAMEBUFFER_BINDING_EXT                     0x8CAA
#endif

#ifndef GL_EXT_framebuffer_multisample
#define GL_RENDERBUFFER_SAMPLES_EXT                         0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT           0x8D56
#define GL_MAX_SAMPLES_EXT                                  0x8D57
#endif

#ifndef GL_MESAX_texture_stack
#define GL_TEXTURE_1D_STACK_MESAX                           0x8759
#define GL_TEXTURE_2D_STACK_MESAX                           0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX                     0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX                     0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX                   0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX                   0x875E
#endif

#ifndef GL_EXT_timer_query
#define GL_TIME_ELAPSED_EXT                                 0x88BF
#endif

#ifndef GL_EXT_gpu_program_parameters
#endif

#ifndef GL_APPLE_flush_buffer_range
#define GL_BUFFER_SERIALIZED_MODIFY_APPLE                   0x8A12
#define GL_BUFFER_FLUSHING_UNMAP_APPLE                      0x8A13
#endif

#ifndef GL_NV_gpu_program4
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV                      0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV                      0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV                     0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV                     0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV                 0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV                 0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV                   0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV                   0x8DA6
#endif

#ifndef GL_NV_geometry_program4
#define GL_LINES_ADJACENCY_EXT                              0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT                         0x000B
#define GL_TRIANGLES_ADJACENCY_EXT                          0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT                     0x000D
#define GL_GEOMETRY_PROGRAM_NV                              0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV                   0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV           0x8C28
#define GL_GEOMETRY_VERTICES_OUT_EXT                        0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                          0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                         0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT             0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT               0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT         0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT           0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT         0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                           0x8642
#endif

#ifndef GL_EXT_geometry_shader4
#define GL_GEOMETRY_SHADER_EXT                              0x8DD9
/* reuse GL_GEOMETRY_VERTICES_OUT_EXT */
/* reuse GL_GEOMETRY_INPUT_TYPE_EXT */
/* reuse GL_GEOMETRY_OUTPUT_TYPE_EXT */
/* reuse GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT */
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT              0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT                0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT                       0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT              0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT                 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT         0x8DE1
/* reuse GL_LINES_ADJACENCY_EXT */
/* reuse GL_LINE_STRIP_ADJACENCY_EXT */
/* reuse GL_TRIANGLES_ADJACENCY_EXT */
/* reuse GL_TRIANGLE_STRIP_ADJACENCY_EXT */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT */
/* reuse GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT */
/* reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT */
/* reuse GL_PROGRAM_POINT_SIZE_EXT */
#endif

#ifndef GL_NV_vertex_program4
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV                   0x88FD
#endif

#ifndef GL_EXT_gpu_shader4
#define GL_SAMPLER_1D_ARRAY_EXT                             0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT                             0x8DC1
#define GL_SAMPLER_BUFFER_EXT                               0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT                      0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT                      0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT                          0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT                            0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT                            0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT                            0x8DC8
#define GL_INT_SAMPLER_1D_EXT                               0x8DC9
#define GL_INT_SAMPLER_2D_EXT                               0x8DCA
#define GL_INT_SAMPLER_3D_EXT                               0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT                             0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT                          0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT                         0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT                         0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT                           0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT                      0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT                      0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT                      0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT                    0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT                 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT                0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT                0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT                  0x8DD8
#endif

#ifndef GL_EXT_draw_instanced
#endif

#ifndef GL_EXT_packed_float
#define GL_R11F_G11F_B10F_EXT                               0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT                 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT                       0x8C3C
#endif

#ifndef GL_EXT_texture_array
#define GL_TEXTURE_1D_ARRAY_EXT                             0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT                       0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT                             0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT                       0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT                     0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT                     0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT                     0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT                 0x884E
/* reuse GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT */
#endif

#ifndef GL_EXT_texture_buffer_object
#define GL_TEXTURE_BUFFER_EXT                               0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT                      0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT                       0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT            0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT                        0x8C2E
#endif

#ifndef GL_EXT_texture_compression_latc
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT                   0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT            0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT             0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT      0x8C73
#endif

#ifndef GL_EXT_texture_compression_rgtc
#define GL_COMPRESSED_RED_RGTC1_EXT                         0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT                  0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT                   0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT            0x8DBE
#endif

#ifndef GL_EXT_texture_shared_exponent
#define GL_RGB9_E5_EXT                                      0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT                     0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT                          0x8C3F
#endif

#ifndef GL_NV_depth_buffer_float
#define GL_DEPTH_COMPONENT32F_NV                            0x8DAB
#define GL_DEPTH32F_STENCIL8_NV                             0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV                0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV                       0x8DAF
#endif

#ifndef GL_NV_fragment_program4
#endif

#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV                 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV                    0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV                0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV                    0x8E12
#endif

#ifndef GL_EXT_framebuffer_sRGB
#define GL_FRAMEBUFFER_SRGB_EXT                             0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT                     0x8DBA
#endif

#ifndef GL_NV_geometry_shader4
#endif

#ifndef GL_NV_parameter_buffer_object
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV         0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV             0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV               0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV             0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV             0x8DA4
#endif

#ifndef GL_EXT_draw_buffers2
#endif

#ifndef GL_NV_transform_feedback
#define GL_BACK_PRIMARY_COLOR_NV                            0x8C77
#define GL_BACK_SECONDARY_COLOR_NV                          0x8C78
#define GL_TEXTURE_COORD_NV                                 0x8C79
#define GL_CLIP_DISTANCE_NV                                 0x8C7A
#define GL_VERTEX_ID_NV                                     0x8C7B
#define GL_PRIMITIVE_ID_NV                                  0x8C7C
#define GL_GENERIC_ATTRIB_NV                                0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV                    0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV                0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV    0x8C80
#define GL_ACTIVE_VARYINGS_NV                               0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV                     0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV                   0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV               0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV                0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV                     0x8C86
#define GL_PRIMITIVES_GENERATED_NV                          0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV         0x8C88
#define GL_RASTERIZER_DISCARD_NV                            0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV       0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV                           0x8C8C
#define GL_SEPARATE_ATTRIBS_NV                              0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV                     0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV             0x8C8F
#define GL_LAYER_NV                                         0x8DAA
#define GL_NEXT_BUFFER_NV                                   -2
#define GL_SKIP_COMPONENTS4_NV                              -3
#define GL_SKIP_COMPONENTS3_NV                              -4
#define GL_SKIP_COMPONENTS2_NV                              -5
#define GL_SKIP_COMPONENTS1_NV                              -6
#endif

#ifndef GL_EXT_bindable_uniform
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT                 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT               0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT               0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT                    0x8DED
#define GL_UNIFORM_BUFFER_EXT                               0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT                       0x8DEF
#endif

#ifndef GL_EXT_texture_integer
#define GL_RGBA32UI_EXT                                     0x8D70
#define GL_RGB32UI_EXT                                      0x8D71
#define GL_ALPHA32UI_EXT                                    0x8D72
#define GL_INTENSITY32UI_EXT                                0x8D73
#define GL_LUMINANCE32UI_EXT                                0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT                          0x8D75
#define GL_RGBA16UI_EXT                                     0x8D76
#define GL_RGB16UI_EXT                                      0x8D77
#define GL_ALPHA16UI_EXT                                    0x8D78
#define GL_INTENSITY16UI_EXT                                0x8D79
#define GL_LUMINANCE16UI_EXT                                0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT                          0x8D7B
#define GL_RGBA8UI_EXT                                      0x8D7C
#define GL_RGB8UI_EXT                                       0x8D7D
#define GL_ALPHA8UI_EXT                                     0x8D7E
#define GL_INTENSITY8UI_EXT                                 0x8D7F
#define GL_LUMINANCE8UI_EXT                                 0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT                           0x8D81
#define GL_RGBA32I_EXT                                      0x8D82
#define GL_RGB32I_EXT                                       0x8D83
#define GL_ALPHA32I_EXT                                     0x8D84
#define GL_INTENSITY32I_EXT                                 0x8D85
#define GL_LUMINANCE32I_EXT                                 0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT                           0x8D87
#define GL_RGBA16I_EXT                                      0x8D88
#define GL_RGB16I_EXT                                       0x8D89
#define GL_ALPHA16I_EXT                                     0x8D8A
#define GL_INTENSITY16I_EXT                                 0x8D8B
#define GL_LUMINANCE16I_EXT                                 0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT                           0x8D8D
#define GL_RGBA8I_EXT                                       0x8D8E
#define GL_RGB8I_EXT                                        0x8D8F
#define GL_ALPHA8I_EXT                                      0x8D90
#define GL_INTENSITY8I_EXT                                  0x8D91
#define GL_LUMINANCE8I_EXT                                  0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT                            0x8D93
#define GL_RED_INTEGER_EXT                                  0x8D94
#define GL_GREEN_INTEGER_EXT                                0x8D95
#define GL_BLUE_INTEGER_EXT                                 0x8D96
#define GL_ALPHA_INTEGER_EXT                                0x8D97
#define GL_RGB_INTEGER_EXT                                  0x8D98
#define GL_RGBA_INTEGER_EXT                                 0x8D99
#define GL_BGR_INTEGER_EXT                                  0x8D9A
#define GL_BGRA_INTEGER_EXT                                 0x8D9B
#define GL_LUMINANCE_INTEGER_EXT                            0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT                      0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT                            0x8D9E
#endif

#ifndef GL_GREMEDY_frame_terminator
#endif

#ifndef GL_NV_conditional_render
#define GL_QUERY_WAIT_NV                                    0x8E13
#define GL_QUERY_NO_WAIT_NV                                 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV                          0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV                       0x8E16
#endif

#ifndef GL_NV_present_video
#define GL_FRAME_NV                                         0x8E26
#define GL_FIELDS_NV                                        0x8E27
#define GL_CURRENT_TIME_NV                                  0x8E28
#define GL_NUM_FILL_STREAMS_NV                              0x8E29
#define GL_PRESENT_TIME_NV                                  0x8E2A
#define GL_PRESENT_DURATION_NV                              0x8E2B
#endif

#ifndef GL_EXT_transform_feedback
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT                    0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT              0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT               0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT            0x8C8F
#define GL_INTERLEAVED_ATTRIBS_EXT                          0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT                             0x8C8D
#define GL_PRIMITIVES_GENERATED_EXT                         0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT        0x8C88
#define GL_RASTERIZER_DISCARD_EXT                           0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT      0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT   0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT                  0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT               0x8C7F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT        0x8C76
#endif

#ifndef GL_EXT_direct_state_access
#define GL_PROGRAM_MATRIX_EXT                               0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT                     0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT                   0x8E2F
#endif

#ifndef GL_EXT_vertex_array_bgra
/* reuse GL_BGRA */
#endif

#ifndef GL_EXT_texture_swizzle
#define GL_TEXTURE_SWIZZLE_R_EXT                            0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT                            0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT                            0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT                            0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT                         0x8E46
#endif

#ifndef GL_NV_explicit_multisample
#define GL_SAMPLE_POSITION_NV                               0x8E50
#define GL_SAMPLE_MASK_NV                                   0x8E51
#define GL_SAMPLE_MASK_VALUE_NV                             0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV                  0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV       0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV                          0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV                          0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV                      0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV             0x8E58
#define GL_MAX_SAMPLE_MASK_WORDS_NV                         0x8E59
#endif

#ifndef GL_NV_transform_feedback2
#define GL_TRANSFORM_FEEDBACK_NV                            0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV              0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV              0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV                    0x8E25
#endif

#ifndef GL_ATI_meminfo
#define GL_VBO_FREE_MEMORY_ATI                              0x87FB
#define GL_TEXTURE_FREE_MEMORY_ATI                          0x87FC
#define GL_RENDERBUFFER_FREE_MEMORY_ATI                     0x87FD
#endif

#ifndef GL_AMD_performance_monitor
#define GL_COUNTER_TYPE_AMD                                 0x8BC0
#define GL_COUNTER_RANGE_AMD                                0x8BC1
#define GL_UNSIGNED_INT64_AMD                               0x8BC2
#define GL_PERCENTAGE_AMD                                   0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD                     0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD                          0x8BC5
#define GL_PERFMON_RESULT_AMD                               0x8BC6
#endif

#ifndef GL_AMD_texture_texture4
#endif

#ifndef GL_AMD_vertex_shader_tesselator
#define GL_SAMPLER_BUFFER_AMD                               0x9001
#define GL_INT_SAMPLER_BUFFER_AMD                           0x9002
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD                  0x9003
#define GL_TESSELLATION_MODE_AMD                            0x9004
#define GL_TESSELLATION_FACTOR_AMD                          0x9005
#define GL_DISCRETE_AMD                                     0x9006
#define GL_CONTINUOUS_AMD                                   0x9007
#endif

#ifndef GL_EXT_provoking_vertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT     0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT                      0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT                       0x8E4E
#define GL_PROVOKING_VERTEX_EXT                             0x8E4F
#endif

#ifndef GL_EXT_texture_snorm
#define GL_ALPHA_SNORM                                      0x9010
#define GL_LUMINANCE_SNORM                                  0x9011
#define GL_LUMINANCE_ALPHA_SNORM                            0x9012
#define GL_INTENSITY_SNORM                                  0x9013
#define GL_ALPHA8_SNORM                                     0x9014
#define GL_LUMINANCE8_SNORM                                 0x9015
#define GL_LUMINANCE8_ALPHA8_SNORM                          0x9016
#define GL_INTENSITY8_SNORM                                 0x9017
#define GL_ALPHA16_SNORM                                    0x9018
#define GL_LUMINANCE16_SNORM                                0x9019
#define GL_LUMINANCE16_ALPHA16_SNORM                        0x901A
#define GL_INTENSITY16_SNORM                                0x901B
/* reuse GL_RED_SNORM */
/* reuse GL_RG_SNORM */
/* reuse GL_RGB_SNORM */
/* reuse GL_RGBA_SNORM */
/* reuse GL_R8_SNORM */
/* reuse GL_RG8_SNORM */
/* reuse GL_RGB8_SNORM */
/* reuse GL_RGBA8_SNORM */
/* reuse GL_R16_SNORM */
/* reuse GL_RG16_SNORM */
/* reuse GL_RGB16_SNORM */
/* reuse GL_RGBA16_SNORM */
/* reuse GL_SIGNED_NORMALIZED */
#endif

#ifndef GL_AMD_draw_buffers_blend
#endif

#ifndef GL_APPLE_texture_range
#define GL_TEXTURE_RANGE_LENGTH_APPLE                       0x85B7
#define GL_TEXTURE_RANGE_POINTER_APPLE                      0x85B8
#define GL_TEXTURE_STORAGE_HINT_APPLE                       0x85BC
#define GL_STORAGE_PRIVATE_APPLE                            0x85BD
/* reuse GL_STORAGE_CACHED_APPLE */
/* reuse GL_STORAGE_SHARED_APPLE */
#endif

#ifndef GL_APPLE_float_pixels
#define GL_HALF_APPLE                                       0x140B
#define GL_RGBA_FLOAT32_APPLE                               0x8814
#define GL_RGB_FLOAT32_APPLE                                0x8815
#define GL_ALPHA_FLOAT32_APPLE                              0x8816
#define GL_INTENSITY_FLOAT32_APPLE                          0x8817
#define GL_LUMINANCE_FLOAT32_APPLE                          0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE                    0x8819
#define GL_RGBA_FLOAT16_APPLE                               0x881A
#define GL_RGB_FLOAT16_APPLE                                0x881B
#define GL_ALPHA_FLOAT16_APPLE                              0x881C
#define GL_INTENSITY_FLOAT16_APPLE                          0x881D
#define GL_LUMINANCE_FLOAT16_APPLE                          0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE                    0x881F
#define GL_COLOR_FLOAT_APPLE                                0x8A0F
#endif

#ifndef GL_APPLE_vertex_program_evaluators
#define GL_VERTEX_ATTRIB_MAP1_APPLE                         0x8A00
#define GL_VERTEX_ATTRIB_MAP2_APPLE                         0x8A01
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE                    0x8A02
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE                   0x8A03
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE                   0x8A04
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE                  0x8A05
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE                    0x8A06
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE                   0x8A07
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE                   0x8A08
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE                  0x8A09
#endif

#ifndef GL_APPLE_aux_depth_stencil
#define GL_AUX_DEPTH_STENCIL_APPLE                          0x8A14
#endif

#ifndef GL_APPLE_object_purgeable
#define GL_BUFFER_OBJECT_APPLE                              0x85B3
#define GL_RELEASED_APPLE                                   0x8A19
#define GL_VOLATILE_APPLE                                   0x8A1A
#define GL_RETAINED_APPLE                                   0x8A1B
#define GL_UNDEFINED_APPLE                                  0x8A1C
#define GL_PURGEABLE_APPLE                                  0x8A1D
#endif

#ifndef GL_APPLE_row_bytes
#define GL_PACK_ROW_BYTES_APPLE                             0x8A15
#define GL_UNPACK_ROW_BYTES_APPLE                           0x8A16
#endif

#ifndef GL_APPLE_rgb_422
#define GL_RGB_422_APPLE                                    0x8A1F
/* reuse GL_UNSIGNED_SHORT_8_8_APPLE */
/* reuse GL_UNSIGNED_SHORT_8_8_REV_APPLE */
#endif

#ifndef GL_NV_video_capture
#define GL_VIDEO_BUFFER_NV                                  0x9020
#define GL_VIDEO_BUFFER_BINDING_NV                          0x9021
#define GL_FIELD_UPPER_NV                                   0x9022
#define GL_FIELD_LOWER_NV                                   0x9023
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV                     0x9024
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV              0x9025
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV                0x9026
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV                     0x9027
#define GL_VIDEO_BUFFER_PITCH_NV                            0x9028
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV                 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV                    0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV                    0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV                 0x902C
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV                  0x902D
#define GL_PARTIAL_SUCCESS_NV                               0x902E
#define GL_SUCCESS_NV                                       0x902F
#define GL_FAILURE_NV                                       0x9030
#define GL_YCBYCR8_422_NV                                   0x9031
#define GL_YCBAYCR8A_4224_NV                                0x9032
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV                    0x9033
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV         0x9034
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV                    0x9035
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV         0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV                         0x9037
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV                     0x9038
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV                    0x9039
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV              0x903A
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV              0x903B
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV                  0x903C
#endif

#ifndef GL_NV_copy_image
#endif

#ifndef GL_EXT_separate_shader_objects
#define GL_ACTIVE_PROGRAM_EXT                               0x8B8D
#endif

#ifndef GL_NV_parameter_buffer_object2
#endif

#ifndef GL_NV_shader_buffer_load
#define GL_BUFFER_GPU_ADDRESS_NV                            0x8F1D
#define GL_GPU_ADDRESS_NV                                   0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV                     0x8F35
#endif

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV                   0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV                         0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV                   0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV                          0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV                          0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV                           0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV                           0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV                   0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV                       0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV                 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV                       0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV                         0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV                    0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV                           0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV                           0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV                            0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV                            0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV                    0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV                        0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV                  0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV                        0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV                          0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV                         0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV                         0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV                          0x8F42
#endif

#ifndef GL_NV_texture_barrier
#endif

#ifndef GL_AMD_shader_stencil_export
#endif

#ifndef GL_AMD_seamless_cubemap_per_texture
/* reuse GL_TEXTURE_CUBE_MAP_SEAMLESS */
#endif

#ifndef GL_AMD_conservative_depth
#endif

#ifndef GL_EXT_shader_image_load_store
#define GL_MAX_IMAGE_UNITS_EXT                              0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_IMAGE_BINDING_NAME_EXT                           0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT                          0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT                        0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT                          0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT                         0x8F3E
#define GL_IMAGE_1D_EXT                                     0x904C
#define GL_IMAGE_2D_EXT                                     0x904D
#define GL_IMAGE_3D_EXT                                     0x904E
#define GL_IMAGE_2D_RECT_EXT                                0x904F
#define GL_IMAGE_CUBE_EXT                                   0x9050
#define GL_IMAGE_BUFFER_EXT                                 0x9051
#define GL_IMAGE_1D_ARRAY_EXT                               0x9052
#define GL_IMAGE_2D_ARRAY_EXT                               0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT                         0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT                         0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT                   0x9056
#define GL_INT_IMAGE_1D_EXT                                 0x9057
#define GL_INT_IMAGE_2D_EXT                                 0x9058
#define GL_INT_IMAGE_3D_EXT                                 0x9059
#define GL_INT_IMAGE_2D_RECT_EXT                            0x905A
#define GL_INT_IMAGE_CUBE_EXT                               0x905B
#define GL_INT_IMAGE_BUFFER_EXT                             0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT                           0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT                           0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT                     0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT                     0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT               0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT                        0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT                        0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT                        0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT                   0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT                      0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT                    0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT                  0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT                  0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT            0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT            0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT      0x906C
#define GL_MAX_IMAGE_SAMPLES_EXT                            0x906D
#define GL_IMAGE_BINDING_FORMAT_EXT                         0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT              0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT                    0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT                          0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT                    0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT              0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT                          0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT                     0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT                   0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT                    0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT                      0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT               0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT                   0x00001000
#define GL_ALL_BARRIER_BITS_EXT                             0xFFFFFFFF
#endif

#ifndef GL_EXT_vertex_attrib_64bit
/* reuse GL_DOUBLE */
#define GL_DOUBLE_VEC2_EXT                                  0x8FFC
#define GL_DOUBLE_VEC3_EXT                                  0x8FFD
#define GL_DOUBLE_VEC4_EXT                                  0x8FFE
#define GL_DOUBLE_MAT2_EXT                                  0x8F46
#define GL_DOUBLE_MAT3_EXT                                  0x8F47
#define GL_DOUBLE_MAT4_EXT                                  0x8F48
#define GL_DOUBLE_MAT2x3_EXT                                0x8F49
#define GL_DOUBLE_MAT2x4_EXT                                0x8F4A
#define GL_DOUBLE_MAT3x2_EXT                                0x8F4B
#define GL_DOUBLE_MAT3x4_EXT                                0x8F4C
#define GL_DOUBLE_MAT4x2_EXT                                0x8F4D
#define GL_DOUBLE_MAT4x3_EXT                                0x8F4E
#endif

#ifndef GL_NV_gpu_program5
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV              0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV             0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV             0x8E5C
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV    0x8E5D
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV             0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV             0x8E5F
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV             0x8F44
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV                    0x8F45
#endif

#ifndef GL_NV_gpu_shader5
#define GL_INT64_NV                                         0x140E
#define GL_UNSIGNED_INT64_NV                                0x140F
#define GL_INT8_NV                                          0x8FE0
#define GL_INT8_VEC2_NV                                     0x8FE1
#define GL_INT8_VEC3_NV                                     0x8FE2
#define GL_INT8_VEC4_NV                                     0x8FE3
#define GL_INT16_NV                                         0x8FE4
#define GL_INT16_VEC2_NV                                    0x8FE5
#define GL_INT16_VEC3_NV                                    0x8FE6
#define GL_INT16_VEC4_NV                                    0x8FE7
#define GL_INT64_VEC2_NV                                    0x8FE9
#define GL_INT64_VEC3_NV                                    0x8FEA
#define GL_INT64_VEC4_NV                                    0x8FEB
#define GL_UNSIGNED_INT8_NV                                 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV                            0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV                            0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV                            0x8FEF
#define GL_UNSIGNED_INT16_NV                                0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV                           0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV                           0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV                           0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV                           0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV                           0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV                           0x8FF7
#define GL_FLOAT16_NV                                       0x8FF8
#define GL_FLOAT16_VEC2_NV                                  0x8FF9
#define GL_FLOAT16_VEC3_NV                                  0x8FFA
#define GL_FLOAT16_VEC4_NV                                  0x8FFB
/* reuse GL_PATCHES */
#endif

#ifndef GL_NV_shader_buffer_store
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV              0x00000010
/* reuse GL_READ_WRITE */
/* reuse GL_WRITE_ONLY */
#endif

#ifndef GL_NV_tessellation_program5
#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV                     0x86D8
#define GL_TESS_CONTROL_PROGRAM_NV                          0x891E
#define GL_TESS_EVALUATION_PROGRAM_NV                       0x891F
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV         0x8C74
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV      0x8C75
#endif

#ifndef GL_NV_vertex_attrib_integer_64bit
/* reuse GL_INT64_NV */
/* reuse GL_UNSIGNED_INT64_NV */
#endif

#ifndef GL_NV_multisample_coverage
#define GL_COVERAGE_SAMPLES_NV                              0x80A9
#define GL_COLOR_SAMPLES_NV                                 0x8E20
#endif

#ifndef GL_AMD_name_gen_delete
#define GL_DATA_BUFFER_AMD                                  0x9151
#define GL_PERFORMANCE_MONITOR_AMD                          0x9152
#define GL_QUERY_OBJECT_AMD                                 0x9153
#define GL_VERTEX_ARRAY_OBJECT_AMD                          0x9154
#define GL_SAMPLER_OBJECT_AMD                               0x9155
#endif

#ifndef GL_AMD_debug_output
#define GL_MAX_DEBUG_MESSAGE_LENGTH_AMD                     0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD                    0x9144
#define GL_DEBUG_LOGGED_MESSAGES_AMD                        0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD                          0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_AMD                        0x9147
#define GL_DEBUG_SEVERITY_LOW_AMD                           0x9148
#define GL_DEBUG_CATEGORY_API_ERROR_AMD                     0x9149
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD                 0x914A
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD                   0x914B
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD            0x914C
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD                   0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD               0x914E
#define GL_DEBUG_CATEGORY_APPLICATION_AMD                   0x914F
#define GL_DEBUG_CATEGORY_OTHER_AMD                         0x9150
#endif

#ifndef GL_NV_vdpau_interop
#define GL_SURFACE_STATE_NV                                 0x86EB
#define GL_SURFACE_REGISTERED_NV                            0x86FD
#define GL_SURFACE_MAPPED_NV                                0x8700
#define GL_WRITE_DISCARD_NV                                 0x88BE
#endif

#ifndef GL_AMD_transform_feedback3_lines_triangles
#endif

#ifndef GL_AMD_depth_clamp_separate
#define GL_DEPTH_CLAMP_NEAR_AMD                             0x901E
#define GL_DEPTH_CLAMP_FAR_AMD                              0x901F
#endif

#ifndef GL_EXT_texture_sRGB_decode
#define GL_TEXTURE_SRGB_DECODE_EXT                          0x8A48
#define GL_DECODE_EXT                                       0x8A49
#define GL_SKIP_DECODE_EXT                                  0x8A4A
#endif

#ifndef GL_NV_texture_multisample
#define GL_TEXTURE_COVERAGE_SAMPLES_NV                      0x9045
#define GL_TEXTURE_COLOR_SAMPLES_NV                         0x9046
#endif

#ifndef GL_AMD_blend_minmax_factor
#define GL_FACTOR_MIN_AMD                                   0x901C
#define GL_FACTOR_MAX_AMD                                   0x901D
#endif

#ifndef GL_AMD_sample_positions
#define GL_SUBSAMPLE_DISTANCE_AMD                           0x883F
#endif

#ifndef GL_EXT_x11_sync_object
#define GL_SYNC_X11_FENCE_EXT                               0x90E1
#endif

#ifndef GL_AMD_multi_draw_indirect
#endif

#ifndef GL_EXT_framebuffer_multisample_blit_scaled
#define GL_SCALED_RESOLVE_FASTEST_EXT                       0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT                        0x90BB
#endif

#ifndef GL_NV_path_rendering
#define GL_PATH_FORMAT_SVG_NV                               0x9070
#define GL_PATH_FORMAT_PS_NV                                0x9071
#define GL_STANDARD_FONT_NAME_NV                            0x9072
#define GL_SYSTEM_FONT_NAME_NV                              0x9073
#define GL_FILE_NAME_NV                                     0x9074
#define GL_PATH_STROKE_WIDTH_NV                             0x9075
#define GL_PATH_END_CAPS_NV                                 0x9076
#define GL_PATH_INITIAL_END_CAP_NV                          0x9077
#define GL_PATH_TERMINAL_END_CAP_NV                         0x9078
#define GL_PATH_JOIN_STYLE_NV                               0x9079
#define GL_PATH_MITER_LIMIT_NV                              0x907A
#define GL_PATH_DASH_CAPS_NV                                0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV                         0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV                        0x907D
#define GL_PATH_DASH_OFFSET_NV                              0x907E
#define GL_PATH_CLIENT_LENGTH_NV                            0x907F
#define GL_PATH_FILL_MODE_NV                                0x9080
#define GL_PATH_FILL_MASK_NV                                0x9081
#define GL_PATH_FILL_COVER_MODE_NV                          0x9082
#define GL_PATH_STROKE_COVER_MODE_NV                        0x9083
#define GL_PATH_STROKE_MASK_NV                              0x9084
#define GL_PATH_SAMPLE_QUALITY_NV                           0x9085
#define GL_PATH_STROKE_BOUND_NV                             0x9086
#define GL_PATH_STROKE_OVERSAMPLE_COUNT_NV                  0x9087
#define GL_COUNT_UP_NV                                      0x9088
#define GL_COUNT_DOWN_NV                                    0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV                      0x908A
#define GL_CONVEX_HULL_NV                                   0x908B
#define GL_MULTI_HULLS_NV                                   0x908C
#define GL_BOUNDING_BOX_NV                                  0x908D
#define GL_TRANSLATE_X_NV                                   0x908E
#define GL_TRANSLATE_Y_NV                                   0x908F
#define GL_TRANSLATE_2D_NV                                  0x9090
#define GL_TRANSLATE_3D_NV                                  0x9091
#define GL_AFFINE_2D_NV                                     0x9092
#define GL_PROJECTIVE_2D_NV                                 0x9093
#define GL_AFFINE_3D_NV                                     0x9094
#define GL_PROJECTIVE_3D_NV                                 0x9095
#define GL_TRANSPOSE_AFFINE_2D_NV                           0x9096
#define GL_TRANSPOSE_PROJECTIVE_2D_NV                       0x9097
#define GL_TRANSPOSE_AFFINE_3D_NV                           0x9098
#define GL_TRANSPOSE_PROJECTIVE_3D_NV                       0x9099
#define GL_UTF8_NV                                          0x909A
#define GL_UTF16_NV                                         0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV                0x909C
#define GL_PATH_COMMAND_COUNT_NV                            0x909D
#define GL_PATH_COORD_COUNT_NV                              0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV                         0x909F
#define GL_PATH_COMPUTED_LENGTH_NV                          0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV                        0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV                      0x90A2
#define GL_SQUARE_NV                                        0x90A3
#define GL_ROUND_NV                                         0x90A4
#define GL_TRIANGULAR_NV                                    0x90A5
#define GL_BEVEL_NV                                         0x90A6
#define GL_MITER_REVERT_NV                                  0x90A7
#define GL_MITER_TRUNCATE_NV                                0x90A8
#define GL_SKIP_MISSING_GLYPH_NV                            0x90A9
#define GL_USE_MISSING_GLYPH_NV                             0x90AA
#define GL_PATH_ERROR_POSITION_NV                           0x90AB
#define GL_PATH_FOG_GEN_MODE_NV                             0x90AC
#define GL_ACCUM_ADJACENT_PAIRS_NV                          0x90AD
#define GL_ADJACENT_PAIRS_NV                                0x90AE
#define GL_FIRST_TO_REST_NV                                 0x90AF
#define GL_PATH_GEN_MODE_NV                                 0x90B0
#define GL_PATH_GEN_COEFF_NV                                0x90B1
#define GL_PATH_GEN_COLOR_FORMAT_NV                         0x90B2
#define GL_PATH_GEN_COMPONENTS_NV                           0x90B3
#define GL_PATH_STENCIL_FUNC_NV                             0x90B7
#define GL_PATH_STENCIL_REF_NV                              0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV                       0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV              0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV               0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV                         0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV                        0x90B4
#define GL_MOVE_TO_RESETS_NV                                0x90B5
#define GL_MOVE_TO_CONTINUES_NV                             0x90B6
#define GL_CLOSE_PATH_NV                                    0x00
#define GL_MOVE_TO_NV                                       0x02
#define GL_RELATIVE_MOVE_TO_NV                              0x03
#define GL_LINE_TO_NV                                       0x04
#define GL_RELATIVE_LINE_TO_NV                              0x05
#define GL_HORIZONTAL_LINE_TO_NV                            0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV                   0x07
#define GL_VERTICAL_LINE_TO_NV                              0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV                     0x09
#define GL_QUADRATIC_CURVE_TO_NV                            0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV                   0x0B
#define GL_CUBIC_CURVE_TO_NV                                0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV                       0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV                     0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV            0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV                         0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV                0x11
#define GL_SMALL_CCW_ARC_TO_NV                              0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV                     0x13
#define GL_SMALL_CW_ARC_TO_NV                               0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV                      0x15
#define GL_LARGE_CCW_ARC_TO_NV                              0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV                     0x17
#define GL_LARGE_CW_ARC_TO_NV                               0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV                      0x19
#define GL_RESTART_PATH_NV                                  0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV                      0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV                       0xF4
#define GL_RECT_NV                                          0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV                           0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV                            0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV                       0xFC
#define GL_ARC_TO_NV                                        0xFE
#define GL_RELATIVE_ARC_TO_NV                               0xFF
#define GL_BOLD_BIT_NV                                      0x01
#define GL_ITALIC_BIT_NV                                    0x02
#define GL_GLYPH_WIDTH_BIT_NV                               0x01
#define GL_GLYPH_HEIGHT_BIT_NV                              0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV                0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV                0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV          0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV                  0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV                  0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV            0x80
#define GL_GLYPH_HAS_KERNING_NV                             0x100
#define GL_FONT_X_MIN_BOUNDS_NV                             0x00010000
#define GL_FONT_Y_MIN_BOUNDS_NV                             0x00020000
#define GL_FONT_X_MAX_BOUNDS_NV                             0x00040000
#define GL_FONT_Y_MAX_BOUNDS_NV                             0x00080000
#define GL_FONT_UNITS_PER_EM_NV                             0x00100000
#define GL_FONT_ASCENDER_NV                                 0x00200000
#define GL_FONT_DESCENDER_NV                                0x00400000
#define GL_FONT_HEIGHT_NV                                   0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_NV                        0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_NV                       0x02000000
#define GL_FONT_UNDERLINE_POSITION_NV                       0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_NV                      0x08000000
#define GL_FONT_HAS_KERNING_NV                              0x10000000
#endif

#ifndef GL_AMD_pinned_memory
#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD               0x9160
#endif

#ifndef GL_AMD_stencil_operation_extended
#define GL_SET_AMD                                          0x874A
#define GL_REPLACE_VALUE_AMD                                0x874B
#define GL_STENCIL_OP_VALUE_AMD                             0x874C
#define GL_STENCIL_BACK_OP_VALUE_AMD                        0x874D
#endif

#ifndef GL_AMD_vertex_shader_viewport_index
#endif

#ifndef GL_AMD_vertex_shader_layer
#endif

#ifndef GL_NV_bindless_texture
#endif

#ifndef GL_NV_shader_atomic_float
#endif

#ifndef GL_AMD_query_buffer_object
#define GL_QUERY_BUFFER_AMD                                 0x9192
#define GL_QUERY_BUFFER_BINDING_AMD                         0x9193
#define GL_QUERY_RESULT_NO_WAIT_AMD                         0x9194
#endif

#ifndef GL_AMD_sparse_texture
#define GL_VIRTUAL_PAGE_SIZE_X_AMD                          0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_AMD                          0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_AMD                          0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_AMD                      0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD                   0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS                  0x919A
#define GL_MIN_SPARSE_LEVEL_AMD                             0x919B
#define GL_MIN_LOD_WARNING_AMD                              0x919C
#define GL_TEXTURE_STORAGE_SPARSE_BIT_AMD                   0x00000001
#endif

#include <stddef.h>
#ifndef GL_VERSION_2_0
/* GL type for program/shader text */
typedef char GLchar;
#endif

#ifndef GL_VERSION_1_5
/* GL types for handling large vertex buffer objects */
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
#endif

#ifndef GL_ARB_vertex_buffer_object
/* GL types for handling large vertex buffer objects */
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
#endif

#ifndef GL_ARB_shader_objects
/* GL types for program/shader text and shader object handles */
typedef char GLcharARB;
typedef unsigned int GLhandleARB;
#endif

/* GL type for "half" precision (s10e5) float data in host memory */
#ifndef GL_ARB_half_float_pixel
typedef unsigned short GLhalfARB;
#endif

#ifndef GL_NV_half_float
typedef unsigned short GLhalfNV;
#endif

#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif

#ifndef GL_EXT_timer_query
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
#endif

#ifndef GL_ARB_sync
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef struct __GLsync *GLsync;
#endif

#ifndef GL_ARB_cl_event
/* These incomplete types let us declare types compatible with OpenCL's cl_context and cl_event */
struct _cl_context;
struct _cl_event;
#endif

#ifndef GL_ARB_debug_output
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif

#ifndef GL_AMD_debug_output
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif

#ifndef GL_KHR_debug
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif

#ifndef GL_NV_vdpau_interop
typedef GLintptr GLvdpauSurfaceNV;
#endif


/* GL_VERSION_1_0 */
extern void (APIENTRY *gglCullFace)(GLenum mode);
extern void (APIENTRY *gglFrontFace)(GLenum mode);
extern void (APIENTRY *gglHint)(GLenum target, GLenum mode);
extern void (APIENTRY *gglLineWidth)(GLfloat width);
extern void (APIENTRY *gglPointSize)(GLfloat size);
extern void (APIENTRY *gglPolygonMode)(GLenum face, GLenum mode);
extern void (APIENTRY *gglScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglTexParameterf)(GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglTexParameterfv)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglTexParameteri)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglTexParameteriv)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglDrawBuffer)(GLenum mode);
extern void (APIENTRY *gglClear)(GLbitfield mask);
extern void (APIENTRY *gglClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRY *gglClearStencil)(GLint s);
extern void (APIENTRY *gglClearDepth)(GLdouble depth);
extern void (APIENTRY *gglStencilMask)(GLuint mask);
extern void (APIENTRY *gglColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (APIENTRY *gglDepthMask)(GLboolean flag);
extern void (APIENTRY *gglDisable)(GLenum cap);
extern void (APIENTRY *gglEnable)(GLenum cap);
extern void (APIENTRY *gglFinish)();
extern void (APIENTRY *gglFlush)();
extern void (APIENTRY *gglBlendFunc)(GLenum sfactor, GLenum dfactor);
extern void (APIENTRY *gglLogicOp)(GLenum opcode);
extern void (APIENTRY *gglStencilFunc)(GLenum func, GLint ref, GLuint mask);
extern void (APIENTRY *gglStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
extern void (APIENTRY *gglDepthFunc)(GLenum func);
extern void (APIENTRY *gglPixelStoref)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglPixelStorei)(GLenum pname, GLint param);
extern void (APIENTRY *gglReadBuffer)(GLenum mode);
extern void (APIENTRY *gglReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
extern void (APIENTRY *gglGetBooleanv)(GLenum pname, GLboolean* params);
extern void (APIENTRY *gglGetDoublev)(GLenum pname, GLdouble* params);
extern GLenum (APIENTRY *gglGetError)();
extern void (APIENTRY *gglGetFloatv)(GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetIntegerv)(GLenum pname, GLint* params);
extern const GLubyte * (APIENTRY *gglGetString)(GLenum name);
extern void (APIENTRY *gglGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
extern void (APIENTRY *gglGetTexParameterfv)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetTexParameteriv)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint* params);
extern GLboolean (APIENTRY *gglIsEnabled)(GLenum cap);
extern void (APIENTRY *gglDepthRange)(GLdouble znear, GLdouble zfar);
extern void (APIENTRY *gglViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglNewList)(GLuint list, GLenum mode);
extern void (APIENTRY *gglEndList)();
extern void (APIENTRY *gglCallList)(GLuint list);
extern void (APIENTRY *gglCallLists)(GLsizei n, GLenum type, const GLvoid* lists);
extern void (APIENTRY *gglDeleteLists)(GLuint list, GLsizei range);
extern GLuint (APIENTRY *gglGenLists)(GLsizei range);
extern void (APIENTRY *gglListBase)(GLuint base);
extern void (APIENTRY *gglBegin)(GLenum mode);
extern void (APIENTRY *gglBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap);
extern void (APIENTRY *gglColor3b)(GLbyte red, GLbyte green, GLbyte blue);
extern void (APIENTRY *gglColor3bv)(const GLbyte* v);
extern void (APIENTRY *gglColor3d)(GLdouble red, GLdouble green, GLdouble blue);
extern void (APIENTRY *gglColor3dv)(const GLdouble* v);
extern void (APIENTRY *gglColor3f)(GLfloat red, GLfloat green, GLfloat blue);
extern void (APIENTRY *gglColor3fv)(const GLfloat* v);
extern void (APIENTRY *gglColor3i)(GLint red, GLint green, GLint blue);
extern void (APIENTRY *gglColor3iv)(const GLint* v);
extern void (APIENTRY *gglColor3s)(GLshort red, GLshort green, GLshort blue);
extern void (APIENTRY *gglColor3sv)(const GLshort* v);
extern void (APIENTRY *gglColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
extern void (APIENTRY *gglColor3ubv)(const GLubyte* v);
extern void (APIENTRY *gglColor3ui)(GLuint red, GLuint green, GLuint blue);
extern void (APIENTRY *gglColor3uiv)(const GLuint* v);
extern void (APIENTRY *gglColor3us)(GLushort red, GLushort green, GLushort blue);
extern void (APIENTRY *gglColor3usv)(const GLushort* v);
extern void (APIENTRY *gglColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
extern void (APIENTRY *gglColor4bv)(const GLbyte* v);
extern void (APIENTRY *gglColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
extern void (APIENTRY *gglColor4dv)(const GLdouble* v);
extern void (APIENTRY *gglColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRY *gglColor4fv)(const GLfloat* v);
extern void (APIENTRY *gglColor4i)(GLint red, GLint green, GLint blue, GLint alpha);
extern void (APIENTRY *gglColor4iv)(const GLint* v);
extern void (APIENTRY *gglColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
extern void (APIENTRY *gglColor4sv)(const GLshort* v);
extern void (APIENTRY *gglColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
extern void (APIENTRY *gglColor4ubv)(const GLubyte* v);
extern void (APIENTRY *gglColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
extern void (APIENTRY *gglColor4uiv)(const GLuint* v);
extern void (APIENTRY *gglColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
extern void (APIENTRY *gglColor4usv)(const GLushort* v);
extern void (APIENTRY *gglEdgeFlag)(GLboolean flag);
extern void (APIENTRY *gglEdgeFlagv)(const GLboolean* flag);
extern void (APIENTRY *gglEnd)();
extern void (APIENTRY *gglIndexd)(GLdouble c);
extern void (APIENTRY *gglIndexdv)(const GLdouble* c);
extern void (APIENTRY *gglIndexf)(GLfloat c);
extern void (APIENTRY *gglIndexfv)(const GLfloat* c);
extern void (APIENTRY *gglIndexi)(GLint c);
extern void (APIENTRY *gglIndexiv)(const GLint* c);
extern void (APIENTRY *gglIndexs)(GLshort c);
extern void (APIENTRY *gglIndexsv)(const GLshort* c);
extern void (APIENTRY *gglNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
extern void (APIENTRY *gglNormal3bv)(const GLbyte* v);
extern void (APIENTRY *gglNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
extern void (APIENTRY *gglNormal3dv)(const GLdouble* v);
extern void (APIENTRY *gglNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
extern void (APIENTRY *gglNormal3fv)(const GLfloat* v);
extern void (APIENTRY *gglNormal3i)(GLint nx, GLint ny, GLint nz);
extern void (APIENTRY *gglNormal3iv)(const GLint* v);
extern void (APIENTRY *gglNormal3s)(GLshort nx, GLshort ny, GLshort nz);
extern void (APIENTRY *gglNormal3sv)(const GLshort* v);
extern void (APIENTRY *gglRasterPos2d)(GLdouble x, GLdouble y);
extern void (APIENTRY *gglRasterPos2dv)(const GLdouble* v);
extern void (APIENTRY *gglRasterPos2f)(GLfloat x, GLfloat y);
extern void (APIENTRY *gglRasterPos2fv)(const GLfloat* v);
extern void (APIENTRY *gglRasterPos2i)(GLint x, GLint y);
extern void (APIENTRY *gglRasterPos2iv)(const GLint* v);
extern void (APIENTRY *gglRasterPos2s)(GLshort x, GLshort y);
extern void (APIENTRY *gglRasterPos2sv)(const GLshort* v);
extern void (APIENTRY *gglRasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglRasterPos3dv)(const GLdouble* v);
extern void (APIENTRY *gglRasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglRasterPos3fv)(const GLfloat* v);
extern void (APIENTRY *gglRasterPos3i)(GLint x, GLint y, GLint z);
extern void (APIENTRY *gglRasterPos3iv)(const GLint* v);
extern void (APIENTRY *gglRasterPos3s)(GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglRasterPos3sv)(const GLshort* v);
extern void (APIENTRY *gglRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglRasterPos4dv)(const GLdouble* v);
extern void (APIENTRY *gglRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglRasterPos4fv)(const GLfloat* v);
extern void (APIENTRY *gglRasterPos4i)(GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglRasterPos4iv)(const GLint* v);
extern void (APIENTRY *gglRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY *gglRasterPos4sv)(const GLshort* v);
extern void (APIENTRY *gglRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
extern void (APIENTRY *gglRectdv)(const GLdouble* v1, const GLdouble* v2);
extern void (APIENTRY *gglRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
extern void (APIENTRY *gglRectfv)(const GLfloat* v1, const GLfloat* v2);
extern void (APIENTRY *gglRecti)(GLint x1, GLint y1, GLint x2, GLint y2);
extern void (APIENTRY *gglRectiv)(const GLint* v1, const GLint* v2);
extern void (APIENTRY *gglRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
extern void (APIENTRY *gglRectsv)(const GLshort* v1, const GLshort* v2);
extern void (APIENTRY *gglTexCoord1d)(GLdouble s);
extern void (APIENTRY *gglTexCoord1dv)(const GLdouble* v);
extern void (APIENTRY *gglTexCoord1f)(GLfloat s);
extern void (APIENTRY *gglTexCoord1fv)(const GLfloat* v);
extern void (APIENTRY *gglTexCoord1i)(GLint s);
extern void (APIENTRY *gglTexCoord1iv)(const GLint* v);
extern void (APIENTRY *gglTexCoord1s)(GLshort s);
extern void (APIENTRY *gglTexCoord1sv)(const GLshort* v);
extern void (APIENTRY *gglTexCoord2d)(GLdouble s, GLdouble t);
extern void (APIENTRY *gglTexCoord2dv)(const GLdouble* v);
extern void (APIENTRY *gglTexCoord2f)(GLfloat s, GLfloat t);
extern void (APIENTRY *gglTexCoord2fv)(const GLfloat* v);
extern void (APIENTRY *gglTexCoord2i)(GLint s, GLint t);
extern void (APIENTRY *gglTexCoord2iv)(const GLint* v);
extern void (APIENTRY *gglTexCoord2s)(GLshort s, GLshort t);
extern void (APIENTRY *gglTexCoord2sv)(const GLshort* v);
extern void (APIENTRY *gglTexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
extern void (APIENTRY *gglTexCoord3dv)(const GLdouble* v);
extern void (APIENTRY *gglTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
extern void (APIENTRY *gglTexCoord3fv)(const GLfloat* v);
extern void (APIENTRY *gglTexCoord3i)(GLint s, GLint t, GLint r);
extern void (APIENTRY *gglTexCoord3iv)(const GLint* v);
extern void (APIENTRY *gglTexCoord3s)(GLshort s, GLshort t, GLshort r);
extern void (APIENTRY *gglTexCoord3sv)(const GLshort* v);
extern void (APIENTRY *gglTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern void (APIENTRY *gglTexCoord4dv)(const GLdouble* v);
extern void (APIENTRY *gglTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void (APIENTRY *gglTexCoord4fv)(const GLfloat* v);
extern void (APIENTRY *gglTexCoord4i)(GLint s, GLint t, GLint r, GLint q);
extern void (APIENTRY *gglTexCoord4iv)(const GLint* v);
extern void (APIENTRY *gglTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
extern void (APIENTRY *gglTexCoord4sv)(const GLshort* v);
extern void (APIENTRY *gglVertex2d)(GLdouble x, GLdouble y);
extern void (APIENTRY *gglVertex2dv)(const GLdouble* v);
extern void (APIENTRY *gglVertex2f)(GLfloat x, GLfloat y);
extern void (APIENTRY *gglVertex2fv)(const GLfloat* v);
extern void (APIENTRY *gglVertex2i)(GLint x, GLint y);
extern void (APIENTRY *gglVertex2iv)(const GLint* v);
extern void (APIENTRY *gglVertex2s)(GLshort x, GLshort y);
extern void (APIENTRY *gglVertex2sv)(const GLshort* v);
extern void (APIENTRY *gglVertex3d)(GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglVertex3dv)(const GLdouble* v);
extern void (APIENTRY *gglVertex3f)(GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglVertex3fv)(const GLfloat* v);
extern void (APIENTRY *gglVertex3i)(GLint x, GLint y, GLint z);
extern void (APIENTRY *gglVertex3iv)(const GLint* v);
extern void (APIENTRY *gglVertex3s)(GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglVertex3sv)(const GLshort* v);
extern void (APIENTRY *gglVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglVertex4dv)(const GLdouble* v);
extern void (APIENTRY *gglVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglVertex4fv)(const GLfloat* v);
extern void (APIENTRY *gglVertex4i)(GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglVertex4iv)(const GLint* v);
extern void (APIENTRY *gglVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY *gglVertex4sv)(const GLshort* v);
extern void (APIENTRY *gglClipPlane)(GLenum plane, const GLdouble* equation);
extern void (APIENTRY *gglColorMaterial)(GLenum face, GLenum mode);
extern void (APIENTRY *gglFogf)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglFogfv)(GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglFogi)(GLenum pname, GLint param);
extern void (APIENTRY *gglFogiv)(GLenum pname, const GLint* params);
extern void (APIENTRY *gglLightf)(GLenum light, GLenum pname, GLfloat param);
extern void (APIENTRY *gglLightfv)(GLenum light, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglLighti)(GLenum light, GLenum pname, GLint param);
extern void (APIENTRY *gglLightiv)(GLenum light, GLenum pname, const GLint* params);
extern void (APIENTRY *gglLightModelf)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglLightModelfv)(GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglLightModeli)(GLenum pname, GLint param);
extern void (APIENTRY *gglLightModeliv)(GLenum pname, const GLint* params);
extern void (APIENTRY *gglLineStipple)(GLint factor, GLushort pattern);
extern void (APIENTRY *gglMaterialf)(GLenum face, GLenum pname, GLfloat param);
extern void (APIENTRY *gglMaterialfv)(GLenum face, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglMateriali)(GLenum face, GLenum pname, GLint param);
extern void (APIENTRY *gglMaterialiv)(GLenum face, GLenum pname, const GLint* params);
extern void (APIENTRY *gglPolygonStipple)(const GLubyte* mask);
extern void (APIENTRY *gglShadeModel)(GLenum mode);
extern void (APIENTRY *gglTexEnvf)(GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglTexEnvfv)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglTexEnvi)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglTexEnviv)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglTexGend)(GLenum coord, GLenum pname, GLdouble param);
extern void (APIENTRY *gglTexGendv)(GLenum coord, GLenum pname, const GLdouble* params);
extern void (APIENTRY *gglTexGenf)(GLenum coord, GLenum pname, GLfloat param);
extern void (APIENTRY *gglTexGenfv)(GLenum coord, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglTexGeni)(GLenum coord, GLenum pname, GLint param);
extern void (APIENTRY *gglTexGeniv)(GLenum coord, GLenum pname, const GLint* params);
extern void (APIENTRY *gglFeedbackBuffer)(GLsizei size, GLenum type, GLfloat* buffer);
extern void (APIENTRY *gglSelectBuffer)(GLsizei size, GLuint* buffer);
extern GLint (APIENTRY *gglRenderMode)(GLenum mode);
extern void (APIENTRY *gglInitNames)();
extern void (APIENTRY *gglLoadName)(GLuint name);
extern void (APIENTRY *gglPassThrough)(GLfloat token);
extern void (APIENTRY *gglPopName)();
extern void (APIENTRY *gglPushName)(GLuint name);
extern void (APIENTRY *gglClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (APIENTRY *gglClearIndex)(GLfloat c);
extern void (APIENTRY *gglIndexMask)(GLuint mask);
extern void (APIENTRY *gglAccum)(GLenum op, GLfloat value);
extern void (APIENTRY *gglPopAttrib)();
extern void (APIENTRY *gglPushAttrib)(GLbitfield mask);
extern void (APIENTRY *gglMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
extern void (APIENTRY *gglMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
extern void (APIENTRY *gglMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
extern void (APIENTRY *gglMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);
extern void (APIENTRY *gglMapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
extern void (APIENTRY *gglMapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
extern void (APIENTRY *gglMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
extern void (APIENTRY *gglMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
extern void (APIENTRY *gglEvalCoord1d)(GLdouble u);
extern void (APIENTRY *gglEvalCoord1dv)(const GLdouble* u);
extern void (APIENTRY *gglEvalCoord1f)(GLfloat u);
extern void (APIENTRY *gglEvalCoord1fv)(const GLfloat* u);
extern void (APIENTRY *gglEvalCoord2d)(GLdouble u, GLdouble v);
extern void (APIENTRY *gglEvalCoord2dv)(const GLdouble* u);
extern void (APIENTRY *gglEvalCoord2f)(GLfloat u, GLfloat v);
extern void (APIENTRY *gglEvalCoord2fv)(const GLfloat* u);
extern void (APIENTRY *gglEvalMesh1)(GLenum mode, GLint i1, GLint i2);
extern void (APIENTRY *gglEvalPoint1)(GLint i);
extern void (APIENTRY *gglEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
extern void (APIENTRY *gglEvalPoint2)(GLint i, GLint j);
extern void (APIENTRY *gglAlphaFunc)(GLenum func, GLfloat ref);
extern void (APIENTRY *gglPixelZoom)(GLfloat xfactor, GLfloat yfactor);
extern void (APIENTRY *gglPixelTransferf)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglPixelTransferi)(GLenum pname, GLint param);
extern void (APIENTRY *gglPixelMapfv)(GLenum map, GLint mapsize, const GLfloat* values);
extern void (APIENTRY *gglPixelMapuiv)(GLenum map, GLint mapsize, const GLuint* values);
extern void (APIENTRY *gglPixelMapusv)(GLenum map, GLint mapsize, const GLushort* values);
extern void (APIENTRY *gglCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
extern void (APIENTRY *gglDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglGetClipPlane)(GLenum plane, GLdouble* equation);
extern void (APIENTRY *gglGetLightfv)(GLenum light, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetLightiv)(GLenum light, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMapdv)(GLenum target, GLenum query, GLdouble* v);
extern void (APIENTRY *gglGetMapfv)(GLenum target, GLenum query, GLfloat* v);
extern void (APIENTRY *gglGetMapiv)(GLenum target, GLenum query, GLint* v);
extern void (APIENTRY *gglGetMaterialfv)(GLenum face, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMaterialiv)(GLenum face, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetPixelMapfv)(GLenum map, GLfloat* values);
extern void (APIENTRY *gglGetPixelMapuiv)(GLenum map, GLuint* values);
extern void (APIENTRY *gglGetPixelMapusv)(GLenum map, GLushort* values);
extern void (APIENTRY *gglGetPolygonStipple)(GLubyte* mask);
extern void (APIENTRY *gglGetTexEnvfv)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetTexEnviv)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetTexGendv)(GLenum coord, GLenum pname, GLdouble* params);
extern void (APIENTRY *gglGetTexGenfv)(GLenum coord, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetTexGeniv)(GLenum coord, GLenum pname, GLint* params);
extern GLboolean (APIENTRY *gglIsList)(GLuint list);
extern void (APIENTRY *gglFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern void (APIENTRY *gglLoadIdentity)();
extern void (APIENTRY *gglLoadMatrixf)(const GLfloat* m);
extern void (APIENTRY *gglLoadMatrixd)(const GLdouble* m);
extern void (APIENTRY *gglMatrixMode)(GLenum mode);
extern void (APIENTRY *gglMultMatrixf)(const GLfloat* m);
extern void (APIENTRY *gglMultMatrixd)(const GLdouble* m);
extern void (APIENTRY *gglOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern void (APIENTRY *gglPopMatrix)();
extern void (APIENTRY *gglPushMatrix)();
extern void (APIENTRY *gglRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglScaled)(GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglScalef)(GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglTranslated)(GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglTranslatef)(GLfloat x, GLfloat y, GLfloat z);

/* GL_VERSION_1_1 */
extern void (APIENTRY *gglDrawArrays)(GLenum mode, GLint first, GLsizei count);
extern void (APIENTRY *gglDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
extern void (APIENTRY *gglGetPointerv)(GLenum pname, GLvoid** params);
extern void (APIENTRY *gglPolygonOffset)(GLfloat factor, GLfloat units);
extern void (APIENTRY *gglCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (APIENTRY *gglCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (APIENTRY *gglCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (APIENTRY *gglCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglBindTexture)(GLenum target, GLuint texture);
extern void (APIENTRY *gglDeleteTextures)(GLsizei n, const GLuint* textures);
extern void (APIENTRY *gglGenTextures)(GLsizei n, GLuint* textures);
extern GLboolean (APIENTRY *gglIsTexture)(GLuint texture);
extern void (APIENTRY *gglArrayElement)(GLint i);
extern void (APIENTRY *gglColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglDisableClientState)(GLenum array);
extern void (APIENTRY *gglEdgeFlagPointer)(GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglEnableClientState)(GLenum array);
extern void (APIENTRY *gglIndexPointer)(GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglInterleavedArrays)(GLenum format, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglNormalPointer)(GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglVertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern GLboolean (APIENTRY *gglAreTexturesResident)(GLsizei n, const GLuint* textures, GLboolean* residences);
extern void (APIENTRY *gglPrioritizeTextures)(GLsizei n, const GLuint* textures, const GLfloat* priorities);
extern void (APIENTRY *gglIndexub)(GLubyte c);
extern void (APIENTRY *gglIndexubv)(const GLubyte* c);
extern void (APIENTRY *gglPopClientAttrib)();
extern void (APIENTRY *gglPushClientAttrib)(GLbitfield mask);
/* OpenGL 3.0 also reuses entry points from these extensions: */
/* ARB_framebuffer_object */
/* ARB_map_buffer_range */
/* ARB_vertex_array_object */
/* OpenGL 3.1 also reuses entry points from these extensions: */
/* ARB_copy_buffer */
/* ARB_uniform_buffer_object */
/* OpenGL 3.2 also reuses entry points from these extensions: */
/* ARB_draw_elements_base_vertex */
/* ARB_provoking_vertex */
/* ARB_sync */
/* ARB_texture_multisample */
/* OpenGL 3.3 also reuses entry points from these extensions: */
/* ARB_blend_func_extended */
/* ARB_sampler_objects */
/* ARB_explicit_attrib_location, but it has none */
/* ARB_occlusion_query2 (no entry points) */
/* ARB_shader_bit_encoding (no entry points) */
/* ARB_texture_rgb10_a2ui (no entry points) */
/* ARB_texture_swizzle (no entry points) */
/* ARB_timer_query */
/* ARB_vertex_type_2_10_10_10_rev */
/* OpenGL 4.0 also reuses entry points from these extensions: */
/* ARB_texture_query_lod (no entry points) */
/* ARB_draw_indirect */
/* ARB_gpu_shader5 (no entry points) */
/* ARB_gpu_shader_fp64 */
/* ARB_shader_subroutine */
/* ARB_tessellation_shader */
/* ARB_texture_buffer_object_rgb32 (no entry points) */
/* ARB_texture_cube_map_array (no entry points) */
/* ARB_texture_gather (no entry points) */
/* ARB_transform_feedback2 */
/* ARB_transform_feedback3 */

/* GL_VERSION_4_1 */
/* OpenGL 4.1 reuses entry points from these extensions: */
/* ARB_ES2_compatibility */
/* ARB_get_program_binary */
/* ARB_separate_shader_objects */
/* ARB_shader_precision (no entry points) */
/* ARB_vertex_attrib_64bit */
/* ARB_viewport_array */

/* GL_VERSION_4_2 */
/* OpenGL 4.2 reuses entry points from these extensions: */
/* ARB_base_instance */
/* ARB_shading_language_420pack (no entry points) */
/* ARB_transform_feedback_instanced */
/* ARB_compressed_texture_pixel_storage (no entry points) */
/* ARB_conservative_depth (no entry points) */
/* ARB_internalformat_query */
/* ARB_map_buffer_alignment (no entry points) */
/* ARB_shader_atomic_counters */
/* ARB_shader_image_load_store */
/* ARB_shading_language_packing (no entry points) */
/* ARB_texture_storage */

/* GL_VERSION_4_3 */
/* OpenGL 4.3 reuses entry points from these extensions: */
/* ARB_arrays_of_arrays (no entry points, GLSL only) */
/* ARB_fragment_layer_viewport (no entry points, GLSL only) */
/* ARB_shader_image_size (no entry points, GLSL only) */
/* ARB_ES3_compatibility (no entry points) */
/* ARB_clear_buffer_object */
/* ARB_compute_shader */
/* ARB_copy_image */
/* KHR_debug (includes ARB_debug_output commands promoted to KHR without suffixes) */
/* ARB_explicit_uniform_location (no entry points) */
/* ARB_framebuffer_no_attachments */
/* ARB_internalformat_query2 */
/* ARB_invalidate_subdata */
/* ARB_multi_draw_indirect */
/* ARB_program_interface_query */
/* ARB_robust_buffer_access_behavior (no entry points) */
/* ARB_shader_storage_buffer_object */
/* ARB_stencil_texturing (no entry points) */
/* ARB_texture_buffer_range */
/* ARB_texture_query_levels (no entry points) */
/* ARB_texture_storage_multisample */
/* ARB_texture_view */
/* ARB_vertex_attrib_binding */

/* GL_ARB_multitexture */
extern void (APIENTRY *gglActiveTextureARB)(GLenum texture);
extern void (APIENTRY *gglClientActiveTextureARB)(GLenum texture);
extern void (APIENTRY *gglMultiTexCoord1dARB)(GLenum target, GLdouble s);
extern void (APIENTRY *gglMultiTexCoord1dvARB)(GLenum target, const GLdouble* v);
extern void (APIENTRY *gglMultiTexCoord1fARB)(GLenum target, GLfloat s);
extern void (APIENTRY *gglMultiTexCoord1fvARB)(GLenum target, const GLfloat* v);
extern void (APIENTRY *gglMultiTexCoord1iARB)(GLenum target, GLint s);
extern void (APIENTRY *gglMultiTexCoord1ivARB)(GLenum target, const GLint* v);
extern void (APIENTRY *gglMultiTexCoord1sARB)(GLenum target, GLshort s);
extern void (APIENTRY *gglMultiTexCoord1svARB)(GLenum target, const GLshort* v);
extern void (APIENTRY *gglMultiTexCoord2dARB)(GLenum target, GLdouble s, GLdouble t);
extern void (APIENTRY *gglMultiTexCoord2dvARB)(GLenum target, const GLdouble* v);
extern void (APIENTRY *gglMultiTexCoord2fARB)(GLenum target, GLfloat s, GLfloat t);
extern void (APIENTRY *gglMultiTexCoord2fvARB)(GLenum target, const GLfloat* v);
extern void (APIENTRY *gglMultiTexCoord2iARB)(GLenum target, GLint s, GLint t);
extern void (APIENTRY *gglMultiTexCoord2ivARB)(GLenum target, const GLint* v);
extern void (APIENTRY *gglMultiTexCoord2sARB)(GLenum target, GLshort s, GLshort t);
extern void (APIENTRY *gglMultiTexCoord2svARB)(GLenum target, const GLshort* v);
extern void (APIENTRY *gglMultiTexCoord3dARB)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
extern void (APIENTRY *gglMultiTexCoord3dvARB)(GLenum target, const GLdouble* v);
extern void (APIENTRY *gglMultiTexCoord3fARB)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
extern void (APIENTRY *gglMultiTexCoord3fvARB)(GLenum target, const GLfloat* v);
extern void (APIENTRY *gglMultiTexCoord3iARB)(GLenum target, GLint s, GLint t, GLint r);
extern void (APIENTRY *gglMultiTexCoord3ivARB)(GLenum target, const GLint* v);
extern void (APIENTRY *gglMultiTexCoord3sARB)(GLenum target, GLshort s, GLshort t, GLshort r);
extern void (APIENTRY *gglMultiTexCoord3svARB)(GLenum target, const GLshort* v);
extern void (APIENTRY *gglMultiTexCoord4dARB)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern void (APIENTRY *gglMultiTexCoord4dvARB)(GLenum target, const GLdouble* v);
extern void (APIENTRY *gglMultiTexCoord4fARB)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void (APIENTRY *gglMultiTexCoord4fvARB)(GLenum target, const GLfloat* v);
extern void (APIENTRY *gglMultiTexCoord4iARB)(GLenum target, GLint s, GLint t, GLint r, GLint q);
extern void (APIENTRY *gglMultiTexCoord4ivARB)(GLenum target, const GLint* v);
extern void (APIENTRY *gglMultiTexCoord4sARB)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
extern void (APIENTRY *gglMultiTexCoord4svARB)(GLenum target, const GLshort* v);

/* GL_ARB_transpose_matrix */
extern void (APIENTRY *gglLoadTransposeMatrixfARB)(const GLfloat* m);
extern void (APIENTRY *gglLoadTransposeMatrixdARB)(const GLdouble* m);
extern void (APIENTRY *gglMultTransposeMatrixfARB)(const GLfloat* m);
extern void (APIENTRY *gglMultTransposeMatrixdARB)(const GLdouble* m);

/* GL_ARB_multisample */
extern void (APIENTRY *gglSampleCoverageARB)(GLfloat value, GLboolean invert);

/* GL_ARB_texture_env_add */

/* GL_ARB_texture_cube_map */

/* GL_ARB_texture_compression */
extern void (APIENTRY *gglCompressedTexImage3DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
extern void (APIENTRY *gglCompressedTexImage2DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
extern void (APIENTRY *gglCompressedTexImage1DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data);
extern void (APIENTRY *gglCompressedTexSubImage3DARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
extern void (APIENTRY *gglCompressedTexSubImage2DARB)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
extern void (APIENTRY *gglCompressedTexSubImage1DARB)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data);
extern void (APIENTRY *gglGetCompressedTexImageARB)(GLenum target, GLint level, GLvoid* img);

/* GL_ARB_texture_border_clamp */

/* GL_ARB_point_parameters */
extern void (APIENTRY *gglPointParameterfARB)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglPointParameterfvARB)(GLenum pname, const GLfloat* params);

/* GL_ARB_vertex_blend */
extern void (APIENTRY *gglWeightbvARB)(GLint size, const GLbyte* weights);
extern void (APIENTRY *gglWeightsvARB)(GLint size, const GLshort* weights);
extern void (APIENTRY *gglWeightivARB)(GLint size, const GLint* weights);
extern void (APIENTRY *gglWeightfvARB)(GLint size, const GLfloat* weights);
extern void (APIENTRY *gglWeightdvARB)(GLint size, const GLdouble* weights);
extern void (APIENTRY *gglWeightubvARB)(GLint size, const GLubyte* weights);
extern void (APIENTRY *gglWeightusvARB)(GLint size, const GLushort* weights);
extern void (APIENTRY *gglWeightuivARB)(GLint size, const GLuint* weights);
extern void (APIENTRY *gglWeightPointerARB)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglVertexBlendARB)(GLint count);

/* GL_ARB_matrix_palette */
extern void (APIENTRY *gglCurrentPaletteMatrixARB)(GLint index);
extern void (APIENTRY *gglMatrixIndexubvARB)(GLint size, const GLubyte* indices);
extern void (APIENTRY *gglMatrixIndexusvARB)(GLint size, const GLushort* indices);
extern void (APIENTRY *gglMatrixIndexuivARB)(GLint size, const GLuint* indices);
extern void (APIENTRY *gglMatrixIndexPointerARB)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

/* GL_ARB_texture_env_combine */

/* GL_ARB_texture_env_crossbar */

/* GL_ARB_texture_env_dot3 */

/* GL_ARB_texture_mirrored_repeat */

/* GL_ARB_depth_texture */

/* GL_ARB_shadow */

/* GL_ARB_shadow_ambient */

/* GL_ARB_window_pos */
extern void (APIENTRY *gglWindowPos2dARB)(GLdouble x, GLdouble y);
extern void (APIENTRY *gglWindowPos2dvARB)(const GLdouble* v);
extern void (APIENTRY *gglWindowPos2fARB)(GLfloat x, GLfloat y);
extern void (APIENTRY *gglWindowPos2fvARB)(const GLfloat* v);
extern void (APIENTRY *gglWindowPos2iARB)(GLint x, GLint y);
extern void (APIENTRY *gglWindowPos2ivARB)(const GLint* v);
extern void (APIENTRY *gglWindowPos2sARB)(GLshort x, GLshort y);
extern void (APIENTRY *gglWindowPos2svARB)(const GLshort* v);
extern void (APIENTRY *gglWindowPos3dARB)(GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglWindowPos3dvARB)(const GLdouble* v);
extern void (APIENTRY *gglWindowPos3fARB)(GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglWindowPos3fvARB)(const GLfloat* v);
extern void (APIENTRY *gglWindowPos3iARB)(GLint x, GLint y, GLint z);
extern void (APIENTRY *gglWindowPos3ivARB)(const GLint* v);
extern void (APIENTRY *gglWindowPos3sARB)(GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglWindowPos3svARB)(const GLshort* v);

/* GL_ARB_vertex_program */
extern void (APIENTRY *gglVertexAttrib1dARB)(GLuint index, GLdouble x);
extern void (APIENTRY *gglVertexAttrib1dvARB)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib1fARB)(GLuint index, GLfloat x);
extern void (APIENTRY *gglVertexAttrib1fvARB)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib1sARB)(GLuint index, GLshort x);
extern void (APIENTRY *gglVertexAttrib1svARB)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib2dARB)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRY *gglVertexAttrib2dvARB)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib2fARB)(GLuint index, GLfloat x, GLfloat y);
extern void (APIENTRY *gglVertexAttrib2fvARB)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib2sARB)(GLuint index, GLshort x, GLshort y);
extern void (APIENTRY *gglVertexAttrib2svARB)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib3dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglVertexAttrib3dvARB)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib3fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglVertexAttrib3fvARB)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib3sARB)(GLuint index, GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglVertexAttrib3svARB)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib4NbvARB)(GLuint index, const GLbyte* v);
extern void (APIENTRY *gglVertexAttrib4NivARB)(GLuint index, const GLint* v);
extern void (APIENTRY *gglVertexAttrib4NsvARB)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib4NubARB)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void (APIENTRY *gglVertexAttrib4NubvARB)(GLuint index, const GLubyte* v);
extern void (APIENTRY *gglVertexAttrib4NuivARB)(GLuint index, const GLuint* v);
extern void (APIENTRY *gglVertexAttrib4NusvARB)(GLuint index, const GLushort* v);
extern void (APIENTRY *gglVertexAttrib4bvARB)(GLuint index, const GLbyte* v);
extern void (APIENTRY *gglVertexAttrib4dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglVertexAttrib4dvARB)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib4fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglVertexAttrib4fvARB)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib4ivARB)(GLuint index, const GLint* v);
extern void (APIENTRY *gglVertexAttrib4sARB)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY *gglVertexAttrib4svARB)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib4ubvARB)(GLuint index, const GLubyte* v);
extern void (APIENTRY *gglVertexAttrib4uivARB)(GLuint index, const GLuint* v);
extern void (APIENTRY *gglVertexAttrib4usvARB)(GLuint index, const GLushort* v);
extern void (APIENTRY *gglVertexAttribPointerARB)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglEnableVertexAttribArrayARB)(GLuint index);
extern void (APIENTRY *gglDisableVertexAttribArrayARB)(GLuint index);
extern void (APIENTRY *gglProgramStringARB)(GLenum target, GLenum format, GLsizei len, const GLvoid* string);
extern void (APIENTRY *gglBindProgramARB)(GLenum target, GLuint program);
extern void (APIENTRY *gglDeleteProgramsARB)(GLsizei n, const GLuint* programs);
extern void (APIENTRY *gglGenProgramsARB)(GLsizei n, GLuint* programs);
extern void (APIENTRY *gglProgramEnvParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglProgramEnvParameter4dvARB)(GLenum target, GLuint index, const GLdouble* params);
extern void (APIENTRY *gglProgramEnvParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglProgramEnvParameter4fvARB)(GLenum target, GLuint index, const GLfloat* params);
extern void (APIENTRY *gglProgramLocalParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglProgramLocalParameter4dvARB)(GLenum target, GLuint index, const GLdouble* params);
extern void (APIENTRY *gglProgramLocalParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglProgramLocalParameter4fvARB)(GLenum target, GLuint index, const GLfloat* params);
extern void (APIENTRY *gglGetProgramEnvParameterdvARB)(GLenum target, GLuint index, GLdouble* params);
extern void (APIENTRY *gglGetProgramEnvParameterfvARB)(GLenum target, GLuint index, GLfloat* params);
extern void (APIENTRY *gglGetProgramLocalParameterdvARB)(GLenum target, GLuint index, GLdouble* params);
extern void (APIENTRY *gglGetProgramLocalParameterfvARB)(GLenum target, GLuint index, GLfloat* params);
extern void (APIENTRY *gglGetProgramivARB)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetProgramStringARB)(GLenum target, GLenum pname, GLvoid* string);
extern void (APIENTRY *gglGetVertexAttribdvARB)(GLuint index, GLenum pname, GLdouble* params);
extern void (APIENTRY *gglGetVertexAttribfvARB)(GLuint index, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetVertexAttribivARB)(GLuint index, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVertexAttribPointervARB)(GLuint index, GLenum pname, GLvoid** pointer);
extern GLboolean (APIENTRY *gglIsProgramARB)(GLuint program);

/* GL_ARB_fragment_program */
/* All ARB_fragment_program entry points are shared with ARB_vertex_program. */

/* GL_ARB_vertex_buffer_object */
extern void (APIENTRY *gglBindBufferARB)(GLenum target, GLuint buffer);
extern void (APIENTRY *gglDeleteBuffersARB)(GLsizei n, const GLuint* buffers);
extern void (APIENTRY *gglGenBuffersARB)(GLsizei n, GLuint* buffers);
extern GLboolean (APIENTRY *gglIsBufferARB)(GLuint buffer);
extern void (APIENTRY *gglBufferDataARB)(GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage);
extern void (APIENTRY *gglBufferSubDataARB)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data);
extern void (APIENTRY *gglGetBufferSubDataARB)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data);
extern GLvoid* (APIENTRY *gglMapBufferARB)(GLenum target, GLenum access);
extern GLboolean (APIENTRY *gglUnmapBufferARB)(GLenum target);
extern void (APIENTRY *gglGetBufferParameterivARB)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetBufferPointervARB)(GLenum target, GLenum pname, GLvoid** params);

/* GL_ARB_occlusion_query */
extern void (APIENTRY *gglGenQueriesARB)(GLsizei n, GLuint* ids);
extern void (APIENTRY *gglDeleteQueriesARB)(GLsizei n, const GLuint* ids);
extern GLboolean (APIENTRY *gglIsQueryARB)(GLuint id);
extern void (APIENTRY *gglBeginQueryARB)(GLenum target, GLuint id);
extern void (APIENTRY *gglEndQueryARB)(GLenum target);
extern void (APIENTRY *gglGetQueryivARB)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetQueryObjectivARB)(GLuint id, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetQueryObjectuivARB)(GLuint id, GLenum pname, GLuint* params);

/* GL_ARB_shader_objects */
extern void (APIENTRY *gglDeleteObjectARB)(GLhandleARB obj);
extern GLhandleARB (APIENTRY *gglGetHandleARB)(GLenum pname);
extern void (APIENTRY *gglDetachObjectARB)(GLhandleARB containerObj, GLhandleARB attachedObj);
extern GLhandleARB (APIENTRY *gglCreateShaderObjectARB)(GLenum shaderType);
extern void (APIENTRY *gglShaderSourceARB)(GLhandleARB shaderObj, GLsizei count, const GLcharARB** string, const GLint* length);
extern void (APIENTRY *gglCompileShaderARB)(GLhandleARB shaderObj);
extern GLhandleARB (APIENTRY *gglCreateProgramObjectARB)();
extern void (APIENTRY *gglAttachObjectARB)(GLhandleARB containerObj, GLhandleARB obj);
extern void (APIENTRY *gglLinkProgramARB)(GLhandleARB programObj);
extern void (APIENTRY *gglUseProgramObjectARB)(GLhandleARB programObj);
extern void (APIENTRY *gglValidateProgramARB)(GLhandleARB programObj);
extern void (APIENTRY *gglUniform1fARB)(GLint location, GLfloat v0);
extern void (APIENTRY *gglUniform2fARB)(GLint location, GLfloat v0, GLfloat v1);
extern void (APIENTRY *gglUniform3fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (APIENTRY *gglUniform4fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (APIENTRY *gglUniform1iARB)(GLint location, GLint v0);
extern void (APIENTRY *gglUniform2iARB)(GLint location, GLint v0, GLint v1);
extern void (APIENTRY *gglUniform3iARB)(GLint location, GLint v0, GLint v1, GLint v2);
extern void (APIENTRY *gglUniform4iARB)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (APIENTRY *gglUniform1fvARB)(GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglUniform2fvARB)(GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglUniform3fvARB)(GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglUniform4fvARB)(GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglUniform1ivARB)(GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglUniform2ivARB)(GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglUniform3ivARB)(GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglUniform4ivARB)(GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglUniformMatrix2fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglUniformMatrix3fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglUniformMatrix4fvARB)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglGetObjectParameterfvARB)(GLhandleARB obj, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetObjectParameterivARB)(GLhandleARB obj, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetInfoLogARB)(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog);
extern void (APIENTRY *gglGetAttachedObjectsARB)(GLhandleARB containerObj, GLsizei maxCount, GLsizei* count, GLhandleARB* obj);
extern GLint (APIENTRY *gglGetUniformLocationARB)(GLhandleARB programObj, const GLcharARB* name);
extern void (APIENTRY *gglGetActiveUniformARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name);
extern void (APIENTRY *gglGetUniformfvARB)(GLhandleARB programObj, GLint location, GLfloat* params);
extern void (APIENTRY *gglGetUniformivARB)(GLhandleARB programObj, GLint location, GLint* params);
extern void (APIENTRY *gglGetShaderSourceARB)(GLhandleARB obj, GLsizei maxLength, GLsizei* length, GLcharARB* source);

/* GL_ARB_vertex_shader */
extern void (APIENTRY *gglBindAttribLocationARB)(GLhandleARB programObj, GLuint index, const GLcharARB* name);
extern void (APIENTRY *gglGetActiveAttribARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name);
extern GLint (APIENTRY *gglGetAttribLocationARB)(GLhandleARB programObj, const GLcharARB* name);

/* GL_ARB_fragment_shader */

/* GL_ARB_shading_language_100 */

/* GL_ARB_texture_non_power_of_two */

/* GL_ARB_point_sprite */

/* GL_ARB_fragment_program_shadow */

/* GL_ARB_draw_buffers */
extern void (APIENTRY *gglDrawBuffersARB)(GLsizei n, const GLenum* bufs);

/* GL_ARB_texture_rectangle */

/* GL_ARB_color_buffer_float */
extern void (APIENTRY *gglClampColorARB)(GLenum target, GLenum clamp);

/* GL_ARB_half_float_pixel */

/* GL_ARB_texture_float */

/* GL_ARB_pixel_buffer_object */

/* GL_ARB_depth_buffer_float */

/* GL_ARB_draw_instanced */
extern void (APIENTRY *gglDrawArraysInstancedARB)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
extern void (APIENTRY *gglDrawElementsInstancedARB)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);

/* GL_ARB_framebuffer_object */
extern GLboolean (APIENTRY *gglIsRenderbuffer)(GLuint renderbuffer);
extern void (APIENTRY *gglBindRenderbuffer)(GLenum target, GLuint renderbuffer);
extern void (APIENTRY *gglDeleteRenderbuffers)(GLsizei n, const GLuint* renderbuffers);
extern void (APIENTRY *gglGenRenderbuffers)(GLsizei n, GLuint* renderbuffers);
extern void (APIENTRY *gglRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint* params);
extern GLboolean (APIENTRY *gglIsFramebuffer)(GLuint framebuffer);
extern void (APIENTRY *gglBindFramebuffer)(GLenum target, GLuint framebuffer);
extern void (APIENTRY *gglDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers);
extern void (APIENTRY *gglGenFramebuffers)(GLsizei n, GLuint* framebuffers);
extern GLenum (APIENTRY *gglCheckFramebufferStatus)(GLenum target);
extern void (APIENTRY *gglFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY *gglFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY *gglFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void (APIENTRY *gglFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (APIENTRY *gglGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
extern void (APIENTRY *gglGenerateMipmap)(GLenum target);
extern void (APIENTRY *gglBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern void (APIENTRY *gglRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);

/* GL_ARB_framebuffer_sRGB */

/* GL_ARB_geometry_shader4 */
extern void (APIENTRY *gglProgramParameteriARB)(GLuint program, GLenum pname, GLint value);
extern void (APIENTRY *gglFramebufferTextureARB)(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void (APIENTRY *gglFramebufferTextureLayerARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void (APIENTRY *gglFramebufferTextureFaceARB)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

/* GL_ARB_half_float_vertex */

/* GL_ARB_instanced_arrays */
extern void (APIENTRY *gglVertexAttribDivisorARB)(GLuint index, GLuint divisor);

/* GL_ARB_map_buffer_range */
extern GLvoid* (APIENTRY *gglMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern void (APIENTRY *gglFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);

/* GL_ARB_texture_buffer_object */
extern void (APIENTRY *gglTexBufferARB)(GLenum target, GLenum internalformat, GLuint buffer);

/* GL_ARB_texture_compression_rgtc */

/* GL_ARB_texture_rg */

/* GL_ARB_vertex_array_object */
extern void (APIENTRY *gglBindVertexArray)(GLuint array);
extern void (APIENTRY *gglDeleteVertexArrays)(GLsizei n, const GLuint* arrays);
extern void (APIENTRY *gglGenVertexArrays)(GLsizei n, GLuint* arrays);
extern GLboolean (APIENTRY *gglIsVertexArray)(GLuint array);

/* GL_ARB_uniform_buffer_object */
extern void (APIENTRY *gglGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
extern void (APIENTRY *gglGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
extern GLuint (APIENTRY *gglGetUniformBlockIndex)(GLuint program, const GLchar* uniformBlockName);
extern void (APIENTRY *gglGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
extern void (APIENTRY *gglUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

/* GL_ARB_compatibility */

/* GL_ARB_copy_buffer */
extern void (APIENTRY *gglCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);

/* GL_ARB_shader_texture_lod */

/* GL_ARB_depth_clamp */

/* GL_ARB_draw_elements_base_vertex */
extern void (APIENTRY *gglDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
extern void (APIENTRY *gglDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices, GLint basevertex);
extern void (APIENTRY *gglDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei instancecount, GLint basevertex);
extern void (APIENTRY *gglMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid* const* indices, GLsizei drawcount, const GLint* basevertex);

/* GL_ARB_fragment_coord_conventions */

/* GL_ARB_provoking_vertex */
extern void (APIENTRY *gglProvokingVertex)(GLenum mode);

/* GL_ARB_seamless_cube_map */

/* GL_ARB_sync */
extern GLsync (APIENTRY *gglFenceSync)(GLenum condition, GLbitfield flags);
extern GLboolean (APIENTRY *gglIsSync)(GLsync sync);
extern void (APIENTRY *gglDeleteSync)(GLsync sync);
extern GLenum (APIENTRY *gglClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (APIENTRY *gglWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (APIENTRY *gglGetInteger64v)(GLenum pname, GLint64* params);
extern void (APIENTRY *gglGetSynciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);

/* GL_ARB_texture_multisample */
extern void (APIENTRY *gglTexImage2DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRY *gglTexImage3DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (APIENTRY *gglGetMultisamplefv)(GLenum pname, GLuint index, GLfloat* val);
extern void (APIENTRY *gglSampleMaski)(GLuint index, GLbitfield mask);

/* GL_ARB_vertex_array_bgra */

/* GL_ARB_draw_buffers_blend */
extern void (APIENTRY *gglBlendEquationiARB)(GLuint buf, GLenum mode);
extern void (APIENTRY *gglBlendEquationSeparateiARB)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
extern void (APIENTRY *gglBlendFunciARB)(GLuint buf, GLenum src, GLenum dst);
extern void (APIENTRY *gglBlendFuncSeparateiARB)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

/* GL_ARB_sample_shading */
extern void (APIENTRY *gglMinSampleShadingARB)(GLfloat value);

/* GL_ARB_texture_cube_map_array */

/* GL_ARB_texture_gather */

/* GL_ARB_texture_query_lod */

/* GL_ARB_shading_language_include */
extern void (APIENTRY *gglNamedStringARB)(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
extern void (APIENTRY *gglDeleteNamedStringARB)(GLint namelen, const GLchar* name);
extern void (APIENTRY *gglCompileShaderIncludeARB)(GLuint shader, GLsizei count, const GLchar** path, const GLint* length);
extern GLboolean (APIENTRY *gglIsNamedStringARB)(GLint namelen, const GLchar* name);
extern void (APIENTRY *gglGetNamedStringARB)(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
extern void (APIENTRY *gglGetNamedStringivARB)(GLint namelen, const GLchar* name, GLenum pname, GLint* params);

/* GL_ARB_texture_compression_bptc */

/* GL_ARB_blend_func_extended */
extern void (APIENTRY *gglBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
extern GLint (APIENTRY *gglGetFragDataIndex)(GLuint program, const GLchar* name);

/* GL_ARB_explicit_attrib_location */

/* GL_ARB_occlusion_query2 */

/* GL_ARB_sampler_objects */
extern void (APIENTRY *gglGenSamplers)(GLsizei count, GLuint* samplers);
extern void (APIENTRY *gglDeleteSamplers)(GLsizei count, const GLuint* samplers);
extern GLboolean (APIENTRY *gglIsSampler)(GLuint sampler);
extern void (APIENTRY *gglBindSampler)(GLuint unit, GLuint sampler);
extern void (APIENTRY *gglSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
extern void (APIENTRY *gglSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint* param);
extern void (APIENTRY *gglSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
extern void (APIENTRY *gglSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat* param);
extern void (APIENTRY *gglSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint* param);
extern void (APIENTRY *gglSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint* param);
extern void (APIENTRY *gglGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint* params);

/* GL_ARB_shader_bit_encoding */

/* GL_ARB_texture_rgb10_a2ui */

/* GL_ARB_texture_swizzle */

/* GL_ARB_timer_query */
extern void (APIENTRY *gglQueryCounter)(GLuint id, GLenum target);
extern void (APIENTRY *gglGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64* params);
extern void (APIENTRY *gglGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64* params);

/* GL_ARB_vertex_type_2_10_10_10_rev */
extern void (APIENTRY *gglVertexP2ui)(GLenum type, GLuint value);
extern void (APIENTRY *gglVertexP2uiv)(GLenum type, const GLuint* value);
extern void (APIENTRY *gglVertexP3ui)(GLenum type, GLuint value);
extern void (APIENTRY *gglVertexP3uiv)(GLenum type, const GLuint* value);
extern void (APIENTRY *gglVertexP4ui)(GLenum type, GLuint value);
extern void (APIENTRY *gglVertexP4uiv)(GLenum type, const GLuint* value);
extern void (APIENTRY *gglTexCoordP1ui)(GLenum type, GLuint coords);
extern void (APIENTRY *gglTexCoordP1uiv)(GLenum type, const GLuint* coords);
extern void (APIENTRY *gglTexCoordP2ui)(GLenum type, GLuint coords);
extern void (APIENTRY *gglTexCoordP2uiv)(GLenum type, const GLuint* coords);
extern void (APIENTRY *gglTexCoordP3ui)(GLenum type, GLuint coords);
extern void (APIENTRY *gglTexCoordP3uiv)(GLenum type, const GLuint* coords);
extern void (APIENTRY *gglTexCoordP4ui)(GLenum type, GLuint coords);
extern void (APIENTRY *gglTexCoordP4uiv)(GLenum type, const GLuint* coords);
extern void (APIENTRY *gglMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords);
extern void (APIENTRY *gglMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint* coords);
extern void (APIENTRY *gglMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords);
extern void (APIENTRY *gglMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint* coords);
extern void (APIENTRY *gglMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords);
extern void (APIENTRY *gglMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint* coords);
extern void (APIENTRY *gglMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords);
extern void (APIENTRY *gglMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint* coords);
extern void (APIENTRY *gglNormalP3ui)(GLenum type, GLuint coords);
extern void (APIENTRY *gglNormalP3uiv)(GLenum type, const GLuint* coords);
extern void (APIENTRY *gglColorP3ui)(GLenum type, GLuint color);
extern void (APIENTRY *gglColorP3uiv)(GLenum type, const GLuint* color);
extern void (APIENTRY *gglColorP4ui)(GLenum type, GLuint color);
extern void (APIENTRY *gglColorP4uiv)(GLenum type, const GLuint* color);
extern void (APIENTRY *gglSecondaryColorP3ui)(GLenum type, GLuint color);
extern void (APIENTRY *gglSecondaryColorP3uiv)(GLenum type, const GLuint* color);
extern void (APIENTRY *gglVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRY *gglVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
extern void (APIENTRY *gglVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRY *gglVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
extern void (APIENTRY *gglVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRY *gglVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
extern void (APIENTRY *gglVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (APIENTRY *gglVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);

/* GL_ARB_draw_indirect */
extern void (APIENTRY *gglDrawArraysIndirect)(GLenum mode, const GLvoid* indirect);
extern void (APIENTRY *gglDrawElementsIndirect)(GLenum mode, GLenum type, const GLvoid* indirect);

/* GL_ARB_gpu_shader5 */

/* GL_ARB_gpu_shader_fp64 */
extern void (APIENTRY *gglUniform1d)(GLint location, GLdouble x);
extern void (APIENTRY *gglUniform2d)(GLint location, GLdouble x, GLdouble y);
extern void (APIENTRY *gglUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglUniform1dv)(GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglUniform2dv)(GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglUniform3dv)(GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglUniform4dv)(GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglGetUniformdv)(GLuint program, GLint location, GLdouble* params);

/* GL_ARB_shader_subroutine */
extern GLint (APIENTRY *gglGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar* name);
extern GLuint (APIENTRY *gglGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar* name);
extern void (APIENTRY *gglGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
extern void (APIENTRY *gglGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
extern void (APIENTRY *gglGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name);
extern void (APIENTRY *gglUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint* indices);
extern void (APIENTRY *gglGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint* params);
extern void (APIENTRY *gglGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint* values);

/* GL_ARB_tessellation_shader */
extern void (APIENTRY *gglPatchParameteri)(GLenum pname, GLint value);
extern void (APIENTRY *gglPatchParameterfv)(GLenum pname, const GLfloat* values);

/* GL_ARB_texture_buffer_object_rgb32 */

/* GL_ARB_transform_feedback2 */
extern void (APIENTRY *gglBindTransformFeedback)(GLenum target, GLuint id);
extern void (APIENTRY *gglDeleteTransformFeedbacks)(GLsizei n, const GLuint* ids);
extern void (APIENTRY *gglGenTransformFeedbacks)(GLsizei n, GLuint* ids);
extern GLboolean (APIENTRY *gglIsTransformFeedback)(GLuint id);
extern void (APIENTRY *gglPauseTransformFeedback)();
extern void (APIENTRY *gglResumeTransformFeedback)();
extern void (APIENTRY *gglDrawTransformFeedback)(GLenum mode, GLuint id);

/* GL_ARB_transform_feedback3 */
extern void (APIENTRY *gglDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
extern void (APIENTRY *gglBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
extern void (APIENTRY *gglEndQueryIndexed)(GLenum target, GLuint index);
extern void (APIENTRY *gglGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint* params);

/* GL_ARB_ES2_compatibility */
extern void (APIENTRY *gglReleaseShaderCompiler)();
extern void (APIENTRY *gglShaderBinary)(GLsizei count, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
extern void (APIENTRY *gglGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
extern void (APIENTRY *gglDepthRangef)(GLfloat n, GLfloat f);
extern void (APIENTRY *gglClearDepthf)(GLfloat d);

/* GL_ARB_get_program_binary */
extern void (APIENTRY *gglGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
extern void (APIENTRY *gglProgramBinary)(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
extern void (APIENTRY *gglProgramParameteri)(GLuint program, GLenum pname, GLint value);

/* GL_ARB_separate_shader_objects */
extern void (APIENTRY *gglUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
extern void (APIENTRY *gglActiveShaderProgram)(GLuint pipeline, GLuint program);
extern GLuint (APIENTRY *gglCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar* const* strings);
extern void (APIENTRY *gglBindProgramPipeline)(GLuint pipeline);
extern void (APIENTRY *gglDeleteProgramPipelines)(GLsizei n, const GLuint* pipelines);
extern void (APIENTRY *gglGenProgramPipelines)(GLsizei n, GLuint* pipelines);
extern GLboolean (APIENTRY *gglIsProgramPipeline)(GLuint pipeline);
extern void (APIENTRY *gglGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint* params);
extern void (APIENTRY *gglProgramUniform1i)(GLuint program, GLint location, GLint v0);
extern void (APIENTRY *gglProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
extern void (APIENTRY *gglProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
extern void (APIENTRY *gglProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
extern void (APIENTRY *gglProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
extern void (APIENTRY *gglProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
extern void (APIENTRY *gglProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
extern void (APIENTRY *gglProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
extern void (APIENTRY *gglProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
extern void (APIENTRY *gglProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (APIENTRY *gglProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
extern void (APIENTRY *gglProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (APIENTRY *gglProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (APIENTRY *gglProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (APIENTRY *gglProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
extern void (APIENTRY *gglProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (APIENTRY *gglProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglValidateProgramPipeline)(GLuint pipeline);
extern void (APIENTRY *gglGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);

/* GL_ARB_vertex_attrib_64bit */
extern void (APIENTRY *gglVertexAttribL1d)(GLuint index, GLdouble x);
extern void (APIENTRY *gglVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRY *gglVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglVertexAttribL1dv)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribL2dv)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribL3dv)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribL4dv)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble* params);

/* GL_ARB_viewport_array */
extern void (APIENTRY *gglViewportArrayv)(GLuint first, GLsizei count, const GLfloat* v);
extern void (APIENTRY *gglViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
extern void (APIENTRY *gglViewportIndexedfv)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglScissorArrayv)(GLuint first, GLsizei count, const GLint* v);
extern void (APIENTRY *gglScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
extern void (APIENTRY *gglScissorIndexedv)(GLuint index, const GLint* v);
extern void (APIENTRY *gglDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble* v);
extern void (APIENTRY *gglDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
extern void (APIENTRY *gglGetFloati_v)(GLenum target, GLuint index, GLfloat* data);
extern void (APIENTRY *gglGetDoublei_v)(GLenum target, GLuint index, GLdouble* data);

/* GL_ARB_cl_event */
extern GLsync (APIENTRY *gglCreateSyncFromCLeventARB)(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);

/* GL_ARB_debug_output */
extern void (APIENTRY *gglDebugMessageControlARB)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
extern void (APIENTRY *gglDebugMessageInsertARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
extern void (APIENTRY *gglDebugMessageCallbackARB)(GLDEBUGPROCARB callback, const GLvoid* userParam);
extern GLuint (APIENTRY *gglGetDebugMessageLogARB)(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);

/* GL_ARB_robustness */
extern GLenum (APIENTRY *gglGetGraphicsResetStatusARB)();
extern void (APIENTRY *gglGetnMapdvARB)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
extern void (APIENTRY *gglGetnMapfvARB)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
extern void (APIENTRY *gglGetnMapivARB)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
extern void (APIENTRY *gglGetnPixelMapfvARB)(GLenum map, GLsizei bufSize, GLfloat* values);
extern void (APIENTRY *gglGetnPixelMapuivARB)(GLenum map, GLsizei bufSize, GLuint* values);
extern void (APIENTRY *gglGetnPixelMapusvARB)(GLenum map, GLsizei bufSize, GLushort* values);
extern void (APIENTRY *gglGetnPolygonStippleARB)(GLsizei bufSize, GLubyte* pattern);
extern void (APIENTRY *gglGetnColorTableARB)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* table);
extern void (APIENTRY *gglGetnConvolutionFilterARB)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid* image);
extern void (APIENTRY *gglGetnSeparableFilterARB)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span);
extern void (APIENTRY *gglGetnHistogramARB)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
extern void (APIENTRY *gglGetnMinmaxARB)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid* values);
extern void (APIENTRY *gglGetnTexImageARB)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* img);
extern void (APIENTRY *gglReadnPixelsARB)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid* data);
extern void (APIENTRY *gglGetnCompressedTexImageARB)(GLenum target, GLint lod, GLsizei bufSize, GLvoid* img);
extern void (APIENTRY *gglGetnUniformfvARB)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
extern void (APIENTRY *gglGetnUniformivARB)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
extern void (APIENTRY *gglGetnUniformuivARB)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
extern void (APIENTRY *gglGetnUniformdvARB)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);

/* GL_ARB_shader_stencil_export */

/* GL_ARB_base_instance */
extern void (APIENTRY *gglDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
extern void (APIENTRY *gglDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
extern void (APIENTRY *gglDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);

/* GL_ARB_shading_language_420pack */

/* GL_ARB_transform_feedback_instanced */
extern void (APIENTRY *gglDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
extern void (APIENTRY *gglDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

/* GL_ARB_compressed_texture_pixel_storage */

/* GL_ARB_conservative_depth */

/* GL_ARB_internalformat_query */
extern void (APIENTRY *gglGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);

/* GL_ARB_map_buffer_alignment */

/* GL_ARB_shader_atomic_counters */
extern void (APIENTRY *gglGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);

/* GL_ARB_shader_image_load_store */
extern void (APIENTRY *gglBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
extern void (APIENTRY *gglMemoryBarrier)(GLbitfield barriers);

/* GL_ARB_shading_language_packing */

/* GL_ARB_texture_storage */
extern void (APIENTRY *gglTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
extern void (APIENTRY *gglTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
extern void (APIENTRY *gglTextureStorage1DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
extern void (APIENTRY *gglTextureStorage2DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglTextureStorage3DEXT)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);

/* GL_KHR_texture_compression_astc_ldr */

/* GL_KHR_debug */
extern void (APIENTRY *gglDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
extern void (APIENTRY *gglDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
extern void (APIENTRY *gglDebugMessageCallback)(GLDEBUGPROC callback, const void* userParam);
extern GLuint (APIENTRY *gglGetDebugMessageLog)(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
extern void (APIENTRY *gglPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
extern void (APIENTRY *gglPopDebugGroup)();
extern void (APIENTRY *gglObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
extern void (APIENTRY *gglGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
extern void (APIENTRY *gglObjectPtrLabel)(const void* ptr, GLsizei length, const GLchar* label);
extern void (APIENTRY *gglGetObjectPtrLabel)(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);

/* GL_ARB_arrays_of_arrays */

/* GL_ARB_clear_buffer_object */
extern void (APIENTRY *gglClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
extern void (APIENTRY *gglClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
extern void (APIENTRY *gglClearNamedBufferDataEXT)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
extern void (APIENTRY *gglClearNamedBufferSubDataEXT)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);

/* GL_ARB_compute_shader */
extern void (APIENTRY *gglDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
extern void (APIENTRY *gglDispatchComputeIndirect)(GLintptr indirect);

/* GL_ARB_copy_image */
extern void (APIENTRY *gglCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);

/* GL_ARB_texture_view */
extern void (APIENTRY *gglTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);

/* GL_ARB_vertex_attrib_binding */
extern void (APIENTRY *gglBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern void (APIENTRY *gglVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern void (APIENTRY *gglVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRY *gglVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRY *gglVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
extern void (APIENTRY *gglVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
extern void (APIENTRY *gglVertexArrayBindVertexBufferEXT)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern void (APIENTRY *gglVertexArrayVertexAttribFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern void (APIENTRY *gglVertexArrayVertexAttribIFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRY *gglVertexArrayVertexAttribLFormatEXT)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern void (APIENTRY *gglVertexArrayVertexAttribBindingEXT)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
extern void (APIENTRY *gglVertexArrayVertexBindingDivisorEXT)(GLuint vaobj, GLuint bindingindex, GLuint divisor);

/* GL_ARB_robustness_isolation */

/* GL_ARB_ES3_compatibility */

/* GL_ARB_explicit_uniform_location */

/* GL_ARB_fragment_layer_viewport */

/* GL_ARB_framebuffer_no_attachments */
extern void (APIENTRY *gglFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglNamedFramebufferParameteriEXT)(GLuint framebuffer, GLenum pname, GLint param);
extern void (APIENTRY *gglGetNamedFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint* params);

/* GL_ARB_internalformat_query2 */
extern void (APIENTRY *gglGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);

/* GL_ARB_invalidate_subdata */
extern void (APIENTRY *gglInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
extern void (APIENTRY *gglInvalidateTexImage)(GLuint texture, GLint level);
extern void (APIENTRY *gglInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
extern void (APIENTRY *gglInvalidateBufferData)(GLuint buffer);
extern void (APIENTRY *gglInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum* attachments);
extern void (APIENTRY *gglInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);

/* GL_ARB_multi_draw_indirect */
extern void (APIENTRY *gglMultiDrawArraysIndirect)(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
extern void (APIENTRY *gglMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);

/* GL_ARB_program_interface_query */
extern void (APIENTRY *gglGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
extern GLuint (APIENTRY *gglGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar* name);
extern void (APIENTRY *gglGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
extern void (APIENTRY *gglGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
extern GLint (APIENTRY *gglGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar* name);
extern GLint (APIENTRY *gglGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar* name);

/* GL_ARB_robust_buffer_access_behavior */

/* GL_ARB_shader_image_size */

/* GL_ARB_shader_storage_buffer_object */
extern void (APIENTRY *gglShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);

/* GL_ARB_stencil_texturing */

/* GL_ARB_texture_buffer_range */
extern void (APIENTRY *gglTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRY *gglTextureBufferRangeEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);

/* GL_ARB_texture_query_levels */

/* GL_ARB_texture_storage_multisample */
extern void (APIENTRY *gglTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRY *gglTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (APIENTRY *gglTextureStorage2DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (APIENTRY *gglTextureStorage3DMultisampleEXT)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);

/* GL_EXT_abgr */

/* GL_EXT_blend_color */
extern void (APIENTRY *gglBlendColorEXT)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

/* GL_EXT_polygon_offset */
extern void (APIENTRY *gglPolygonOffsetEXT)(GLfloat factor, GLfloat bias);

/* GL_EXT_texture */

/* GL_EXT_texture3D */
extern void (APIENTRY *gglTexImage3DEXT)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTexSubImage3DEXT)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);

/* GL_SGIS_texture_filter4 */
extern void (APIENTRY *gglGetTexFilterFuncSGIS)(GLenum target, GLenum filter, GLfloat* weights);
extern void (APIENTRY *gglTexFilterFuncSGIS)(GLenum target, GLenum filter, GLsizei n, const GLfloat* weights);

/* GL_EXT_copy_texture */
extern void (APIENTRY *gglCopyTexSubImage3DEXT)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

/* GL_EXT_histogram */
extern void (APIENTRY *gglGetHistogramEXT)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
extern void (APIENTRY *gglGetHistogramParameterfvEXT)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetHistogramParameterivEXT)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMinmaxEXT)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
extern void (APIENTRY *gglGetMinmaxParameterfvEXT)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMinmaxParameterivEXT)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglHistogramEXT)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
extern void (APIENTRY *gglMinmaxEXT)(GLenum target, GLenum internalformat, GLboolean sink);
extern void (APIENTRY *gglResetHistogramEXT)(GLenum target);
extern void (APIENTRY *gglResetMinmaxEXT)(GLenum target);

/* GL_EXT_convolution */
extern void (APIENTRY *gglConvolutionFilter1DEXT)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* image);
extern void (APIENTRY *gglConvolutionFilter2DEXT)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image);
extern void (APIENTRY *gglConvolutionParameterfEXT)(GLenum target, GLenum pname, GLfloat params);
extern void (APIENTRY *gglConvolutionParameterfvEXT)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglConvolutionParameteriEXT)(GLenum target, GLenum pname, GLint params);
extern void (APIENTRY *gglConvolutionParameterivEXT)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglCopyConvolutionFilter1DEXT)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
extern void (APIENTRY *gglCopyConvolutionFilter2DEXT)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglGetConvolutionFilterEXT)(GLenum target, GLenum format, GLenum type, GLvoid* image);
extern void (APIENTRY *gglGetConvolutionParameterfvEXT)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetConvolutionParameterivEXT)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetSeparableFilterEXT)(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span);
extern void (APIENTRY *gglSeparableFilter2DEXT)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column);

/* GL_SGI_color_matrix */

/* GL_SGI_color_table */
extern void (APIENTRY *gglColorTableSGI)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
extern void (APIENTRY *gglColorTableParameterfvSGI)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglColorTableParameterivSGI)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglCopyColorTableSGI)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
extern void (APIENTRY *gglGetColorTableSGI)(GLenum target, GLenum format, GLenum type, GLvoid* table);
extern void (APIENTRY *gglGetColorTableParameterfvSGI)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetColorTableParameterivSGI)(GLenum target, GLenum pname, GLint* params);

/* GL_SGIX_pixel_texture */
extern void (APIENTRY *gglPixelTexGenSGIX)(GLenum mode);

/* GL_SGIS_pixel_texture */
extern void (APIENTRY *gglPixelTexGenParameteriSGIS)(GLenum pname, GLint param);
extern void (APIENTRY *gglPixelTexGenParameterivSGIS)(GLenum pname, const GLint* params);
extern void (APIENTRY *gglPixelTexGenParameterfSGIS)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglPixelTexGenParameterfvSGIS)(GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglGetPixelTexGenParameterivSGIS)(GLenum pname, GLint* params);
extern void (APIENTRY *gglGetPixelTexGenParameterfvSGIS)(GLenum pname, GLfloat* params);

/* GL_SGIS_texture4D */
extern void (APIENTRY *gglTexImage4DSGIS)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTexSubImage4DSGIS)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid* pixels);

/* GL_SGI_texture_color_table */

/* GL_EXT_cmyka */

/* GL_SGIS_detail_texture */
extern void (APIENTRY *gglDetailTexFuncSGIS)(GLenum target, GLsizei n, const GLfloat* points);
extern void (APIENTRY *gglGetDetailTexFuncSGIS)(GLenum target, GLfloat* points);

/* GL_SGIS_sharpen_texture */
extern void (APIENTRY *gglSharpenTexFuncSGIS)(GLenum target, GLsizei n, const GLfloat* points);
extern void (APIENTRY *gglGetSharpenTexFuncSGIS)(GLenum target, GLfloat* points);

/* GL_EXT_packed_pixels */

/* GL_SGIS_texture_lod */

/* GL_SGIS_multisample */
extern void (APIENTRY *gglSampleMaskSGIS)(GLclampf value, GLboolean invert);
extern void (APIENTRY *gglSamplePatternSGIS)(GLenum pattern);

/* GL_EXT_rescale_normal */

/* GL_EXT_vertex_array */
extern void (APIENTRY *gglColorPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
extern void (APIENTRY *gglEdgeFlagPointerEXT)(GLsizei stride, GLsizei count, const GLboolean* pointer);
extern void (APIENTRY *gglIndexPointerEXT)(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
extern void (APIENTRY *gglNormalPointerEXT)(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
extern void (APIENTRY *gglTexCoordPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
extern void (APIENTRY *gglVertexPointerEXT)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);

/* GL_EXT_misc_attribute */

/* GL_SGIS_generate_mipmap */

/* GL_SGIX_clipmap */

/* GL_SGIX_shadow */

/* GL_SGIS_texture_edge_clamp */

/* GL_SGIS_texture_border_clamp */

/* GL_EXT_blend_minmax */
extern void (APIENTRY *gglBlendEquationEXT)(GLenum mode);

/* GL_EXT_blend_subtract */

/* GL_EXT_blend_logic_op */

/* GL_SGIX_interlace */

/* GL_SGIX_pixel_tiles */

/* GL_SGIX_texture_select */

/* GL_SGIX_sprite */
extern void (APIENTRY *gglSpriteParameterfSGIX)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglSpriteParameterfvSGIX)(GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglSpriteParameteriSGIX)(GLenum pname, GLint param);
extern void (APIENTRY *gglSpriteParameterivSGIX)(GLenum pname, const GLint* params);

/* GL_SGIX_texture_multi_buffer */

/* GL_EXT_point_parameters */
extern void (APIENTRY *gglPointParameterfEXT)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglPointParameterfvEXT)(GLenum pname, const GLfloat* params);

/* GL_SGIS_point_parameters */
extern void (APIENTRY *gglPointParameterfSGIS)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglPointParameterfvSGIS)(GLenum pname, const GLfloat* params);

/* GL_SGIX_instruments */
extern GLint (APIENTRY *gglGetInstrumentsSGIX)();
extern void (APIENTRY *gglInstrumentsBufferSGIX)(GLsizei size, GLint* buffer);
extern GLint (APIENTRY *gglPollInstrumentsSGIX)(GLint* marker_p);
extern void (APIENTRY *gglReadInstrumentsSGIX)(GLint marker);
extern void (APIENTRY *gglStartInstrumentsSGIX)();
extern void (APIENTRY *gglStopInstrumentsSGIX)(GLint marker);

/* GL_SGIX_texture_scale_bias */

/* GL_SGIX_framezoom */
extern void (APIENTRY *gglFrameZoomSGIX)(GLint factor);

/* GL_SGIX_tag_sample_buffer */
extern void (APIENTRY *gglTagSampleBufferSGIX)();

/* GL_SGIX_polynomial_ffd */
extern void (APIENTRY *gglDeformationMap3dSGIX)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble* points);
extern void (APIENTRY *gglDeformationMap3fSGIX)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat* points);
extern void (APIENTRY *gglDeformSGIX)(GLbitfield mask);
extern void (APIENTRY *gglLoadIdentityDeformationMapSGIX)(GLbitfield mask);

/* GL_SGIX_reference_plane */
extern void (APIENTRY *gglReferencePlaneSGIX)(const GLdouble* equation);

/* GL_SGIX_flush_raster */
extern void (APIENTRY *gglFlushRasterSGIX)();

/* GL_SGIX_depth_texture */

/* GL_SGIS_fog_function */
extern void (APIENTRY *gglFogFuncSGIS)(GLsizei n, const GLfloat* points);
extern void (APIENTRY *gglGetFogFuncSGIS)(GLfloat* points);

/* GL_SGIX_fog_offset */

/* GL_HP_image_transform */
extern void (APIENTRY *gglImageTransformParameteriHP)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglImageTransformParameterfHP)(GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglImageTransformParameterivHP)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglImageTransformParameterfvHP)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglGetImageTransformParameterivHP)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetImageTransformParameterfvHP)(GLenum target, GLenum pname, GLfloat* params);

/* GL_HP_convolution_border_modes */

/* GL_SGIX_texture_add_env */

/* GL_EXT_color_subtable */
extern void (APIENTRY *gglColorSubTableEXT)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data);
extern void (APIENTRY *gglCopyColorSubTableEXT)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);

/* GL_PGI_vertex_hints */

/* GL_PGI_misc_hints */
extern void (APIENTRY *gglHintPGI)(GLenum target, GLint mode);

/* GL_EXT_paletted_texture */
extern void (APIENTRY *gglColorTableEXT)(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
extern void (APIENTRY *gglGetColorTableEXT)(GLenum target, GLenum format, GLenum type, GLvoid* data);
extern void (APIENTRY *gglGetColorTableParameterivEXT)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetColorTableParameterfvEXT)(GLenum target, GLenum pname, GLfloat* params);

/* GL_EXT_clip_volume_hint */

/* GL_SGIX_list_priority */
extern void (APIENTRY *gglGetListParameterfvSGIX)(GLuint list, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetListParameterivSGIX)(GLuint list, GLenum pname, GLint* params);
extern void (APIENTRY *gglListParameterfSGIX)(GLuint list, GLenum pname, GLfloat param);
extern void (APIENTRY *gglListParameterfvSGIX)(GLuint list, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglListParameteriSGIX)(GLuint list, GLenum pname, GLint param);
extern void (APIENTRY *gglListParameterivSGIX)(GLuint list, GLenum pname, const GLint* params);

/* GL_SGIX_ir_instrument1 */

/* GL_SGIX_calligraphic_fragment */

/* GL_SGIX_texture_lod_bias */

/* GL_SGIX_shadow_ambient */

/* GL_EXT_index_texture */

/* GL_EXT_index_material */
extern void (APIENTRY *gglIndexMaterialEXT)(GLenum face, GLenum mode);

/* GL_EXT_index_func */
extern void (APIENTRY *gglIndexFuncEXT)(GLenum func, GLclampf ref);

/* GL_EXT_index_array_formats */

/* GL_EXT_compiled_vertex_array */
extern void (APIENTRY *gglLockArraysEXT)(GLint first, GLsizei count);
extern void (APIENTRY *gglUnlockArraysEXT)();

/* GL_EXT_cull_vertex */
extern void (APIENTRY *gglCullParameterdvEXT)(GLenum pname, GLdouble* params);
extern void (APIENTRY *gglCullParameterfvEXT)(GLenum pname, GLfloat* params);

/* GL_SGIX_ycrcb */

/* GL_SGIX_fragment_lighting */
extern void (APIENTRY *gglFragmentColorMaterialSGIX)(GLenum face, GLenum mode);
extern void (APIENTRY *gglFragmentLightfSGIX)(GLenum light, GLenum pname, GLfloat param);
extern void (APIENTRY *gglFragmentLightfvSGIX)(GLenum light, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglFragmentLightiSGIX)(GLenum light, GLenum pname, GLint param);
extern void (APIENTRY *gglFragmentLightivSGIX)(GLenum light, GLenum pname, const GLint* params);
extern void (APIENTRY *gglFragmentLightModelfSGIX)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglFragmentLightModelfvSGIX)(GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglFragmentLightModeliSGIX)(GLenum pname, GLint param);
extern void (APIENTRY *gglFragmentLightModelivSGIX)(GLenum pname, const GLint* params);
extern void (APIENTRY *gglFragmentMaterialfSGIX)(GLenum face, GLenum pname, GLfloat param);
extern void (APIENTRY *gglFragmentMaterialfvSGIX)(GLenum face, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglFragmentMaterialiSGIX)(GLenum face, GLenum pname, GLint param);
extern void (APIENTRY *gglFragmentMaterialivSGIX)(GLenum face, GLenum pname, const GLint* params);
extern void (APIENTRY *gglGetFragmentLightfvSGIX)(GLenum light, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetFragmentLightivSGIX)(GLenum light, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetFragmentMaterialfvSGIX)(GLenum face, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetFragmentMaterialivSGIX)(GLenum face, GLenum pname, GLint* params);
extern void (APIENTRY *gglLightEnviSGIX)(GLenum pname, GLint param);

/* GL_IBM_rasterpos_clip */

/* GL_HP_texture_lighting */

/* GL_EXT_draw_range_elements */
extern void (APIENTRY *gglDrawRangeElementsEXT)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);

/* GL_WIN_phong_shading */

/* GL_WIN_specular_fog */

/* GL_EXT_light_texture */
extern void (APIENTRY *gglApplyTextureEXT)(GLenum mode);
extern void (APIENTRY *gglTextureLightEXT)(GLenum pname);
extern void (APIENTRY *gglTextureMaterialEXT)(GLenum face, GLenum mode);

/* GL_SGIX_blend_alpha_minmax */

/* GL_EXT_bgra */

/* GL_SGIX_async */
extern void (APIENTRY *gglAsyncMarkerSGIX)(GLuint marker);
extern GLint (APIENTRY *gglFinishAsyncSGIX)(GLuint* markerp);
extern GLint (APIENTRY *gglPollAsyncSGIX)(GLuint* markerp);
extern GLuint (APIENTRY *gglGenAsyncMarkersSGIX)(GLsizei range);
extern void (APIENTRY *gglDeleteAsyncMarkersSGIX)(GLuint marker, GLsizei range);
extern GLboolean (APIENTRY *gglIsAsyncMarkerSGIX)(GLuint marker);

/* GL_SGIX_async_pixel */

/* GL_SGIX_async_histogram */

/* GL_INTEL_parallel_arrays */
extern void (APIENTRY *gglVertexPointervINTEL)(GLint size, GLenum type, const GLvoid** pointer);
extern void (APIENTRY *gglNormalPointervINTEL)(GLenum type, const GLvoid** pointer);
extern void (APIENTRY *gglColorPointervINTEL)(GLint size, GLenum type, const GLvoid** pointer);
extern void (APIENTRY *gglTexCoordPointervINTEL)(GLint size, GLenum type, const GLvoid** pointer);

/* GL_HP_occlusion_test */

/* GL_EXT_pixel_transform */
extern void (APIENTRY *gglPixelTransformParameteriEXT)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglPixelTransformParameterfEXT)(GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglPixelTransformParameterivEXT)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglPixelTransformParameterfvEXT)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglGetPixelTransformParameterivEXT)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetPixelTransformParameterfvEXT)(GLenum target, GLenum pname, GLfloat* params);

/* GL_EXT_pixel_transform_color_table */

/* GL_EXT_shared_texture_palette */

/* GL_EXT_separate_specular_color */

/* GL_EXT_secondary_color */
extern void (APIENTRY *gglSecondaryColor3bEXT)(GLbyte red, GLbyte green, GLbyte blue);
extern void (APIENTRY *gglSecondaryColor3bvEXT)(const GLbyte* v);
extern void (APIENTRY *gglSecondaryColor3dEXT)(GLdouble red, GLdouble green, GLdouble blue);
extern void (APIENTRY *gglSecondaryColor3dvEXT)(const GLdouble* v);
extern void (APIENTRY *gglSecondaryColor3fEXT)(GLfloat red, GLfloat green, GLfloat blue);
extern void (APIENTRY *gglSecondaryColor3fvEXT)(const GLfloat* v);
extern void (APIENTRY *gglSecondaryColor3iEXT)(GLint red, GLint green, GLint blue);
extern void (APIENTRY *gglSecondaryColor3ivEXT)(const GLint* v);
extern void (APIENTRY *gglSecondaryColor3sEXT)(GLshort red, GLshort green, GLshort blue);
extern void (APIENTRY *gglSecondaryColor3svEXT)(const GLshort* v);
extern void (APIENTRY *gglSecondaryColor3ubEXT)(GLubyte red, GLubyte green, GLubyte blue);
extern void (APIENTRY *gglSecondaryColor3ubvEXT)(const GLubyte* v);
extern void (APIENTRY *gglSecondaryColor3uiEXT)(GLuint red, GLuint green, GLuint blue);
extern void (APIENTRY *gglSecondaryColor3uivEXT)(const GLuint* v);
extern void (APIENTRY *gglSecondaryColor3usEXT)(GLushort red, GLushort green, GLushort blue);
extern void (APIENTRY *gglSecondaryColor3usvEXT)(const GLushort* v);
extern void (APIENTRY *gglSecondaryColorPointerEXT)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

/* GL_EXT_texture_perturb_normal */
extern void (APIENTRY *gglTextureNormalEXT)(GLenum mode);

/* GL_EXT_multi_draw_arrays */
extern void (APIENTRY *gglMultiDrawArraysEXT)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount);
extern void (APIENTRY *gglMultiDrawElementsEXT)(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount);

/* GL_EXT_fog_coord */
extern void (APIENTRY *gglFogCoordfEXT)(GLfloat coord);
extern void (APIENTRY *gglFogCoordfvEXT)(const GLfloat* coord);
extern void (APIENTRY *gglFogCoorddEXT)(GLdouble coord);
extern void (APIENTRY *gglFogCoorddvEXT)(const GLdouble* coord);
extern void (APIENTRY *gglFogCoordPointerEXT)(GLenum type, GLsizei stride, const GLvoid* pointer);

/* GL_REND_screen_coordinates */

/* GL_EXT_coordinate_frame */
extern void (APIENTRY *gglTangent3bEXT)(GLbyte tx, GLbyte ty, GLbyte tz);
extern void (APIENTRY *gglTangent3bvEXT)(const GLbyte* v);
extern void (APIENTRY *gglTangent3dEXT)(GLdouble tx, GLdouble ty, GLdouble tz);
extern void (APIENTRY *gglTangent3dvEXT)(const GLdouble* v);
extern void (APIENTRY *gglTangent3fEXT)(GLfloat tx, GLfloat ty, GLfloat tz);
extern void (APIENTRY *gglTangent3fvEXT)(const GLfloat* v);
extern void (APIENTRY *gglTangent3iEXT)(GLint tx, GLint ty, GLint tz);
extern void (APIENTRY *gglTangent3ivEXT)(const GLint* v);
extern void (APIENTRY *gglTangent3sEXT)(GLshort tx, GLshort ty, GLshort tz);
extern void (APIENTRY *gglTangent3svEXT)(const GLshort* v);
extern void (APIENTRY *gglBinormal3bEXT)(GLbyte bx, GLbyte by, GLbyte bz);
extern void (APIENTRY *gglBinormal3bvEXT)(const GLbyte* v);
extern void (APIENTRY *gglBinormal3dEXT)(GLdouble bx, GLdouble by, GLdouble bz);
extern void (APIENTRY *gglBinormal3dvEXT)(const GLdouble* v);
extern void (APIENTRY *gglBinormal3fEXT)(GLfloat bx, GLfloat by, GLfloat bz);
extern void (APIENTRY *gglBinormal3fvEXT)(const GLfloat* v);
extern void (APIENTRY *gglBinormal3iEXT)(GLint bx, GLint by, GLint bz);
extern void (APIENTRY *gglBinormal3ivEXT)(const GLint* v);
extern void (APIENTRY *gglBinormal3sEXT)(GLshort bx, GLshort by, GLshort bz);
extern void (APIENTRY *gglBinormal3svEXT)(const GLshort* v);
extern void (APIENTRY *gglTangentPointerEXT)(GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglBinormalPointerEXT)(GLenum type, GLsizei stride, const GLvoid* pointer);

/* GL_EXT_texture_env_combine */

/* GL_APPLE_specular_vector */

/* GL_APPLE_transform_hint */

/* GL_SGIX_fog_scale */

/* GL_SUNX_constant_data */
extern void (APIENTRY *gglFinishTextureSUNX)();

/* GL_SUN_global_alpha */
extern void (APIENTRY *gglGlobalAlphaFactorbSUN)(GLbyte factor);
extern void (APIENTRY *gglGlobalAlphaFactorsSUN)(GLshort factor);
extern void (APIENTRY *gglGlobalAlphaFactoriSUN)(GLint factor);
extern void (APIENTRY *gglGlobalAlphaFactorfSUN)(GLfloat factor);
extern void (APIENTRY *gglGlobalAlphaFactordSUN)(GLdouble factor);
extern void (APIENTRY *gglGlobalAlphaFactorubSUN)(GLubyte factor);
extern void (APIENTRY *gglGlobalAlphaFactorusSUN)(GLushort factor);
extern void (APIENTRY *gglGlobalAlphaFactoruiSUN)(GLuint factor);

/* GL_SUN_triangle_list */
extern void (APIENTRY *gglReplacementCodeuiSUN)(GLuint code);
extern void (APIENTRY *gglReplacementCodeusSUN)(GLushort code);
extern void (APIENTRY *gglReplacementCodeubSUN)(GLubyte code);
extern void (APIENTRY *gglReplacementCodeuivSUN)(const GLuint* code);
extern void (APIENTRY *gglReplacementCodeusvSUN)(const GLushort* code);
extern void (APIENTRY *gglReplacementCodeubvSUN)(const GLubyte* code);
extern void (APIENTRY *gglReplacementCodePointerSUN)(GLenum type, GLsizei stride, const GLvoid** pointer);

/* GL_SUN_vertex */
extern void (APIENTRY *gglColor4ubVertex2fSUN)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
extern void (APIENTRY *gglColor4ubVertex2fvSUN)(const GLubyte* c, const GLfloat* v);
extern void (APIENTRY *gglColor4ubVertex3fSUN)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglColor4ubVertex3fvSUN)(const GLubyte* c, const GLfloat* v);
extern void (APIENTRY *gglColor3fVertex3fSUN)(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglColor3fVertex3fvSUN)(const GLfloat* c, const GLfloat* v);
extern void (APIENTRY *gglNormal3fVertex3fSUN)(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglNormal3fVertex3fvSUN)(const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglColor4fNormal3fVertex3fSUN)(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglColor4fNormal3fVertex3fvSUN)(const GLfloat* c, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglTexCoord2fVertex3fSUN)(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglTexCoord2fVertex3fvSUN)(const GLfloat* tc, const GLfloat* v);
extern void (APIENTRY *gglTexCoord4fVertex4fSUN)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglTexCoord4fVertex4fvSUN)(const GLfloat* tc, const GLfloat* v);
extern void (APIENTRY *gglTexCoord2fColor4ubVertex3fSUN)(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglTexCoord2fColor4ubVertex3fvSUN)(const GLfloat* tc, const GLubyte* c, const GLfloat* v);
extern void (APIENTRY *gglTexCoord2fColor3fVertex3fSUN)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglTexCoord2fColor3fVertex3fvSUN)(const GLfloat* tc, const GLfloat* c, const GLfloat* v);
extern void (APIENTRY *gglTexCoord2fNormal3fVertex3fSUN)(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglTexCoord2fNormal3fVertex3fvSUN)(const GLfloat* tc, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglTexCoord2fColor4fNormal3fVertex3fSUN)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglTexCoord4fColor4fNormal3fVertex4fSUN)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglTexCoord4fColor4fNormal3fVertex4fvSUN)(const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiVertex3fSUN)(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiVertex3fvSUN)(const GLuint* rc, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiColor4ubVertex3fSUN)(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiColor4ubVertex3fvSUN)(const GLuint* rc, const GLubyte* c, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiColor3fVertex3fSUN)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiColor3fVertex3fvSUN)(const GLuint* rc, const GLfloat* c, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiNormal3fVertex3fSUN)(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiNormal3fVertex3fvSUN)(const GLuint* rc, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiColor4fNormal3fVertex3fSUN)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiColor4fNormal3fVertex3fvSUN)(const GLuint* rc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiTexCoord2fVertex3fSUN)(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiTexCoord2fVertex3fvSUN)(const GLuint* rc, const GLfloat* tc, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(const GLuint* rc, const GLfloat* tc, const GLfloat* n, const GLfloat* v);
extern void (APIENTRY *gglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLuint* rc, const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v);

/* GL_EXT_blend_func_separate */
extern void (APIENTRY *gglBlendFuncSeparateEXT)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);

/* GL_INGR_blend_func_separate */
extern void (APIENTRY *gglBlendFuncSeparateINGR)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);

/* GL_INGR_color_clamp */

/* GL_INGR_interlace_read */

/* GL_EXT_stencil_wrap */

/* GL_EXT_422_pixels */

/* GL_NV_texgen_reflection */

/* GL_SUN_convolution_border_modes */

/* GL_EXT_texture_env_add */

/* GL_EXT_texture_lod_bias */

/* GL_EXT_texture_filter_anisotropic */

/* GL_EXT_vertex_weighting */
extern void (APIENTRY *gglVertexWeightfEXT)(GLfloat weight);
extern void (APIENTRY *gglVertexWeightfvEXT)(const GLfloat* weight);
extern void (APIENTRY *gglVertexWeightPointerEXT)(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);

/* GL_NV_light_max_exponent */

/* GL_NV_vertex_array_range */
extern void (APIENTRY *gglFlushVertexArrayRangeNV)();
extern void (APIENTRY *gglVertexArrayRangeNV)(GLsizei length, const GLvoid* pointer);

/* GL_NV_register_combiners */
extern void (APIENTRY *gglCombinerParameterfvNV)(GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglCombinerParameterfNV)(GLenum pname, GLfloat param);
extern void (APIENTRY *gglCombinerParameterivNV)(GLenum pname, const GLint* params);
extern void (APIENTRY *gglCombinerParameteriNV)(GLenum pname, GLint param);
extern void (APIENTRY *gglCombinerInputNV)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
extern void (APIENTRY *gglCombinerOutputNV)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
extern void (APIENTRY *gglFinalCombinerInputNV)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
extern void (APIENTRY *gglGetCombinerInputParameterfvNV)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetCombinerInputParameterivNV)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetCombinerOutputParameterfvNV)(GLenum stage, GLenum portion, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetCombinerOutputParameterivNV)(GLenum stage, GLenum portion, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetFinalCombinerInputParameterfvNV)(GLenum variable, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetFinalCombinerInputParameterivNV)(GLenum variable, GLenum pname, GLint* params);

/* GL_NV_fog_distance */

/* GL_NV_texgen_emboss */

/* GL_NV_blend_square */

/* GL_NV_texture_env_combine4 */

/* GL_MESA_resize_buffers */
extern void (APIENTRY *gglResizeBuffersMESA)();

/* GL_MESA_window_pos */
extern void (APIENTRY *gglWindowPos2dMESA)(GLdouble x, GLdouble y);
extern void (APIENTRY *gglWindowPos2dvMESA)(const GLdouble* v);
extern void (APIENTRY *gglWindowPos2fMESA)(GLfloat x, GLfloat y);
extern void (APIENTRY *gglWindowPos2fvMESA)(const GLfloat* v);
extern void (APIENTRY *gglWindowPos2iMESA)(GLint x, GLint y);
extern void (APIENTRY *gglWindowPos2ivMESA)(const GLint* v);
extern void (APIENTRY *gglWindowPos2sMESA)(GLshort x, GLshort y);
extern void (APIENTRY *gglWindowPos2svMESA)(const GLshort* v);
extern void (APIENTRY *gglWindowPos3dMESA)(GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglWindowPos3dvMESA)(const GLdouble* v);
extern void (APIENTRY *gglWindowPos3fMESA)(GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglWindowPos3fvMESA)(const GLfloat* v);
extern void (APIENTRY *gglWindowPos3iMESA)(GLint x, GLint y, GLint z);
extern void (APIENTRY *gglWindowPos3ivMESA)(const GLint* v);
extern void (APIENTRY *gglWindowPos3sMESA)(GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglWindowPos3svMESA)(const GLshort* v);
extern void (APIENTRY *gglWindowPos4dMESA)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglWindowPos4dvMESA)(const GLdouble* v);
extern void (APIENTRY *gglWindowPos4fMESA)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglWindowPos4fvMESA)(const GLfloat* v);
extern void (APIENTRY *gglWindowPos4iMESA)(GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglWindowPos4ivMESA)(const GLint* v);
extern void (APIENTRY *gglWindowPos4sMESA)(GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY *gglWindowPos4svMESA)(const GLshort* v);

/* GL_IBM_cull_vertex */

/* GL_IBM_multimode_draw_arrays */
extern void (APIENTRY *gglMultiModeDrawArraysIBM)(const GLenum* mode, const GLint* first, const GLsizei* count, GLsizei primcount, GLint modestride);
extern void (APIENTRY *gglMultiModeDrawElementsIBM)(const GLenum* mode, const GLsizei* count, GLenum type, const GLvoid* const* indices, GLsizei primcount, GLint modestride);

/* GL_IBM_vertex_array_lists */
extern void (APIENTRY *gglColorPointerListIBM)(GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
extern void (APIENTRY *gglSecondaryColorPointerListIBM)(GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
extern void (APIENTRY *gglEdgeFlagPointerListIBM)(GLint stride, const GLboolean** pointer, GLint ptrstride);
extern void (APIENTRY *gglFogCoordPointerListIBM)(GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
extern void (APIENTRY *gglIndexPointerListIBM)(GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
extern void (APIENTRY *gglNormalPointerListIBM)(GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
extern void (APIENTRY *gglTexCoordPointerListIBM)(GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
extern void (APIENTRY *gglVertexPointerListIBM)(GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);

/* GL_SGIX_subsample */

/* GL_SGIX_ycrcba */

/* GL_SGIX_ycrcb_subsample */

/* GL_SGIX_depth_pass_instrument */

/* GL_3DFX_texture_compression_FXT1 */

/* GL_3DFX_multisample */

/* GL_3DFX_tbuffer */
extern void (APIENTRY *gglTbufferMask3DFX)(GLuint mask);

/* GL_EXT_multisample */
extern void (APIENTRY *gglSampleMaskEXT)(GLclampf value, GLboolean invert);
extern void (APIENTRY *gglSamplePatternEXT)(GLenum pattern);

/* GL_SGIX_vertex_preclip */

/* GL_SGIX_convolution_accuracy */

/* GL_SGIX_resample */

/* GL_SGIS_point_line_texgen */

/* GL_SGIS_texture_color_mask */
extern void (APIENTRY *gglTextureColorMaskSGIS)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);

/* GL_SGIX_igloo_interface */
extern void (APIENTRY *gglIglooInterfaceSGIX)(GLenum pname, const GLvoid* params);

/* GL_EXT_texture_env_dot3 */

/* GL_ATI_texture_mirror_once */

/* GL_NV_fence */
extern void (APIENTRY *gglDeleteFencesNV)(GLsizei n, const GLuint* fences);
extern void (APIENTRY *gglGenFencesNV)(GLsizei n, GLuint* fences);
extern GLboolean (APIENTRY *gglIsFenceNV)(GLuint fence);
extern GLboolean (APIENTRY *gglTestFenceNV)(GLuint fence);
extern void (APIENTRY *gglGetFenceivNV)(GLuint fence, GLenum pname, GLint* params);
extern void (APIENTRY *gglFinishFenceNV)(GLuint fence);
extern void (APIENTRY *gglSetFenceNV)(GLuint fence, GLenum condition);

/* GL_NV_evaluators */
extern void (APIENTRY *gglMapControlPointsNV)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid* points);
extern void (APIENTRY *gglMapParameterivNV)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglMapParameterfvNV)(GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglGetMapControlPointsNV)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid* points);
extern void (APIENTRY *gglGetMapParameterivNV)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMapParameterfvNV)(GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMapAttribParameterivNV)(GLenum target, GLuint index, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMapAttribParameterfvNV)(GLenum target, GLuint index, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglEvalMapsNV)(GLenum target, GLenum mode);

/* GL_NV_packed_depth_stencil */

/* GL_NV_register_combiners2 */
extern void (APIENTRY *gglCombinerStageParameterfvNV)(GLenum stage, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglGetCombinerStageParameterfvNV)(GLenum stage, GLenum pname, GLfloat* params);

/* GL_NV_texture_compression_vtc */

/* GL_NV_texture_rectangle */

/* GL_NV_texture_shader */

/* GL_NV_texture_shader2 */

/* GL_NV_vertex_array_range2 */

/* GL_NV_vertex_program */
extern GLboolean (APIENTRY *gglAreProgramsResidentNV)(GLsizei n, const GLuint* programs, GLboolean* residences);
extern void (APIENTRY *gglBindProgramNV)(GLenum target, GLuint id);
extern void (APIENTRY *gglDeleteProgramsNV)(GLsizei n, const GLuint* programs);
extern void (APIENTRY *gglExecuteProgramNV)(GLenum target, GLuint id, const GLfloat* params);
extern void (APIENTRY *gglGenProgramsNV)(GLsizei n, GLuint* programs);
extern void (APIENTRY *gglGetProgramParameterdvNV)(GLenum target, GLuint index, GLenum pname, GLdouble* params);
extern void (APIENTRY *gglGetProgramParameterfvNV)(GLenum target, GLuint index, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetProgramivNV)(GLuint id, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetProgramStringNV)(GLuint id, GLenum pname, GLubyte* program);
extern void (APIENTRY *gglGetTrackMatrixivNV)(GLenum target, GLuint address, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVertexAttribdvNV)(GLuint index, GLenum pname, GLdouble* params);
extern void (APIENTRY *gglGetVertexAttribfvNV)(GLuint index, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetVertexAttribivNV)(GLuint index, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVertexAttribPointervNV)(GLuint index, GLenum pname, GLvoid** pointer);
extern GLboolean (APIENTRY *gglIsProgramNV)(GLuint id);
extern void (APIENTRY *gglLoadProgramNV)(GLenum target, GLuint id, GLsizei len, const GLubyte* program);
extern void (APIENTRY *gglProgramParameter4dNV)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglProgramParameter4dvNV)(GLenum target, GLuint index, const GLdouble* v);
extern void (APIENTRY *gglProgramParameter4fNV)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglProgramParameter4fvNV)(GLenum target, GLuint index, const GLfloat* v);
extern void (APIENTRY *gglProgramParameters4dvNV)(GLenum target, GLuint index, GLsizei count, const GLdouble* v);
extern void (APIENTRY *gglProgramParameters4fvNV)(GLenum target, GLuint index, GLsizei count, const GLfloat* v);
extern void (APIENTRY *gglRequestResidentProgramsNV)(GLsizei n, const GLuint* programs);
extern void (APIENTRY *gglTrackMatrixNV)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
extern void (APIENTRY *gglVertexAttribPointerNV)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglVertexAttrib1dNV)(GLuint index, GLdouble x);
extern void (APIENTRY *gglVertexAttrib1dvNV)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib1fNV)(GLuint index, GLfloat x);
extern void (APIENTRY *gglVertexAttrib1fvNV)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib1sNV)(GLuint index, GLshort x);
extern void (APIENTRY *gglVertexAttrib1svNV)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib2dNV)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRY *gglVertexAttrib2dvNV)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib2fNV)(GLuint index, GLfloat x, GLfloat y);
extern void (APIENTRY *gglVertexAttrib2fvNV)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib2sNV)(GLuint index, GLshort x, GLshort y);
extern void (APIENTRY *gglVertexAttrib2svNV)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib3dNV)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglVertexAttrib3dvNV)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib3fNV)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglVertexAttrib3fvNV)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib3sNV)(GLuint index, GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglVertexAttrib3svNV)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib4dNV)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglVertexAttrib4dvNV)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttrib4fNV)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglVertexAttrib4fvNV)(GLuint index, const GLfloat* v);
extern void (APIENTRY *gglVertexAttrib4sNV)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY *gglVertexAttrib4svNV)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttrib4ubNV)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void (APIENTRY *gglVertexAttrib4ubvNV)(GLuint index, const GLubyte* v);
extern void (APIENTRY *gglVertexAttribs1dvNV)(GLuint index, GLsizei count, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribs1fvNV)(GLuint index, GLsizei count, const GLfloat* v);
extern void (APIENTRY *gglVertexAttribs1svNV)(GLuint index, GLsizei count, const GLshort* v);
extern void (APIENTRY *gglVertexAttribs2dvNV)(GLuint index, GLsizei count, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribs2fvNV)(GLuint index, GLsizei count, const GLfloat* v);
extern void (APIENTRY *gglVertexAttribs2svNV)(GLuint index, GLsizei count, const GLshort* v);
extern void (APIENTRY *gglVertexAttribs3dvNV)(GLuint index, GLsizei count, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribs3fvNV)(GLuint index, GLsizei count, const GLfloat* v);
extern void (APIENTRY *gglVertexAttribs3svNV)(GLuint index, GLsizei count, const GLshort* v);
extern void (APIENTRY *gglVertexAttribs4dvNV)(GLuint index, GLsizei count, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribs4fvNV)(GLuint index, GLsizei count, const GLfloat* v);
extern void (APIENTRY *gglVertexAttribs4svNV)(GLuint index, GLsizei count, const GLshort* v);
extern void (APIENTRY *gglVertexAttribs4ubvNV)(GLuint index, GLsizei count, const GLubyte* v);

/* GL_SGIX_texture_coordinate_clamp */

/* GL_SGIX_scalebias_hint */

/* GL_OML_interlace */

/* GL_OML_subsample */

/* GL_OML_resample */

/* GL_NV_copy_depth_to_color */

/* GL_ATI_envmap_bumpmap */
extern void (APIENTRY *gglTexBumpParameterivATI)(GLenum pname, const GLint* param);
extern void (APIENTRY *gglTexBumpParameterfvATI)(GLenum pname, const GLfloat* param);
extern void (APIENTRY *gglGetTexBumpParameterivATI)(GLenum pname, GLint* param);
extern void (APIENTRY *gglGetTexBumpParameterfvATI)(GLenum pname, GLfloat* param);

/* GL_ATI_fragment_shader */
extern GLuint (APIENTRY *gglGenFragmentShadersATI)(GLuint range);
extern void (APIENTRY *gglBindFragmentShaderATI)(GLuint id);
extern void (APIENTRY *gglDeleteFragmentShaderATI)(GLuint id);
extern void (APIENTRY *gglBeginFragmentShaderATI)();
extern void (APIENTRY *gglEndFragmentShaderATI)();
extern void (APIENTRY *gglPassTexCoordATI)(GLuint dst, GLuint coord, GLenum swizzle);
extern void (APIENTRY *gglSampleMapATI)(GLuint dst, GLuint interp, GLenum swizzle);
extern void (APIENTRY *gglColorFragmentOp1ATI)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
extern void (APIENTRY *gglColorFragmentOp2ATI)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
extern void (APIENTRY *gglColorFragmentOp3ATI)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
extern void (APIENTRY *gglAlphaFragmentOp1ATI)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
extern void (APIENTRY *gglAlphaFragmentOp2ATI)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
extern void (APIENTRY *gglAlphaFragmentOp3ATI)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
extern void (APIENTRY *gglSetFragmentShaderConstantATI)(GLuint dst, const GLfloat* value);

/* GL_ATI_pn_triangles */
extern void (APIENTRY *gglPNTrianglesiATI)(GLenum pname, GLint param);
extern void (APIENTRY *gglPNTrianglesfATI)(GLenum pname, GLfloat param);

/* GL_ATI_vertex_array_object */
extern GLuint (APIENTRY *gglNewObjectBufferATI)(GLsizei size, const GLvoid* pointer, GLenum usage);
extern GLboolean (APIENTRY *gglIsObjectBufferATI)(GLuint buffer);
extern void (APIENTRY *gglUpdateObjectBufferATI)(GLuint buffer, GLuint offset, GLsizei size, const GLvoid* pointer, GLenum preserve);
extern void (APIENTRY *gglGetObjectBufferfvATI)(GLuint buffer, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetObjectBufferivATI)(GLuint buffer, GLenum pname, GLint* params);
extern void (APIENTRY *gglFreeObjectBufferATI)(GLuint buffer);
extern void (APIENTRY *gglArrayObjectATI)(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
extern void (APIENTRY *gglGetArrayObjectfvATI)(GLenum array, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetArrayObjectivATI)(GLenum array, GLenum pname, GLint* params);
extern void (APIENTRY *gglVariantArrayObjectATI)(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
extern void (APIENTRY *gglGetVariantArrayObjectfvATI)(GLuint id, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetVariantArrayObjectivATI)(GLuint id, GLenum pname, GLint* params);

/* GL_EXT_vertex_shader */
extern void (APIENTRY *gglBeginVertexShaderEXT)();
extern void (APIENTRY *gglEndVertexShaderEXT)();
extern void (APIENTRY *gglBindVertexShaderEXT)(GLuint id);
extern GLuint (APIENTRY *gglGenVertexShadersEXT)(GLuint range);
extern void (APIENTRY *gglDeleteVertexShaderEXT)(GLuint id);
extern void (APIENTRY *gglShaderOp1EXT)(GLenum op, GLuint res, GLuint arg1);
extern void (APIENTRY *gglShaderOp2EXT)(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
extern void (APIENTRY *gglShaderOp3EXT)(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
extern void (APIENTRY *gglSwizzleEXT)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
extern void (APIENTRY *gglWriteMaskEXT)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
extern void (APIENTRY *gglInsertComponentEXT)(GLuint res, GLuint src, GLuint num);
extern void (APIENTRY *gglExtractComponentEXT)(GLuint res, GLuint src, GLuint num);
extern GLuint (APIENTRY *gglGenSymbolsEXT)(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
extern void (APIENTRY *gglSetInvariantEXT)(GLuint id, GLenum type, const GLvoid* addr);
extern void (APIENTRY *gglSetLocalConstantEXT)(GLuint id, GLenum type, const GLvoid* addr);
extern void (APIENTRY *gglVariantbvEXT)(GLuint id, const GLbyte* addr);
extern void (APIENTRY *gglVariantsvEXT)(GLuint id, const GLshort* addr);
extern void (APIENTRY *gglVariantivEXT)(GLuint id, const GLint* addr);
extern void (APIENTRY *gglVariantfvEXT)(GLuint id, const GLfloat* addr);
extern void (APIENTRY *gglVariantdvEXT)(GLuint id, const GLdouble* addr);
extern void (APIENTRY *gglVariantubvEXT)(GLuint id, const GLubyte* addr);
extern void (APIENTRY *gglVariantusvEXT)(GLuint id, const GLushort* addr);
extern void (APIENTRY *gglVariantuivEXT)(GLuint id, const GLuint* addr);
extern void (APIENTRY *gglVariantPointerEXT)(GLuint id, GLenum type, GLuint stride, const GLvoid* addr);
extern void (APIENTRY *gglEnableVariantClientStateEXT)(GLuint id);
extern void (APIENTRY *gglDisableVariantClientStateEXT)(GLuint id);
extern GLuint (APIENTRY *gglBindLightParameterEXT)(GLenum light, GLenum value);
extern GLuint (APIENTRY *gglBindMaterialParameterEXT)(GLenum face, GLenum value);
extern GLuint (APIENTRY *gglBindTexGenParameterEXT)(GLenum unit, GLenum coord, GLenum value);
extern GLuint (APIENTRY *gglBindTextureUnitParameterEXT)(GLenum unit, GLenum value);
extern GLuint (APIENTRY *gglBindParameterEXT)(GLenum value);
extern GLboolean (APIENTRY *gglIsVariantEnabledEXT)(GLuint id, GLenum cap);
extern void (APIENTRY *gglGetVariantBooleanvEXT)(GLuint id, GLenum value, GLboolean* data);
extern void (APIENTRY *gglGetVariantIntegervEXT)(GLuint id, GLenum value, GLint* data);
extern void (APIENTRY *gglGetVariantFloatvEXT)(GLuint id, GLenum value, GLfloat* data);
extern void (APIENTRY *gglGetVariantPointervEXT)(GLuint id, GLenum value, GLvoid** data);
extern void (APIENTRY *gglGetInvariantBooleanvEXT)(GLuint id, GLenum value, GLboolean* data);
extern void (APIENTRY *gglGetInvariantIntegervEXT)(GLuint id, GLenum value, GLint* data);
extern void (APIENTRY *gglGetInvariantFloatvEXT)(GLuint id, GLenum value, GLfloat* data);
extern void (APIENTRY *gglGetLocalConstantBooleanvEXT)(GLuint id, GLenum value, GLboolean* data);
extern void (APIENTRY *gglGetLocalConstantIntegervEXT)(GLuint id, GLenum value, GLint* data);
extern void (APIENTRY *gglGetLocalConstantFloatvEXT)(GLuint id, GLenum value, GLfloat* data);

/* GL_ATI_vertex_streams */
extern void (APIENTRY *gglVertexStream1sATI)(GLenum stream, GLshort x);
extern void (APIENTRY *gglVertexStream1svATI)(GLenum stream, const GLshort* coords);
extern void (APIENTRY *gglVertexStream1iATI)(GLenum stream, GLint x);
extern void (APIENTRY *gglVertexStream1ivATI)(GLenum stream, const GLint* coords);
extern void (APIENTRY *gglVertexStream1fATI)(GLenum stream, GLfloat x);
extern void (APIENTRY *gglVertexStream1fvATI)(GLenum stream, const GLfloat* coords);
extern void (APIENTRY *gglVertexStream1dATI)(GLenum stream, GLdouble x);
extern void (APIENTRY *gglVertexStream1dvATI)(GLenum stream, const GLdouble* coords);
extern void (APIENTRY *gglVertexStream2sATI)(GLenum stream, GLshort x, GLshort y);
extern void (APIENTRY *gglVertexStream2svATI)(GLenum stream, const GLshort* coords);
extern void (APIENTRY *gglVertexStream2iATI)(GLenum stream, GLint x, GLint y);
extern void (APIENTRY *gglVertexStream2ivATI)(GLenum stream, const GLint* coords);
extern void (APIENTRY *gglVertexStream2fATI)(GLenum stream, GLfloat x, GLfloat y);
extern void (APIENTRY *gglVertexStream2fvATI)(GLenum stream, const GLfloat* coords);
extern void (APIENTRY *gglVertexStream2dATI)(GLenum stream, GLdouble x, GLdouble y);
extern void (APIENTRY *gglVertexStream2dvATI)(GLenum stream, const GLdouble* coords);
extern void (APIENTRY *gglVertexStream3sATI)(GLenum stream, GLshort x, GLshort y, GLshort z);
extern void (APIENTRY *gglVertexStream3svATI)(GLenum stream, const GLshort* coords);
extern void (APIENTRY *gglVertexStream3iATI)(GLenum stream, GLint x, GLint y, GLint z);
extern void (APIENTRY *gglVertexStream3ivATI)(GLenum stream, const GLint* coords);
extern void (APIENTRY *gglVertexStream3fATI)(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglVertexStream3fvATI)(GLenum stream, const GLfloat* coords);
extern void (APIENTRY *gglVertexStream3dATI)(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglVertexStream3dvATI)(GLenum stream, const GLdouble* coords);
extern void (APIENTRY *gglVertexStream4sATI)(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
extern void (APIENTRY *gglVertexStream4svATI)(GLenum stream, const GLshort* coords);
extern void (APIENTRY *gglVertexStream4iATI)(GLenum stream, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglVertexStream4ivATI)(GLenum stream, const GLint* coords);
extern void (APIENTRY *gglVertexStream4fATI)(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglVertexStream4fvATI)(GLenum stream, const GLfloat* coords);
extern void (APIENTRY *gglVertexStream4dATI)(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglVertexStream4dvATI)(GLenum stream, const GLdouble* coords);
extern void (APIENTRY *gglNormalStream3bATI)(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
extern void (APIENTRY *gglNormalStream3bvATI)(GLenum stream, const GLbyte* coords);
extern void (APIENTRY *gglNormalStream3sATI)(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
extern void (APIENTRY *gglNormalStream3svATI)(GLenum stream, const GLshort* coords);
extern void (APIENTRY *gglNormalStream3iATI)(GLenum stream, GLint nx, GLint ny, GLint nz);
extern void (APIENTRY *gglNormalStream3ivATI)(GLenum stream, const GLint* coords);
extern void (APIENTRY *gglNormalStream3fATI)(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
extern void (APIENTRY *gglNormalStream3fvATI)(GLenum stream, const GLfloat* coords);
extern void (APIENTRY *gglNormalStream3dATI)(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
extern void (APIENTRY *gglNormalStream3dvATI)(GLenum stream, const GLdouble* coords);
extern void (APIENTRY *gglClientActiveVertexStreamATI)(GLenum stream);
extern void (APIENTRY *gglVertexBlendEnviATI)(GLenum pname, GLint param);
extern void (APIENTRY *gglVertexBlendEnvfATI)(GLenum pname, GLfloat param);

/* GL_ATI_element_array */
extern void (APIENTRY *gglElementPointerATI)(GLenum type, const GLvoid* pointer);
extern void (APIENTRY *gglDrawElementArrayATI)(GLenum mode, GLsizei count);
extern void (APIENTRY *gglDrawRangeElementArrayATI)(GLenum mode, GLuint start, GLuint end, GLsizei count);

/* GL_SUN_mesh_array */
extern void (APIENTRY *gglDrawMeshArraysSUN)(GLenum mode, GLint first, GLsizei count, GLsizei width);

/* GL_SUN_slice_accum */

/* GL_NV_multisample_filter_hint */

/* GL_NV_depth_clamp */

/* GL_NV_occlusion_query */
extern void (APIENTRY *gglGenOcclusionQueriesNV)(GLsizei n, GLuint* ids);
extern void (APIENTRY *gglDeleteOcclusionQueriesNV)(GLsizei n, const GLuint* ids);
extern GLboolean (APIENTRY *gglIsOcclusionQueryNV)(GLuint id);
extern void (APIENTRY *gglBeginOcclusionQueryNV)(GLuint id);
extern void (APIENTRY *gglEndOcclusionQueryNV)();
extern void (APIENTRY *gglGetOcclusionQueryivNV)(GLuint id, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetOcclusionQueryuivNV)(GLuint id, GLenum pname, GLuint* params);

/* GL_NV_point_sprite */
extern void (APIENTRY *gglPointParameteriNV)(GLenum pname, GLint param);
extern void (APIENTRY *gglPointParameterivNV)(GLenum pname, const GLint* params);

/* GL_NV_texture_shader3 */

/* GL_NV_vertex_program1_1 */

/* GL_EXT_shadow_funcs */

/* GL_EXT_stencil_two_side */
extern void (APIENTRY *gglActiveStencilFaceEXT)(GLenum face);

/* GL_ATI_text_fragment_shader */

/* GL_APPLE_client_storage */

/* GL_APPLE_element_array */
extern void (APIENTRY *gglElementPointerAPPLE)(GLenum type, const GLvoid* pointer);
extern void (APIENTRY *gglDrawElementArrayAPPLE)(GLenum mode, GLint first, GLsizei count);
extern void (APIENTRY *gglDrawRangeElementArrayAPPLE)(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
extern void (APIENTRY *gglMultiDrawElementArrayAPPLE)(GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount);
extern void (APIENTRY *gglMultiDrawRangeElementArrayAPPLE)(GLenum mode, GLuint start, GLuint end, const GLint* first, const GLsizei* count, GLsizei primcount);

/* GL_APPLE_fence */
extern void (APIENTRY *gglGenFencesAPPLE)(GLsizei n, GLuint* fences);
extern void (APIENTRY *gglDeleteFencesAPPLE)(GLsizei n, const GLuint* fences);
extern void (APIENTRY *gglSetFenceAPPLE)(GLuint fence);
extern GLboolean (APIENTRY *gglIsFenceAPPLE)(GLuint fence);
extern GLboolean (APIENTRY *gglTestFenceAPPLE)(GLuint fence);
extern void (APIENTRY *gglFinishFenceAPPLE)(GLuint fence);
extern GLboolean (APIENTRY *gglTestObjectAPPLE)(GLenum object, GLuint name);
extern void (APIENTRY *gglFinishObjectAPPLE)(GLenum object, GLint name);

/* GL_APPLE_vertex_array_object */
extern void (APIENTRY *gglBindVertexArrayAPPLE)(GLuint array);
extern void (APIENTRY *gglDeleteVertexArraysAPPLE)(GLsizei n, const GLuint* arrays);
extern void (APIENTRY *gglGenVertexArraysAPPLE)(GLsizei n, GLuint* arrays);
extern GLboolean (APIENTRY *gglIsVertexArrayAPPLE)(GLuint array);

/* GL_APPLE_vertex_array_range */
extern void (APIENTRY *gglVertexArrayRangeAPPLE)(GLsizei length, GLvoid* pointer);
extern void (APIENTRY *gglFlushVertexArrayRangeAPPLE)(GLsizei length, GLvoid* pointer);
extern void (APIENTRY *gglVertexArrayParameteriAPPLE)(GLenum pname, GLint param);

/* GL_APPLE_ycbcr_422 */

/* GL_S3_s3tc */

/* GL_ATI_draw_buffers */
extern void (APIENTRY *gglDrawBuffersATI)(GLsizei n, const GLenum* bufs);

/* GL_ATI_pixel_format_float */
/* This is really a WGL extension, but defines some associated GL enums.
 * ATI does not export "GL_ATI_pixel_format_float" in the GL_EXTENSIONS string.
 */

/* GL_ATI_texture_env_combine3 */

/* GL_ATI_texture_float */

/* GL_NV_float_buffer */

/* GL_NV_fragment_program */
/* Some NV_fragment_program entry points are shared with ARB_vertex_program. */
extern void (APIENTRY *gglProgramNamedParameter4fNV)(GLuint id, GLsizei len, const GLubyte* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglProgramNamedParameter4dNV)(GLuint id, GLsizei len, const GLubyte* name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglProgramNamedParameter4fvNV)(GLuint id, GLsizei len, const GLubyte* name, const GLfloat* v);
extern void (APIENTRY *gglProgramNamedParameter4dvNV)(GLuint id, GLsizei len, const GLubyte* name, const GLdouble* v);
extern void (APIENTRY *gglGetProgramNamedParameterfvNV)(GLuint id, GLsizei len, const GLubyte* name, GLfloat* params);
extern void (APIENTRY *gglGetProgramNamedParameterdvNV)(GLuint id, GLsizei len, const GLubyte* name, GLdouble* params);

/* GL_NV_half_float */
extern void (APIENTRY *gglVertex2hNV)(GLhalfNV x, GLhalfNV y);
extern void (APIENTRY *gglVertex2hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglVertex3hNV)(GLhalfNV x, GLhalfNV y, GLhalfNV z);
extern void (APIENTRY *gglVertex3hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglVertex4hNV)(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
extern void (APIENTRY *gglVertex4hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglNormal3hNV)(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
extern void (APIENTRY *gglNormal3hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglColor3hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
extern void (APIENTRY *gglColor3hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglColor4hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
extern void (APIENTRY *gglColor4hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglTexCoord1hNV)(GLhalfNV s);
extern void (APIENTRY *gglTexCoord1hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglTexCoord2hNV)(GLhalfNV s, GLhalfNV t);
extern void (APIENTRY *gglTexCoord2hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglTexCoord3hNV)(GLhalfNV s, GLhalfNV t, GLhalfNV r);
extern void (APIENTRY *gglTexCoord3hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglTexCoord4hNV)(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
extern void (APIENTRY *gglTexCoord4hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglMultiTexCoord1hNV)(GLenum target, GLhalfNV s);
extern void (APIENTRY *gglMultiTexCoord1hvNV)(GLenum target, const GLhalfNV* v);
extern void (APIENTRY *gglMultiTexCoord2hNV)(GLenum target, GLhalfNV s, GLhalfNV t);
extern void (APIENTRY *gglMultiTexCoord2hvNV)(GLenum target, const GLhalfNV* v);
extern void (APIENTRY *gglMultiTexCoord3hNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
extern void (APIENTRY *gglMultiTexCoord3hvNV)(GLenum target, const GLhalfNV* v);
extern void (APIENTRY *gglMultiTexCoord4hNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
extern void (APIENTRY *gglMultiTexCoord4hvNV)(GLenum target, const GLhalfNV* v);
extern void (APIENTRY *gglFogCoordhNV)(GLhalfNV fog);
extern void (APIENTRY *gglFogCoordhvNV)(const GLhalfNV* fog);
extern void (APIENTRY *gglSecondaryColor3hNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
extern void (APIENTRY *gglSecondaryColor3hvNV)(const GLhalfNV* v);
extern void (APIENTRY *gglVertexWeighthNV)(GLhalfNV weight);
extern void (APIENTRY *gglVertexWeighthvNV)(const GLhalfNV* weight);
extern void (APIENTRY *gglVertexAttrib1hNV)(GLuint index, GLhalfNV x);
extern void (APIENTRY *gglVertexAttrib1hvNV)(GLuint index, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttrib2hNV)(GLuint index, GLhalfNV x, GLhalfNV y);
extern void (APIENTRY *gglVertexAttrib2hvNV)(GLuint index, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttrib3hNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
extern void (APIENTRY *gglVertexAttrib3hvNV)(GLuint index, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttrib4hNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
extern void (APIENTRY *gglVertexAttrib4hvNV)(GLuint index, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttribs1hvNV)(GLuint index, GLsizei n, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttribs2hvNV)(GLuint index, GLsizei n, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttribs3hvNV)(GLuint index, GLsizei n, const GLhalfNV* v);
extern void (APIENTRY *gglVertexAttribs4hvNV)(GLuint index, GLsizei n, const GLhalfNV* v);

/* GL_NV_pixel_data_range */
extern void (APIENTRY *gglPixelDataRangeNV)(GLenum target, GLsizei length, const GLvoid* pointer);
extern void (APIENTRY *gglFlushPixelDataRangeNV)(GLenum target);

/* GL_NV_primitive_restart */
extern void (APIENTRY *gglPrimitiveRestartNV)();
extern void (APIENTRY *gglPrimitiveRestartIndexNV)(GLuint index);

/* GL_NV_texture_expand_normal */

/* GL_NV_vertex_program2 */

/* GL_ATI_map_object_buffer */
extern GLvoid* (APIENTRY *gglMapObjectBufferATI)(GLuint buffer);
extern void (APIENTRY *gglUnmapObjectBufferATI)(GLuint buffer);

/* GL_ATI_separate_stencil */
extern void (APIENTRY *gglStencilOpSeparateATI)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
extern void (APIENTRY *gglStencilFuncSeparateATI)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);

/* GL_ATI_vertex_attrib_array_object */
extern void (APIENTRY *gglVertexAttribArrayObjectATI)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
extern void (APIENTRY *gglGetVertexAttribArrayObjectfvATI)(GLuint index, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetVertexAttribArrayObjectivATI)(GLuint index, GLenum pname, GLint* params);

/* GL_OES_read_format */

/* GL_EXT_depth_bounds_test */
extern void (APIENTRY *gglDepthBoundsEXT)(GLclampd zmin, GLclampd zmax);

/* GL_EXT_texture_mirror_clamp */

/* GL_EXT_blend_equation_separate */
extern void (APIENTRY *gglBlendEquationSeparateEXT)(GLenum modeRGB, GLenum modeAlpha);

/* GL_MESA_pack_invert */

/* GL_MESA_ycbcr_texture */

/* GL_MESA_ycbcr_texture */

/* GL_EXT_pixel_buffer_object */

/* GL_NV_fragment_program_option */

/* GL_NV_fragment_program2 */

/* GL_NV_vertex_program2_option */

/* GL_NV_vertex_program3 */

/* GL_EXT_framebuffer_object */
extern GLboolean (APIENTRY *gglIsRenderbufferEXT)(GLuint renderbuffer);
extern void (APIENTRY *gglBindRenderbufferEXT)(GLenum target, GLuint renderbuffer);
extern void (APIENTRY *gglDeleteRenderbuffersEXT)(GLsizei n, const GLuint* renderbuffers);
extern void (APIENTRY *gglGenRenderbuffersEXT)(GLsizei n, GLuint* renderbuffers);
extern void (APIENTRY *gglRenderbufferStorageEXT)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglGetRenderbufferParameterivEXT)(GLenum target, GLenum pname, GLint* params);
extern GLboolean (APIENTRY *gglIsFramebufferEXT)(GLuint framebuffer);
extern void (APIENTRY *gglBindFramebufferEXT)(GLenum target, GLuint framebuffer);
extern void (APIENTRY *gglDeleteFramebuffersEXT)(GLsizei n, const GLuint* framebuffers);
extern void (APIENTRY *gglGenFramebuffersEXT)(GLsizei n, GLuint* framebuffers);
extern GLenum (APIENTRY *gglCheckFramebufferStatusEXT)(GLenum target);
extern void (APIENTRY *gglFramebufferTexture1DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY *gglFramebufferTexture2DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY *gglFramebufferTexture3DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void (APIENTRY *gglFramebufferRenderbufferEXT)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (APIENTRY *gglGetFramebufferAttachmentParameterivEXT)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
extern void (APIENTRY *gglGenerateMipmapEXT)(GLenum target);

/* GL_GREMEDY_string_marker */
extern void (APIENTRY *gglStringMarkerGREMEDY)(GLsizei len, const GLvoid* string);

/* GL_EXT_packed_depth_stencil */

/* GL_EXT_stencil_clear_tag */
extern void (APIENTRY *gglStencilClearTagEXT)(GLsizei stencilTagBits, GLuint stencilClearTag);

/* GL_EXT_texture_sRGB */

/* GL_EXT_framebuffer_blit */
extern void (APIENTRY *gglBlitFramebufferEXT)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

/* GL_EXT_framebuffer_multisample */
extern void (APIENTRY *gglRenderbufferStorageMultisampleEXT)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);

/* GL_MESAX_texture_stack */

/* GL_EXT_timer_query */
extern void (APIENTRY *gglGetQueryObjecti64vEXT)(GLuint id, GLenum pname, GLint64EXT* params);
extern void (APIENTRY *gglGetQueryObjectui64vEXT)(GLuint id, GLenum pname, GLuint64EXT* params);

/* GL_EXT_gpu_program_parameters */
extern void (APIENTRY *gglProgramEnvParameters4fvEXT)(GLenum target, GLuint index, GLsizei count, const GLfloat* params);
extern void (APIENTRY *gglProgramLocalParameters4fvEXT)(GLenum target, GLuint index, GLsizei count, const GLfloat* params);

/* GL_APPLE_flush_buffer_range */
extern void (APIENTRY *gglBufferParameteriAPPLE)(GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglFlushMappedBufferRangeAPPLE)(GLenum target, GLintptr offset, GLsizeiptr size);

/* GL_NV_gpu_program4 */
extern void (APIENTRY *gglProgramLocalParameterI4iNV)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglProgramLocalParameterI4ivNV)(GLenum target, GLuint index, const GLint* params);
extern void (APIENTRY *gglProgramLocalParametersI4ivNV)(GLenum target, GLuint index, GLsizei count, const GLint* params);
extern void (APIENTRY *gglProgramLocalParameterI4uiNV)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (APIENTRY *gglProgramLocalParameterI4uivNV)(GLenum target, GLuint index, const GLuint* params);
extern void (APIENTRY *gglProgramLocalParametersI4uivNV)(GLenum target, GLuint index, GLsizei count, const GLuint* params);
extern void (APIENTRY *gglProgramEnvParameterI4iNV)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglProgramEnvParameterI4ivNV)(GLenum target, GLuint index, const GLint* params);
extern void (APIENTRY *gglProgramEnvParametersI4ivNV)(GLenum target, GLuint index, GLsizei count, const GLint* params);
extern void (APIENTRY *gglProgramEnvParameterI4uiNV)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (APIENTRY *gglProgramEnvParameterI4uivNV)(GLenum target, GLuint index, const GLuint* params);
extern void (APIENTRY *gglProgramEnvParametersI4uivNV)(GLenum target, GLuint index, GLsizei count, const GLuint* params);
extern void (APIENTRY *gglGetProgramLocalParameterIivNV)(GLenum target, GLuint index, GLint* params);
extern void (APIENTRY *gglGetProgramLocalParameterIuivNV)(GLenum target, GLuint index, GLuint* params);
extern void (APIENTRY *gglGetProgramEnvParameterIivNV)(GLenum target, GLuint index, GLint* params);
extern void (APIENTRY *gglGetProgramEnvParameterIuivNV)(GLenum target, GLuint index, GLuint* params);

/* GL_NV_geometry_program4 */
extern void (APIENTRY *gglProgramVertexLimitNV)(GLenum target, GLint limit);
extern void (APIENTRY *gglFramebufferTextureEXT)(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void (APIENTRY *gglFramebufferTextureLayerEXT)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void (APIENTRY *gglFramebufferTextureFaceEXT)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

/* GL_EXT_geometry_shader4 */
extern void (APIENTRY *gglProgramParameteriEXT)(GLuint program, GLenum pname, GLint value);

/* GL_NV_vertex_program4 */
extern void (APIENTRY *gglVertexAttribI1iEXT)(GLuint index, GLint x);
extern void (APIENTRY *gglVertexAttribI2iEXT)(GLuint index, GLint x, GLint y);
extern void (APIENTRY *gglVertexAttribI3iEXT)(GLuint index, GLint x, GLint y, GLint z);
extern void (APIENTRY *gglVertexAttribI4iEXT)(GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglVertexAttribI1uiEXT)(GLuint index, GLuint x);
extern void (APIENTRY *gglVertexAttribI2uiEXT)(GLuint index, GLuint x, GLuint y);
extern void (APIENTRY *gglVertexAttribI3uiEXT)(GLuint index, GLuint x, GLuint y, GLuint z);
extern void (APIENTRY *gglVertexAttribI4uiEXT)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (APIENTRY *gglVertexAttribI1ivEXT)(GLuint index, const GLint* v);
extern void (APIENTRY *gglVertexAttribI2ivEXT)(GLuint index, const GLint* v);
extern void (APIENTRY *gglVertexAttribI3ivEXT)(GLuint index, const GLint* v);
extern void (APIENTRY *gglVertexAttribI4ivEXT)(GLuint index, const GLint* v);
extern void (APIENTRY *gglVertexAttribI1uivEXT)(GLuint index, const GLuint* v);
extern void (APIENTRY *gglVertexAttribI2uivEXT)(GLuint index, const GLuint* v);
extern void (APIENTRY *gglVertexAttribI3uivEXT)(GLuint index, const GLuint* v);
extern void (APIENTRY *gglVertexAttribI4uivEXT)(GLuint index, const GLuint* v);
extern void (APIENTRY *gglVertexAttribI4bvEXT)(GLuint index, const GLbyte* v);
extern void (APIENTRY *gglVertexAttribI4svEXT)(GLuint index, const GLshort* v);
extern void (APIENTRY *gglVertexAttribI4ubvEXT)(GLuint index, const GLubyte* v);
extern void (APIENTRY *gglVertexAttribI4usvEXT)(GLuint index, const GLushort* v);
extern void (APIENTRY *gglVertexAttribIPointerEXT)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglGetVertexAttribIivEXT)(GLuint index, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVertexAttribIuivEXT)(GLuint index, GLenum pname, GLuint* params);

/* GL_EXT_gpu_shader4 */
extern void (APIENTRY *gglGetUniformuivEXT)(GLuint program, GLint location, GLuint* params);
extern void (APIENTRY *gglBindFragDataLocationEXT)(GLuint program, GLuint color, const GLchar* name);
extern GLint (APIENTRY *gglGetFragDataLocationEXT)(GLuint program, const GLchar* name);
extern void (APIENTRY *gglUniform1uiEXT)(GLint location, GLuint v0);
extern void (APIENTRY *gglUniform2uiEXT)(GLint location, GLuint v0, GLuint v1);
extern void (APIENTRY *gglUniform3uiEXT)(GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (APIENTRY *gglUniform4uiEXT)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (APIENTRY *gglUniform1uivEXT)(GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglUniform2uivEXT)(GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglUniform3uivEXT)(GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglUniform4uivEXT)(GLint location, GLsizei count, const GLuint* value);

/* GL_EXT_draw_instanced */
extern void (APIENTRY *gglDrawArraysInstancedEXT)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
extern void (APIENTRY *gglDrawElementsInstancedEXT)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount);

/* GL_EXT_packed_float */

/* GL_EXT_texture_array */

/* GL_EXT_texture_buffer_object */
extern void (APIENTRY *gglTexBufferEXT)(GLenum target, GLenum internalformat, GLuint buffer);

/* GL_EXT_texture_compression_latc */

/* GL_EXT_texture_compression_rgtc */

/* GL_EXT_texture_shared_exponent */

/* GL_NV_depth_buffer_float */
extern void (APIENTRY *gglDepthRangedNV)(GLdouble zNear, GLdouble zFar);
extern void (APIENTRY *gglClearDepthdNV)(GLdouble depth);
extern void (APIENTRY *gglDepthBoundsdNV)(GLdouble zmin, GLdouble zmax);

/* GL_NV_fragment_program4 */

/* GL_NV_framebuffer_multisample_coverage */
extern void (APIENTRY *gglRenderbufferStorageMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);

/* GL_EXT_framebuffer_sRGB */

/* GL_NV_geometry_shader4 */

/* GL_NV_parameter_buffer_object */
extern void (APIENTRY *gglProgramBufferParametersfvNV)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat* params);
extern void (APIENTRY *gglProgramBufferParametersIivNV)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint* params);
extern void (APIENTRY *gglProgramBufferParametersIuivNV)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint* params);

/* GL_EXT_draw_buffers2 */
extern void (APIENTRY *gglColorMaskIndexedEXT)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
extern void (APIENTRY *gglGetBooleanIndexedvEXT)(GLenum target, GLuint index, GLboolean* data);
extern void (APIENTRY *gglGetIntegerIndexedvEXT)(GLenum target, GLuint index, GLint* data);
extern void (APIENTRY *gglEnableIndexedEXT)(GLenum target, GLuint index);
extern void (APIENTRY *gglDisableIndexedEXT)(GLenum target, GLuint index);
extern GLboolean (APIENTRY *gglIsEnabledIndexedEXT)(GLenum target, GLuint index);

/* GL_NV_transform_feedback */
extern void (APIENTRY *gglBeginTransformFeedbackNV)(GLenum primitiveMode);
extern void (APIENTRY *gglEndTransformFeedbackNV)();
extern void (APIENTRY *gglTransformFeedbackAttribsNV)(GLuint count, const GLint* attribs, GLenum bufferMode);
extern void (APIENTRY *gglBindBufferRangeNV)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRY *gglBindBufferOffsetNV)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
extern void (APIENTRY *gglBindBufferBaseNV)(GLenum target, GLuint index, GLuint buffer);
extern void (APIENTRY *gglTransformFeedbackVaryingsNV)(GLuint program, GLsizei count, const GLint* locations, GLenum bufferMode);
extern void (APIENTRY *gglActiveVaryingNV)(GLuint program, const GLchar* name);
extern GLint (APIENTRY *gglGetVaryingLocationNV)(GLuint program, const GLchar* name);
extern void (APIENTRY *gglGetActiveVaryingNV)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
extern void (APIENTRY *gglGetTransformFeedbackVaryingNV)(GLuint program, GLuint index, GLint* location);
extern void (APIENTRY *gglTransformFeedbackStreamAttribsNV)(GLsizei count, const GLint* attribs, GLsizei nbuffers, const GLint* bufstreams, GLenum bufferMode);

/* GL_EXT_bindable_uniform */
extern void (APIENTRY *gglUniformBufferEXT)(GLuint program, GLint location, GLuint buffer);
extern GLint (APIENTRY *gglGetUniformBufferSizeEXT)(GLuint program, GLint location);
extern GLintptr (APIENTRY *gglGetUniformOffsetEXT)(GLuint program, GLint location);

/* GL_EXT_texture_integer */
extern void (APIENTRY *gglTexParameterIivEXT)(GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglTexParameterIuivEXT)(GLenum target, GLenum pname, const GLuint* params);
extern void (APIENTRY *gglGetTexParameterIivEXT)(GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetTexParameterIuivEXT)(GLenum target, GLenum pname, GLuint* params);
extern void (APIENTRY *gglClearColorIiEXT)(GLint red, GLint green, GLint blue, GLint alpha);
extern void (APIENTRY *gglClearColorIuiEXT)(GLuint red, GLuint green, GLuint blue, GLuint alpha);

/* GL_GREMEDY_frame_terminator */
extern void (APIENTRY *gglFrameTerminatorGREMEDY)();

/* GL_NV_conditional_render */
extern void (APIENTRY *gglBeginConditionalRenderNV)(GLuint id, GLenum mode);
extern void (APIENTRY *gglEndConditionalRenderNV)();

/* GL_NV_present_video */
extern void (APIENTRY *gglPresentFrameKeyedNV)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
extern void (APIENTRY *gglPresentFrameDualFillNV)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
extern void (APIENTRY *gglGetVideoivNV)(GLuint video_slot, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVideouivNV)(GLuint video_slot, GLenum pname, GLuint* params);
extern void (APIENTRY *gglGetVideoi64vNV)(GLuint video_slot, GLenum pname, GLint64EXT* params);
extern void (APIENTRY *gglGetVideoui64vNV)(GLuint video_slot, GLenum pname, GLuint64EXT* params);

/* GL_EXT_transform_feedback */
extern void (APIENTRY *gglBeginTransformFeedbackEXT)(GLenum primitiveMode);
extern void (APIENTRY *gglEndTransformFeedbackEXT)();
extern void (APIENTRY *gglBindBufferRangeEXT)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (APIENTRY *gglBindBufferOffsetEXT)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
extern void (APIENTRY *gglBindBufferBaseEXT)(GLenum target, GLuint index, GLuint buffer);
extern void (APIENTRY *gglTransformFeedbackVaryingsEXT)(GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode);
extern void (APIENTRY *gglGetTransformFeedbackVaryingEXT)(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);

/* GL_EXT_direct_state_access */
extern void (APIENTRY *gglClientAttribDefaultEXT)(GLbitfield mask);
extern void (APIENTRY *gglPushClientAttribDefaultEXT)(GLbitfield mask);
extern void (APIENTRY *gglMatrixLoadfEXT)(GLenum mode, const GLfloat* m);
extern void (APIENTRY *gglMatrixLoaddEXT)(GLenum mode, const GLdouble* m);
extern void (APIENTRY *gglMatrixMultfEXT)(GLenum mode, const GLfloat* m);
extern void (APIENTRY *gglMatrixMultdEXT)(GLenum mode, const GLdouble* m);
extern void (APIENTRY *gglMatrixLoadIdentityEXT)(GLenum mode);
extern void (APIENTRY *gglMatrixRotatefEXT)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglMatrixRotatedEXT)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglMatrixScalefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglMatrixScaledEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglMatrixTranslatefEXT)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
extern void (APIENTRY *gglMatrixTranslatedEXT)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglMatrixFrustumEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern void (APIENTRY *gglMatrixOrthoEXT)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
extern void (APIENTRY *gglMatrixPopEXT)(GLenum mode);
extern void (APIENTRY *gglMatrixPushEXT)(GLenum mode);
extern void (APIENTRY *gglMatrixLoadTransposefEXT)(GLenum mode, const GLfloat* m);
extern void (APIENTRY *gglMatrixLoadTransposedEXT)(GLenum mode, const GLdouble* m);
extern void (APIENTRY *gglMatrixMultTransposefEXT)(GLenum mode, const GLfloat* m);
extern void (APIENTRY *gglMatrixMultTransposedEXT)(GLenum mode, const GLdouble* m);
extern void (APIENTRY *gglTextureParameterfEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglTextureParameteriEXT)(GLuint texture, GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglCopyTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (APIENTRY *gglCopyTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (APIENTRY *gglCopyTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (APIENTRY *gglCopyTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglGetTextureImageEXT)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
extern void (APIENTRY *gglGetTextureParameterfvEXT)(GLuint texture, GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetTextureParameterivEXT)(GLuint texture, GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetTextureLevelParameterfvEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetTextureLevelParameterivEXT)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
extern void (APIENTRY *gglTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglCopyTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglMultiTexParameterfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglMultiTexParameteriEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglCopyMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (APIENTRY *gglCopyMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (APIENTRY *gglCopyMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (APIENTRY *gglCopyMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglGetMultiTexImageEXT)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels);
extern void (APIENTRY *gglGetMultiTexParameterfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMultiTexParameterivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMultiTexLevelParameterfvEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMultiTexLevelParameterivEXT)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
extern void (APIENTRY *gglMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
extern void (APIENTRY *gglCopyMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (APIENTRY *gglBindMultiTextureEXT)(GLenum texunit, GLenum target, GLuint texture);
extern void (APIENTRY *gglEnableClientStateIndexedEXT)(GLenum array, GLuint index);
extern void (APIENTRY *gglDisableClientStateIndexedEXT)(GLenum array, GLuint index);
extern void (APIENTRY *gglMultiTexCoordPointerEXT)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglMultiTexEnvfEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
extern void (APIENTRY *gglMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglMultiTexEnviEXT)(GLenum texunit, GLenum target, GLenum pname, GLint param);
extern void (APIENTRY *gglMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglMultiTexGendEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
extern void (APIENTRY *gglMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
extern void (APIENTRY *gglMultiTexGenfEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
extern void (APIENTRY *gglMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglMultiTexGeniEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
extern void (APIENTRY *gglMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
extern void (APIENTRY *gglGetMultiTexEnvfvEXT)(GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMultiTexEnvivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMultiTexGendvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
extern void (APIENTRY *gglGetMultiTexGenfvEXT)(GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetMultiTexGenivEXT)(GLenum texunit, GLenum coord, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetFloatIndexedvEXT)(GLenum target, GLuint index, GLfloat* data);
extern void (APIENTRY *gglGetDoubleIndexedvEXT)(GLenum target, GLuint index, GLdouble* data);
extern void (APIENTRY *gglGetPointerIndexedvEXT)(GLenum target, GLuint index, GLvoid** data);
extern void (APIENTRY *gglCompressedTextureImage3DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedTextureImage2DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedTextureImage1DEXT)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedTextureSubImage3DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedTextureSubImage2DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedTextureSubImage1DEXT)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglGetCompressedTextureImageEXT)(GLuint texture, GLenum target, GLint lod, GLvoid* img);
extern void (APIENTRY *gglCompressedMultiTexImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedMultiTexImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedMultiTexImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedMultiTexSubImage3DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedMultiTexSubImage2DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglCompressedMultiTexSubImage1DEXT)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* bits);
extern void (APIENTRY *gglGetCompressedMultiTexImageEXT)(GLenum texunit, GLenum target, GLint lod, GLvoid* img);
extern void (APIENTRY *gglNamedProgramStringEXT)(GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid* string);
extern void (APIENTRY *gglNamedProgramLocalParameter4dEXT)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglNamedProgramLocalParameter4dvEXT)(GLuint program, GLenum target, GLuint index, const GLdouble* params);
extern void (APIENTRY *gglNamedProgramLocalParameter4fEXT)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (APIENTRY *gglNamedProgramLocalParameter4fvEXT)(GLuint program, GLenum target, GLuint index, const GLfloat* params);
extern void (APIENTRY *gglGetNamedProgramLocalParameterdvEXT)(GLuint program, GLenum target, GLuint index, GLdouble* params);
extern void (APIENTRY *gglGetNamedProgramLocalParameterfvEXT)(GLuint program, GLenum target, GLuint index, GLfloat* params);
extern void (APIENTRY *gglGetNamedProgramivEXT)(GLuint program, GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetNamedProgramStringEXT)(GLuint program, GLenum target, GLenum pname, GLvoid* string);
extern void (APIENTRY *gglNamedProgramLocalParameters4fvEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
extern void (APIENTRY *gglNamedProgramLocalParameterI4iEXT)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (APIENTRY *gglNamedProgramLocalParameterI4ivEXT)(GLuint program, GLenum target, GLuint index, const GLint* params);
extern void (APIENTRY *gglNamedProgramLocalParametersI4ivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
extern void (APIENTRY *gglNamedProgramLocalParameterI4uiEXT)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (APIENTRY *gglNamedProgramLocalParameterI4uivEXT)(GLuint program, GLenum target, GLuint index, const GLuint* params);
extern void (APIENTRY *gglNamedProgramLocalParametersI4uivEXT)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
extern void (APIENTRY *gglGetNamedProgramLocalParameterIivEXT)(GLuint program, GLenum target, GLuint index, GLint* params);
extern void (APIENTRY *gglGetNamedProgramLocalParameterIuivEXT)(GLuint program, GLenum target, GLuint index, GLuint* params);
extern void (APIENTRY *gglTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, const GLuint* params);
extern void (APIENTRY *gglGetTextureParameterIivEXT)(GLuint texture, GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetTextureParameterIuivEXT)(GLuint texture, GLenum target, GLenum pname, GLuint* params);
extern void (APIENTRY *gglMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLint* params);
extern void (APIENTRY *gglMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
extern void (APIENTRY *gglGetMultiTexParameterIivEXT)(GLenum texunit, GLenum target, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetMultiTexParameterIuivEXT)(GLenum texunit, GLenum target, GLenum pname, GLuint* params);
extern void (APIENTRY *gglProgramUniform1fEXT)(GLuint program, GLint location, GLfloat v0);
extern void (APIENTRY *gglProgramUniform2fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
extern void (APIENTRY *gglProgramUniform3fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (APIENTRY *gglProgramUniform4fEXT)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (APIENTRY *gglProgramUniform1iEXT)(GLuint program, GLint location, GLint v0);
extern void (APIENTRY *gglProgramUniform2iEXT)(GLuint program, GLint location, GLint v0, GLint v1);
extern void (APIENTRY *gglProgramUniform3iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
extern void (APIENTRY *gglProgramUniform4iEXT)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (APIENTRY *gglProgramUniform1fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform2fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform3fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform4fvEXT)(GLuint program, GLint location, GLsizei count, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform1ivEXT)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform2ivEXT)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform3ivEXT)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniform4ivEXT)(GLuint program, GLint location, GLsizei count, const GLint* value);
extern void (APIENTRY *gglProgramUniformMatrix2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix2x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix3x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix2x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix4x2fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix3x4fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniformMatrix4x3fvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
extern void (APIENTRY *gglProgramUniform1uiEXT)(GLuint program, GLint location, GLuint v0);
extern void (APIENTRY *gglProgramUniform2uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1);
extern void (APIENTRY *gglProgramUniform3uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (APIENTRY *gglProgramUniform4uiEXT)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (APIENTRY *gglProgramUniform1uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniform2uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniform3uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglProgramUniform4uivEXT)(GLuint program, GLint location, GLsizei count, const GLuint* value);
extern void (APIENTRY *gglNamedBufferDataEXT)(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage);
extern void (APIENTRY *gglNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
extern GLvoid* (APIENTRY *gglMapNamedBufferEXT)(GLuint buffer, GLenum access);
extern GLboolean (APIENTRY *gglUnmapNamedBufferEXT)(GLuint buffer);
extern GLvoid* (APIENTRY *gglMapNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern void (APIENTRY *gglFlushMappedNamedBufferRangeEXT)(GLuint buffer, GLintptr offset, GLsizeiptr length);
extern void (APIENTRY *gglNamedCopyBufferSubDataEXT)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (APIENTRY *gglGetNamedBufferParameterivEXT)(GLuint buffer, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetNamedBufferPointervEXT)(GLuint buffer, GLenum pname, GLvoid** params);
extern void (APIENTRY *gglGetNamedBufferSubDataEXT)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data);
extern void (APIENTRY *gglTextureBufferEXT)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
extern void (APIENTRY *gglMultiTexBufferEXT)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
extern void (APIENTRY *gglNamedRenderbufferStorageEXT)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglGetNamedRenderbufferParameterivEXT)(GLuint renderbuffer, GLenum pname, GLint* params);
extern GLenum (APIENTRY *gglCheckNamedFramebufferStatusEXT)(GLuint framebuffer, GLenum target);
extern void (APIENTRY *gglNamedFramebufferTexture1DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY *gglNamedFramebufferTexture2DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (APIENTRY *gglNamedFramebufferTexture3DEXT)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void (APIENTRY *gglNamedFramebufferRenderbufferEXT)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (APIENTRY *gglGetNamedFramebufferAttachmentParameterivEXT)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
extern void (APIENTRY *gglGenerateTextureMipmapEXT)(GLuint texture, GLenum target);
extern void (APIENTRY *gglGenerateMultiTexMipmapEXT)(GLenum texunit, GLenum target);
extern void (APIENTRY *gglFramebufferDrawBufferEXT)(GLuint framebuffer, GLenum mode);
extern void (APIENTRY *gglFramebufferDrawBuffersEXT)(GLuint framebuffer, GLsizei n, const GLenum* bufs);
extern void (APIENTRY *gglFramebufferReadBufferEXT)(GLuint framebuffer, GLenum mode);
extern void (APIENTRY *gglGetFramebufferParameterivEXT)(GLuint framebuffer, GLenum pname, GLint* params);
extern void (APIENTRY *gglNamedRenderbufferStorageMultisampleEXT)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglNamedRenderbufferStorageMultisampleCoverageEXT)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (APIENTRY *gglNamedFramebufferTextureEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
extern void (APIENTRY *gglNamedFramebufferTextureLayerEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void (APIENTRY *gglNamedFramebufferTextureFaceEXT)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
extern void (APIENTRY *gglTextureRenderbufferEXT)(GLuint texture, GLenum target, GLuint renderbuffer);
extern void (APIENTRY *gglMultiTexRenderbufferEXT)(GLenum texunit, GLenum target, GLuint renderbuffer);
extern void (APIENTRY *gglProgramUniform1dEXT)(GLuint program, GLint location, GLdouble x);
extern void (APIENTRY *gglProgramUniform2dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y);
extern void (APIENTRY *gglProgramUniform3dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglProgramUniform4dEXT)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglProgramUniform1dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform2dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform3dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniform4dvEXT)(GLuint program, GLint location, GLsizei count, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix2x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix2x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix3x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix3x4dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix4x2dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
extern void (APIENTRY *gglProgramUniformMatrix4x3dvEXT)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);

/* GL_EXT_vertex_array_bgra */

/* GL_EXT_texture_swizzle */

/* GL_NV_explicit_multisample */
extern void (APIENTRY *gglGetMultisamplefvNV)(GLenum pname, GLuint index, GLfloat* val);
extern void (APIENTRY *gglSampleMaskIndexedNV)(GLuint index, GLbitfield mask);
extern void (APIENTRY *gglTexRenderbufferNV)(GLenum target, GLuint renderbuffer);

/* GL_NV_transform_feedback2 */
extern void (APIENTRY *gglBindTransformFeedbackNV)(GLenum target, GLuint id);
extern void (APIENTRY *gglDeleteTransformFeedbacksNV)(GLsizei n, const GLuint* ids);
extern void (APIENTRY *gglGenTransformFeedbacksNV)(GLsizei n, GLuint* ids);
extern GLboolean (APIENTRY *gglIsTransformFeedbackNV)(GLuint id);
extern void (APIENTRY *gglPauseTransformFeedbackNV)();
extern void (APIENTRY *gglResumeTransformFeedbackNV)();
extern void (APIENTRY *gglDrawTransformFeedbackNV)(GLenum mode, GLuint id);

/* GL_ATI_meminfo */

/* GL_AMD_performance_monitor */
extern void (APIENTRY *gglGetPerfMonitorGroupsAMD)(GLint* numGroups, GLsizei groupsSize, GLuint* groups);
extern void (APIENTRY *gglGetPerfMonitorCountersAMD)(GLuint group, GLint* numCounters, GLint* maxActiveCounters, GLsizei counterSize, GLuint* counters);
extern void (APIENTRY *gglGetPerfMonitorGroupStringAMD)(GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString);
extern void (APIENTRY *gglGetPerfMonitorCounterStringAMD)(GLuint group, GLuint counter, GLsizei bufSize, GLsizei* length, GLchar* counterString);
extern void (APIENTRY *gglGetPerfMonitorCounterInfoAMD)(GLuint group, GLuint counter, GLenum pname, GLvoid* data);
extern void (APIENTRY *gglGenPerfMonitorsAMD)(GLsizei n, GLuint* monitors);
extern void (APIENTRY *gglDeletePerfMonitorsAMD)(GLsizei n, GLuint* monitors);
extern void (APIENTRY *gglSelectPerfMonitorCountersAMD)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint* counterList);
extern void (APIENTRY *gglBeginPerfMonitorAMD)(GLuint monitor);
extern void (APIENTRY *gglEndPerfMonitorAMD)(GLuint monitor);
extern void (APIENTRY *gglGetPerfMonitorCounterDataAMD)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten);

/* GL_AMD_texture_texture4 */

/* GL_AMD_vertex_shader_tesselator */
extern void (APIENTRY *gglTessellationFactorAMD)(GLfloat factor);
extern void (APIENTRY *gglTessellationModeAMD)(GLenum mode);

/* GL_EXT_provoking_vertex */
extern void (APIENTRY *gglProvokingVertexEXT)(GLenum mode);

/* GL_EXT_texture_snorm */

/* GL_AMD_draw_buffers_blend */
extern void (APIENTRY *gglBlendFuncIndexedAMD)(GLuint buf, GLenum src, GLenum dst);
extern void (APIENTRY *gglBlendFuncSeparateIndexedAMD)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern void (APIENTRY *gglBlendEquationIndexedAMD)(GLuint buf, GLenum mode);
extern void (APIENTRY *gglBlendEquationSeparateIndexedAMD)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);

/* GL_APPLE_texture_range */
extern void (APIENTRY *gglTextureRangeAPPLE)(GLenum target, GLsizei length, const GLvoid* pointer);
extern void (APIENTRY *gglGetTexParameterPointervAPPLE)(GLenum target, GLenum pname, GLvoid** params);

/* GL_APPLE_float_pixels */

/* GL_APPLE_vertex_program_evaluators */
extern void (APIENTRY *gglEnableVertexAttribAPPLE)(GLuint index, GLenum pname);
extern void (APIENTRY *gglDisableVertexAttribAPPLE)(GLuint index, GLenum pname);
extern GLboolean (APIENTRY *gglIsVertexAttribEnabledAPPLE)(GLuint index, GLenum pname);
extern void (APIENTRY *gglMapVertexAttrib1dAPPLE)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
extern void (APIENTRY *gglMapVertexAttrib1fAPPLE)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
extern void (APIENTRY *gglMapVertexAttrib2dAPPLE)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
extern void (APIENTRY *gglMapVertexAttrib2fAPPLE)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);

/* GL_APPLE_aux_depth_stencil */

/* GL_APPLE_object_purgeable */
extern GLenum (APIENTRY *gglObjectPurgeableAPPLE)(GLenum objectType, GLuint name, GLenum option);
extern GLenum (APIENTRY *gglObjectUnpurgeableAPPLE)(GLenum objectType, GLuint name, GLenum option);
extern void (APIENTRY *gglGetObjectParameterivAPPLE)(GLenum objectType, GLuint name, GLenum pname, GLint* params);

/* GL_APPLE_row_bytes */

/* GL_APPLE_rgb_422 */

/* GL_NV_video_capture */
extern void (APIENTRY *gglBeginVideoCaptureNV)(GLuint video_capture_slot);
extern void (APIENTRY *gglBindVideoCaptureStreamBufferNV)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
extern void (APIENTRY *gglBindVideoCaptureStreamTextureNV)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
extern void (APIENTRY *gglEndVideoCaptureNV)(GLuint video_capture_slot);
extern void (APIENTRY *gglGetVideoCaptureivNV)(GLuint video_capture_slot, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVideoCaptureStreamivNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint* params);
extern void (APIENTRY *gglGetVideoCaptureStreamfvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat* params);
extern void (APIENTRY *gglGetVideoCaptureStreamdvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble* params);
extern GLenum (APIENTRY *gglVideoCaptureNV)(GLuint video_capture_slot, GLuint* sequence_num, GLuint64EXT* capture_time);
extern void (APIENTRY *gglVideoCaptureStreamParameterivNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint* params);
extern void (APIENTRY *gglVideoCaptureStreamParameterfvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat* params);
extern void (APIENTRY *gglVideoCaptureStreamParameterdvNV)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble* params);

/* GL_NV_copy_image */
extern void (APIENTRY *gglCopyImageSubDataNV)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

/* GL_EXT_separate_shader_objects */
extern void (APIENTRY *gglUseShaderProgramEXT)(GLenum type, GLuint program);
extern void (APIENTRY *gglActiveProgramEXT)(GLuint program);
extern GLuint (APIENTRY *gglCreateShaderProgramEXT)(GLenum type, const GLchar* string);

/* GL_NV_parameter_buffer_object2 */

/* GL_NV_shader_buffer_load */
extern void (APIENTRY *gglMakeBufferResidentNV)(GLenum target, GLenum access);
extern void (APIENTRY *gglMakeBufferNonResidentNV)(GLenum target);
extern GLboolean (APIENTRY *gglIsBufferResidentNV)(GLenum target);
extern void (APIENTRY *gglMakeNamedBufferResidentNV)(GLuint buffer, GLenum access);
extern void (APIENTRY *gglMakeNamedBufferNonResidentNV)(GLuint buffer);
extern GLboolean (APIENTRY *gglIsNamedBufferResidentNV)(GLuint buffer);
extern void (APIENTRY *gglGetBufferParameterui64vNV)(GLenum target, GLenum pname, GLuint64EXT* params);
extern void (APIENTRY *gglGetNamedBufferParameterui64vNV)(GLuint buffer, GLenum pname, GLuint64EXT* params);
extern void (APIENTRY *gglGetIntegerui64vNV)(GLenum value, GLuint64EXT* result);
extern void (APIENTRY *gglUniformui64NV)(GLint location, GLuint64EXT value);
extern void (APIENTRY *gglUniformui64vNV)(GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglGetUniformui64vNV)(GLuint program, GLint location, GLuint64EXT* params);
extern void (APIENTRY *gglProgramUniformui64NV)(GLuint program, GLint location, GLuint64EXT value);
extern void (APIENTRY *gglProgramUniformui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);

/* GL_NV_vertex_buffer_unified_memory */
extern void (APIENTRY *gglBufferAddressRangeNV)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
extern void (APIENTRY *gglVertexFormatNV)(GLint size, GLenum type, GLsizei stride);
extern void (APIENTRY *gglNormalFormatNV)(GLenum type, GLsizei stride);
extern void (APIENTRY *gglColorFormatNV)(GLint size, GLenum type, GLsizei stride);
extern void (APIENTRY *gglIndexFormatNV)(GLenum type, GLsizei stride);
extern void (APIENTRY *gglTexCoordFormatNV)(GLint size, GLenum type, GLsizei stride);
extern void (APIENTRY *gglEdgeFlagFormatNV)(GLsizei stride);
extern void (APIENTRY *gglSecondaryColorFormatNV)(GLint size, GLenum type, GLsizei stride);
extern void (APIENTRY *gglFogCoordFormatNV)(GLenum type, GLsizei stride);
extern void (APIENTRY *gglVertexAttribFormatNV)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
extern void (APIENTRY *gglVertexAttribIFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride);
extern void (APIENTRY *gglGetIntegerui64i_vNV)(GLenum value, GLuint index, GLuint64EXT* result);

/* GL_NV_texture_barrier */
extern void (APIENTRY *gglTextureBarrierNV)();

/* GL_AMD_shader_stencil_export */

/* GL_AMD_seamless_cubemap_per_texture */

/* GL_AMD_conservative_depth */

/* GL_EXT_shader_image_load_store */
extern void (APIENTRY *gglBindImageTextureEXT)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
extern void (APIENTRY *gglMemoryBarrierEXT)(GLbitfield barriers);

/* GL_EXT_vertex_attrib_64bit */
extern void (APIENTRY *gglVertexAttribL1dEXT)(GLuint index, GLdouble x);
extern void (APIENTRY *gglVertexAttribL2dEXT)(GLuint index, GLdouble x, GLdouble y);
extern void (APIENTRY *gglVertexAttribL3dEXT)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (APIENTRY *gglVertexAttribL4dEXT)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (APIENTRY *gglVertexAttribL1dvEXT)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribL2dvEXT)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribL3dvEXT)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribL4dvEXT)(GLuint index, const GLdouble* v);
extern void (APIENTRY *gglVertexAttribLPointerEXT)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
extern void (APIENTRY *gglGetVertexAttribLdvEXT)(GLuint index, GLenum pname, GLdouble* params);
extern void (APIENTRY *gglVertexArrayVertexAttribLOffsetEXT)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);

/* GL_NV_gpu_program5 */
extern void (APIENTRY *gglProgramSubroutineParametersuivNV)(GLenum target, GLsizei count, const GLuint* params);
extern void (APIENTRY *gglGetProgramSubroutineParameteruivNV)(GLenum target, GLuint index, GLuint* param);

/* GL_NV_gpu_shader5 */
extern void (APIENTRY *gglUniform1i64NV)(GLint location, GLint64EXT x);
extern void (APIENTRY *gglUniform2i64NV)(GLint location, GLint64EXT x, GLint64EXT y);
extern void (APIENTRY *gglUniform3i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
extern void (APIENTRY *gglUniform4i64NV)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
extern void (APIENTRY *gglUniform1i64vNV)(GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglUniform2i64vNV)(GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglUniform3i64vNV)(GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglUniform4i64vNV)(GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglUniform1ui64NV)(GLint location, GLuint64EXT x);
extern void (APIENTRY *gglUniform2ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y);
extern void (APIENTRY *gglUniform3ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
extern void (APIENTRY *gglUniform4ui64NV)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
extern void (APIENTRY *gglUniform1ui64vNV)(GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglUniform2ui64vNV)(GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglUniform3ui64vNV)(GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglUniform4ui64vNV)(GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglGetUniformi64vNV)(GLuint program, GLint location, GLint64EXT* params);
extern void (APIENTRY *gglProgramUniform1i64NV)(GLuint program, GLint location, GLint64EXT x);
extern void (APIENTRY *gglProgramUniform2i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
extern void (APIENTRY *gglProgramUniform3i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
extern void (APIENTRY *gglProgramUniform4i64NV)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
extern void (APIENTRY *gglProgramUniform1i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglProgramUniform2i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglProgramUniform3i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglProgramUniform4i64vNV)(GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
extern void (APIENTRY *gglProgramUniform1ui64NV)(GLuint program, GLint location, GLuint64EXT x);
extern void (APIENTRY *gglProgramUniform2ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
extern void (APIENTRY *gglProgramUniform3ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
extern void (APIENTRY *gglProgramUniform4ui64NV)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
extern void (APIENTRY *gglProgramUniform1ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglProgramUniform2ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglProgramUniform3ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
extern void (APIENTRY *gglProgramUniform4ui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);

/* GL_NV_shader_buffer_store */

/* GL_NV_tessellation_program5 */

/* GL_NV_vertex_attrib_integer_64bit */
extern void (APIENTRY *gglVertexAttribL1i64NV)(GLuint index, GLint64EXT x);
extern void (APIENTRY *gglVertexAttribL2i64NV)(GLuint index, GLint64EXT x, GLint64EXT y);
extern void (APIENTRY *gglVertexAttribL3i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
extern void (APIENTRY *gglVertexAttribL4i64NV)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
extern void (APIENTRY *gglVertexAttribL1i64vNV)(GLuint index, const GLint64EXT* v);
extern void (APIENTRY *gglVertexAttribL2i64vNV)(GLuint index, const GLint64EXT* v);
extern void (APIENTRY *gglVertexAttribL3i64vNV)(GLuint index, const GLint64EXT* v);
extern void (APIENTRY *gglVertexAttribL4i64vNV)(GLuint index, const GLint64EXT* v);
extern void (APIENTRY *gglVertexAttribL1ui64NV)(GLuint index, GLuint64EXT x);
extern void (APIENTRY *gglVertexAttribL2ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y);
extern void (APIENTRY *gglVertexAttribL3ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
extern void (APIENTRY *gglVertexAttribL4ui64NV)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
extern void (APIENTRY *gglVertexAttribL1ui64vNV)(GLuint index, const GLuint64EXT* v);
extern void (APIENTRY *gglVertexAttribL2ui64vNV)(GLuint index, const GLuint64EXT* v);
extern void (APIENTRY *gglVertexAttribL3ui64vNV)(GLuint index, const GLuint64EXT* v);
extern void (APIENTRY *gglVertexAttribL4ui64vNV)(GLuint index, const GLuint64EXT* v);
extern void (APIENTRY *gglGetVertexAttribLi64vNV)(GLuint index, GLenum pname, GLint64EXT* params);
extern void (APIENTRY *gglGetVertexAttribLui64vNV)(GLuint index, GLenum pname, GLuint64EXT* params);
extern void (APIENTRY *gglVertexAttribLFormatNV)(GLuint index, GLint size, GLenum type, GLsizei stride);

/* GL_NV_multisample_coverage */

/* GL_AMD_name_gen_delete */
extern void (APIENTRY *gglGenNamesAMD)(GLenum identifier, GLuint num, GLuint* names);
extern void (APIENTRY *gglDeleteNamesAMD)(GLenum identifier, GLuint num, const GLuint* names);
extern GLboolean (APIENTRY *gglIsNameAMD)(GLenum identifier, GLuint name);

/* GL_AMD_debug_output */
extern void (APIENTRY *gglDebugMessageEnableAMD)(GLenum category, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
extern void (APIENTRY *gglDebugMessageInsertAMD)(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar* buf);
extern void (APIENTRY *gglDebugMessageCallbackAMD)(GLDEBUGPROCAMD callback, GLvoid* userParam);
extern GLuint (APIENTRY *gglGetDebugMessageLogAMD)(GLuint count, GLsizei bufsize, GLenum* categories, GLuint* severities, GLuint* ids, GLsizei* lengths, GLchar* message);

/* GL_NV_vdpau_interop */
extern void (APIENTRY *gglVDPAUInitNV)(const GLvoid* vdpDevice, const GLvoid* getProcAddress);
extern void (APIENTRY *gglVDPAUFiniNV)();
extern GLvdpauSurfaceNV (APIENTRY *gglVDPAURegisterVideoSurfaceNV)(const GLvoid* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames);
extern GLvdpauSurfaceNV (APIENTRY *gglVDPAURegisterOutputSurfaceNV)(GLvoid* vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint* textureNames);
extern void (APIENTRY *gglVDPAUIsSurfaceNV)(GLvdpauSurfaceNV surface);
extern void (APIENTRY *gglVDPAUUnregisterSurfaceNV)(GLvdpauSurfaceNV surface);
extern void (APIENTRY *gglVDPAUGetSurfaceivNV)(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values);
extern void (APIENTRY *gglVDPAUSurfaceAccessNV)(GLvdpauSurfaceNV surface, GLenum access);
extern void (APIENTRY *gglVDPAUMapSurfacesNV)(GLsizei numSurfaces, const GLvdpauSurfaceNV* surfaces);
extern void (APIENTRY *gglVDPAUUnmapSurfacesNV)(GLsizei numSurface, const GLvdpauSurfaceNV* surfaces);

/* GL_AMD_transform_feedback3_lines_triangles */

/* GL_AMD_depth_clamp_separate */

/* GL_EXT_texture_sRGB_decode */

/* GL_NV_texture_multisample */
extern void (APIENTRY *gglTexImage2DMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
extern void (APIENTRY *gglTexImage3DMultisampleCoverageNV)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
extern void (APIENTRY *gglTextureImage2DMultisampleNV)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
extern void (APIENTRY *gglTextureImage3DMultisampleNV)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
extern void (APIENTRY *gglTextureImage2DMultisampleCoverageNV)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
extern void (APIENTRY *gglTextureImage3DMultisampleCoverageNV)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);

/* GL_AMD_blend_minmax_factor */

/* GL_AMD_sample_positions */
extern void (APIENTRY *gglSetMultisamplefvAMD)(GLenum pname, GLuint index, const GLfloat* val);

/* GL_EXT_x11_sync_object */
extern GLsync (APIENTRY *gglImportSyncEXT)(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);

/* GL_AMD_multi_draw_indirect */
extern void (APIENTRY *gglMultiDrawArraysIndirectAMD)(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
extern void (APIENTRY *gglMultiDrawElementsIndirectAMD)(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride);

/* GL_EXT_framebuffer_multisample_blit_scaled */

/* GL_NV_path_rendering */
extern GLuint (APIENTRY *gglGenPathsNV)(GLsizei range);
extern void (APIENTRY *gglDeletePathsNV)(GLuint path, GLsizei range);
extern GLboolean (APIENTRY *gglIsPathNV)(GLuint path);
extern void (APIENTRY *gglPathCommandsNV)(GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
extern void (APIENTRY *gglPathCoordsNV)(GLuint path, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
extern void (APIENTRY *gglPathSubCommandsNV)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
extern void (APIENTRY *gglPathSubCoordsNV)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const GLvoid* coords);
extern void (APIENTRY *gglPathStringNV)(GLuint path, GLenum format, GLsizei length, const GLvoid* pathString);
extern void (APIENTRY *gglPathGlyphsNV)(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const GLvoid* charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
extern void (APIENTRY *gglPathGlyphRangeNV)(GLuint firstPathName, GLenum fontTarget, const GLvoid* fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
extern void (APIENTRY *gglWeightPathsNV)(GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights);
extern void (APIENTRY *gglCopyPathNV)(GLuint resultPath, GLuint srcPath);
extern void (APIENTRY *gglInterpolatePathsNV)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
extern void (APIENTRY *gglTransformPathNV)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues);
extern void (APIENTRY *gglPathParameterivNV)(GLuint path, GLenum pname, const GLint* value);
extern void (APIENTRY *gglPathParameteriNV)(GLuint path, GLenum pname, GLint value);
extern void (APIENTRY *gglPathParameterfvNV)(GLuint path, GLenum pname, const GLfloat* value);
extern void (APIENTRY *gglPathParameterfNV)(GLuint path, GLenum pname, GLfloat value);
extern void (APIENTRY *gglPathDashArrayNV)(GLuint path, GLsizei dashCount, const GLfloat* dashArray);
extern void (APIENTRY *gglPathStencilFuncNV)(GLenum func, GLint ref, GLuint mask);
extern void (APIENTRY *gglPathStencilDepthOffsetNV)(GLfloat factor, GLfloat units);
extern void (APIENTRY *gglStencilFillPathNV)(GLuint path, GLenum fillMode, GLuint mask);
extern void (APIENTRY *gglStencilStrokePathNV)(GLuint path, GLint reference, GLuint mask);
extern void (APIENTRY *gglStencilFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat* transformValues);
extern void (APIENTRY *gglStencilStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat* transformValues);
extern void (APIENTRY *gglPathCoverDepthFuncNV)(GLenum func);
extern void (APIENTRY *gglPathColorGenNV)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat* coeffs);
extern void (APIENTRY *gglPathTexGenNV)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat* coeffs);
extern void (APIENTRY *gglPathFogGenNV)(GLenum genMode);
extern void (APIENTRY *gglCoverFillPathNV)(GLuint path, GLenum coverMode);
extern void (APIENTRY *gglCoverStrokePathNV)(GLuint path, GLenum coverMode);
extern void (APIENTRY *gglCoverFillPathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
extern void (APIENTRY *gglCoverStrokePathInstancedNV)(GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
extern void (APIENTRY *gglGetPathParameterivNV)(GLuint path, GLenum pname, GLint* value);
extern void (APIENTRY *gglGetPathParameterfvNV)(GLuint path, GLenum pname, GLfloat* value);
extern void (APIENTRY *gglGetPathCommandsNV)(GLuint path, GLubyte* commands);
extern void (APIENTRY *gglGetPathCoordsNV)(GLuint path, GLfloat* coords);
extern void (APIENTRY *gglGetPathDashArrayNV)(GLuint path, GLfloat* dashArray);
extern void (APIENTRY *gglGetPathMetricsNV)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLsizei stride, GLfloat* metrics);
extern void (APIENTRY *gglGetPathMetricRangeNV)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat* metrics);
extern void (APIENTRY *gglGetPathSpacingNV)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const GLvoid* paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat* returnedSpacing);
extern void (APIENTRY *gglGetPathColorGenivNV)(GLenum color, GLenum pname, GLint* value);
extern void (APIENTRY *gglGetPathColorGenfvNV)(GLenum color, GLenum pname, GLfloat* value);
extern void (APIENTRY *gglGetPathTexGenivNV)(GLenum texCoordSet, GLenum pname, GLint* value);
extern void (APIENTRY *gglGetPathTexGenfvNV)(GLenum texCoordSet, GLenum pname, GLfloat* value);
extern GLboolean (APIENTRY *gglIsPointInFillPathNV)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
extern GLboolean (APIENTRY *gglIsPointInStrokePathNV)(GLuint path, GLfloat x, GLfloat y);
extern GLfloat (APIENTRY *gglGetPathLengthNV)(GLuint path, GLsizei startSegment, GLsizei numSegments);
extern GLboolean (APIENTRY *gglPointAlongPathNV)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat* y, GLfloat* tangentX, GLfloat* tangentY);

/* GL_AMD_pinned_memory */

/* GL_AMD_stencil_operation_extended */
extern void (APIENTRY *gglStencilOpValueAMD)(GLenum face, GLuint value);

/* GL_AMD_vertex_shader_viewport_index */

/* GL_AMD_vertex_shader_layer */

/* GL_NV_bindless_texture */
extern GLuint64 (APIENTRY *gglGetTextureHandleNV)(GLuint texture);
extern GLuint64 (APIENTRY *gglGetTextureSamplerHandleNV)(GLuint texture, GLuint sampler);
extern void (APIENTRY *gglMakeTextureHandleResidentNV)(GLuint64 handle);
extern void (APIENTRY *gglMakeTextureHandleNonResidentNV)(GLuint64 handle);
extern GLuint64 (APIENTRY *gglGetImageHandleNV)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
extern void (APIENTRY *gglMakeImageHandleResidentNV)(GLuint64 handle, GLenum access);
extern void (APIENTRY *gglMakeImageHandleNonResidentNV)(GLuint64 handle);
extern void (APIENTRY *gglUniformHandleui64NV)(GLint location, GLuint64 value);
extern void (APIENTRY *gglUniformHandleui64vNV)(GLint location, GLsizei count, const GLuint64* value);
extern void (APIENTRY *gglProgramUniformHandleui64NV)(GLuint program, GLint location, GLuint64 value);
extern void (APIENTRY *gglProgramUniformHandleui64vNV)(GLuint program, GLint location, GLsizei count, const GLuint64* values);
extern GLboolean (APIENTRY *gglIsTextureHandleResidentNV)(GLuint64 handle);
extern GLboolean (APIENTRY *gglIsImageHandleResidentNV)(GLuint64 handle);

/* GL_NV_shader_atomic_float */

/* GL_AMD_query_buffer_object */

/* GL_AMD_sparse_texture */
extern void (APIENTRY *gglTexStorageSparseAMD)(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
extern void (APIENTRY *gglTextureStorageSparseAMD)(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);

typedef struct {
	int _GL_3DFX_multisample : 1;
	int _GL_3DFX_texture_compression_FXT1 : 1;
	int _GL_AMD_blend_minmax_factor : 1;
	int _GL_AMD_conservative_depth : 1;
	int _GL_AMD_depth_clamp_separate : 1;
	int _GL_AMD_pinned_memory : 1;
	int _GL_AMD_query_buffer_object : 1;
	int _GL_AMD_seamless_cubemap_per_texture : 1;
	int _GL_AMD_shader_stencil_export : 1;
	int _GL_AMD_texture_texture4 : 1;
	int _GL_AMD_transform_feedback3_lines_triangles : 1;
	int _GL_AMD_vertex_shader_layer : 1;
	int _GL_AMD_vertex_shader_viewport_index : 1;
	int _GL_APPLE_aux_depth_stencil : 1;
	int _GL_APPLE_client_storage : 1;
	int _GL_APPLE_float_pixels : 1;
	int _GL_APPLE_rgb_422 : 1;
	int _GL_APPLE_row_bytes : 1;
	int _GL_APPLE_specular_vector : 1;
	int _GL_APPLE_transform_hint : 1;
	int _GL_APPLE_ycbcr_422 : 1;
	int _GL_ARB_ES3_compatibility : 1;
	int _GL_ARB_arrays_of_arrays : 1;
	int _GL_ARB_compatibility : 1;
	int _GL_ARB_compressed_texture_pixel_storage : 1;
	int _GL_ARB_conservative_depth : 1;
	int _GL_ARB_depth_buffer_float : 1;
	int _GL_ARB_depth_clamp : 1;
	int _GL_ARB_depth_texture : 1;
	int _GL_ARB_explicit_attrib_location : 1;
	int _GL_ARB_explicit_uniform_location : 1;
	int _GL_ARB_fragment_coord_conventions : 1;
	int _GL_ARB_fragment_layer_viewport : 1;
	int _GL_ARB_fragment_program : 1;
	int _GL_ARB_fragment_program_shadow : 1;
	int _GL_ARB_fragment_shader : 1;
	int _GL_ARB_framebuffer_sRGB : 1;
	int _GL_ARB_gpu_shader5 : 1;
	int _GL_ARB_half_float_pixel : 1;
	int _GL_ARB_half_float_vertex : 1;
	int _GL_ARB_map_buffer_alignment : 1;
	int _GL_ARB_occlusion_query2 : 1;
	int _GL_ARB_pixel_buffer_object : 1;
	int _GL_ARB_point_sprite : 1;
	int _GL_ARB_robust_buffer_access_behavior : 1;
	int _GL_ARB_robustness_isolation : 1;
	int _GL_ARB_seamless_cube_map : 1;
	int _GL_ARB_shader_bit_encoding : 1;
	int _GL_ARB_shader_image_size : 1;
	int _GL_ARB_shader_stencil_export : 1;
	int _GL_ARB_shader_texture_lod : 1;
	int _GL_ARB_shading_language_100 : 1;
	int _GL_ARB_shading_language_420pack : 1;
	int _GL_ARB_shading_language_packing : 1;
	int _GL_ARB_shadow : 1;
	int _GL_ARB_shadow_ambient : 1;
	int _GL_ARB_stencil_texturing : 1;
	int _GL_ARB_texture_border_clamp : 1;
	int _GL_ARB_texture_buffer_object_rgb32 : 1;
	int _GL_ARB_texture_compression_bptc : 1;
	int _GL_ARB_texture_compression_rgtc : 1;
	int _GL_ARB_texture_cube_map : 1;
	int _GL_ARB_texture_cube_map_array : 1;
	int _GL_ARB_texture_env_add : 1;
	int _GL_ARB_texture_env_combine : 1;
	int _GL_ARB_texture_env_crossbar : 1;
	int _GL_ARB_texture_env_dot3 : 1;
	int _GL_ARB_texture_float : 1;
	int _GL_ARB_texture_gather : 1;
	int _GL_ARB_texture_mirrored_repeat : 1;
	int _GL_ARB_texture_non_power_of_two : 1;
	int _GL_ARB_texture_query_levels : 1;
	int _GL_ARB_texture_query_lod : 1;
	int _GL_ARB_texture_rectangle : 1;
	int _GL_ARB_texture_rg : 1;
	int _GL_ARB_texture_rgb10_a2ui : 1;
	int _GL_ARB_texture_swizzle : 1;
	int _GL_ARB_vertex_array_bgra : 1;
	int _GL_ATI_meminfo : 1;
	int _GL_ATI_pixel_format_float : 1;
	int _GL_ATI_text_fragment_shader : 1;
	int _GL_ATI_texture_env_combine3 : 1;
	int _GL_ATI_texture_float : 1;
	int _GL_ATI_texture_mirror_once : 1;
	int _GL_EXT_422_pixels : 1;
	int _GL_EXT_abgr : 1;
	int _GL_EXT_bgra : 1;
	int _GL_EXT_blend_logic_op : 1;
	int _GL_EXT_blend_subtract : 1;
	int _GL_EXT_clip_volume_hint : 1;
	int _GL_EXT_cmyka : 1;
	int _GL_EXT_framebuffer_multisample_blit_scaled : 1;
	int _GL_EXT_framebuffer_sRGB : 1;
	int _GL_EXT_index_array_formats : 1;
	int _GL_EXT_index_texture : 1;
	int _GL_EXT_misc_attribute : 1;
	int _GL_EXT_packed_depth_stencil : 1;
	int _GL_EXT_packed_float : 1;
	int _GL_EXT_packed_pixels : 1;
	int _GL_EXT_pixel_buffer_object : 1;
	int _GL_EXT_pixel_transform_color_table : 1;
	int _GL_EXT_rescale_normal : 1;
	int _GL_EXT_separate_specular_color : 1;
	int _GL_EXT_shadow_funcs : 1;
	int _GL_EXT_shared_texture_palette : 1;
	int _GL_EXT_stencil_wrap : 1;
	int _GL_EXT_texture : 1;
	int _GL_EXT_texture_array : 1;
	int _GL_EXT_texture_compression_latc : 1;
	int _GL_EXT_texture_compression_rgtc : 1;
	int _GL_EXT_texture_compression_s3tc : 1;
	int _GL_EXT_texture_env_add : 1;
	int _GL_EXT_texture_env_combine : 1;
	int _GL_EXT_texture_env_dot3 : 1;
	int _GL_EXT_texture_filter_anisotropic : 1;
	int _GL_EXT_texture_lod_bias : 1;
	int _GL_EXT_texture_mirror_clamp : 1;
	int _GL_EXT_texture_sRGB : 1;
	int _GL_EXT_texture_sRGB_decode : 1;
	int _GL_EXT_texture_shared_exponent : 1;
	int _GL_EXT_texture_snorm : 1;
	int _GL_EXT_texture_swizzle : 1;
	int _GL_EXT_vertex_array_bgra : 1;
	int _GL_HP_convolution_border_modes : 1;
	int _GL_HP_occlusion_test : 1;
	int _GL_HP_texture_lighting : 1;
	int _GL_IBM_cull_vertex : 1;
	int _GL_IBM_rasterpos_clip : 1;
	int _GL_INGR_color_clamp : 1;
	int _GL_INGR_interlace_read : 1;
	int _GL_KHR_texture_compression_astc_ldr : 1;
	int _GL_MESAX_texture_stack : 1;
	int _GL_MESA_pack_invert : 1;
	int _GL_MESA_ycbcr_texture : 1;
	int _GL_NV_blend_square : 1;
	int _GL_NV_copy_depth_to_color : 1;
	int _GL_NV_depth_clamp : 1;
	int _GL_NV_float_buffer : 1;
	int _GL_NV_fog_distance : 1;
	int _GL_NV_fragment_program : 1;
	int _GL_NV_fragment_program2 : 1;
	int _GL_NV_fragment_program4 : 1;
	int _GL_NV_fragment_program_option : 1;
	int _GL_NV_geometry_shader4 : 1;
	int _GL_NV_light_max_exponent : 1;
	int _GL_NV_multisample_coverage : 1;
	int _GL_NV_multisample_filter_hint : 1;
	int _GL_NV_packed_depth_stencil : 1;
	int _GL_NV_parameter_buffer_object2 : 1;
	int _GL_NV_shader_atomic_float : 1;
	int _GL_NV_shader_buffer_store : 1;
	int _GL_NV_tessellation_program5 : 1;
	int _GL_NV_texgen_emboss : 1;
	int _GL_NV_texgen_reflection : 1;
	int _GL_NV_texture_compression_vtc : 1;
	int _GL_NV_texture_env_combine4 : 1;
	int _GL_NV_texture_expand_normal : 1;
	int _GL_NV_texture_rectangle : 1;
	int _GL_NV_texture_shader : 1;
	int _GL_NV_texture_shader2 : 1;
	int _GL_NV_texture_shader3 : 1;
	int _GL_NV_vertex_array_range2 : 1;
	int _GL_NV_vertex_program1_1 : 1;
	int _GL_NV_vertex_program2 : 1;
	int _GL_NV_vertex_program2_option : 1;
	int _GL_NV_vertex_program3 : 1;
	int _GL_OES_read_format : 1;
	int _GL_OML_interlace : 1;
	int _GL_OML_resample : 1;
	int _GL_OML_subsample : 1;
	int _GL_PGI_vertex_hints : 1;
	int _GL_REND_screen_coordinates : 1;
	int _GL_S3_s3tc : 1;
	int _GL_SGIS_generate_mipmap : 1;
	int _GL_SGIS_point_line_texgen : 1;
	int _GL_SGIS_texture_border_clamp : 1;
	int _GL_SGIS_texture_edge_clamp : 1;
	int _GL_SGIS_texture_lod : 1;
	int _GL_SGIX_async_histogram : 1;
	int _GL_SGIX_async_pixel : 1;
	int _GL_SGIX_blend_alpha_minmax : 1;
	int _GL_SGIX_calligraphic_fragment : 1;
	int _GL_SGIX_clipmap : 1;
	int _GL_SGIX_convolution_accuracy : 1;
	int _GL_SGIX_depth_pass_instrument : 1;
	int _GL_SGIX_depth_texture : 1;
	int _GL_SGIX_fog_offset : 1;
	int _GL_SGIX_fog_scale : 1;
	int _GL_SGIX_interlace : 1;
	int _GL_SGIX_ir_instrument1 : 1;
	int _GL_SGIX_pixel_tiles : 1;
	int _GL_SGIX_resample : 1;
	int _GL_SGIX_scalebias_hint : 1;
	int _GL_SGIX_shadow : 1;
	int _GL_SGIX_shadow_ambient : 1;
	int _GL_SGIX_subsample : 1;
	int _GL_SGIX_texture_add_env : 1;
	int _GL_SGIX_texture_coordinate_clamp : 1;
	int _GL_SGIX_texture_lod_bias : 1;
	int _GL_SGIX_texture_multi_buffer : 1;
	int _GL_SGIX_texture_scale_bias : 1;
	int _GL_SGIX_texture_select : 1;
	int _GL_SGIX_vertex_preclip : 1;
	int _GL_SGIX_ycrcb : 1;
	int _GL_SGIX_ycrcb_subsample : 1;
	int _GL_SGIX_ycrcba : 1;
	int _GL_SGI_color_matrix : 1;
	int _GL_SGI_texture_color_table : 1;
	int _GL_SUNX_constant_data : 1;
	int _GL_SUN_convolution_border_modes : 1;
	int _GL_SUN_global_alpha : 1;
	int _GL_SUN_mesh_array : 1;
	int _GL_SUN_slice_accum : 1;
	int _GL_SUN_triangle_list : 1;
	int _GL_SUN_vertex : 1;
	int _GL_WIN_phong_shading : 1;
	int _GL_WIN_specular_fog : 1;
} gglext_t;

extern gglext_t gglext;

extern void ggl_init(int enableDebug);
extern void ggl_rebind(int enableDebug);
extern void ggl_check_extensions();

#ifdef __cplusplus
}
#endif

#endif /* __GGL_H__ */
