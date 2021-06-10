#pragma once

#include "Book.h"
#include "Magazine.h"

class Comics : public Book, public Magazine
{
	public:
		Comics(const std::string& title, unsigned int yearOfPublishing, double price, const std::string& author, Periodicity periodicity)
			:	PrintEdition(title, yearOfPublishing, price),
				Book(title, yearOfPublishing, price, author),
				Magazine(title, yearOfPublishing, price, periodicity)
		{}

		//virtual void print() const override
		//{
		//	PrintEdition::print();
		//	this->printOwnData();
		//}

		virtual PrintEdition* clone() const override
		{
			return new Comics(*this);
		}

	protected:
		virtual void printOwnData() const override
		{
			Book::printOwnData();
			Magazine::printOwnData();
		}
};