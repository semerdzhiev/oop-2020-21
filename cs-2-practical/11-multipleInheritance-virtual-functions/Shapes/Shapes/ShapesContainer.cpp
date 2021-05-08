#include "ShapesContainer.h"
#include "ShapeFactory.hpp"

ShapesContainer::ShapesContainer(size_t capacity) : f_capacity(capacity), f_size(0)
{
	f_elements = new IDescribableShape * [f_capacity];
}

ShapesContainer::ShapesContainer(const ShapesContainer& other)
{
	copy(other);
}

ShapesContainer& ShapesContainer::operator=(const ShapesContainer& other)
{
	if (this != &other)
	{
		clean();
		copy(other);
	}

	return *this;
}

ShapesContainer::~ShapesContainer()
{
	clean();
}

void ShapesContainer::add(IDescribableShape* newShape)
{
	f_elements[f_size] = newShape;
	f_size++;
}

IDescribableShape* ShapesContainer::operator[](int index)
{
	return f_elements[index];
}

const IDescribableShape* ShapesContainer::operator[](int index) const
{
	return f_elements[index];
}

void ShapesContainer::copy(const ShapesContainer& other)
{
	f_size = other.f_size;
	f_capacity = other.f_capacity;
	f_elements = new IDescribableShape * [f_capacity];

	for (size_t i = 0; i < f_size; i++)
	{
		f_elements[i] = other.f_elements[i]->clone();
	}
}

void ShapesContainer::clean()
{
	for (size_t i = 0; i < f_size; i++)
	{
		delete f_elements[i];
	}

	delete[] f_elements;
}

std::ostream& operator<<(std::ostream& out, const ShapesContainer& shapes)
{
	out << shapes.f_size << std::endl;
	for (size_t i = 0; i < shapes.f_size; i++)
	{
		shapes[i]->save(out);
	}

	return out;
}

std::istream& operator>>(std::istream& in, ShapesContainer& shapes)
{
	size_t size;
	in >> size;
	shapes.clean();
	shapes.f_size = 0;
	shapes.f_capacity = size;
	shapes.f_elements = new IDescribableShape * [size];

	std::string type;
	for (size_t i = 0; i < size; i++)
	{
		in >> type;
		shapes.f_elements[i] = ShapeFactory::create(type);
		shapes[i]->load(in);
		shapes.f_size++;
	}

	return in;
}
