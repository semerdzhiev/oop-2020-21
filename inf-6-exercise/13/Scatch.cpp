#include "Scatch.h"

#include <iostream>

void Scatch::copy(const Scatch& other)
{
	this->figures.resize(other.figures.size());

	for (Figure* currentFigure : other.figures)
	{
		// виртуалната функция clone ще създаде динамично
		// копие на фигурата, независимо дали е обикновен или цветен кръг
		this->figures.push_back(currentFigure->clone());
	}
}

void Scatch::clear()
{
	for (Figure* currentFigure : this->figures)
	{
		delete currentFigure;
	}
}

Scatch::Scatch(const Scatch& other)
	: figures(other.figures.size())
{
	copy(other);
}

Scatch& Scatch::operator=(const Scatch& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}

	return *this;
}

Scatch::~Scatch()
{
	this->clear();
}

void Scatch::addFigure(Figure* newFigure)
{
	// добавяне на динамично копие на подадената фигура...
	this->figures.push_back(newFigure->clone());
}

Figure* Scatch::at(size_t position)
{
	return this->figures[position];
}

const Figure* Scatch::at(size_t position) const
{
	return this->figures[position];
}

void Scatch::print() const
{
	std::cout << "\nScatch: (" << this->figures.size() << ") figures\n";
	for (Figure* currentFigure : this->figures)
	{
		currentFigure->print();
		std::cout << std::endl;
	}
}