#pragma once

#include "Card.h"
#include "Deck.h"
#include <iostream>

#define MAX_HAND_SIZE 10

class Player {
private:
    Card hand[MAX_HAND_SIZE];
    unsigned short handSize; // Cards currently in hand;

public:
    Player(unsigned short numOfCardsInHand = 3);

public:
    size_t getHandSize() const;

    const Card& getCard(unsigned short idx) const;

private:
    void createHand(unsigned short handSize);

    bool freeSpaceCheck(); //Checks if there is free space in the hand for another card;
    void removeCard(unsigned short idx); //Removes a card from the hand;
    unsigned short chooseCard() const; //Returns the index of a card in hand;

public:
    void drawCard(Deck &deck);

    Card playCard();

    void removeCard(const Card &card);

};