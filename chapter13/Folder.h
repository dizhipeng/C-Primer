#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include <ostream>

class Folder
{
    friend class Message;
    friend std::ostream& print_messages(std::ostream &out, const Folder &f);
    public:
        Folder(std::string n):name(n){}

        //Folder(const Folder &f);
        //Folder& operator=(const Folder &f);

        //prvent copying
        Folder(const Folder &f)=delete;
        Folder& operator=(const Folder &f)=delete;

        //bookkeeping for destructor
        ~Folder();

    private:
        void addMsg(Message *msg);
        void remMsg(Message *msg);
        std::string name;
        std::set<Message *> messages;
};

std::ostream& print_messages(std::ostream &out, const Folder &f);
#endif
