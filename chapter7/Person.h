#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    friend std::istream& read(std::istream &in_stream,Person &p);
    friend std::ostream& print(std::ostream &in_stream,const Person &p);

    private:
        std::string name;
        std::string address;
    public:
        Person()=default;
        Person(const std::string &n):name(n){}
        Person(const std::string &n,const std::string &a):name(n),address(a){}
        std::string get_name() const { return name; }
        std::string get_address() const { return address; }

};


std::istream& read(std::istream &in_stream,Person &p);
std::ostream& print(std::ostream &in_stream,const Person &p);
#endif
