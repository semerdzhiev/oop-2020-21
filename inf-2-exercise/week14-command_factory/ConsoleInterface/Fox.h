#pragma once
#include <iostream>
using namespace std;

#include "Animal.h"


class Fox : public Animal {
public:
    enum Type {
        Canis, Vulpes
    };

    Type type;
public:
    Fox(string name, int age, Type type);

    virtual void print() const;
    virtual void makeSound() const;
    virtual Animal* clone();
};

