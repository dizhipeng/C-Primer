#include <iostream>
#include "StrVec.h"

using std::cout;
using std::endl;

int main(int argc,char** argv)
{
    StrVec v1;
    for(size_t i=0;i!=33;++i)
    {
        v1.push_back("");
        cout<<v1<<endl;
    }

    StrVec v2=v1;
    {
        StrVec v3=v1;
        v3.push_back("");
        v3.push_back("");
        cout<<"v3:"<<v3<<endl;

        v2=v3;
    }
    cout<<"v2:"<<v2<<endl;

    return EXIT_SUCCESS;
}
