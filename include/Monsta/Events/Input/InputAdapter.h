#ifndef __LIBMONSTA_EVENTS_INPUT_INPUTADAPTER_H__
#define __LIBMONSTA_EVENTS_INPUT_INPUTADAPTER_H__

#include <vector>
#include <GLFW/glfw3.h>

#include "InputListener.h"

namespace Monsta
{

    class InputAdapter final
    {
        
    private:
        static std::vector<InputListener*> s_Events;

    public:
        InputAdapter()  = delete;
        ~InputAdapter() = delete;

    public:
        static void InputKeycallBack(GLFWwindow*, int, int, int , int) noexcept;
        static void InputMousePositionCallback(GLFWwindow*, double, double) noexcept;

    public:
        static void add_listener(const InputListener*) noexcept;
        static void remove_listener(const InputListener*) noexcept;
        static bool has_listener(const int&) noexcept;
        static bool has_listener(const InputListener*) noexcept;
        static const InputListener* get_listener(const int&) noexcept;

        template<typename...Args>
        static void dispatch_event(const InputEventType&, Args...) noexcept;

    };

}

#endif /* __LIBMONSTA_EVENTS_INPUT_INPUTADAPTER_H__ */