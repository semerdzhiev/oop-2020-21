#pragma once
#include <iostream>

enum class COLOR {
	UNKNOWN = -1,
	RED,
	BLUE,
	GREEN,
	YELLOW
};

class Card{
private:
	COLOR color;
	unsigned short number;

public:
	Card();
	Card(COLOR color, unsigned short number);
	Card(const Card& other);
	Card& operator=(const Card& other);
	bool operator==(const Card& other) const;
	bool operator!=(const Card& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
	void create(const COLOR color, const unsigned short number);

public:
	const COLOR getColor() const;
	const unsigned short getNumber() const;

public:
	void generateRandom();
	void changeColor(const int color);
};