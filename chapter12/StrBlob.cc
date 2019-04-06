#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::out_of_range;
using std::string;
using std::ostream;
using std::make_shared;
using std::vector;
using std::string;

ostream& operator<<(ostream &out,const StrBlob &s)
{
    for(const auto &ele:*s.data)
    {
        out<<ele<<" ";
    }

    return out;
}

void StrBlob::check(size_type sz,const string &msg) const
{
    if(sz>=data->size())
    {
        throw out_of_range("check failed while calling "+msg+"()");
    }
}

void StrBlob::push_back(const string &s)
{
    data->push_back(s);
}


void StrBlob::pop_back()
{
    check(0,__func__);
    data->pop_back();
}

string& StrBlob::front()
{
    check(0,__func__);
    return data->front();
}

const string& StrBlob::front() const
{
    check(0,__func__);
    return data->front();
}

string& StrBlob::back()
{
    check(0,__func__);
    return data->back();
}

const string& StrBlob::back() const
{
    check(0,__func__);
    return data->back();
}

//return type is a class defined type, use :: to indicate
StrBlob::size_type StrBlob::size() const
{
    return data->size();
}

bool StrBlob::empty() const
{
    return data->empty();
}

#ifdef VALUE_LIKE
StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    //reference count of the left operand will decrease by 1
    data=make_shared<vector<string>>(*rhs.data);

    return *this;
}
#endif

StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this,0);
}

StrBlobPtr StrBlob::end() const
{
    return StrBlobPtr(*this,data->size());
}
