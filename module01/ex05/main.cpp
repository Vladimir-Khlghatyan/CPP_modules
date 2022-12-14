#include "Karen.hpp"

int	main(void)
{
	Karen		karen;
	std::string	command;

	while (true)
	{
		std::cout << CYAN << "Please insert " << PINK << "DEBUG";
		std::cout << CYAN << ", " << PINK << "INFO";
		std::cout << CYAN << ", " << PINK << "WARNING";
		std::cout << CYAN << ", " << PINK << "ERROR";
		std::cout << CYAN << " or " << PINK << "exit" << std::endl;
		std::cout << CYAN << "> " << WHITE;
		std::getline(std::cin, command);
		std::cout << RESET;
		if (std::cin.eof())
		{
			std::cout << RED << "\nBad inputs! Please relaunch program!" << RESET << std::endl;
			return (1);
		}
		if (command == "exit")
			return (0);
		karen.complain(command);
	}
	return (0);
}
