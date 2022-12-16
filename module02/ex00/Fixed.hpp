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
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_FPV; 					// Fixed Point Value
		static const int	_fractional_bits = 8;	// Fractional Bits
};

#endif
