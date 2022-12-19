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
	std::cout << YELLOW << "Copy constructor called (another " << PINK << _name << GREEN << " created" << YELLOW << ").";
	std::cout << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << BLUE << "Copy assignment operator called (" << PINK << _name << BLUE << " changed his name to ";
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
	std::string MESSAGE = "empty";

	if (_hit_points == 0 and _energy_points != 0)
		MESSAGE = "because it has no health!";
	else if (_hit_points != 0 and _energy_points == 0)
		MESSAGE = "because it has no energy!";
	else if (_hit_points == 0 and _energy_points == 0)
		MESSAGE = "because it has no health and energy!";
	if (_hit_points == 0 or _energy_points == 0)
	{
		std::cout << WHITE << "ClapTrap " << PINK << _name << RED << " cannot attack, " << WHITE << MESSAGE;
		std::cout << RESET << std::endl;
		return ;	
	}
	std::cout << WHITE << "ClapTrap " << PINK << _name << WHITE << " attacks ";
	std::cout << YELLOW << target << WHITE << ", causing " << RED << _attack_damage << WHITE << " points of damage!";
	std::cout << RESET << std::endl;
	_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= amount)
	{
		_hit_points = 0;
		std::cout << WHITE << "ClapTrap " << PINK << _name << RED << " was killed " << WHITE << "(hit points = " << RED << 0 << WHITE << ")";
		std::cout << RESET << std::endl;
		return ;
	}
	_hit_points -= amount;
	std::cout << WHITE << "ClapTrap " << PINK << _name << RED << " was damaged ";
	std::cout << WHITE << "(it lost " << RED << amount << WHITE << " hit points).";
	std::cout << RESET << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::string	MESSAGE = " was repaired ";

	if (_energy_points == 0)
	{
		std::cout << WHITE << "ClapTrap " << PINK << _name << RED << " cannot repair itself, ";
		std::cout << WHITE << "because it has no energy!";
		std::cout << RESET << std::endl;
		return ;
	}
	if (_hit_points == 0)
		MESSAGE = " rose again ";
	_hit_points += amount;
	_energy_points--;
	std::cout << WHITE << "ClapTrap " << PINK << _name << GREEN << MESSAGE;
	std::cout << WHITE << "(it got " << GREEN << amount << WHITE << " hit points).";
	std::cout << RESET << std::endl;
}


void	ClapTrap::showAttributes(void)
{
	std::cout << CYAN << "+----------------------------+" << std::endl;
	std::cout << "| " << PINK << _name << WHITE << " has:";
	std::cout << CYAN << std::setw(30 - _name.length() - 7) << "|" << std::endl;
	std::cout << CYAN << "| " << std::setw(10) << _hit_points << WHITE << " hit points" << CYAN << "      |" << std::endl;
	std::cout << CYAN << "| " << std::setw(10) << _energy_points << WHITE << " energy points" << CYAN << "   |" << std::endl;
	std::cout << CYAN << "| " << std::setw(10) << _attack_damage << WHITE << " attack damage" << CYAN << "   |" << std::endl;
	std::cout << CYAN << "+----------------------------+" << RESET << std::endl;
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	_hit_points = amount;
	std::cout << PINK << _name << "'s " << WHITE << "hit points were set to " << GREEN << amount << std::endl;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	_energy_points = amount;
	std::cout << PINK << _name << "'s " << WHITE << "energy points were set to " << GREEN << amount << std::endl;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	_attack_damage = amount;
	std::cout << PINK << _name << "'s " << WHITE << "attack damage was set to " << GREEN << amount << std::endl;
}
