#include "Fauna.hpp"
#include "Zoo.hpp"
#pragma once

class Planet
{
private:
    Fauna *fauna;
    Zoo *zoo;

public:
    Planet(unsigned faunaCapacity, unsigned zooCapacity);
    Planet(const Planet &other) = delete;
    Planet &operator=(const Planet &other) = delete;
    ~Planet();

    void addFamilyInFauna(const char *, unsigned);
    void addFamilyInZoo(const char *);
    void removeFamilyFromFauna(const char *);
    void removeFamilyFromZoo(const char *);
    void print() const;
};