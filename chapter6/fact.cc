#include <iostream>
#include <vector>
#include "Chapter6.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::initializer_list;
using std::vector;

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

int hasUpper(const string &str)
{
    int count=0;

    for(auto c:str)
    {
        if(isupper(c))
        {
            return count;
        }
        ++count;
    }
    return -1;
}

string &toUpper(string &str)
{
    for(auto &c:str)
    {
        c=toupper(c);
    }
    return str;
}

void swap_int_ptr(const int *&p1,const int *&p2)    //reference to pointers can swap two pointer
{
    auto temp=p1;
    p1=p2;
    p2=temp;
}

void print_arr(const int *beg, const int *end)      //extent of array parameter given by begin/end
{
    if(nullptr!=beg && nullptr!=end)
    {
        for(auto it=beg;it!=end;++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void print_arr(const int arr[],size_t sz)           //extent of array parameter given by size
{
    if(nullptr!=arr)                            //arr is a pointer, must check for empty if deferenced
    {
        for(size_t i=0;i!=sz;++i)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int cal_arr(char op,initializer_list<int> li)
{
    int result=0;

    switch(op)
    {
        case 'a':
            result=0;
            for(const auto &ele:li)
            {
                result+=ele;
            }
            break;
        case 'm':
            result=1;
            for(const auto &ele:li)
            {
                result*=ele;
            }
            break;
        default:
            result=0;
            break;
    }

    return result;
}

void print_vec(vector<int>::const_iterator beg,vector<int>::const_iterator end)     //recursive print a vector
{
    if(beg!=end)                //no more elements
    {
#ifndef NDEBUG
        cout<<"Calling "<<__func__<<" with vector size "<<end-beg<<endl;
#else
        cout<<*beg<<" ";      //print current element, proceed to next
#endif
        print_vec(++beg,end);
    }
}

//return parameter directly; 4 ways to return a reference of an array
string (&ret_arr1(string (&arr)[10]))[10]        
{
    return arr;
}

ref_string_arr_10 ret_arr2(string (&arr)[10])
{
    return arr;
}

auto ret_arr3(string (&arr)[10])->string (&)[10]
{
    return arr;
}

void f(int)     //parameter name can be omitted if not used
{
    cout<<"f(int);"<<" ";
}
void f(int,int)
{
    cout<<"f(int,int);"<<" ";
}
void f(double,double)
{
    cout<<"f(double,double);"<<" ";
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return ctr>1 ? word+ending : word;
}

const string &shorterString(const string &s1,const string &s2)
{
    return s1.size()<s2.size() ? s1 : s2;
}

string &shorterString(string &s1,string &s2)
{
    const auto &cs1=s1,&cs2=s2;          //auto must use & to generate ref, can't deduction ref directly
    auto &r=shorterString(cs1,cs2);      //calling the const version of shorterString
    return const_cast<string &>(r);      //cast const away to get original plein ref
}

int add_fun(int a,int b)
{
    return a+b;
}

int substract_fun(int a,int b)
{
    return a-b;
}

int multiply_fun(int a,int b)
{
    return a*b;
}

int divide_fun(int a,int b)
{
    return a/b;
}
