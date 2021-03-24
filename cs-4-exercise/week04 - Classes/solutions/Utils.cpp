#include "Utils.h"
//#pragma warning(disable : 4996)
#include <cstring>

char* copyDynStr(const char* str) {
	char* res = new (std::nothrow) char[strlen(str) + 1];
	strcpy(res, str);
	return res;
}
