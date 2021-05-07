#include <iostream>
#include <cstring>
#include "shape.h"

Shape::Shape() {
    this->type = "";
}

Shape::Shape(const std::string &type) {
    this->type = type;
}

void Shape::print() {
    std::cout << "type: " << type << std::endl;
}