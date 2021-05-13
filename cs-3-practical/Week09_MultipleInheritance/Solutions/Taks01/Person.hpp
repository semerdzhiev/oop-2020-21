#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
    std::string name;

protected:
    void copy(const char *name);

public:
    Person(const std::string name);

    std::string getName() const;
};

#endif