#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <string>
# include <ctime>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

template <typename T>
class Array
{
	private:
		unsigned int _n;
		T*			_arrT;

	public:
		Array(void);							// Default constructor
		Array(unsigned int n);					// Parameterized constructor
		Array(const Array &other);				// Copy constructor
		Array &operator=(const Array &other);	// Copy assignment operator
		~Array(void);							// Destructor

	public:
		T				&operator[](unsigned int index) const;
		unsigned int	size(void) const;

	public:
		class OutOfBoundsException : public std::exception
		{
			const char	*what() const throw();
		};	
};

# include "Array.tpp"

#endif
