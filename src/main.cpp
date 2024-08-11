#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"
#include <cstdarg>
#include <iostream>

#include "Monsta/Engine.h"
#include "Monsta/Graphics/Shaders/ShaderSystem.h"
#include "Monsta/Platform/Version.h"

using namespace Monsta;

int
main ()
{

  std::cout << "Hello Monsta Engine!\n";

  return 0;
}

// Define vertex shader source code
// const char* vertexShaderSource = R"(
//     #version 330 core
//     layout (location = 0) in vec3 aPos;
//     void main() {
//         gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
//     }
// )";
//
// // Define fragment shader source code
// const char* fragmentShaderSource = R"(
//     #version 330 core
//     out vec4 FragColor;
//     void main() {
//         FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
//     }
// )";

// Main function
// int main() {
// Initialize GLFW
// if (!glfwInit()) {
//     std::cerr << "Failed to initialize GLFW" << std::endl;
//     return -1;
// }
//
// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, LIB_MONSTA_OPENGL_MAJOR);
// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, LIB_MONSTA_OPENGL_MINOR);
// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
// // Create a GLFW window and OpenGL context
// GLFWwindow* window = glfwCreateWindow(800, 600, "Monsta", nullptr, nullptr);
// if (!window) {
//     std::cerr << "Failed to create GLFW window" << std::endl;
//     glfwTerminate();
//     return -1;
// }
// glfwMakeContextCurrent(window);
//
// // Initialize GLEW
// if (glewInit() != GLEW_OK) {
//     std::cerr << "Failed to initialize GLEW" << std::endl;
//     glfwTerminate();
//     return -1;
// }

// ShaderSystem vertex_shader(vertexShaderSource);
// ShaderSystem frag_shader(fragmentShaderSource);
// GLuint shader_program = ShaderSystem::get_shader_pid();
//
// auto vertex_result = vertex_shader.compile_shader(ShaderType::MONSTA_VERTEX_SHADER);
// auto frag_result = frag_shader.compile_shader(ShaderType::MONSTA_FRAGMENT_SHADER);
//
// if (!std::get<0>(vertex_result) || !std::get<0>(frag_result)) {
//     glfwTerminate();
//     return -1;
// }
//
// bool vcr = vertex_shader.link_shader(shader_program, std::get<1>(vertex_result));
// bool fcr = frag_shader.link_shader(shader_program, std::get<1>(frag_result));
//
// if (!vcr || !fcr) {
//     glfwTerminate();
//     return -1;
// }
//
// // Define vertices for a triangle
// GLfloat vertices[] = {
//     -0.5f, -0.5f, 0.0f, // bottom-left
//      0.5f, -0.5f, 0.0f, // bottom-right
//      0.0f,  0.5f, 0.0f  // top-center
// };
//
// // Create and bind a vertex array object (VAO)
// GLuint VAO, VBO;
// glGenVertexArrays(1, &VAO);
// glGenBuffers(1, &VBO);
// glBindVertexArray(VAO);
//
// // Bind vertex buffer object (VBO) and copy vertex data into it
// glBindBuffer(GL_ARRAY_BUFFER, VBO);
// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
// // Set vertex attribute pointers
// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
// glEnableVertexAttribArray(0);
//
// // Unbind VAO (optional)
// glBindVertexArray(0);

// Render loop
// while (!glfwWindowShouldClose(window)) {
//     // Process events
//     glfwPollEvents();
//
//     // Clear the color buffer
//     glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//     glClear(GL_COLOR_BUFFER_BIT);
//
//     // Use shader program
//     glUseProgram(shader_program);
//     // Draw triangle
//     glBindVertexArray(VAO);
//     glDrawArrays(GL_TRIANGLES, 0, 3);
//     glBindVertexArray(0);
//
//     // Swap the screen buffers
//     glfwSwapBuffers(window);
// }
//
// // Cleanup
// glDeleteVertexArrays(1, &VAO);
// glDeleteBuffers(1, &VBO);
// ShaderSystem::destroy_shader_pid(shader_program);
//
// // Terminate GLFW
// glfwTerminate();
// return 0;
//}
