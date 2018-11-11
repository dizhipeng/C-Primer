#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main()
{
    constexpr size_t arr_size=50;
    char p1[arr_size]="Concat";
    char p2[]="a string";
    char p3[arr_size]={};
    string s1=", again.";

    cout<<p1<<' '<<p2<<endl;
    cout<<"String size: "<<"strlen(p1)="<<strlen(p1)<<' '<<"s1.size()="<<s1.size()<<endl;

    if(sizeof(p3)>=(strlen(p1)+1+strlen(p2)+s1.size()))       //Before strcat and strcpy, the size of target char array must be checked to be big enough
    {
        strcpy(p3,p1);
        strcat(p3," ");
        strcat(p3,p2);
        strcat(p3,s1.c_str());                               //string.c_str() returns a char array(const pointer to the first character)
    }
    cout<<p3<<endl;

    vector<char> v1(begin(p3),end(p3));                      //use array to initialize vector
    cout<<"array init vector: ";

    for(const auto &c:v1)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    auto v1_begin=v1.cbegin(),v1_end=v1.cend();
    size_t i=0;
    
    while(i!=arr_size && v1_begin!=v1_end)                  //terminate when one of the sequence is over
    {
        p1[i]=*v1_begin;
        ++i;
        ++v1_begin;
    }

    cout<<"copy vector to array: ";
    for(const auto &c:p1)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    return 0;
}
