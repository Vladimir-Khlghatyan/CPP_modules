#include "PhoneBook.hpp"

const std::string ft_show_promt(int i)
{
    if (i == 0)
        return ("First name > ");
    if (i == 1)
        return ("Last name > ");
    if (i == 2)
        return ("Nickname > ");
    if (i == 3)
        return ("Phone number > ");
    if (i == 4)
        return ("Darkest secret > ");
    return (NULL);
}

int	ft_input_validation(const std::string &str, int field_idx)
{
	if (str.length() == 0)
	{
		std::cout << RED << "The field can't be empty!" << RESET << std::endl;
		return (0);
	}
	else if (field_idx == 0 or field_idx == 1)
	{
		for (unsigned int i = 0; i < str.length(); i++)
			if (!isalpha(str[i]) and str[i] != '-')
			{
				std::cout << RED << " Use only [A-Z], [a-z] or '-'!" << RESET << std::endl;
				return (0);
			}
	}
	else if (field_idx == 2 or field_idx == 4)
	{
		for (unsigned int i = 0; i < str.length(); i++)
			if (!isalnum(str[i]) and str[i] != '_')
			{
				std::cout << RED << " Use only [A-Z], [a-z], [0-9] or '_'!" << RESET << std::endl;
				return (0);
			}
	}
	else if (field_idx == 3)
	{
		for (unsigned int i = 0; i < str.length(); i++)
		{
			if (str[i] == '+' and i != 0)
			{
				std::cout << RED << "The '+' sign should only be at the beginning!" << RESET << std::endl;
				return (0);
			}
			if (!isdigit(str[i]) and str[i] != '+')
			{
				std::cout << RED << " Use only [0-9] or '+'!" << RESET << std::endl;
				return (0);
			}
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
			std::cout << YELLOW << ft_show_promt(i) << WHITE;
			std::getline(std::cin, fields[i]);
			std::cout << RESET;
			if (std::cin.fail())
			{
				std::cout << RED << "\nBad inputs! Please relaunch PhoneBook!" << RESET << std::endl;
				exit(1);
			}
			if (ft_input_validation(fields[i], i))
				break ;
		}
	}
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	std::string	fields[5];
	int			index;

	while (true)
	{
		std::cout << GREEN << "Please insert " << PINK << "ADD";
		std::cout << GREEN << ", " << PINK << "SEARCH";
		std::cout << GREEN << " or " << PINK << "EXIT" << std::endl;
		std::cout << GREEN << "> " << WHITE;
		std::getline(std::cin, command);
		std::cout << RESET;
		if (std::cin.eof())
		{
			std::cout << RED << "\nBad inputs! Please relaunch PhoneBook!" << RESET << std::endl;
			return (1);
		}
		if (command == "ADD")
		{
			std::cout << GREEN << "Enter new contact ⬇" << RESET << std::endl;
			get_and_check_fields(fields);
			phonebook.set_contact(fields);
			std::cout << GREEN << " >>> added <<< " << RESET << std::endl;
		}
		if (command == "SEARCH")
		{
			phonebook.print_phonebook();
			while (phonebook.get_size())
			{
				std::cout << GREEN << "Insert index to see contact in detail ⬇" << std::endl;
				std::cout << "> " << WHITE;
				std::cin >> index;
				std::cout << RESET;
				if (std::cin.eof())
				{
					std::cout << RED << "\nBad inputs! Please relaunch PhoneBook!" << RESET << std::endl;
					return (2);
				}
				if (std::cin.fail() or index < 0 or index >= phonebook.get_size())
				{
					std::cout << RED << "No such index in the PhoneBook!" << RESET << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					continue ;
				}
				phonebook.print_contact(index);
				std::cin.ignore(256, '\n');
				break ;
			}
		}
		if (command == "EXIT")
			return(0);
	}
	return (0);
}
