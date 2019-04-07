#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include "Quote.h"

class Bulk_quote: public Quote
{
    public:
        Bulk_quote()=default;
        //using base class's constructor to initialize its member
        Bulk_quote(const std::string &s, double d,size_t n,double p):
            Quote(s,d),min_copie(n),discount(p){}
        //derived class overrides the base class virtual function
        double net_price(size_t n) const override;
        void debug() const override 
        { Quote::debug(); std::cout<<" mim_copie: "<<min_copie<<" discount: "<<discount;}
    protected:
        //if purchased amount is beyond a given minimum number of copies
        //then give a discount
        size_t min_copie=0;
        double discount=1.0;
};

#endif
