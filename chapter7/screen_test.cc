#include <iostream>
#include "Screen.h"

using std::cout;
using std::endl;

int main()
{
    Screen front(5,6),back(4,10,'c');

    cout<<front.get()<<" "<<back.get()<<endl;

    return EXIT_SUCCESS;
}
