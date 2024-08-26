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

#ifndef LIB_MONSTA_VERTEX_BUFFER_H
#define LIB_MONSTA_VERTEX_BUFFER_H

#include "types.h"

#include <GL/glew.h>
#include <cstdint>

namespace Monsta::Renderer
{

class VertexBuffer final
{
private:
  uint32_t m_vbo;

public:
  VertexBuffer ();
  ~VertexBuffer ();

public:
  [[maybe_unused]] uint32_t create () noexcept;
  void destroy () noexcept;

  void bind () const noexcept;
  void bufferData ( size_t, const void*, const BufferMode& ) const noexcept;

  void setAttribute ( uint32_t, int, unsigned int, int, void*, uint32_t ) const noexcept;
};

}

#endif /* LIB_MONSTA_VERTEX_BUFFER_H */
