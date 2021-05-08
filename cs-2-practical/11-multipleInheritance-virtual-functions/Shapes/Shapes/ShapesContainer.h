#pragma once
#include "Shape.h"
class ShapesContainer
{
public:
	ShapesContainer(size_t capacity = 16);
	ShapesContainer(const ShapesContainer& other);
	ShapesContainer& operator=(const ShapesContainer& other);
	~ShapesContainer();

public:
	void add(IDescribableShape* newShape);
	IDescribableShape* operator[](int index);
	const IDescribableShape* operator[](int index) const;
	friend std::ostream& operator<<(std::ostream& out, const ShapesContainer& shapes);
	friend std::istream& operator>>(std::istream& in, ShapesContainer& shapes);

private:
	void copy(const ShapesContainer& other);
	void clean();
private:
	IDescribableShape** f_elements;
	size_t f_capacity;
	size_t f_size;
};

