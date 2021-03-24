#include "VirtualWallet.hpp"

VirtualWallet::VirtualWallet()
{
    walletSize = 0;
}


bool VirtualWallet::registerCard(const Card& card)
{
    if (walletSize >= WALLET_CAPACITY)
    {
        return false;
    }

    wallet[walletSize] = card;
    ++walletSize;
    return true;
}

bool VirtualWallet::makePayment(int cardID, double sum)
{
    for (int i = 0; i < walletSize; ++i)
    {
        if (wallet[i].getID() == cardID)
        {
            return wallet[i].withdraw(sum);
        }
    }

    return false;
}

bool VirtualWallet::feedCard(int cardID, double sum)
{
    for (int i = 0; i < walletSize; ++i)
    {
        if (wallet[i].getID() == cardID)
        {
            wallet[i].deposit(sum);
            return true;
        }
    }

    return false;
}

const Card* VirtualWallet::getCard(int cardID) const
{
    for (int i = 0; i < walletSize; ++i)
    {
        if (wallet[i].getID() == cardID)
        {
            return &wallet[i];
        }
    }

    return nullptr;
}

int VirtualWallet::getCardsCount() const
{
    return walletSize;
}
