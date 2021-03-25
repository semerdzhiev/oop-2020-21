#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
    double a, b, c;
    bool isValid();

public:
    void read();
    double perimeter();
    double area();
};

#endif