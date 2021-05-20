#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

#include <cstddef>
#include <ostream>
 
template <typename T>
class List {
public:
    List(T arr[], size_t size);
    List(const List<T>& rhs);
    List<T> operator=(const List<T>& rhs) = delete;
    ~List();

    void add(T& elem);
    bool remove(T& elem);
    bool remove(size_t idx);
    bool contains(T& elem) const;
    size_t getCapacity() const;
    size_t getSize() const;
    T& operator[](size_t idx);
    void print() const;

    List<T> filter(bool (*func)(T));

    template<typename F>
    List<T> genFilter(F f);

    template<typename T2>
    List<T2> map(T2 (*func)(T));

    T reduce(T (*func)(T, T), T);

    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const List<U>& list);

private:
    T* arr;
    size_t size;
    size_t capacity;
};


#include "List.inl"

#endif //TEMPLATE_LIST_H
