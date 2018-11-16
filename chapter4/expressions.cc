#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

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
    int val=10;
    vec={};

    cout<<"enter 4 positive ints, 42 to stop: ";
    while(cin>>val && val!=42)
    {
        vec.push_back(val);
    }

    while(vec.size()<4)             //complete vec to have at least 4 elements
    {
        vec.push_back(--val);
    }
    cout<<endl;

    if(vec[0]>vec[1] && vec[1]>vec[2] && vec[2]>vec[3])
    {
        cout<<"we have a>b>c>d"<<endl;
    }
    else
    {
        cout<<"we don't have a>b>c>d"<<endl;
    }

    //test postfix ++
    for(int i=-2;i<=2;++i)
    {   
        val=i;
        bool test=val++&&val;
        cout<<"when val="<<i<<",test val++ && val: "<<test<<endl;
    }

    //test -> 
    cout<<"-> operator yield lvalue?"<<(&vec)->size()<<endl;
    //(&vec)->size()=9;

    vector<vector<int>> vec2={{1,2,3},{},{3,4,5,6}}; 
    auto beg=vec2.cbegin();

    cout<<"test iter++->mem: ";
    while(beg!=vec2.cend())
    {
        cout<<beg++->empty()<<" ";
    }
    cout<<endl;

    //test ?:
    for(val=-2;val<=2;++val)
    {
        const auto &cval=val;
        auto &out=cval>0?cout<<"cval>0":cout<<"cval<=0";
        out<<endl;
    }


    for(auto &i:vec)
    {
        i= i%2 ? i*2 : i;       //double every odd element
    }

    for(const auto &i:vec)
    {
        cout<<i<<' ';
    }
    cout<<endl;

    for(const auto &i:vec)
    {
        cout<<( i>75 
                ? (i>90 ? "high pass" : "pass")
                : (i>=60 ? "low pass" : "fail")
              )<<", ";
    }
    cout<<endl;

    //test bitwise operation
    cout<<"bit operation promotes uchar: ";
    unsigned char byte=0;
    cout<<~byte<<" "<<~0<<endl;      //uchar is promoted to int, thus its value is negative

    const unsigned long qbits = ~'q'<<6;
    unsigned long result = ~0;
    cout<<"bit test: ";
    for(int i=32;i>=0;--i)
    {
        bool bit_test = qbits & 1UL<<i;      //bit test
        if(bit_test)
        {
            result |= 1UL<<i;                //bit set
        }
        else
        {
            result &= ~(1UL<<i);             //bit clear
        }
        cout<<bit_test;
    }
    cout<<(result==qbits ? ", equal" : ", unequal" )<<endl;


    //test sizeof operation
    cout<<"sizeof char: "<<sizeof(char)<<endl;
    cout<<"sizeof short: "<<sizeof(short)<<endl;
    cout<<"sizeof int: "<<sizeof(int)<<endl;
    cout<<"sizeof long: "<<sizeof(long)<<endl;
    cout<<"sizeof long long: "<<sizeof(long long)<<endl;
    cout<<"sizeof built-in pointer: "
        <<sizeof(char*)<<" "
        <<sizeof(short*)<<" "
        <<sizeof(int*)<<" "
        <<sizeof(long*)<<" "
        <<sizeof(long long*)<<endl;

    decltype(&vec) pvec;                                //pointer is uninitialized, can't be dereferenced
    cout<<"vector size and sizeof: "<<vec.size()<<" "
        <<sizeof vec<<" "                               //same as sizeof(vector<int>)
        <<sizeof(vector<int>)<<" "
        <<sizeof(*pvec)<<" "                            //sizeof doesn't eval operand, so *p is legal
        <<sizeof(vector<int>::value_type)<<endl;        //use :: to get the size of a member

    int x[10],*p=x;
    constexpr size_t xs=sizeof(x)/sizeof(*x);           //array size
    constexpr size_t ptrs=sizeof(p)/sizeof(*p);           //sizeof yields type size_t, which is a const expression
    cout<<"array size: "<<xs<<" "<<ptrs<<endl;
    
//    auto cnt = vec.size();
//    for(decltype(vec.size()) ix=0;ix!=vec.size();ix++,cnt--)
//    {
//        vec[ix]=cnt;
//    }
//
//    for(const auto &i:vec)
//    {
//        cout<<i<<" ";
//    }
//
//    cout<<endl;

    //static cast test
    int i=4;
    double d=2.5;
    
//  i*=d;                                   //floating-point multiplication
    i*=static_cast<int>(d);                 //integral multiplication
    cout<<"static_cast to int: "<<i<<endl;

    const string *ps;
    char *pc;
    void *pv;

    pv=const_cast<string*>(ps);
    i=static_cast<int>(*pc);
    pv=static_cast<void*>(&d);
    pc=static_cast<char*>(pv);

    return 0;

}
