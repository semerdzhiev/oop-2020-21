#pragma once
#include "Food.h"

class Salad : public Food {
private:
	int productsCount;
	bool isSpiced;

public:
	Salad(const int productsCount = 4, const bool isSpiced = true,
		const int weight = 300, const double price = 4.5);

	void print();

	virtual void category() override;

	virtual Food* clone() override;
};

