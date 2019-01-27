#include "QueryResult.h"

using std::endl;
using std::ostream;
using std::vector;
using std::string;

ostream& print(ostream &out,const QueryResult &qr)
{
    vector<string> &lines=*qr.lines_ptr;

    if(qr.nums_ptr->size())
    {
        out<<qr.word<<" appears "<<qr.nums_ptr->size()<<" time(s)."<<endl;
        for(auto num:*qr.nums_ptr)
        {
            out<<"line "<<num+1<<" : "<<lines[num]<<endl;
        }
    }
    else
    {
        out<<qr.word<<" never appears."<<endl;
    }

    return out;
}
