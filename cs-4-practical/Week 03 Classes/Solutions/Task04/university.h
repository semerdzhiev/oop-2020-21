#ifndef UNIVERSITY
#define UNIVERSITY

#include <cstring>
#include "enums.h"

template <typename T>
using cmpFn = bool (*)(T, T, Order);

template <typename T>
bool nameCompare(T humanA, T humanB, Order order)
{
    return order == asc ? strcmp(humanA.getName(), humanB.getName()) > 0 : strcmp(humanA.getName(), humanB.getName()) < 0;
}

template <typename T>
bool fnCompare(T humanA, T humanB, Order order)
{
    return order == asc ? strcmp(humanA.getFN(), humanB.getFN()) > 0 : strcmp(humanA.getFN(), humanB.getFN()) < 0;
}

template <typename T>
bool averageScoreCompare(T humanA, T humanB, Order order)
{
    return order == asc ? humanA.getAverage() > humanB.getAverage() : humanA.getAverage() > humanB.getAverage();
}

template<typename T>
class University {
    T* people;
    int size = 0;

    cmpFn<T> getComparison(Field field)
    {
        switch (field)
        {
            case name:
                return nameCompare<T>;
            case fn:
                return fnCompare<T>;
            case averageScore:
                return averageScoreCompare<T>;
            default:
                return nameCompare<T>;
        }
    }

public:
    void createPeople(T *newPeople, int newSize)
    {
        size = newSize;
        people = new T[size];
        for (int i = 0; i < size; i++)
        {
            people[i] = newPeople[i];
        }
    }

    void sort(Field field, Order order)
    {

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (getComparison(field)(people[i], people[j], order))
                {
                    T tmp = people[i];
                    people[i] = people[j];
                    people[j] = tmp;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            people[i].print();
        }
    }

    void clean()
    {
        for (int i = 0; i < size; i++)
        {
            people[i].clean();
        }

        size = 0;
        delete[] people;
    }
};

#endif