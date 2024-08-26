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
#include "Monsta/Renderer/Pipeline/ElementBuffer.h"
#include "Monsta/Renderer/Pipeline/Shader.h"
#include "Monsta/Renderer/Pipeline/VertexBuffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GLFW/glfw3.h>

#include <GL/glew.h>
#include <memory>
#include <spdlog/spdlog.h>

namespace Monsta::Renderer
{

// clang-format off
constexpr float square[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left
};
// clang-format on

constexpr int indices[] = { 0, 1, 3, 1, 2, 3 };

const char* vertexShaderSource = "#version 410 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "uniform mat4 u_transform;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = u_transform * vec4(aPos, 1.0);\n"
                                 "}\0";

const char* fragShaderSource = "#version 410 core\n"
                               "out vec4 FragColor;\n"
                               "void main()\n"
                               "{\n"
                               "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                               "}\n";

VertexBuffer vbo;
ElementBuffer ebo;
Shader shader;

int location;
glm::mat4 transform = glm::mat4 ( 1.0f ); // identity matrix (base matrix for transformations);

OpenGLRenderer::OpenGLRenderer ()
    : m_vertices ( 0 )
{
  spdlog::info ( "[MONSTA]: Allocated OpenGL Renderer" );
}

OpenGLRenderer::~OpenGLRenderer ()
{
  m_vertexArray.destroy ();
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
  m_vertexArray.create ();
  m_vertexArray.bind ();

  vbo.create ();
  vbo.bind ();

  ebo.create ();
  ebo.bind ();

  vbo.bufferData ( sizeof ( square ), square, BufferMode::BUFFER_STATIC );
  vbo.setAttribute ( 0, 3, GL_FLOAT, sizeof ( float ) * 3, ( void* )0, 0 );

  ebo.bufferData ( sizeof ( indices ), indices, BufferMode::BUFFER_STATIC );

  ShaderResult result = shader.compileShader ( vertexShaderSource, fragShaderSource );

  transform = glm::translate(transform, glm::vec3(-0.5f, 0.5f, 0.0f));
  //transform = glm::rotate ( transform, glm::radians ( 20.0f ), glm::vec3 ( 0.0f, 0.0f, 1.0f ) );
  location = result.programId;
}

void
OpenGLRenderer::run () noexcept
{
  m_vertexArray.bind ();

  glClear ( GL_COLOR_BUFFER_BIT );
  glClearColor ( 1.0, 1.0, 0.0, 1.0 );

  shader.select ();

  int r = glGetUniformLocation ( location, "u_transform" );
  glUniformMatrix4fv ( r, 1, GL_FALSE, glm::value_ptr ( transform ) );

  glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
  shader.deselect ();
}

void
OpenGLRenderer::release () noexcept
{
  vbo.destroy ();
  ebo.destroy ();
  m_vertexArray.destroy ();
}

}
