#pragma once
#include "Book.h"
#include "Utils.h"


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

	void printBookByPrice(priceFilter pf);

	void printBookWithLowestPrice();

	void printBookWithHighestPrice();
};

