#pragma once
#include "Person.h"
#include "Color.h"

class Car
{

private:
	char* m_model;
	char* m_number;
	Color m_color;
	Person m_owner;

	void erase();

	void copy(const Car& c);

public:
	Car();

	Car(const Car& c);

	Car& operator=(const Car& other);

	~Car();
};

