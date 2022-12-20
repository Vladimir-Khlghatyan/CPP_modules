#include "FragTrap.hpp"

//==== constructors =====================================================================

FragTrap::FragTrap(void)
{
	this->_name = "Unnamed";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << PINK << _name << " " + this->getClassName() + " ";
	std::cout << GREEN << "created." << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name)// : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << this->getClassName() << WHITE << " named " << PINK << _name;
	std::cout << GREEN << " created." << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	std::cout << YELLOW << "Copy constructor of " << this->getClassName();
	std::cout << YELLOW << " called (another " << PINK << _name;
	std::cout << GREEN << " created" << YELLOW << ").";
	std::cout << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << BLUE << "Copy assignment operator of " << this->getClassName();
	std::cout << BLUE << " called (" << PINK << _name << BLUE << " changed his name to ";
	std::cout << PINK << other._name << BLUE << ")." << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
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

void	FragTrap::attack(const std::string& target)
{
	std::string MESSAGE = "empty";

	if (_hit_points == 0 and _energy_points != 0)
		MESSAGE = "because it has no health!";
	else if (_hit_points != 0 and _energy_points == 0)
		MESSAGE = "because it has no energy!";
	else if (_hit_points == 0 and _energy_points == 0)
		MESSAGE = "because it has no health and energy!";
	if (_hit_points == 0 or _energy_points == 0)
	{
		std::cout << this->getClassName() + " " << PINK << _name;
		std::cout << RED << " cannot attack, " << WHITE << MESSAGE;
		std::cout << RESET << std::endl;
		return ;	
	}
	std::cout << this->getClassName() + " " << PINK << _name << WHITE << " attacks ";
	std::cout << YELLOW << target << WHITE << ", causing ";
	std::cout << RED << _attack_damage << WHITE << " points of damage!";
	std::cout << RESET << std::endl;
	_energy_points--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << PINK << _name;
	std::cout << WHITE << " gives everyone high fives." << RESET << std::endl;
}

//==== member functions by me (for better testing)=======================================

std::string	FragTrap::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	s = WHITE + s + RESET;
	return (s);
}
