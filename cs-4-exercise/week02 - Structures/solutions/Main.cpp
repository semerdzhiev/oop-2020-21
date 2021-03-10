#include "Book.h"
#include "Library.h"

int main() {
	Library l;
	l.create(4);
	l.addBook();
	l.addBook();


	Book bestBook = l.getBestBook();
	bestBook.print();
	return 0;
}