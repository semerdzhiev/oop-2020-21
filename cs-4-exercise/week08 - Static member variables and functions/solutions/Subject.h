#pragma once
#include "University.h"

class Subject
{
private:
	static University* m_uni;
	int* m_facultyNumbers;
	size_t m_size;
	size_t m_capacity;

	void erase();

	void copy(const Subject& other);

public:
	static void setUni(University* uni);

	Subject();

	Subject(const Subject& other);


	Subject& operator=(const Subject& other);

	~Subject();

	void addFacultyNumber(int facultyNumber);

	void printStudentsWithoutSubject();

	Student& operator[](int index);

};

