#include <iostream>
#include "polynom.h"

using namespace std;

int main() {
	Polynom p1(5); // 5x^2 + 3
	p1.setCoefficient(2, 5);
	p1.setCoefficient(0, 3);	
	p1.print();

	Polynom p2; // 5x^2 + 5x
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