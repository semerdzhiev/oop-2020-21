#pragma once
#include <fstream>

#include "ISerializable.hpp"
#include "Point.hpp"
#include "IShapeCloneable.hpp"

class IDescribableShape : public ISerializable, public IDescribableShapeCloneable
{
public:
	virtual	Point2D getCentroid() const = 0;
	virtual double getDescribedCircleRadius() const = 0;
	virtual void writeDescribedCircleRadius(std::ofstream& out) const = 0;
	virtual ~IDescribableShape() {};

private:
	IDescribableShape& operator=(const IDescribableShape&);
};


