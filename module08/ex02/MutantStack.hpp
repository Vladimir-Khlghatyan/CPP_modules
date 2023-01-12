#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <string>
# include <vector>
# include <iterator>

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
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};									// Default constructor
		MutantStack(const MutantStack &other) {*this = other;};	// Copy constructor
		MutantStack &operator=(const MutantStack &other) { 		// Copy assignment operator
			if (this != &other)
        		this->c = other.c;
    		return (*this);
		};
		~MutantStack(void) {};									// Destructor

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin()	{return this->c.begin();};
		iterator	end()	{return this->c.end();};
};

#endif
