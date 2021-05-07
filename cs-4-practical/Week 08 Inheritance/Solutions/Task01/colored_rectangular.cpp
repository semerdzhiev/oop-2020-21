#include "colored_rectangular.h"
#include <iostream>

ColoredRectangular::ColoredRectangular(const std::string &color, int width, int height) : Rectangular("colored rectangular", width, height)
{
    this->color = color;
}

void ColoredRectangular::print() {
    Rectangular::print();
    std::cout << "color: " << color << std::endl;
}