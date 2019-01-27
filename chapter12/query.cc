#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

#ifndef NONE_CLASS
#include "TextQuery.h"
#endif

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::vector;
using std::istringstream;

bool not_in_black_list(string &word,const set<string> &bl)
{
    //using generic algorithm tranform to 
    //change every letter in the string to lower case
    transform(word.cbegin(),word.cend(),word.begin(),tolower);

    //remove and erase every punctuation
    word.erase(remove_if(word.begin(),word.end(),ispunct),word.end());

    //use set's find() member, rather than the generic one
    return bl.find(word)==bl.end();
}

int main(int argc,char **argv)
{
    ifstream ifs1("words");
    if(!ifs1)
    {
        cerr<<"Open input file failed"<<endl;
        return EXIT_FAILURE;
    }

    string word;
#ifdef NONE_CLASS
    //save each line of the file into vector
    vector<string> lines;
    string line;
    while(getline(ifs1,line))
    {
        //pre-process every line before saving
        not_in_black_list(line,set<string>());
        lines.push_back(line);
    }
    ifs1.close();

    //save every word and the lines where it appears in the map
    map<string,set<size_t>> record;
    size_t num=0;
    for(const auto &ele:lines)
    {
        istringstream iss(ele);

        //cut line into word
        while(iss>>word)
        {
            //for any word, record current line number in the set
            //if already in the set, insertion will fail, thus ensure it's unique
            record[word].insert(num);
        }
        //proceed next line, increament line number
        ++num;
    }

    //query the word entered from cin
    cout<<"Enter the word to query: ";
    while(cin>>word)
    {
        auto it=record.find(word);
        if(it!=record.end())
        {
            cout<<word<<" appears "<<it->second.size()<<" time(s)."<<endl;
            for(auto num:it->second)
            {
                cout<<"line "<<num+1<<" : "<<lines[num]<<endl;
            }
        }
        else
        {
            cout<<word<<" never appears."<<endl;
        }
    }
#else
    TextQuery tq(ifs1);

    cout<<"Enter the word to query: ";
    while(cin>>word)
    {
#ifndef QUERY_MEMBER_TEST
        print(cout,tq.query(word));
#else
        auto qr=tq.query(word);
        for(auto p=qr.begin();p!=qr.end();++p)
        {
            cout<<"line "<<*p+1<<" : "<<(*qr.get_file())[*p]<<endl;
        }
#endif
    }
#endif
    return EXIT_SUCCESS;
}
