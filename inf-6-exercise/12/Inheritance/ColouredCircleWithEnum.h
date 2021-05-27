#ifndef COLOUREDCIRCLE_H
#define COLOUREDCIRCLE_H

#include "Circle.h"

class ColouredCircle : public Circle
{
	public:
		enum class Colour{ RED, GREEN, BLUE, WHITE};

	public:
		ColouredCircle(const Point& center, double radius, Colour colour);

		// няма нужда да се дефинират копиращ конструктор,
		// операция за присвояване и деструктор

		Colour getColour() const;
		void setColour(Colour newColour);

		void print() const;
	private:
		 Colour colour{Colour::WHITE};

		 static const char* colours[];
};

#endif // !COLOUREDCIRCLE_H
