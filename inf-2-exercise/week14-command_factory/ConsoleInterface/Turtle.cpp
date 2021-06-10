#include "Turtle.h"

Turtle::Turtle(string name, int age, double shellDiameter) : Animal(name, age), shellDiameter(shellDiameter) {}

void Turtle::print() const {
    cout << "this " << age << "-aged turtle is called " << name << ", has a shell diameter of "<< shellDiameter<< " and makes this sound: ";
    makeSound();
}

void Turtle::makeSound() const {
    cout << "....." << endl;
}

Animal* Turtle::clone() {
    return new Turtle(*this);
}