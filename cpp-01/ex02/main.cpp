#include <iostream>
#include <string>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of 'string' in memory : " << &string << std::endl;
	std::cout << "Address held in 'stringPTR' : " << stringPTR << std::endl;
	std::cout << "Address held in 'stringREF' : " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of 'string' : " << string << std::endl;
	std::cout << "Pointed value by 'stringPTR' : " << *stringPTR << std::endl;
	std::cout << "Pointed value by 'stringREF' : " << stringREF << std::endl;

	return (0);
}
