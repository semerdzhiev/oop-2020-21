#ifndef Polynom_H
#define Polynom_H

/*
	Representing polynoms of Nth degree
	An * x^n + An-1 * x^n-1 ... + A1 * n + A0;
*/
class Polynom {
public: 
	Polynom(int maxN = 10);
	Polynom(const Polynom & other);
	Polynom& operator=(const Polynom & other);
	~Polynom();

	double getCoefficient(int n) const;
	void setCoefficient(int n, double coefValue);

	void print() const;
	
	Polynom operator+(const Polynom & other);
	Polynom operator-(const Polynom & other);
	Polynom & operator+=(const Polynom & other);
	Polynom & operator-=(const Polynom & other);

	bool operator==(const Polynom & other) const;
	bool operator!=(const Polynom & other) const;

private:
	void copy(const Polynom & other);
	void destroy();
	void extend(int newMaxN);

private:
	int maxN;
	double * coefficients;
};
#endif