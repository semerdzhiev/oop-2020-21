#include "DynArray.h"
#include <iostream>


DynArray create(size_t capacity) {
	DynArray dynArray;
	dynArray.capacity = capacity;
	dynArray.size = 0;
	dynArray.arr = new int[dynArray.capacity];
	return dynArray;
}

void push_back(DynArray& dynArray, int element) {
	if (dynArray.size == dynArray.capacity) {
		resize(dynArray);
	}

	dynArray.arr[dynArray.size++] = element;
}

void resize(DynArray& dynArray) {
	dynArray.capacity *= 2;

	int* old = dynArray.arr;
	dynArray.arr = new int[dynArray.capacity];

	for (size_t i = 0; i < dynArray.size; i++) {
		dynArray.arr[i] = old[i];
	}

	delete[] old;

}

void pop_back(DynArray& dynArray) {

	if (dynArray.size == 0) {
		return;
	}

	dynArray.size--;
}

void remove(DynArray& dynArray, size_t index) {
	if (index < 0 || index >= dynArray.size) {
		std::cout << "Not valid index" << std::endl;
		return;
	}

	for (size_t i = index; i < dynArray.size - 1; i++) {
		dynArray.arr[i] = dynArray.arr[i + 1];
	}

	dynArray.size--;
}

int get(DynArray& dynArray, size_t index) {
	if (index < 0 || index >= dynArray.size) {
		std::cout << "Not valid index" << std::endl;
		return -1;
	}

	return dynArray.arr[index];
}

void print(DynArray dynArray) {

}

void eraseDynMemory(DynArray& dynArray) {
	delete[] dynArray.arr;
}
