#pragma once

#include <iostream>

enum class COLOR {
    UNKNOWN = -1,
    RED,
    BLUE,
    GREEN,
    YELLOW
};

const COLOR UNKNOWN_COLOR = COLOR::UNKNOWN;
#define DEFAULT_NUMBER 0

class Card {
private:
    COLOR color;
    unsigned short number;

public:
    Card(COLOR color = COLOR::UNKNOWN, unsigned short number = 0);

    bool operator==(const Card &other) const;

    bool operator!=(const Card &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);

private:
    void create(COLOR color, unsigned short number);

public:
    COLOR getColor() const;

    unsigned short getNumber() const;

public:
    void generateRandom();

    void changeColor(int color);
};