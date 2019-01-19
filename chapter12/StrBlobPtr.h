#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include "StrBlob.h"

class StrBlobPtr
{
    public:
        //size & index type
        using size_type=std::vector<std::string>::size_type;
        //default constructor has nothing to do, synthetic
        StrBlobPtr()=default;
        //weak pointer points to the object managed by shared pointer
        StrBlobPtr(const StrBlob &sp,size_type i=0):wp(sp.data),index(i){}

        //pointer operations

        //deference get a reference of the element
        std::string& deref() const;

        //increament operator
        StrBlobPtr& incr();
        
    private:
        std::weak_ptr<std::vector<std::string>> wp;
        size_type index=0;
        std::shared_ptr<std::vector<std::string>>
            check(size_type sz,const std::string &msg) const;
};
#endif
