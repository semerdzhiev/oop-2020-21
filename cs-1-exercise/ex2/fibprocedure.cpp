#include <iostream>
#include "FibonacciCalculator.h"

using namespace std;

// Fibonacci
long fib(int n, long * cache) {
	if (n == 1 || n == 2) {
		return 1;
	}

	if (cache[n] == -1) {
		cache[n] = fib(n-1, cache) + fib(n-2, cache);
	}

	return cache[n];

}

long fib(int n) {
	if (n <= 0) {
		return 1;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	
	long * cache = new long[n+1];
	for (int i = 0; i <= n; i++) {
		cache[i] = -1;
	}
	long result = fib(n-1, cache) + fib(n-2, cache);
	delete[] cache;
	
	return result;
}

void doSomething(int x, FibonacciCalculator f) { // copy-constructor
	// currently will NOT work!!!
}

int main() {
	FibonacciCalculator f(100), f1(50), f2(50), f3(50), f4(50);
	{
		FibonacciCalculator g(5);
	}
	for (int i = 15; i >= 0; i--) {
		cout << "fib(" <<  i << ")=" << fib(i) << "\t\t|\t\t" << f.calculate(i) << endl;	
	}
	return 0;
}