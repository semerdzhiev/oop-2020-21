#include "Car.h"
#include "Utils.h"
#include <iostream>


void Car::erase() {
	if (m_model) {
		delete[] m_model;
	}

	if (m_number) {
		delete[] m_number;
	}
}

void Car::copy(const Car& c) {
	m_model = copyDynStr(c.m_model);
	m_number = copyDynStr(c.m_number);
	m_color = c.m_color;
	m_owner = c.m_owner;
}

Car::Car() : m_owner() {
	m_model = copyDynStr("N/A");
	m_number = copyDynStr("N/A");
	m_color = NONE;
}


Car::Car(const Car& c) {
	copy(c);
}

Car& Car::operator=(const Car& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Car::~Car() {
	erase();
}

void Car::setModel(const char* model) {
	if (m_model) {
		delete[] m_model;
	}
	m_model = copyDynStr(model);
}

void Car::setNumber(const char* number) {
	if (m_number) {
		delete[] m_number;
	}
	m_number = copyDynStr(number);
}

void Car::setColor(const Color color) {
	m_color = color;
}

void Car::setOwner(const Person owner) {
	m_owner = owner;
}

char* Car::getModel() const {
	return m_model;
}

char* Car::getNumber() const {
	return m_number;
}

Color Car::getColor() const {
	return m_color;
}

Person Car::getOwner() const {
	return m_owner;
}


void Car::print() {
	std::cout << "Model: " << m_model << std::endl;
	std::cout << "Number: " << m_number << std::endl;
	std::cout << "Color: " << m_color << std::endl;
	std::cout << "Owner: ";
	m_owner.print();
}

