#include <iostream>
#include <vector>
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

    cout<<"recursively print vector: ";
    vector<int> vec(begin(arr),end(arr));
    print_vec(vec.cbegin(),vec.cend());
    cout<<endl;

    //return poiter/reference to arrays
    string str_arr[10];

    //reference returned from function is an lvalue
    //str_arr is not converted to &str_arr[0], but the array itself when the parameter is a reference to array
    ret_arr1(str_arr)[0]="abc";
    ret_arr2(str_arr)[1]="def";           
    ret_arr3(str_arr)[2]="ghi";
    ret_arr4(str_arr)[3]="jkl";


    cout<<"Test reference to array as parameter: ";
    for(const auto &s:str_arr)
    {
        cout<<s<<" ";
    }

    cout<<endl;

    return EXIT_SUCCESS;    //machine independent
}
