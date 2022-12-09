#include "PhoneBook.hpp"

const std::string ft_show_promt(int i)
{
    if (i == 0)
        return ("First name ([A-Z], [a-z], '-') > ");
    if (i == 1)
        return ("Last name ([A-Z], [a-z], '-') > ");
    if (i == 2)
        return ("Nickname ([A-Z], [a-z], [0-9], '_') > ");
    if (i == 3)
        return ("Phone name ([0-9], '+') > ");
    if (i == 4)
        return ("Darkest secret ([A-Z], [a-z], [0-9], '_') > ");
    return (NULL);
}

int	ft_input_validation(const std::string &str, int field_idx)
{
	if (str.length() == 0)
	{
		std::cout << RED << "The field can't be empty!\n";
		std::cout << RESET;
		return (0);
	}
	else if (field_idx == 0 or field_idx == 1)
	{
		for (unsigned int i = 0; i < str.length(); i++)
			if (!((str[i] >= 'A' and str[i] <= 'Z') or \
				  (str[i] >= 'a' and str[i] <= 'z') or \
				   str[i] == '-'))
			{
				std::cout << RED << "Only characters [A-Z], [a-z] and '-' are available!\n";
				std::cout << RESET;
				return (0);
			}
	}
	else if (field_idx == 2 or field_idx == 4)
	{
		for (unsigned int i = 0; i < str.length(); i++)
			if (!((str[i] >= 'A' and str[i] <= 'Z') or \
				  (str[i] >= 'a' and str[i] <= 'z') or \
				  (str[i] >= '0' and str[i] <= '9') or \
				   str[i] == '_'))
			{
				std::cout << RED << "Only characters [A-Z], [a-z], [0-9] and '_' are available!\n";
				std::cout << RESET;
				return (0);
			}
	}
	else if (field_idx == 3)
	{
		for (unsigned int i = 0; i < str.length(); i++)
			if (!((str[i] >= '0' and str[i] <= '9') or \
				   str[i] == '+'))
			{
				std::cout << RED << "Only characters [0-9] and '+' are available!\n";
				std::cout << RESET;
				return (0);
			}
	}
	return (1);
}

void	get_and_check_fields(std::string *fields)
{	
	for (int i = 0; i < 5; i++)
	{
		while (true)
		{
			std::cout << GREEN << ft_show_promt(i);
			std::getline(std::cin, fields[i]);
			std::cout << RESET;
			if (std::cin.fail())
			{
				std::cout << RED << "Bad inputs! Please relanch Phonebook!" << RESET << std::endl;
				exit(1);
			}
			if (ft_input_validation(fields[i], i))
				break ;
		}
	}
}

int	main(int ac, char **av)
{
	PhoneBook	phonebook;
	std::string	command;
	std::string	fields[5];
	int			index;

	(void)ac;
	(void)**av;
	(void)index;
	while (1)
	{
		std::cout << PINK;
		std::cout << "Please insert one of these 3 commands: ADD SEARCH EXIT" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, command);
		std::cout << RESET;
		if (command == "ADD")
		{
			std::cout << CYAN << "Enter new contact > " << RESET;
			get_and_check_fields(fields);
			phonebook.set_contact(fields);
		}
	}
}