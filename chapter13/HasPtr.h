#ifndef HAS_PTR_H
#define HAS_PTR_H

#include <string>
#include <iostream>

#define POINTER_LIKE

class HasPtr
{
    friend std::ostream& print(std::ostream &out,const HasPtr &h);
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    public:
        HasPtr()=default;
        HasPtr(const std::string &s):ps(new std::string(s)){}
        HasPtr(const HasPtr &hp);
        HasPtr& operator=(const HasPtr &rhs);
        ~HasPtr();
        std::string getStr() const {return *ps;}
        //HasPtr& setString(const std::string &s){*ps=s;return *this;}
        //string getString(const std::string &s){*ps=s;return *this;}
    private:
        std::string *ps=new std::string();
        int i=0;
#ifdef POINTER_LIKE
        unsigned *num=new unsigned(1);
#endif

};

std::ostream& print(std::ostream &out,const HasPtr &h);

//swap function should be inline, and takes two reference
//definition of inline function should be in header files
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    //do not call std::swap(), but write using std::swap
    using std::swap;

    //call swap member-wise
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
#ifdef POINTER_LIKE
    swap(lhs.num,rhs.num);
#endif
    std::cout<<"swap"<<std::endl;
}

#endif
