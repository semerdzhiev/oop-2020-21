#ifndef point
#define point

struct Point
{
    double x, y;

    void read();
    void print();
    double distance();
    double distanceFrom(Point other);
};

#endif