#include "String.h"

#include <cstring>
#include <memory>

using std::ostream;
using std::allocator;
using std::uninitialized_copy_n;

allocator<char> String::alloc_char;

ostream& operator<<(ostream& out,const String &s)
{
    out<<s.c_ptr;
    return out;
}

String::String(const char* cp)
{
    len = strlen(cp)+1;
    c_ptr = alloc_char.allocate(len);
    uninitialized_copy_n(cp,len,c_ptr);
}

//copy control
String::String(const String &s)
{
    len = strlen(s.c_ptr)+1;
    c_ptr = alloc_char.allocate(len);
    uninitialized_copy_n(s.c_ptr,len,c_ptr);
}

String& String::operator=(String s)
{
    swap(*this,s);
    return *this;
}

String::~String()
{
    for(signed i=len-1;i>=0;--i)
    {
        alloc_char.destroy(c_ptr+i);
    }
    alloc_char.deallocate(c_ptr,len);
}
