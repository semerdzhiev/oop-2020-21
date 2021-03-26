#ifndef ARRAY_FUNCTIONS_H_INCLUDED
#define ARRAY_FUNCTIONS_H_INCLUDED

struct Array
{
	int* data{ nullptr };
	size_t capacity{ 0 };
	size_t size{ 0 };
};

void allocateMemory(Array& array);
void freeMemory(Array& array);

bool resize(Array& array);

bool addElement(Array& array, int newElem);
bool addElement(Array& array, int newElem, size_t position);

void print(const Array& array);
bool removeElement(Array& array, size_t position);

#endif // !ARRAY_FUNCTIONS_H_INCLUDED
