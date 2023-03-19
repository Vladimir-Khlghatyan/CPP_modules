#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class BitcoinExchange
{
	private:
		const std::map<std::string, float> database;

	public:
		BitcoinExchange(const std::string &databasePath);		// Parameterized constructor
		BitcoinExchange(const BitcoinExchange &other);			// Copy constructor
		BitcoinExchange &operator=(const BitcoinExchange &rhs);	// Copy assignment operator
		~BitcoinExchange(void);									// Destructor

	public:

	private:
		bool is_valid_date(const std::string &dateStr);
};

#endif