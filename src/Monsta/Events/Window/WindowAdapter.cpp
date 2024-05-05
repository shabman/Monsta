#include "Monsta/Events/Window/WindowAdapter.h"
#include "spdlog/spdlog.h"

namespace Monsta
{

    std::vector<WindowListener*> WindowAdapter::s_Events;

    void WindowAdapter::RegisterWindowFocusEvent(GLFWwindow* window, int isFocused) noexcept
    {
        spdlog::info("Window Call back called!");
        for (const auto& event : s_Events)
        {
            event->onWindowEvent( 
                ( isFocused ? WindowEventType::WINDOW_EVENT_FOCUS_GAIN : WindowEventType::WINDOW_EVENT_FOCUS_LOST )
            );
        }
    }

    bool WindowAdapter::already_exists(const WindowListener* listener) noexcept
    {
        return std::find(s_Events.begin(), s_Events.end(), listener) != s_Events.end();
    }

    void WindowAdapter::add_listener(const WindowListener* listener) noexcept
    {
        if (!already_exists(listener))
            s_Events.push_back(const_cast<WindowListener*>(listener));
    }

    void WindowAdapter::remove_listener(const WindowListener* listener) noexcept
    {
        if (already_exists(listener))
            s_Events.erase(std::find(s_Events.begin(), s_Events.end(), listener));
    }

    bool WindowAdapter::has_listener(const int& index) noexcept
    {
        if (index > s_Events.size())
            return false;
        return s_Events[index] != nullptr;
    }

    const WindowListener* WindowAdapter::get_listener(const int& index) noexcept
    {
        if (index > s_Events.size())
            return nullptr;
        return s_Events[index];
    }

}