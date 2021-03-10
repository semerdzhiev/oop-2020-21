#pragma once
struct Book
{
	char* title;
	char* author;
	char* genre;
	double price;
	int sales;

	void initiate();

	void print();

	void freeMemory();
};

