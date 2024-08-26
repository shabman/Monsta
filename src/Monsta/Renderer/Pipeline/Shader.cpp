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

#include "Monsta/Renderer/Pipeline/Shader.h"
#include "Monsta/Exceptions/InvalidShaderException.h"

#include <iostream>
#include <spdlog/spdlog.h>

namespace Monsta::Renderer
{

Shader::Shader ()
    : m_vertexSource ( "" ), m_fragSource ( "" ), m_programId ( 0 ), m_succeeded ( false )
{
}

Shader::~Shader () = default;

bool
Shader::isCompiled ( const uint32_t shader ) noexcept
{
  int status;
  glGetShaderiv ( shader, GL_COMPILE_STATUS, &status );

  if ( status != GL_TRUE )
    {
      glGetShaderInfoLog ( shader, sizeof ( m_buf ) * sizeof ( char ), NULL, m_buf );
      std::cout << "[SHADER COMPILE ERROR]: " << m_buf << "\n";
      return false;
    }

  return true;
}

void
Shader::configureShader () noexcept ( false )
{
  if ( m_vertexSource[ 0 ] == '\0' || m_fragSource[ 0 ] == '\0' )
    {
      spdlog::error ( "Cannot configure empty string Shader values" );
      throw InvalidShaderException ();
    }

  uint32_t vertShader = glCreateShader ( GL_VERTEX_SHADER );
  uint32_t fragShader = glCreateShader ( GL_FRAGMENT_SHADER );

  glShaderSource ( vertShader, 1, &m_vertexSource, NULL );
  glShaderSource ( fragShader, 1, &m_fragSource, NULL );

  glCompileShader ( vertShader );
  if ( !this->isCompiled ( vertShader ) )
    {
      throw InvalidShaderException ();
    }

  glCompileShader ( fragShader );
  if ( !this->isCompiled ( fragShader ) )
    {
      throw InvalidShaderException ();
    }

  uint32_t program = glCreateProgram ();
  glAttachShader ( program, vertShader );
  glAttachShader ( program, fragShader );

  glLinkProgram ( program );
  int linker_status;

  glGetProgramiv ( program, GL_LINK_STATUS, &linker_status );
  if ( linker_status != GL_TRUE )
    {
      m_programId = 0;
      glGetProgramInfoLog ( program, sizeof ( m_buf ) * sizeof ( char ), NULL, m_buf );
      std::cout << "[SHADER LINK ERROR]: " << m_buf << "\n";
      throw InvalidShaderException ();
    }

  m_succeeded = true;
  m_programId = program;
}

[[nodiscard]] ShaderResult
Shader::compileShader ( const char* vert, const char* frag ) noexcept ( false )
{

  m_vertexSource = vert;
  m_fragSource = frag;

  this->configureShader ();

  return {
    m_programId,
    m_succeeded
  };
}

void
Shader::select () const noexcept
{
  if ( m_programId == 0 || !m_succeeded )
    {
      spdlog::warn ( "Ignoring shader select request because the shader is NULL" );
      return;
    }
  glUseProgram ( m_programId );
}

void
Shader::deselect () const noexcept
{
  glUseProgram ( 0 );
}

}
