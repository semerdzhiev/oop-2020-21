#include <iostream>

// header files -> declarations only [.h]
// source files -> definitions [.cpp]

#include "helpers.h"
#include "functions.h"

#define MY_CONST f(5)

// c-style consts
// # - pre-processor instructions

using namespace std;

int main() {
	#ifdef MY_CONST
		cout << "I have a const .... " << endl;
	#endif

	#ifndef MY_CONST
		cout << "Missing my const :`(.... " << endl;
	#endif


	cout << g(f(5)) << endl;
	return 0;
}
