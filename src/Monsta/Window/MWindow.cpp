#include <GL/glew.h>

#include "Monsta/Events/Input/InputAdapter.h"
#include "Monsta/Events/Window/WindowAdapter.h"
#include "Monsta/Platform/Platform.h"
#include "Monsta/Platform/Version.h"
#include "Monsta/Window/MWindow.h"

Monsta::MWindow *__mwindow = nullptr;

namespace Monsta
{

MWindow::
MWindow ()
{
  this->m_Window = nullptr;
  this->m_Context = nullptr;
  this->did_init = glfwInit ();
  this->m_Width = 0;
  this->m_Height = 0;
  this->m_Title = "";
  this->m_ContextMode = Context::GraphicsContextMode::MONSTA_UNKNOWN_GRAPHICS;
}

MWindow::~
MWindow ()
{
  if ( this->m_Context != nullptr )
    {
      delete this->m_Context;
    }
  glfwTerminate ();
}

MWindow *
MWindow::get_instance () noexcept
{
  if ( __mwindow == nullptr )
    {
      __mwindow = new MWindow;
    }
  return __mwindow;
}

bool
MWindow::init_window ( int &&width, int &&height, const char *title ) noexcept
{
  if ( !this->did_init )
    return false;

  this->m_Width = width;
  this->m_Height = height;
  this->m_Title = title;

  glfwWindowHint ( GLFW_SCALE_TO_MONITOR, GL_TRUE );
  glfwWindowHint ( GLFW_SCALE_FRAMEBUFFER, GL_TRUE );
  glfwWindowHint ( GLFW_RESIZABLE, GL_TRUE );
  glfwWindowHint ( GLFW_FLOATING, GL_FALSE );

#ifdef MONSTA_PLAT_MAC
  glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, LIB_MONSTA_OPENGL_MAJOR );
  glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, LIB_MONSTA_OPENGL_MINOR );
  glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
  glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
  // NOTE: Might cause problems later on if not un-commented
  // glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#endif

  this->m_Window = glfwCreateWindow ( width, height, title, nullptr, nullptr );

  if ( !this->m_Window )
    {
      glfwTerminate ();
      return false;
    }

  this->m_ContextMode = Context::GraphicsContextMode::MONSTA_OPENGL_GRAPHICS;

  glfwSetWindowFocusCallback ( this->m_Window, WindowAdapter::RegisterWindowFocusEvent );
  glfwSetKeyCallback ( this->m_Window, InputAdapter::InputKeycallBack );
  glfwSetCursorPosCallback ( this->m_Window, InputAdapter::InputMousePositionCallback );

  switch ( this->m_ContextMode )
    {
    case Context::GraphicsContextMode::MONSTA_OPENGL_GRAPHICS:
      {
        this->m_Context = new Context::OpenGLContext ( this->m_Window );
        break;
      }
    case Context::GraphicsContextMode::MONSTA_METAL_API_GRAPHICS:
    case Context::GraphicsContextMode::MONSTA_UNKNOWN_GRAPHICS:
      break;
    }

  glViewport ( 0, 0, width, height );

  if ( glewInit () != GLEW_OK )
    {
      glfwTerminate ();
      return false;
    }

  return true;
}

void
MWindow::deinit_window () noexcept
{
  if ( __mwindow != nullptr )
    {
      delete __mwindow;
    }
}

GLFWwindow *
MWindow::get_glfw_window () const noexcept
{
  return this->m_Window;
}

const int
MWindow::get_width () const noexcept
{
  return this->m_Width;
}

const int
MWindow::get_height () const noexcept
{
  return this->m_Height;
}

const char *
MWindow::get_title () const noexcept
{
  return this->m_Title;
}

Context::GraphicsContext *
MWindow::get_context () const noexcept
{
  return this->m_Context;
}

}