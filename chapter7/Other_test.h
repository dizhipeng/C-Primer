#ifndef OTHER_TEST_H
#define OTHER_TEST_H

#include <iostream>

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
#endif
