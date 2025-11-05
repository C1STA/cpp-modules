#include "Fixed.hpp"

int	main()
{

	Fixed				a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}

/* int	main()
{
	Fixed	a(2);
	Fixed	b(3.5f);
	Fixed	c(a);
	Fixed	d;

	std::cout << "--- Constructors ---" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl << std::endl;

	std::cout << "--- Comparisons ---" << std::endl;
	std::cout << "(a < b): " << (a < b) << std::endl;
	std::cout << "(a > b): " << (a > b) << std::endl;
	std::cout << "(a <= c): " << (a <= c) << std::endl;
	std::cout << "(a == c): " << (a == c) << std::endl;
	std::cout << "(a != b): " << (a != b) << std::endl << std::endl;

  std::cout << "--- Arithmetic ---" << std::endl;
  std::cout << "a + b = " << (a + b) << std::endl;
  std::cout << "b - a = " << (b - a) << std::endl;
  std::cout << "a * b = " << (a * b) << std::endl;
  std::cout << "b / a = " << (b / a) << std::endl << std::endl;

	std::cout << "--- Increment / Decrement ---" << std::endl;
	Fixed	e;
	std::cout << "e = " << e << std::endl;
	std::cout << "++e = " << ++e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "e after = " << e << std::endl;
	std::cout << "--e = " << --e << std::endl;
	std::cout << "e-- = " << e-- << std::endl;
	std::cout << "e after = " << e << std::endl << std::endl;

	std::cout << "--- Min / Max ---" << std::endl;
	Fixed	f(10);
	const Fixed	g(42.42f);
	std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;

	return 0;
} */
