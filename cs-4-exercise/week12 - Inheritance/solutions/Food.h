#pragma once

class Food
{
private:
	int weight;
	int parts;
	double price;
	double weightPerPart;

public:
	Food(const int weight = 0, const int parts = 0,
		const double price = 0.0);

	virtual void category() = 0;

	virtual Food* clone() = 0;

	void consume();

	virtual void print();

	int getWeight() const;

	int getParts() const;

	double getPrice() const;

	double getWeightPerPart() const;

	virtual bool operator==(const Food& f) const;

	virtual ~Food() = default;
};

