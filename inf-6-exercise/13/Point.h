#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    public:
        Point(double x = 0, double y = 0);

        // const methods, they do not change the current object
        double getX() const;
        double getY() const;

        // how to convert the Cartesian coordinates into radial and angular coordinates

        // distance to the pole, radius or radial distance
        double getR() const;

        // the angle
        double getT() const;

        // distance to the center of the coordinate system
        double distanceToCenter() const;
        double distance(const Point&) const;

        // functions used to modify the values of the data members
        void setX(double);
        void setY(double);

        // translate the point, arguments: offset for x and y
        void translate(double dx, double dy);

        // print to the standard output
        void print() const;

    private:
        // set of numerical coordinates
        double x, y;
};

#endif // POINT_H
