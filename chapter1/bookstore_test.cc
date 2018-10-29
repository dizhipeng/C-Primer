#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item trans,total;
    int amount=1;

    if(cin>>total) //Input is not empty
    {
        while(cin>>trans)
        {
            if(trans.isbn()==total.isbn())  //The same ISBN
            {
                total+=trans;   //Sales_item object supports add operation
                ++amount;       //Increament the transaction number
            }
            else  //Another book, print result
            {
                cout<<"Book of ISBN: "
                    <<total.isbn()
                    <<" has "
                    <<amount
                    <<" transactions."
                    <<endl
                    <<"The sum of this books sold is: "
                    <<endl
                    <<total
                    <<endl<<endl;

                total=trans; //Update the current record
                amount=1;   //Clear the amount
            }
        }
        //Print the last record
        cout<<"Book of ISBN: "
            <<total.isbn()
            <<" has "
            <<amount
            <<" transactions."
            <<endl
            <<"The sum of this books sold is: "
            <<endl
            <<total
            <<endl;
    }
    else //Input is empty
    {
        cout<<"Input is empty"<<endl;
        return -1;
    }
   
    return 0; 
}
