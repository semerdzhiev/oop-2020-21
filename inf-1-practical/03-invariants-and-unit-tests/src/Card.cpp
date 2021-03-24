#include "Card.hpp"

Card::Card(int newId, double newBalance)
{
    id = newId;
    balance = validate(newBalance) ? newBalance : 0.f;

}

bool Card::withdraw(double sum)
{
    if (sum > balance || !validate(sum))
    {
        return false;
    }
    balance -= sum;
    return true;
}

void Card::deposit(double sum)
{
    if (validate(sum))
    {
        balance += sum;
    }
}

int Card::getID() const
{
    return id;
}

double Card::getBalance() const
{
    return balance;
}

bool Card::validate(double sum)
{
    if (sum < 0.f)
        return false;

    return true;
}
