#include <iostream>

// forward declarations
void functionWithLocalVariable();
void functionWithStaticVariable();

extern int g_var;
//extern int gs_var;

int main()
{
	functionWithLocalVariable();
	functionWithLocalVariable();

	functionWithStaticVariable();
	functionWithStaticVariable();

	std::cout << "Forwarded global variable: " << &g_var << " value: " << g_var << std::endl;
	//std::cout << "Forwarded global static variable: " << gs_var << std::endl;

	return 0;
}
