#pragma once
#include "Triangle.h"
class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(Point2D a, Point2D b, Point2D c) : Triangle(a, b, c) {}

private:
	IDescribableShape* clone() const
	{
		return new EquilateralTriangle(*this);
	}

	void save(std::ostream& out) const
	{
		out << "equilateral-triangle " << f_a << " " << f_b << " " << f_c << std::endl;
	}
};
