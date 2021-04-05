#pragma once

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Game {
private:
    unsigned short playerCount;
    Player *players;
    Deck deck;
    Deck onTheField;
    short currentCard; //Holds the index of the current card on the field;
    bool reverse; //Reverse the play order;

public:
    Game(unsigned short playerCount = 2, unsigned short deckSize = 30);

    ~Game();

private:
    void deleteGame();

    bool cardIsValid(const Card &card) const;

    bool hasPlayableCards(const Player &player);

    void deckHasEnded();

    unsigned short specialCard(Card &card, unsigned short player_idx);

    unsigned short nextPlayer(unsigned short player_idx);

    void changeColor(Card& card);

public:
    Player& getPlayer(unsigned short idx) const;

    bool turn(Player &player, unsigned short &i); //i keeps track of the player whose turn it is; //Returns true if player wins;
    static bool isWinner(const Player &player);

    void printGame(const Player &player) const;

    void play();
};