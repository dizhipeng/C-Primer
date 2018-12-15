#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data
{
    std::string book_isbn;

#ifdef IN_CLASS
    //use in-class initializer
    unsigned copies{0};
    double revenue={0.0};
#else
    //aggregate class can't use in-class initializer
    unsigned copies;
    double revenue;
#endif
};

#endif
