#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include <iostream>
#include "Quote.h"

class Disc_quote: public Quote
{
    public:
        Disc_quote() = default;
        Disc_quote(const std::string &s, double d,size_t n,double p):
            Quote(s,d),min_copie(n),discount(p){}
        //net_price is derived from Quote, but becomes pure virtual
        double net_price(size_t n) const = 0;
        void debug() const override 
        { Quote::debug(); std::cout<<" mim_copie: "<<min_copie<<" discount: "<<discount;}
    protected:
        //discount related to copies sold
        size_t min_copie=0;
        double discount=1.0;
};

#endif
