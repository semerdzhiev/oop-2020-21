#ifndef COLOUREDCIRCLE_H
#define COLOUREDCIRCLE_H

#include "Circle.h"
#include "Point.h"

class ColouredCircle : public Circle
{
	public:
		// динамична памет за colour => задължително поне функциите от rule of 3
		ColouredCircle(const Point& center, double radius, const char* colour);
		ColouredCircle(const ColouredCircle& other);
		ColouredCircle& operator=(const ColouredCircle& other);
		~ColouredCircle();

		const char* getColour() const { return this->colour; }
		void setColour(const char* colour);

		void print() const;

	private:
		char* colour{ nullptr };
};

#endif // !COLOUREDCIRCLE_H
