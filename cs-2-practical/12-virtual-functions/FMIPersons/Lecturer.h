#pragma once
#include "Person.h"

class Lecturer : virtual public Person {
    float salary;
public:
    Lecturer(const char* name, const char* ucn, float salary);

    float getSalary() const;
    void setSalary(float salary);

    void printJobTittle() override;
};


