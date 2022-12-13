#include "Sed.hpp"

int	main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cerr << RED << "Number of args must be four!" << RESET << std::endl;
		return (1);
	}
	std::string	inFile = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	Sed sed(inFile);
	sed.replace(s1, s2);
	return (0);
}
