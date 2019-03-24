#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>
//#include "StrBlobPtr.h"

class StrBlob
{
    friend class StrBlobPtr;

    public:
        //size & index type
        using size_type=std::vector<std::string>::size_type;
        //make_shared allocates dynamic memory
        //and initialize it using args in ()
        StrBlob():data(std::make_shared<std::vector<std::string>>()){};
        StrBlob(std::initializer_list<std::string> li):
            data(std::make_shared<std::vector<std::string>>(li)){};
        std::ostream& print(std::ostream &out) const;
        void push_back(const std::string &s);
        void pop_back();
        std::string &front();
        std::string &back();
        const std::string &front() const;
        const std::string &back() const;
        size_type size() const;
        bool empty() const;

#ifdef VALUE_LIKE
        //copy control member
        StrBlob(const StrBlob &s):data(std::make_shared<std::vector<std::string>>(*s.data)){}
        StrBlob& operator=(const StrBlob &rhs);
#endif
        ////iterator range
        //StrBlobPtr begin() const;
        //StrBlobPtr end() const;

    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type sz,const std::string &msg) const;
};
#endif
