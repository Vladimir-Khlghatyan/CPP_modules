#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_FPV = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{

}

int	Fixed::getRawBits(void) const
{
	return(this->_FPV);
}

void	Fixed::setRawBits(int const raw)
{
	this->_FPV = raw;
}

//=====================================================================================

Fixed::Fixed(const int param)
{
	this->setRawBits(param << this->_FB);
}

Fixed::Fixed(const float param)
{
	this->setRawBits((int)roundf(param * (1 << this->_FB)));
}

float   Fixed::toFloat(void) const {
    return static_cast<float>(this->_FPV) / (1 << this->_FB);
}

int	Fixed::toInt(void) const
{
	return (this->_FPV >> this->_FB);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

//==== comparison operators ===========================================================

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

//==== arithmetic operators ===========================================================

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

//==== increment/decrement operators ==================================================

Fixed	&Fixed::operator++(void)
{
	++this->_FPV;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++this->_FPV;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	--this->_FPV;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--this->_FPV;
	return (tmp);
}

//==== overloaded member functions ====================================================

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
