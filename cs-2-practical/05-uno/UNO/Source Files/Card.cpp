#include "Card.h"
#include <iostream>
#include <cstdlib>

void Card::create(const COLOR color, const unsigned short number) {
    this->color = color;
    this->number = number;
}

Card::Card(COLOR _color, const unsigned short _number) : color(_color),number(_number) {
    if (color == COLOR::UNKNOWN || number < 1 && number > 9){
        color = UNKNOWN_COLOR;
        number = DEFAULT_NUMBER;
        std::cerr << "Invalid Color or Number." << std::endl;
    }
}

bool Card::operator==(const Card &other) const {
    if (color == other.color && number == other.number)
        return true;
    return false;
}

bool Card::operator!=(const Card &other) const {
    return !(*this == other);
}

COLOR Card::getColor() const { return color; }

unsigned short Card::getNumber() const { return number; }

void Card::changeColor(const int color) {
    switch (color) {
        case 0:
            this->color = COLOR::RED;
            break;
        case 1:
            this->color = COLOR::BLUE;
            break;
        case 2:
            this->color = COLOR::GREEN;
            break;
        case 3:
            this->color = COLOR::YELLOW;
            break;
        default:
            this->color = COLOR::UNKNOWN;
            break;
    }
}

void Card::generateRandom() {
    number = rand() % 13 + 1;
    int color = rand() % 4;
    changeColor(color);
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << '/';
    switch (card.getColor()) {
        case COLOR::RED:
            os << "  Red  ";
            break;
        case COLOR::BLUE:
            os << "  Blue ";
            break;
        case COLOR::GREEN:
            os << " Green ";
            break;
        case COLOR::YELLOW:
            os << "Yellow ";
            break;
        default:
            os << "Unknown";
            break;
    }

    switch (card.getNumber()) {
        default:
            os << card.getNumber() << "/";
            break;
        case 10:
            os << "Reverse" << "/";
            break;
        case 11:
            os << "+4" << "/";
            break;
        case 12:
            os << '/';
            break;
        case 13:
            os << "Skip" << "/";
            break;
    }
    return os;
}
