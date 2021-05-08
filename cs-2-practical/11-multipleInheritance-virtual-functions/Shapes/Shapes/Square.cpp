#include "Square.h"

Point2D Square::getCentroid() const
{
	return Point2D();
}

double Square::getDescribedCircleRadius() const
{
	return 0.0;
}

void Square::writeDescribedCircleRadius(std::ofstream& out) const
{
}

void Square::load(std::istream& in)
{
	Point2D lowerLeft, upperRight;
	double width;
	in >> lowerLeft >> upperRight;
	f_lowerLeft = lowerLeft;
	if (in.good())
	{
		f_width = upperRight.x - lowerLeft.x;
		return;
	}

	in.clear();
	f_width = upperRight.x;
}

void Square::save(std::ostream& out) const
{
	out << "square " << f_lowerLeft << " " << f_width << std::endl;
}

IDescribableShape* Square::clone() const
{
	return new Square(*this);
}
