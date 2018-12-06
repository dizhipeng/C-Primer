#include <iostream>
#include <vector>
#include <cassert>
#include "Chapter6.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::vector;

string test_arr[10];
decltype((test_arr)) ret_arr4(string (&arr)[10])    //decltype generants string (&)[10] because of the (()) in it
{
    return arr;
}

int main()
{
    compute_fac();

    cout<<"absolute value test: ";
    for(int i=-4;i<=4;++i)
    {
        cout<<absolute(i)<<" ";
    }
    cout<<endl;

    //local static variable test
    cout<<"Call function 10 times: ";
    for(int i=0;i!=10;++i)
    {
        cout<<count_call()<<" ";
    }
    cout<<endl;

    int a1=5,a2=10;
    cout<<"swap two ints: ";
    cout<<"("<<a1<<","<<a2<<") ";
    swap_ints(&a1,&a2);                 //passed by value, pointer
    cout<<"("<<a1<<","<<a2<<") ";
    swap_ints(a1,a2);                   //passed by reference
    cout<<"("<<a1<<","<<a2<<") ";

    const string &cs="ABCD";            //bound literal char[] to const string
    cout<<endl<<cs<<endl;

    cin.clear();
    string s1;
    cout<<"Enter a string: ";
    cin>>s1;
    cout<<( hasUpper(s1)<0 ? "No upper case letters" : "It exists upper case letter")<<endl
        <<"Change string to upper case: "<<toUpper(s1)<<endl;
    //cout<<hasUpper(s1)<<endl; 

    int i1=100,i2=200;
    const int *p1=&i1,*p2=&i2;

    swap_int_ptr(p1,p2);
    cout<<"Swap two pointers(not the object pointed by the pointers: "<<*p1<<*p2<<endl;

    //arrary as parameter
    int arr[]={2,5,6,7,1,9};   
    cout<<"print array by begin/end: "; 
    print_arr(begin(arr),end(arr));
    cout<<"print array by size: "; 
    print_arr(arr,sizeof arr/sizeof *arr);

    //initializer_list test
    cout<<"Add elements: "<<cal_arr('a',{2,5,6,7,1,9})<<endl;
    cout<<"Multiply elements: "<<cal_arr('m',{2,5,6,7,1,9})<<endl;

    cout<<"recursively print vector:"<<endl;
    vector<int> vec(begin(arr),end(arr));
    print_vec(vec.cbegin(),vec.cend());
    cout<<endl;

    //return poiter/reference to arrays
    string str_arr[10];

    //reference returned from function is an lvalue
    //str_arr is not converted to &str_arr[0], but the array itself when the parameter is a reference to array
    ret_arr1(str_arr)[0]="abcdef";
    ret_arr2(str_arr)[1]="defgh";           
    ret_arr3(str_arr)[2]="ghij";
    ret_arr4(str_arr)[3]="jkl";


    cout<<"Test reference to array as parameter: ";
    for(const auto &s:str_arr)
    {
        cout<<s<<" ";
    }

    cout<<endl;

    cout<<"Calling overloading functions: ";
    //overload & matching
    //f(2.56,42);           //ambiguous
    f(5.6);
    f(42);
    f(42,0);
    f(2.56,3.14);
    cout<<endl;

    cout<<"Default argument for plural: "; 
    cout<<make_plural(2,"failure")<<" "<<       //failure uses default ending 's'
        make_plural(2,"success","es")<<endl;    //success uses ending 'es'

    cout<<"isShorter function is inline: "<<(isShorter("Shorter string","Longer than shorter string") ? "shorter" : "longer" )<<endl;

    //test whether constexpr function returns a constexpr
    constexpr size_t arr_sz=compute_arr_size(sizeof arr,sizeof *arr);       //sizeof operator generates constexpr, guarantees the constexpr functions return constexpr
    constexpr size_t str_arr_sz=compute_arr_size(sizeof str_arr,sizeof *str_arr); 
    cout<<"arr has: "<<arr_sz<<" elements"<<endl;
    cout<<"str_arr has: "<<str_arr_sz<<" elements"<<endl;

    //cout<<"Argument that is not a constexpr will let constexpr function return a non constexpr value: ";
    //size_t sz1=0;
    //cin.clear();
    //cin>>sz1;
    //constexpr size_t test_sz=compute_arr_size(sz1,1);       //constexpr check will fail

    cout<<"plein ref shorter string: "<<shorterString(str_arr[0],str_arr[1])<<endl;
    cout<<"const ref shorter string: "<<shorterString(const_cast<const string&>(str_arr[2]),const_cast<const string&>(str_arr[3]))<<endl;

    cout<<"Debug information: "
        <<"calling "<<__func__
        <<", in file "<<__FILE__
        <<", at line "<<__LINE__
        <<", compiled at "<<__TIME__<<" "<<__DATE__<<endl;

#ifndef NDEBUG
    cout<<endl<<"If NDEBUG is not defined, the programe will now aborted because of assert(0)"<<endl;
#endif

    //fuction pointer test
    vector<int (*)(int,int)> vec_fun1(10);      //write a function pointer type directly

    //declare a function
    int fun(int,int);
    vector<decltype(fun)*> vec_fun2(10);        //using decltype to get a function type, then turn it to pointer by adding *

    using FUN=int (int,int);                //using alias to declare a function type, or a function pointer type
    using FUNP=int (*)(int,int);
    vector<FUN*> vec_fun3(10);
    vector<FUNP> vec_fun4(10);

    cout<<"test the function pointer type..."<<(vec_fun1[0]=vec_fun2[0]=vec_fun3[0]=vec_fun4[0])<<"k"<<endl;

    auto beg=vec_fun1.begin();
    *beg++ = add_fun;                       //function is converted to function pointer
    *beg++ = substract_fun;
    *beg++ = multiply_fun;
    *beg++ = divide_fun;

    cout<<"Calling a op b, where op is +,-,*,/: ";
    for(auto fun:vec_fun1)
    {
        if(nullptr!=fun)
        {
            cout<<fun(8,2)<<" ";        //function pointer is converted to function
        }
    }
    cout<<endl;

    assert(0);

    return EXIT_SUCCESS;    //machine independent
}
