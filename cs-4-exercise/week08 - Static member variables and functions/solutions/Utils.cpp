#include "Utils.h"


char* copyDynStr(const char* str) {
	char* newStr = nullptr;
	size_t len = strlen(str) + 1;
	try {
		newStr = new char[len];
	}
	catch (std::bad_alloc& exc) {
		return newStr;
	}

	strcpy_s(newStr, len, str);
}