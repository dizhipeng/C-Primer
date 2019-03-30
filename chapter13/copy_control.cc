#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include "HasPtr.h"

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::string;
using std::set;
using std::vector;
using std::sort;

struct Point
{
    Point()=default;
    Point(const Point &p){cout<<"calling copy-constructor "<<++called<<" times"<<endl;}

    private:
        static size_t called;
};

size_t Point::called=0;

Point global;
//calling 1: value pass parameters
Point foo_bar(Point arg)
{
    //calling 2,3: copy initialize local/dynamic varibles
    Point local=arg,*heap=new Point(global);
    *heap=local;
    //call 4,5: copy initialize vector elements
    Point pa[4]={local,*heap};
    (void)pa;

    //call 6: return by value
    return *heap;
}

struct X
{
    X(){std::cout<<"X()"<<std::endl;}
    X(const X&){std::cout<<"X(const X&)"<<std::endl;}
    X& operator=(const X&)
    {std::cout<<"X& operator=(const X&)"<<std::endl;return *this;}
    ~X(){std::cout<<"~X()"<<std::endl;}
};

class numbered
{
    friend void f(const numbered &s);

    public:
        numbered():mysn(new_serial()){};
        numbered(const numbered &n):mysn(new_serial()){};

    private:
        unsigned mysn;
        static default_random_engine e;
        static uniform_int_distribution<unsigned> u;
        static set<unsigned> generated;
        static unsigned new_serial();
};

//definition of static members of class numbered
default_random_engine numbered::e;
uniform_int_distribution<unsigned> numbered::u(10000,99999);
set<unsigned> numbered::generated;

//generate a new serial number that has not been generated
unsigned numbered::new_serial()
{
    unsigned ret;

    //find a number that is not generated ever
    do
    {
        ret=u(e);
    }while(generated.end()!=generated.find(ret));

    //record the new generated number
    generated.insert(ret);
    return ret;
};

//functions to print the serial numebr
void f(const numbered &s){cout<<s.mysn<<endl;}

int main(int argc,char **argv)
{

    Point p;
    foo_bar(p);

    //copy construct & copy-assigment operator
    HasPtr a,b=a,c("hello"),d=c;
    a=c;
    d=b;

    //test self-assignment
    b=b;
    d=d;

    print(cout,a)<<endl;
    print(cout,b)<<endl;
    print(cout,c)<<endl;
    print(cout,d)<<endl;

    //print copy control information
    X x1,x2=x1;
    x1=x2;

    //copy control for bookkeeping purposes
    numbered an,bn=an,cn=bn;
    f(an);
    f(bn);
    f(cn);

    //if pointer like, one object's reference count will go to zero 
    //and its memory will be freed
    a=b=c=d;

    //whether HasPtr act like value or pointer makes difference
    a=string("first");
    b=string("second");

    //test swap
    swap(a,b);

    c=string("third");
    d=string("fourth");
    vector<HasPtr> hv={a,b,c,d};

    //Using sort to test swap, only when vector is big enough
    for(int i=0;i!=50000;++i)
    {
        hv.push_back(hv[i%4]);
    }
    sort(hv.begin(),hv.end(),[](const HasPtr &lhs,const HasPtr &rhs)
            {return lhs.getStr()<rhs.getStr();});

    print(cout,a)<<" ";
    print(cout,b)<<endl;

    return EXIT_SUCCESS;
}

