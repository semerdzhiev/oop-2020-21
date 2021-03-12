#include <iostream>

#include "ErrorConstants.h"
#include "UserInput.h"


int main () {

	int size;
	ErrorCode error;
	int *data = readArrayFromInput(size, error);
	if (data == nullptr) {
		std::cout << getErrorMessage(error) << std::endl;

		return 0;
	}

	int max = 0;
	for (int c = 0; c < size; c++) {
		if (data[c] > data[max]) {
			max = c;
		}
	}

	std::cout << "Max element = " << data[max];
	delete[] data;
	return 0;
}
