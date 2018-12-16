#include <iostream>
#include <vector>
#include <cstdlib>
#include "Other_test.h"

using std::cout;
using std::endl;
using std::vector;

//Define static members outside the class without static keyword
//for nonconst data member, define with initializer
double Example::rate=6.5;
vector<double> Example::vec(vecSize);

//for const data member, define without initializer
const int Example::vecSize;

//static function member
double Example::get_rate(){ return rate; }

int main()
{
    //NoDefault can't be default initialized
    //It must has an initial value
    vector<NoDefault> v1(10,0);

    //object of C can be default initialized
    vector<C> v2(10);

    //create 2 literal class objects
    constexpr Debug deb1;
    constexpr Debug deb2(true,false,false);

    //create a regular class object
    Debug deb3(true);

    //aggregate litral class
    constexpr Data li={0,0.0};

    //literal class object can't call reset()
    //but regular class can
    cout<<"literal class test: "<<deb1.testStat()
        <<", "<<deb2.testStat();
    cout<<", "<<deb3.testStat();
    cout<<", "<<deb3.reset().testStat();
    cout<<", "<<li.ival<<endl;

    //test static members of the class
    Example exa;
    cout<<"Two way to access static members: "
        <<Example::get_rate()<<", "<<exa.get_rate()<<endl;

    return EXIT_SUCCESS;
}
