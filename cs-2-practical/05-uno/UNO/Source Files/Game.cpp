#include "Game.h"

void Game::createGame(const size_t playerCount, const size_t deckSize)
{
	reverse = false;
	this->currentCard = 29; //Because the deck will have 30 cards by default;
	this->playerCount = playerCount;
	players = new(std::nothrow) Player[playerCount];
	if (!players)
		std::cerr << "Memory for players not allocated" << std::endl;
	if (deckSize != 30) {
		deck.setSize(deckSize);
		onTheField.setSize(deckSize);
		this->currentCard = deckSize - 1; //Index of the top card in the deck on the field;
	}
}

void Game::deleteGame() { delete[] players; }

Game::Game() { createGame(2); }

Game::Game(const size_t playerCount) { createGame(playerCount); }

Game::Game(const size_t playerCount, const size_t deckSize) { createGame(playerCount, deckSize); }

Game::~Game() {	deleteGame(); }

Player& Game::getPlayer(const size_t idx) const 
{ 
	if (idx < playerCount)
		return players[idx];
	return players[playerCount - 1]; //If idx is out of bounds return last player;
}

void Game::deckHasEnded()
{
	if (deck.getSize() == currentCard + deck.getSize()) {
		deck = onTheField;
		currentCard = deck.getSize() - 1;
	}
}

bool Game::hasPlayableCards(const Player& player)
{
	for (size_t i = 0; i < player.getHandSize(); i++)
		if (cardIsValid(player.getCard(i)))
			return true;
	return false;
}

bool Game::cardIsValid(const Card& card) const
{
	if (card.getNumber() == 12) //Change color;
		return true;
	if (onTheField[currentCard].getColor() == card.getColor())
		return true;
	if (onTheField[currentCard].getNumber() == card.getNumber())
		return true;
	return false;
}

size_t Game::nextPlayer(const size_t player_idx)
{
	if (reverse) {
		if (player_idx - 1 >= playerCount)
			return playerCount - 1;
		return player_idx - 1;
	}
	if (player_idx + 1 >= playerCount)
		return 0;
	return player_idx + 1;
}

void Game::changeColor(Card& card)
{
	int choice;
	do {
		system("cls");
		std::cout << "Please choose a color:\n"
				  << "0. Red\n"
				  << "1. Blue\n"
				  << "2. Green\n"
				  << "3. Yellow" << std::endl;
		std::cin >> choice;
		if (choice < 0 || choice > 3) {
			std::cerr << "Invalid choice." << std::endl;
			system("pause");
		}
	} while (choice < 0 || choice > 3);
	card.changeColor(choice);
}

size_t Game::specialCard(Card& card, size_t player_idx)
{
	if (card.getNumber() == 10) { //Reverse;
		reverse ? reverse = false : reverse = true;
	}
	else if (card.getNumber() == 11) { // +4;
		player_idx = nextPlayer(player_idx);
		for (short i = 0; i < 4; i++) {
			deckHasEnded();
			players[player_idx].drawCard(deck);
		}
		return player_idx;
	}
	else if (card.getNumber() == 12) { // Change color;
		changeColor(card);
	}
	else if (card.getNumber() == 13) { // Skip next player;
		player_idx = nextPlayer(player_idx);
	}
	return nextPlayer(player_idx);
}

bool Game::turn(Player& player, size_t& i) //i == player index;
{
	deckHasEnded();
	if (!hasPlayableCards(player)) {
		player.drawCard(deck);
		std::cout << "No card can be played. You drew: " << players[i].getCard(players[i].getHandSize() - 1) << std::endl;
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

bool Game::isWinner(const Player& player)
{
	if (player.getHandSize() == 0)
		return true;
	return false;
}

void Game::printGame(const Player& player) const
{
	system("cls");
	std::cout << "Current card:        " << onTheField[currentCard] << std::endl;
	for (size_t i = 0; i < player.getHandSize(); i++)
		std::cout << i << " : " << player.getCard(i) << std::endl;
}

void Game::play()
{
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
