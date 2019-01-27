#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <set>
#include <vector>
#include <memory>
#include <iostream>

class QueryResult
{
    friend std::ostream& print(std::ostream &out,const QueryResult &qr);

    public:
        QueryResult(const std::string &w,
        std::shared_ptr<std::vector<std::string>> l,
        std::shared_ptr<std::set<size_t>> n):word(w),lines_ptr(l),nums_ptr(n){}
        std::set<size_t>::iterator begin() const {return nums_ptr->begin();}
        std::set<size_t>::iterator end() const {return nums_ptr->end();}
        std::shared_ptr<std::vector<std::string>> get_file() const {return lines_ptr;}
    private:
        std::string word;
        std::shared_ptr<std::vector<std::string>> lines_ptr;
        std::shared_ptr<std::set<size_t>> nums_ptr;
};

std::ostream& print(std::ostream &out,const QueryResult &qr);

#endif
