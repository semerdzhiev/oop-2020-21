#pragma once
#include "Book.h"
struct Library
{
	size_t size;
	size_t capacity;
	Book* books;

	void create(size_t capacity);

	void resize();

	void addBook();

	void printBooks();

	void freeMemory();

	Book& getBestBook();

};

