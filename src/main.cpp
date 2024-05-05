#include "Monsta/Window/MWindow.h"
#include <stdio.h>

using namespace Monsta;

int main(void)
{

    MWindow* window = MWindow::get_instance();
    if (window == nullptr)
    {
        printf("%s\n", "Window is null!");
        return 1;
    }

    window->init_window(900, 500, "Monsta Game Engine Demo");

    while (!glfwWindowShouldClose(window->get_glfw_window()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window->get_glfw_window());
        glfwPollEvents();
    }

    window->deinit_window();
    printf("%s\n", "De-allocated window!");

    return 0;

}