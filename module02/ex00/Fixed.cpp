#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_FPV = 0;
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	this->_FPV = other.getRawBits();	// <-- This is deep copy
	// *this = other; 					// <-- This is shallow copy
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << PINK << "Copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
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
	return(this->_FPV);
}

void	Fixed::setRawBits(int const raw)
{
	this->_FPV = raw;
}
