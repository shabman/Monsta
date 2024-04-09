#ifndef __LIBMONSTA_EVENTS_WINDOWLISTENER_H__
#define __LIBMONSTA_EVENTS_WINDOWLISTENER_H__

namespace Monsta
{

    enum class WindowEventType
    {
        WINDOW_EVENT_INIT,
        WINDOW_EVENT_FOCUS_LOST,
        WINDOW_EVENT_FOCUS_GAIN,
        WINDOW_EVENT_DESTROY,
        WINDOW_EVENT_RESIZE
    };

    class WindowListener
    {
    
    public:
        WindowListener();
        virtual ~WindowListener() = 0;

    public:
        virtual void onWindowEvent(const WindowEventType&) noexcept = 0;

    };

}

#endif /* __LIBMONSTA_EVENTS_WINDOWLISTENER_H__ */