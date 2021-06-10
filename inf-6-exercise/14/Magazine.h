#pragma once

#include "PrintEdition.h"

#include <iostream>

class Magazine : virtual public PrintEdition
{
	public:
		enum class Periodicity { WEEKLY = 0, MONTHLY, ANNUALLY };

	public:
		Magazine(const std::string& title, unsigned int yearOfPublishing, double price, Periodicity periodicity)
			: PrintEdition(title, yearOfPublishing, price), periodicity(periodicity)
		{}

		Periodicity getPeriodicity() const { return this->periodicity; }

		//virtual void print() const override
		//{
		//	PrintEdition::print();
		//	this->printOwnData();
		//}

		virtual PrintEdition* clone() const override
		{
			return new Magazine(*this);
		}

	protected:
		virtual void printOwnData() const override
		{
			std::cout << "Periodicity: " << periodicityStrings[static_cast<int>(this->periodicity)] << std::endl;
		}

	private:
		static const char* periodicityStrings[3];

	private:
		Periodicity periodicity;
};

const char* Magazine::periodicityStrings[3] = { "Weekly", "Monthly", "Annually" };