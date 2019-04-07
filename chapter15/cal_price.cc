#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

using std::cout;
using std::endl;

int main(int argc,char **argv)
{
    Quote book("Normal",10);
    Bulk_quote book_discount("Discount",10,5,0.8);
    Limit_quote book_limit("Limited",10,4,0.6);

    print_total(cout,book,8)<<endl;
    print_total(cout,book,10)<<endl;
    print_total(cout,book_discount,4)<<endl;
    print_total(cout,book_discount,5)<<endl;
    print_total(cout,book_discount,6)<<endl;
    print_total(cout,book_discount,10)<<endl;
    print_total(cout,book_limit,2)<<endl;
    print_total(cout,book_limit,3)<<endl;
    print_total(cout,book_limit,4)<<endl;
    print_total(cout,book_limit,10)<<endl;

    book.debug();
    cout<<endl;
    book_discount.debug();
    cout<<endl;
    book_limit.debug();
    cout<<endl;

    return EXIT_SUCCESS;
}
