#include <iostream>
#include "HasPtr.h"

using std::cout;
using std::endl;

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

    a.print();
    b.print();
    c.print();
    d.print();

    X x1,x2=x1;
    x1=x2;

    return EXIT_SUCCESS;
}
