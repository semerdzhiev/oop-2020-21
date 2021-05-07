#pragma once
#include "human.h"
#include <iostream>

class Student : public Human
{
    int facultyNumber;
    std::string spec;

public:
    Student();
    Student(const std::string &name, const std::string &family, int age, int faculty, const std::string &spec);
    void print();
};