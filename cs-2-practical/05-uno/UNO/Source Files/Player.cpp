#include "Player.h"

void Player::create(const size_t handSize)
{
	MAX_HAND_SIZE = 10;
	if (handSize > MAX_HAND_SIZE)
		MAX_HAND_SIZE = MAX_HAND_SIZE;
	hand = allocHand(MAX_HAND_SIZE);
	this->handSize = handSize;
	if (!hand)
		return;
	for (size_t i = 0; i < handSize; i++)
		hand[i].generateRandom();
}

Card* Player::allocHand(const size_t MAX_HAND_SIZE)
{
	Card* newHand = new(std::nothrow) Card[MAX_HAND_SIZE];
	if (!hand) {
		std::cerr << "Memory not allocated for hand." << std::endl;
		return nullptr;
	}
	return newHand;
}

bool Player::freeSpace(const size_t handSize) { return (0 <= handSize && handSize < MAX_HAND_SIZE); }

void Player::clean()
{
	delete[] hand;
}

Player::Player()
{
	create(3);
}

Player::Player(const unsigned short handSize)
{
	create(handSize);
}

Player::~Player()
{
	clean();
}

const size_t Player::getHandSize() const { return handSize; }

const Card Player::getCard(const size_t idx) const
{
	if (idx < handSize)
		return hand[idx];
	Card a; //Invalid card by default;
	return a;
}

void Player::removeCard(const size_t idx)
{
	for (size_t i = idx; i < handSize - 1; i++)
		hand[i] = hand[i + 1];
	handSize--;
}

void Player::removeCard(const Card& card)
{
	size_t idx = 0;
	while (card != hand[idx])
		idx++;
	if (idx < handSize) {
		removeCard(idx);
		return;
	}
	std::cerr << "Card not found." << std::endl;
}

const size_t Player::chooseCard() const
{
	std::cout << "Pick a card: ";
	size_t choice;
	do {
		std::cin >> choice;
		if (choice >= handSize)
			std::cerr << "Invalid choice." << std::endl;
	} while (choice >= handSize);
	return choice;
}

bool Player::increaseMaxHandSize()
{
	if (handSize >= MAX_HAND_SIZE) {
		MAX_HAND_SIZE *= 2;
		Card* newHand = allocHand(MAX_HAND_SIZE);
		if (!newHand)
			return false;
		for (size_t i = 0; i < handSize; i++)
			newHand[i] = hand[i];
		clean();
		hand = newHand;
	}
	return true;
}

void Player::drawCard(Deck& deck)
{
	if (!freeSpace(handSize))
		removeCard(chooseCard());
	hand[handSize++] = deck.topCard();
	if (!increaseMaxHandSize())
		std::cerr << "Hand size not increased." << std::endl;
}

Card Player::playCard()
{
	const size_t choice = chooseCard();
	Card card(hand[choice]);
	return card;
}
