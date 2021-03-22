#include "Course.h"
#include "cstring"
Course::Course(): students(16) {
    capacity=16;
    name = new (std::nothrow) char[5];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
    }
    strcpy(name,"empty");
}

Course::Course(char *_name, DynamicArray<Student> &_students, size_t _capacity): students(_capacity) {
    capacity=_capacity;
    name = new (std::nothrow) char[strlen(_name)];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        return;
    }
    strcpy(name,_name);
    students=_students;
}

bool Course::operator==(const Course &other) const {
    return strcmp(name,other.getName())==0;
}



Course::Course(char *_name, size_t _capacity):students(_capacity) {
    capacity=_capacity;
    name = new (std::nothrow) char[strlen(_name)];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        return;
    }
    strcpy(name,_name);
}

Course::Course(const Course &course): students(course.capacity) {
    name = new (std::nothrow) char[strlen(course.getName())];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        return;
    }
    strcpy(name,course.name);
    capacity=course.capacity;
    students=course.students;
}

Course & Course::operator=(const Course &course) {
    if(this!=&course) {
        delete[] name;
        name = new (std::nothrow) char[strlen(course.name)];
        if(name==nullptr) {
            std::cerr<<"Allocation returned nullptr\n";
            return *this;
        }
        strcpy(name,course.name);
        capacity=course.capacity;
        students=course.students;
    }
    return *this;
}

Course::~Course() {
    delete[] name;
}

const char * Course::getName() const {
    return name;
}

size_t Course::getCapacity() const {
    return capacity;
}

void Course::setCapacity(size_t _capacity) {
    capacity=_capacity;
}

void Course::setName(const char *_name) {
    delete[] name;
    name = new (std::nothrow) char[strlen(_name)];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        return;
    }
    strcpy(name,_name);
}

void Course::printInformation() const {
    std::cout<<"Course name:"<<name<<" with capacity:"<<capacity<<" with students:\n";
    students.print();
}

bool Course::enrolStudent(Student& _student) {
    if(students.getSize()>=capacity) {
        std::cerr<<"Not enough space in course!\n";
        return false;
    } else {
        students.add(_student);
        return true;
    }
}

void Course::enrolStudents(const DynamicArray<Student> &_students) {
    for(size_t i=0;i<_students.getSize();++i) {
        enrolStudent(_students[i]);
    }
}

std::ostream& operator<<(std::ostream& os, const Course& _course) {
    os << "Course name:"<<_course.name<<" with capacity:"<<_course.capacity<<" with students:\n";
    os<<_course.students;
    return os;
}