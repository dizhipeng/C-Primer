#include "HasPtr.h"

using std::string;
using std::cout;
using std::endl;

//steps for copy-assignment operator
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    cout<<"copy-assignment op"<<endl;

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
