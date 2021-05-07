#include "student.h"

Student::Student() {
    this->facultyNumber = 0;
    this->spec = "";
}

Student::Student(const std::string &name, const std::string &family, int age, int faculty, const std::string &spec) : Human(name, family, age) {
    this->facultyNumber = faculty;
    this->spec = spec;
}

void Student::print() {
    Human::print();
    cout << "FN: " << facultyNumber << endl;
    cout << "Spec: " << spec << endl;
}