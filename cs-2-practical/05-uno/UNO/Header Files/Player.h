#pragma once
#include "Card.h"
#include "Deck.h"
#include <iostream>

class Player {
private:
	Card* hand;
	size_t MAX_HAND_SIZE; // Size of the array hand;
	size_t handSize; // Cards currently in hand;

public:
	Player();
	Player(const unsigned short numOfCardsInHand);
	~Player();

public:
	const size_t getHandSize() const;
	const Card getCard(const size_t handSize) const;

private:
	void create(const size_t idx);
	Card* allocHand(const size_t MAX_HAND_SIZE);
	void clean();
	bool freeSpace(const size_t handSize); //Checks if there is free space in the hand for another card;
	void removeCard(const size_t idx); //Removes a card from the hand;
	const size_t chooseCard() const; //Returns the index of a card in hand;
	bool increaseMaxHandSize();

public:
	void drawCard(Deck& deck);
	Card playCard();
	void removeCard(const Card& card);

};