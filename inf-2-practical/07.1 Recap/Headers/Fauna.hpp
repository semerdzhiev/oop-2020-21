#include "AnimalFamily.hpp"
#pragma once

class Fauna {
private:
    AnimalFamily** animalFamilies;
    unsigned capacity{};
    unsigned numberOfFamilies{};
    unsigned numberOfAnimals{};

public:

    Fauna(unsigned);
    Fauna(const Fauna&);
    Fauna& operator=(const Fauna&);
    ~Fauna();

    void addFamily(const char*, unsigned);
    void removeFamily(const char*);
    AnimalFamily* find(const char* name);
    void print() const;
};