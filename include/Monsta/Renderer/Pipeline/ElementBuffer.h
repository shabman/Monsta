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

#ifndef LIB_MONSTA_ELEMENT_BUFFER_H
#define LIB_MONSTA_ELEMENT_BUFFER_H

#include "types.h"

#include <cstdint>
#include <stddef.h>

namespace Monsta::Renderer
{

/**
 * @brief The element buffer is used as part of indexed drawing.
 *
 * @see [Element Buffers](https://learnopengl.com/Getting-started/Hello-Triangle)
 *
 * @since 0.0.1
 */
class ElementBuffer final
{
private:
  uint32_t m_ebo;

public:
  ElementBuffer ();
  ~ElementBuffer ();

public:
  /**
   * @brief Generates a specific buffer for the EBO.
   *
   * @return An ID to the buffer provided by OpenGL.
   *
   * @note This method is marked as *maybe_unused* since you may not
   * need the ID at all but still there just in case.
   */
  [[maybe_unused]] uint32_t create () noexcept;
  /**
   * @brief Destroys the buffer and sets the ID to 0.
   */
  void destroy () noexcept;
  /**
   * @brief Activates the buffer and makes it usable.
   */
  void bind () const noexcept;
  /**
   * @brief Filling the buffer with data to be passed onto the GPU.
   *
   * @param size - The size of the data we are passing (in bytes).
   * @param data - The array of data we are providing (the indexed values of our vertices array).
   * @param bufferMode - Depending on the value, OpenGL will place the buffer in various areas in memory
   * for faster reads/writes.
   */
  void bufferData ( size_t, const void*, const BufferMode& ) const noexcept;
};

}

#endif /* LIB_MONSTA_ELEMENT_BUFFER_H */
