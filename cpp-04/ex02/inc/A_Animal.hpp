#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <string>

class A_Animal
{
protected:
	std::string	_type;
public:
	A_Animal();
	A_Animal(const A_Animal& other);
	A_Animal&	operator=(const A_Animal& other);
	virtual ~A_Animal();

	A_Animal(const std::string& type);
	
	virtual void	makeSound() const = 0;
	std::string getType() const;
};

#endif