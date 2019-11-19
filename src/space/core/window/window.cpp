#include <GLFW/glfw3.h>
#include "monitor.h"
#include <iostream>

class Window
{
private:
    GLFWwindow *instance;

public:
    Window(Monitor *monitor, std::string title);
};

/**
 * The Callback Function for Errors
 */
static void error_callback(int error, const char *description)
{
    std::cout << "Error : " << error << std::endl;
    std::cout << description << std::endl;
}

Window::Window(Monitor *monitor, std::string title)
{
    if (glfwInit())
    {
        instance = glfwCreateWindow(
            (*monitor).get_width(),
            (*monitor).get_height(),
            title.c_str(),
            (*monitor).get_instance(),
            NULL);
    }

    if (!instance)
    {
        glfwTerminate();
    }
    else
    {
        glfwSetErrorCallback(error_callback);
        glfwMakeContextCurrent(instance);
        glfwSwapInterval(1);
        while (!glfwWindowShouldClose(instance))
        {

            glfwPollEvents();
        }
        glfwTerminate();
    }
}