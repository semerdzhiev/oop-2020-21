#pragma once
#include "shape.h"

class Triangle : Shape
{
    int side1, side2, side3;

public:
    Triangle(int side1, int side2, int side3);
    void print();
};
