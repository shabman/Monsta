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

#include "Monsta/Renderer/Pipeline/VertexArray.h"

#include <GL/glew.h>
#include <spdlog/spdlog.h>

namespace Monsta::Renderer
{

VertexArray::VertexArray ()
    : m_vao ( 0 )
{
  spdlog::info ( "[RENDERER]: VAO Object Created" );
}

VertexArray::~VertexArray ()
{
  this->destroy ();
  this->unbind ();
  spdlog::info ( "[RENDERER]: VAO Object Deleted" );
}

uint32_t
VertexArray::create () noexcept
{
  if ( this->m_vao == 0 )
    {
      glGenVertexArrays ( 1, &this->m_vao );
      glEnableVertexAttribArray ( 0 );
    }
  return this->m_vao;
}

void
VertexArray::destroy () noexcept
{
  glDeleteVertexArrays ( 1, &this->m_vao );
  this->m_vao = 0;
}

void
VertexArray::bind () noexcept
{
  if ( this->m_vao == 0 )
    {
      spdlog::warn ( "[RENDERER]: Binding a VAO with 0, not the allocated value" );
    }
  glBindVertexArray ( this->m_vao );
}

void
VertexArray::unbind () noexcept
{
  glBindVertexArray ( 0 );
}

}
