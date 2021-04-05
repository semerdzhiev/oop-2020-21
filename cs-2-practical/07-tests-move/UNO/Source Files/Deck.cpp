#include "Deck.h"
#include <iostream>
#include<algorithm>
#include <random>
#include <chrono>
#include<exception>

void Deck::create(unsigned short _deckSize) {
    const unsigned short numberOfSpecialCards = _deckSize / 6;
    this->deckSize = _deckSize;
    this->curDeckSize = deckSize;
    this->idxCurrentCard = deckSize - 1;
    deck = new(std::nothrow) Card[deckSize];
    if (!deck) {
        std::cerr << "Deck()::create():Deck not allocated" << std::endl;
        exit(1);
    }
    for (unsigned short i = 0; i < deckSize - numberOfSpecialCards; ++i) {
        deck[i].generateRandom();
    }
    for (unsigned short i = deckSize - numberOfSpecialCards; i < deckSize; ++i) {
        deck[i].generateRandomSpecial();
    }
    this->shuffleDeck();
    // Assure that top card it's not special at the begining
    deck[idxCurrentCard].generateRandom();
}

Deck::Deck(unsigned short _deckSize) {
    if (_deckSize > 1)
        create(_deckSize);
    else {
        std::cerr << "Deck():Deck size must be more then 1!";
        exit(1);
    }

}

void Deck::deleteDeck() { delete[] deck; }

void Deck::copyDeck(const Deck &src) {
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

Card &Deck::operator[](unsigned short idx) {
    if (idx < deckSize)
        return deck[idx];
    std::cerr << "Invalid index of array\n";
    exit(1);
}

const Card &Deck::operator[](unsigned short idx) const {
    if (idx < deckSize)
        return deck[idx];
    std::cerr << "Invalid index of array\n";
    exit(1);
}

unsigned short Deck::getSize() const { return deckSize; }

void Deck::setSize(unsigned short _deckSize) {
    deleteDeck();
    create(deckSize);
}

Card &Deck::getTopCardAndRemoveIt() {
    if (curDeckSize > 0) {
        --curDeckSize;
        return deck[idxCurrentCard--];
    } else
        throw std::range_error("getTopCardAndRemoveIt():Removing from empty deck!");


}

const Card &Deck::getTopCard() const {
    if (curDeckSize > 0)
        return deck[idxCurrentCard];
    throw std::range_error("getTopCard():Removing from empty deck!");
}

unsigned short Deck::getCurDeckSize() const {
    return curDeckSize;
}

void Deck::shuffleDeck() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck, deck + deckSize, std::default_random_engine(seed));
}
