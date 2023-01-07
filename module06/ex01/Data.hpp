#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Data
{
	private:
		std::string	_value;

	public:
		Data(void);							// Default constructor
		Data(std::string const &value);		// Parameterized constructor
		Data(const Data &other);			// Copy constructor
		Data &operator=(const Data &other);	// Copy assignment operator
		~Data(void);						// Destructor

	public:
		const std::string	getValue(void) const;

};

#endif