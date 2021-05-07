#pragma once
#include <iostream>

class Shape {
    std::string type;

public:
    Shape();
    Shape(const std::string &type);
    void print();
};