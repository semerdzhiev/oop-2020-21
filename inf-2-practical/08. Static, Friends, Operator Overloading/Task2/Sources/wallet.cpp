#include "../Headers/wallet.hpp"

void Wallet::addMoney(const Money &_money)
{
    money.operator+=(_money);
}

void Wallet::removeMoney(const Money &_money)
{
    money -= (_money);
}

ostream &operator<<(ostream &os, const Wallet &wallet)
{
    os << "Money in wallet: " << wallet.money;
    return os;
}

istream &operator>>(istream &is, Wallet &wallet)
{
    is >> wallet.money;
    return is;
}
