#ifndef SCATCH_H_INCLUDED
#define SCATCH_H_INCLUDED

#include "Figure.h"
#include <vector>

class Scatch
{
	public:
		Scatch() = default;
		Scatch(const Scatch& other);
		Scatch& operator=(const Scatch& other);
		~Scatch();

		void addFigure(Figure* newFigure);

		size_t size() const { return this->figures.size(); }

		Figure* at(size_t position);
		const Figure* at(size_t position) const;

		void print() const;

	private:
		void copy(const Scatch& other);
		void clear();

	private:
		std::vector<Figure*> figures;
};

#endif // !SCATCH_H_INCLUDED