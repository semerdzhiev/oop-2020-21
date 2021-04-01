#include "Product.h"

void Product::print() {
	std::cout << name << " " << currPrice << " " << normalPrice << std::endl;
}

bool Product::withDiscount() {
	return false;
}

