#include <iostream>
#include <cassert>
#include "Food.h"
#include "Pizza.h"
#include "Salad.h"
#include "Menu.h"


int main() {

	Pizza p1("Margherita", 420, 6, 5.90);
	Pizza p2("Capricciosa", 560, 8, 9.30);
	/* p1.print();
	 p1.consume();
	 p1.print();*/

	Salad s1(3, false, 330, 4.70);
	/* s1.print();
	 s1.consume();
	 s1.print();*/

	Food* f = &p1;
	 //f->print();

	Menu m(10);
	m.addFood(&p1);
	m.addFood(&s1);
	m.addFood(f);
	m.addFood(&p2);
	m.remove(f);
	m.print();

	//m.getCheapestFood();

	std::cout << std::endl << std::endl;
	std::cout << "Consume" << std::endl;
	m.consumeFood(&s1);
	m.consumeFood(&p2);
	m.print();

	return 0;
}