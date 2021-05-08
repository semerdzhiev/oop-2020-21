#pragma once
#include "Shape.h"
class Rectangle :
	public IDescribableShape
{
public:
	Rectangle(Point2D lowerLeft = Point2D(),
		Point2D upperRight = Point2D()) : f_lowerLeft(lowerLeft), f_upperRight(upperRight) {}

private:
	Point2D getCentroid() const override;
	double getDescribedCircleRadius() const override;
	void writeDescribedCircleRadius(std::ofstream& out) const override;

	void load(std::istream& in) override;
	void save(std::ostream& out) const override;

	IDescribableShape* clone() const override;

private:
	Point2D f_lowerLeft;
	Point2D f_upperRight;
};

