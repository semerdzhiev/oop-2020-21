#pragma once

#include <cstdio>
#include "Node.h"
#include "ListIterator.h"

class List {
private:
    using I = LinkedListIterator;

    Node *front, *back;

public:

    List();

    List(const List &l);

    List &operator=(const List &l);

    ~List();

    int& operator[](size_t idx);
    int operator[](size_t idx) const;

    I begin() const;

    I end() const;

    bool isEmpty() const;

    int getAt(const I& it) const;

    static int& getAt(I& it);

    bool insertBefore(int x, const I& it);

    bool insertAfter(int x, const I& it);

    void insertBegin(int x);

    void insertEnd(int x);

    bool deleteAt(const I& it);

    bool deleteBegin();

    bool deleteEnd();

    bool deleteBefore(const I& it);

    bool deleteAfter(const I& it);

    void print() const;

private:

    void copyList(const List &l);

    void deleteList();

    I findPrev(I const &it);
};
