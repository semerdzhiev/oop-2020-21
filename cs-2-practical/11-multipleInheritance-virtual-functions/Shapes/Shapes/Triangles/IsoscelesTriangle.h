#pragma once
#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(Point2D a, Point2D b, Point2D c) : Triangle(a, b, c) {}

private:
	IDescribableShape* clone() const
	{
		return new IsoscelesTriangle(*this);
	}

	void save(std::ostream& out) const
	{
		out << "isosceles-triangle " << f_a << " " << f_b << " " << f_c << std::endl;
	}
};
