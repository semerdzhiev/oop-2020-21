# Object Lifetime, RAII, Rule of 3

[Запис от упражнението](https://drive.google.com/file/d/1wsYRZpfJHwDAMe_3P8_i9o2dh-7s7ynp/view?usp=sharing)

## Note about assert
`assert` е макрос, чиято дефиниция зависи от друг макрос - `NDEBUG`. Ако `NDEBUG` е дефиниран, `assert` не прави нищо. Тоест, `assert` прави проверки само когато сме в debug mode. Целта на всички assertion-и които правим е да подсигурим, че кода ни не прави "забранените" неща, дефинирани в assertion-ите. Тези проверки са ни нужни само по време на разработка, тъй като се очаква, че release build-а ни е bug free, а допълнтелни проверки само биха го забавяли излишно. 

[assert on cppreference](https://en.cppreference.com/w/cpp/error/assert)  

## **R**esource **A**cquisition **I**s **I**nitialization
  and moreover - resource deallocation is done at destruction. Това е по-важното. Когато класът ви използва динамична памет, "притежанието" на тази памет е инварианта на класа и е пряко обвързана с живота на обекта. 

## Default Operations
  - Default Constructor - `X()`
  - Default Copy Constructor - `X(const X&)`
  - Default Copy Assignment Operator - `X& operator=(const X&)`
  - Default Destructor - `~X()`
  - Move Constructor - `X(X&&)`
  - Move Assignment Operator - `X operator=(X&&)`

  Когато не дефинираме някое от тези, компилатора дефинира автоматични такива. За последните 2 ще си говорим по-подробно следващия път.

```c++
class X
{
public:
  // The compiler will generate something similiar to
  /*
    X() {}
    X(const X& other)
    {
      val = other.val;
    }
    X& operator=(const X& other)
    {
      val = other.val;
      return *this;
    }
    ~X() {}
  */
private:
  int* val{};
};
```

Забележете че тук в `copy constructor` & `opertor=` нищо не се грижи за копиране на стойността, към която сочи `val`. Единственото което се случва е, че указателя на текущия обект става същия като този на `other` - започват да сочат към една и съща памет.

## Rule of 3
  Ако класът ви дефинира (или трие) някое от
  - Destructor
  - Copy Constructor
  - Copy Assignment Operator
  
  то *най-вероятно* трябва да дефинира (или трие) и трите. 

## Rule of 0
  Ако класът ви не се грижи пряко за динамична памет - *най-вероятно* няма нужда от дефиниране на default operations. С други думи - когато няма нужда, не го правете.
