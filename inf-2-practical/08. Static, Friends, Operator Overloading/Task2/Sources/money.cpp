#include <iostream>
#include "../Headers/money.hpp"

using namespace std;

unsigned Money::asCoins() const
{
    return banknotes * 100 + coins;
}

void Money::normalize()
{
    if (coins > 100)
    {
        banknotes += coins / 100;
        coins %= 100;
    }
}

void Money::addMoney(const Money &other)
{
    unsigned asCoins = this->asCoins();
    unsigned otherAsCoins = other.asCoins();

    this->banknotes = 0;
    this->coins = asCoins + otherAsCoins;

    this->normalize();
}

void Money::removeMoney(const Money &other)
{
    unsigned asCoins = this->asCoins();
    unsigned otherAsCoins = other.asCoins();

    if (otherAsCoins > asCoins)
        throw out_of_range("Money cannot be negative number");

    this->banknotes = 0;
    this->coins = asCoins - otherAsCoins;

    this->normalize();
}

Money::Money(unsigned _coins = 0, unsigned _banknotes = 0) : coins(_coins), banknotes(_banknotes)
{
    normalize();
}

Money Money::operator+(const Money &other) const
{
    Money newMoney(this->coins, this->banknotes);
    newMoney.addMoney(other);
    return newMoney;
}

Money &Money::operator+=(const Money &other)
{
    this->addMoney(other);
    return *this;
}

Money Money::operator-(const Money &other)
{
    Money newMoney(this->coins, this->banknotes);
    newMoney.removeMoney(other);
    return newMoney;
}

Money &Money::operator-=(const Money &other)
{
    this->removeMoney(other);
    return *this;
}

bool Money::operator<(const Money &other) const
{
    return this->asCoins() < other.asCoins();
}

bool Money::operator>(const Money &other) const
{
    return this->asCoins() > other.asCoins();
}

bool Money::operator>=(const Money &other) const
{
    return !(*this < other);
}

bool Money::operator<=(const Money &other) const
{
    return !(*this > other);
}

bool Money::operator==(const Money &other) const
{
    return this->coins == other.coins && this->banknotes == other.banknotes;
}

bool Money::operator!=(const Money &other) const
{
    return !(*this == other);
}

ostream &operator<<(ostream &os, const Money &money)
{
    os << money.banknotes << "," << money.coins;
    return os;
}

istream &operator>>(istream &is, Money &money)
{
    cout << "Add banknotes: ";
    is >> money.banknotes;
    cout << "Add coins: ";
    is >> money.coins;
    money.normalize();
    return is;
}
