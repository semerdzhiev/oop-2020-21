# Класове, енкапсулация, инварианти

[Запис от упражнението](https://drive.google.com/file/d/183aexZxkvolY1rQjLhsvQrh-Gan-HpqQ/view?usp=sharing)

## Бележки

### Класове
Клас дефинираме по същия начин като структура:

```c++
class Person
{
    char name[50]{};
    unsigned age{};
};
```

### Спецификатори на достъп (Access modifiers)
1. `public`, `private`, `protected` (за него ще си говорим по-късно в курса)
2. Спецификаторът за достъп на класовете по пдразбиране е `private`, а на структурите - `public`. Това е и 
единствената съществена разлика между тях. По тази причина класът `Person`, дефиниран по-горе, **няма да има** видими извън него член-данни.

### Методи (член-функции)
1. Функции, дефинирани в тялото на класа
2. Специалното за тях е, че имат "скрит" указател към обекта, който ги извиква - `this`. Използваме го експлицитно, когато имаме еднакви имена на аргументите на функциите и член-данните на обекта (не е препоръчително) 
3. Препоръчително е всички методи, които не променят обекта, да бъдат константи
   
   > **NB:** Всички константни методи правят указателя `this` константен => в тялото им можем да извикваме само други константни методи. 
    
### Конструктори 
1. Методи, които се извикват, когато създаваме обект от класа
2. Името им е същото като името на класа
3. Могат да приемат всякакви аргументи, които ни трябват за създаването на обекта (най-често са стойностите на някои/всички от член-данните)
4. Когато не дефинираме конструктор в тялото на класа **се създава** конструктор по подразбиране, който инициализира всички член-данни с тези стойности, които сме им задали по подразбиране
5. Когато дефинираме конструктор в тялото на класа **не се създава** констрктор по подразбиране
5. Препоръчително е да използваме инициализиращ списък, вместо да присвояваме в тялото на класа (когато това е възможно)

```c++
class Person
{
public:
    Person() = default; // if we still want to keep the default constructor
    Person(unsigned age, const char* name) : m_age{age}
    {
        std::strcpy(m_name, name); //we cannot do this in the initialzier list
    }
private:
    char m_name[50]{};
    unsigned m_age{};
};

```c++
// GOOD
class Person
{
public:
    bool is_years_old(unsigned age) const
    {
        // the same as (age == this->m_age)
        // but we do not have to explicitly indicate
        // we want to access the object's 'm_age' property
        return age == m_age;
    }
private:
    char m_name[50]{};
    unsigned m_age{};
};
```

```c++
// NOT SO GOOD
class Person
{
public:
    bool is_years_old(unsigned age) const
    {
        // here we must use the 'this' pointer
        // to access the object's 'age' property
        return age == this->age;
    }
private:
    char name[50]{};
    unsigned age{};
};
```

### Selectors & Мutators (Getters & Сetters)
1. Методи, чието предназначение е да дават "безопасен" начин за употреба на нашите класове. Чрез тях реализираме принципа за **енкапсулация**. 
2. Всички член-данни, чиято стойност желаем да е видима публично, expose-ваме чрез selector-и. Препоръчително е selector-ите да са константи функции.
3. Всички член-данни, чиято стойност желаем да може да се променя публично, expose-ваме чрез mutator-и.

```c++
class Person
{
public:
    // selectors
    unsigned get_age() const
    {
        return m_age;
    }
    const char* get_name() const
    {
        return m_name;
    }

    // mutators
    void set_age(unsigned age)
    {
        m_age = age;
    }
    void set_name(const char* name)
    {
        std::strcpy(m_name, name);
    }
private:
    char m_name[50]{};
    unsigned m_age{};
};
```

### Инварианти
Инвариантите на класовете са някакви свойства на всички обекти от този клас, които остават непроменени през цялото си съществуване - независимо как и колко се модифицират самите обекти.

Пример: Човек е пълнолетен когато навърши 18 години. Ако имаме клас `Adult`, който представя пълнолетен човек, и пазим неговата възраст в полето `m_age`, то инвариантата ни е: всеки обект от тип `Adult` има (и трябва винаги да има) `m_age>=18` 

#### cassert

```c++
#include <cassert>

class Adult
{
public:
    Adult(unsigned age) : m_age{age}
    {
        assert(age>=18);
    }
    void set_age(unsigned age)
    {
        assert(age>=18);
        m_age = age;
    }
private:
    unsigned m_age{};
};
```