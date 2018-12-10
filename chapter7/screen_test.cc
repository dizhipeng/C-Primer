#include <iostream>
#include "Screen.h"

using std::cout;
using std::endl;

int main()
{
    Screen front(5,6),back(4,10,'c');

    cout<<front.get()<<" "<<back.get()<<endl;

   // int a=11,*pa=&a;
   // const int *ca1=pa;
   // const auto ca2=pa;

   // cout<<*ca1<<" "<<*ca2<<endl;

    back.set('h').move(3,4).set('k').display(cout);
    cout<<endl;


    return EXIT_SUCCESS;
}
