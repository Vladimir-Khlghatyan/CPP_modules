#include "PhoneBook.hpp"

int	main(int ac, char **av)
{
	PhoneBook	phonebook;
	std::string	command;
	std::string	fields[5];
	int			index;

	while (1)
	{
		std::cout << PINK;
		std::cout << "Please insert one of these 3 commands: ADD SEARCH EXIT" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, command);
		std::cout << RESET;
		if (command == "ADD")
		{
			std::cout << CYAN << "Enter new contact > "
			// get_and_check_command
			phonebook.set_contact(fields);
		}
	}
}
