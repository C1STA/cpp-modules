#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {

private:
  T            *_arr;
  unsigned int  _size;
public:
  Array();
  Array(unsigned int);
  Array(Array const&);
  Array&  operator=(Array const&);
  ~Array();

  T&  operator[](unsigned int);
  T const&  operator[](unsigned int) const;

  unsigned int size() const;

};

#include "Array.tpp"

#endif