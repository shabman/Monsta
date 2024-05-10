//
// Created by Mustafa Malik on 05/05/2024.
//

#ifndef __LIBMONSTA_GRAPHICS_RENDERER_GAMEOBJECT_H__
#define __LIBMONSTA_GRAPHICS_RENDERER_GAMEOBJECT_H__

namespace Monsta::Renderer
{

    class GameObject
    {
    private:
        unsigned int m_Id;
    public:
        GameObject();
        virtual ~GameObject() = 0;

    public:
        const unsigned int get_id() const noexcept;

    public:
        void on_start() noexcept;
        void on_pause() noexcept;
        void on_update(float&) noexcept;
        void on_close() noexcept;
    };

}

#endif /* __LIBMONSTA_GRAPHICS_RENDERER_GAMEOBJECT_H__ */
