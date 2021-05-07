#include "component.h"
#include <iostream>

int Component::genId = 0;

Component::Component(const std::string &characteristic) {
    this->id = genId++;
    this->characteristic = characteristic;
}

void Component::print() {
    std::cout << "id: " << id << " | ";
    std::cout << characteristic << std::endl;
}