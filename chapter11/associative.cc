#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include "Sales_data.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::set;
using std::multiset;
using std::ifstream;
using std::vector;
using std::list;
using std::istringstream;
using std::pair;
using std::to_string;

//function pointer type
using comp=bool(*)(const Sales_data &b1,const Sales_data &b2);
//function definition that is the previously defined type
bool compareIsbn(const Sales_data &b1,const Sales_data &b2)
{
    return b1.isbn()<b2.isbn();
}

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
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }

    map<string,size_t> word_count;
    set<string> bl={"the","a","oh"};

    string word;
    while(ifs1>>word)
    {
        //only count words not in the blacklist
        if(not_in_black_list(word,bl))
        {
            //increment the count
            //when key does'nt exist, value init to 0 automatically
            ++word_count[word];
        }
    }

    //travers all elements(pairs) in a map using ranged for
    for(const auto &ele:word_count)
    {
        cout<<ele.first<<" appears "<<ele.second<<" time(s) "<<endl;
    }

    map<string,vector<string>> families=
    {{"bovary",{"charles","emma"}},{"meursault",{"mary","raymon"}}};

    //add new pairs
    families["jojo"]={"buccarati","apachio","gioruno"};
    families.insert({"exuperee",{"prince","roi","serpent"}});

    //change values
    families["meursault"].push_back("masson");

    vector<int> vec_int={3,4,5,5,4,3,2,1,1,3,2};

    //set elements are ordered and unique
    set<int> set_int(vec_int.cbegin(),vec_int.cend());
    vector<int> mimic_set;

    //insert the first element
    mimic_set.push_back(*vec_int.cbegin());
    //insert unique elements in ascending order
    for(const auto &ele:vec_int)
    {
        auto it=find_if(mimic_set.begin(),mimic_set.end(),
                [ele](int e){return ele<=e;});

        //not find
        if(it==mimic_set.end() || *it!=ele)
        {
            mimic_set.insert(it,ele);
        }
    }

    cout<<"elements in set: ";
    for(const auto &ele:set_int)
    {
        cout<<ele<<" ";
    }

    cout<<endl<<"elements in vector acts as a set: ";
    for(const auto &ele:mimic_set)
    {
        cout<<ele<<" ";
    }

    list<int> ls={3,4};
    //list<int>::iterator doesn't have < operator
    //so it can't be keys
    //map<list<int>::iterator,int> list_map={{ls.begin(),*ls.begin()}};

    vector<int> vs={3,4};
    //vector iterator is allowed to be keys
    map<vector<int>::iterator,int> vector_map={{vs.begin(),*vs.begin()}};

    ifs1.close();
    ifstream ifs2("words");
    if(!ifs2)
    {
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }

    map<string,list<int>> lines;
    string line;
    size_t line_num=1;
    while(getline(ifs2,line))
    {
        istringstream sstrm(line);

        while(sstrm>>word)
        {
            if(not_in_black_list(word,bl))
            {
                //record line number associated with the word
                lines[word].push_back(line_num);
            }
        }
        ++line_num;
    }

    for(auto &ele:lines)
    {
        cout<<endl<<ele.first<<" appears at line: ";

        ele.second.unique();
        for(auto nu:ele.second)
        {
            cout<<nu<<", ";
        }
        cout<<"\b\b ";
    }

    //function pointer type in <>
    //function pointer as initializer in ()
    multiset<Sales_data,comp> books(compareIsbn);

    ifstream ifs3("pairs");
    if(!ifs3)
    {
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }

    vector<pair<string,int>> vec_pair;
    int num;
    while(ifs3>>word && ifs3>>num)
    {
        //three ways to create a pair
        //vec_pair.push_back(pair<string,int>(word,num));
        //vec_pair.push_back(make_pair(word,num));
        vec_pair.push_back({word,num});
    }

    cout<<endl<<"pairs in vector: ";
    for(const auto &ele:vec_pair)
    {
        cout<<"("<<ele.first<<","<<ele.second<<"), ";
    }
    cout<<"\b\b ";

    map<string,vector<pair<string,string>>> more_fam;
    for(const auto &ele:families)
    {
        for(const auto &name:ele.second)
        {
            auto info=find_if(vec_pair.cbegin(),vec_pair.cend(),
                    [name](const pair<string,int> &p){return p.first==name;});

            if(info!=vec_pair.cend())
            {
                more_fam[ele.first].push_back({name,to_string(info->second)});
            }
            else
            {
                more_fam[ele.first].push_back({name,""});
            }
        }
    }

    for(const auto &ele:more_fam)
    {
        cout<<endl<<"family "<<ele.first<<"'s children: ";

        for(const auto &child:ele.second)
        {
            cout<<child.first;
            if(!child.second.empty())
            {
                cout<<"("<<child.second<<")";
            }
            cout<<", ";
        }
        cout<<"\b\b ";
    }

    return EXIT_SUCCESS;

}
