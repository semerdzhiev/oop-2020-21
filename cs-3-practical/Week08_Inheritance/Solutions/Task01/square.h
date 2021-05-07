#pragma once
#include "shape.h"

class Square : Shape
{
    int side;

public:
    Square(int side);
    void print();
};