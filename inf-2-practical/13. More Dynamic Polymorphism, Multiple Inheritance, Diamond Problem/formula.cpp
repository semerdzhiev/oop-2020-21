#include <iostream>

class Formula
{
public:
    Formula() = default;
    virtual void print() const = 0;
    virtual float evaluate() const = 0;
    virtual ~Formula() = default;
    virtual Formula* clone() const = 0;
    Formula(const Formula&) = delete;
    Formula& operator=(const Formula&) = delete;
};

class Number : public Formula
{
public:
    Number(float value) : value{value} {}
    void print() const override
    {
        std::cout << value;
    }
    float evaluate() const override
    {
        return value;
    }
    Number* clone() const override
    {
        return new Number{value};
    }

private:
    float value{};
};


class BinaryOperation : public Formula
{
public:
    BinaryOperation(char op, Formula *lhs, Formula *rhs) : op{op}, lhs{lhs}, rhs{rhs} {}
    void print() const override
    {
        std::cout<<'(';
        lhs->print();
        std::cout << op;
        rhs->print();
        std::cout<<')';
    }
    float evaluate() const override
    {
        switch(op)
        {
            case '+':
                return lhs->evaluate() + rhs->evaluate();
            case '-':
                return lhs->evaluate() - rhs->evaluate();
            case '*':
                return lhs->evaluate() * rhs->evaluate();
            case '/':
                return lhs->evaluate() / rhs->evaluate();
            default:
                throw std::runtime_error("Unknown arguments");
        }
    }

    BinaryOperation* clone() const override
    {
        return new BinaryOperation{op, lhs->clone(), rhs->clone()};
    }

    ~BinaryOperation()
    {
        delete lhs;
        delete rhs;
    }
private:
    char op;
    Formula *lhs;
    Formula *rhs;
};

int main()
{
    Formula* f1 = new Number(4.3);
    Formula* f2 = new Number(5);
    Formula* f3 = new BinaryOperation('+', f1, f2); // (4.3 + 5)
    Formula* f4 = new Number(4);
    Formula* f5 = new Number(5);
    Formula* f6 = new BinaryOperation('*', f4, f5); // (4 * 5)
    Formula* f7 = new BinaryOperation('-', f6, f3); // (4 * 5) - (4.3 + 4)
    Formula* f8 = new BinaryOperation('+', new Number(8), f7);
    f7->print();
    std::cout<<"=";
    std::cout<<f7->evaluate()<<std::endl; // 10.7
    Formula* f9 = f7->clone();
    delete f7;
    f9->print();
    std::cout<<"=";
    std::cout<<f9->evaluate()<<std::endl; // 10.7
    delete f9;
    return 0;
}