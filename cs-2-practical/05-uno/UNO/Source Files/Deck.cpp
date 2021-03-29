#include "Deck.h"
#include <iostream>

void Deck::create(size_t deckSize) {
    this->deckSize = deckSize;
    this->inxCurrentCard = deckSize - 1;
    deck = new(std::nothrow) Card[deckSize];
    if (!deck){
        std::cerr << "Deck not allocated" << std::endl;
        exit(1);
    }
    while(deck[deckSize-1].getNumber()>9) {
        deck[deckSize-1].generateRandom();
    }
//    for (size_t i = 0; i < deckSize; i++)
//        deck[i].generateRandom();
}

Deck::Deck(size_t deckSize) {
    create(deckSize);
}

void Deck::deleteDeck() { delete[] deck; }

void Deck::copyDeck(const Deck& src) {
    if (this->deckSize != src.deckSize) {
        std::cerr << "Deck sizes must be the same." << std::endl;
        return;
    }
    for (size_t i = 0; i < src.deckSize; i++)
        this->deck[i] = src.deck[i];
}



Deck::Deck(const Deck &other) {
    create(other.deckSize);
}

Deck::~Deck() {
    deleteDeck();
}

Deck &Deck::operator=(const Deck &other) {
    if (this != &other) {
        deleteDeck();
        create(other.deckSize);
        copyDeck(other);
    }
    return *this;
}

Card &Deck::operator[](size_t idx) {
    if (idx < deckSize)
        return deck[idx];
    std::cerr<<"Invalid index of array\n";
    exit(1);
}

const Card &Deck::operator[](size_t idx) const {
    if (idx < deckSize)
        return deck[idx];
    std::cerr<<"Invalid index of array\n";
    exit(1);
}

size_t Deck::getSize() const { return deckSize; }

void Deck::setSize(size_t deckSize) {
    deleteDeck();
    create(deckSize);
}

const Card& Deck::topCard() {
    return deck[inxCurrentCard--];
}
