#include <iostream>
#include "../Headers/Zoo.hpp"

Zoo::Zoo(unsigned _capacity) : capacity(_capacity), numberOfFamilies(0), numberOfAnimals(0)
{
    std::cout << "Zoo created" << std::endl;
    families = new AnimalFamily *[_capacity];
}

Zoo::~Zoo()
{
    delete[] families;
    std::cout << "Zoo deleted" << std::endl;
}

void Zoo::addFamily(AnimalFamily &family)
{
    if (numberOfAnimals + family.getMembers() >= capacity)
        throw std::length_error("Reached capacity in Zoo");

    families[numberOfFamilies++] = &family;
    numberOfAnimals += family.getMembers();
}

AnimalFamily *Zoo::removeFamily(const char *name)
{
    for (unsigned i = 0; i < numberOfFamilies; i++)
    {
        if (!strcmp(families[i]->getName(), name))
        {
            AnimalFamily *animal = families[i];
            numberOfAnimals -= families[i]->getMembers();
            families[i] = families[--numberOfFamilies];
            families[numberOfFamilies] = nullptr;

            return animal;
        }
    }

    return nullptr;
}

void Zoo::print() const
{
    for (unsigned i = 0; i < numberOfFamilies; i++)
    {
        families[i]->print();
    }
}