#include "HasPtr.h"


using std::string;
using std::cout;
using std::endl;
using std::ostream;

#ifndef POINTER_LIKE
//steps for copy-assignment operator
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    //allocate memory, copy member from right hand side
    auto ps_new=new string(*rhs.ps);

    //free memory of left hand side
    delete ps;

    //assign right hand side to left
    ps=ps_new;
    i=rhs.i;

    //return reference to left hand side
    return *this;
}

HasPtr::~HasPtr()
{
    delete ps;
}

HasPtr::HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
#else
//steps for copy-assignment operator
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    //increase the right hand's reference count
    ++*rhs.num;

    //decrease the left hand's reference count
    if(!--*num)
    {
        delete ps;
        delete num;
        cout<<"last object destroyed, memory freed."<<endl;
    }

    //member-wise assigment
    ps=rhs.ps;
    i=rhs.i;
    num=rhs.num;

    return *this;
}

HasPtr::~HasPtr()
{
    //destroy an object decrease the reference count
    if(!--*num)
    {
        delete ps;
        delete num;
        cout<<"last object destroyed, memory freed."<<endl;
    }
}

HasPtr::HasPtr(const HasPtr &hp):ps(hp.ps),i(hp.i),num(hp.num)
{
    //copy init increase the reference count
    ++*num;
}
#endif

ostream& print(ostream &out,const HasPtr &h)
{
    out<<*h.ps;
    return out;
}

