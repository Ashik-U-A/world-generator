#include <GLFW/glfw3.h>
#include <iostream>

class Monitor
{
private:
    int width, height, offset_x, offset_y;
    GLFWmonitor *instance;
    Monitor(GLFWmonitor *monitor);

public:
    Monitor(){};
    int get_width();
    int get_height();
    int get_offset_x();
    int get_offset_y();
    GLFWmonitor *get_instance();
    static Monitor *get_all_connected_monitors();
};

/**
 * Static Member Definitions
*/
static Monitor *connected_monitor_list;

/**
 * Implementation of all the Functions
 */

Monitor::Monitor(GLFWmonitor *monitor)
{
    glfwGetMonitorWorkarea(monitor, &offset_x, &offset_y, &width, &height);
    instance = monitor;
    std::cout << "Monitor Width : " << width << " and Monitor Height : " << height << ". Monitor Offset : " << offset_x << " x " << offset_y << std::endl;
}

Monitor *Monitor::get_all_connected_monitors()
{
    if (!glfwInit())
    {
        return NULL;
    }
    else
    {
        int count;
        free(connected_monitor_list);
        GLFWmonitor **connected_monitors = glfwGetMonitors(&count);

        connected_monitor_list = (Monitor *)malloc(count);
        for (int i = 0; i < count; i++)
        {
            Monitor m = Monitor(connected_monitors[i]);
            (connected_monitor_list)[i] = m;
        }
        return connected_monitor_list;
    }
};

/**
 * Member Functions
 */
int Monitor::get_width()
{
    return width;
}

int Monitor::get_height()
{
    return height;
}

int Monitor::get_offset_x()
{
    return offset_x;
}

int Monitor::get_offset_y()
{
    return offset_y;
}

GLFWmonitor *Monitor::get_instance()
{
    return instance;
}
