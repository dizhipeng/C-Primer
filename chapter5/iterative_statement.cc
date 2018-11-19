#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{

    //while loop
    cout<<endl<<"Enter word sequence: ";
    string word;
    string du_word;
    string max_word;
    unsigned du_count=1,max_count=1;
    while(cin>>word)
    {
        if(word==du_word)           //duplicate word
        {
            ++du_count;
            if(du_count>max_count)
            { 
                max_count=du_count;
                max_word=word;
            }
        }
        else                        //new word
        {
            du_count=1;
            du_word=word;
        }
    }

    if(max_count!=1)
    {
        cout<<max_word<<" appears for "<<max_count<<" times"<<endl;
    }
    else
    {
        cout<<"No duplicate words"<<endl;
    }

    //for loop

    return 0;
}
