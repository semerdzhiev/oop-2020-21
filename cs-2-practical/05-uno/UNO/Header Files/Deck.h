#pragma once

#include <iostream>
#include "Card.h"

class Deck {
private:
    size_t deckSize;
    size_t inxCurrentCard;
    Card *deck;

public:
    Deck(size_t deckSize=30);

    Deck(const Deck &other);

    ~Deck();

    Deck &operator=(const Deck &other);

    Card &operator[](size_t idx);

    const Card &operator[](size_t idx) const;

private:
    void create(size_t deckSize);

    void deleteDeck();

    void copyDeck(const Deck& src);

public:
    void setSize(size_t deckSize);

    size_t getSize() const;

    const Card& topCard();

};