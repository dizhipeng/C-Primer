#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <string>
#include <iostream>

class HasPtr
{
    public:
        HasPtr()=default;
        HasPtr(const std::string &s):ps(new std::string(s)){}
        HasPtr(const HasPtr &hp):ps(new std::string(*hp.ps)),i(hp.i)
        {std::cout<<"copy construct"<<std::endl;}
        void print() const {std::cout<<*ps<<std::endl;}
        HasPtr& operator=(const HasPtr &rhs);
        ~HasPtr(){std::cout<<"destructor"<<std::endl;delete ps;}
    private:
        std::string *ps=new std::string();
        int i=0;
};

#endif
