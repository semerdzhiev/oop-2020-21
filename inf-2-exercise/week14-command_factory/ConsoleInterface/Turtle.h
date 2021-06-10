#pragma once
#include <iostream>
using namespace std;

#include "Animal.h"

class Turtle : public Animal {
    double shellDiameter;
public:
    Turtle(string name, int age, double shellDiameter);

    virtual void print() const;
    virtual void makeSound() const;
    virtual Animal* clone();
};

