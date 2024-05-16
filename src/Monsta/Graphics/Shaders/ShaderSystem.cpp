//
// Created by Mustafa Malik on 11/05/2024.
//

#include "Monsta/Graphics/Shaders/ShaderSystem.h"
#include "spdlog/spdlog.h"
#include <GL/glew.h>

namespace Monsta
{

ShaderSystem::
ShaderSystem ( const std::string &src )
    : m_Source ( src )
{
}

ShaderSystem::~ShaderSystem () = default;

std::tuple<bool, unsigned int>
ShaderSystem::compile_shader ( const ShaderType &shader_type ) noexcept
{
  GLuint shader_source_id = 0;

  switch ( shader_type )
    {
    case ShaderType::MONSTA_VERTEX_SHADER:
      {
        shader_source_id = glCreateShader ( GL_VERTEX_SHADER );
        break;
      }
    case ShaderType::MONSTA_FRAGMENT_SHADER:
      {
        shader_source_id = glCreateShader ( GL_FRAGMENT_SHADER );
        break;
      }
    }

  if ( shader_source_id == 0 )
    return std::make_tuple ( false, 0 );

  const char *converted_source = m_Source.c_str ();
  glShaderSource ( shader_source_id, 1, &converted_source, nullptr );
  glCompileShader ( shader_source_id );

  GLint did_succeed;
  glGetShaderiv ( shader_source_id, GL_COMPILE_STATUS, &did_succeed );
  if ( !did_succeed )
    {
      char log[ 512 ];
      glGetShaderInfoLog ( shader_source_id, 512, nullptr, log );
      spdlog::error ( "The shader source failed to compile: %s\n", log );
      return std::make_tuple ( false, 0 );
    }

  return std::make_tuple ( true, shader_source_id );
}

bool
ShaderSystem::link_shader ( const unsigned int &shader_pid, const unsigned int &shader_id ) noexcept
{
  GLint did_succeed;
  glAttachShader ( shader_pid, shader_id );
  glLinkProgram ( shader_pid );

  glGetProgramiv ( shader_pid, GL_LINK_STATUS, &did_succeed );
  if ( !did_succeed )
    {
      char log[ 512 ];
      glGetProgramInfoLog ( shader_pid, 512, nullptr, log );
      spdlog::error ( "The shader linking process failed: %s\n", log );
      return false;
    }

  glDeleteShader ( shader_id );
  return true;
}

const std::string &
ShaderSystem::get_source () const noexcept
{
  return this->m_Source;
}

unsigned int
ShaderSystem::get_shader_pid () noexcept
{
  return glCreateProgram ();
}

void
ShaderSystem::destroy_shader_pid ( const unsigned int &pid ) noexcept
{
  glDeleteProgram ( pid );
}

}