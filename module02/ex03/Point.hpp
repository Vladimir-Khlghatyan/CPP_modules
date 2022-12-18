#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);							// Default constructor
		Point(const Point &other);				// Copy constructor
		Point &operator=(const Point &other);	// Copy assignment operator
		~Point(void);							// Destructor

	public:
		Point(const float x, const float y);	// Parameterized constructor

	public:
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		float	getFloatX(void) const;
		float	getFloatY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
