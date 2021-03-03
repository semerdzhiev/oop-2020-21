#pragma once
struct DynArray
{
	size_t size;
	size_t capacity;
	int* arr;
};

DynArray create(size_t capacity = 2);

void push_back(DynArray& dynArray, int element);

void resize(DynArray& dynArray);

void pop_back(DynArray& dynArray);

void remove(DynArray& dynArray, size_t index);

int get(DynArray& dynArray, size_t index);

void print(DynArray dynArray);

void eraseDynMemory(DynArray& dynArray);


