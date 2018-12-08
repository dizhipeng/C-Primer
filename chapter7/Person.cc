#include <iostream>
#include "Person.h"

using std::istream;
using std::ostream;

istream& read(istream &in_stream,Person &p)
{
    in_stream>>p.name>>p.address;
    return in_stream;
}

ostream& print(ostream &out_stream,const Person &p)
{
    out_stream<<"Person name="<<p.name<<", address="<<p.address;
    return out_stream;
}
