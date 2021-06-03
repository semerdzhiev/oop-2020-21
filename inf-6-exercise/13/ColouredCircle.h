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
		virtual ~ColouredCircle();

		const char* getColour() const { return this->colour; }
		void setColour(const char* colour);

		// площта на цветния кръг се намира по същия начин както и на обикновен
		// няма нужда тук да бъде предефинирана функцията area

		// другите две функции се предефинират, очаква различно поведение с този клас
		virtual void print() const override;
		virtual Figure* clone() const override;

	private:
		char* colour{ nullptr };
};

#endif // !COLOUREDCIRCLE_H
