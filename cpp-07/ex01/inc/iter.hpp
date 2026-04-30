#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void iter(T *arr, std::size_t const size, void (*f)(T&))
{
	for (std::size_t i = 0; i < size; i++)
		f(arr[i]);
}

template<typename T>
void iter(T const *arr, std::size_t const size, void (*f)(T const&))
{
	for (std::size_t i = 0; i < size; i++)
		f(arr[i]);
}

#endif