#pragma once

#include "Card.hpp"

#define WALLET_CAPACITY 5

class VirtualWallet
{
public:
    VirtualWallet();

    /// Adds a card to the wallet if there are less than WALLET_CAPACITY cards in the wallet.
    /// If the wallet is full the function does nothing.
    /// @param card the card to be added
    /// @return true if a card was added successfully, false otherwise.
    bool registerCard(const Card& card);

    /// Makes a payment with the card.
    /// If the card if in the wallet the function will try and execute the payment with the card.
    /// If there arent enough money in the card or the card id is invalid the payment will fail.
    /// The sum must always be greater than zero
    /// @param cardID the ID of the card with which the payment will be executed
    /// @param sum the amount of money to be payed
    /// @return true when a payment was successful, false otherwise
    bool makePayment(int cardID, double sum);

    /// Adds balance to the card with a corresponding ID
    /// The sum must always be greater than zero
    /// @param cardID the ID of the card
    /// @param sum the amount of money to be fed
    /// @return true when a deposit was successful, false otherwise
    bool feedCard(int cardID, double sum);

    /// @return constant reference to the card with the given ID. nullptr if the is no such card
    const Card* getCard(int cardID) const;

    /// @return the number of cards in the wallet
    int getCardsCount() const;

private:
    Card wallet[WALLET_CAPACITY];
    int walletSize;
};

