#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Conversion test
    unsigned u=10,u2=42;
    cout<<u2-u<<endl;
    cout<<u-u2<<endl;

    int i=10,i2=42;
    cout<<i2-i<<endl;
    cout<<i-i2<<endl;
    cout<<i-u<<endl;
    cout<<u-i<<endl;
    cout<<endl;

    //Literal test
    cout<<sizeof('a')<<endl;    //char
    cout<<sizeof(L'a')<<endl;   //wchar_t
    cout<<sizeof("a")<<endl;    //char[]
    cout<<sizeof(L"a")<<endl;   //wchar_t
    cout<<endl;

    cout<<sizeof(10)<<endl;     //int
    cout<<sizeof(10u)<<endl;    //unsigned int
    cout<<sizeof(10L)<<endl;    //long
    cout<<sizeof(10uL)<<endl;   //unsigned long
    cout<<sizeof(012)<<endl;    //int
    cout<<sizeof(0xC)<<endl;    //int
    cout<<endl;

    cout<<sizeof(3.14)<<endl;   //double
    cout<<sizeof(3.14f)<<endl;  //float
    cout<<sizeof(3.14L)<<endl;  //long double
    cout<<endl;

    cout<<sizeof(10)<<endl;     //int
    cout<<sizeof(10u)<<endl;    //unsigned int
    cout<<sizeof(10.)<<endl;    //double
    cout<<sizeof(10e-2)<<endl;  //double
    cout<<endl;
   
    cout<<"F\145rgus?\012"<<endl; //char[]
    cout<<sizeof(3.14e1L)<<endl;  //long double
//  cout<<sizeof(1024f)<<endl;    //error
    cout<<sizeof(3.14L)<<endl;    //long double

//  int a={1.1},b{2.2};         //error, list init doesn't allow precision loss
//  cout<<a<<' '<<b<<endl;

    return 0; 
}
