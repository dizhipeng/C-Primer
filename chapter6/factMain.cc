#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
    compute_fac();

    cout<<"absolute value test: ";
    for(int i=-4;i<=4;++i)
    {
        cout<<absolute(i)<<" ";
    }
    cout<<endl;

    //local static variable test
    cout<<"Call function 10 times: ";
    for(int i=0;i!=10;++i)
    {
        cout<<count_call()<<" ";
    }
    cout<<endl;

    int a1=5,a2=10;
    cout<<"swap two ints: ";
    cout<<"("<<a1<<","<<a2<<") ";
    swap_ints(&a1,&a2);                 //passed by value, pointer
    cout<<"("<<a1<<","<<a2<<") ";
    swap_ints(a1,a2);                   //passed by reference
    cout<<"("<<a1<<","<<a2<<") ";

    return 0;
}
