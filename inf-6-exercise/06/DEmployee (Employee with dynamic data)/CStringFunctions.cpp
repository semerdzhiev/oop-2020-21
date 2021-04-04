#define _CRT_SECURE_NO_WARNINGS

#include "CStringFunctions.h"

#include <cstring>

void createDynCopy(char*& destination, const char* source)
{
	if (source)
	{
		size_t len = strlen(source);

		destination = new char[len + 1];
		strncpy(destination, source, len);
		destination[len] = '\0';
	}
	else
	{
		// source == nullptr
		destination = nullptr;
	}
}
