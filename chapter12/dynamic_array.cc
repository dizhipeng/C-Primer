#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <cstring>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::allocator;
using std::vector;

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
    cout<<"string concat: ";
    auto cp1=concat_cp("hello"," world");
    auto cp2=concat_str("bonjour"," monde");

    cout<<cp1<<" -> "<<cp2<<endl;

    delete [] cp1;
    delete [] cp2;

    ifstream ifs1("integers");
    if(!ifs1)
    {
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }

    size_t cp_pos=0,cp_len=10;
    char *cp3=new char[cp_len]();
    char ctemp;
    while(ifs1>>ctemp)
    {
        //dynamic char[] size is not enough, doubles the space allocated
        if(cp_pos+1>=cp_len)
        {
            //allocate new space, copy the content
            cp_len*=2;
            auto cp4=new char[cp_len]();
            memcpy(cp4,cp3,cp_pos);

            //free old space, replace with the new one
            delete [] cp3;
            cp3=cp4;

            cout<<"allocating new memory..."<<endl;
        }

        //save the new char
        cp3[cp_pos++]=ctemp;
    }

    ifs1.close();
    cout<<"input saved in dynamic char[]: "<<cp3<<endl;

    vector<string> vs={"hello","wordl","bonjour","monde"};
    allocator<string> as;
    size_t len=6;

    //top-level const to ensure the pointer will always point to head of the array 
    //only allocate dynamic array without construction
    string *const beg_al=as.allocate(len);

#ifdef LOOP_CONSTRUCT
    auto beg_v=vs.cbegin();
    //construct elements one by one
    for(auto curr=beg_al;curr!=beg_al+len;++curr)
    {
        if(beg_v!=vs.cend())
        {
            as.construct(curr,*beg_v++);
        }
        else
        {
            as.construct(curr,"<empty>");
        }
    }
#else
    //construct elements using copy/fill algorithms
    uninitialized_copy(vs.cbegin(),vs.cend(),beg_al);
    uninitialized_fill(beg_al+vs.size(),beg_al+len,"<empty>");
#endif

    //print the result
    for(auto curr=beg_al;curr!=beg_al+len;++curr)
    {
        cout<<*curr<<" ";
    }
    cout<<endl;

    //destruct elements
    for(auto curr=beg_al+len;curr!=beg_al;)
    {
        as.destroy(--curr);
    }
    
    //free the allocated memory
    as.deallocate(beg_al,len);

    return EXIT_SUCCESS;
}
