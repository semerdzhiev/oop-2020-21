#pragma once
#include <iostream>
#include "Card.h"

class Deck {
private:
	size_t deckSize;
	size_t currentCard;
	Card* deck;

public:
	Deck();
	Deck(const size_t deckSize);
	Deck(const Deck& other);
	~Deck();
	Deck& operator=(const Deck& other);
	Card& operator[](const size_t idx);
	const Card& operator[](const size_t idx) const;

private:
	void create(const size_t deckSize);
	void deleteDeck();
	void copyDeck(Deck dest, const Deck src);

public:
	const Card* getDeck() const;
	void setSize(const size_t deckSize);
	const size_t getSize() const;
	Card topCard();

};