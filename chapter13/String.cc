#include "String.h"

#include <cstring>
#include <memory>

using std::ostream;
using std::allocator;
using std::uninitialized_copy_n;
using std::cout;
using std::endl;

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
    c_ptr = alloc_char.allocate(s.len);
    uninitialized_copy_n(s.c_ptr,s.len,c_ptr);
    len = s.len;
    cout<<"copy construct of String"<<endl;
}

#ifdef USING_SWAP
String& String::operator=(String s)
{
    swap(*this,s);
    cout<<"copy assignment of String"<<endl;
    return *this;
}
#else
String& String::operator=(const String &s)
{
    //save rightside string to temp variable
    auto temp_ptr = alloc_char.allocate(s.len);
    uninitialized_copy_n(s.c_ptr,s.len,temp_ptr);

    //free leftside string
    freeStr();
    
    //copy temp variable to leftside
    c_ptr = temp_ptr;
    len = strlen(c_ptr) + 1;

    cout<<"copy assignment of String"<<endl;
    return *this;
}
#endif
String::~String()
{
    freeStr();
}

void String::freeStr()
{
    for(signed i=len-1;i>=0;--i)
    {
        alloc_char.destroy(c_ptr+i);
    }
    alloc_char.deallocate(c_ptr,len);
}
