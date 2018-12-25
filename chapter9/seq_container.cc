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

    vector<int> v2={2,5,1,7,4,8,0,9,3};
    list<int> l1(v2.begin(),v2.end());

    //initial vector<double> from list<int> and vector<int>
    //only the element type matters
    vector<double> v3(v2.begin(),v2.end());
    vector<double> v4(l1.begin(),l1.end());

    list<const char *> l2={"test","string","list"};
    vector<string> v5={"string","vectors"};

    //assign function test
    v5.assign(l2.begin(),l2.end());

    //container equality operation
    cout<<"Whether v3 and v4 are equal: "<<(v3==v4)<<endl;
    cout<<"Whether v2 and l1 are equal: ";

    //change some elements for test
    //v2[2]=3;
    //*l1.begin()=9;

    if(v2.size()!=l1.size())
    {
        //unequal if size is different
        cout<<false<<endl;
    }
    else if(0==v2.size())
    {
        //empty containers
        cout<<true<<endl;
    }
    else
    {
        //use const iterator when elements won't be changed
        auto beg1=v2.cbegin();
        auto beg2=l1.cbegin();

        //check equality for every element
        for(decltype(v2.size()) i=0;i!=v2.size();++i)
        {
            //found unequal elements, stop checking
            if(*beg1++!=*beg2++)
            {
                cout<<false<<endl;
                break;
            }
            //the last element are equal, then the containers are equal
            else if(v2.size()==i+1)
            {
                cout<<true<<endl;
            }
        }
    }

    for(const auto &s:v5)
    {
        cout<<s<<endl;
    }

    //add strings from input into deque, and print
    cout<<"Input some strings:";
    deque<string> d1;
    string s1;
    while(cin>>s1)
    {
        d1.push_back(s1);
    }

    cout<<"strings pushed into deques: "<<endl;
    for(auto iter=d1.cbegin();iter!=d1.cend();++iter)
    {
        cout<<*iter<<endl;
    }

    //copy elemnts from list<int>, even element to one deque, odd to another
    deque<int> d_even,d_odd;
    for(auto const &ele:l1)
    {
        if(ele%2)
        {
            //odd elements
            d_odd.push_back(ele);
        }
        else
        {
            d_even.push_back(ele);
        }
    }

    v1.clear();
    auto it1=v1.begin();
    auto it2=v2.cbegin();

    //push_front every two element in a vector
    while(it2!=v2.cend())
    {
        //the next element, can be end()
        auto it2_next=it2+1;
        
        //insert act like a push_front for vectors, when vector doesn't have push_front
        //insert position other than the last can be slow for vector
        it1=v1.insert(it1,it2,it2_next);
        
        if(it2_next!=v2.cend())
        {
            //jump to the next two elements
            it2=it2_next+1;
        }
        else
        {
            //no more elements
            break;
        }
    }

    for(auto const &ele:v1)
    {
        cout<<ele<<endl;
    }
}
