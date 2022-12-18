#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
