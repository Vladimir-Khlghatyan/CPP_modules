#include "BitcoinExchange.hpp"

int errorMsg1(void);
int errorMsg2(void);

int	main(int ac, char **av)
{
	std::ifstream	databaseFile;
	std::ifstream	priceFile;
	
	// if (ac != 3)
	// 	return errorMsg1();

	// open exchange rates database	
	databaseFile.open(av[ac - 1]);		
	if (!databaseFile.is_open())
		return errorMsg2();

	// open prices/dates file		
	// priceFile.open(av[ac - 2]);
	// if (!priceFile.is_open())
	// {
	// 	databaseFile.close();
	// 	return errorMsg2();
	// }

	BitcoinExchange btc(databaseFile);
	btc.printMap();

	databaseFile.close();
	// priceFile.close();

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
