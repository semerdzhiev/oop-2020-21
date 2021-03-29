#include "Game.h"

void Game::deleteGame() { delete[] players; }

Game::Game(unsigned short _playerCount, unsigned short _deckSize) :
playerCount(_playerCount),deck(_deckSize),onTheField(_deckSize),currentCard(_deckSize-1),reverse(false){
    if(_playerCount<2) {
        std::cerr<<"Invalid players count\n";
        exit(1);
    }
    if(_deckSize<5) {
        std::cerr<<"Invalid deck size\n";
        exit(1);
    }
    players = new(std::nothrow) Player[playerCount];
    if (!players) {
        std::cerr << "Memory for players not allocated" << std::endl;
        exit(1);
    }
}

Game::~Game() { deleteGame(); }

const Player& Game::getPlayer(unsigned short idx) const {
    if (idx < playerCount)
        return players[idx];
    else {
        std::cerr<<"Invalid index of array\n";
        exit(1);
    }
}

//TODO : Continue from here
void Game::deckHasEnded() {
    if (currentCard<0) {
        deck = onTheField;
        currentCard = deck.getSize() - 1;
        onTheField = Deck(deck.getSize());
    }
}

bool Game::hasPlayableCards(const Player &player) {
    for (unsigned short i = 0; i < player.getHandSize(); i++)
        if (cardIsValid(player.getCard(i)))
            return true;
    return false;
}

bool Game::cardIsValid(const Card &card) const {
    if (card.getNumber() == 12) //Change color;
        return true;
    if (onTheField[currentCard].getColor() == card.getColor())
        return true;
    if (onTheField[currentCard].getNumber() == card.getNumber())
        return true;
    return false;
}

unsigned short Game::nextPlayer(unsigned short player_idx) {
    if (reverse) {
        if (player_idx - 1 >= playerCount)
            return playerCount - 1;
        return player_idx - 1;
    }
    if (player_idx + 1 >= playerCount)
        return 0;
    return player_idx + 1;
}

void Game::changeColor(Card& card) {
    int choice;
    do {
        system("cls"); //Is this working?
        std::cout << "Please choose a card:\n"
                  << "0. Red\n"
                  << "1. Blue\n"
                  << "2. Green\n"
                  << "3. Yellow" << std::endl;
        std::cin >> choice;
        if (choice < 0 || choice > 3) {
            std::cerr << "Invalid choice." << std::endl;
            system("pause"); // And this?
        }
    } while (choice < 0 || choice > 3);
    card.changeColor(choice);
}

unsigned short Game::specialCard(Card &card, unsigned short player_idx) {
    if (card.getNumber() == 10) { //Reverse;
        reverse = !reverse;
//        reverse ? reverse = false : reverse = true;
    } else if (card.getNumber() == 11) { // +4;
        player_idx = nextPlayer(player_idx);
        for (short i = 0; i < 4; i++) {
            deckHasEnded();
            players[player_idx].drawCard(deck);
        }
        return player_idx;
    } else if (card.getNumber() == 12) { // Change color;
        changeColor(card);
    } else if (card.getNumber() == 13) { // Skip next player;
        player_idx = nextPlayer(player_idx);
    }
    return nextPlayer(player_idx);
}

bool Game::turn(Player &player, size_t &i) //i == player index;
{
    deckHasEnded();
    if (!hasPlayableCards(player)) {
        player.drawCard(deck);
        std::cout << "No card can be played. You drew: " << players[i].getCard(players[i].getHandSize() - 1)
                  << std::endl;
        system("pause");
        i = nextPlayer(i);
        return false;
    }
    Card card; //Card that will now be played;
    do {
        card = player.playCard();
        if (!cardIsValid(card))
            std::cerr << "Invalid choice. Try again" << std::endl;
    } while (!cardIsValid(card));
    onTheField[--currentCard] = card;
    player.removeCard(card);
    if (isWinner(player))
        return true;
    i = specialCard(onTheField[currentCard], i);
    return false;
}

bool Game::isWinner(const Player &player) {
    if (player.getHandSize() == 0)
        return true;
    return false;
}

void Game::printGame(const Player &player) const {
    system("cls");
    std::cout << "Current card:        " << onTheField[currentCard] << std::endl;
    for (size_t i = 0; i < player.getHandSize(); i++)
        std::cout << i << " : " << player.getCard(i) << std::endl;
}

void Game::play() {
    size_t i = 0;
    size_t winner;
    while (true) {
        printGame(getPlayer(i));
        std::cout << "Player " << i << "'s turn." << std::endl;
        if (turn(getPlayer(i), i)) {
            winner = i;
            break;
        }
    }
    std::cout << "Player " << winner << " wins!!!" << std::endl;
}
