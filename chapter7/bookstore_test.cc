#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int amount=1;

    //default constructor
    Sales_data total,trans;

    Sales_data one_cstrct("ISBN1");
    Sales_data three_cstrct("ISBN2",30,90);

    //constructor that read from istream
    Sales_data is_cstrct(cin);     

    cout<<"Test constructors: "<<endl;
    print(cout,is_cstrct)<<endl;
    print(cout,one_cstrct)<<endl;
    print(cout,three_cstrct)<<endl<<endl;

    //implicit conversion from constructor
    string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    Sales_data item2("9-999-99999-9");

    //Input is not empty
    if(read(cin,total)) 
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
