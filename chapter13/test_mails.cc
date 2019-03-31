#include <iostream>
#include "Message.h"
#include "Folder.h"

using std::cout;
using std::endl;

int main(int argc,char **argv)
{
    
    Folder f1("mailbox 1"),f2("mailbox 2"),f3("mailbox 3");
    Message m1("mail 1"),m2("mail 2");

    cout<<"Step 1:"<<endl;
    print_messages(cout,f1)<<endl;
    print_messages(cout,f2)<<endl;
    print_messages(cout,f3)<<endl;

    //test interface
    m1.add(f1);
    m1.add(f2);
    m1.add(f3);
    m1.remove(f2);

    cout<<"Step 2:"<<endl;
    print_messages(cout,f1)<<endl;
    print_messages(cout,f2)<<endl;
    print_messages(cout,f3)<<endl;

    //test operator=
    m2=m1;
    cout<<"Step 3:"<<endl;
    print_messages(cout,f1)<<endl;
    print_messages(cout,f2)<<endl;
    print_messages(cout,f3)<<endl;

    //test copy constructor
    Message m3=m2;
    cout<<"Step 4:"<<endl;
    print_messages(cout,f1)<<endl;
    print_messages(cout,f2)<<endl;
    print_messages(cout,f3)<<endl;

    //make changes
    m2.remove(f1);
    m2.add(f2);
    m3.remove(f3);
    cout<<"Step 5:"<<endl;
    print_messages(cout,f1)<<endl;
    print_messages(cout,f2)<<endl;
    print_messages(cout,f3)<<endl;

    //test swap
    swap(m2,m3);
    cout<<"Step 6:"<<endl;
    print_messages(cout,f1)<<endl;
    print_messages(cout,f2)<<endl;
    print_messages(cout,f3)<<endl;


    return EXIT_SUCCESS;
}
