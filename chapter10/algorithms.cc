#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Sales_data.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::begin;
using std::end;
using std::equal;
using std::ifstream;

bool isShorter(const string &s1,const string &s2)
{
    return s1.size()<s2.size();
}

bool compareIsbn(const Sales_data &book1,const Sales_data &book2)
{

    string s1=book1.isbn();
    string s2=book2.isbn();
    string::size_type po1=0;
    string::size_type po2=0;

    while(po1!=string::npos || po2!=string::npos)
    {
        //save the tail of the number in the substring into sub_po
        size_t sub_po;
        unsigned n1=0;
        unsigned n2=0;

        //find the next number of isbn1
        po1=s1.find_first_of("0123456789",po1);
        if(po1!=string::npos)
        {
            n1=stoi(s1.substr(po1),&sub_po);
        }
        else
        {
            n1=10;
            sub_po=0;
        }
        po1+=sub_po;

        //find the next number of isbn2
        po2=s2.find_first_of("0123456789",po2);
        if(po2!=string::npos)
        {
            n2=stoi(s2.substr(po2),&sub_po);
        }
        else
        {
            n2=10;
            sub_po=0;
        }
        po2+=sub_po;

        if(n1<n2)
        {
            return true;
        }
        else if(n1>n2)
        {
            return false;
        }
        else
        {
            //compare the next number
        }
    }

    //two isbns are exactly the same 
    return true;
}

//Eliminate all duplicated elements
void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());

    auto end_uni=unique(words.begin(),words.end());

    words.erase(end_uni,words.end());
}

bool longerThanFive(const string &s)
{
    return s.size()>=5;
}

int main(int argc,char **argv)
{
    vector<int> v1={4,6,7,7,8,7,5,4,7,4};
    list<string> l1={"l4","l6","l7","l7","l8"
                    ,"l7","l5","l4","l7","l4"};

    cout<<"test count algorithm: "
        <<count(v1.cbegin(),v1.cend(),7)<<" "
        <<count(l1.cbegin(),l1.cend(),"l4")<<endl;

    cout<<"sum of int elements in v1: "
        <<accumulate(v1.cbegin(),v1.cend(),0)<<endl;

    vector<double> v2={3.4,7.5,4.1,9.1,4.8,2.7,1.9};

    //return type is the same type as the third argument val 
    cout<<"sum of double elements in v2(int initial value): "
        <<accumulate(v2.cbegin(),v2.cend(),0.0)<<endl;

    const char ch1[]="literal string",ch2[]="literal string";
    cout<<"compare whether to const char[] are equal: "
        <<equal(begin(ch1),end(ch1),begin(ch2))<<endl;

    //clear all elements to 0
    fill_n(v1.begin(),v1.size(),0);

    vector<string> words={"qu'est",
                          "ce",
                          "que",
                          "c'est",
                          "que",
                          "ce",
                          "truc",
                          "que",
                          "je",
                          "vois"};
    elimDups(words);

    //stabel_sort keeps the alphabetical order when sorted by length
    //pass the isShorter as the predicate
    stable_sort(words.begin(),words.end(),isShorter);

    auto part_it=partition(words.begin(),words.end(),longerThanFive);

    words.erase(part_it,words.end());

    for(const auto &ele:words)
        cout<<ele<<endl;

    //save all books from ifstream
    ifstream ifstrm("book_sales");

    //test whether file open is ok
    if(!ifstrm)
    {
        cerr<<"File open fails"<<endl;
        return EXIT_FAILURE;
    }

    vector<Sales_data> books;
    Sales_data tmp;
    while(read(ifstrm,tmp))
    {
        books.push_back(tmp);
    }

    books.erase(books.begin(),books.end());
    //sort books as isbn using sort, given a isbn compare predicate
    sort(books.begin(),books.end(),compareIsbn);

    for(const auto &ele:books)
    {
        print(cout,ele)<<endl;
    }

    cout<<endl;
    auto book_it=books.cbegin();
    while(book_it!=books.cend())
    {
        //find the next record with a different isbn
        auto next_isbn=find_if(book_it,books.cend(),
                [book_it](const Sales_data &b){return b.isbn()!=book_it->isbn();});

        //initial value for accumulate is a Sales_data object *book_it
        //accumulate begins at the next object of book_it, ranges [book_it+1,next_isbn)
        //Sale_data doesn't have + operator, a binary operattion must be provided
        auto sum=accumulate(book_it+1,next_isbn,*book_it,
                [](const Sales_data &b1,const Sales_data &b2){return add(b1,b2);});

        print(cout,sum)<<endl;

        //proceed to the next isbn
        book_it=next_isbn;
    }

    return EXIT_SUCCESS;
}
