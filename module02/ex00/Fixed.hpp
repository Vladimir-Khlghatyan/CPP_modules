#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define PINK	"\33[1;35m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;36m"
# define CYAN	"\33[1;37m"
# define WHITE	"\033[1;37m"
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
		int					_fixed_point_number;
		static const int	_fractional_bits = 8;
};

#endif
