#ifndef __LIBMONSTA_WINDOW_MWINDOW_H__
#define __LIBMONSTA_WINDOW_MWINDOW_H__

#include <GLFW/glfw3.h>

namespace Monsta
{

    class MWindow final
    {
    
    private:
        GLFWwindow* m_Window;
        int m_Width;
        int m_Height;
        const char* m_Title;
        bool did_init;

    private:
        MWindow();
        ~MWindow();

    public:
        static MWindow* get_instance() noexcept;
        bool init_window(int&&, int&&, const char*) noexcept;
        void deinit_window() noexcept;

    public:
        GLFWwindow* get_glfw_window() const noexcept;
        const int get_width() const noexcept;
        const int get_height() const noexcept;
        const char* get_title() const noexcept;

    };

}

#endif /* __LIBMONSTA_WINDOW_MWINDOW_H__ */