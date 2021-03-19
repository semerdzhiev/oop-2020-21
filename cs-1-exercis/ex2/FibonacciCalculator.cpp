#include <iostream>
#include "FibonacciCalculator.h"
using namespace std;

FibonacciCalculator::FibonacciCalculator(int n) { // Constructor
	this->n = n;
	this->cache = new long[n + 1];
	for (int i = 0; i <= n; i++) {
		this->cache[i] = -1;
	}
	cout << "Fibonacci calculator created with n=" << n << endl;
}

FibonacciCalculator::~FibonacciCalculator() { // Destructor
	if (this->cache) {
		delete[] this->cache;	
	}
	cout << "Deleting Fibonacci instance" << endl;
}	

long FibonacciCalculator::calculate(int n) {
	if (n <= 0) {
		return 1;
	}

	if (n == 1 || n == 2) {
		return 1;
	}

	if (this->cache[n] == -1) {
		this->cache[n] = calculate(n-1) + calculate(n-2);
	}

	return cache[n];
}
