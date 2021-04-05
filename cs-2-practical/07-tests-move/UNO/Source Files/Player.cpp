#include "Player.h"

void Player::createHand(unsigned short _handSize) {
    if (_handSize > MAX_HAND_SIZE){
        std::cerr<<"Player:CreateHand():Hand size is bigger then max hand size\n";
        exit(1);
    }
    unsigned short numberOfSpecialCards = (handSize / 6) + 1;
    for (unsigned short i = 0; i < handSize-numberOfSpecialCards; ++i)
        hand[i].generateRandom();

    for(unsigned short i=handSize-numberOfSpecialCards; i<handSize;++i)
        hand[i].generateRandom();
}

Player::Player(unsigned short _handSize) : handSize(_handSize) {
    if (handSize > MAX_HAND_SIZE){
        std::cerr<<"Player():Hand size is bigger then max hand size\n";
        exit(1);
    }
    createHand(handSize);
}


bool Player::freeSpaceCheck() const {
    return (0 <= handSize && handSize < MAX_HAND_SIZE);
}

unsigned short Player::getHandSize() const { return handSize; }

const Card& Player::getCard(unsigned short idx) const {
    if (idx < handSize)
        return hand[idx];
    std::cerr<<"Player:getCard():Invalid index of cards array\n";
    exit(1);
}

void Player::removeCard(unsigned short idx) {
    if (idx < handSize) {
        hand[idx]=hand[--handSize];
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
    std::cerr << "Player:removeCard():Card not found." << std::endl;
}

unsigned short Player::chooseCard() const {
    std::cout << "Pick a card: ";
    unsigned short choice;
    do {
        std::cin >> choice;
        if (choice >= handSize)
            std::cerr << "\nPlayer:chooseCard():Invalid choice!\n";
    } while (choice >= handSize);
    return choice;
}

void Player::drawCard(Deck &deck) {
    if (!freeSpaceCheck())
        removeCard(handSize-1);
    hand[handSize++] = deck.getTopCardAndRemoveIt();
}

Card Player::playCard() { // not change size IO function
    //TODO: Remove row bellow
    //printHand();
    unsigned short choice =  chooseCard();
    Card res = hand[choice];
    return res;
}

void Player::printHand() const {
    for (unsigned short i = 0; i < handSize; ++i)
        std::cout << i << " : " << getCard(i) << std::endl;
}