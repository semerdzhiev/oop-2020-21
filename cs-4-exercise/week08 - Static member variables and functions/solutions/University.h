#pragma once
#include "Student.h"

class University
{

private:
	Student** m_students;
	size_t m_size;
	size_t m_capacity;

	void copy(const University& other);

	void erase();

	void resize();

public:
	University();

	University(const University& other);

	University& operator=(const University& other);

	~University();

};

