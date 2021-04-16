#include <iostream>
#include "polynom.h"
using namespace std;

Polynom::Polynom(int maxN) {
	this->maxN = maxN;
	this->coefficients = new double[maxN + 1];
	for (int i = 0; i <= maxN; i++) {
		coefficients[i] = 0;
	}
}

Polynom::Polynom(const Polynom & other) {
	copy(other);
}

Polynom& Polynom::operator=(const Polynom & other) {
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

Polynom::~Polynom() {
	destroy();
}

double Polynom::getCoefficient(int n) const {
	if (0 <= n && n <= this->maxN) {
		return this->coefficients[n];
	} else {
		return 0;	
	}
}

void Polynom::setCoefficient(int n, double coefValue) {
	if (n > this->maxN) {
		extend(n);
	}
	if (0 <= n && n <= this->maxN) {
		this->coefficients[n] = coefValue;	
	}

}

void Polynom::print() const {
	for (int i = this->maxN; i >= 0; i--) {
		if (this->coefficients[i] != 0) {
			if (i == 1) {
				cout << this->coefficients[i] << "*x" << " + ";
			} else if (i == 0) {
				cout << this->coefficients[i] << " + ";
			} else {
				cout << this->coefficients[i] << "*x^" << i << " + ";	
			}
		}
	}
	cout << endl;
}

Polynom Polynom::operator+(const Polynom & other) {
	Polynom result = *this;
	result += other;
	return result;
}

Polynom Polynom::operator-(const Polynom & other) {
	Polynom result = *this;
	result -= other;
	return result;
}

Polynom & Polynom::operator+=(const Polynom & other) {
	for (int i = this->maxN; i >= 0; i--) { // Notice the change of order. This is in order to extend the memory only once
		this->setCoefficient(i, this->getCoefficient(i) + other.getCoefficient(i));
	}
	return *this;
}

Polynom & Polynom::operator-=(const Polynom & other) {
	for (int i = this->maxN; i >= 0; i--) { // Notice the change of order. This is in order to extend the memory only once
		this->setCoefficient(i, this->getCoefficient(i) - other.getCoefficient(i));
	}
	return *this;
}

// TODO: add tests
bool Polynom::operator==(const Polynom & other) const {
	if (this->maxN != other.maxN) {
		return false;
	}
	for (int i = 0; i <= this->maxN; i++) {
		if (this->coefficients[i] != other.coefficients[i]) {
			return false;
		}
	}
	return true;
}

bool Polynom::operator!=(const Polynom & other) const {
	return !this->operator==(other);
}

void Polynom::copy(const Polynom & other) {
	this->maxN = other.maxN;
	this->coefficients = new double[this->maxN + 1];
	for (int i = 0; i <= this->maxN; i++) {
		this->coefficients[i] = other.coefficients[i];
	}
}

void Polynom::destroy() {
	if (coefficients) {
		delete[] coefficients;	
	}
}

void Polynom::extend(int newMaxN) {
	if (this->maxN >= newMaxN) {
		return;
	}
	double * newCoefficients = new double[newMaxN + 1];
	for (int i = 0; i <= newMaxN; i++) {
		newCoefficients[i] = this->getCoefficient(i);
	}
	delete[] this->coefficients;
	this->maxN = newMaxN;
	this->coefficients = newCoefficients;
}
