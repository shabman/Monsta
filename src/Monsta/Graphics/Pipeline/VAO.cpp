//
// Created by Mustafa Malik on 06/05/2024.
//

#include "Monsta/Graphics/Pipeline/VAO.h"

#include "GL/glew.h"

static Monsta::Pipeline::VAO* __instance = nullptr;

namespace Monsta::Pipeline
{

    VAO::VAO() : m_Vao(0)
    {
        glGenVertexArrays(1, &this->m_Vao);
        this->loop_bind();
    }


    VAO* VAO::get_instance() noexcept
    {
        if (__instance == nullptr)
        {
            __instance = new VAO;
        }
        return __instance;
    }

    void VAO::loop_bind() const noexcept
    {
        // Call in the game loop only
        glBindVertexArray(this->m_Vao);
    }

    [[nodiscard]] const unsigned int VAO::get_vao() const noexcept
    {
        return this->m_Vao;
    }

    void VAO::close() noexcept
    {
        if (__instance != nullptr)
        {
            delete __instance;
        }
    }
}
