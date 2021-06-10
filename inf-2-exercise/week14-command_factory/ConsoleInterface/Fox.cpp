#include "Fox.h"

Fox::Fox(string name, int age, Type type) : Animal(name, age), type(type) {}

void Fox::print() const {
    cout << "this " << age << "-aged fox is called " << name << " and makes this sound: ";
    makeSound();
}

void Fox::makeSound() const {
    cout << "wa pa pa pa pow" << endl;
}

Animal* Fox::clone() {
    return new Fox(*this);
}