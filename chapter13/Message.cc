#include "Message.h"
#include "Folder.h"

using std::ostream;

//add the current message to the folders of m
void Message::add_to_folder(const Message &m)
{
    for(auto f:m.folders)
    {
        f->addMsg(this);
    }
}

//remove the current message from its own folders
void Message::remove_from_folder()
{
    for(auto f:folders)
    {
        f->remMsg(this);
    }
}

Message::Message(const Message &m):/*content(m.content),*/folders(m.folders)
{
    add_to_folder(m);
}

Message& Message::operator=(const Message &m)
{
    remove_from_folder();

    //content=m.content;
    folders=m.folders;

    add_to_folder(m);

    return *this;
}

Message::~Message()
{
    remove_from_folder();
}

void Message::add(Folder &f)
{
    //add the folder pointer to set
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFld(Folder *f)
{
    folders.insert(f);
}

void Message::remFld(Folder *f)
{
    folders.insert(f);
}

//ostream& print_folders(ostream &out, const Message &m)
//{
    //return out;
//}
