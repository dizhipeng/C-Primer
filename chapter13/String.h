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
#ifdef USING_SWAP
        String& operator=(String s);
#else
        String& operator=(const String &s);
#endif
        ~String();
    private:
        void freeStr();
        static std::allocator<char> alloc_char;
        char* c_ptr = nullptr;
        // '\0' included
        size_t len = 0;
};

inline void swap(String &lhs,String &rhs)
{
    using std::swap;
    swap(lhs.c_ptr,rhs.c_ptr);
    swap(lhs.len,rhs.len);
}

#endif
