#include <iostream>
#include "Screen.h"

using std::ostream;
//{ content[cursor]=c; return *this; }

const Screen& Screen::display(ostream& out_stream) const
{
    out_stream<<content;
    return *this;
}

Screen& Screen::display(ostream& out_stream)
{
    //type deduction with this pointer doesn't work correctly
    //const auto p1 = this;
    //const Screen *p1 = this;
    //p1->display();

    //use const_cast to call the const version of display
    const_cast<const Screen*>(this)->display(out_stream);

    return *this;
}

Screen& Screen::move(pos x,pos y)
{
    if(x<=height && y<=width)       //if the range is legal, move the cursor
    {
        cursor = x*width + y;
    }

    return *this;
}

Screen& Screen::set(char c)
{
    content[cursor]=c;
    return *this;
}

Screen& Screen::set(pos x,pos y,char c)
{
    if(x<=height && y<=width)       //if the range is legal, move the cursor
    {
        content[x*width+y]=c;
    }
    return *this;
}
