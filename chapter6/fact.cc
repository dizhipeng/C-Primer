#include <iostream>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::endl;

int absolute(int n)
{
    return n>=0 ? n : -n;
}

int factorial(int n)
{
    int ret=1;
    while(n>1)
    {
        ret*=n--;
    }
    return ret;
}

void compute_fac()
{
    int num=0;
    cout<<"Enter a number to calculate factorial to: ";
    cin>>num;
    cout<<"The factorial of "<<num<<" is "<<factorial(num)<<endl;
}

unsigned count_call()
{
    static unsigned n;  //value-init to 0
    return n++;
}

void swap_ints(int *a,int *b)
{
    if(a!=nullptr && b!=nullptr)
    {
        auto temp=*a;
        *a=*b;
        *b=temp;
    }
}

void swap_ints(int &a,int &b)
{
    auto temp=a;
    a=b;
    b=temp;
}
