#include "Utils.h"
#pragma warning(disable : 4996)
#include <cstring>

void copyStr(char* buffer, char*& field) {
	field = new char[strlen(buffer) + 1];
	strcpy(field, buffer);
}

bool isBigger(double num1, double num2) {
	return num1 < num2;
}

bool isSmaller(double num1, double num2) {
	return num1 > num2;
}

