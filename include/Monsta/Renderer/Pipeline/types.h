/**
 *  Monsta 3D Game Engine Framework.
 *  Copyright (C) 2024 Mustafa Malik (avia.shabbyman@gmail.com)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LIB_MONSTA_PIPELINE_TYPES_H
#define LIB_MONSTA_PIPELINE_TYPES_H

#include <GL/glew.h>

namespace Monsta::Renderer
{

/// Determines the specific memory to place the buffer in VRAM
enum class BufferMode
{
  /// Write once, use many times
  BUFFER_STATIC = GL_STATIC_DRAW,
  /// Write many times, use many times
  BUFFER_DYNAMIC = GL_DYNAMIC_DRAW,
  /// Write once, use few times
  BUFFER_STREAM = GL_STREAM_DRAW
};

/**
 * @brief When a shader is compiled this value is returned to determine
 * whether the shader did compile successfully or not.
 *
 * @since 0.0.1
 */
typedef struct shader_result_t
{
  /**
   * @brief If the shader compiled, OpenGL will return a program ID to access the shader program.
   */
  uint32_t programId;
  /**
   * @brief If the shader compiled, this value will be set to true.
   */
  bool isCompiled;
} ShaderResult;

}

#endif /* LIB_MONSTA_PIPELINE_TYPES_H */
