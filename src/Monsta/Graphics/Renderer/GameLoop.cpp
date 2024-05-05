//
// Created by Mustafa Malik on 05/05/2024.
//

#include "Monsta/Graphics/Renderer/GameLoop.h"
#include "spdlog/spdlog.h"

static Monsta::Renderer::GameLoop* __render_loop = nullptr;

namespace Monsta::Renderer
{

    GameLoop* GameLoop::get_instance()
    {
        if (__render_loop == nullptr)
        {
            spdlog::info("Initialising Main Game Loop");
            __render_loop = new GameLoop;
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
        spdlog::info("Started Main Game Loop");
        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
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



}