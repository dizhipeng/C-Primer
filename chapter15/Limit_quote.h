#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include <string>

#ifdef NO_DISC

#include "Bulk_quote.h"

class Limit_quote: public Bulk_quote
{
    public:
        Limit_quote()=default;
        //using base class's constructor to initialize its member
        Limit_quote(const std::string &s, double d,size_t n,double p):Bulk_quote(s,d,n,p){}
        //derived class overrides the base class virtual function
        double net_price(size_t n) const override;
};

#else

#include "Disc_quote.h"

class Limit_quote: public Disc_quote
{
    public:
        Limit_quote()=default;
        //using base class's constructor to initialize its member
        Limit_quote(const std::string &s, double d,size_t n,double p):Disc_quote(s,d,n,p){}
        //derived class overrides the base class virtual function
        double net_price(size_t n) const override;
};

#endif

#endif
