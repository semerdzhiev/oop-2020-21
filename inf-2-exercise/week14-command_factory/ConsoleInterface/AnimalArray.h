#pragma once

#include <vector>
#include "Animal.h"

using namespace std;

class AnimalArray {
    vector<Animal*> animals;

    void clean() {
        for (int i = 0; i < size(); ++i) {
            delete animals[i];
            animals.clear();
        }
    }

    void copy(const AnimalArray& other, bool doClean = true) {
        if (doClean) {
            clean();
        }

        for (int i = 0; i < other.size(); ++i) {
            animals.push_back(other.animals[i]->clone());
        }
    }

public:
    void add(Animal* newAnimal) {
        animals.push_back(newAnimal);
    }

    Animal& operator[](int index) {
        return *animals[index];
    }

    const Animal& operator[](int index) const {
        return *animals[index];
    }

    int size() const {
        return animals.size();
    }

    AnimalArray() {}

    AnimalArray(const AnimalArray& other) {
        copy(other);
    }

    AnimalArray& operator=(const AnimalArray& other) {
        if (this != &other) {
            copy(other);
        }

        return *this;
    }

    ~AnimalArray() {
        clean();
    }
};

