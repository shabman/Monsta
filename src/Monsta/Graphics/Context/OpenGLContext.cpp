//
// Created by Mustafa Malik on 07/05/2024.
//

#include <GLFW/glfw3.h>
#include "Monsta/Graphics/Context/OpenGLContext.h"
#include "spdlog/spdlog.h"

namespace Monsta::Context
{
    const char* vertex_shader = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

    const char* frag_shader = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )";

    OpenGLContext::OpenGLContext(GLFWwindow* handle) : m_Handle(handle)
    {
        this->init_context();
    }

    OpenGLContext::~OpenGLContext()
    {
        this->close_context();
    }

    void OpenGLContext::init_context()
    {
        spdlog::info("Initialising OpenGL Grpahics Context");
        glfwMakeContextCurrent(this->m_Handle);
    }

    void OpenGLContext::close_context()
    {
        spdlog::info("Terminating OpenGL Grpahics Context");
    }

    void OpenGLContext::swap_buffers()
    {
        glfwSwapBuffers(this->m_Handle);
    }

    void OpenGLContext::start_renderer()
    {

    }

    void OpenGLContext::stop_renderer()
    {

    }

}