#include "Bulk_quote.h"

double Bulk_quote::net_price(size_t n) const
{
    if(n>min_copie)
    {
        return discount*n*price;
    }
    else
    {
        return n*price;
    }
}
