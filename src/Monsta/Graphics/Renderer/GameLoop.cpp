//
// Created by Mustafa Malik on 05/05/2024.
//

#include "GL/glew.h"
#include "Monsta/Graphics/Renderer/GameLoop.h"
#include "spdlog/spdlog.h"

static Monsta::Renderer::GameLoop* __render_loop = nullptr;

namespace Monsta::Renderer
{

    GameLoop::GameLoop(const Context::GraphicsContext* context)
        : m_VertexBuffer(0), m_VertexArray(0), m_IndexBuffer(0)
    {
        this->m_Context = const_cast<Context::GraphicsContext*>(context);
    }

    GameLoop* GameLoop::get_instance(const Context::GraphicsContext* ctx)
    {
        if (__render_loop == nullptr)
        {
            spdlog::info("Initialising Main Game Loop");
            __render_loop = new GameLoop(ctx);
        }
        return __render_loop;
    }

    void GameLoop::has_object(const GameObject*)
    {

    }

    void GameLoop::add_object(const GameObject*)
    {

    }

    void GameLoop::remove_object(const GameObject*)
    {

    }

    void GameLoop::start(GLFWwindow* window)
    {
        // TODO: Refactor later
        glGenVertexArrays(1, &this->m_VertexArray);
        glBindVertexArray(this->m_VertexArray);

        glGenBuffers(1, &this->m_VertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, this->m_VertexBuffer);

        constexpr float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };

        // upload to gpu, GL_ARRAY_BUFFER basically means vertex buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0); // activate our buffer

        // stride: bytes between vertices (3 values float)
        // vertex attr for the shader location 0, index 0
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

        glGenBuffers(1, &this->m_IndexBuffer);
        // buffer of indices, index into our vertex buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndexBuffer);

        unsigned int indices[3] = { 0, 1, 2 };
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        spdlog::info("Started Main Game Loop");
        while (!glfwWindowShouldClose(window))
        {
            //glClearColor(0.23, 0.23, 0.23, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            glBindVertexArray(this->m_VertexArray);
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr); // no specific indices index buffer

            this->m_Context->swap_buffers();
            glfwPollEvents();
        }
        cleanup();
    }

    void GameLoop::cleanup()
    {
        if (__render_loop != nullptr)
        {
            delete __render_loop;
            spdlog::info("Main Game Loop Terminated");
        }
    }

    void GameLoop::set_context(Context::GraphicsContext* context)
    {
        this->m_Context = context;
    }

}