#include <iostream>
#include <cstring>

#include "../Headers/Server.h"

void Server::read() {
    std::cout << "Enter IP4 address: ";
    char ch;
    for (int i = 0; i < 3; ++i) {
        std::cin >> IP4Address[i];
        std::cin >> ch;
    }
    std::cin >> IP4Address[3];

    std::cout << "Enter HDD capacity: ";
    std::cin >> hdd;

    std::cout << "Enter RAM size: ";
    std::cin >> ram;

    std::cout << "Enter CPU frequency in GHz: ";
    std::cin >> frequency;

    std::cin.ignore();

    std::cout << "Enter OS name: ";
    std::cin.getline(os, 20);
}

void Server::print() const {
    std::cout << "IP4Address: ";

    for (int i = 0; i < 3; ++i) {
        std::cout << IP4Address[i] << ".";
    }
    std::cout << IP4Address[3];

    std::cout << " HDD memory: " << hdd << " RAM: " << ram << " OS: " << os << std::endl;
}

bool Server::operator<(const Server& other) const {
    for (int i = 0; i < 4; ++i) {
        if (IP4Address[i] > other.IP4Address[i]) {
            return false;
        }
    }
    std::cout << "wtf";

    return true;
}

bool Server::operator==(const Server &other) const {
    bool eqIp = true;

    for (int i = 0; i < 4; ++i) {
        if (IP4Address[i] != other.IP4Address[i]) {
            eqIp = false;
            break;
        }
    }

    return eqIp && hdd == other.hdd && ram == other.ram
        && frequency == other.frequency && strcmp(os, other.os) == 0;
}

bool Server::sameNetwork(int *ip) {
    return IP4Address[0] == ip[0] && IP4Address[1] == ip[1] && IP4Address[2] == ip[2];
}
