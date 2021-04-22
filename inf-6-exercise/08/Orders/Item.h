#pragma once

class Item
{
	public:
		// validation!
		Item() = default;
		Item(const char* id, const char* name, double price);
		Item(const Item& other);
		Item& operator=(const Item& other);
		~Item();

		const char* getID() const { return this->id; }
		const char* getName() const { return this->name; }
		double getPrice() const { return this->price; }

		// validation!
		void setID(const char*);
		void setName(const char*);
		void setPrice(double);

	private:
		char id[6]{"00000"};
		char* name{ nullptr };
		double price{ 0 };
};

bool operator==(const Item& left, const Item& right);
