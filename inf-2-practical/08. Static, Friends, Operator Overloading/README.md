# Статични членове, Приятели, Предефиниране на оператори 

[Запис](https://drive.google.com/file/d/1uatmQ1DzFH_MA7DtkHxy-YnYtB2aD6D3/view?usp=sharing)

## Статични членове

Статичните полета и методи са част от класа, а не от обекта, т.е. всички инстанции на даден клас споделят общи статични полета и методи.
Статичните методи могат да достъпват само статични полета и методи, но могат да бъдат достъпвани и от нестатични методи.

Пример: 

```c++
class Person
{
private:
    static int numberOfPeople;

public:
    static int publicMember;

    Person()
    {
        numberOfPeople++;
    }
    static int getNumberOfPeople()
    {
        return numberOfPeople;
    }
};

int Person::numberOfPeople = 0;  // в source файла

int main()
{
  
    Person p1;
    cout << Person::getNumberOfPeople() << endl; // 1

    Person p2, p3;
    cout << p3.getNumberOfPeople() << endl; // 3
    cout << p1.getNumberOfPeople() << endl; // 3
    cout << Person::getNumberOfPeople() << endl; // 3
};
```

## Приятелски класове, методи и функции

Когато декларираме даден клас като приятел на друг, то той има достъп до private членовете му.
Трябва да сме внимателни с приятелските класове, защото може да нарушим енкапсулацията и разделението между отделните класове.


Примери:

Приятелски клас:

```c++
class X
{
private:
    int x;

public:

    X(int _x): x(_x){}

    friend class Y;

};

class Y
{
    X xObj{6};

public:

    void substractX()
    {
        xObj.x--;
    }
};
```
Приятелството не е двустранно. У е приятел на Х, но Х не е приятел на У (освен ако не го декларираме като такъв). 



Приятелски метод:

```c++
class Y;

class X
{
public:
    void showY(Y& y);
};

class Y
{
    int y;

public:
    Y(int _y):  y(_y) {}

    friend void X::showY(Y& y);
};

void X::showY(Y& yObj)
{
    cout << yObj.y << endl;
}
```

Приятелска функция: 

```c++
class X
{
    int x;
public:
    X(int _x): x(_x) {}

    friend void showX(X&);
};

void showX(X& xObj)
{
    cout << xObj.x << endl;
}
```






