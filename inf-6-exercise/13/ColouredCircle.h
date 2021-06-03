#ifndef COLOUREDCIRCLE_H
#define COLOUREDCIRCLE_H

#include "Circle.h"
#include "Point.h"

class ColouredCircle : public Circle
{
	public:
		// ��������� ����� �� colour => ������������ ���� ��������� �� rule of 3
		ColouredCircle(const Point& center, double radius, const char* colour);
		ColouredCircle(const ColouredCircle& other);
		ColouredCircle& operator=(const ColouredCircle& other);
		virtual ~ColouredCircle();

		const char* getColour() const { return this->colour; }
		void setColour(const char* colour);

		// ������ �� ������� ���� �� ������ �� ����� ����� ����� � �� ���������
		// ���� ����� ��� �� ���� ������������� ��������� area

		// ������� ��� ������� �� ������������, ������ �������� ��������� � ���� ����
		virtual void print() const override;
		virtual Figure* clone() const override;

	private:
		char* colour{ nullptr };
};

#endif // !COLOUREDCIRCLE_H
