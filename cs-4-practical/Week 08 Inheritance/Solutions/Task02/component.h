#pragma once
#include <iostream>

class Component {
    static int genId;

    int id;
    std::string characteristic;

public:
    Component(const std::string &characteristic);
    void print();
};