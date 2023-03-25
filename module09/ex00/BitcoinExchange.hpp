#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <string>
# include <algorithm>
# include <iomanip>
# include <numeric>

# include <cmath>
# include <ctime>
# include <cstdlib>
# include <climits>

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
		std::map<unsigned int, float> _database;

	public:
		BitcoinExchange(std::ifstream &databaseFile);			// Parameterized constructor
		BitcoinExchange(const BitcoinExchange &other);			// Copy constructor
		BitcoinExchange &operator=(const BitcoinExchange &rhs);	// Copy assignment operator
		~BitcoinExchange(void);									// Destructor

	public:
		void	display_values_multiplied_by_the_exchange_rates(std::ifstream &priceFile);

	private:
		unsigned int 					is_valid_date(const std::string &dateStr);
		std::pair<std::string, float>	is_valid_number(const std::string &numStr);
		unsigned int 					date_to_days_since_era(int year, int month, int day);
		void    						strTrim(std::string &str);
};

#endif
