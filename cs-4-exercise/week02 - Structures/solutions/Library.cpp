#include "Library.h"
#include <iostream>


void Library::create(size_t capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->books = new Book[this->capacity];
}

void Library::resize() {
	this->capacity *= 2;

	Book* old = this->books;
	this->books = new Book[this->capacity];

	for (size_t i = 0; i < this->size; i++) {
		this->books[i] = old[i];
	}

	delete[] old;
}

void Library::addBook() {
	Book book;
	book.initiate();

	if (this->size == this->capacity) {
		resize();
	}

	this->books[this->size++] = book;
}

void Library::printBooks() {

	std::cout << "Print Books:\n";
	for (size_t i = 0; i < this->size; i++) {
		this->books[i].print();
	}
}

void Library::freeMemory() {
	delete[] this->books;
}

Book& Library::getBestBook() {
	int maxSales = this->books[0].sales;
	int pos = 0;
	for (size_t i = 1; i < this->size; i++) {
		if (maxSales < this->books[i].sales) {
			maxSales = this->books[i].sales;
			pos = i;
		}	
	}

	return this->books[pos];
}

void Library::printBookByPrice(priceFilter pf) {
	double price = this->books[0].price;
	int pos = 0;
	for (size_t i = 1; i < this->size; i++) {
		if (pf(price, this->books[i].price)) {
			price = this->books[i].price;
			pos = i;
		}
	}

	this->books[pos].print();
}

void Library::printBookWithLowestPrice() {
	printBookByPrice(isSmaller);
}

void Library::printBookWithHighestPrice() {
	printBookByPrice(isBigger);
}

