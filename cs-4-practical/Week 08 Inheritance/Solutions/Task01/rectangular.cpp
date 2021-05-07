#include "rectangular.h"
#include <iostream>

using std::cout;
using std::endl;

Rectangular::Rectangular(int width, int height) : Shape("rectangular") {
    this->width = width;
    this->height = height;
}

Rectangular::Rectangular(char const *type, int width, int height) : Shape(type) {
    this->width = width;
    this->height = height;
}

void Rectangular::print() {
    Shape::print();
    cout << "width: " << width << endl;
    cout << "height: " << height << endl;
}