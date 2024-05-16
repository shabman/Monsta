//
// Created by Mustafa Malik on 07/05/2024.
//

#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include "Monsta/Graphics/Context/OpenGLContext.h"
#include "Monsta/Graphics/Shaders/ShaderSystem.h"

#include "spdlog/spdlog.h"

namespace Monsta::Context
{

OpenGLContext::
OpenGLContext ( GLFWwindow *handle )
    : m_Handle ( handle )
{
  this->init_context ();
}

OpenGLContext::~
OpenGLContext ()
{
  this->close_context ();
}

void
OpenGLContext::init_context ()
{
  spdlog::info ( "Initialising OpenGL Grpahics Context" );
  spdlog::error("ok");

  //glfwMakeContextCurrent ( this->m_Handle );

  const char *vertex = "#version 330 core layout (location = 0) in vec3 aPos; void main() { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }";
  const char *frag = "#version 330 core out vec4 FragColor; void main() { FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }";

  ShaderSystem vertex_shader ( vertex );
  ShaderSystem frag_shader ( frag );
  GLuint shader_program = ShaderSystem::get_shader_pid ();

  auto vertex_result = vertex_shader.compile_shader ( ShaderType::MONSTA_VERTEX_SHADER );
  auto frag_result = frag_shader.compile_shader ( ShaderType::MONSTA_FRAGMENT_SHADER );

  if ( !std::get<0> ( vertex_result ) || !std::get<0> ( frag_result ) )
    {
      glfwTerminate ();
      return;
    }

  bool vcr = vertex_shader.link_shader ( shader_program, std::get<1> ( vertex_result ) );
  bool fcr = frag_shader.link_shader ( shader_program, std::get<1> ( frag_result ) );

  if ( !vcr || !fcr )
    {
      glfwTerminate ();
      return;
    }

  // Define vertices for a triangle
  GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f, // bottom-left
    0.5f,
    -0.5f,
    0.0f, // bottom-right
    0.0f,
    0.5f,
    0.0f // top-center
  };

  // Create and bind a vertex array object (VAO)
  GLuint VAO, VBO;
  glGenVertexArrays ( 1, &VAO );
  glGenBuffers ( 1, &VBO );
  glBindVertexArray ( VAO );

  // Bind vertex buffer object (VBO) and copy vertex data into it
  glBindBuffer ( GL_ARRAY_BUFFER, VBO );
  glBufferData ( GL_ARRAY_BUFFER, sizeof ( vertices ), vertices, GL_STATIC_DRAW );

  // Set vertex attribute pointers
  glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof ( GLfloat ), ( GLvoid * )0 );
  glEnableVertexAttribArray ( 0 );

  // Unbind VAO (optional)
  glBindVertexArray ( 0 );

  while ( !glfwWindowShouldClose ( m_Handle ) )
    {
      // Process events
      glfwPollEvents ();

      // Clear the color buffer
      glClearColor ( 0.2f, 0.3f, 0.3f, 1.0f );
      glClear ( GL_COLOR_BUFFER_BIT );

      // Use shader program
      glUseProgram ( shader_program );
      // Draw triangle
      glBindVertexArray ( VAO );
      glDrawArrays ( GL_TRIANGLES, 0, 3 );
      glBindVertexArray ( 0 );

      // Swap the screen buffers
      glfwSwapBuffers ( m_Handle );
    }

  // Cleanup
  glDeleteVertexArrays ( 1, &VAO );
  glDeleteBuffers ( 1, &VBO );
  ShaderSystem::destroy_shader_pid ( shader_program );

  // Terminate GLFW
  glfwTerminate ();
}

void
OpenGLContext::close_context ()
{
  spdlog::info ( "Terminating OpenGL Grpahics Context" );
}

void
OpenGLContext::swap_buffers ()
{
  glfwSwapBuffers ( this->m_Handle );
}

void
OpenGLContext::render ()
{
  glClear ( GL_COLOR_BUFFER_BIT );
  glBindVertexArray ( 0 );
}

void
OpenGLContext::stop_renderer ()
{
}

}