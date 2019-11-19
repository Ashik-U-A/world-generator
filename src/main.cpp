#include <iostream>
#include "window.h"
#include "monitor.h"

using namespace std;

Monitor *monitors;
Window *primary_window;

void prepareMainWindow()
{
    monitors = Monitor::get_all_connected_monitors();
    *primary_window = Window(monitors + 1, "Main Window | World Generator");
}

void cleanup()
{
    cout << "Freeing up Resources" << endl;
    free(monitors);
}

int main()
{
    cout << "Starting World Generator 1.0" << endl;
    prepareMainWindow();

    cleanup();
    return 0;
}