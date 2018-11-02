#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int var_fun();

const int local_var=100;        //Global const variable is local to the source file, can have multipule same const.
extern const int shared_var;    //Declaration of an extern const, not defined in this file.
//int test=100;                 //Global nonconst variable is not local to the source file, redefine is not allowed.
extern int test;                //Nonconst variable declaration.

int main()
{

    //Reference to pointer
    int *p=NULL;
    int *&rp=p;

    int i=10;
    p=&i;
    cout<<"Test reference to a pointer:"<<*rp<<endl;
 
    //Local const and shared const
    cout<<"const in file1:"<<local_var<<endl;
    cout<<"const in file2:"<<var_fun()<<endl;
    cout<<"shared const:"<<shared_var<<endl;
    cout<<"shared nonconst:"<<test<<endl;

    return 0; 
}
