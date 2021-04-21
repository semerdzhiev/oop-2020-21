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

	void addStudent(const char* m_name, int m_facultyNumber, bool m_hasSubject);

	void addStudent(const Student& s);

	size_t count();

	Student& operator[](size_t index);

	University operator+(const University& uni);

};

