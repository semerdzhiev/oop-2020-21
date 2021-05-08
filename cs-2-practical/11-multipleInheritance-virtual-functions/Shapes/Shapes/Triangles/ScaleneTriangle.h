#pragma once
#include "Triangle.h"

class Triangle;
class ScaleneTriangle : public Triangle
{
public:
	ScaleneTriangle(Point2D a, Point2D b, Point2D c) : Triangle(a, b, c) {}

private:
	IDescribableShape* clone() const
	{
		return new ScaleneTriangle(*this);
	}

	void save(std::ostream& out) const
	{
		out << "scalene-triangle " << f_a << " " << f_b << " " << f_c << std::endl;
	}
};
