#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    constexpr size_t rows=3;
    constexpr size_t cols=4;
    
    //multiarray init
    int ma1[rows][cols]={                 //init every row explicitly
        {1},
        {0,1},
        {0,0,1},
    };

    for(const auto &row:ma1)
    {
        for(auto &col:row)
        {
            cout<<col<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    int ma2[rows][cols]={1,2,3,4,5,6};    //init from the first row

    //multiarray and ranged for
    for(const auto &row:ma2)
    {
        for(auto &col:row)
        {
            cout<<col<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    //multiarray and reference
    for(size_t i=0;i!=rows;++i)
    {
        const int (&r)[cols]=ma1[i];     //ma1[0] has the type int[cols], r is a ref to int[cols]

        for(size_t j=0;j!=cols;++j)
        {
            cout<<r[j]<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    //multiarray and pointer
    for(const int (*p)[cols]=begin(ma2);p!=end(ma2);++p)        //ma2 is the pointer to the first element of its row, so p is a pointer to int[cols]
    {
        for(const int *q=begin(*p);q!=end(*p);++q)              //dereference a point to array get an array, which itself is a pointer to its first element
        {
            cout<<*q<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    //using alias
    using row_type=int[cols];
    for(const row_type *p=begin(ma1);p!=end(ma1);++p)
    {
        for(const int *q=begin(*p);q!=end(*p);++q)
        {
            cout<<*q<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    const auto p1=ma1;     //auto deduce *(int[cols]), top-level const
    const auto *p2=ma1;    //auto deduce int[cols], low-level const

    ++(**p1);
//  p1=ma2;
//  ++(**p2);
    p2=ma2;

    cout<<**p1<<' '<<**p2<<endl;
    
}
