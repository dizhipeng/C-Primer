#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr
{
    public:
        using ScreenIndex=std::vector<Screen>::size_type;
        void clear(ScreenIndex i);
    
    private:
        //manage a group of screens
        std::vector<Screen> screens;
};
#endif

