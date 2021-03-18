#include "Stack.h"

Stack::Stack() {
	size = 0;
	maxSize = 4;
	arr = new int[maxSize]; // TBD errors
}

Stack::Stack(const Stack& stack1) {
	createObj(stack1);
}

Stack& Stack::operator=(const Stack& stack1) {
	if (this != &stack1) {
		deleteObj();
		createObj(stack1);
	}
	return *this;
}

Stack::~Stack() {
	deleteObj();
}

Stack::Stack(int maxSize) {
	size = 0;
	this->maxSize = maxSize;
	arr = new int[maxSize];
}

bool Stack::push(int el) {
	if (size == maxSize) {
		maxSize *= 2;
		int* newArr = new int[maxSize]; // BTD error
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}
	arr[size++] = el;
	return true;
}

bool Stack::pop() {
	if (size == 0) {
		return false;
	}
	size--;
	return true;
}

int Stack::top() const {
	if (size == 0) {
		return -1; // TBD error
	}
	return arr[size - 1];
}

void Stack::deleteObj() {
	size = maxSize = 0;
	delete[] arr;
}

int Stack::getSize() {
	return size;
}

void Stack::createObj(const Stack& stack1) {
	this->arr = new int[stack1.maxSize]; //TBD error
	this->size = stack1.size;
	this->maxSize = stack1.maxSize;
	for (int i = 0; i < size; i++) {
		this->push(stack1.arr[i]);
	}
}
