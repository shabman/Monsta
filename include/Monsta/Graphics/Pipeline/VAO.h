//
// Created by Mustafa Malik on 05/05/2024.
//

#ifndef __LIBMONSTA_GRAPHICS_PIPELINE_VERTEXBUFFERS_H__
#define __LIBMONSTA_GRAPHICS_PIPELINE_VERTEXBUFFERS_H__

namespace Monsta::Pipeline
{
    class VAO
    {
    private:
        unsigned int m_Vao;

    public:
        VAO();
        ~VAO() = default;

    public:
        static VAO* get_instance() noexcept;
        void close() noexcept;
        void loop_bind() const noexcept;
        [[nodiscard]] const unsigned int get_vao() const noexcept;
    };
}

#endif /* __LIBMONSTA_GRAPHICS_PIPELINE_VERTEXBUFFERS_H__ */
