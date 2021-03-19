#pragma once
#include <string>
#include <iostream>

class Product {
private:
	std::string name;
	double currPrice;
	double normalPrice;

public:
	void print();
	bool withDiscount();
};

