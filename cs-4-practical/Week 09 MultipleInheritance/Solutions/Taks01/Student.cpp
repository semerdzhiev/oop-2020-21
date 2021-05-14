#include "Student.hpp"

Student::Student(const std::string name, const int number) : Person(name)
{
    this->number = number;
}

int Student::getNumber() const
{
    return this->number;
}