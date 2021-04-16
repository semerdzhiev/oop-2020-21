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

FibonacciCalculator::FibonacciCalculator(const FibonacciCalculator & other) { // copy-constructor
	this->copy(other);
}

FibonacciCalculator& FibonacciCalculator::operator=(const FibonacciCalculator & other) { // operator=
	// FibonacciCalculator * this
	// FibonacciCalculator & other
	if (this != &other) {
		this->destroy();
		this->copy(other);
	}
	return *this;
}

FibonacciCalculator::~FibonacciCalculator() { // Destructor
	this->destroy();
	cout << "Deleting Fibonacci instance" << endl;
}	

long FibonacciCalculator::calculate(int n) {
	if (n <= 0) {
		return 1;
	}

	if (n > this->n) {
		// option 1: throw exception
		// option 2: return -1;
		this->expandCache(n); // option 3
	}

	if (n == 1 || n == 2) {
		return 1;
	}

	if (this->cache[n] == -1) {
		this->cache[n] = calculate(n-1) + calculate(n-2);
	}

	return cache[n];
}

void FibonacciCalculator::copy(const FibonacciCalculator & other) {
	this->n = other.n;
	this->cache = new long[this->n + 1];
	for (int i = 0; i <= n; i++) {
		this->cache[i] = other.cache[i];
	}
}

void FibonacciCalculator::destroy() {
	if (this->cache) {
		delete[] this->cache;	
	}
}

void FibonacciCalculator::expandCache(int n) {
	const int expandBuffer = 2;
	long * newCache = new long[n + 1 + expandBuffer];
	for (int i = 0; i <= n + expandBuffer; i++) {
		if (i <= this->n) {
			newCache[i] = this->cache[i];
		} else {
			newCache[i] = -1;
		}
	}
	delete[] this->cache;
	this->n = n + expandBuffer;
	this->cache = newCache;
	cout << "Cache expanded to size: " << this->n << endl;
}
