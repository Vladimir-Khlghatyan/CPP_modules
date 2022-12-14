#include "Sed.hpp"

int	main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cerr << RED << "Please enter ";
		std::cerr << YELLOW << "1) ";
		std::cerr << RED << "filename ";
		std::cerr << YELLOW <<  "2) ";
		std::cerr << RED << "str to find and ";
		std::cerr << YELLOW << "3) ";
		std::cerr << RED << "str to replace!" << RESET << std::endl;
		return (1);
	}
	std::string	inFile = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	Sed sed(inFile);
	sed.replace(s1, s2);
	return (0);
}
