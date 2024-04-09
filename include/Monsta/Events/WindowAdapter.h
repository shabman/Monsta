#ifndef __LIBMONSTA_EVENTS_WINDOWADAPTER_H__
#define __LIBMONSTA_EVENTS_WINDOWADAPTER_H__

#include "WindowListener.h"

#include <vector>

namespace Monsta
{

    class WindowAdapter final
    {

    private:
        static std::vector<WindowListener*> s_Events;

    private:
        WindowAdapter()     = delete;
        ~WindowAdapter()    = delete;

    private:
        static bool already_exists(const WindowListener*) noexcept;

    public:
        static void add_listener(const WindowListener*) noexcept;
        static void remove_listener(const WindowListener*) noexcept;
        static bool has_listener(const int&) noexcept;
        static const WindowListener* get_listener(const int&) noexcept;

    };

}

#endif /* __LIBMONSTA_EVENTS_WINDOWADAPTER_H__ */