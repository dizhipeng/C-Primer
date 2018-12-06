#ifndef CHAPTER_6_H
#define CHAPTER_6_H
#include <vector>

using ref_string_arr_10=std::string (&)[10];

int absolute(int n);
int factorial(int n);
void compute_fac();
unsigned count_call();
void swap_ints(int *a,int *b);
void swap_ints(int &a,int &b);
int hasUpper(const std::string &str);
std::string &toUpper(std::string &str);
void swap_int_ptr(const int *&p1,const int *&p2);
void print_arr(const int *beg, const int *end);
void print_arr(const int arr[],size_t sz);
int cal_arr(char op,std::initializer_list<int> li);
void print_vec(std::vector<int>::const_iterator beg,std::vector<int>::const_iterator end);
std::string (&ret_arr1(std::string (&arr)[10]))[10];
ref_string_arr_10 ret_arr2(std::string (&arr)[10]);
auto ret_arr3(std::string (&arr)[10])->std::string (&)[10];
void f(int);
void f(int,int);
void f(double,double=3.14);

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending="s");    //default arguments appear in function declaration

const std::string &shorterString(const std::string &s1,const std::string &s2);
std::string &shorterString(std::string &s1,std::string &s2);

//inline & constexpr functions are defined in header files
inline bool isShorter(const std::string &s1,const std::string &s2)
{
    return s1.size()<s2.size(); 
}

constexpr size_t compute_arr_size(size_t arr,size_t element)     //constexpr function is itself inline
{
    return arr/element;      //Only if baseSize is initialized by a constexpr, the return value will be constexpr
}

int add_fun(int a,int b);
int substract_fun(int a,int b);
int multiply_fun(int a,int b);
int divide_fun(int a,int b);
#endif
