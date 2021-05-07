#include <iostream>
#include <string.h>

#include "Doctor.h"

void Doctor::copy(const char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Doctor::Doctor()
{
    name = nullptr;
}

Doctor::Doctor(const char *name)
{
    this->copy(name);
}

Doctor::Doctor(Doctor const &otherDoctor)
{
    this->copy(otherDoctor.getName());
}

Doctor &Doctor::operator=(Doctor const &otherDoctor)
{
    if (this != &otherDoctor)
    {
        delete[] this->name;

        this->copy(otherDoctor.getName());
    }

    return *this;
}

Doctor::~Doctor()
{
    if (name != NULL)
    {
        delete[] name;
    }
}

void Doctor::operation()
{
    std::cout << "Doctor operation" << std::endl;
}