#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T const& x)
{
	std::cout << x << std::endl;
}

template<typename T>
void increment(T& x)
{
	x++;
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::cout << "--- int array ---" << std::endl;
	iter(arr, 5, print<int>);

	std::cout << "--- after increment ---" << std::endl;
	iter(arr, 5, increment<int>);
	iter(arr, 5, print<int>);

	std::string strs[] = {"hello", "world", "42"};
	std::cout << "--- string array ---" << std::endl;
	iter(strs, 3, print<std::string>);

	int const carr[] = {10, 20, 30};
	std::cout << "--- const int array ---" << std::endl;
	iter(carr, 3, print<int>);

	return 0;
}
