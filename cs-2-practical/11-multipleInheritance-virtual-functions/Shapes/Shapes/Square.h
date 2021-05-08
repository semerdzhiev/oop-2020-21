#pragma once
#include "Shape.h"

class Square : public IDescribableShape
{
public:
	Square(Point2D lowerLeft, double width) : f_lowerLeft(lowerLeft), f_width(width) {}
	Square(Point2D lowerLeft, Point2D upperRight);

private:
	Point2D getCentroid() const override;
	double getDescribedCircleRadius() const override;
	void writeDescribedCircleRadius(std::ofstream& out) const override;

	void load(std::istream& in) override;
	void save(std::ostream& out) const override;

	IDescribableShape* clone() const override;

private:
	double f_width;
	Point2D f_lowerLeft;
};
