#include "RetiredTeacher.h"
#include "cstring"

RetiredTeacher::RetiredTeacher():courses() {
    name = new (std::nothrow) char[5];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        exit(1);
    }
    strcpy(name,"empty");
    setExperience(0);
}

RetiredTeacher::RetiredTeacher(char* _name, unsigned short _exp):courses() {
    name = new (std::nothrow) char[strlen(_name)];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        exit(1);
    }
    strcpy(name,_name);
    setExperience(_exp);
}

RetiredTeacher::RetiredTeacher(char *_name, unsigned short _exp,
                               DynamicArray<Course>& _courses) {
    name = new (std::nothrow) char[strlen(_name)];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        exit(1);
    }
    strcpy(name,_name);
    setExperience(_exp);
    courses=_courses;
}

RetiredTeacher::RetiredTeacher(const RetiredTeacher &rt) {
    name = new (std::nothrow) char[strlen(rt.getName())];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        exit(1);
    }
    strcpy(name,rt.getName());
    experience=rt.experience;
    courses=rt.courses;
}

RetiredTeacher::~RetiredTeacher() {
    delete[] name;
}

RetiredTeacher & RetiredTeacher::operator=(const RetiredTeacher &rt) {
    if(this!=&rt) {
        setName(rt.name);
        experience=rt.experience;
        courses=rt.courses;
    }
    return *this;
}

unsigned short RetiredTeacher::getExperience() const {
    return experience;
}

const char * RetiredTeacher::getName() const {
    return name;
}

void RetiredTeacher::setName(const char *_name) {
    delete[] name;
    name = new (std::nothrow) char[strlen(_name)];
    if(name== nullptr) {
        std::cerr<<"Allocation returned nullptr\n";
        exit(1);
    }
    strcpy(name,_name);
}

void RetiredTeacher::setExperience(unsigned short _exp) {
    if(_exp>=0) {
        experience=_exp;
    }
}

void RetiredTeacher::printInformation() const {
    cout<<"Teacher "<<getName()<<" with experience "<<getExperience()<<" years with courses\n";
    courses.print();
}

bool RetiredTeacher::checkCourse(const Course &course) const {
    return courses.contains(course);
}

void RetiredTeacher::addCourse(const Course &course) {
    courses.add(course);
}
