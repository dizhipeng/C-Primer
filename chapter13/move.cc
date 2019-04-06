#include <iostream>
#include <vector>

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

    s1="ABC";
    cout<<r1<<" "<<r2<<endl;

    //test deleted move constructor(failed)
    hasY hy,hy2=std::move(hy);
    (void)hy2;
    return EXIT_SUCCESS;
}
