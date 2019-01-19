#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <memory>
#include "StrBlob.h"
#include "StrBlobPtr.h"

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
using std::weak_ptr;

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

int main(int argc,char **argv)
{
    StrBlob b1;
    {
        StrBlob b2={"a","an","the"};
        //++ref_count
        b1=b2;

        cout<<"b1 and b2 are the same originally: "<<endl<<"b1: ";
        b1.print(cout)<<"  b2: ";
        b2.print(cout)<<endl;

        b2.push_back("about");
        cout<<"call push_back to b1 changes b2 as well: "<<endl<<"b1: ";
        b1.print(cout)<<"  b2: ";
        b2.print(cout)<<endl;

        //--ref_count
    }

    //++ref_count
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

    auto sp1=make_shared<int>(99),sp2=make_shared<int>(150);

    //top-level const weak pointer
    const weak_ptr<int> wp1(sp1);
    cout<<"smart pointer const test: "<<++*wp1.lock()<<" ";

    //low-level const weak pointer
    weak_ptr<const int> wp2(sp1);
    wp2=sp2;
    cout<<*wp2.lock()<<endl;

    //StrBlobPtr & StrBlob test 
    StrBlobPtr p1(b1);
    cout<<p1.deref()<<" ";

    p1.deref()="eht";
    cout<<p1.deref()<<endl;

    return EXIT_SUCCESS;
}
