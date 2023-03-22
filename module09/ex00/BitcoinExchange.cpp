#include "BitcoinExchange.hpp"

// ==== constructors ========================================================
BitcoinExchange::BitcoinExchange(std::ifstream &databaseFile)
{
	std::string line, date, rate;
	size_t 		commaPos;

	std::getline(databaseFile, line); // omitting first line
	while (std::getline(databaseFile, line))
	{
		commaPos = line.find(',');
		date = line.substr(0, commaPos);
		if (commaPos != std::string::npos)
			rate = line.substr(commaPos + 1);
		else
			rate = "";
		if (!is_valid_date(date))
		{
			_database.clear();
			std::cout << RED << "[Rates DB] Error: bad input => ";
			std::cout << YELLOW << date;
			std::cout << RESET << std::endl;
			return ;
		}
		if (is_valid_number(rate).first != "ok")
		{
			_database.clear();
			std::cout << RED << "[Rates DB] " << is_valid_number(rate).first << std::endl;
			return ;
		}
		_database[is_valid_date(date)] = is_valid_number(rate).second;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	for (std::map<unsigned int, float>::const_iterator it = other._database.begin(); \
														it != other._database.end(); ++it)
			this->_database[it->first] = it->second;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_database.clear();
		for (std::map<unsigned int, float>::const_iterator it = rhs._database.begin(); \
														it != rhs._database.end(); ++it)
			this->_database[it->first] = it->second;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// ==== member functions =====================================================

void 	BitcoinExchange::display_values_multiplied_by_the_exchange_rates(std::ifstream &priceFile)
{
	if (_database.empty())
		return ;

	std::string	line, date, value;
	size_t 		pipePos, dateInDays;

	std::getline(priceFile, line); // omitting first line
	while (std::getline(priceFile, line))
	{
		pipePos = line.find('|');
		date = line.substr(0, pipePos);
		value = "";
		if (pipePos != std::string::npos)
			value = line.substr(pipePos + 1);
		this->strTrim(date);	
		this->strTrim(value);
		dateInDays = is_valid_date(date);
		if (dateInDays)
		{
			std::map<unsigned int, float>::iterator it = _database.find(dateInDays);
			while (--dateInDays && it == _database.end())
				it = _database.find(dateInDays);
			if (it == _database.end())
				std::cout << RED << "Error: date not found in database => " << YELLOW << date << RESET << std::endl;
			else
			{
				if (is_valid_number(value).first != "ok")
				{
					if (value == "")
					{
						std::cout << is_valid_number(value).first;
						std::cout << YELLOW << line.substr(0, line.length() - 1);
						std::cout << "..." << RESET << std::endl;
					}
					else
						std::cout << is_valid_number(value).first << std::endl;
				}
				else if (is_valid_number(value).second > 1000)
					std::cout << RED << "Error: price is greater than 1000 => " << YELLOW << value << RESET << std::endl;
				else
				{
					std::cout << GREEN << date << " => ";
					std::cout << std::setw(6) << is_valid_number(value).second << " = ";
					std::cout << is_valid_number(value).second * (*it).second << RESET << std::endl;
				}
			}
		}
		else
			std::cout << RED << "Error: bad input => " << YELLOW << date << RESET << std::endl;
	}
}

unsigned int	BitcoinExchange::is_valid_date(const std::string &dateStr)
{
	//A valid date will always be in the following format: yyyy-mm-dd
	if (dateStr.length() != 10)
		return 0;
	size_t notAllowedSymbolPosition = dateStr.find_first_not_of("-0123456789");
	if (notAllowedSymbolPosition != std::string::npos)
        return 0;
	if (dateStr[4] != '-' || dateStr[7] != '-')
		return 0;

	std::string yearStr = dateStr.substr(0, 4);
	std::string monthStr = dateStr.substr(5, 2);
	std::string dayStr = dateStr.substr(8, 2);

	std::istringstream yearIss(yearStr);
	int year;
	yearIss >> year;

	std::istringstream monthIss(monthStr);
	int month;
	monthIss >> month;

	std::istringstream dayIss(dayStr);
	int day;
	dayIss >> day;

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return 0;

	// In the Julian calendar (untill 1582), a leap year occurs every 4 years.
	// Under the Gregorian calendar (was introduced by Pope Gregory XIII in 1582),
	// a year is a leap year if it is divisible by 4, 
	// but not divisible by 100, unless it is also divisible by 400.
	// 1700, 1800 and 1900 were not leap years, but 1600 and 2000 were leap years.
	
	int daysInMonth;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;
	else if (month == 2 && year < 1582)
	{
		if (year % 4 == 0)
			daysInMonth = 29;
		else
			daysInMonth = 28;
	}
	else if (month == 2 && year >= 1582)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			daysInMonth = 29;
		else
			daysInMonth = 28;
	}
	else
		daysInMonth = 31;

	if (day > daysInMonth)
		return 0;
	return date_to_days_since_era(year, month, day);
}

std::pair<std::string, float>	BitcoinExchange::is_valid_number(const std::string &numStr)
{
	std::string msg;
	
	if (numStr == "" || numStr == "-" || numStr == "+")
		return std::make_pair("\33[1;31mError: missing value => \33[0;m", 0.0);

	// checking if "numStr" represents an integer
	size_t notNumPos = numStr.find_first_not_of("0123456789");
	if (numStr[0] == '-' || numStr[0] == '+')
		notNumPos = numStr.substr(1).find_first_not_of("0123456789");
	if (notNumPos == std::string::npos) 
	{
		long long	num;
		std::stringstream ss(numStr);
		ss >> num;
	    if (num < INT_MIN)
		{
			msg = RED;
			msg += "Error: too small a number => ";
			msg += YELLOW;
			msg += numStr + RESET;
			return std::make_pair(msg, 0.0);
		}
		if (num < 0)
		{
        	msg = RED;
			msg += "Error: not a positive number? => ";
			msg += YELLOW;
			msg += numStr + RESET;
			return std::make_pair(msg, 0.0);
		}
		if (num > INT_MAX)
		{
			msg = RED;
			msg += "Error: too large a number => ";
			msg += YELLOW;
			msg += numStr + RESET;
			return std::make_pair(msg, 0.0);
		}
		return std::make_pair("ok", static_cast<float>(num));
    }

	// checking if "numStr" represents a float
	char* endptr;
    float value = strtof(numStr.c_str(), &endptr);
    if (*endptr != '\0')
	{
		msg = RED;
		msg += "Error: not valid a number => ";
		msg += YELLOW;
		msg += numStr + RESET;
		return std::make_pair(msg, 0.0);
	}
	if (value == -HUGE_VALF)
	{
		msg = RED;
		msg += "Error: too small a number (-inf) => ";
		msg += YELLOW;
		msg += numStr + RESET;
		return std::make_pair(msg, 0.0);
	}
	if (value < 0)
	{
		msg = RED;
		msg += "Error: not a positive number => ";
		msg += YELLOW;
		msg += numStr + RESET;
		return std::make_pair(msg, 0.0);
	}
	if (value == HUGE_VALF)
	{
		msg = RED;
		msg += "Error: too large a number (inf) => ";
		msg += YELLOW;
		msg += numStr + RESET;
		return std::make_pair(msg, 0.0);
	}
	return std::make_pair("ok", value);
}

unsigned int	BitcoinExchange::date_to_days_since_era(int year, int month, int day)
{
    // Number of days in February, taking into account leap years
	int feb;
	if (year < 1582)
		feb = 28 + (year % 4 == 0);
	else
		feb = 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

	// Number of days in each month
    int months[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Cumulative number of days in each month
    int cumulDays = 0;
    for (int i = 0; i < month - 1; i++)
        cumulDays += months[i];

    // Calculate the number of days since the beginning of the year
    int daysSinceJan1 = cumulDays + day;

    // Calculate the number of leap years since the beginning of the era (January 1, 1 AD)
	unsigned int leapYearsSinceEra = 0;
	for (int i = 1; i < year; ++i)
	{
		if (year < 1582)
			leapYearsSinceEra += (i % 4 == 0);
		else
			leapYearsSinceEra += ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0);
	}

	// Calculate the number of days since the beginning of the era (January 1, 1 AD)
    unsigned int daysSinceEra = leapYearsSinceEra + 365 * (year - 1) + daysSinceJan1;

    return daysSinceEra;
}

void BitcoinExchange::strTrim(std::string &str)
{
    size_t startPosition = str.find_first_not_of(" \f\n\r\t\v");
    if (startPosition != std::string::npos)
        str.erase(0, startPosition);

    size_t endPosition = str.find_last_not_of(" \f\n\r\t\v");
    if (endPosition != std::string::npos)
        str.erase(endPosition + 1);

    if (startPosition == std::string::npos && endPosition == std::string::npos)
        str.clear();
}