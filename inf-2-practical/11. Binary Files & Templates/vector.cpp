#include <iostream>
#include <cassert>

template <typename T>
class Vector
{
public:
  Vector();
  Vector(const Vector &other);
  Vector<T> &operator=(const Vector &other);
  ~Vector();
  void push_back(T new_element);
  T pop_back();
  std::size_t size() const;
  std::size_t capacity() const;
  bool empty() const;
  T &operator[](std::size_t pos);
  const T &operator[](std::size_t pos) const;
  void clear();


private:
  T *m_elements{};
  std::size_t m_size{};
  std::size_t m_capacity{};
  void resize();
};


template <typename T>
Vector<T>::Vector()
{
  m_elements = new T[1];
  m_capacity = 1;
  m_size = 0;
}

template <typename T>
Vector<T>::Vector(const Vector &other)
{
  m_elements = new T[other.m_capacity];

  for (unsigned i = 0; i < other.m_size; i++)
  {
    m_elements[i] = other.m_elements[i];
  }

  m_capacity = other.m_capacity;
  m_size = other.m_size;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other)
{
  if (&other)
  {
    T *buffer = new T[other.m_capacity];

    for (unsigned i = 0; i < other.m_size; i++)
    {
      buffer[i] = other.m_elements[i];
    }

    delete[] m_elements;
    m_elements = buffer;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
  }

  return *this;
}

template <typename T>
Vector<T>::~Vector()
{
  delete[] m_elements;
}

template <typename T>
void Vector<T>::push_back(T new_element)
{
  if (m_size >= m_capacity)
  {
    resize();
  }

  m_elements[m_size++] = new_element;
}

template <typename T>
T Vector<T>::pop_back()
{
  T last_element = m_elements[--m_size];
  return last_element;
}

template <typename T>
std::size_t Vector<T>::capacity() const
{
  return m_capacity;
}

template <typename T>
std::size_t Vector<T>::size() const
{
  return m_size;
}

template <typename T>
bool Vector<T>::empty() const
{
  return m_size == 0;
}

template <typename T>
T &Vector<T>::operator[](std::size_t pos)
{
  assert(pos < m_size);
  return m_elements[pos];
}

template <typename T>
void Vector<T>::clear()
{
  m_size = 0; 
}

template <typename T>
void Vector<T>::resize()
{
  T *buffer = new T[m_capacity * 2];

  for (unsigned i = 0; i < m_size; i++)
  {
    buffer[i] = m_elements[i];
  }

  delete[] m_elements;

  m_elements = buffer;
  m_capacity *= 2;
}
