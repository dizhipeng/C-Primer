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

    for(const auto &row:ma2)
    {
        for(auto &col:row)
        {
            cout<<col<<' ';
        }
        cout<<endl;
    }

}
