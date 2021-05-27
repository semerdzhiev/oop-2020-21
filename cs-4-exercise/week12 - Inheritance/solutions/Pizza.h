#pragma once
#include "Food.h"
#include <string>

class Pizza final : public Food {
private:
	std::string type;

public:
	Pizza(const std::string type = "N/A",
		const int weight = 450, const int parts = 8,
		const double price = 6.5);

	virtual void print() override ;

	virtual void category() override;

	virtual Food* clone() override;

};
