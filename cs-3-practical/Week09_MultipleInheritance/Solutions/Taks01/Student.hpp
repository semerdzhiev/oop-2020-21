#ifndef STUDENT_H
#define STUDENT_H

#include "Person.hpp"

class Student : virtual public Person
{
    int number;

public:
    Student(const std::string name, const int number);

    int getNumber() const;
};

#endif