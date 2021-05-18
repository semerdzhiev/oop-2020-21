#include "ColouredCircleWithEnum.h"

const char* ColouredCircle::colours[] = { "red", "green", "blue", "white" };

ColouredCircle::ColouredCircle(const Point& center, double radius, Colour colour) 
	: Circle(center, radius), colour(colour)
{
	std::cout << "\nColouredCircle created" << std::endl;
	print();
}

ColouredCircle::Colour ColouredCircle::getColour() const
{
	return this->colour;
}

void ColouredCircle::setColour(ColouredCircle::Colour newColour)
{
	this->colour = newColour;
}

void ColouredCircle::print() const
{
	Circle::print();
	std::cout << "Colour " << colours[static_cast<int>(this->colour)] << std::endl;
}