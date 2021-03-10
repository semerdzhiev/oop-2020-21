#include "Vector.h"
#include <iostream>

void Vector::create() {
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;
}

void Vector::print() {
    std::cout << "x = " << x << " y = " << y << " x = " << z << std::endl;
}


