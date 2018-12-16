#ifndef OTHER_TEST_H
#define OTHER_TEST_H

#include <iostream>
#include <vector>

class Y;

class X
{
    //class X has a member of a --pointer-- to Y
    //Require class Y to be declared
    Y *y;
};

class Y
{
    //class Y has a member of an --object-- of X
    //Require class X to be defined
    X x;
};

//This class has no default constructor
class NoDefault
{
    public:
        NoDefault(int){ std::cout<<"NoDefault init"<<std::endl; }
};

class C
{
    private:
        NoDefault member;

    public:
        //Default constructor which initialize NoDefault member explicitly
        C():member(0){ std::cout<<"C init"<<std::endl; }
};

//non aggregate literal class
class Debug
{
    public:
        //constexpr constructors
        constexpr Debug(bool b=false):sw(b),hw(b),other(b){}
        constexpr Debug(bool s,bool h,bool o):sw(s),hw(h),other(o){}

        //const member functions can be called from literal class
        bool testStat() const { return sw || hw || other ; }

        //regular memeber functions can't be call from literal class
        Debug& reset(bool s=false,bool h=false,bool o=false)
        { sw=s; hw=h; other=o; return *this; }

    private:
        bool sw;
        bool hw;
        bool other;
};

//aggregate literal class
struct Data
{
#ifndef IN_CLASS
    //aggregate class can't have in-class initializer
    int ival;
    double dval;
#else
    int ival=0;
    double dval=0.0;
#endif
};

class Example
{
    private:
        static double rate;
        static const int vecSize = 20;
        static std::vector<double> vec;

    public:
        static double get_rate();
};
#endif
