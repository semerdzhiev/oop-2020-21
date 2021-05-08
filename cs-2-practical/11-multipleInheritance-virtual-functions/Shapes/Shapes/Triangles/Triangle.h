#pragma once
#include "Shape.h"

class Triangle : public IDescribableShape
{
public:
	Triangle(Point2D a = Point2D(),
		Point2D b = Point2D(),
		Point2D c = Point2D());
	virtual ~Triangle() {  };

private:
	Point2D getCentroid() const override;
	double getDescribedCircleRadius() const override;
	void writeDescribedCircleRadius(std::ofstream& out) const override;

	virtual void load(std::istream& in) override;
	virtual void save(std::ostream& out) const override;

	virtual IDescribableShape* clone() const override
	{
		return new Triangle(*this);
	}

protected:
	Point2D f_a;
	Point2D f_b;
	Point2D f_c;
};
