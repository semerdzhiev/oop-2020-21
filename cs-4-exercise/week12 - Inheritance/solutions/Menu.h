#pragma once
#include "Food.h"

class Menu
{
private:
	Food** foods;
	int size;
	int capacity;

	void copy(const Menu& m);

	void erase();

	void resize();

public:
	Menu(int capacity = 4);

	Menu(const Menu& m);

	Menu& operator=(const Menu& other);

	~Menu();

	void print();

	const Food* operator[](int index) const;

	void addFood(Food* f);

	void remove(const Food* f);

	void getCheapestFood();

	void consumeFood(const Food* f);
};

