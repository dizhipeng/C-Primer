#include <iostream>
#include "Person.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Person one,another,third("jojo","Naples"),forth("boss");

    read(read(cin,one),another);
    print(print(print(print(cout,one)<<endl,another)<<endl,third)<<endl,forth)<<endl;

    return EXIT_SUCCESS;
}



