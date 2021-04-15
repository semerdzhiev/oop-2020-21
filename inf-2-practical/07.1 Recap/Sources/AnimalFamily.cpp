#include <iostream>
#include <cstring>
#include "../Headers/AnimalFamily.hpp"

AnimalFamily::AnimalFamily(const char *_name, unsigned _members) : members(_members), nameLen(strlen(_name) + 1)
{
    std::cout << "Animal created" << std::endl;
    name = new char[nameLen];
    strcpy(name, _name);
}

AnimalFamily::AnimalFamily(const AnimalFamily &other) : members(other.members)
{
    name = new char[other.nameLen];
    strcpy(name, other.name);
}

AnimalFamily &AnimalFamily::operator=(const AnimalFamily &other)
{
    if (this != &other)
    {
        char *buffer = new char[other.nameLen];
        strcpy(buffer, other.name);

        delete[] name;
        name = buffer;

        nameLen = other.nameLen;
        members = other.members;
    }

    return *this;
}

AnimalFamily::~AnimalFamily()
{
    std::cout << "Animal deleted" << std::endl;
    delete[] name;
    members = 0;
}

const char *AnimalFamily::getName() const
{
    return name;
}

unsigned AnimalFamily::getMembers() const
{
    return members;
}

void AnimalFamily::print() const
{
    std::cout << name << " " << members << std::endl;
}