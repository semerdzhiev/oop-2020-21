#include "Zoo.h"

Zoo::Zoo(unsigned int capacity) : capacity(capacity) {
    try {
        animalFamilies = new AnimalFamily *[capacity];
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
        animalFamilies = nullptr;
        return;
    }
    std::cout<<"AAA:"<<numOfFamilies<<' '<<numOfAnimals;
}

Zoo::~Zoo() {
    delete[] animalFamilies;
    numOfAnimals = numOfFamilies = 0;
}

void Zoo::addFamily(const char *name, unsigned number) {
    if (numOfAnimals + number > capacity) {
        throw 0;
    }
    if (Fauna::findFamily(name, animalFamilies, numOfFamilies) > 0) {
        throw -1;
    }
    numOfAnimals+=number;
    AnimalFamily *temp = new AnimalFamily(name, number);
    animalFamilies[numOfFamilies++] = temp;
    temp = nullptr;
}

void Zoo::addFamily(AnimalFamily &newFamily) {
    addFamily(newFamily.getName(), newFamily.getNumber());

}

AnimalFamily *Zoo::removeFamily(const char *name) {
    int index = Fauna::findFamily(name, animalFamilies, numOfFamilies);
    if (index < 0) {
        return nullptr;
    }
    numOfAnimals -= animalFamilies[index]->getNumber();
    AnimalFamily *result = animalFamilies[index];
    animalFamilies[index] = animalFamilies[numOfFamilies - 1];
    animalFamilies[numOfFamilies - 1] = nullptr;
    numOfFamilies--;
    return result;
}

AnimalFamily *Zoo::removeFamily(const AnimalFamily &newFamily) {
    return removeFamily(newFamily.getName());
}

void Zoo::print(std::ostream &os) const {
    for (unsigned i = 0; i < numOfFamilies; i++) {
        animalFamilies[i]->print(os);
    }
}

int Zoo::findFamily(const char *name) {
    Fauna::findFamily(name, animalFamilies, numOfFamilies);
}

const AnimalFamily *Zoo::at(unsigned int pos) const {
    if (pos >= numOfAnimals) {
        throw std::out_of_range("Out of range access!\n");
    }
    return animalFamilies[pos];
}

Zoo::Zoo(const Zoo &other) : capacity(other.capacity),
                             numOfAnimals(other.numOfAnimals), numOfFamilies(other.numOfFamilies) {
    animalFamilies = new AnimalFamily *[other.capacity];
    for(unsigned i=0;i<other.numOfFamilies;++i)
        animalFamilies[i] = new AnimalFamily(*other.animalFamilies[i]);
}

Zoo::Zoo(Zoo &&other) noexcept: animalFamilies(other.animalFamilies),
capacity(other.capacity),numOfAnimals(other.numOfAnimals),
numOfFamilies(other.numOfFamilies){
    other.animalFamilies= nullptr;
}


