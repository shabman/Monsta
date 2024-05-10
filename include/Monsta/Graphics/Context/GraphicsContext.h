//
// Created by Mustafa Malik on 07/05/2024.
//

#ifndef __LIBMONSTA_GRAPHICS_CONTEXT_GRAPHICSCONTEXT_H__
#define __LIBMONSTA_GRAPHICS_CONTEXT_GRAPHICSCONTEXT_H__

namespace Monsta::Context
{

    enum class GraphicsContextMode
    {
        MONSTA_OPENGL_GRAPHICS,
        MONSTA_METAL_API_GRAPHICS,
        MONSTA_UNKNOWN_GRAPHICS
    };

    class GraphicsContext
    {
    public:
        GraphicsContext() = default;
        virtual ~GraphicsContext() = 0;

    public:
        virtual void init_context() = 0;
        virtual void close_context() = 0;
        virtual void swap_buffers() = 0;

    public:
        virtual void start_renderer() = 0;
        virtual void stop_renderer() = 0;
    };
}

#endif /* __LIBMONSTA_GRAPHICS_CONTEXT_GRAPHICSCONTEXT_H__ */
