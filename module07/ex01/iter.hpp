#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

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
void	iter(T* array, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	myPrint(T& item)
{
	static size_t idx;
	std::cout << RESET << "item[" << idx << "]: ";
	std::cout << WHITE << item <<  RESET << std::endl;
	idx++;
}

#endif
