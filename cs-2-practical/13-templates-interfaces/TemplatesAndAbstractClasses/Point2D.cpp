#include "Point2D.h"

void Point2D::print(std::ostream &os) const {
    Point1D::print(os);
    os<<y<<' ';
}

Point2D::Point2D(float x, float y) : Point1D(x),y(y) {}