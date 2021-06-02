#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

// абстрактен клас Figure
// от този клас не могат да се създават обекти, 
// можем да използваме Figure*, Figure& 

class Figure
{
public:
	virtual ~Figure() {};

	// чисто витуални функции, които трябва да се предефинират 
	// в производните класове

	virtual double area() const = 0;
	virtual void print() const = 0;
	virtual Figure* clone() const = 0;
};

#endif // !FIGURE_H_INCLUDED


