//
// Created by Mustafa Malik on 05/05/2024.
//

#ifndef __LIBMONTSA_GRAPHICS_RENDERER_GAMELOOP_H__
#define __LIBMONTSA_GRAPHICS_RENDERER_GAMELOOP_H__

#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <vector>

namespace Monsta::Renderer
{
    class GameLoop
    {
    private:
        std::vector<GameObject*> s_WorldObjects;
    private:
        GameLoop() = default;
        ~GameLoop() = default;
    public:
        static GameLoop* get_instance();

        void has_object(const GameObject*);
        void add_object(const GameObject*);
        void remove_object(const GameObject*);

        void start(GLFWwindow*);
        void cleanup();
    };
}

#endif /* __LIBMONTSA_GRAPHICS_RENDERER_GAMELOOP_H__ */
