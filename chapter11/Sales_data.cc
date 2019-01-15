#include <iostream>
#include "Sales_data.h"

using std::istream;
using std::ostream;
using std::endl;

//member functions defined outside the class definition
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    copies+=rhs.copies;     //private members can be accessed inside the class
    revenue+=rhs.revenue;
    return *this;           //return the referece of the object itself
}


//nonmember function that belongs to the class interface
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data temp=lhs;
    return temp.combine(rhs);
}

ostream& print(ostream &out_stream,const Sales_data &book)
{
    out_stream<<"The sum of this books sold is: "<<endl
        <<book.isbn()<<' '
        <<book.copies<<' '
        <<book.revenue<<' '
        <<book.average_price();

    return out_stream;
}

istream& read(istream &in_stream,Sales_data &book)
{
    double price=0.0;

    in_stream>>book.book_isbn>>book.copies>>price;
    book.revenue=price*book.copies;

    return in_stream;
}


