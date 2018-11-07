#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
    //vector<..> can't have elements as ref, but object of class vector<..> can be refered.
    vector<string> v0,&rv=v0;

    //vector init
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10,42);      
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};          //value init 10 empty string
    vector<string> v7{10,"hi"};     //not list init because initializer's type doesn't match. equivalent to v4(10,"hi")

    cout<<"Result of every init(size): "
        <<v1.size()<<' '
        <<v2.size()<<' '
        <<v3.size()<<' '
        <<v4.size()<<' '
        <<v5.size()<<' '
        <<v6.size()<<' '
        <<v7.size()<<' '
        <<endl;

    //Using .push_back() to add element into vector
    string temp_str;
    while(cin>>temp_str)
    {
        rv.push_back(temp_str);     //if the size of a vector is changed, then ranged for can't be used
    }

    cout<<endl;
    for(auto &i:rv)         //ranged for for vector
    {
        for(auto &j:i)      //ranged for for string
        {
            j=toupper(j);
        }
        cout<<i<<' ';
    }
    cout<<endl;

    for(int i=2;i<9;++i)
    {
        v1.push_back(i);     //if the size of a vector is changed, then ranged for can't be used
    }

    cout<<"The sum of adjacent elements: ";
    const auto &cv1=v1;
//  for(decltype(cv1.size()) i=0;i<cv1.size();i+=2)
    for(decltype(cv1.size()) i=0;i<cv1.size();++i)
    {
        auto second=cv1.size()-1-i;        //index comparison, type must be the same
//      auto second=i+1;        
//      if(second>=cv1.size())
        if(second>i)
        {
            cout<<cv1[i]+cv1[second]<<' ';
        }
//      else
        else if(second==i)
        {
            cout<<cv1[i]<<' ';
        }
    }
    cout<<endl;

    return 0;
}
