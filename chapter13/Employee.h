#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
    public:
        Employee():identifier(new_id++){}
        Employee(const std::string &n):name(n),identifier(new_id++){}
        //copy control member
        Employee(const Employee &e):name(e.name),identifier(new_id++){}
        Employee& operator=(const Employee &e);
        void test(){std::cout<<name<<" "<<identifier<<std::endl;}

    private:
        std::string name;
        unsigned identifier;
        static unsigned new_id;
};

#endif
