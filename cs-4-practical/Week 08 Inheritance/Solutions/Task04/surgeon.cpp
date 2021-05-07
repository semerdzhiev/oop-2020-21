#include <iostream>
#include <string.h>

#include "Surgeon.h"

void Surgeon::copy(const char *name)
{
    Doctor::copy(name);
}

Surgeon::Surgeon()
{
}

Surgeon::Surgeon(const char *name)
{
    this->copy(name);
}

Surgeon::Surgeon(Surgeon const &otherSurgeon)
{
    this->copy(otherSurgeon.getName());
}

Surgeon &Surgeon::operator=(Surgeon const &otherSurgeon)
{
    return *this;
}

Surgeon::~Surgeon()
{
}

void Surgeon::operation()
{
    std::cout << "Surgeon operation" << std::endl;
}