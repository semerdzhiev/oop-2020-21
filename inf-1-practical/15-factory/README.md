## Формула

Реализирайте работата с формули от вида: (1+2), ((1+2)*2) и тн. За леснота приемете следните правила:
- числата винаги са с плаваща запетая
- изразите се заграждат винаги със скоби
- поддържаните операции между числата са +-*/

Разгледайте примерната йерархична структура дадена по-долу и имплементирайте тяхната логика.

```
class Formula
{
 public:
    Formula() = default;
    ... float evaluate() ...;
    ... std::ostream& print(std::ostream& out = std::cout) ...;
    ... ~Formula() = default;
    ... Formula* clone() ...;
    Formula(const Formula&) = delete;
    Formula& operator=(const Formula&) = delete;
};


class Number: public Formula
{
 public:
    Number(float value) {}
    .
    .
    .
 private:
    float value;
}

class Operation : public Formula
{
 public:
    Operation(char op, Formula* lhs, Formula* rhs) {}
    .
    .
    .

 private:
    char m_op;
    Formula* m_lhs;
    Formula* m_rhs;
}
```
