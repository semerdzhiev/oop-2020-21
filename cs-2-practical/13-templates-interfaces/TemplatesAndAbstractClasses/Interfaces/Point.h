#pragma once

#include"Printable.h"
#include "ToFile.h"

class Point : public Printable, public ToFile {
public:
    virtual void add(const Point& other) = 0;
    virtual float distance(const Point& other) const = 0;
    virtual float* getCoordinates() const = 0;
};

