
#include <cstring>
#include "AnimalFamily.h"


void AnimalFamily::copyFrom(const AnimalFamily &other) {//strong exeption guarantee!!!
    char *newName = nullptr;//new char[strlen(other.name)];
    try {
        newName = new char[strlen(other.name)];
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
        return;
    }
    delete[] name;
    strcpy(newName, other.name);
    name = newName;
    number = other.number;
    newName = nullptr;

}

AnimalFamily::AnimalFamily(const char *newName, unsigned int newNum) {
    std::cout << "Animal Created\n";
    try {
        name = new char[strlen(newName) + 1];
    }
    catch (const std::exception &e) {
        std::cerr << "Memory allocation error " << e.what() << std::endl;
        return;
    }
    strcpy(name, newName);
    //strcpy(name, newName);
    number = newNum;

}

AnimalFamily::AnimalFamily(const AnimalFamily &other) {
    copyFrom(other);
}

AnimalFamily &AnimalFamily::operator=(const AnimalFamily &other) {

    if (this != &other) {
        copyFrom(other);
    }
    return *this;
}

AnimalFamily::~AnimalFamily() {
    delete[] name;
    number = 0;
    name = nullptr;

}

const char *AnimalFamily::getName() const {
    return name;
}

unsigned int AnimalFamily::getNumber() const {
    return number;
}

void AnimalFamily::print(std::ostream &os) const {
    os << "Name :" << name << " , Number of members: " << number << std::endl;
}

AnimalFamily::AnimalFamily(AnimalFamily &&other) noexcept: name(other.name), number(other.number) {
    other.name = nullptr;
    other.number = 0;
}

AnimalFamily &AnimalFamily::operator=(AnimalFamily &&other) noexcept {
    if (this != &other) {
        delete name;
        name = other.name;
        number = other.number;
        other.name = nullptr;
        other.number = 0;
    }
    return *this;
}
