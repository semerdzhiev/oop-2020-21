#include <iostream>

using namespace std;


// only if we are going to work with dynamic memory
class X {
public:
	X() {
		cout << "constructor of X" << endl;
	}

	X(const X & x) {
		cout << "copy-constructor of X" << endl;
		copy(x);
	}

	// X(const X && x) {
	// 	cout << "move-constructor of X" << endl;
	// }
	/*
		X createX() {
			X x;
			return x;
		}

		// move semantic
		X myx = createX();
	*/

	X& operator=(const X & x) {
		cout << "operator= of X" << endl;
		if (this != &x) {	// a = a
			free();
			copy(x);
		}
		return *this;
	}
	
	~X() {
		cout << "destructor of X" << endl;
		free();
	}
private:
	copy(const X & x) {}
	free() {}
};


void print(X x) {
	cout << "printing x" << endl;
}

void print(int a) {
	cout << a << endl;
}

int main() {
	{
		int x; // 1. the compiler & runtime must allocate memory
		// ==, !=, <, >, ?, [] ... 

		x = 10; // 2. we are saving the value "10" in the allocated memory
		// int& operator=(int&, int&)


		print(x); // 5. the compiler allocates additional memory in the stack for "a" and copies "x" on top of it
		
		int y = 5; // 3. = 1. + 2.
		print(y);
	} // 4. the compilers frees the memory taken by x & y

	{
		cout << "X to be created" << endl;
		X x; // consturctor is called
		print(x); // pass by value. Copy-constuctor is called
		
		cout << "Y to be created" << endl;
		X y = x; // copy-constructor is called
		
		cout << "Z to be created" << endl;
		X z; // consturctor is called
		z = x; // operator=
	} // destructor is called
	cout << "out of scope" << endl;



	return 0;
}