#include "StrBlobPtr.h"

using std::out_of_range;
using std::runtime_error;
using std::string;
using std::ostream;
using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;

shared_ptr<vector<string>> 
StrBlobPtr::check(size_type sz,const string &msg) const
{
    auto sp=wp.lock();

    //if object is already destroyed, lock() returns null
    if(!sp)
    {
        throw runtime_error(msg+"(): object in shared_ptr is invalid");
    }
    
    //index range check
    if(sz>=sp->size())
    {
        throw out_of_range(msg+"(): index exceeds vector size");
    }

    return sp;
}

string& StrBlobPtr::deref() const
{
    auto p=check(index,__func__);

    //* gets the vector, [] gets the string
    return (*p)[index];
}

StrBlobPtr& StrBlobPtr::incr()
{
    //index must less than size to increase
    check(index,__func__);

    //after increament, index<=size
    ++index;

    //return the increamented pointer as usual
    return *this;
}
