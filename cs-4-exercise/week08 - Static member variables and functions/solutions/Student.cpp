#include "Student.h"
#include "Utils.h"


void Student::erase() {
	delete[] m_name;
}

void Student::copy(const Student& other) {
	m_name = copyDynStr(other.m_name);
	m_facultyNumber = other.m_facultyNumber;
	m_hasSubject = other.m_hasSubject;
}

Student::Student(const char* name, int facultyNumber, bool hasSubject) {
	m_name = copyDynStr(name);
	m_facultyNumber = facultyNumber;
	m_hasSubject = hasSubject;
}

Student::Student(const Student& other) {
	copy(other);
}

Student& Student::operator=(const Student& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Student::~Student() {
	erase();
}