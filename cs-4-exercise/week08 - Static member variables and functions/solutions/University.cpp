#include "University.h"


void University::copy(const University& other) {

	m_size = other.m_size;
	m_capacity = other.m_capacity;

	erase();

	if (m_capacity != 0) {
		m_students = new Student * [m_capacity];

		for (size_t i = 0; i < m_size; i++) {
			//m_students[i] = new Student(* other.m_students[i]);
		}
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

void addStudent(const char* m_name, int m_facultyNumber, bool m_hasSubject) {

}


void addStudent(const Student& s) {

}