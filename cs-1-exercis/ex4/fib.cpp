#include <iostream>
#include "FibonacciCalculator.h"

using namespace std;


/*
class Polynomial - representing a polynoms of Nth
An * x^n + An-1 * x^n-1 ... + A1 * n + A0;

Polynomial p(maxN);
p.setCoefficient(n, An);

e.g.
5x^2 + 3
Polynomial p(10);
p.setCoefficient(2, 5);
p.setCoefficient(0, 3);

p.print();
p1 + p2
p1 - p2
p1 += p2
p1 -= p2
p1 == p2
p1 != p2

*/


int main() {
	FibonacciCalculator f(10);

	for (int i = 0; i <= 15; i++) {
		cout << "fib(" <<  i << ")=" << f.calculate(i) << endl;	
	}
	return 0;
}
