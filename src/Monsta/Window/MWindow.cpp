#include "Monsta/Window/MWindow.h"

#include "Monsta/Events/Input/InputAdapter.h"
#include "Monsta/Platform/Platform.h"
#include "Monsta/Platform/Version.h"
#include "Monsta/Events/Window/WindowAdapter.h"

Monsta::MWindow* __mwindow = nullptr;

namespace Monsta
{

    MWindow::MWindow()
    {
        this->did_init = glfwInit();
    }
    
    MWindow::~MWindow()
    {
        glfwTerminate(); 
    }

    MWindow* MWindow::get_instance() noexcept
    {
        if (__mwindow == nullptr)
        {
            __mwindow = new MWindow;
        }
        return __mwindow;
    }

    bool MWindow::init_window(int&& width, int&& height, const char* title) noexcept
    {
        if (!this->did_init)
            return false;

        this->m_Width = width;
        this->m_Height = height;
        this->m_Title = title;

        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GL_TRUE);
        glfwWindowHint(GLFW_SCALE_FRAMEBUFFER, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        glfwWindowHint(GLFW_FLOATING, GL_FALSE);

#ifdef MONSTA_PLAT_MAC
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, LIB_MONSTA_OPENGL_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, LIB_MONSTA_OPENGL_MINOR);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#endif

        this->m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!this->m_Window)
        {
            glfwTerminate();
            return false;
        }

        glfwSetWindowFocusCallback(this->m_Window, WindowAdapter::RegisterWindowFocusEvent);
        glfwSetKeyCallback(this->m_Window, InputAdapter::InputKeycallBack);
        glfwSetCursorPosCallback(this->m_Window, InputAdapter::InputMousePositionCallback);

        glfwMakeContextCurrent(this->m_Window);
        glViewport(0, 0, width, height);

        return true;
    }

    void MWindow::deinit_window() noexcept
    {
        if (__mwindow != nullptr)
        {
            delete __mwindow;
        }
    }

    GLFWwindow* MWindow::get_glfw_window() const noexcept
    {
        return this->m_Window;
    }

    const int MWindow::get_width() const noexcept
    {
        return this->m_Width;
    }

    const int MWindow::get_height() const noexcept
    {
        return this->m_Height;
    }

    const char* MWindow::get_title() const noexcept
    {
        return this->m_Title;
    }

}