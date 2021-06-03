// include the declaration of the class
// "" instead of <>

#include "Point.h"

#include <cmath>
#include <iomanip>

//
Point::Point(double x, double y): x(x), y(y)
{}

double Point::getX() const
 {
     return this->x;
 }

double Point::getY() const
{
    return this->y;
}

double Point::getR() const
{
    return std::sqrt(this->x * this->x + this->y*this->y);
}

double Point::getT() const
{
    // valid only for a point in x > 0 && y > 0
    return std::atan2(this->y, this->x);
}

double Point::distanceToCenter() const
{
    return this->getR();
}

double Point::distance(const Point& point) const
{
    return std::sqrt((this->x - point.x) * (this->x - point.x) +
                     (this->y - point.y) * (this->y - point.y));
}

void Point::setX(double newX)
{
    this->x = newX;
}

void Point::setY(double newY)
{
    this->y = newY;
}

void Point::translate(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::print() const
{
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

