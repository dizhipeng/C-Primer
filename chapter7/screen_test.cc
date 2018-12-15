#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"
#include "X_Y.h"

using std::cout;
using std::endl;

int main()
{
    //return the object as reference, thus it can be modified successively
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

    Window_mgr a;

    return EXIT_SUCCESS;
}
