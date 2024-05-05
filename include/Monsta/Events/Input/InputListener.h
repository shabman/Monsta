#ifndef __LIBMONSTA_EVENTS_INPUT_INPUTLISTENER_H__
#define __LIBMONSTA_EVENTS_INPUT_INPUTLISTENER_H__

namespace Monsta
{

    enum class InputEventType
    {
        INPUT_KEY_CALLBACK,
        INPUT_MOUSE_POS_CALLBACK
    };

    class InputListener
    {

    public:
        InputListener();
        virtual ~InputListener() = 0;

    public:
        virtual void onInputEvent(const InputEventType&, ...) noexcept = 0;

    };

}

#endif /* __LIBMONSTA_EVENTS_INPUT_INPUTLISTENER_H__ */