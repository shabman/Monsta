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

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "Monsta/Core/Window.h"
#include "Monsta/Config.h"

#include <spdlog/spdlog.h>

static bool __monsta_glfw_init = false;
static bool __monsta_hints_set = false;

static uint32_t __monsta_window_index = 0;
static GLFWwindow *__monsta_shared_window = nullptr;

namespace Monsta::Core
{

Window::Window ( uint32_t width, uint32_t height, const char *title )
    : m_width ( width ), m_height ( height ), m_title ( title )
{
  m_id = __monsta_window_index;

  if ( !__monsta_glfw_init )
    {
      if ( !glfwInit () )
        {
          spdlog::error ( "Unable to initialise GLFW. Aborting..." );
          return;
        }
      __monsta_glfw_init = true;
    }

  if ( __monsta_hints_set )
    {
      glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, MONSTA_OPENGL_MAJOR_VERSION );
      glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, MONSTA_OPENGL_MINOR_VERSION );
      glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
      glfwWindowHint ( GLFW_SAMPLES, 4 );
#ifdef MONSTA_PLAT_MAC
      glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
#endif
      __monsta_hints_set = true;
    }

  __monsta_window_index++;
  spdlog::info ( "Window Object Created (ID): {}", m_id );
}

Window::~Window ()
{
  if ( m_id == 0 )
    {
      __monsta_glfw_init = false;
      __monsta_hints_set = false;
      __monsta_window_index = 0;
      glfwTerminate ();

      spdlog::info ( "Window Parent Deallocated" );
    }
  else
    __monsta_window_index--;

  spdlog::info ( "Window Object Destroyed" );
}

void
Window::show ( bool shared ) noexcept
{
  m_window = glfwCreateWindow ( m_width, m_height, m_title, NULL, ( shared && m_id != 0 ) ? m_window : NULL );
  if ( m_window == nullptr )
    {
      if ( m_id == 0 )
        glfwTerminate ();
      spdlog::error ( "Unable to create GLFW Window" );
      return;
    }

  if ( m_id == 0 )
    __monsta_shared_window = m_window;

  glfwMakeContextCurrent ( m_window );

  int fx, fy;
  glfwGetFramebufferSize ( m_window, &fx, &fy );
  glViewport ( fx, fy, m_width, m_height );

  spdlog::info ( "GLFW Window Configured" );
}

void
Window::close () noexcept
{
  glfwSetWindowShouldClose ( m_window, 1 );
}

void
Window::attachContext ( void * ) noexcept
{
}

void
Window::start () noexcept
{
  spdlog::info ( "Starting Renderer" );
  while ( !glfwWindowShouldClose ( m_window ) )
    {
      glClear ( GL_COLOR_BUFFER_BIT );
      glClearColor ( 1, 1, 0, 1 );
      glfwPollEvents ();
      glfwSwapBuffers ( m_window );
    }
}

}