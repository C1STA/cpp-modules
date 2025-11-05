#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _raw(0) {}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_raw = other._raw;
	return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(int const n) : _raw(n << _bits) {}

Fixed::Fixed(float const n) : _raw(static_cast<int>(roundf(n * (1 << _bits)))) {}

int	Fixed::getRawBits() const
{
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

bool	Fixed::operator>(const Fixed& other) const
{
	return this->_raw > other._raw;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->_raw < other._raw;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->_raw >= other._raw;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->_raw <= other._raw;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->_raw == other._raw;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->_raw != other._raw;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->_raw++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_raw++;
	return temp;
}

Fixed&	Fixed::operator--()
{
	this->_raw--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_raw--;
	return temp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
