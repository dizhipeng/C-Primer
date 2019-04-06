#include "Employee.h"

unsigned Employee::new_id=0;

Employee& Employee::operator=(const Employee &rhs)
{
    name=rhs.name;
    identifier=new_id++;
    return *this;
}
