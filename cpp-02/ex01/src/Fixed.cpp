#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_raw = other._raw;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called " << std::endl;
}

Fixed::Fixed(int const n) : _raw(n << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _raw(static_cast<int>(roundf(n * (1 << _bits))))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_raw) / (1 << _bits);
}

int	Fixed::toInt(void) const
{
	return _raw >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
