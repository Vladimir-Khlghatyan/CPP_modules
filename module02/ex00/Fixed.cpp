#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_fixed_point_number = 0;
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	this->_fixed_point_number = other.getRawBits(); // <-- This is deep copy
	// *this = other; // <-- This is shallow copy
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
	{
		std::cout << PINK << "Copy assignment operator called" << RESET << std::endl;
		return (*this);
	}
	std::cout << PINK << "Copy assignment operator called" << RESET << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << BLUE << "getRawBits member function called" << RESET << std::endl;
	return(this->_fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_number = raw;
}
