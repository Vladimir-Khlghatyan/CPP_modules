#include "Point.hpp"

//==========================================================

Point::Point(void)
{
	(Fixed)this->_x = Fixed(0);
	(Fixed)this->_y = Fixed(0);
}

//==========================================================

Point::Point(const Point &other) : _x(other.getFloatX()), _y(other.getFloatY())
{

}

//==========================================================

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed)this->_x = other.getX();
		(Fixed)this->_y = other.getY();
	}
	return (*this);
}

//==========================================================

Point::~Point(void)
{

}

//==========================================================

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{

}

//==========================================================

Fixed Point::getX(void) const
{
    return this->_x;
}

//==========================================================

Fixed Point::getY(void) const
{
    return this->_y;
}

//==========================================================

float	Point::getFloatX(void) const
{
	return this->_x.toFloat();
}

//==========================================================

float	Point::getFloatY(void) const
{
	return this->_y.toFloat();
}

//==========================================================
