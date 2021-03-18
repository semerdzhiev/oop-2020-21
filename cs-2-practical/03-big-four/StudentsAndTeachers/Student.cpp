#include <cstring>
#include <iostream>
#include "Student.h"

using std::cin;
using std::cout;


Student::Student() {
    FN = 0;
    strcpy(name, "unknown");
    strcpy(major, "unknown");
    group = 0;
}

Student::Student(unsigned _facultyNumber, const char* _name, const char* _major, unsigned short _group) {
    FN = (isValidFN(_facultyNumber) ? _facultyNumber : 0);
    strcpy(name, _name);
    strcpy(major, (isValidMajor(_major) ? _major : "unknown" ));
    group = (isValidGroup(_group) ? _group : 0);
}

Student::Student(const Student& s) {
    FN=s.getFacultyNumber();
    group=s.getGroup();
    setMajor(s.major);
    strcpy(name,s.name);
}

Student & Student::operator=(const Student& s) {
    if(this!=&s) {
        FN=s.getFacultyNumber();
        group=s.getGroup();
        setMajor(s.major);
        strcpy(name,s.name);
    }
    return *this;
}

unsigned Student::getFacultyNumber() const {
    return FN;
}

const char* Student::getName() const {
    return name;
}

const char* Student::getMajor() const {
    return major;
}

void Student::setMajor(const char* newMajor) {
    strcpy(major, (isValidMajor(newMajor) ? newMajor : "Major Not Chosen" ));
}

unsigned short Student::getGroup() const {
    return group;
}

void Student::setGroup(unsigned short newGroup) {
    group = (isValidGroup(newGroup) ? newGroup : 0);
}

void Student::printInformation() const {
    std::cout << FN << ", " << name << ", " << major << ", group " << group;
}

void Student::readFromConsole() {
    int fn,_group;
    std::cin>>fn>>_group;
    FN = isValidFN(fn) ? fn : FN;
    group = isValidGroup(_group) ? group : 0;
    cin.getline(name,50);
    char _major[33];
    cin.getline(_major,32);
    strcpy(major, (isValidMajor(_major) ? _major : "unknown"));
}

bool Student::isValidFN(unsigned FN) {
    return 10000 <= FN && FN < 100000;
}

bool Student::isValidGroup(unsigned short _group) {
    return 1 <= _group && _group <= 8;
}

bool Student::isValidMajor(const char* _major) const {
    bool result = false;
    for (auto major : majors) {
        if(strcmp(major, _major) == 0) {
            result = true;
            break;
        }
    }
    return result;
}

bool Student::operator==(const Student &other) const {
    return FN==other.getFacultyNumber();
}



//cin & cout
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.getFacultyNumber() << ", " << s.getName() << ", " << s.getMajor() << ", group "
    << s.getGroup();
    return os;
}

std::istream& operator>>(std::istream  &input, Student& s) {
    input >> s.FN >> s.name>>s.group>>s.major;
    return input;
}