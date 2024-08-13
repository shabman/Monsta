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
#define GL_SILENCE_DEPRECATION // Fuck You Apple (JK Metal Support Soon)
#endif

#include <GL/glew.h>

#include "Monsta/Config.h"
#include "Monsta/Core/Window.h"

#include <spdlog/spdlog.h>

static GLFWwindow* __monsta_core_window = nullptr;
static bool __monsta_glfw_init = false;

namespace Monsta::Core
{

Window::Window ( uint32_t width, uint32_t height, const char* title )
    : m_width ( width ), m_height ( height ), m_title ( title )
{
  // TODO: Maybe just make it return a reference to the parent?
  if ( __monsta_core_window != nullptr || __monsta_glfw_init )
    {
      spdlog::warn ( "Main Window already exists" );
      return;
    }

  if ( !glfwInit () )
    {
      spdlog::error ( "Failed to initialise GLFW. Aborting..." );
      return;
    }

  __monsta_glfw_init = true;

  glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
  glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 3 );
  glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
  glfwWindowHint ( GLFW_SAMPLES, 4 );
#ifdef MONSTA_PLAT_MAC
  glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
  spdlog::info ( "GLFW macOS Window hints set" );
#endif

  spdlog::info ( "GLFW Window Initialised" );
}

Window::~Window ()
{
  glfwTerminate ();
  spdlog::info ( "GLFW Window Terminated" );
}

void
Window::init () noexcept
{
  if ( ( m_window = glfwCreateWindow ( m_width, m_height, m_title, NULL, NULL ) ) == NULL )
    {
      spdlog::error ( "GLFW Failed to create Window" );
      glfwTerminate ();
      return;
    }

  glfwMakeContextCurrent ( m_window );

  if ( glewInit () != GLEW_OK )
    {
      spdlog::error ( "GLEW Failed to initialise Wrangler" );
      glfwTerminate ();
      return;
    }

  int fx, fy;
  glfwGetFramebufferSize ( m_window, &fx, &fy );
  glViewport ( 0, 0, fx, fy );

  __monsta_core_window = m_window;
  spdlog::info ( "GLFW Window & GLEW Ready" );
}

void
Window::close () noexcept
{
  glfwSetWindowShouldClose ( m_window, 1 );
}

void
Window::attachContext ( const Renderer::Context* context ) noexcept
{
  m_ctx = const_cast<Renderer::Context*> ( context );
}

void
Window::start () noexcept
{
  spdlog::info ( "[MONSTA]: Starting Renderer" );
  while ( !glfwWindowShouldClose ( m_window ) )
    {
      glClear ( GL_COLOR_BUFFER_BIT );
      glClearColor ( 1.0, 1.0, 0.0, 1.0 );
      glfwPollEvents ();
      glfwSwapBuffers ( m_window );
    }
  spdlog::info ( "[MONSTA]: Stopping Renderer" );
}

GLFWwindow*
Window::getCoreWindow () const noexcept
{
  return m_window;
}

const char*
Window::getTitle () const noexcept
{
  return m_title;
}

Renderer::Context*
Window::getContext () const noexcept
{
  return m_ctx;
}

uint32_t
Window::getWidth () const noexcept
{
  return m_width;
}

uint32_t
Window::getHeight () const noexcept
{
  return m_height;
}

}