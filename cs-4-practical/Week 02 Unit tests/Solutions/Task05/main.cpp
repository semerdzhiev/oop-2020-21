#include <iostream>
#include "structs.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Rectangular firstRectangular, secondRectangular;
    Point givenPoint;

    cout << "Define rectangular A: " << endl;
    firstRectangular.read();

    cout << "Here it is: " << endl;
    firstRectangular.print();

    cout << "Enter point to be checked for being in rect. A: " << endl;

    givenPoint.read();

    cout << "It is " << (firstRectangular.contains(givenPoint) ? "" : "not ") << "in rectangular A" << endl;

    cout << "Define rectangular B: " << endl;
    secondRectangular.read();

    cout << "The two rectangulars are " << (firstRectangular.intersectingWith(secondRectangular) ? "" : "not ") << "intersecting" << endl;

    return 0;
}