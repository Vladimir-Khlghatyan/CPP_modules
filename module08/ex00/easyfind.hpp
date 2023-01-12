#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <string>
# include <algorithm>

# define BLACK	"\33[1;30m"
# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class NotFoundException : public std::exception
{
	public:
		const char *what() const throw() {
			return ("\33[1;31mEXCEPTION: element not found!\33[0;m");
		}
};

template <typename T>
void    easyfind(T const &t, int toFind)
{
	typename T::const_iterator it;

	it = std::find(t.begin(), t.end(), toFind);
	if (it == t.end())
		throw NotFoundException();
	else
	{
		std::cout << GREEN << "The number ";
		std::cout << WHITE << toFind;
		std::cout << GREEN << " is under index ";
		std::cout << WHITE << it - t.begin();
		std::cout << GREEN << "." << RESET << std::endl;
	}
}

#endif
