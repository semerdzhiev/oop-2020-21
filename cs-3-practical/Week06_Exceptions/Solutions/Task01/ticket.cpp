#include <iostream>
#include <cstring>
#include "ticket.h"

using std::endl;

int Ticket::idGen = 0;

Ticket::Ticket() {
    id = idGen++;
    name = nullptr;
    phone = nullptr;
}

Ticket::Ticket(const char* name, const char* phone) {

    try {
        id = idGen++;
        setName(name);
        setPhone(phone);
    } catch (std::length_error &e) {
        std::cerr << e.what() << endl;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << endl;
    }
}

const int Ticket::getId() const {
    return id;
}

const char* Ticket::getName() const {
    return name;
}

const char* Ticket::getPhone() const {
    return phone;
}

void Ticket::setName(const char *name) {
    if (name == nullptr) {
        throw std::invalid_argument("Name should not be null");
    }

    int n = strlen(name);
    for (int i = 0; i < n; i++) {
        if (!((name[i] >= 'a' && name[i] <= 'z')
        || (name[i] >= 'A' && name[i] <= 'Z')
        || (name[i] == ' '))) {
            throw std::invalid_argument("Invalid name. it should contains only letters & ' '");
        }
    }

    this->name = new (std::nothrow) char[n + 1];
    strcpy(this->name, name);
}

void Ticket::setPhone(const char *phone) {
    if (phone == nullptr) {
        throw std::invalid_argument("Phone should not be null");
    }

    int n = strlen(phone);
    if (n != 10) {
        throw std::length_error("The phone number should be 10 digits");
    }

    this->phone = new (std::nothrow) char[n + 1];
    strcpy(this->phone, phone);
}

Ticket &Ticket::operator=(const Ticket &ticket) {
    if (this != &ticket) {
        id = ticket.id;
        setName(ticket.getName());
        setPhone(ticket.getPhone());
    }

    return *this;
}

ostream &operator<<(ostream &out, Ticket const &ticket) {
    out << ticket.id << endl;

    if (ticket.name != nullptr) {
        out << ticket.name;
    }
    out << endl;
    
    if (ticket.phone != nullptr) {
        out << ticket.phone;
    }
    out << endl;

    return out;
}

istream &operator>>(istream &in, Ticket &ticket) {

    char tmp[Ticket::MAX_STRING];

    try {
        in.getline(tmp, Ticket::MAX_STRING);
        ticket.setName(tmp);
        in >> tmp;
        ticket.setPhone(tmp);
    } catch (std::length_error &e) {
        std::cerr << e.what() << endl;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << endl;
    }

    in.ignore();

    return in;
}

Ticket::~Ticket() {
    delete[] name;
    delete[] phone;
}