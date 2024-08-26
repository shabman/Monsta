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

#ifndef LIB_MONSTA_INVALID_SHADER_EXCEPTION_H
#define LIB_MONSTA_INVALID_SHADER_EXCEPTION_H

#include <stdexcept>

namespace Monsta
{

/**
 * @brief An exception class that throws an error if a GLSL Shader program is invalid
 *
 * @since 0.0.1
 */
class InvalidShaderException final : public std::exception
{
public:
  /**
   * @brief Returns the cause of the exception
   *
   * @return A C-Styled string with the reason of the exception
   */
  const char*
  what () const _NOEXCEPT override
  {
    return "Shader source is empty or invalid";
  }
};

}

#endif /* LIB_MONSTA_INVALID_SHADER_EXCEPTION_H */
