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

#include "Monsta/Renderer/Pipeline/ElementBuffer.h"
#include <spdlog/spdlog.h>

namespace Monsta::Renderer
{

ElementBuffer::ElementBuffer ()
    : m_ebo ( 0 )
{
}

ElementBuffer::~ElementBuffer () = default;

[[maybe_unused]] uint32_t
ElementBuffer::create () noexcept
{
  if ( m_ebo != 0 )
    return m_ebo;
  glGenBuffers ( 1, &m_ebo );
  return m_ebo;
}

void
ElementBuffer::destroy () noexcept
{
  if ( m_ebo == 0 )
    {
      spdlog::warn ( "Attempting to delete EBO of 0" );
      return;
    }
  glDeleteBuffers ( 1, &m_ebo );
}

void
ElementBuffer::bind () const noexcept
{
  if ( m_ebo == 0 )
    {
      spdlog::warn ( "Attempting to bind EBO of 0" );
      return;
    }
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER, m_ebo );
}

void
ElementBuffer::bufferData ( size_t size, const void* data, const BufferMode& bufferMode ) const noexcept
{
  if ( m_ebo == 0 )
    {
      spdlog::warn ( "Attempting to buffer data to EBO of 0" );
      return;
    }
  glBufferData ( GL_ELEMENT_ARRAY_BUFFER, size, data, static_cast<GLenum> ( bufferMode ) );
}

}
