#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    constexpr size_t arr_size=10;   //array size in [] must be a const expression, array size type is size_t
    int arr1[arr_size]={};           //value init 10 elements

    for(size_t i=0;i<arr_size;++i)  //indexing an array must use variable of size_t
    {
        arr1[i]=i;
    }

    int (*const ptr1_a1)[arr_size]=&arr1;  //const pointer to array
    const int (*ptr2_a1)[arr_size]=&arr1;  //pointer to const array

    int arr2[arr_size]={};          //copy to another array and vector
    int (&r_a2)[arr_size]=arr2;     //ref to array

    //const test
    ++((*ptr1_a1)[0]);
//  ptr1_a1=&arr2;
//  ++((*ptr2_a1)[0]);
    ptr2_a1=&arr2;

    vector<int> v1;
    for(size_t i=0;i<arr_size;++i)
    {
        r_a2[i]=(*ptr1_a1)[i];       //use ref to array and pointer to array
        v1.push_back(arr1[i]);
    }

    cout<<"Copy to arr2: ";
    for(const auto &ele:arr2)
    {
        cout<<ele<<' ';
    }
    cout<<endl;

    decltype(arr1) arr3={};     //decltpype deduces a int[10]
    auto ptr1_a3=arr3;             //auto deduces a ptr to int

    ++*(ptr1_a3+1);
    cout<<"deduced type of array3: "<<arr3[1]<<endl;

    //pointer & iterator of array
    auto beg1_arr1=arr1;
    auto end1_arr1=&arr1[arr_size];      //legal; off-the-end pointer

    auto beg2_arr1=begin(arr1);         //same as before, but looks like an iterator
    auto end2_arr1=end(arr1);           //begin() and end() are in namespace std!!!!

    cout<<"pointer/iterator of elements: ";
    while(beg1_arr1!=end1_arr1)
    {
        ++*beg1_arr1;
        ++beg1_arr1;
    }

    while(beg2_arr1!=end2_arr1)
    {
        cout<<*beg2_arr1<<' ';
        ++beg2_arr1;
    }
    cout<<endl;

    auto ptr_idx=*ptr2_a1+8;     //low-level const is kept, *ptr2_a1 to get arr1
    cout<<"negative index: "<<ptr_idx[-3]<<endl;     //negative index is allowed if point to an element or off-the-end

    return 0;
}
