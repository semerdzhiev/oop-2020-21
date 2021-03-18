#include <iostream>

#include "UserInput.h"


int *readArrayFromInput(int &size, ErrorCode &error) {
	error = ERR_CODE_NO_ERR;
	std::cin >> size;
	if (size <= 0) {
		error = ERR_CODE_WRONG_INPUT;
		return nullptr;
	}
	int *data = new (std::nothrow) int[size];
	if (!data) {
		error = ERR_CODE_NO_MEM;
		return nullptr;
	}

	for (int c = 0; c < size; c++) {
		std::cin >> data[c];
	}

	return data;
}