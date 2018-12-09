#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen
{
    public:
        using pos=std::string::size_type;       //type memeber function

        Screen()=default;
        Screen(pos h,pos w,char c=' '):height(h),wight(w),content(h*w,c){}

        char get() const { return content[cursor]; }
        char get(pos x,pos y) const { return content[x*wight+y]; }

        Screen& move(pos x,pos y);
    private:
        pos height=0;
        pos wight=0;
        pos cursor=0;
        std::string content;


};

#endif
