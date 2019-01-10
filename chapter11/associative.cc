#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::set;
using std::ifstream;
using std::vector;

int main(int argc,char **argv)
{
    ifstream ifs("words");
    if(!ifs)
    {
        cerr<<"open input file failed"<<endl;
        return EXIT_FAILURE;
    }

    map<string,size_t> word_count;
    set<string> bl={"the","a","oh"};

    string word;
    while(ifs>>word)
    {
        //using generic algorithm tranform to 
        //change every letter in the string to lower case
        transform(word.cbegin(),word.cend(),word.begin(),tolower);

        //remove and erase every punctuation
        word.erase(remove_if(word.begin(),word.end(),ispunct),word.end());

        //only count words not in the blacklist
        //use set's find() member, rather than the generic one
        if(bl.find(word)==bl.end())
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

    for(const auto &ele:families)
    {
        cout<<"family "<<ele.first<<"'s children: ";

        for(const auto &child:ele.second)
        {
            cout<<child<<", ";
        }
        cout<<"\b\b "<<endl;
    }

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

    return EXIT_SUCCESS;
}
