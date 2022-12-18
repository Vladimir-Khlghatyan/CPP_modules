#include "Fixed.hpp"

std::string ft_bool(int t)
{
	if (t)
		return ("true");
	return ("false");

}

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << WHITE << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << CYAN << "---- My tests ----------------" << std::endl;
	std::cout << std::endl;

	Fixed	x(2.3f);
	Fixed	y(5.9f);

	std::cout << YELLOW << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;

	std::cout << std::endl;

	std::cout << BLUE << "x > y  ---> " << ft_bool(x > y) << std::endl;
	std::cout << "x < y  ---> " << ft_bool(x < y) << std::endl;
	std::cout << "x >= y ---> " << ft_bool(x >= y) << std::endl;
	std::cout << "x <= y ---> " << ft_bool(x <= y) << std::endl;
	std::cout << "x == y ---> " << ft_bool(x == y) << std::endl;
	std::cout << "x != y ---> " << ft_bool(x != y) << std::endl;

	std::cout << std::endl;
	
	std::cout << GREEN << "x + y = " << x + y << std::endl;
	std::cout << "x - y = " << x - y << std::endl;
	std::cout << "x * y = " << x * y << std::endl;
	std::cout << "x / y = " << x / y << std::endl;

	std::cout << std::endl;

	std::cout << RED << Fixed::max(x,y) << " > " << Fixed::min(x,y) << std::endl;
	std::cout << Fixed::min(x,y) << " < " << Fixed::max(x,y) << RESET << std::endl;
	return (0);
}
