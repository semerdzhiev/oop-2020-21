#pragma once

#include <iostream>
#include "Card.h"

class Deck {
private:
    unsigned short deckSize;
    unsigned short idxCurrentCard;
    unsigned short curDeckSize;
    Card *deck;

public:
    Deck(unsigned short _deckSize=30);

    Deck(const Deck &other);

    ~Deck();

    Deck &operator=(const Deck &other);

    Card &operator[](unsigned short idx);

    const Card &operator[](unsigned short idx) const;

private:
    void create(unsigned short _deckSize);

    void deleteDeck();

    void copyDeck(const Deck& src);

public:
    void setSize(unsigned short _deckSize);

    unsigned short getSize() const;

    unsigned short getCurDeckSize() const;

    Card& getTopCardAndRemoveIt();

    const Card& getTopCard() const;

    void shuffleDeck();

};