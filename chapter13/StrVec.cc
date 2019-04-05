#include <memory>
#include "StrVec.h"

using std::string;
using std::ostream;
using std::allocator;
using std::pair;

//static member definition for the allocator
allocator<string> StrVec::alloc;

pair<string*,string*> StrVec::alloc_n_copy
(const string *b, const string *e)
{
    auto new_ele = alloc.allocate(e-b);

    //return the pair of [beg,end)
    return {new_ele, uninitialized_copy(b,e,new_ele)};
}

//destruct the vector
void StrVec::free()
{
    if(elements)
    {
        //destruct elements reversely
        while(first_free!=elements)
        {
            alloc.destroy(--first_free);
        }
        //free the allocated space
        alloc.deallocate(elements,capacity());
    }
}

//make more space
void StrVec::reallocate()
{
    auto curr_cap=capacity();

    //if the vector isn't allocated, allocate 1 space
    //else, double the current space
    size_t space = curr_cap==0 ? 1 : 2*curr_cap;

    auto new_ele = alloc.allocate(space);

    //return off-the-end iterator of the destination
    auto new_first_free = uninitialized_copy(make_move_iterator(elements),
                          make_move_iterator(first_free),
                          new_ele);

    //free old space
    free();

    //update pointers of current object
    elements = new_ele;
    first_free = new_first_free;
    cap =  new_ele + space;
}

void StrVec::push_back(const std::string &s)
{
    //make sure there is room for new element
    chk_n_alloc();
    //construct new element based on s
    alloc.construct(first_free++,s);
}

ostream& operator<<(ostream& out,const StrVec &s)
{
    out<<"size="<<s.size()<<", capacity="<<s.capacity();
    return out;
}

StrVec::StrVec(const StrVec &s)
{
    auto copied = alloc_n_copy(s.begin(),s.end());
    elements = copied.first;
    cap = first_free = copied.second;
}

StrVec& StrVec::operator=(const StrVec &s)
{
    auto copied = alloc_n_copy(s.begin(),s.end());
    free();
    elements = copied.first;
    cap = first_free = copied.second;

    return *this;
}

StrVec::~StrVec()
{
    free();
}
