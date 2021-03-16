#pragma once

class Card
{
public:
    Card() : id(-1), balance(0.f) {}
    Card(int newId, double newBalance);

    /// Subtracts a given sum from the balance of the card.
    /// If the sum cannot be validated by @see Card::validate the function fails.
    /// If the balance is insufficient the function fails
    /// @param sum the sum to be withdrawn
    /// @return true is the sum was successfully subtracted, false otherwise
    bool withdraw(double sum);

    /// Adds a given sum to the balance of the card.
    /// If the sum cannot be validated by @see Card::validate the function fails.
    /// @param sum the sum to be deposited
    /// @return true is the sum was successfully added, false otherwise
    void deposit(double sum);

    /// @return the ID of the card.
    int getID() const;

    /// @return the Current Balance.
    double getBalance() const;

private:
    int id;
    double balance;

    /// Validates the monetary sum
    /// The sum should be positive
    static bool validate(double sum);
};

