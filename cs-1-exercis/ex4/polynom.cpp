#include <iostream>
#include "FibonacciCalculator.h"

using namespace std;


/*
	Representing polynoms of Nth degree
	An * x^n + An-1 * x^n-1 ... + A1 * n + A0;
*/
class Polynom {
public: 
	Polynom(int maxN) {
		this->maxN = maxN;
		this->coefficients = new double[maxN + 1];
		for (int i = 0; i <= maxN; i++) {
			coefficients[i] = 0;
		}
	}

	Polynom(const Polynom & other) {
		copy(other);
	}

	Polynom& operator=(const Polynom & other) {
		if (this != &other) {
			destroy();
			copy(other);
		}
		return *this;
	}

	~Polynom() {
		destroy();
	}

	double getCoefficient(int n) const {
		if (0 <= n && n <= this->maxN) {
			return this->coefficients[n];
		} else {
			return 0;	
		}
	}

	void setCoefficient(int n, double coefValue) {
		if (n > this->maxN) {
			extend(n);
		}
		if (0 <= n && n <= this->maxN) {
			this->coefficients[n] = coefValue;	
		}

	}

	void print() const {
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

	Polynom operator+(const Polynom & other) {
		Polynom result(max(this->maxN, other.maxN));
		result += *this;
		result += other;
		return result;
	}

	Polynom operator-(const Polynom & other) {
		Polynom result(max(this->maxN, other.maxN));
		result += *this;
		result -= other;
		return result;
	}

	Polynom & operator+=(const Polynom & other) {
		if (this->maxN < other.maxN) { // remove after we implement the extend() method
			// ignore for now
		}
		for (int i = 0; i <= this->maxN; i++) {
			this->setCoefficient(i, this->getCoefficient(i) + other.getCoefficient(i));
		}
		return *this;
	}

	Polynom & operator-=(const Polynom & other) {
		if (this->maxN < other.maxN) { // remove after we implement the extend() method
			// ignore for now
		}
		for (int i = 0; i <= this->maxN; i++) {
			this->setCoefficient(i, this->getCoefficient(i) - other.getCoefficient(i));
		}
		return *this;
	}

	bool operator==(const Polynom & other) const {
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

	bool operator!=(const Polynom & other) const {
		return !this->operator==(other);
	}
private:
	void copy(const Polynom & other) {
		this->maxN = other.maxN;
		this->coefficients = new double[this->maxN + 1];
		for (int i = 0; i <= this->maxN; i++) {
			this->coefficients[i] = other.coefficients[i];
		}
	}

	void destroy() {
		if (coefficients) {
			delete[] coefficients;	
		}
	}

	void extend(int newMaxN) {
		// 
	}

private:
	int maxN;
	double * coefficients;

};

int main() {
	Polynom p1(10); // 5x^2 + 3
	p1.setCoefficient(2, 5);
	p1.setCoefficient(0, 3);	
	p1.print();

	Polynom p2(10); // 5x^2 + 5x
	p2.setCoefficient(2, 5);
	p2.setCoefficient(1, 5);
	p2.print();

	cout << "p1 == p1: " << (p1 == p1) << endl;
	cout << "p1 == p2: " << (p1 == p2) << endl;
	cout << "p1 + p2: ";
	(p1+p2).print();

	cout << "p1 - p2: ";
	(p1-p2).print();

	cout << "p1 - p1: ";
	(p1-p1).print();


	return 0;
}