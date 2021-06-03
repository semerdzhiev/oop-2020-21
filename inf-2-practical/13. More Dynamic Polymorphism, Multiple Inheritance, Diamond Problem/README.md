# Още динамичен полиморфизъм, множествено наследяване, диамантен проблем


[Задачата от часа](https://drive.google.com/file/d/1BW-Uc80Tuliw-kHGspkO3IgflqINND1m/view?usp=sharing)

[автор](https://github.com/Angeld55)

Може да направите 2 задача за домашно ^.^

## Копиране vs Клониране
[A polymorphic class should suppress copying](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c67-a-polymorphic-class-should-suppress-copying)

## Множествено наследяване
В С++ може един производен клас да наследява повече от един базов клас. 
Например:
```c++
class Base1
{
public:
    Base1() = default;
};

class Base2
{
public:
    Base2() = default;
};

class Derived: public Base1, public Base2
{
public:
    Derived() = default;
};
```

- В такъв случай конструктора на `Derived` ще извика конструкторите на базовите си класове в реда на наследяване - тоест, първо конструктора на `Base1`, след това на `Base2`.
- Деструкторите пък се извикват обратно на реда на наследяване - първо деструктора на `Base2`, след това на `Base1`

## Диамантен Проблем
Диамантения проблем се получава, когато нечии 2 родителски класа имат общ базов клас.
Ето следния пример:
```c++
class Person
{
public:
    Person()
    {
        std::cout<<"Person constructor"<<std::endl;
    }
};

class Student: public Person
{
public:
    Student()
    {
        std::cout<<"Student constructor"<<std::endl;
    }
};

class Teacher: public Person
{
public:
    Teacher()
    {
        std::cout<<"Teacher constructor"<<std::endl;
    }
};

class TeachingAssisatant: public Teacher, public Student
{
    TeachingAssistant()
    {
        std::cout<<"Teaching assistant constructor"<<std::endl;
    }
}
```

Ако създадем обект от тип `TeachingAssistant`, това ще ни изведе:
```
Person constructor
Teacher constructor
Person constructor
Student constructor
Teaching assistant constructor
```

Както виждаме, конструкторът на `Person` се е извикал 2 пъти, т.е. имаме 2 инстанции на обект от тип `Person` за един обект от тип `TeachingAssistant`. За да избегнем този проблем, на помощ отново идва ключовата дума `virtual`.

```c++
class Person
{
public:
    Person()
    {
        std::cout<<"Person constructor"<<std::endl;
    }
};

class Student: virtual public Person
{
public:
    Student()
    {
        std::cout<<"Student constructor"<<std::endl;
    }
};

class Teacher: virtual public Person
{
public:
    Teacher()
    {
        std::cout<<"Teacher constructor"<<std::endl;
    }
};

class TeachingAssisatant: public Teacher, public Student
{
    TeachingAssistant()
    {
        std::cout<<"Teaching assistant constructor"<<std::endl;
    }
}
```

Ако остово създадем обект от тип `TeachingAssistant`, това вече ще ни изведе:
```
Person constructor
Teacher constructor
Student constructor
Teaching assistant constructor
```

    Q: Ами ако искаме да викаме конструктор на Person, различен от конструктора му по подразбиране, в Teaching Assistant (например, изобщо нямаме конструктор по подразбиране на Person)? 
    A: Трябва експлицитно да го извикаме в конструктора на Teaching Assistant.