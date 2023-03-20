#include "BitcoinExchange.hpp"

int errorMsg1(void);
int errorMsg2(void);
bool isFloat(const std::string &str);
int stringToInt(const std::string &str);

int	main(int ac, char **av)
{
	// if (ac != 3)
	// 	return errorMsg1();

	// std::ifstream file;	
	// file.open(av[1]);

	// if (!file.is_open())
	// 	return errorMsg2();

	// BitcoinExchange btc(file);
	// file.close();

	std::string str = av[ac - 1];
	std::cout << isFloat(str) << std::endl;
	std::cout << stringToInt(str) << std::endl;

	return 0;
}

int	errorMsg1(void)
{
	std::cout << RED << "Error: 2 arguments required => ";
	std::cout << YELLOW << "exchange rates file and price/dates file.";
	std::cout << RESET << std::endl;
	return 1;
}

int	errorMsg2(void)
{
	std::cout << RED << "Error: could not open file.";
	std::cout << RESET << std::endl;
	return 2;
}

bool isFloat(const std::string &str) {
    char* endptr;
    float val = strtof(str.c_str(), &endptr);
    if (*endptr != '\0') {
        return false;  // Input is not a valid float
    }
	std::cout << "val: " << val << std::endl;
	std::cout << "HUGE_VALF: " << HUGE_VALF << std::endl;
	return (val > -HUGE_VALF && val < HUGE_VALF);
}

int stringToInt(const std::string& str) {
    int result;
    std::stringstream ss(str);
    ss >> result;

    if (ss.fail() || !ss.eof()) {
        std::cout << "not valid int" << std::endl;
    }

    if (result > INT_MAX || result < INT_MIN) {
        std::cout << "int overflow" << std::endl;
    }

    return result;
}
