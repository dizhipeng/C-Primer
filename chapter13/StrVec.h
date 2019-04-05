#ifndef STR_VEC_H
#define STR_VEC_H

#include <iostream>

class StrVec
{
    friend std::ostream& operator<<(std::ostream& out,const StrVec &s);
    public:
        StrVec()=default;

        //copy control
        StrVec(const StrVec &s);
        StrVec& operator=(const StrVec &s);
        ~StrVec();

        //interface
        size_t size() const {return first_free - elements;}
        size_t capacity() const {return cap - elements;}
        void push_back(const std::string &s);
        std::string* begin() const { return elements; }
        std::string* end() const { return first_free; }
    private:
        static std::allocator<std::string> alloc;

        //auxiliary functions
        //guarantees at least 1 (usually more) space is available
        void chk_n_alloc(){ if(first_free==cap){reallocate();} }
        //allocate enough space, then copy elements [b,e) to current vector
        std::pair<std::string*,std::string*> alloc_n_copy
            (const std::string *b, const std::string *e);
        //destruct the vector, free all spaces
        void free();
        //make more space
        void reallocate();

        //important positions for the vector
        std::string *elements = nullptr;
        std::string *first_free = nullptr;
        std::string *cap = nullptr;
};

#endif
