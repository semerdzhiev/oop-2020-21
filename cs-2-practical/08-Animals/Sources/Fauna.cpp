#include "Fauna.h"
#include <exception>
#include <cstring>

int Fauna::findFamily(const char *name, AnimalFamily **family, unsigned numOfFamilies) {
    for (unsigned i = 0; i < numOfFamilies; i++) {
        if (strcmp(family[i]->getName(), name) == 0) {
            return i;
        }
    }
    return -1;

}

Fauna::Fauna(unsigned capacity) : capacity(capacity) {
    try {
        animalFamilies = new AnimalFamily *[capacity];
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
        animalFamilies = nullptr;
        return;
    }

}

Fauna::Fauna(const Fauna &other) : capacity(other.capacity), numOfAnimals(other.numOfAnimals),
                                   numOfFamilies(other.numOfFamilies) {
    try {
        animalFamilies = new AnimalFamily *[capacity];
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
        animalFamilies = nullptr;
        return;
    }
    for (unsigned i = 0; i < numOfFamilies; i++) {
        animalFamilies[i] = new AnimalFamily(*other.animalFamilies[i]);
    }


}

Fauna::~Fauna() {
    for (unsigned i = 0; i < numOfFamilies; i++) {
        delete animalFamilies[i];
    }
    delete[] animalFamilies;
    numOfAnimals = numOfFamilies = 0;
}

void Fauna::addFamily(const char *name, unsigned number) {
    if (findFamily(name, animalFamilies, numOfFamilies) > 0) {
        throw std::invalid_argument("family is already added!");
    }
    if (capacity < number + numOfAnimals) {
        throw std::length_error("There is not enough space in the fauna");
    }
    animalFamilies[numOfFamilies++] = new AnimalFamily(name, number);
    numOfAnimals += number;
}

void Fauna::addFamily(const AnimalFamily &newFamily) {
    /*if (find(newFamily.getName(),animalFamilies,numOfFamilies) < 0)
    {
        throw std::exception("There is such family in the fauna already");
    }
    if (capacity < newFamily.getNumber() + numOfAnimals)
    {
        throw std::exception("There is not enough space in the fauna");
    }
    animalFamilies[numOfFamilies++] = new AnimalFamily(newFamily.getName(), newFamily.getNumber());
    numOfAnimals += newFamily.getNumber();*/
    addFamily(newFamily.getName(), newFamily.getNumber());
}

void Fauna::removeFamily(const char *name) {
    int foundFamilyIndex = findFamily(name, animalFamilies, numOfFamilies);
    if (foundFamilyIndex < 0) {
        return;
    }

    AnimalFamily *temp = animalFamilies[foundFamilyIndex];
    animalFamilies[foundFamilyIndex] = animalFamilies[numOfFamilies - 1];
    animalFamilies[--numOfFamilies] = nullptr;
    numOfAnimals -= temp->getNumber();
    delete temp;

}

void Fauna::removeFamily(const AnimalFamily &newFamily) {
    removeFamily(newFamily.getName());
}

void Fauna::print(std::ostream &os) const {
    for (unsigned i = 0; i < numOfFamilies; i++) {
        animalFamilies[i]->print(os);
    }
}

int Fauna::find(const char *name) {
    return Fauna::findFamily(name,animalFamilies,numOfFamilies);
}

const AnimalFamily* Fauna::at(unsigned pos) const{
    if(pos>=numOfAnimals) {
        throw std::out_of_range("Out of range access!\n");
    }
    return animalFamilies[pos];
}

Fauna::Fauna(Fauna &&other)noexcept:animalFamilies(other.animalFamilies),
capacity(other.capacity),
numOfAnimals(other.numOfAnimals),
numOfFamilies(other.numOfFamilies){
    other.animalFamilies = nullptr;
}



