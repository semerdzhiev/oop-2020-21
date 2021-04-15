#include "Parking.h"
#include "Utils.h"
#include <iostream>


void Parking::resize() {
	m_capacity *= INCREMENT_STEP;
	Car* temp = m_cars;
	m_cars = new Car[m_capacity];

	for (int i = 0; i < m_size; i++) {
		m_cars[i] = temp[i];
	}

	delete[] temp;
}

void Parking::copy(const Parking& p) {
	m_size = p.m_size;
	m_capacity = p.m_capacity;

	m_cars = new Car[m_capacity];

	for (int i = 0; i < m_size; i++) {
		m_cars[i] = p.m_cars[i];
	}

	m_name = copyDynStr(p.m_name);
}

void Parking::erase() {
	if (m_name) {
		delete[] m_name;
	}

	if (m_cars) {
		delete[] m_cars;
	}
}


Parking::Parking() {
	m_size = 0;
	m_capacity = INITIAL_CAPACITY;
	m_cars = new Car[m_capacity];
	m_name = copyDynStr("N/A");
}

Parking::Parking(const Parking& p) {
	copy(p);
}

Parking& Parking::operator=(const Parking& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Parking::~Parking() {
	erase();
}


void Parking::setName(const char* name) {
	delete[] m_name;
	m_name = copyDynStr(name);
}

char* Parking::getName() const {
	return m_name;
}

Car* Parking::getCars() const {
	return m_cars;
}

size_t Parking::getSize() const {
	return m_size;
}

size_t Parking::getCapacity() const {
	return m_capacity;
}

void Parking::addCar(const Car& car) {

	if (m_size >= m_capacity) {
		resize();
	}

	m_cars[m_size] = car;
	m_size++;
}


void Parking::remove(int index) {
	if (index < 0 || index > m_size - 1) {
		std::cout << "Invalid index" << std::endl;
		return;
	}


	for (int i = index; i < m_size - 1; i++) {
		m_cars[i] = m_cars[i + 1];
	}

	m_size--;
}

