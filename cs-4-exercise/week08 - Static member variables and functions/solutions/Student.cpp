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

void Student::print() {
	std::cout << "STUDENT:" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "FacultyNumber: " << m_facultyNumber << std::endl;
	std::cout << "HasSubject: " << m_hasSubject << std::endl << std::endl;
}

void Student::setHasSubject(bool hasSubject) {
	m_hasSubject = hasSubject;
}

bool Student::hasSubject() const {
	return m_hasSubject;
}


