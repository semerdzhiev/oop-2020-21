#include <iostream>
using namespace std;

class ComplexNumber {
private:
	double real; // член-данни, полета, атрибути | fields, attributes | properties
	double imaginary;

public:
	// ComplexNumber() {
	// 	this->real = 0;
	// 	this->imaginary = 0;
	// }

	ComplexNumber(double real = 0, double imaginary = 0) {
		// we prefer:
		setReal(real);
		setImaginary(imaginary);
		// over:
		// this->real = real;
		// this->imaginary = imaginary;
	}

	/* Generated by the compiler
	ComplexNumber(){} // default constructor
	ComplexNumber(const ComplexNumber& other){
		this->real = other.real;
		this->imaginary = other.imaginary;
	} // copy constructor
	ComplexNumber& operator=(const ComplexNumber& other){
		if (this != &other) {
			this->real = other.real;
			this->imaginary = other.imaginary;
		}
		return *this;
	}
	~ComplexNumber(){}
	*/

	void print() const {
		cout << "(" << getReal() << " + " << getImaginary() << "i)" << endl;
	}

	ComplexNumber operator+(const ComplexNumber & other) const {
		ComplexNumber result;
		result.setReal(this->getReal() + other.getReal());
		result.setImaginary(this->getImaginary() + other.getImaginary());
		return result;
	}

	ComplexNumber & operator+=(const ComplexNumber & other) {
		this->setReal(this->getReal() + other.getReal());
		this->setImaginary(this->getImaginary() + other.getImaginary());
		return *this;
	}

	double getReal() const {
		return real;
	}

	void setReal(double real) {
		this->real = real;
	}

	double getImaginary() const {
		return imaginary;
	}

	void setImaginary(double imaginary) {
		this->imaginary = imaginary;
	}
};

int main() {
	// ComplexNumber a1, a2, a3;
	// a1 = a2 = a3;
	// a1.operator=(a2.operator=(a3));
	// a1 + a2 + a3

	ComplexNumber a1;
	a1.setReal(5);
	a1.setImaginary(3);
	a1.print();

	ComplexNumber a2 = a1;
	a2.print();
	
	ComplexNumber a3;
	a3 = a1;
	a3.print();

	ComplexNumber b1;
	b1.print();

	ComplexNumber b2(4, 2);
	b2.print();

	cout << "SUM" << endl;
	// ComplexNumber c = a1.sum(b2);
	// c.print();

	// a1.sum(b2).print(); // method chaining
	ComplexNumber c = a1 + b2;
	c.print();
	(a1 + b2).print();
	a1.print();
	b2.print();

	cout << "ADD" << endl;
	// a1.add(b2).print();
	a1 += b2;
	a1.print();
	b2.print();

	return 0;
}