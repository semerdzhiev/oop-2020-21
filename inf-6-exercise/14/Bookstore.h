#pragma once

#include "PrintEdition.h"

#include <vector>

class Bookstore
{
	public:
		Bookstore(const std::vector<PrintEdition*>& editions);
		Bookstore(const Bookstore& other);
		Bookstore& operator=(const Bookstore& other);
		~Bookstore();

		PrintEdition* at(size_t index) { return this->editions.at(index); }
		const PrintEdition* at(size_t index) const { return this->editions.at(index); }

		size_t countPrintEditions() const { return this->editions.size(); }

		Bookstore& addPrintEdition(const PrintEdition& newEdition)
		{
			this->editions.push_back(newEdition.clone());
		}

		void print() const;

	private:
		void copy(const std::vector<PrintEdition*>& editions);
		void clear();

	private:
		std::vector<PrintEdition*> editions;
};