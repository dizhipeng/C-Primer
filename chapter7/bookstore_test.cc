#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int amount=1;

    Sales_data total,trans;             //default constructor

    Sales_data is_cstrct(cin);     //constructor that read from istream
    Sales_data one_cstrct("ISBN1");
    Sales_data three_cstrct("ISBN2",30,90);

    cout<<"Test constructors: "<<endl;
    print(cout,is_cstrct)<<endl;
    print(cout,one_cstrct)<<endl;
    print(cout,three_cstrct)<<endl<<endl;

    if(read(cin,total)) //Input is not empty
    {
        while(read(cin,trans))
        {
            if(trans.isbn()==total.isbn())  //The same ISBN
            {
                total.combine(trans); //test combine member function
                ++amount;                   //Increament the transaction number
            }
            else  //Another book, print result
            {
                cout<<"Book of ISBN: " <<total.isbn()
                    <<" has " <<amount <<" transactions."
                    <<endl;
                print(cout,total)<<endl<<endl;      //print returns cout, so << can attached after its call

                total=trans;
                amount=1;   //Clear the amount
            }
        }
        //Print the last record
        cout<<"Book of ISBN: " <<total.isbn()
            <<" has " <<amount <<" transactions."
            <<endl;
        print(cout,total)<<endl;
    }
    else //Input is empty
    {
        cout<<"Input is empty"<<endl;
        return -1;
    }

    return 0; 
}