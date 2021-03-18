#include "Book.h"
#include "Utils.h"
#include <iostream>
#include <cstring>

const int SIZE = 100;

void Book::initiate() {

	char buffer[SIZE];

	std::cout << "Title\n";
	std::cin.getline(buffer, SIZE);
	copyStr(buffer, this->title);

	std::cout << "Author\n";
	std::cin.getline(buffer, SIZE);
	copyStr(buffer, this->author);

	std::cout << "Genre\n";
	std::cin.getline(buffer, SIZE);
	copyStr(buffer, this->genre);

	std::cout << "Price\n";
	std::cin >> this->price;
	
	std::cout << "Sales\n";
	std::cin >> this->sales;
	std::cin.ignore();


	std::cout << std::endl << std::endl;

}

void Book::print() {
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Genre: " << this->genre << std::endl;
	std::cout << "Price: " << this->price << std::endl;
	std::cout << "Sales: " << this->sales << std::endl << std::endl;
}

void Book::freeMemory() {
	delete[] this->title;
	delete[] this->author;
	delete[] this->genre;
}
