#pragma once

#include <string>

class PrintEdition
{
	public:
		PrintEdition(const std::string& title, unsigned int yearOfPublishing, double price);
		virtual ~PrintEdition() {}

		std::string getTitle() const { return this->title; }
		double getPrice() const { return this->price; }
		unsigned int getYearOfPublishing() const { return this->yearOfPublishing; }

		void print() const;

		virtual PrintEdition* clone() const = 0;

	protected:
		virtual void printOwnData() const = 0;

	private:
		unsigned int yearOfPublishing;
		double price;
		std::string title;
};