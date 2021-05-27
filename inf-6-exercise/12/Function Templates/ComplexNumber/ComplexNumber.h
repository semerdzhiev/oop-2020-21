#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

#include <iostream>

class ComplexNumber
{
	friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& c);
	friend std::istream& operator>>(std::istream& in, ComplexNumber& c);

	public:
		ComplexNumber() = default;
		ComplexNumber(double real, double imaginary);

		ComplexNumber& operator+=(const ComplexNumber& right);
		ComplexNumber& operator+=(double right);

		bool operator!() const;
		double module() const;

		// връща комплексно спрегнато
		ComplexNumber operator-() const;

		// ++c
		ComplexNumber& operator++();

		// c++
		ComplexNumber operator++(int dummy);

	private:
		double re{ 0 };
		double im{ 0 };
};

ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber operator+(double left, const ComplexNumber& right);
ComplexNumber operator+(const ComplexNumber& left, double right);

bool operator==(const ComplexNumber& left, const ComplexNumber& right);
bool operator!=(const ComplexNumber& left, const ComplexNumber& right);

#endif // !COMPLEXNUMBER_H_INCLUDED
