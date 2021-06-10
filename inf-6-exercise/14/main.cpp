#include "PrintEdition.h"
#include "Book.h"
#include "Magazine.h"
#include "Comics.h"

#include "Bookstore.h"

bool searchForPrintEdition(const Bookstore& bookstore, const std::string& title)
{
	size_t count = bookstore.countPrintEditions();
	for (size_t index = 0; index < count; ++index)
	{
		const PrintEdition* currentPrintEdition = bookstore.at(index);
		if (currentPrintEdition->getTitle() == title)
			return true;
	}

	return false;
}

size_t countWeeklyComics(const Bookstore& bookstore)
{
	size_t countWeeklyComics = 0;

	size_t count = bookstore.countPrintEditions();
	for (size_t index = 0; index < count; ++index)
	{
		const PrintEdition* currentPrintEdition = bookstore.at(index);

		const Comics* comics = dynamic_cast<const Comics*>(currentPrintEdition);
		if (comics)
		{
			if (comics->getPeriodicity() == Magazine::Periodicity::WEEKLY)
				++countWeeklyComics;
		}
	}

	return countWeeklyComics;
}

int main()
{
	Comics naruto("Naruto", 2001, 3.50, "Someone", Magazine::Periodicity::MONTHLY);
	naruto.print();



	return 0;
}