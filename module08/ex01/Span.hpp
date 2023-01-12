#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <string>
# include <algorithm>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <sys/time.h>
# include <unistd.h>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

typedef std::vector<int>::iterator	vecIt;

class Span
{
	private:
		std::vector<int>	_spanVector;

	public:
		Span(void);					// Default constructor
		Span(unsigned int N);					// Parameterized constructor
		Span(const Span &other);				// Copy constructor
		Span &operator=(const Span &other);		// Copy assignment operator
		~Span(void);							// Destructor

	public:
		void			addNumber(int n);
		void			addRange(vecIt begin, vecIt end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

	public:
		class	SpanIsFullException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	NotEnoughElementsException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	NotEnoughSpaceException : public std::exception
		{
			public:
				const char	*what() const throw();
		};	
};

#include "Span.tpp"

#endif
