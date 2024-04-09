#include "Monsta/Events/WindowAdapter.h"

namespace Monsta
{

    namespace Events
    {
        void on_window_event()
        {
            auto x = WindowAdapter::s_Events;
        }
    }

    std::vector<WindowListener*> WindowAdapter::s_Events;

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