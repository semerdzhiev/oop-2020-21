
#pragma once
#include "Person.h"

class Student : virtual public Person {
    const unsigned int facultyNum;
public:
    Student(const char* name, const char* ucn, const unsigned int facultyNum);

    unsigned int getFacultyNum() const;

    void printJobTittle() override;
};


