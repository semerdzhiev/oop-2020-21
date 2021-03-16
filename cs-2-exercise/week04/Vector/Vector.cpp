#include "Vector.h"

Vector::Vector()
{
	//TDB
}

Vector::Vector(size_t n)
{ 
	size = n;
	arr = new int[n]; // TDB how to handle error
}

Vector::Vector(const Vector& obj)
{
	//TDB
}

void Vector::putValue(int position, int el)
{
	arr[position] = el; // TDB position >= size or negative?
}

size_t Vector::getSize() const
{
	return size;
}
int Vector::getValue(int position) const {
	//correct position?
	return arr[position];
}

void Vector::add(const Vector& obj) {
	//TBD are sizes same?
	for (size_t i = 0; i < getSize();i++) {
		arr[i] += obj.arr[i];
	}
}

Vector::~Vector()
{
	//TBD
}

Vector& Vector::operator+= (Vector const& obj) {
	//TBD are sizes same?
	for (size_t i = 0; i < size; i++) {
		arr[i] += obj.arr[i];
	}
	return *this;
}

Vector Vector::operator+ (Vector const& obj) {
	//TBD are sizes same?
	Vector result(*this);
	result += obj;
	return result;
}

const int& Vector::operator[](size_t index) const {
	//TBD in the limit?
	return arr[index];
}

int& Vector::operator[](size_t index) {
	//TBD in the limit?
	return arr[index];
}

bool Vector::operator==(Vector const& obj)
{
	if (getSize() != obj.getSize()) {
		return false;
	}
	for (size_t i = 0; i <getSize(); i++) {
		if (arr[i] != obj[i]) {
			return false;
		}
	}

	return true;
}