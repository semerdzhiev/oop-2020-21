#include <iostream>
#include "point.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Point point1, point2;

    point1.x = 3;
    point1.y = 4;

    cout << "Point 1: ";
    point1.print();

    cout << "Distance of Point 1 from (0,0): " << point1.distance() << endl;

    point2.read();

    cout << "Distance of Point 1 from Point 2: " << point1.distanceFrom(point2) << endl;

    return 0;
}