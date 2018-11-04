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
    cout<<"test reference to a pointer: "<<*rp<<endl;
 
    //Local const and shared const
    cout<<"const in file1: "<<local_var<<endl;
    cout<<"const in file2: "<<var_fun()<<endl;
    cout<<"shared const: "<<shared_var<<endl;
    cout<<"shared nonconst: "<<test<<endl;

    //Bind const ref to literal and expression
    const double &conref1=i+50;
    const int &conref2=120.5;
    cout<<"const ref: "<<conref1<<' '<<conref2<<endl;

    //Bind const ref to nonconst object, and change the object
    int val=80;
    const int &ref_val=val;
    cout<<"const ref before and after: "<<ref_val<<' ';
    val+=10;
    cout<<ref_val<<endl;

    //Errors
//  int &const r1=i;  //Reference has no top-level
//  int &r2=0;        //Nonconst ref must bind to a same type object
//  int *const p1;    //Const object(pointer) must be initialized

    //constexpr must be intialized by constant expression
//  constexpr int conex=var_fun();
    constexpr int *conp=&test;      //constexpr pointers can be init by addr(fixed) of globla var
    constexpr int &conr=test;       //so as to constexpr ref
    test=700;
    ++(*conp);  //constexpr pointer is a const pointer rather than a pointer to const
    ++conr;
    cout<<"test constexpr ref and pointer: "<<*conp<<' ' <<conr<<endl;

    return 0; 
}
