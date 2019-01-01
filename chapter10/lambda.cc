#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::begin;
using std::end;
using std::equal;

using namespace std::placeholders;

bool check_size(const string &s,string::size_type sz)
{
    return s.size()>sz;
}

void biggies(vector<string> &words,string::size_type sz)
{
    //count how many words are longer than sz
    auto callable_l=[sz](const string &s){return s.size()>sz;};
    auto callable_b=bind(check_size,_1,sz);

    cout<<"total "
        <<count_if(words.cbegin(),words.cend(),callable_b)
        <<" word(s) longer than "
        <<sz<<endl;
                
    //move all string longer than sz in the front, using partition
    auto par_end=stable_partition(words.begin(),words.end(),callable_l);

    //print every element in the partition
    for_each(words.begin(),par_end,
            [](const string &s){cout<<s<<",";});
    cout<<"\b "<<endl;
}

int main(int argc,char **argv)
{
    //defines a lambda and create a lambda object
    auto la1=[](int a,int b){return a+b;};
    
    //call the lambda object
    cout<<"Calling lambda object: "<<la1(40,2)<<endl;

    int i=100;
    //lambda with capture by value
    auto l2=[i](int a){return i+a;};
    cout<<"Calling lambda with capture: "<<l2(50)<<endl;

    vector<string> va={"333",
                       "22",
                       "55555",
                       "4444",
                       "55555",
                       "333",
                       "55555",
                       "4444",
                       "55555",
                       "333",
                       "22",
                       "4444",
                       "55555",
                       "1",
                       "4444",
                       "7777777"};
    biggies(va,4);

    i=5;
    //if capture by value, keyword mutable is needed to change the capture member
    auto l3=[i]()mutable{return i==0?true:--i==0;};

    cout<<"Calling l3 10 times: ";
    for(size_t j=0;j!=10;++j)
    {
        cout<<l3()<<" ";
    }
    cout<<endl;

    //using algothrim find_if_not to find the bigger int
    string str="Length=8";
    vector<int> v1={3,1,9,10,7,11};
    cout<<"The first int bigger than the length of a string: "
        <<*find_if_not(v1.cbegin(),v1.cend(),bind(check_size,str,_1));

    return EXIT_SUCCESS;
}
