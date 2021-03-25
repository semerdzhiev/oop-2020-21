#pragma once
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Game {
private:
	size_t playerCount;
	Player* players;
	Deck deck;
	Deck onTheField;
	size_t currentCard; //Holds the index of the current card on the field;
	bool reverse; //Reverse the play order;

public:
	Game();
	Game(const size_t playerCount);
	Game(const size_t playerCount, const size_t deckSize);
	~Game();

private: 
	void createGame(const size_t playerCount, const size_t deckSize = 30);
	void deleteGame();
	bool cardIsValid(const Card& card) const;
	bool hasPlayableCards(const Player& player);
	void deckHasEnded();
	size_t specialCard(Card& card, size_t player_idx);
	size_t nextPlayer(const size_t player_idx);
	void changeColor(Card& card);

public:
	Player& getPlayer(const size_t idx) const;
	bool turn(Player& player, size_t& i); //i keeps track of the player whose turn it is; //Returns true if player wins;
	bool isWinner(const Player& player);
	void printGame(const Player& player) const;
	void play();
};