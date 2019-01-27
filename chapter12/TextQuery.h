#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <vector>
#include <algorithm>
#include "QueryResult.h"

extern bool not_in_black_list(std::string &word,const std::set<std::string> &bl);

class TextQuery
{
    public:
        TextQuery(std::istream &ifs1);
        QueryResult query(const std::string &word) const;
    private:
        //Every part that needs to share should be made shared_ptr
        std::shared_ptr<std::vector<std::string>> lines_ptr;
        std::map<std::string,std::shared_ptr<std::set<size_t>>> record;
};

#endif
