#ifndef MONITOR_CPP
#define MONITOR_CPP

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

#endif