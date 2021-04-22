#include "Subject.h"

void Subject::erase() {
	if (m_facultyNumbers) {
		delete[] m_facultyNumbers;
	}
}

void Subject::copy(const Subject& other) {
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	int* temp = m_facultyNumbers;
	m_facultyNumbers = new int [m_capacity];

	for (size_t i = 0; i < m_size; i++) {
		m_facultyNumbers[i] = other.m_facultyNumbers[i];
	}

	delete[] temp;
}

void resize() {
	//todo
}

void Subject::setUni(University* uni) {
	Subject::m_uni = uni;
}

Subject::Subject() {
	m_facultyNumbers = nullptr;
	m_size = 0;
	m_capacity = 4;
	m_facultyNumbers = new int[m_capacity];

}

Subject::Subject(const Subject& other) {
	copy(other);
}


Subject& Subject::operator=(const Subject& other) {
	if (&other != this) {
		erase();
		copy(other);
	}

	return *this;
}

Subject::~Subject() {
	erase();
}

void Subject::addFacultyNumber(int facultyNumber) {
	if (m_size < m_uni->count()) {

		if (m_size >= m_capacity) {
			resize();
		}
		m_facultyNumbers[m_size++] = facultyNumber;
		(*m_uni)[facultyNumber].setHasSubject(true);
	}
}

void Subject::printStudentsWithoutSubject() {
	for (size_t i = 0; i < m_uni->count(); i++) {
		if (!(*m_uni)[i].hasSubject()) {
			(*m_uni)[i].print();
		}
	}
 }

Student& Subject::operator[](int index) {
	return (*m_uni)[m_facultyNumbers[index]];
}