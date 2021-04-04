#include "Date.h"

#include <iostream>

Date::Date()
{
    std::cout << "Default date 1.1.1900 has been created!" << std::endl;
}

Date::Date(size_t day, size_t month, size_t year)
{
    if (isValidDate(day, month, year))
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    std::cout << "The following date has been created: ";
    this->print();
}

Date::Date(const Date& other) 
	: day(other.day), month(other.month), year(other.year)
{
    std::cout << "Copy constructor has been invoked to copy: ";
    other.print();
}

Date::~Date()
{
    std::cout << "The following data has been destroyed: ";
    this->print();
}

size_t Date::getDay() const
{
    return day;
}

size_t Date::getMonth() const
{
    return month;
}

size_t Date::getYear() const
{
    return year;
}

void Date::setDay(size_t day)
{
    if (isValidDate(day, this->month, this->year))
    {
        this->day = day;
    }
}

void Date::setMonth(size_t month)
{
    if (month >= 1 && month <= 12)
    {
        this->month = month;
    }
}

void Date::setYear(size_t year)
{
    if (year >= 1900)
    {
        this->year = year;
    }
}

bool Date::isValidDate(size_t day, size_t month, size_t year)
{
    if(year < 1900)
        return false;

    if(month < 1 || month > 12)
        return false;

    size_t countDays{ 0 };
    switch(month)
    {
        case 2: countDays = 28; break;
        case 4:
        case 6:
        case 9:
        case 11: countDays = 30; break;
        default: countDays = 31;
    }

    if(day < 1 || day > countDays)
        return false;

    return true;
}

void Date::print() const
{
    std::cout << day << "." << month << "." << year << std::endl;
}

