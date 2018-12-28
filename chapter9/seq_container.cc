#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::out_of_range;
using std::forward_list;

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

void insert_fl(forward_list<string> &fl,const string &s1,const string &s2)
{
    auto prev=fl.before_begin();
    auto curr=fl.begin();

    bool exist=false;

    while(curr!=fl.end())
    {
        if(*curr==s1)
        {
            exist=true;
            
            //curr points to the new inserted string
            curr=fl.insert_after(curr,s2);
        }

        prev=curr++;
    }

    //no s2 exists, after insert the last element
    if(!exist)
    {
        fl.insert_after(prev,s2);
    }

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

        if(it2_next!=v2.cend())
        {
            //insert act like a push_front for vectors, when vector doesn't have push_front
            //insert position other than the last can be slow for vector
            //form insert(p,b,e) inserts [b,e) elements, so we insert two elements in this case
            it1=v1.insert(it1,it2,it2_next+1);

            //jump to the next two elements
            it2=it2_next+1;
        }
        else
        {
            //insert the last element
            it1=v1.insert(it1,it2,it2_next);

            //no more elements
            break;
        }
    }

    //size of v1 is now 1
    v1 = {6};
    cout<<"test the element: "<<v1.front()<<" "
        <<v1.back()<<" "
        <<*v1.cbegin()<<" "
        <<*(v1.cend()-1)<<endl;
    
    //access elements from an empty vector
    v1.clear();
    try
    {
        //when using at() with an ilegal index, an out-of-ranged exception is thrown
        cout<<v1.at(0)<<endl;

        cout<<"Others ways don't throw exceptions, but are undefined"<<endl;
        cout<<v1[0]<<endl;
        cout<<v1.front()<<endl;
        cout<<*v1.cbegin()<<endl;
    }
    catch(out_of_range e)
    {
        cout<<"Out of range exception thrown:"<<endl;
        cout<<e.what()<<endl;
    }

    //two same iterators mark an empty range
    v2.erase(v2.begin(),v2.begin());
    v2.erase(v2.end(),v2.end());

    //copy an array into containers
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    v1.assign(std::begin(ia),std::end(ia));
    l1.assign(std::begin(ia),std::end(ia));

    it1=v1.begin();
    auto it3=l1.begin();

    while(it1!=v1.end()&&it3!=l1.end())
    {
        //odd values in vector are kept
        if(*it1%2)
        {
            ++it1;
        }
        else
        {
            //erase returns the iterator after the last removed one
            //increment the iterator automatically
            it1=v1.erase(it1);
        }

        //even values in list
        if(!(*it3%2))
        {
            ++it3;
        }
        else
        {
            it3=l1.erase(it3);
        }

    }

    forward_list<int> f1(std::begin(ia),std::end(ia));

    //forward list usually need two iterators to operate
    auto prev=f1.before_begin();
    auto curr=f1.begin();

    while(curr!=f1.end())
    {
        //odd value
        if(*curr%2)
        {
            //original current element is erased
            //new current element is the next one
            //prev stays the same
            curr=f1.erase_after(prev);
        }
        else
        {
            //two iterators move forward
            prev=curr++;
        }
    }

    forward_list<string> f2={"insert","after","one","special","word"};

    insert_fl(f2,"not","one");
    insert_fl(f2,"one","very");
    insert_fl(f2,"one","not");

    //added elements are value-initialized if no initial value is provided
    v2.resize(100);

    //tail elements are removed
    v2.resize(10);

    for(auto const &ele:v2)
    {
        cout<<ele<<endl;
    }
}
