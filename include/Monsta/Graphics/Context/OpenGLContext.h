//
// Created by Mustafa Malik on 07/05/2024.
//

#ifndef __LIBMONSTA_GRAPHICS_CONTEXT_OPENGLCONTEXT_H__
#define __LIBMONSTA_GRAPHICS_CONTEXT_OPENGLCONTEXT_H__

#include "GraphicsContext.h"

struct GLFWwindow;

namespace Monsta::Context
{
    class OpenGLContext final : public GraphicsContext
    {
    private:
        GLFWwindow* m_Handle;
    public:
        explicit OpenGLContext(GLFWwindow* handle);
        ~OpenGLContext() override;

    public:
        OpenGLContext(OpenGLContext&) = delete;
        OpenGLContext(OpenGLContext&&) = delete;

        OpenGLContext& operator = (OpenGLContext&) = delete;
        OpenGLContext& operator = (OpenGLContext&&) = delete;

    private:
        void init_context() override;
        void close_context() override;
        void swap_buffers() override;

    public:
        void render() override;
        void stop_renderer() override;
    };
}

#endif /* __LIBMONSTA_GRAPHICS_CONTEXT_OPENGLCONTEXT_H__ */
