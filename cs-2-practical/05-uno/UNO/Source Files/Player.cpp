#include "Player.h"

void Player::createHand(unsigned short _handSize) {
    if (_handSize > MAX_HAND_SIZE){
        std::cerr<<"Hand size is bigger then max hand size\n";
        exit(1);
    }
    for (unsigned short i = 0; i < handSize; i++)
        hand[i].generateRandom();
}

Player::Player(unsigned short _handSize) : handSize(_handSize) {
    if (handSize > MAX_HAND_SIZE){
        std::cerr<<"Hand size is bigger then max hand size\n";
        exit(1);
    }
    createHand(handSize);
}


bool Player::freeSpaceCheck() {
    return (0 <= handSize && handSize < MAX_HAND_SIZE);
}

size_t Player::getHandSize() const { return handSize; }

const Card& Player::getCard(unsigned short idx) const {
    if (idx < handSize)
        return hand[idx];
    std::cerr<<"Invalid index of cards array\n";
    exit(1);
}

void Player::removeCard(unsigned short idx) {
    if (idx < handSize) {
        hand[idx]=hand[handSize-1];
        handSize--;
    } else {
        std::cerr<<"Invalid index of cards array\n";
        exit(1);
    }
}

void Player::removeCard(const Card &card) {
    for(unsigned short i=0;i<handSize;++i) {
        if(card==hand[i]) {
            removeCard(i);
            return;
        }
    }
    std::cerr << "Card not found." << std::endl;
}

unsigned short Player::chooseCard() const {
    std::cout << "Pick a card: ";
    unsigned short choice;
    do {
        std::cin >> choice;
        if (choice >= handSize)
            std::cerr << "Invalid choice." << std::endl;
    } while (choice >= handSize);
    return choice;
}

void Player::drawCard(Deck &deck) {
    if (!freeSpaceCheck())
        removeCard(chooseCard());
    hand[handSize++] = deck.topCard();
}

Card Player::playCard() {
    unsigned short choice = chooseCard();
    Card res = hand[choice];
    //hand[choice] = hand[handSize-1];
    //handSize--;
    return res;
}