#include "Menu.h"
#include <cassert>
#include <iostream>


void Menu::copy(const Menu& m) {
	this->capacity = m.capacity;
	this->size = m.size;
	this->foods = new Food * [this->capacity];

	for (int i = 0; i < this->size; i++) {
		foods[i] = m.foods[i]->clone();
	}
}

void Menu::erase() {
	for (int i = 0; i < size; i++) {
		delete foods[i];
	}

	delete[] foods;
}

void Menu::resize() {
	Food** temp = foods;
	this->capacity *= 2;
	this->foods = new Food * [capacity];

	for (int i = 0; i < size; i++) {
		foods[i] = temp[i]->clone();
	}

	delete[] temp;
}

Menu::Menu(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->foods = new Food * [this->capacity];
}

Menu::Menu(const Menu& m) {
	copy(m);
}

Menu& Menu::operator=(const Menu& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Menu::~Menu() {
	erase();
}

void Menu::print() {
	for (int i = 0; i < size; i++) {
		foods[i]->category();
		foods[i]->print();
		std::cout << std::endl;
	}
}

const Food* Menu::operator[](int index) const {
	assert(index >= 0 && index < size);
	return this->foods[index];
}

void Menu::addFood(Food* f) {
	if (size >= capacity) {
		resize();
	}

	foods[size] = f->clone();

	size++;
}

void Menu::remove(const Food* f) {
	for (int i = 0; i < size; i++) {
		if ((*foods[i]) == (*f)) {
			delete[] foods[i];
			foods[i] = foods[size - 1];
			foods[size - 1] = nullptr;
			size--;
			break;
		}
	}
}

void Menu::getCheapestFood() {
	assert(size > 0);

	if (size == 1) {
		foods[0]->print();
	}

	double lowestPrice = foods[0]->getPrice();
	int index = 0;

	for (int i = 1; i < size; i++) {
		if (foods[i]->getPrice() < lowestPrice) {
			lowestPrice = foods[i]->getPrice();
			index = i;
		}
	}

	std::cout << "Lowest price:" << lowestPrice << std::endl;
	foods[index]->category();
	foods[index]->print();
}

void Menu::consumeFood(const Food* f) {
	for (int i = 0; i < size; i++) {
		if ((*foods[i]) == (*f)) {
			foods[i]->consume();

			if (foods[i]->getParts() == 0) {
				remove(foods[i]);
			}
			break;
		}
	}
}