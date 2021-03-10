#include "Utils.h"
#pragma warning(disable : 4996)
#include <cstring>

void copyStr(char* buffer, char*& field) {
	field = new char[strlen(buffer) + 1];
	strcpy(field, buffer);
}
