#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_FPV = 0;
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	this->_FPV = other.getRawBits(); // <-- This is deep copy
	// *this = other; // <-- This is shallow copy
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

//=================================================================================

Fixed::Fixed(const int value)
{
	this->_FPV = (value << this->_FB);  // moving bits of "value" to the left (8 bits)
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float value)
{
	_FPV = roundf(value * (1 << this->_FB));
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>(this->getRawBits());
}

int	Fixed::toInt(void) const
{
	return (this->_FPV >> this->_FB);
}







