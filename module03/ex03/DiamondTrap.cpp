#include "DiamondTrap.hpp"

//==== constructors =====================================================================

DiamondTrap::DiamondTrap(void)
{
	this->_name = "Unnamed";
	std::cout << PINK << _name << " " + this->getClassName() + " ";
	std::cout << GREEN << "created." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : \
	ClapTrap(name + "_clap_name"), \
	FragTrap(name + "_clap_name"), \
	ScavTrap(name + "_clap_name")
{
	// this->ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	std::cout << this->getClassName() << WHITE << " named " << PINK << _name;
	std::cout << GREEN << " created." << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : \
	ClapTrap(other), \
	FragTrap(other), \
	ScavTrap(other)
{
	this->_name = other._name;
	std::cout << YELLOW << "Copy constructor of " << this->getClassName();
	std::cout << YELLOW << " called (another " << PINK << _name;
	std::cout << GREEN << " created" << YELLOW << ").";
	std::cout << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << BLUE << "Copy assignment operator of " << this->getClassName();
	std::cout << BLUE << " called (" << PINK << _name << BLUE << " changed his name to ";
	std::cout << PINK << other._name << BLUE << ")." << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	if (_name.compare("Unnamed") == 0)
	{
		std::cout << PINK << _name << " " + this->getClassName();
		std::cout << RED << " destroyed" << RESET << std::endl;
	}
	else
	{
		std::cout << this->getClassName() + " " << PINK << _name;
		std::cout << RED << " destroyed" << RESET << std::endl;
	}
}

//==== member functions by subject ======================================================

void	DiamondTrap::whoAmI(void)
{
	std::cout << WHITE << "My name is " << PINK << this->_name;
	std::cout << WHITE << " and I am an object of the " << this->getClassName() << " class. ";
	std::cout << "My parent ClapTrap's name is " << PINK << ClapTrap::_name;
	std::cout << RESET << std::endl;

}

//==== member functions by me (for better testing)=======================================

void	DiamondTrap::showAttributes(void)
{
	std::cout << CYAN << "+----------------------------+" << std::endl;
	std::cout << "| " << PINK << _name << WHITE << " has:";
	std::cout << CYAN << std::setw(30 - _name.length() - 7) << "|" << std::endl;
	std::cout << CYAN << "| " << std::setw(10) << _hit_points;
	std::cout << WHITE << " hit points" << CYAN << "      |" << std::endl;
	std::cout << CYAN << "| " << std::setw(10) << _energy_points;
	std::cout << WHITE << " energy points" << CYAN << "   |" << std::endl;
	std::cout << CYAN << "| " << std::setw(10) << _attack_damage;
	std::cout << WHITE << " attack damage" << CYAN << "   |" << std::endl;
	std::cout << CYAN << "+----------------------------+" << RESET << std::endl;
}

std::string	DiamondTrap::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	s = WHITE + s + RESET;
	return (s);
}
