#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Fixed
{
	private:
		int					_FPV; 				// Fixed Point Value
		static const int	_FB = 8;			// Fractional Bits

	public:
		Fixed(void);							// Default constructor
		Fixed(const Fixed &other);				// Copy constructor
		Fixed &operator=(const Fixed &other);	// Copy assignment operator
		~Fixed(void);							// Destructor

	public:
		Fixed(const int param);					// Parameterized constructor
		Fixed(const float param);				// Parameterized constructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	public:
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

	public:
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

	public:
		Fixed	&operator++(void);	// pre-increment
    	Fixed	operator++(int);	// post-increment
    	Fixed	&operator--(void);	// pre-decrement
    	Fixed	operator--(int);	// post-decrement

    public:
    	static Fixed		&min(Fixed &a, Fixed &b);
    	static const Fixed	&min(const Fixed &a, const Fixed &b);
    	static Fixed		&max(Fixed &a, Fixed &b);
    	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &i);

#endif
