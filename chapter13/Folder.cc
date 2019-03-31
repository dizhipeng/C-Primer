#include "Message.h"
#include "Folder.h"

#include <ostream>

using std::ostream;

void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}

//Folder::Folder(const Folder &f):name(f.name),messages(f.messages)
//{

//}

//Folder& Folder::operator=(const Folder &f)
//{

    //return *this;
//}

Folder::~Folder()
{

}

ostream& print_messages(ostream &out, const Folder &f)
{
    if(f.messages.empty())
    {
        out<<f.name<<" is empty";
    }
    else
    {
        out<<f.name<<" has: ";
        for(auto m:f.messages)
        {
            out<<m->content<<", ";
        }
        out<<"\b\b ";
    }
    return out;
}
