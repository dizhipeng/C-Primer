#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen
{
    public:
        using pos=std::string::size_type;       //type memeber function

        Screen()=default;
        Screen(pos h,pos w,char c=' '):height(h),width(w),content(h*w,c){}

        char get() const { return content[cursor]; }
        char get(pos x,pos y) const { return content[x*width+y]; }

        Screen& move(pos x,pos y);
        Screen& set(char c);      //set the character at the cursor
        Screen& set(pos x,pos y,char c);

        const Screen& display(std::ostream& out_stream) const;      //declare as const member function
        Screen& display(std::ostream& out_stream);
    private:
        pos height=0;
        pos width=0;
        pos cursor=0;
        std::string content;


};

#endif
