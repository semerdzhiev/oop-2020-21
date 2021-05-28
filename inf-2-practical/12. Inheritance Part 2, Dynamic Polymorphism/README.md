# Наследяване, Динамичен Полиморфизъм

[Запис](https://drive.google.com/file/d/1t8Zu8-6Rbiko5wAvn1tMavmCYHkTuprC/view?usp=sharing)

## Какво е полиморфизъм?
Свойството обекти от различен тип да имат еднакъв интерфейс, който е реализиран (евентуално) различно за различните типове. Когато става въпрос за ООП, полиморфизма се изразява в това методите в йерархията на класовете да имат (евентуално) различна реализация за всеки клас.

## Полиморфизъм в C++
В C++ има 2 типа полиморфизъм 
- Статичен (compile-time): method **overloading**, function **overloading**, operator **overloading**, templates
- Динамичен (runtime): method **overriding**


Каква е разликата между `overload` & `override`?
- overload - имаме множество методи/функции с еднакво име, но различна сигнатура - различни return types и/или различен брой параметри и/или различен тип на параметрите
- override - предефинира се поведението на някой метод от производен клас, сигнатурата на метода си остава същата като тази на базовия клас

Примери за overload:
```c++
// overloading functions
int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return a + b;
}

// we now know we can use templates for cases like the above one - thus, we are using templates, to achieve overloading
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

// overloading methods
class SomeClassThatSums
{
public:
    int sum_with(int x)
    {
        return a + x;
    }
    double sum_with(double x)
    {
        return a + x;
    }
private:
    int a;
};

```

## Как се реализира динамичен полиморфизъм в C++?
С помощта на така наречените виртуални методи. Когато декларираме метод като виртуален, ние даваме възможност той да бъде предефиниран в наследниците.
Използваме ключовата дума `virtual`, който поставяме пред retyrn-type-a на метода:
```c++
virtual return_type method_name(args...)
```
Когато предефинираме виртуален метод в производен клас няма нужда да използваме ключовата дума `virtual`.

- [A base class destructor should be either public and virtual, or protected and non-virtual](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c35-a-base-class-destructor-should-be-either-public-and-virtual-or-protected-and-non-virtual). Long story short, (почти) винаги правете деструктора виртуален.
- [Do not invoke virtual functions from constructors or destructors](https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP50-CPP.+Do+not+invoke+virtual+functions+from+constructors+or+destructors)

## Абстрактни класове
Абстрактните класове са такива класове, в които има поне един чисто виртуален (pure virtual) метод. Чисто виртуален метод се дефинира така:
```c++
virtual return_type method_name(args...) = 0;
```
Не можем да създаваме обекти от тип абстрактен клас. Когато някой клас наследява абстрактен клас, то той трябва да дефинира всички чисто виртуални методи на базовия, иначе той също ще бъде абстрактен.

## Override & final
Добра практика е при всяко предефиниране на всеки виртуален метод да отбелязваме дали той е `override` или `final`:
```c++
return_type method_name(args...) override
```

```c++
return_type method_name(args...) final
```

С `final` означавме виртуален метод, който не искаме да се предефинира повече от производни класове.
С `override` е хубаво да означаваме всяко предефиниране на метод, който не е "първа" или "последна" дефиниция. Ключовата дума `override` ни предпазва от това да правим грешки в сигнатурите на виртуалните методи, тъй като кара компилатора да проверява дали има виртуални функции със същата сигнатура в родителските класове. 
