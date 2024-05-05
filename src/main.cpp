#include "Monsta/Window/MWindow.h"
#include "Monsta/Events/Input/InputListener.h"
#include "Monsta/Events/Input/InputAdapter.h"
#include "Monsta/Graphics/Renderer/GameLoop.h"

#include <cstdarg>
#include <iostream>
#include "spdlog/spdlog.h"

using namespace Monsta;

// FIXME: Shit gets called twice
class TestInput : public InputListener {

public:
    TestInput() = default;
    ~TestInput() override { }

public:
    void onInputEvent(const InputEventType& event, ...) noexcept override {
        va_list args;
        if (event == InputEventType::INPUT_KEY_CALLBACK) {
            va_start(args, 2);
            int key = va_arg(args, int);
            int action = va_arg(args, int);
            if (action == GLFW_RELEASE) return;
            std::cout << "Key callback triggered!\n";
            if (key == GLFW_KEY_SPACE)
                std::cout << "Space bar pressed!\n";
        }
        va_end(args);
    }

};

int main()
{

    const TestInput input;

    MWindow* window = MWindow::get_instance();
    InputAdapter::add_listener(&input);

    if (window == nullptr)
    {
        printf("%s\n", "Window is null!");
        return 1;
    }

    window->init_window(900, 500, "Monsta Game Engine Demo");

    Renderer::GameLoop* main_loop = Renderer::GameLoop::get_instance();
    main_loop->start(window->get_glfw_window());

    window->deinit_window();
    spdlog::info("De-allocated window!");

    return 0;

}