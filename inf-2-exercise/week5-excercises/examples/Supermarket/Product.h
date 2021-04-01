#pragma once

#include <string>
#include <iostream>

class Product {
private:
	std::string name;
	double currPrice;
	double normalPrice;

public:
	std::string getName();

	void print();
	bool withDiscount();
	bool cheaper(const Product& other);
	Product(std::string name = "", double currPrice = 0, double normalPrice = 0);
};

