
#include "Triangle.h"

Triangle::Triangle(Point2D a, Point2D b, Point2D c) : f_a(a), f_b(b), f_c(c) {}

Point2D Triangle::getCentroid() const
{
	return Point2D();
}

double Triangle::getDescribedCircleRadius() const
{
	return 0.0;
}

void Triangle::writeDescribedCircleRadius(std::ofstream& out) const
{
}


void Triangle::load(std::istream& in)
{
	in >> f_a >> f_b >> f_c;
}

void Triangle::save(std::ostream& out) const
{
	out << "triangle " << f_a << " " << f_b << " " << f_c << std::endl;
}
