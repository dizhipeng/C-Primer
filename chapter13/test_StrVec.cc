#include <iostream>
#include <vector>
#include "StrVec.h"
#include "String.h"

using std::cout;
using std::endl;
using std::vector;

int main(int argc,char** argv)
{
    ////test basic allocation
    //StrVec v1;
    //for(size_t i=0;i!=33;++i)
    //{
        //v1.push_back("");
        //cout<<v1<<endl;
    //}

    ////test constructor with initializer_list
    //StrVec v2={"abc","def","ghi"};
    //cout<<v2<<endl;

    ////test copy control
    //{
        //StrVec v3=v1;
        //v3.push_back("");
        //v3.push_back("");
        //cout<<"v3:"<<v3<<endl;

        //v2=v3;
    //}
    //cout<<"v2:"<<v2<<endl;

    ////test advanced interfaces
    //v2.reserve(50);
    //cout<<v2<<endl;
    //v2.reserve(20);
    //cout<<v2<<endl;

    //v2.resize(10);
    //cout<<v2<<endl;
    //v2.resize(60);
    //cout<<v2<<endl;
    //v2.resize(0);
    //cout<<v2<<endl;
    //v2.resize(20);
    //cout<<v2<<endl;

    //test String class
    String s1="Hello, world";
    String s2=s1;
    String s3;
    s1="Bonjour, monde";
    s3=s2;
    s3=s3;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;


    cout<<"vector<String> push_back test:"<<endl;
    vector<String> v1;
    for(size_t i=0;i<10;++i)
    {
        cout<<"Calling push_back() "<<i+1<<" times."<<endl;
        v1.push_back("1");
    }

    return EXIT_SUCCESS;
}
