#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen
{
    //declare friend class
    friend class Window_mgr;

    //declare friend member of class

    public:

        //type memeber function
        using pos=std::string::size_type;       

        Screen()=default;
        Screen(pos h,pos w,char c=' '):height(h),width(w),content(h*w,c){}

        //get the character at the cursor or a given position
        char get() const { return content[cursor]; }
        char get(pos x,pos y) const { return content[x*width+y]; }
        
        //set the character at the cursor or a given position
        Screen& set(char c);      
        Screen& set(pos x,pos y,char c);    

        //move the curser
        Screen& move(pos x,pos y);

        //Dislay the content, declare as const member function
        const Screen& display(std::ostream& out_stream) const;      
        //Overload a nonconst version of screen using the const version
        Screen& display(std::ostream& out_stream);

    //private:
        pos height=0;
        pos width=0;
        pos cursor=0;
        std::string content;
};

#endif
