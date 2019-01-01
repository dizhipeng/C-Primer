#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

//declare the class
class Sales_data;

//declare the function; friend declaration can't used as normal declaration
//act like >> operator
std::istream& read(std::istream &in_stream,Sales_data &book);

class Sales_data
{
    //friendship declaration
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);           
    friend std::istream& read(std::istream &in_stream,Sales_data &book);          
    friend std::ostream& print(std::ostream &out_stream,const Sales_data &book); 

    private:
        std::string book_isbn;      
        //in-class initializer is used in default constructor first
        unsigned copies{0};
        double revenue={0.0};

        //inner function, doesn't belong to interface
        double average_price() const {  return copies ? revenue/copies : 0.0; }

    public:

        //Do the work of in-class initializer
        //Sales_data():copies(0),revenue(0.0){ std::cout<<"Default initialization"<<std::endl; }

#ifndef DELEGATING
        //synthesized the default constructor
        Sales_data()=default;

        //explicit conversion constructor test
        //explicit Sales_data(const std::string &b):book_isbn(b){ std::cout<<"explicit"<<std::endl; }
        Sales_data(const std::string &b):book_isbn(b){}
        Sales_data(const std::string &b,unsigned c,double r):book_isbn(b),copies(c),revenue(r){}
        Sales_data(std::istream &in_stream){ read(in_stream,*this); }
#else
        //nondelegating function
        Sales_data(const std::string &b,unsigned c,double r):book_isbn(b),copies(c),revenue(r)
        {std::cout<<"3 args constructor"<<std::endl;}

        //delegating functions
        Sales_data():Sales_data("",0,0.0)
        {std::cout<<"Default constructor"<<std::endl;}

        Sales_data(const std::string &b):Sales_data(b,0,0.0)
        {std::cout<<"1 arg constructor"<<std::endl;}

        Sales_data(std::istream &in_stream):Sales_data()
        {std::cout<<"stream constructor"<<std::endl;  read(in_stream,*this); }
#endif

        //get isbn, const member function
        std::string isbn() const { return book_isbn; }
        //act like += operator,returns a lvalue 
        Sales_data &combine(const Sales_data &rhs);
};

//function declaration
//act like + operator,returns a rvalue
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
//act like << operator
std::ostream& print(std::ostream &out_stream,const Sales_data &book);

#endif


