#include "Book.h"
#include "Library.h"
#include<iostream>


int main() {
	Library l;
	l.create(4);
	l.addBook();
	l.addBook();


	Book bestBook = l.getBestBook();
	bestBook.print();

	
	std::cout << "Print Book With Highest Price" << std::endl;
	l.printBookWithHighestPrice();

	std::cout << "Print Book With Lowest Price" << std::endl;
	l.printBookWithLowestPrice();
	return 0;
}