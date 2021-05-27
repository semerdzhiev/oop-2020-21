# Polymorphism. Abstract classes

## Pointers and references to the base class of derived objects

## Virtual functions - function that, when called, resolves to the most-derived version of the function that exists between the base and derived class:

- Use of the virtual keyword

- Never call virtual functions from constructors or destructors

-  Virtual function call takes longer than resolving a regular one

## Polymorphism - concept that objects of different types can be accessed through the same interface. Each type can provide its own, independent implementation of this interface.

### The override specifier
```
	// derived class
	virtual <return_type> <name>() override { body }
```

### The final specifier
```
	// derived class
	virtual <return_type> <name>() override final { body }
```

```
class Derived final : public Base { }; 
```

## Virtual destructors

## Pure virtual functions
```
    virtual <return_type> <name>() = 0;
```

### Pure virtual functions with bodies

## Abstract base class:

- class with one or more pure virtual functions;

- can not be instantiated;

- derived class must define a body for pure virtual functions, or that derived class will be considered an abstract base class as well.

## Interface classes - class that has no member variables, and where all of the functions are pure virtual


# Задачи:

## Задача 1:
Направете клас Duck, който да пази данни за височината, цвета и теглото на пате. Класът трябва да притежава следните виртуални методи: quack() - чисто виртуален, read(istream&), write(ostream&). Класът да предефинира операторите за вход и изход.

## Задача 2:
Направете клас RubberDuck. Класът да притежава член данни за еластичност на гумата на патето (число в интервала 1-100) и дали то може да дебъгва.

## Задача 3:
Направете клас RealDuck, който съдържа информация за името и възрастта на патето.

## Задача 4:
Направете клас PlasticDuck, който представлява пластмасово сглобяемо пате. Класът да съдържа информация за броя на елементите, от които е съставено.

## Задача 5:
Направете клас Lake, което съдържа масив от патета. Езерото да може да се чете и пише във файл.
