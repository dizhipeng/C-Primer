#include "TextQuery.h"
#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::istream;
using std::make_shared;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::istringstream;

TextQuery::TextQuery(istream &ifs1):
lines_ptr(make_shared<vector<string>>())
{
    vector<string> &lines=*lines_ptr;

    string line;
    while(getline(ifs1,line))
    {
        //pre-process every line before saving
        not_in_black_list(line,set<string>());
        lines.push_back(line);
    }

    //save every word and the lines where it appears in the map
    size_t num=0;
    string word;
    for(const auto &ele:lines)
    {
        istringstream iss(ele);

        //cut line into word
        while(iss>>word)
        {
            //if the set is empty, allocate shared memory first
            if(!record[word])
            {
                record[word]=make_shared<set<size_t>>();
            }

            //for any word, record current line number in the set
            //if already in the set, insertion will fail, thus ensure it's unique
            record[word]->insert(num);
        }
        //proceed next line, increament line number
        ++num;
    }
}

QueryResult TextQuery::query(const string &word) const
{
    auto it=record.find(word);
    if(it!=record.end())
    {
        return QueryResult(word,lines_ptr,it->second);
        //const member function's 'this' pointer is const
        //so map member is const, and can't use [] operator
        //return QueryResult(word,lines_ptr,record[word]);
    }
    else
    {
        return QueryResult(word,lines_ptr,make_shared<set<size_t>>());
    }
}
