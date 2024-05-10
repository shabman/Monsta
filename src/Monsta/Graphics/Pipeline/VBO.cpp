//
// Created by Mustafa Malik on 06/05/2024.
//

#include <GL/glew.h>
#include "Monsta/Graphics/Pipeline/VBO.h"

static Monsta::Pipline::VBO* __instance = nullptr;

namespace Monsta::Pipline
{

    VBO::VBO(const BindMode& mode) : m_Vbo(0)
    {
        glGenBuffers(1, &this->m_Vbo);
        switch (mode)
        {
            case BindMode::ENGINE_VERTEX_BUFFER:
            {
                glBindBuffer(GL_ARRAY_BUFFER, this->m_Vbo);
                break;
            }
            case BindMode::ENGINE_ELEMENT_BUFFER:
            {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_Vbo);
                break;
            }
        }
    }

    VBO* VBO::get_instance(const BindMode& mode) noexcept
    {
        if (__instance == nullptr)
        {
            __instance = new VBO(mode);
        }
        return __instance;
    }

    void VBO::close() noexcept {
        if (__instance != nullptr)
        {
            delete __instance;
        }
    }

    void VBO::loop_bind() const noexcept {

    }

    [[nodiscard]] const unsigned int VBO::get_vbo() const noexcept {
        return this->m_Vbo;
    }
}