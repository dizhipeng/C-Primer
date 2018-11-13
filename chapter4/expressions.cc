#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{

    vector<int> vec;

    cout<<"vector elements: ";
    for(unsigned i=1;i<=10;++i)
    {
        vec.push_back(i*(i%2||i>6?1:-1));        
        cout<<*(vec.cend()-1)<<' ';         //print the new element
    }

    cout<<endl<<"precedence of * . and ()  :"<<*vec.begin()+1<<endl;

    //arithmatic operation
    cout<<"arithmatic operation: ";
    cout<<5+10*20/2<<' '
        <<12/3*4+5*15+24%4/2<<' '
        <<-30*3+21/5<<' '
        <<-30+3*21/5<<' '
        <<30/3*21%5<<' '
        <<-30/3*21%4<<endl;

    cout<<"odd or even in vec: ";
    for(const auto &i:vec)
    {
        if(i%2==0)
        {
            cout<<"e ";
        }
        else
        {
            cout<<"o ";
        }
    }
    cout<<endl;

    //logical&relational operation
    cout<<"Enter numbers, 42 to stop: ";
    int val=0;

    return 0;
}
