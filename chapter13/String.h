#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
    friend std::ostream& operator<<(std::ostream& out,const String &s);
    friend void swap(String &lhs,String &rhs);
    public:
        //constructor
        String()=default;
        String(const char* cp);

        //copy control
        String(const String &s);
        String& operator=(String s);
        ~String();
    private:
        static std::allocator<char> alloc_char;
        char* c_ptr = nullptr;
        size_t len = 0;
};

inline void swap(String &lhs,String &rhs)
{
    using std::swap;
    swap(lhs.c_ptr,rhs.c_ptr);
    swap(lhs.len,rhs.len);
}

#endif
