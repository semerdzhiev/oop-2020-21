#include "Car.h"
#include "Utils.h"


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
