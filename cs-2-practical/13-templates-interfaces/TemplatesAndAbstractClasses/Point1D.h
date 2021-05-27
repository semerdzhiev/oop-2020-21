#pragma once
#include"Point.h"

struct Point1D : public Point{
    float x;

public:
    explicit Point1D(float x=0);
    void print(std::ostream& os) const override;
    void toFile(std::ofstream& os) const override;
    void add(const Point& other) override;
    float distance(const Point& other) const override;

    friend std::ostream& operator<<(std::ostream &os, const Point1D &t) {
        t.print(os);
        return os;
    }

private:
    float* getCoordinates() const override;
};
