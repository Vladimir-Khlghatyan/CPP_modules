#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iostream>
# include <exception>
# include <string>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class NotFindException : public exception
{
	public:
		what() const throw() {
			return ("\33[1;31mEXCEPTION: element not find!\33[0;m");
		}
};

template <typename T>
void    easyfind(T& t, int toFind)
{
	int	idx = -1;

	for (T::iterator *prt = t.begin(); prt != t.end(); prt++)
	{
		idx++;
		if (*prt == toFind)
		{
			std::cout << "The number " << toFind << "is found in index " << i << std::endl;
			return ;
		}
	}
	throw NotFindException();
}

#endif
