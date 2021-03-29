#pragma once

#include "Node.h"

class LinkedListIterator {
private:
    Node *ptr;
    friend class List;

public:
    using I = LinkedListIterator;

    explicit LinkedListIterator(Node *p = nullptr);

    I next() const;

    int get() const;

    int& get();

    bool operator==(const I &it) const;

    bool operator!=(const I &it) const;

    //it++
    I operator++(int);

    //++it
    I& operator++();

    int operator*() const;

    operator bool() const;
};

