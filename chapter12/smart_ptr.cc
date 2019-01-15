#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <memory>
#include <cstring>
#include "StrBlob.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::istringstream;
using std::to_string;
using std::shared_ptr;
using std::make_shared;
using std::istream;
using std::ostream;

shared_ptr<vector<int>> make_vec()
{
    return make_shared<vector<int>>();
}

vector<int>* new_vec()
{
    return new vector<int>;
}

istream& in_vec(istream &in,vector<int> &vec)
{
    int ele;
    while(in>>ele)
    {
        vec.push_back(ele);
    }

    return in;
}

ostream& out_vec(ostream &out,const vector<int> &vec)
{
    for(auto ele:vec)
    {
        cout<<ele<<" ";
    }

    return out;
}

using connection=string;
using destination=string;

connection connect(destination *dst)
{
    cout<<"connecting to "<<*dst<<endl;
    return connection("open");
}

void end_connection(connection *c)
{
    *c="closed";
    cout<<"connection "<<*c<<endl;
}

char* concat_cp(const char cp1[],const char cp2[])
{
    size_t len1=strlen(cp1),len2=strlen(cp2);

    //allocate memory, must reserve space for '\0'
    char *p=new char[len1+len2+1]();

    strcpy(p,cp1);
    strcat(p,cp2);

    return p;
}

char* concat_str(const string &s1,const string &s2)
{
    return concat_cp(s1.c_str(),s2.c_str());
}

int main(int argc,char **argv)
{
    StrBlob b1;
    {
        StrBlob b2={"a","an","the"};
        b1=b2;

        cout<<"b1 and b2 are the same originally: "<<endl<<"b1: ";
        b1.print(cout)<<"  b2: ";
        b2.print(cout)<<endl;

        b2.push_back("about");
        cout<<"call push_back to b1 changes b2 as well: "<<endl<<"b1: ";
        b1.print(cout)<<"  b2: ";
        b2.print(cout)<<endl;
    }

    const StrBlob b3=b1;
    cout<<"const member function test: "<<b1.back()<<" "<<b3.back()<<endl;

    auto vec_ptr1=make_vec();
    auto vec1=*vec_ptr1;

    auto vec_ptr2=new_vec();
    auto vec2=*vec_ptr2;

    ifstream ifs1("integers");
    if(!ifs1)
    {
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }
    in_vec(ifs1,vec1);
    ifs1.close();

    ifstream ifs2("integers");
    if(!ifs2)
    {
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }
    in_vec(ifs2,vec2);
    ifs2.close();

    cout<<"integers write to vec1: "; 
    out_vec(cout,vec1)<<endl;

    cout<<"integers write to vec2: "; 
    out_vec(cout,vec2)<<endl;

    //when done, dynamic memory allocated from new must be deleted
    delete vec_ptr2;

    destination dst("192.168.4.205");
    connection con=connect(&dst);

    //shared_ptr manage non-dynamic objects using deleter
    {
        shared_ptr<connection> con_ptr(&con,end_connection);
    }

    con=connect(&dst);
    shared_ptr<connection> con_ptr(&con,
            [](connection *c){*c="closed";
            cout<<"connection "<<*c<<endl;});

    cout<<"string concat: ";
    auto cp1=concat_cp("hello"," world");
    auto cp2=concat_str("bonjour"," monde");

    cout<<cp1<<" -> "<<cp2<<endl;

    delete [] cp1;
    delete [] cp2;

    return EXIT_SUCCESS;
}
