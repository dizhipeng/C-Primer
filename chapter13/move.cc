#include <iostream>
#include <vector>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//class Y defines a copy constructor but without move constructor
struct Y
{
    Y()=default;
    //copy constructor
    Y(const Y&){};
};

struct hasY
{
    hasY()=default;
    //move constructor will be deleted because it has a Y mem
    hasY(hasY&&)=default;
    hasY(const Y&){cout<<"copy constructor called"<<endl;}
    Y mem;
};

int main(int argc,char **argv)
{
    //test rvalue ref
    string s1="abc";
    string &&r1=s1+"";
    string &&r2=std::move(s1);

    //r2 bound to s1, but s1 is not moved by any move constructor
    s1="ABC";
    cout<<r1<<" "<<r2<<endl;

    //test move with memory allocation
    //to see whether the new object's move constructor can be called
    string *ps = new string(std::move(s1));
    s1 = "DEF";
    cout<<*ps<<endl;

    shared_ptr<string> ssp = make_shared<string>(std::move(s1));
    s1 = "GHI";
    cout<<*ssp<<endl;
    cout<<s1<<endl;

    //test deleted move constructor(failed)
    hasY hy,hy2=std::move(hy);
    (void)hy2;
    return EXIT_SUCCESS;
}
