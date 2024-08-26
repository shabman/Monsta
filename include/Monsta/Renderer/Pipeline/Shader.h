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

#ifndef LIB_MONSTA_SHADER_H
#define LIB_MONSTA_SHADER_H

#include "types.h"
#include <cstdint>

namespace Monsta::Renderer
{

/**
 * @brief Sends shader programs (GLSL) to the GPU with Vertex and Fragment Shader sources.
 *
 * @since 0.0.1
 */
class Shader final
{
private:
  uint32_t m_programId;
  bool m_succeeded;

  const char* m_vertexSource;
  const char* m_fragSource;

  char m_buf[ 512 ];

public:
  Shader ();
  ~Shader ();

private:
  bool isCompiled ( const uint32_t ) noexcept;
  void configureShader () noexcept ( false );

public:
  /**
   * @brief Compiles both given Shader programs to be executed on the GPU. This method is
   * marked as *nodiscard* because the return values are critical to ensure the shaders
   * compiled successfully.
   *
   * @note If one or the other shader program string is empty, this method will throw an
   * `Monsta::InvalidShaderException`.
   *
   * @param vertexSource - The vertex shader source code.
   * @param fragSource - The fragment shader source code.
   *
   * @return `shader_result_t` which determines whether the shader compiled or not.
   */
  [[nodiscard]] ShaderResult compileShader ( const char*, const char* ) noexcept ( false );
  /**
   * @brief Tells the GPU to start executing the given shader program.
   */
  void select () const noexcept;
  /**
   * @brief Tells the GPU to switch back to the default shader and to end this program.
   */
  void deselect () const noexcept;
};

}

#endif /* LIB_MONSTA_SHADER_H */
