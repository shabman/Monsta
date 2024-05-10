//
// Created by Mustafa Malik on 07/05/2024.
//

#include "Monsta/Engine.h"
#include "spdlog/spdlog.h"

static Monsta::Engine* __engine = nullptr;

namespace Monsta
{

    Engine::Engine()
    {
        this->m_Window = MWindow::get_instance();
        this->m_MainLoop = Renderer::GameLoop::get_instance(this->m_Window->get_context());
    }

    Engine::~Engine()
    {
        this->m_Window->deinit_window();
        spdlog::info("De-allocated window!");
    }


    Engine *Engine::GetInstance() noexcept
    {
        if (__engine == nullptr)
        {
            __engine = new Engine;
        }
        return __engine;
    }

    void Engine::Start() noexcept
    {
        this->m_Window->init_window(900, 500, "Monsta Game Engine Demo");
        this->m_MainLoop->set_context(this->m_Window->get_context());
        this->m_MainLoop->start(this->m_Window->get_glfw_window());
    }

    void Engine::Stop() noexcept
    {
        if (__engine != nullptr)
        {
            delete __engine;
        }
    }

}
