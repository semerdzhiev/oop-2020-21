#include "AnimalFamily.hpp"
#pragma once

class Zoo
{
    AnimalFamily** families;
    unsigned capacity{};
    unsigned numberOfAnimals{};
    unsigned numberOfFamilies{};

public:
    Zoo(unsigned);
    Zoo(const Zoo&) = delete;
    Zoo& operator=(const Zoo&) = delete;
    ~Zoo();

    void addFamily(AnimalFamily& );

    AnimalFamily* removeFamily(const char*);
    void print() const;
};
