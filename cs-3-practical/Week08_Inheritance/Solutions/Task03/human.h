#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Human
{
    std::string name;
    std::string family;
    int age;

public:
    Human();
    Human(const std::string &name, const std::string &family, int age);
    void print();
};