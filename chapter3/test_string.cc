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

    return 0;
}
