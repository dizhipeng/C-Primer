#include <iostream>

using std::cout;
using std::endl;

int main()
{
    //typedef declaration
    typedef int INT,*INT_PTR;
    INT var=20;
    INT_PTR var_ptr=&var;
    cout<<"typedef test: "<<var<<' '<<*var_ptr<<endl;

    //using declaration
    using DOUBLE = double;
    using DOUBLE_PTR = double*;
    DOUBLE dou = 3.1416;
    DOUBLE_PTR dou_ptr = &dou;
    cout<<"def test: "<<dou<<' '<<*dou_ptr<<endl;
    
    //pointer alias with const is a const pointer, not a pointer to const
    const DOUBLE_PTR db_ptr=&dou;
    double nature = 2.71828;
    *db_ptr = nature;
    cout<<"const of pointer alias: "<<dou<<endl;
//  db_ptr = &nature;

    //auto keyword test
    auto dedu_int=300,*dedu_int_ptr=&dedu_int,&dedu_int_ref=dedu_int;   //Initializer must be consistent
    auto dedu_dou=dou,*dedu_dou_ptr=&dou,&dedu_dou_ref=dedu_dou;
    cout<<"auto type: "<<dedu_int_ref<<' '<<*dedu_int_ptr<<' '<<dedu_dou_ref<<' '<<*dedu_dou_ptr<<endl;

    const int ci=var,&cr=ci;
    auto a1=ci,a2=cr;    //top-level const is ignored. As initializer, ref is equivalent to its biding object
    auto b1=&var;
    auto c1=&ci;         //low-level const is kept
    const auto c2=&var;  //Add const before auto to achieve top-level const
    auto &d1=ci;         //ref is const when its binding object is const
    ++a1;
    ++a2;
    ++(*b1);
    c1=dedu_int_ptr;    //top-level nonconst
//  ++(*c1);            //low-level const
//  c2=c1;              //top-level const
    ++(*c2);            //low-level nonconst
//  ++d1;
    cout<<"auto const: " <<a1<<' '<<a2<<' '<<*b1<<' '<<*c1<<' '<<*c2<<endl;

    //Both low-level & top-level const is kept
    decltype(c1) decl_c1;               //const int*
    decltype(c2) decl_c2=&var;          //int *const
    decltype(d1) decl_d1=500;           //const int&, can bind to a literal

    //varibale in () will generate ref type
    decltype((var)) decl_var1=var; //int&
    decltype(var) decl_var2;            //int

    decl_c1=&var;
//  ++(*decl_c1);
    ++(*decl_c2);
    ++(decl_var1);
    decl_var2=decl_d1;
    cout<<"decltype: "<<*decl_c1<<' '<<decl_var1<<' '<<decl_var2<<endl;

    return 0; 
}
