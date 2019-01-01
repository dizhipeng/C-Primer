#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void updateStr1(string &s,const string &oldVal,const string &newVal)
{
    //index for the found one
    string::size_type pos=0;

    //find every occurrence
    while((pos=s.find(oldVal,pos))!=string::npos)
    {
#ifndef REPLACE
        //using iterator & insert,erase
        s.erase(s.begin()+pos,s.begin()+pos+oldVal.size());
        s.insert(s.begin()+pos,newVal.begin(),newVal.end());
#else
        //using pos,length & replace
        s.replace(pos,oldVal.size(),newVal);
#endif
        //current position is replaced, proceed to the next
        pos+=newVal.size();
    }
}

int main(int argc,char **argv)
{
    //string initialized from vector of chars
    vector<char> vchar={'a','o','e','h','t','n'};
    string s1(vchar.cbegin(),vchar.cend());

    //reserve member in string class
    s1.reserve(100);

    cout<<"string copied from vector: "<<s1<<endl;

    s1="tho 'tho' and 'thru' looks similar, \
    \b\b\b\bthey are different thru my eyes";

    cout<<s1<<endl;

    updateStr1(s1,"tho","though");
    updateStr1(s1,"thru","through");

    cout<<s1<<endl;
    return EXIT_SUCCESS;

}
