#include <iostream>

#include "point.h"

using std::ostream;
using std::istream;

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

Point::Point(Point const &temp) {
    x = temp.x;
    y = temp.y;
}

Point &Point::operator=(Point const &temp) {
    x = temp.x;
    y = temp.y;

    return *this;
}

bool Point::operator>(Point const temp) const {
    return x > temp.x || ( x == temp.x && y > temp.y);
}

bool Point::operator==(Point const temp) {
    return x == temp.x && y == temp.y;
}

ostream &operator<<(ostream &ostr, Point const &temp) {
    ostr << temp.x << " " << temp.y;
    return ostr;
}

istream &operator>>(istream &in, Point &temp)
{
    in >> temp.x >> temp.y;
    return in;
}