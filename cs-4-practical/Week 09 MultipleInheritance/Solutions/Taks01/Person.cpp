#include "Person.hpp"

Person::Person(const std::string name)
{
    this->name = name;
}

std::string Person::getName() const
{
    return this->name;
}