#include "square.h"
#include <iostream>

Square::Square(int side) : Shape("square") {
    this->side = side;
}

void Square::print() {
    Shape::print();
    std::cout << "side: " << side << std::endl;
};
