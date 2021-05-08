#include "Rectangle.h"

Point2D Rectangle::getCentroid() const
{
	return Point2D();
}

double Rectangle::getDescribedCircleRadius() const
{
	return 0.0;
}

void Rectangle::writeDescribedCircleRadius(std::ofstream& out) const
{
}

void Rectangle::load(std::istream& in)
{
	in >> f_lowerLeft >> f_upperRight;
}

void Rectangle::save(std::ostream& out) const
{
	out << "rectangle " << f_lowerLeft << " " << f_upperRight << std::endl;
}

IDescribableShape* Rectangle::clone() const
{
	return new Rectangle(*this);
}
