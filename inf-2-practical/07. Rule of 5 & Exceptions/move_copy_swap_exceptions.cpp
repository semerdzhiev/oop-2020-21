#include <iostream>
#include <cstring>

class Beer
{
private:
    char *brand;
    unsigned volume{};
    double abv{};

    void copy(const Beer &other)
    {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);

        volume = other.volume;
        abv = other.abv;
    }
    void erase()
    {
        delete[] brand;
    }

    void move(Beer &&other)
    {
        brand = std::move(other.brand);
        abv = other.abv;
        volume = other.volume;
    }

public:
    Beer()
    {
        brand = new char[1];
        brand[0] = '\0';
    }

    Beer(const char *_brand, unsigned _volume, double _abv) : volume{_volume}, abv{_abv}
    {
        brand = new char[strlen(_brand) + 1];
        strcpy(brand, _brand);
    }

    Beer(const Beer &other)
    {
        copy(other);
    }

    Beer(Beer &&other)
    {
        move(std::move(other));
    }

    Beer &operator=(const Beer &other)
    {
        if (this != &other)
        {
            erase();
            copy(other);
        }

        return *this;
    }

    Beer &operator=(Beer &&other)
    {
        if (this != &other)
        {
            erase();
            move(std::move(other));
        }

        return *this;
    }

    void print()
    {
        std::cout << brand << " " << abv << " " << volume << std::endl;
    }

    ~Beer()
    {
        erase();
    }
};

class Beerhouse
{
private:
    Beer *beers;
    unsigned count{};
    unsigned capacity{};

    void copyHouse(const Beerhouse &other)
    {
        beers = new Beer[other.capacity];
        for (unsigned i = 0; i < other.count; i++)
        {
            beers[i] = other.beers[i];
        }
        count = other.count;
        capacity = other.capacity;
    }

public:
    Beerhouse(unsigned _capacity) : capacity{_capacity}, count{0}
    {
        beers = new Beer[capacity];
    }

    ~Beerhouse()
    {
        delete[] beers;
    }

    Beerhouse(const Beerhouse &other)
    {
        copyHouse(other);
    }

    Beerhouse &operator=(const Beerhouse &other) // copy & swap
    {
        Beerhouse cpy{other};
        std::swap(cpy.beers, beers);
        std::swap(cpy.count, count);
        std::swap(cpy.capacity, capacity);
        return *this;
    }

    Beerhouse(Beerhouse &&other)
    {
        beers = std::move(other.beers);
        count = other.count;
        capacity = other.capacity;
    }

    Beerhouse &operator=(Beerhouse &&other) //move & swap
    {
        Beerhouse cpy{other};
        std::swap(cpy.beers, beers);
        std::swap(cpy.count, count);
        std::swap(cpy.capacity, capacity);
        return *this;
    }

    void addBeer(Beer newBeer)
    {
        if (count == capacity)
        {
            throw std::length_error("Exceeded capacity");
        }
        beers[count++] = newBeer;
    }

    void print()
    {
        for (unsigned i = 0; i < count; i++)
        {
            beers[i].print();
        }
    }
};

int main()
{

    Beer beer1{"Tuborg", 330, 4.6};
    Beer beer2{"Stela Artois", 500, 4.5};

    Beerhouse beerhouse1{1};
    try
    {
        beerhouse1.addBeer(beer1);
    }
    catch (std::length_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        beerhouse1.addBeer(beer2);
    }
    catch (std::length_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
