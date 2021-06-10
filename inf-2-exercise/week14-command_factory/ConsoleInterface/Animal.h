#pragma once
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string name, int age);

    virtual void print() const = 0;
    virtual void makeSound() const = 0;
    virtual Animal* clone() = 0;
};

