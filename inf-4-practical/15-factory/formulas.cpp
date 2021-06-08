#include <iostream>
#include <stdexcept>
#include <string>

class Formula
{
public:
    Formula() = default;
    virtual ~Formula() = default;

    virtual Formula* clone() const = 0;

    virtual float evaluate() const = 0;
    virtual std::ostream& print(std::ostream& out = std::cout) const = 0;
};

class Number : public Formula {
public:
	Number() = default;
	Number(float value): data(value) {};
	Number(const Number&) = default;
	Number& operator=(const Number&) = default;
	~Number() = default;


    Formula* clone() const override
    {
    	return new Number(*this);
    }

    float evaluate() const override
    {
    	return data;
    }

    std::ostream& print(std::ostream& out = std::cout) const override
    {
    	out << data;
    	return out;
    }

private:
	float data;
};

class Expression : public Formula
{
public:
	Expression() = default;
	Expression(char operation, const Formula* left, const Formula* right) : op(operation)
	{
		lhs = left->clone();
		rhs = right->clone();
	}
	Expression(const Expression& other) : op(other.op), lhs(other.lhs->clone()), rhs(other.rhs->clone()) {}
	Expression& operator=(const Expression& other)
	{
		if (this != &other)
		{
			op = other.op;
			lhs = other.lhs->clone();
			rhs = other.rhs->clone();
		}
		return *this;
	}
	~Expression()
	{
		delete lhs;
		delete rhs;
	}

	Formula* clone() const override
	{
		return new Expression(*this);
	}

	float evaluate() const override
	{
		switch (op)
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
				throw std::runtime_error("Invalid operation");
		}
	}

	std::ostream& print(std::ostream& out = std::cout) const override
	{
		out << '(';
		lhs->print(out);
		out << op;
		rhs->print(out);
		out << ')';
		return out;
	}	
private:
	char op;
	Formula* lhs;
	Formula* rhs;
};

size_t findNextOperation(const std::string& expression, size_t from = 0)
{
	// ((1+2)*(3+4))
	// 		 *
	// (1+2) 	   (3+4)
	//   +			 +
	// 1   2      3    4
	char cur{expression[from++]};

	if (cur >= '0' && cur <= '9')
	{
		return from;
	}

	for (size_t count = 1; count != 0 ; from++)
	{
		cur = expression[from];

		if (cur == '(')
		{
			++count;
		}
		else if (cur == ')')
		{
			--count;
		}
	}
	return from;
}

Formula* parse(const std::string& expression, size_t from = 0)
{
	char cur{expression[from]};
	if (cur >= '0' && cur <= '9')
	{
		return new Number(static_cast<float>(cur - '0'));
	}

	// cur = '('
	size_t next = findNextOperation(expression, from + 1);
	char op = expression[next];
	Formula* lhs = parse(expression, from + 1);
	Formula* rhs = parse(expression, next + 1);

	return new Expression(op, lhs, rhs);
}

int main(int argc, char const *argv[])
{
	Formula* f = parse("((1+2)*3");
	Expression* expr = dynamic_cast<Expression*>(f);
	f->print();
	std::cout << '=' << f->evaluate() << std::endl;
	return 0;
}