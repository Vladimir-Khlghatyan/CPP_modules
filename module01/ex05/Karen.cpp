#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void	Karen::debug(void)
{
	std::cout << BLUE << "I love having extra bacon for my 7XL-double-";
	std::cout << "cheese-triple-pickle-specialketchup burger.\nI really do!";
	std::cout << RESET << std::endl;
}

void	Karen::info(void)
{
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t ";
	std::cout << "put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!";
	std::cout << RESET << std::endl;
}

void	Karen::warning(void)
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free.\nI’ve been coming ";
	std::cout << "for years whereas you started working here since last month.";
	std::cout << RESET << std::endl;
}

void	Karen::error(void)
{
	std::cout << RED << "This is unacceptable!\nI want to speak to the manager now.";
	std::cout << RESET << std::endl;
}

void	Karen::complain(std::string level)
{
	void (Karen::*ptr_member_func[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
    while (i <=4 && levels[i].compare(level))
    {
        i++;
        while (i == 4)
        	return ;
    }
	(this->*ptr_member_func[i])();	
}
