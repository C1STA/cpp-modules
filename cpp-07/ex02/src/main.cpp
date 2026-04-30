#include <exception>
#include <iostream>
#include "Array.hpp"

int main(void)
{
	std::cout << "--- empty array ---" << std::endl;
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;

	std::cout << "--- int array(5) ---" << std::endl;
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = static_cast<int>(i * 10);
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;

	std::cout << "--- copy ---" << std::endl;
	Array<int> copy(arr);
	copy[0] = 999;
	std::cout << "original[0]: " << arr[0] << " copy[0]: " << copy[0] << std::endl;

	std::cout << "--- assignment ---" << std::endl;
	Array<int> assigned;
	assigned = arr;
	assigned[1] = 888;
	std::cout << "original[1]: " << arr[1] << " assigned[1]: " << assigned[1] << std::endl;

	std::cout << "--- string array ---" << std::endl;
	Array<std::string> sarr(3);
	sarr[0] = "hello"; sarr[1] = "world"; sarr[2] = "42";
	for (unsigned int i = 0; i < sarr.size(); i++)
		std::cout << sarr[i] << std::endl;

	std::cout << "--- out of bounds ---" << std::endl;
	try {
		std::cout << arr[10] << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
