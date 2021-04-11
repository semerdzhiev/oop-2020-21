#include <iostream>
#include "../Headers/Planet.hpp"

Planet::Planet(unsigned faunaCapacity, unsigned zooCapacity)
{
    std::cout << "Planet created" << std::endl;
    fauna = new Fauna(faunaCapacity);
    zoo = new Zoo(zooCapacity);
}

Planet::~Planet()
{
    delete zoo;
    delete fauna;
    std::cout << "Planet deleted" << std::endl;
}

void Planet::addFamilyInFauna(const char *name, unsigned members)
{
    fauna->addFamily(name, members);
}

void Planet::addFamilyInZoo(const char *name)
{
    AnimalFamily *animal = fauna->find(name);
    zoo->addFamily(*animal);
}

void Planet::removeFamilyFromFauna(const char *name)
{
    zoo->removeFamily(name);
    fauna->removeFamily(name);
}

void Planet::removeFamilyFromZoo(const char *name)
{
    zoo->removeFamily(name);
}

void Planet::print() const
{
    std::cout << "Animals in fauna:" << std::endl;
    fauna->print();
    std::cout << "Animals in zoo:" << std::endl;
    zoo->print();
}