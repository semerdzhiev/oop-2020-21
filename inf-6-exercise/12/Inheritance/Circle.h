#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle
{
    public:
        // конструктор с подразбиращи се параметри
        Circle(double x = 0, double y = 0, double r = 0);
        // предефиниран конструктор, с параметри точка и радиус
        Circle(const Point&, double);
        // деструктор
        ~Circle();

        // селектори
        const Point& getCenter() const
        {
            return center;
        }

        double getRadius() const
        {
            return radius;
        }

        // извеждане на окръжност
        void print() const;

        // мутатори
        void setRadius(double);
        void setCenter(double, double);
        void setCenter(const Point&);

        // проверява дали дадена точка е вътрешна за окръжността
        bool isInside(const Point& ) const;
        // функция
        bool intersect(const Circle& ) const;

        friend std::istream& operator >> (std::istream&, Circle&);
        friend std::ostream& operator << (std::ostream&, const Circle&);

    private:
        // окръжността се описва с център и радиус
        Point center;
        double radius;
};

#endif // CIRCLE_H
