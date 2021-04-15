#include<iostream>

#include "Matrix.h"

int main()
{
	try
	{
		Matrix aBigOne(10, 1000000000);
	}
	catch (std::exception& e)
	{
		std::cout << "exception caught : " << e.what() << std::endl;
	}

	Matrix a{ 5, 5 };
	a.randomize();
	a.print();

	Matrix b{ 5, 10 };
	b.randomize();
	b.print();
	
	try 
	{
		Matrix m = a.getMultipliedBy(b);
		m.print();

		//trying to touch something that doesn't even exist
		m.setAt(7, 7, 11);
	}
	catch (std::out_of_range& e) {

		std::cout << "exception caught : " << e.what() << std::endl;
	}

	std::cout << "After the exception..." << std::endl;

	Matrix moved{ std::move(Matrix{3, 3}) };
	moved = std::move(Matrix{3, 3});

	return 0;
}