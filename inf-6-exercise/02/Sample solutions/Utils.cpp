#include "Utils.h"

#include <climits>
#include <iostream>

void readString(char* str, size_t length)
{
	std::cin.get(str, length, '\n');

	if (!std::cin)
	{
		std::cin.clear();
	}

	// ignore what is left in the buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

unsigned int readPositiveInteger()
{
	// bool success = true;

	int number = -1;
	do
	{
		std::cin >> number;

		if (!std::cin)
		{
			std::cin.clear();
		}

		// ignore what is left in the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
	} while (number <= 0);

	return number;
}

unsigned int readPositiveInteger(unsigned int upperBound)
{
	unsigned number = upperBound;
	do
	{
		number = readPositiveInteger();

	} while (number > upperBound);

	return number;
}

double readNonNegativeDouble()
{
	double number = 0;
	do
	{
		std::cin >> number;

		if (!std::cin)
		{
			std::cin.clear();
		}

		// ignore what is left in the buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (number <= 0);

	return number;
}