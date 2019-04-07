#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>

class Quote
{
    public:
        Quote()=default;
        Quote(const std::string &s, double d):isbn(s),price(d){}
        //functions that will be overriden by the derived class
        std::string get_isbn() const{ return isbn; }
        virtual double net_price(size_t n) const {return n*price;}
        virtual void debug() const { std::cout<<"isbn: "<<isbn<<" price: "<<price;}
        //base class must have a virtual destructor
        virtual ~Quote()=default;
protected:
        double price=0.0;
private:
        std::string isbn;
};

std::ostream& print_total(std::ostream& out, const Quote &q, size_t n);
#endif
