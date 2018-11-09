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
    cout<<"Input string: ";
    while(cin>>temp_str)
    {
        rv.push_back(temp_str);     //if the size of a vector is changed, then ranged for can't be used
    }

    cout<<endl<<"to upper case: ";
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
    for(decltype(cv1.size()) i=0;i<=(cv1.size()-1)/2;++i)
    {
        auto second=cv1.size()-1-i;        //index comparison, type must be the same
        if(second>i)
        {
            cout<<cv1[i]+cv1[second]<<' ';
        }
        else if(second==i)
        {
            cout<<cv1[i]<<' ';
        }
    }
    cout<<endl<<"to lower case: ";

    for(auto pi=rv.begin();pi!=rv.end();++pi)           //pi is the iterator of vector<string>, like a pointer to string
    {
        for(auto pj=pi->begin();pj!=pi->end();++pj)     //pj is the iterator of string, like a pointer to char
        {
            (*pj)=tolower(*pj);
        }

        cout<<(*pi)<<' ';
    }

    //binary search using iterator
    cin.clear();        //reset cin because it became EOF last time
    int find=0;
    cout<<endl<<"Element to search: ";
    cin>>find;
    auto beg=v1.cbegin(),end=v1.cend(),mid=beg+(end-beg)/2;
    while(*mid!=find && mid!=end)                   //If mid==end, the target doesn't exist.
    {                                               //end can't be the target, because 
        if(*mid>find)                               //1.In the beginning, it doesn't point to any element. 
            end=mid;                                //2.If it moves to an element, the element is excluded because it's bigger than the target
        else
            beg=mid+1;
        mid=beg+(end-beg)/2;    //recalculate the mid every time
    }
    
    if(mid==end)
        cout<<"Element not found"<<endl;
    else
        cout<<"vi["<<mid-v1.cbegin()+0<<"] is the element."<<endl;        //iterator1-iterator2 returns difference_type, begin is at position 0

    vector<unsigned> grade{42,65,95,100,39,67,95,76,88,76,83,92,76,93};
    vector<unsigned> stat(11,0);        //11 level for grade 0 to 100
    
    auto it=stat.begin();
    for(const auto &i:grade)
    {
        if(i<=100)
            ++*(it+i/10);
    }
    for(const auto &i:stat)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}
