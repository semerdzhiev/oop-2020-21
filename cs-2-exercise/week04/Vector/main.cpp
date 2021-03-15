#include <iostream>
#include "Vector.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
	Vector a(3);
	a.putValue(0, 2);
	a.putValue(1, 4);
	a.putValue(2, 0);
	a.add(a);
	a += a;
	cout << a.getValue(1) << "=" <<a[1]<< endl;
	a[2] = 4;
	cout << a[2] << endl;
	cout << (a == a) << endl;
	return 0;
}