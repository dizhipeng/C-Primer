#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int amount=1;

    Sales_data total,trans;

    //aggregate class test
    //if in-classs initializer is used, there will be error
    Sales_data item={"978-0590353403",25,15.99};

    double price=0.0;

    if(cin>>total.book_isbn>>total.copies>>price) //Input is not empty
    {
        total.revenue=price*total.copies;

        while(cin>>trans.book_isbn>>trans.copies>>price)
        {
            trans.revenue=price*trans.copies;

            if(trans.book_isbn==total.book_isbn)  //The same ISBN
            {
                total.copies+=trans.copies;     //Add copies and revenue of the current transaction
                total.revenue+=trans.revenue;   
                ++amount;       //Increament the transaction number
            }
            else  //Another book, print result
            {
                cout<<"Book of ISBN: "
                    <<total.book_isbn
                    <<" has "
                    <<amount
                    <<" transactions."
                    <<endl
                    <<"The sum of this books sold is: "
                    <<endl
                    <<total.book_isbn<<' '<<total.copies<<' '<<total.revenue<<' '<<total.revenue/total.copies
                    <<endl<<endl;

                total.book_isbn=trans.book_isbn;     //Update the current record
                total.copies=trans.copies;    
                total.revenue=trans.revenue;     
                amount=1;   //Clear the amount
            }
        }
        //Print the last record
        cout<<"Book of ISBN: "
            <<total.book_isbn
            <<" has "
            <<amount
            <<" transactions."
            <<endl
            <<"The sum of this books sold is: "
            <<endl
            <<total.book_isbn<<' '<<total.copies<<' '<<total.revenue<<' '<<total.revenue/total.copies
            <<endl;
    }
    else //Input is empty
    {
        cout<<"Input is empty"<<endl;
        return -1;
    }

    return 0; 
}
