#include "Window_mgr.h"

void Window_mgr::clear(ScreenIndex i)
{
    auto &s=*screens[i];

    //create an empty screen
    s=Screen(s.height,s.width,'-');
}

void Window_mgr::addScreen(Screen &s)
{
    //add new screen to the vector
    screens.push_back(&s);
}
