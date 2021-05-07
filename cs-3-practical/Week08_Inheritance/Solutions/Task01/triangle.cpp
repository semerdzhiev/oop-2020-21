#include "triangle.h"
#include <iostream>

using std::cout;
using std::endl;

Triangle::Triangle(int side1, int side2, int side3) : Shape("triangle")
{
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

void Triangle::print()
{
    Shape::print();
    cout << "side1: " << side1 << endl;
    cout << "side2: " << side2 << endl;
    cout << "side3: " << side3 << endl;
}