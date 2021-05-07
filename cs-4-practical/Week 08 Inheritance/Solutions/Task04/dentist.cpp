#include <iostream>
#include <string.h>

#include "Dentist.h"

void Dentist::copy(const char *name)
{
    Doctor::copy(name);
}

Dentist::Dentist()
{
}

Dentist::Dentist(const char *name)
{
    this->copy(name);
}

Dentist::Dentist(Dentist const &otherDentist)
{
    this->copy(otherDentist.getName());
}

Dentist &Dentist::operator=(Dentist const &otherDentist)
{
    return *this;
}

Dentist::~Dentist()
{
}

void Dentist::operation()
{
    std::cout << "Dentist operation" << std::endl;
}