#include "ComplexNumber.h"

#include <cmath>

ComplexNumber::ComplexNumber(double real, double imaginary)
	: re(real), im(imaginary)
{}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber & right)
{
	this->re += right.re;
	this->im += right.im;

	return *this;
}

ComplexNumber& ComplexNumber::operator+=(double right)
{
	this->re += right;
	return *this;
}

bool ComplexNumber::operator!() const
{
	// a - b < eps
	double eps = 0.000001;
	return this->re < eps && this->im < eps;
}

double ComplexNumber::module() const
{
	return std::sqrt(this->re * this->re + this->im*this->im);
}

ComplexNumber ComplexNumber::operator-() const
{
	return ComplexNumber{ this->re, -this->im };
}

ComplexNumber& ComplexNumber::operator++()
{
	*this += 1;
	return *this;
}

ComplexNumber ComplexNumber::operator++(int dummy)
{
	ComplexNumber old = *this;
	++(*this);
	return old;
}

ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right)
{
	ComplexNumber result{ left };
	result += right;
	return result;
}

ComplexNumber operator+(double left, const ComplexNumber& right)
{
	return right + ComplexNumber{ left, 0 };
}

ComplexNumber operator+(const ComplexNumber& left, double right)
{
	return right + left;
}

bool operator==(const ComplexNumber& left, const ComplexNumber& right)
{
	double eps = 0.000001;
	return std::fabs(left.module() - right.module()) < eps;
}

bool operator!=(const ComplexNumber& left, const ComplexNumber& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& c)
{
	out << c.re << " + i*" << c.im;
	return out;
}

std::istream& operator>>(std::istream& in, ComplexNumber& c)
{
	in >> c.re;
	in >> c.im;

	return in;
}
