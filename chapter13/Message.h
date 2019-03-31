#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message &lhs,Message &rhs); 
    friend std::ostream& print_messages(std::ostream &out, const Folder &f);
    //friend std::ostream& print_folders(std::ostream&, const Message &m);
    public:
        //constructor
        Message(const std::string &str):content(str){}

        //copy control
        Message(const Message &m);
        Message& operator=(const Message &m);
        ~Message();

        //interfaces
        void add(Folder &f);
        void remove(Folder &f);

    private:
        //message content
        std::string content="mail 3";
        //folders that this message is in
        std::set<Folder *> folders;

        //auxiliary functions, modify the state of folders
        void add_to_folder(const Message &m);
        void remove_from_folder();

        void addFld(Folder *f);
        void remFld(Folder *f);
};

inline void swap(Message &lhs,Message &rhs)
{
    lhs.remove_from_folder();
    rhs.remove_from_folder();

    using std::swap;
    //swap(lhs.content,rhs.content);
    swap(lhs.folders,rhs.folders);

    lhs.add_to_folder(lhs);
    rhs.add_to_folder(rhs);
}
#endif 
