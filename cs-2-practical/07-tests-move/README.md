# Упражнение 7 - 05/04/2021
## План за упражнението
	- Какво е lvalue и rvalue
	- Move semantics and Move constructor in C++
	- std::move and the move assignment operator
	- Да напишем тестове за нашето UNO, за да видим дали всичко е наред :)

## Задача 1.
Имплементиайте клас, Virus, който има:
	- name (char*)
	- servility (int)
Напишете operator<,operator<=,operator>,operator>=

## Задача 2.
Имплементирайте динамичен масив(vector) от вируси. Напишете следните оператор:
	- += добавя елемент на края на вектора
	- += добавя вектор на края на вектора (конкатенация, сливане)
	- << извеждане на всички елементи на вектора
	- [] за да можем да оперираме с нега като с масив
	
## Задача 3.
Имплементирайте клас Person с полета:
	-age
	-name
	-copy constructor
	-operator=
	-move assignment operator
	- move constructor
	- да съдръжа вектор от вируси, както и функкция infect. При наличие, вече на такъв вирус просто му увеличете сервилността.