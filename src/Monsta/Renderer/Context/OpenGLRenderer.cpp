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

#include "Monsta/Renderer/Context/OpenGLRenderer.h"

#include <GL/glew.h>
#include <memory>
#include <spdlog/spdlog.h>

namespace Monsta::Renderer
{

OpenGLRenderer::OpenGLRenderer ()
    : m_vertices ( 0 )
{
  spdlog::info ( "[MONSTA]: Allocated OpenGL Renderer" );
}

OpenGLRenderer::~OpenGLRenderer ()
{
  m_vertexObject.destroy ();
  spdlog::info ( "[MONSTA]: Deallocated OpenGL Renderer" );
}

OpenGLRenderer*
OpenGLRenderer::getInstance () noexcept
{
  static OpenGLRenderer instance;
  return &instance;
}

void
OpenGLRenderer::init () noexcept
{
  m_vertexObject.create ();
  m_vertexObject.bind ();
}

void
OpenGLRenderer::run () noexcept
{
  glClear ( GL_COLOR_BUFFER_BIT );
  glClearColor ( 1.0, 1.0, 0.0, 1.0 );
}

void
OpenGLRenderer::release () noexcept
{
}

}
