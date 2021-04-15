#include "Planet.h"

Planet::Planet(unsigned zooCapacity, unsigned faunaCapacity) {
    zoos = new Zoo(zooCapacity);
    faunas = new Fauna(faunaCapacity);
}

Planet::~Planet() {
    delete zoos;
    delete faunas;
}

void Planet::addFamilyZoo(const AnimalFamily &newFamily) {

    zoos->addFamily(newFamily.getName(), newFamily.getNumber());
}

void Planet::addFamilyZoo(const char *name, unsigned number) {
    zoos->addFamily(name, number);
}

void Planet::addFamilyFauna(const AnimalFamily &newFamily) {
    faunas->addFamily(newFamily.getName(), newFamily.getNumber());
}

void Planet::addFamilyFauna(const char *name, unsigned number) {
    faunas->addFamily(name, number);
}

void Planet::removeFamilyZoo(const AnimalFamily &newFamily) {
    zoos->removeFamily(newFamily.getName());
}

void Planet::removeFamilyFauna(const AnimalFamily &newFamily) {
    faunas->removeFamily(newFamily.getName());
}

void Planet::print(std::ostream &os) const {
    os << "Animals is cages:\n";
    zoos->print(os);
    os << "Free animals:\n";
    faunas->print(os);
}

void Planet::removeFamilyFauna(const char *name) {
    faunas->removeFamily(name);
}

void Planet::removeFamilyZoo(const char *name) {
    zoos->removeFamily(name);
}
