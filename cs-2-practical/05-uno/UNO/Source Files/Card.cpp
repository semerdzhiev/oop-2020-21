#include "Card.h"
#include <iostream>
#include <cstdlib>

void Card::create(const COLOR color, const unsigned short number)
{
	this->color = color;
	this->number = number;
}

Card::Card()
{
	create(COLOR::UNKNOWN, 10); 
}

Card::Card(const COLOR color, const unsigned short number)
{
	if (color != COLOR::UNKNOWN && number > 0 && number <= 9)
		create(color, number);
	else {
		std::cerr << "Ivalid Color or Number." << std::endl;
		create(COLOR::UNKNOWN, 10);
	}
}

Card::Card(const Card& other)
{
	create(other.color, other.number);
}

Card& Card::operator=(const Card& other)
{
	if (this != &other)
		create(other.color, other.number);
	return *this;
}

bool Card::operator==(const Card& other) const
{
	if (color == other.color && number == other.number)
		return true;
	return false;
}

bool Card::operator!=(const Card& other) const
{
	return !(*this == other);
}

const COLOR Card::getColor() const { return color; }
const unsigned short Card::getNumber() const { return number; }

void Card::changeColor(const int color)
{
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

void Card::generateRandom()
{
	number = rand() % 13 + 1;
	int color = rand() % 4;
	changeColor(color);
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
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
