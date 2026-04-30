#include <stdexcept>

template<typename T>
Array<T>::Array() : _arr(new T[0]()), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(Array const& other) : _arr(new T[other._size]()), _size(other._size)
{
  for (unsigned int i = 0; i < _size; i++)
    _arr[i] = other._arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
  if (this != &other)
  {
    delete[] _arr;
    _size = other._size;
    _arr = new T[_size]();
    for (unsigned int i = 0; i < _size; i++)
      _arr[i] = other._arr[i];
  }
  return *this;
}

template<typename T>
Array<T>::~Array() { delete[] _arr; }

template<typename T>
T&  Array<T>::operator[](unsigned int idx)
{
  if (idx >= _size)
    throw std::out_of_range("Index out of bounds");
  return _arr[idx];
}

template<typename T>
T const& Array<T>::operator[](unsigned int idx) const
{
  if (idx >= _size)
    throw std::out_of_range("Index out of bounds");
  return _arr[idx];
}

template<typename T>
unsigned int Array<T>::size() const { return _size; }
