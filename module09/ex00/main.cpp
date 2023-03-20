#include "BitcoinExchange.hpp"

int errorMsg1(void);
int errorMsg2(void);

int	main(int ac, char **av)
{
	std::ifstream	file1;
	// std::ifstream	file2;
	
	// if (ac != 3)
	// 	return errorMsg1();

	// open exchange rates database	
	file1.open(av[ac - 1]);		
	if (!file1.is_open())
		return errorMsg2();

	// open prices/dates file		
	// file2.open(av[ac - 2]);
	// if (!file2.is_open())
	// {
	// 	file1.close();
	// 	return errorMsg2();
	// }

	BitcoinExchange btc(file1);
	btc.printMap();

	file1.close();
	// file2.close();

	return 0;
}

int	errorMsg1(void)
{
	std::cout << RED << "Error: 2 arguments required => ";
	std::cout << YELLOW << "[exchange rates file] and [prices/dates file].";
	std::cout << RESET << std::endl;
	return 1;
}

int	errorMsg2(void)
{
	std::cout << RED << "Error: could not open file.";
	std::cout << RESET << std::endl;
	return 2;
}
