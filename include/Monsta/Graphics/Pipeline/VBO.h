//
// Created by Mustafa Malik on 06/05/2024.
//

#ifndef __LIBMONSTA_GRAPHICS_PIPLINE_VBO_H__
#define __LIBMONSTA_GRAPHICS_PIPLINE_VBO_H__

namespace Monsta::Pipline
{

    enum class BindMode
    {
        ENGINE_VERTEX_BUFFER,
        ENGINE_ELEMENT_BUFFER
    };

    class VBO
    {
    private:
        unsigned int m_Vbo;
    private:
        VBO(const BindMode&);
        ~VBO() = default;
    public:
        static VBO* get_instance(const BindMode&) noexcept;
        void close() noexcept;
        void loop_bind() const noexcept;
        [[nodiscard]] const unsigned int get_vbo() const noexcept;
    };
}

#endif /* __LIBMONSTA_GRAPHICS_PIPLINE_VBO_H__ */
