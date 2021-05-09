#include <iostream>

// non-constant globals -- external linkage by default 
// unless static is used (a forward declaration cannot be used then)

static int gs_var = 10;
int g_var = 2;

void functionWithLocalVariable()
{
	int var = 2;
	std::cout << "var = " << var << std::endl;

	++var;
}

void functionWithStaticVariable()
{
	static int var = 7;
	std::cout << "var = " << var << std::endl;

	++var;
}






