#include "human.h"

Human::Human() {
    this->name = "";
    this->family = "";
    this->age = 0;
}

Human::Human(const std::string &name, const std::string &family, int age) {
    this->name = name;
    this->family = family;
    this->age = age;
}

void Human::print() {
    cout << "Name: " << name << endl;
    cout << "Family: " << family << endl;
    cout << "Age: " << age << endl;
}