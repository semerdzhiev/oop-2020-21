 # Наследяване
 
 [Запис](https://drive.google.com/file/d/1iYa7XANmvVgaKRQhlDufuIw41DrzTtRJ/view?usp=sharing) 

За домашно остана да направите втора и трета задача ^.^

## Още малко оператори
### Conversion operator
```c++
class Time
{
private:
    unsigned seconds{};
    unsigned minutes{};
    unsigned hours{};
public:
    operator bool() const
    {
        return seconds!=0 && minutes !=0 && seconds!=0;
    }
    Time() = default;
    Time(unsigned _seconds, unsigned _minutes = 0, unsigned _hours = 0)
    {
        assert(_seconds < 60 && _minutes < 60 && _hours < 24);
        seconds = _seconds;
        minutes = _minutes;
        hours = _hours;
    }  
};
```

### Increment/Decrement operators
```c++
class Fraction
{
private:
    int numerator{};
    int denominator{};
public:
    // prefix - ++a
    Fraction& operator++() 
    {
        numerator += denominator;
        return *this;
    }

    // postfix - a++
    Fraction operator++(int) // the additional integer parameter here is a 
                             // dummy parameter
                             // used to differentiate the prefix and postfix 
                             // version of the ++/-- operators
    {
        Fraction cpy{*this};
        operator++();
        return cpy;
    }
};
```
[Increment/Decrement operators](https://en.cppreference.com/w/cpp/language/operator_incdec)

### Member access operators
```c++
class IntPointer
{
private:
    int* ptr;
public:
    // Ro3/Ro5 Implementation
    int* operator->()
    {
        return ptr;
    }
    int& operator*()
    {
        return *ptr;  
    }
    // NOTE - we can also overload the
    // '&' - operator
    // we will not do it here
    // so we don't ruin our encapsulation
};
```
[Member access operators](https://en.cppreference.com/w/cpp/language/operator_member_access)

### Function call operator
```c++
struct Quadratic
{
    double a{};
    double b{};
    double c{};
    double operator()(double x)
    {
        return a*x*x + b*x + c;
    } 
};
```

### More operators
[Тук](https://en.cppreference.com/w/cpp/language/operators)

## Наследяване
### protected

```c++
class Base
{
protected:
    int value;
public:
    Base (int _value): value{_value}
    { }
};

class Derived : public Base
{
public: 
    Derived(int _value): value{_value}
    { }
}
```

### order of construction
```c++
class Base
{
protected:
    int value;
public:
    Base (int _value): value{_value}
    { }
};

class Derived : public Base
{
private:
    int other_value{};
public:
    // Case 1 - NOT GOOD
    Derived(int _value, int _other_value): value{_value}, // <-- this works
                                                          // but wouldn't work if
                                                          // value was const, for example
                                           other_value{_other_value} 
    { }
    // Case 2 - GOOD
    Derived(int _value, int _other_value): Base(_value),
                                           other_value{_other_value}
    { }
};
```

При създаване на обект от тип Derived, първо се извиква конструктора на Base и след това този на Derived.
Деструкторите се извикват в обратен ред.


### access specifers & inheritance

![access specifers & inheritance](https://z-p3-scontent.fpdv1-1.fna.fbcdn.net/v/t1.15752-9/176760796_255215846343541_6009060051701602976_n.png?_nc_cat=108&ccb=1-3&_nc_sid=ae9488&_nc_ohc=evrl4DvQ5nwAX_NIyKI&_nc_ht=z-p3-scontent.fpdv1-1.fna&oh=c8198d7c75be4431b391516ef076fe4f&oe=60A627F7)


*[Image credits](https://github.com/triffon/oop-2019-20/blob/master/exercises/2/10-inheritance/seminar-10.pdf)*   
