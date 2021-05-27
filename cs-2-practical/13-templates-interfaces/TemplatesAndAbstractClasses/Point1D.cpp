#include "Point1D.h"
#include<cmath>

Point1D::Point1D(float x) : x(x) {}

void Point1D::print(std::ostream &os) const {
    os<<x<<' ';
}

void Point1D::toFile(std::ofstream &os) const {
    os<<"[x]: ["<<x<<"]\n";
    if(!os.good())
        throw std::runtime_error("Error with file!\n");
}

float * Point1D::getCoordinates() const {
    auto* coordinates = new float[1];
    coordinates[0] = x;
    return coordinates;
}

void Point1D::add(const Point &other) {
    float* coordinates = other.getCoordinates();
    this->x += (coordinates[0]);
    delete[] coordinates;
}

float Point1D::distance(const Point &other) const {
    float* coordinates = other.getCoordinates();
    float result = std::fabs(this->x-coordinates[0]);
    delete[] coordinates;
    return result;
}