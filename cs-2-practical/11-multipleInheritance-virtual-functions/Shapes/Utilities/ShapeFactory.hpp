#pragma once
#include <string>

#include "Rectangle.h"
#include "Square.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "ScaleneTriangle.h"

class IDescribableShape;
class ShapeFactory
{
public:
	static IDescribableShape* create(std::string type)
	{
		if (type == "rectangle")
		{
			return new Rectangle();
		}
		else if (type == "square")
		{
			return new Square(0, 0);
		}
		else if (type == "equilateral-triangle")
		{
			Point2D zero = { 0,0 };
			return new EquilateralTriangle(zero, zero, zero);
		}
		else if (type == "isosceles-triangle")
		{
			Point2D zero = { 0,0 };
			return new IsoscelesTriangle(zero, zero, zero);
		}
		else if (type == "scalene-triangle")
		{
			Point2D zero = { 0,0 };
			return new ScaleneTriangle(zero, zero, zero);
		}
		else
		{
			throw "Unknown type";
		}

		return nullptr;
	}
};
