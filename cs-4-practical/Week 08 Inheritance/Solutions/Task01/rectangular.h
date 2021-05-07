#pragma once
#include "shape.h"

class Rectangular : Shape {
    int width;
    int height;

public:
    Rectangular(int width, int height);
    Rectangular(char const *type, int width, int height);
    void print();
};