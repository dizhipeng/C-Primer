#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data
{
    //friendship declaration
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);           
    friend std::istream& read(std::istream &in_stream,Sales_data &book);          
    friend std::ostream& print(std::ostream &out_stream,const Sales_data &book); 

    private:    //data member
        std::string book_isbn;      
        unsigned copies{0};             //in-class initializer is used in default constructor first
        double revenue={0.0};

    public:     //interface
        Sales_data()=default;
        Sales_data(std::string b):book_isbn(b){}                        //use constructor initializer list
        Sales_data(std::string b,unsigned c,double r):book_isbn(b),copies(c),revenue(r){}
        Sales_data(std::istream &in_stream){ read(in_stream,*this); }
        std::string isbn() const { return book_isbn; }                  //const member function
        Sales_data &combine(const Sales_data &rhs);                     //act like += operator,returns a lvalue 
};

//function declaration
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);           //act like + operator,returns a rvalue
std::istream& read(std::istream &in_stream,Sales_data &book);          //act like >> operator
std::ostream& print(std::ostream &out_stream,const Sales_data &book);   //act like << operator

#endif


