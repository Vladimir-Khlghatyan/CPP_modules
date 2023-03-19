#include "BitcoinExchange.hpp"

// ==== constructors ========================================================
BitcoinExchange::BitcoinExchange(const std::string &databasePath)
{
	(void)&databasePath; //tmp
	// write code here
	std::cout << " " << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)&other; //tmp
	// write code here
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		// write code here
	}
	
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// write code here
}


// ==== member functions =====================================================

bool	BitcoinExchange::is_valid_date(const std::string &dateStr)
{
	//A valid date will always be in the following format: yyyy-mm-dd
	if (dateStr.length() != 10)
		return false;
	size_t notAllowedSymbolPosition = dateStr.find_first_not_of("-0123456789");
	if (notAllowedSymbolPosition != std::string::npos)
        return false;
	if (dateStr[4] != '-' || dateStr[7] != '-')
		return false;

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
		return false;

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
		return false;
	std::cout << year << " " << month << " " << day << std::endl;
	return true;
}