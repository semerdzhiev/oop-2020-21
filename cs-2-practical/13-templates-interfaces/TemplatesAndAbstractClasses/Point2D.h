#pragma once
#include"Point1D.h"
struct Point2D : public Point1D{
    float y;

    Point2D(float x=0,float y=0);
    void print(std::ostream &os) const override;
};

