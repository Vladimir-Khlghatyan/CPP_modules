#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <climits>
# include <cctype>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cmath>

class Converter
{
	private:
		std::string	_argument;

	public:
		Converter(void);								// Default constructor
		Converter(std::string const &argument);			// Parameterized constructor
		Converter(const Converter &other);				// Copy constructor
		Converter &operator=(const Converter &other);	// Copy assignment operator
		~Converter(void);								// Destructor

	public:
		operator char(void);
		operator int(void);
		operator float(void);
		operator double(void);		
};

#endif