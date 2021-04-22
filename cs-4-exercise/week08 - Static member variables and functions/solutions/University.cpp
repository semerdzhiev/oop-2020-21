#include "University.h"
#include <iostream>


void University::copy(const University& other) {

	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_students = new Student * [m_capacity];

	for (size_t i = 0; i < m_size; i++) {
		m_students[i] = new Student(* other.m_students[i]);
	}
}

void University::resize() {
	m_capacity *= 2;
	Student** temp = m_students;
	m_students = new Student * [m_capacity];

	for (size_t i = 0; i < m_size; i++) {
		m_students[i] = temp[i];
	}

	delete[] temp;
}

void University::erase() {
	if (m_students) {
		for (size_t i = 0; i < m_size; i++) {
			delete m_students[i];
		}

		delete[] m_students;
	}
}

University::University() {
	m_students = nullptr;
	m_size = 0;
	m_capacity = 8;
	m_students = new Student * [m_capacity];
}

University::University(const University& other) {
	copy(other);

}

University& University::operator=(const University& other) {
	if (this != &other) {
		erase();
		copy(other);
	}

	return *this;
}

University::~University() {
	erase();
}

void University::addStudent(const char* m_name, int m_facultyNumber, bool m_hasSubject) {
	if (m_size >= m_capacity) {
		resize();
	}
	m_students[m_size++] = new Student(m_name, m_facultyNumber, m_hasSubject);
}


void University::addStudent(const Student& s) {
	if (m_size >= m_capacity) {
		resize();
	}
	m_students[m_size++] = new Student(s);
}

Student& University::operator[](size_t index) {
	if (index >= m_size || index < 0) {
		throw std::out_of_range("Invalid index -> operator[] -> University");
	}

	return *m_students[index];
}

University University::operator+(const University& uni) {
	University newUni = *this;

	for (size_t i = 0; i < uni.m_size; i++) {
		newUni.addStudent(*uni.m_students[i]);
	}

	return newUni;
}

size_t University::count() {
	return m_size;
}
