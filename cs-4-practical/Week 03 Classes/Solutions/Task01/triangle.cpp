#include <iostream>
#include <cmath>
#include "triangle.h"

using std::cin;

bool Triangle::isValid() {
    return !(a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0);
}

void Triangle::read() {
    do {
        cin >> a >> b >> c;
    } while(this->isValid());
}

double Triangle::perimeter() {
    return a + b + c;
}

double Triangle::area()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}