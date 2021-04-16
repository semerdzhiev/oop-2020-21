#include "Set.h"

#include <iostream>
#include <stdexcept>

Set::Set(const Set& other)
{
    this->copy(other);
}

Set& Set::operator=(const Set& other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }

    return *this;
}

Set::Set(Set&& other) noexcept
    : elements(other.elements), numberOfElements(other.numberOfElements)
{
    other.elements = nullptr;
    other.numberOfElements = 0;
}

Set& Set::operator=(Set&& other) noexcept
{
    if (this != &other)
    {
        this->clear();

        this->elements = other.elements;
        this->numberOfElements = other.numberOfElements;

        other.elements = nullptr;
        other.numberOfElements = 0;
    }

    return *this;
}

Set::~Set()
{
    this->clear();
}

Set& Set::operator+=(int element)
{
    // check if the element is already in the set
    this->operator()(element);

    if ((*this)(element))
        return *this;

    int* temp = new int[this->numberOfElements + 1]{ 0 };
    for (size_t index = 0; index < this->numberOfElements; ++index)
    {
        temp[index] = this->elements[index];
    }

    temp[this->numberOfElements] = element;

    delete[] this->elements;
    this->elements = temp;
    ++this->numberOfElements;

    return *this;
}

Set& Set::operator+=(const Set& right)
{
    // what is the downside here?
    //for (size_t index = 0; index < right.numberOfElements; ++index)
    //{
    //    *this += right.elements[index];
    //}

    return *this;
}

Set operator+(const Set& left, int right)
{
    Set result{ left };
    result += right;
    return result;
}

// s[2] = 3;
int& Set::operator[](size_t position)
{
    if (position >= this->numberOfElements)
        throw std::out_of_range("Index out of range!");

    return this->elements[position];
}

const int& Set::operator[](size_t position) const
{
    if (position >= this->numberOfElements)
        throw std::out_of_range("Index out of range!");

    return this->elements[position];
}

bool Set::operator()(int element) const
{
    for (size_t index = 0; index < this->numberOfElements; ++index)
    {
        if (this->elements[index] == element)
            return true;
    }

    return false;
}

void Set::copy(const Set& other)
{
    this->numberOfElements = other.numberOfElements;

    this->elements = new int[this->numberOfElements];
    for (size_t index = 0; index < this->numberOfElements; ++index)
    {
        this->elements[index] = other.elements[index];
    }
}

void Set::clear()
{
    delete[] this->elements;
    this->elements = nullptr;
}

// ==, !=, < , <=, >, >=

bool operator==(const Set& left, const Set& right)
{
    size_t leftCard = left.getCard();
    size_t rightCard = right.getCard();

    if (leftCard != rightCard)
        return false;

    for (size_t i = 0; i < leftCard; ++i)
    {
        if (!right(left[i]))
            return false;
    }

    return true;
}

bool operator!=(const Set& left, const Set& right)
{
    return !(left == right);
}

bool operator<(const Set& left, const Set& right)
{
    size_t leftCard = left.getCard();
    size_t rightCard = right.getCard();

    if (leftCard >= rightCard)
        return false;

    for (size_t i = 0; i < leftCard; ++i)
    {
        if (!right(left[i]))
            return false;
    }

    return true;
}

bool operator<=(const Set& left, const Set& right)
{
    return left < right || left == right;
}

bool operator>(const Set& left, const Set& right)
{
    return !(left <= right);
}

std::ostream& operator<<(std::ostream& out, const Set& set)
{
    out << "{ ";

    size_t setCard = set.getCard();
    for (size_t i = 0; i < setCard; ++i)
    {
        out << set[i] << ", ";
    }

    out << "}";

    return out;
}


