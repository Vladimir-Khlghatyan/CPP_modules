#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	std::ifstream file;	
	file.open(av[1]);
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
			std::cout << line << std::endl;
		file.close();
	}

	return 0;
}

