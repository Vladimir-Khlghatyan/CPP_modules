#include "BitcoinExchange.hpp"

int errorMsg1(void);
int	errorMsg2(std::ifstream	&databaseFile, std::ifstream &priceFile);

int	main(int ac, char **av)
{
	std::ifstream	databaseFile;
	std::ifstream	priceFile;
	
	if (ac != 3)
		return errorMsg1();

	databaseFile.open(av[ac - 2]);		
	if (!databaseFile.is_open())
		return errorMsg2(databaseFile, priceFile);

	priceFile.open(av[ac - 1]);
	if (!priceFile.is_open())
		return errorMsg2(databaseFile, priceFile);

	BitcoinExchange btc(databaseFile);
	btc.display_values_multiplied_by_the_exchange_rates(priceFile);

	databaseFile.close();
	priceFile.close();
	return 0;
}

int	errorMsg1(void)
{
	std::cout << RED << "Error: 2 arguments required => ";
	std::cout << YELLOW << "[exchange rates file] and [prices/dates file].";
	std::cout << RESET << std::endl;
	return 1;
}

int	errorMsg2(std::ifstream	&databaseFile, std::ifstream &priceFile)
{
	if (databaseFile.is_open())
		databaseFile.close();
	if (priceFile.is_open())
		priceFile.close();
	std::cout << RED << "Error: could not open file.";
	std::cout << RESET << std::endl;
	return 2;
}
