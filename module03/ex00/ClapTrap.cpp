#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "Unnamed";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << PINK << _name << WHITE << " ClapTrap " << GREEN << "created." << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;	
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	if (_name.compare("Unnamed") == 0)
		std::cout << PINK << _name << WHITE << " ClapTrap " << RED << "destroyed" << RESET << std::endl;
	else
		std::cout << WHITE << "ClapTrap " << PINK << _name << RED << " destroyed" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << WHITE "ClapTrap named " << PINK << _name << WHITE << GREEN << " created." << RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << WHITE << "ClapTrap " << PINK << _name << WHITE << " attacks ";
	std::cout << YELLOW << target << WHITE << ", causing " << RED << _attack_damage << WHITE << " points of damage!";
	std::cout << RESET << std::endl;
}

// void	ClapTrap::takeDamage(unsigned int amount)
// {

// }

// void	ClapTrap::beRepaired(unsigned int amount)
// {

// }
