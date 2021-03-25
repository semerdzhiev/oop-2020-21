#include "Deck.h"
#include <iostream>

void Deck::create(const size_t deckSize)
{
	this->deckSize = deckSize;
	this->currentCard = deckSize - 1;
	deck = new(std::nothrow) Card[deckSize];
	if (!deck)
		std::cerr << "Deck not allocated" << std::endl;
	for(size_t i = 0; i < deckSize; i++)
		deck[i].generateRandom();
}

void Deck::deleteDeck() { delete[] deck; }

void Deck::copyDeck(Deck dest, const Deck src)
{
	if (dest.deckSize != src.deckSize) {
		std::cerr << "Deck sizes must be the same." << std::endl;
		return;
	}
	for (size_t i = 0; i < src.deckSize; i++)
		dest.deck[i] = src.deck[i];
}

Deck::Deck()
{
	create(30);
}

Deck::Deck(const size_t deckSize)
{
	create(deckSize);
}

Deck::Deck(const Deck& other)
{
	create(other.deckSize);
}

Deck::~Deck()
{
	deleteDeck();
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other) {
		deleteDeck();
		create(other.deckSize);
		copyDeck(*this, other);
	}
	return *this;
}

Card& Deck::operator[](const size_t idx)
{
	if (idx < deckSize)
		return deck[idx];
	return deck[deckSize - 1];
}

const Card& Deck::operator[](const size_t idx) const
{
	if (idx < deckSize)
		return deck[idx];
	return deck[deckSize - 1];
}

const size_t Deck::getSize() const { return deckSize; }
const Card* Deck::getDeck() const { return deck; }

void Deck::setSize(const size_t deckSize)
{
	deleteDeck();
	create(deckSize);
}

Card Deck::topCard()
{
	if (currentCard - 1 > deckSize - 1)
		return deck[deckSize - 1];
	return deck[currentCard--];
}
