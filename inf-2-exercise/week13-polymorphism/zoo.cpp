#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
class ISounding {
public:
    virtual void makeSound() const = 0;
};

class IClonable {
public:
    virtual IClonable* clone() = 0;
};

class Animal: public ISounding, public IClonable {
    string name;
    int age;
public:
    Animal(string name, int age) : name(name), age(age) {}

    virtual void makeSound() const = 0;

    virtual Animal* clone() = 0;
};

class Turtle: public Animal {
    double shellDiameter;
public:
    Turtle(string name, int age, double shellDiameter) : Animal(name, age), shellDiameter(shellDiameter) {}

    virtual void makeSound() const {
        cout<< "....."<< endl;
    }

    virtual Animal* clone() {
        return new Turtle(*this);
    }
};

enum Type {
    Canis, Vulpes
};

class Fox: public Animal {
    Type type;
public:
    Fox(string name, int age, Type type) : Animal(name, age), type(type) {}

    virtual void makeSound() const {
        cout<< "wa pa pa pa pow"<< endl;
    }

    virtual Animal* clone() {
        return new Fox(*this);
    }
};

void printSounding(const ISounding* animal) {
    animal->makeSound();
}

class AnimalArray {
    vector<Animal*> animals;

    void clean() {
        for(int i = 0; i< size(); ++i) {
            delete animals[i];
            animals.clear();
        }
    }

    void copy(const AnimalArray& other, bool doClean = true) {
        if(doClean) {
            clean();
        }

        for(int i = 0; i< other.size(); ++i) {
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
        if(this != &other) {
            copy(other);
        }

        return *this;
    }

    ~AnimalArray() {
        clean();
    }
};*/