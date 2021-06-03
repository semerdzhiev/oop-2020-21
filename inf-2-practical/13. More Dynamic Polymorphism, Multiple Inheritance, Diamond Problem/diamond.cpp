#include <string>
#include <iostream>

class PrintedEdition
{
public:
    PrintedEdition(const std::string &name, unsigned year, unsigned price) : name{name},
                                                                             year{year},
                                                                             price{price}
    {
        std::cout<<"Printed edition constructor\n";
    }
    virtual ~PrintedEdition() = default;

private:
    std::string name{};
    unsigned year{};
    unsigned price{};
};

enum class Periodicity
{
    DAILY,
    WEEKLY,
    MONTHLY,
    ANNUAL,
};

class Magazine : virtual public PrintedEdition
{

public:
    Magazine(const std::string &name, unsigned year, unsigned price, Periodicity periodicity) : PrintedEdition(name, year, price),
                                                                                                periodicity{periodicity}
    {
        std::cout<<"Magazine constructor\n";
    }

private:
    Periodicity periodicity{};
};

class Book : virtual public PrintedEdition
{
public:
    Book(const std::string &name, unsigned year, unsigned price, const std::string &author) : PrintedEdition(name, year, price),
                                                                                              author{author}
    {
        std::cout<<"Book constructor\n";
    }

private:
    std::string author{};
};

class Comics : public Book, public Magazine
{
public:
    Comics(const std::string &name, unsigned year, unsigned price, const std::string &author, Periodicity periodicity) : PrintedEdition(name, year, price),
                                                                                                                         Book(name, year, price, author),
                                                                                                                         Magazine(name, year, price, periodicity)
    {
        std::cout<<"Comics constructor\n";
    }
};

int main()
{
    Comics c("spiderman", 2009, 10, "someone", Periodicity::WEEKLY);
    return 0;
}