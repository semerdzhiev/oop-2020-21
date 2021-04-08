#pragma once
#include "Car.h"

class Parking
{

private:
	char* m_name;
	Car* m_cars;
	size_t m_size;
	size_t m_capacity;

	void resize();

	void copy(const Parking& p);

	void erase();

public:

	Parking();

	Parking(const Parking& p);

	Parking& operator=(const Parking& other);

	~Parking();

	void setName(const char* name);

	char* getName() const;
	Car* getCars() const;
	size_t getSize() const;
	size_t getCapacity() const;

	void addCar(const Car& c);

	void remove(int index);

};

