#include <iostream>
#include <math.h>
#include "point.h"

using std::cin;
using std::cout;
using std::endl;

void Point::read()
{
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
}

void Point::print()
{
    cout << "(" << x << "," << y << ")" << endl;
}

double Point::distance()
{
    return sqrt(x * x + y * y);
}

double Point::distanceFrom(Point other)
{
    double deltaX = x - other.x;
    double deltaY = y - other.y;

    return sqrt(deltaX * deltaX + deltaY * deltaY);
}