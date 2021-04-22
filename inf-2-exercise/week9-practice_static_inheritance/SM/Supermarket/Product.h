#pragma once

#include <string>
#include <iostream>

class Product {
private:
	std::string name;
	double currPrice;
	double normalPrice;

public:
	std::string getName() const;
	double getCurrPrice() const;

	bool operator==(const Product& other);

	void print(std::ostream& out) const;
	bool withDiscount();
	bool cheaper(const Product& other);
	Product(std::string name = "", double currPrice = 0, double normalPrice = 0);
};

std::ostream& operator<<(std::ostream& out, const Product& p);

