#include "Utils.h"
#include <cstring>

char* copyDynStr(const char* str) {
	char* res = nullptr;
	if (str) {
		size_t len = strlen(str) + 1;
		res = new (std::nothrow) char[len];
		strcpy_s(res, len, str);
	}
	return res;
}