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

#include "Monsta/Renderer/Pipeline/VertexBuffer.h"
#include <spdlog/spdlog.h>

namespace Monsta::Renderer
{

VertexBuffer::VertexBuffer ()
    : m_vbo ( 0 )
{
}

VertexBuffer::~VertexBuffer () = default;

uint32_t
VertexBuffer::create () noexcept
{
  glGenBuffers ( 1, &this->m_vbo );
  return this->m_vbo;
}

void
VertexBuffer::destroy () noexcept
{
  if ( m_vbo == 0 )
    {
      spdlog::warn ( "Cannot delete a NULL VBO" );
      return;
    }
  glDeleteBuffers ( 1, &m_vbo );
}

void
VertexBuffer::bind () const noexcept
{
  if ( m_vbo == 0 )
    {
      spdlog::warn ( "Attempting to bind a VBO of 0" );
      return;
    }
  glBindBuffer ( GL_ARRAY_BUFFER, m_vbo ); // Vertex Buffer (note for myself ;D)
}

void
VertexBuffer::bufferData ( size_t size, const void* data, const BufferMode& bufferMode ) const noexcept
{
  if ( m_vbo == 0 )
    {
      spdlog::warn ( "Attempting to buffer data to a VBO of 0" );
      return;
    }
  glBufferData ( GL_ARRAY_BUFFER, size, data, static_cast<GLenum> ( bufferMode ) );
}

void
VertexBuffer::setAttribute ( uint32_t index, int size, unsigned int type, int stride, void* offset, uint32_t vertIndex ) const noexcept
{
  if ( m_vbo == 0 )
    {
      spdlog::warn ( "Attempting to set attribute to a VBO of 0" );
      return;
    }
  glVertexAttribPointer ( index, size, type, GL_FALSE, stride, offset );
  glEnableVertexAttribArray ( vertIndex );
}

}
