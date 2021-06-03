#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"
#include "Point.h"

class Circle : public Figure
{
    public:
        Circle(double x = 0, double y = 0, double r = 0);
        Circle(const Point&, double);
        virtual ~Circle();

        const Point& getCenter() const { return center; }
        double getRadius() const { return radius; }

        void setRadius(double);
        void setCenter(double, double);
        void setCenter(const Point&);

        bool isInside(const Point& ) const;
        bool intersect(const Circle& ) const;

        // предефиниране на чисто виртуалните функции от базовия клас
        virtual void print() const override;
        virtual double area() const override;
        virtual Figure* clone() const override;

    private:
        Point center;
        double radius;
};

#endif // CIRCLE_H
