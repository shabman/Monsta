//
// Created by Mustafa Malik on 05/05/2024.
//

#ifndef __LIBMONTSA_GRAPHICS_RENDERER_GAMELOOP_H__
#define __LIBMONTSA_GRAPHICS_RENDERER_GAMELOOP_H__

#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <vector>

#include "Monsta/Graphics/Context/GraphicsContext.h"

namespace Monsta::Renderer
{
    class GameLoop final
    {
    private:
        std::vector<GameObject*> m_WorldObjects;
        Context::GraphicsContext* m_Context;
        unsigned int m_VertexBuffer, m_VertexArray, m_IndexBuffer;
    private:
        GameLoop(const Context::GraphicsContext*);
        ~GameLoop() = default;
    public:
        static GameLoop* get_instance(const Context::GraphicsContext*);

        void has_object(const GameObject*);
        void add_object(const GameObject*);
        void remove_object(const GameObject*);

        void start(GLFWwindow*);
        void cleanup();

        void set_context(Context::GraphicsContext*);
    };
}

#endif /* __LIBMONTSA_GRAPHICS_RENDERER_GAMELOOP_H__ */
