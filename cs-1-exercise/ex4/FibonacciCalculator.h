#ifndef FibonacciCalculator_H
#define FibonacciCalculator_H

class FibonacciCalculator {
public:
	FibonacciCalculator(int n); // constructor
	FibonacciCalculator(const FibonacciCalculator & other); // copy-constructor
	FibonacciCalculator& operator=(const FibonacciCalculator & other); // operator=
	~FibonacciCalculator(); // destructor
	
	long calculate(int n);

private:
	void copy(const FibonacciCalculator & other);
	void destroy();
	void expandCache(int n);

	long * cache; // !!!
	int n;
};
#endif
