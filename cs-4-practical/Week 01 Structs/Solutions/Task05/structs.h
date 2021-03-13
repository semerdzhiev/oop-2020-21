#ifndef structs
#define structs

struct Point
{
    double x, y;

    void read();
    void setPoint(double new_x, double new_y);
    void print();
};

struct Rectangular
{
    Point a, b;

    void read();
    void print();
    bool contains(Point point);
    bool intersectingWith(Rectangular secondRectangle);
};

#endif