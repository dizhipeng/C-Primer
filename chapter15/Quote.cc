#include "Quote.h"
#include <iostream>

using std::ostream;

ostream& print_total(ostream& out, const Quote &q, size_t n)
{
    out<<"purchase "<<n<<" book(s) of "<<q.get_isbn()<<" costs "<<q.net_price(n)<<" dollars.";
    return out;
}
