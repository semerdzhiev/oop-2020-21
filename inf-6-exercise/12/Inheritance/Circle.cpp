#include "Circle.h"

#include <iostream>
#include <cmath>

Circle::Circle(double x, double y, double r)
    : center(x, y), radius(r)
{
    // � �������������� ������, ��������� ������������
    // �� ����� Point(x, y), �� �� ������������ ����-�������
    // center; ���� ���������� ����������� �� ������������� ��
    // �����������; ������ �� �������������� ���� radius
    // radius = r;

    std::cout << "\nCreate Circle" << std::endl;
    print();
}

Circle::Circle(const Point& newCenter, double newRadius)
    : center(newCenter), radius(newRadius)
{
    // � ��������������� ������ �� �������� ��������� ����������� �� Point
    // radius = newRadius;

    std::cout << "\nCreate Circle with ( Point, r )" << std::endl;
    print();
}

// ����������, ���� ������� ���������,������ ������ ��������� �������� �����
Circle::~Circle()
{
    std::cout << "\n~Circle() " << std::endl;
    print();
}

// ��������� �� ������������ �� �����������
void Circle::print() const
{
    std::cout << "Center ";
    center.print();

    std::cout << " Radius = " << radius << std::endl;
}

// ��������
void Circle::setCenter(const Point& newCenter)
{
    center = Point(newCenter.getX(), newCenter.getY());
}

// ��������� ������������ �� �������
void Circle::setCenter(double x, double y)
{
    center = Point(x, y);
}

void Circle::setRadius(double newRadius)
{
    // ��������, ���������?
    radius = newRadius;
}

bool Circle::isInside(const Point& point) const
{
    // (x - center.x)^2 + (y - center.y)^2 <= radius^2
    return  (point.getX() - center.getX())*(point.getX() - center.getX()) +
            (point.getY() - center.getY())*(point.getY() - center.getY()) <= radius*radius;
}

bool Circle::intersect(const Circle& otherCircle) const
{
    // d - ������������ ����� ����� �������
    // �������� ��, ��� R - r < d < R + r
    // R > r

    double dist = center.distance(otherCircle.center);
    return fabs(radius - otherCircle.radius) < dist &&
            dist < radius + otherCircle.radius;
}

std::ostream& operator << (std::ostream& out, const Circle& c)
{
    if(!out) return out;

    out << "(" << c.center.getX() << ", " << c.center.getY() << ")" << '\t' << c.radius;

    return out;
}

/// (x, y)  r
std::istream& operator >> (std::istream& in, Circle& c)
{
    if(!in) return in;

    /// ���������� ������� (
    in.ignore();

    double x, y, radius;
    in >> x; /// �������� ����� �� ,

    /// ���������� ,
    in.ignore();
    in >> y;

    /// ���������� )
    in.ignore();

    /// >> �������� �����������
    in >> radius;

    if(in)
    {
        c.center = Point(x, y);
        c.radius = radius;
    }

    return in;
}
