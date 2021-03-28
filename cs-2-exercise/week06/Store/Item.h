#pragma once
class Item
{
	double price;
	int id;
	int typeProduct;
	double applicableDiscound;
	int quantity;

public:
	Item();
	Item(const Item& item);
	Item(int id, double price);
	~Item();

	// TO DO: define operator=
	double getPrice() const;
	const double getApplicableDiscount() const;
	const int getQuantity() const;
	void setQuantity(int qty);
	void setPrice(double price);
	int getID() const;
	void setTypeProduct(int typeProduct);

};

