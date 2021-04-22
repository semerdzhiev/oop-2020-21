#include "Product.h"

const double eps = 0.001;

bool equal(double d1, double d2) {
	return abs(d1 - d2) < eps;
}

std::string Product::getName() const {
	return name;
}

double Product::getCurrPrice() const {
	return currPrice;
}

bool Product::operator==(const Product& other) {
	return name == other.name;
}

void Product::print(std::ostream& out) const {
	out << name << " " << currPrice << " " << normalPrice << std::endl;
}

bool Product::withDiscount() {
	return (currPrice < normalPrice && !equal(currPrice, normalPrice));
}

bool Product::cheaper(const Product& other) {
	return (currPrice < other.currPrice && !equal(currPrice, other.currPrice));
}

Product::Product(std::string name, double currPrice, double normalPrice):
	name(name), currPrice(currPrice), normalPrice(normalPrice) {}

std::ostream& operator<<(std::ostream& out, const Product& p) {
	p.print(out);
	return out;
}
