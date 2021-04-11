#include <iostream>
#include <cstring>
#include "../Headers/Fauna.hpp"

Fauna::Fauna(unsigned _capacity) : capacity(_capacity), numberOfAnimals(0), numberOfFamilies(0)
{
    std::cout << "Fauna created" << std::endl;
    animalFamilies = new AnimalFamily *[_capacity];
}

Fauna::Fauna(const Fauna &other) : capacity(other.capacity),
                                   numberOfAnimals(other.numberOfAnimals),
                                   numberOfFamilies(other.numberOfFamilies)
{
    animalFamilies = new AnimalFamily *[other.capacity];

    for (unsigned i = 0; i < other.numberOfFamilies; i++)
    {
        animalFamilies[i] = new AnimalFamily(*(other.animalFamilies[i]));
    }
}

Fauna &Fauna::operator=(const Fauna &other)
{
    if (this != &other)
    {
        AnimalFamily **buffer = new AnimalFamily *[other.capacity];

        for (unsigned i = 0; i < other.numberOfFamilies; i++)
        {
            buffer[i] = new AnimalFamily(*(other.animalFamilies[i]));
        }

        for (unsigned i = 0; i < numberOfFamilies; i++)
        {
            delete animalFamilies[i];
        }

        delete[] animalFamilies;

        animalFamilies = buffer;
        numberOfFamilies = other.numberOfFamilies;
        numberOfAnimals = other.numberOfFamilies;
        capacity = other.capacity;
    }
    return *this;
}

Fauna::~Fauna()
{
    for (unsigned i = 0; i < numberOfFamilies; i++)
    {
        delete animalFamilies[i];
    }

    delete[] animalFamilies;
    std::cout << "Fauna deleted" << std::endl;
}

void Fauna::addFamily(const char *name, unsigned members)
{
    if (numberOfAnimals + members >= capacity)
        throw std::length_error("Reached capacity in Fauna");

    AnimalFamily *family = new AnimalFamily(name, members);
    animalFamilies[numberOfFamilies++] = family;
    numberOfAnimals += members;
}

void Fauna::removeFamily(const char *name)
{
    for (unsigned i = 0; i < numberOfFamilies; i++)
    {
        if (!strcmp(animalFamilies[i]->getName(), name))
        {
            numberOfAnimals -= animalFamilies[i]->getMembers();
            delete animalFamilies[i];
            animalFamilies[i] = animalFamilies[--numberOfFamilies];
            animalFamilies[numberOfFamilies] = nullptr;
        }
    }
}

AnimalFamily *Fauna::find(const char *name) // issues with that implementation?
                                            // we give direct access to the objects and
                                            // invariants might be violated
                                            // we only need that method in the Planet class, so we should
                                            // consider ways for providing that method to the Planet class only
{
    for (unsigned i = 0; i < numberOfFamilies; i++)
    {
        if (!strcmp(animalFamilies[i]->getName(), name))
            return animalFamilies[i];
    }

    return nullptr;
}

void Fauna::print() const
{
    for (unsigned i = 0; i < numberOfFamilies; i++)
    {
        animalFamilies[i]->print();
    }
}
