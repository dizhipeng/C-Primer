#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s1,s2;

    cin>>s1;            //ignore leading whitespace, stops before the first whitespace
    getline(cin,s2);    //read the newline character
    getline(cin,s2);    //read the next whole line

    cout<<s1<<endl;
    cout<<s2<<endl<<endl;

    string s3("Hello"),s4="Hallo,welt!";
    cout<<"s3: "<<s3<<"\ts4: "<<s4<<endl;
    cout<<((s3<s4)?"s3 is smaller than s4":"s3 is bigger than s4")<<endl;                   //string compare
    cout<<((s3.size()<s4.size())?"s3 is shorter than s4":"s3 is longer than s4")<<endl;     //string length compare

    s2="";
    while(cin>>s1)
    {
        s2+=s1+' ';     //adding character and concatenating string
    }
    cout<<s2;

    auto str_size=s2.size();                //str_size has the type string::size_type
    cout<<str_size<<" characters"<<endl;

    for(auto &c:s4)     //ranged for(declaration:expression), must use ref to change the sequence
    {
        c=toupper(c);   //change the current letter to upper case
    }
    cout<<"Change to upper case: "<<s4<<endl;

    s3+=",Er..."+s4;
    cout<<"Origin: "<<s3<<endl;
    s4="";
    for(decltype(s3.size()) i=0; i<s3.size() ;++i)        //index must have type string::size_type, and must 0<i<.size()
    {
        if(!ispunct(s3[i]))
        {
           s4+=s3[i];
        }
    }
    cout<<"Remove punctuation: "<<s4<<endl;

    cout<<string{'t','e','m','p','1'}<<string("temp2")<<endl;   //temp string

    return 0;
}
