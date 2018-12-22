#include <iostream>
#include <vector>

//iostream isn't enough, specific headers must be included
#include <fstream>
#include <sstream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::ifstream;
using std::vector;
using std::istringstream;
using std::ostringstream;

istream& print(istream& istr)
{
    string str;

    //save the state of the stream 
    //and make it valid before using
    const auto state=istr.rdstate();
    istr.clear();

    while(getline(istr,str))
    {
        cout<<str<<endl;
    }

    //reset the state after using
    istr.setstate(state);

    if(state!=istr.rdstate())
    {
        cout<<"setstate() function fails"<<endl;
    }

    return istr;
}

void file_to_vector(const string &fileName,vector<string> &vec)
{
    string str;

    //open a file for input
    ifstream ifstrm(fileName);

    //file stream must be check after open
    if(!ifstrm)
    {
        cerr<<"File open fails"<<endl;
        return;
    }

    while(getline(ifstrm,str))       //a line an element
    //while(ifstrm>>str)             //a word an element
    {
        vec.push_back(str);
    }

}

struct PersonInfo
{
    string name;
    vector<string> phone;
};

string &format(string &s)
{
    s="010-"+s;
    return s;
}

bool wrong_number(const string &s)
{
    return s.size() != 10;
}

int main(int argc,char **argv)
{

    vector<string> lines;
    istringstream isstrm;
    string tmp;

    if(argc<2)
    {
        cerr<<"Too few command arguments"<<endl;
        return EXIT_FAILURE;
    }

    //the last argument as the file name
    file_to_vector(argv[1],lines);
    
    for(const auto &aline:lines)
    {
        //copy a line to string stream
        isstrm.str(aline);

        //if the string stream is defined here, its constructor can be used
        //and clear() at the end can be omitted

        //extract each word from the string stream
        while(isstrm>>tmp)
        {
            cout<<tmp<<endl;
        }

        isstrm.clear();
    }

    isstrm.str("Print a string stream");
    print(isstrm);

    //test whetch print() function restore the state
    if(!isstrm)
    {
        cout<<"string stream is invalid"<<endl;
    }

    //PersonInfo test
    ifstream ifstrm(argv[1]);

    if(!ifstrm)
    {
        cerr<<"File open fails"<<endl;
        return EXIT_FAILURE;
    }

    vector<PersonInfo> contact;

    while(getline(ifstrm,tmp))
    {
        PersonInfo person;
        
        //define a local stream every time a line is read
        istringstream lisstrm(tmp);

        //the first substring is name
        lisstrm>>person.name;

        //the rest substrings are phones
        while(lisstrm>>tmp)
        {
            person.phone.push_back(tmp);
        }

        //add this person to contact
        contact.push_back(person);

    }
    

    for(const auto &p:contact)
    {
        ostringstream valid,invalid;

        for(const auto &n:p.phone)
        {
            if(wrong_number(n))
            {
                invalid<<n;
            }
            else
            {
                valid<<" "<<format(n);
            }
        }
    }

    return EXIT_SUCCESS;
}
