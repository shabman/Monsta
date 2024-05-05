#include "Monsta/Events/Input/InputAdapter.h"

namespace Monsta
{

    std::vector<InputListener*> InputAdapter::s_Events;

    void InputAdapter::InputKeycallBack(GLFWwindow* window, int key, int scancode, int action, int mods) noexcept
    {
        dispatch_event(InputEventType::INPUT_KEY_CALLBACK, key, action);
    }

    void InputAdapter::InputMousePositionCallback(GLFWwindow*, double x, double y) noexcept
    {
        dispatch_event(InputEventType::INPUT_MOUSE_POS_CALLBACK, x, y);
    }

    // TODO: Implement more events

    void InputAdapter::add_listener(const InputListener* listener_class) noexcept
    {
        if (!has_listener(listener_class))
            s_Events.push_back(const_cast<InputListener*>(listener_class));
    }

    void InputAdapter::remove_listener(const InputListener* listener_class) noexcept
    {
        if (has_listener(listener_class))
            s_Events.erase(std::find(s_Events.begin(), s_Events.end(), listener_class));
    }

    bool InputAdapter::has_listener(const int& index) noexcept
    {
        if (index < s_Events.size())
            return false;
        return s_Events[index] != nullptr;
    }

    bool InputAdapter::has_listener(const InputListener* listener_class) noexcept
    {
        return std::find(s_Events.begin(), s_Events.end(), listener_class) != s_Events.end();
    }

    const InputListener* InputAdapter::get_listener(const int& index) noexcept
    {
        if (index < s_Events.size())
            return s_Events[index];
        return nullptr;
    }

    template<typename...Args>
    void InputAdapter::dispatch_event(const InputEventType& event_type, Args...v) noexcept
    {
        for (auto& input_class : s_Events)
        {
            input_class->onInputEvent(event_type, v...);
        }
    }

}