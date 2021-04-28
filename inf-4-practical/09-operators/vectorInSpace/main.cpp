#include <iostream>
#include "Vector.h"

int main() {
    Vector v(3);
    Vector v1(1, 3, 4);

    std::cout << v << std::endl;
    std::cout << v1 << std::endl;


    bool isZero = v;

    std::cout << "is zero: " << std::boolalpha << isZero << std::endl;

    isZero = v1;
    std::cout << "is zero: " << std::boolalpha << isZero << std::endl;

    std::cout << ++v << std::endl;
    Vector v2 = v++;
    std::cout << v2 << std::endl;
    std::cout << v << std::endl;

    std::cout << "operator <: " << (v < v1) << std::endl;
    std::cout << "operator >: " << (v > v1) << std::endl;
    std::cout << "operator <=: " << (v <= v1) << std::endl;
    std::cout << "operator >=: " << (v >= v1) << std::endl;
    std::cout << "operator ==: " << (v == v1) << std::endl;
    std::cout << "operator !=: " << (v != v1) << std::endl;

    double len = v;

    std::cout << len << std::endl;

    v = v * 5;
    std::cout << v << std::endl;
    v2 *= 2;
    std::cout << v2 << std::endl;

    Vector v3(5, 6);
    v3 += v2;

    std::cout << v3 << std::endl;

    std::cin >> v1;

    std::cout << v1 << std::endl;

    return 0;
}
