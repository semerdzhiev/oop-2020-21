#ifndef ITEM
#define ITEM

class Item
{
private:
    char* name;
    double weight;
    double volume;

public:
    Item();
    Item(const char *name, double weight, double volume);

    const char* getName() const;
    double getVolume() const;
    double getWeight() const;

    Item &operator=(const Item &item);
    bool operator==(const Item &item);
    bool operator>(const Item &item);

    ~Item();
};

#endif