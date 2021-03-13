#include <iostream>
#include "structs.h"
#include "helpers.cpp"

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

void Point::setPoint(double new_x, double new_y)
{
    x = new_x;
    y = new_y;
}

void Point::print()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

void Rectangular::read()
{
    cout << "Enter first point of rectangular" << endl;
    a.read();
    cout << "Enter second point of rectangular" << endl;
    b.read();
}

void Rectangular::print()
{
    double minX = min(a.x, b.x);
    double maxX = max(a.x, b.x);
    double minY = min(a.y, b.y);
    double maxY = max(a.y, b.y);

    for (int i = 0; i < maxY; i++)
    {
        if (i >= minY)
        {
            for (int j = 0; j < maxX; j++)
            {
                if (j >= minX)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}

bool Rectangular::contains(Point point)
{
    double minX = min(a.x, b.x);
    double maxX = max(a.x, b.x);
    double minY = min(a.y, b.y);
    double maxY = max(a.y, b.y);

    return minX <= point.x && maxX >= point.x && minY <= point.y && maxY >= point.y;
}

bool Rectangular::intersectingWith(Rectangular secondRectangle)
{
    Point pointA, pointB, pointC, pointD;

    pointA.setPoint(secondRectangle.a.x, secondRectangle.a.y);
    pointB.setPoint(secondRectangle.b.x, secondRectangle.b.y);
    pointC.setPoint(secondRectangle.a.x, secondRectangle.b.y);
    pointD.setPoint(secondRectangle.b.x, secondRectangle.a.y);

    return this->contains(pointA) || this->contains(pointB) || this->contains(pointC) || this->contains(pointD);
}