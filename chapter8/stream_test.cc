#include <iostream>
#include <vector>

//iostream isn't enough, fstream must be included to use file stream
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::ifstream;
using std::vector;

istream& print(istream& istr)
{
    string str;

    //save the state of the stream 
    //and make it valid before using
    auto state=istr.rdstate();
    istr.clear();

    while(getline(istr,str))
    {
        cout<<str<<endl;
    }

    //reset the state after using
    istr.setstate(state);

    return istr;
}

void file_to_vector(const string &fileName,vector<string> &vec)
{
    string str;

    //open a file for input
    ifstream ifstr(fileName);

    //file stream must be check after open
    if(!ifstr)
    {
        return;
    }

    while(getline(ifstr,str))       //a line an element
    //while(ifstr>>str)             //a word an element
    {
        vec.push_back(str);
    }

}

int main(int argc,char **argv)
{

    //print(cin);
    vector<string> lines;

    //the last argument as the file name
    file_to_vector(argv[argc-1],lines);
    
    for(const auto &s:lines)
    {
        cout<<s<<endl;
    }

    return EXIT_SUCCESS;
}
