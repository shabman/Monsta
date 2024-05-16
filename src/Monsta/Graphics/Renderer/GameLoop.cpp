//
// Created by Mustafa Malik on 05/05/2024.
//

#include "GL/glew.h"
#include "Monsta/Graphics/Renderer/GameLoop.h"
#include "spdlog/spdlog.h"

static Monsta::Renderer::GameLoop *__render_loop = nullptr;

namespace Monsta::Renderer
{

GameLoop::
GameLoop ( const Context::GraphicsContext *context )
    : m_VertexBuffer ( 0 ), m_VertexArray ( 0 ), m_IndexBuffer ( 0 )
{
  this->m_Context = const_cast<Context::GraphicsContext *> ( context );
}

GameLoop *
GameLoop::get_instance ( const Context::GraphicsContext *ctx )
{
  if ( __render_loop == nullptr )
    {
      spdlog::info ( "Initialising Main Game Loop" );
      __render_loop = new GameLoop ( ctx );
    }
  return __render_loop;
}

void
GameLoop::has_object ( const GameObject * )
{
}

void
GameLoop::add_object ( const GameObject * )
{
}

void
GameLoop::remove_object ( const GameObject * )
{
}

void
GameLoop::start ( GLFWwindow *window )
{
  spdlog::info ( "Started Main Game Loop" );
  // while ( !glfwWindowShouldClose ( window ) )
  //   {
  //
  //     this->m_Context->render ();
  //     this->m_Context->swap_buffers ();
  //
  //     glfwPollEvents ();
  //   }

  this->m_Context->render ();
  this->m_Context->stop_renderer ();
  cleanup ();
}

void
GameLoop::cleanup ()
{
  if ( __render_loop != nullptr )
    {
      delete __render_loop;
      spdlog::info ( "Main Game Loop Terminated" );
    }
}

void
GameLoop::set_context ( Context::GraphicsContext *context )
{
  this->m_Context = context;
}

}