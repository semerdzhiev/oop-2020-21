#pragma once

#include "PrintEdition.h"

#include <iostream>
#include <string>

class Book : virtual public PrintEdition
{
	public:
		Book(const std::string& title, unsigned int yearOfPublishing, double price, const std::string& author)
			: PrintEdition(title, yearOfPublishing, price), author(author)
		{}

		std::string getAuthor() const { return this->author; }

		//virtual void print() const override
		//{
		//	PrintEdition::print();
		//	this->printOwnData();
		//}

		virtual PrintEdition* clone() const override
		{
			return new Book(*this);
		}

	protected:
		virtual void printOwnData() const override
		{
			std::cout << this->author << std::endl;
		}

	private:
		std::string author;
};