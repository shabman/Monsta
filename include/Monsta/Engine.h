//
// Created by Mustafa Malik on 07/05/2024.
//

#ifndef __LIBMONSTA_ENGINE_H__
#define __LIBMONSTA_ENGINE_H__

#include "Monsta/Window/MWindow.h"
#include "Monsta/Graphics/Renderer/GameLoop.h"

namespace Monsta
{
    class Engine final
    {
    private:
        MWindow* m_Window;
        Renderer::GameLoop* m_MainLoop;
    private:
        Engine();
        ~Engine();
    public:
        static Engine* GetInstance() noexcept;
        void Start() noexcept;
        void Stop() noexcept;
    };
}

#endif /* __LIBMONSTA_ENGINE_H__ */
