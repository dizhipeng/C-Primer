#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;

bool find_element(vector<int>::iterator begin,
                  vector<int>::iterator end,
                  int target)
{
    auto iter=begin;

    //increment when the range is not empty
    //and the target is not found
    while(iter!=end && *iter!=target)
    {
        ++iter;
    }

    //if the element is found, it must in the range
    return iter!=end;
}

int main(int argc,char **argv)
{
    list<deque<int>> test;

    vector<int> v1={2,6,8,9};
    
    //iterator range
    int ele1=9,ele2=7;
    cout<<"Whether the elements are found: "
        <<find_element(v1.begin(),v1.end(),ele1)<<" "
        <<find_element(v1.begin(),v1.end(),ele2)<<endl;

    vector<int> v2={2,5,1,7};
    list<int> l1(v2.begin(),v2.end());

    //initial vector<double> from list<int> and vector<int>
    //only the element type matters
    vector<double> v3(v2.begin(),v2.end());
    vector<double> v4(l1.begin(),l1.end());
    
}
