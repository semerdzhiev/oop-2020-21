#include "Circle.h"

#include <iostream>
#include <cmath>

Circle::Circle(double x, double y, double r)
    : center(x, y), radius(r)
{
    std::cout << "\nCreate Circle" << std::endl;
    print();
}

Circle::Circle(const Point& newCenter, double newRadius)
    : center(newCenter), radius(newRadius)
{
    std::cout << "\nCreate Circle with ( Point, r )" << std::endl;
    print();
}

Circle::~Circle()
{
    std::cout << "\n~Circle() " << std::endl;
    print();
}

void Circle::print() const
{
    std::cout << "Center ";
    center.print();

    std::cout << " Radius = " << radius << std::endl;
}

double Circle::area() const
{
    const double PI = 3.14159;
    return PI * radius * radius;
}

Figure* Circle::clone() const
{
    return new Circle(*this);
}

void Circle::setCenter(const Point& newCenter)
{
    center = Point(newCenter.getX(), newCenter.getY());
}

void Circle::setCenter(double x, double y)
{
    center = Point(x, y);
}

void Circle::setRadius(double newRadius)
{
    // проверка, валидация?
    radius = newRadius;
}

bool Circle::isInside(const Point& point) const
{
    // (x - center.x)^2 + (y - center.y)^2 <= radius^2
    return  (point.getX() - center.getX())*(point.getX() - center.getX()) +
            (point.getY() - center.getY())*(point.getY() - center.getY()) <= radius*radius;
}

bool Circle::intersect(const Circle& otherCircle) const
{
    // d - разстоянието между двата центъра
    // пресичат се, ако R - r < d < R + r
    // R > r

    double dist = center.distance(otherCircle.center);
    return fabs(radius - otherCircle.radius) < dist &&
            dist < radius + otherCircle.radius;
}

