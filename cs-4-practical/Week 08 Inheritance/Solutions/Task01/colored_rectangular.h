#pragma once
#include "rectangular.h"

class ColoredRectangular : Rectangular
{
    std::string color;

public:
    ColoredRectangular(const std::string &color, int width, int height);
    void print();
};