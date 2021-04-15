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
	
	void setModel(const char* model);
	void setNumber(const char* number);
	void setColor(const Color color);
	void setOwner(const Person owner);

	char* getModel() const;
	char* getNumber() const;
	Color getColor() const;
	Person getOwner() const;

	void print();
};

