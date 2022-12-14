#include "Karen.hpp"

int	main(int ac, char **av)
{
	Karen		karen;
	std::string	command = "";
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	if (ac > 1)
		command = av[1];
	while (i < 4 and command.compare(levels[i]))
		i++;
	switch (i)
	{
		case 0:
			std::cout << WHITE << "[ " << levels[0] << " ]" << RESET << std::endl;
			karen.complain(levels[0]);
			std::cout << std::endl;
		case 1:
			std::cout << WHITE << "[ " << levels[1] << " ]" << RESET << std::endl;
			karen.complain(levels[1]);
			std::cout << std::endl;
		case 2:
			std::cout << WHITE << "[ " << levels[2] << " ]" << RESET << std::endl;
			karen.complain(levels[2]);
			std::cout << std::endl;
		case 3:
			std::cout << WHITE << "[ " << levels[3] << " ]" << RESET << std::endl;
			karen.complain(levels[3]);
			std::cout << std::endl;
			break ;
		default:
			std::cout << WHITE << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
	}
	return (0);
}
