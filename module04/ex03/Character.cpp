#include "Character.hpp"

//==== constructors =====================================================================

Character::Character(void)
{
	this->_name = "";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_recycleBin[i] = NULL;
	std::cout << GREEN << "Default constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Character::Character(std::string const &name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_recycleBin[i] = NULL;
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Character::Character(const Character &other)
{
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
		this->_recycleBin[i] = NULL; // It makes no sense to copy the Recycle Bin, so we leave it empty.
	std::cout << GREEN << "Copy constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
		int	i = -1;
		while (this->_recycleBin[++i])
		{
			delete this->_recycleBin[i]; // It makes no sense to back up the recycle bin, so we empty it.
			this->_recycleBin[i] = NULL;
		}
		std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName() <<" class called.";
		std::cout << RESET << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	int i = -1;
	while (this->_recycleBin[++i])
	{
		delete this->_recycleBin[i];
		this->_recycleBin[i] = NULL;
	}
	std::cout << RED << "Destructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

//==== member functions by subject ======================================================

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (m != NULL)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i] == NULL)
			{
				this->_inventory[i] = m;
				std::cout << CYAN << this->getClassName() << " " << _name;
				std::cout << " equipped with " << m->getType() << "." << RESET << std::endl;
				return ;
			}
		}
	}
	std::cout << YELLOW << this->getClassName() << " " << _name;
	std::cout << " cannot equip (no space left or nothing equip)." << RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 and idx < 4 and this->_inventory[idx] != NULL)
	{
		this->pushToRecycleBin(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
		std::cout << CYAN << "Character " << this->_name << " unequipped." << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "Character " << this->_name << " can't unequip." << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 and idx < 4 and this->_inventory[idx] != NULL)
	{
		this->_inventory[idx]->use(target);
        std::cout << CYAN << "Character " << this->_name << " uses ";
        std::cout << this->_inventory[idx]->getType() << "." << RESET << std::endl;
    }
    else
    	std::cout << YELLOW << "Nothing found to use at index." << RESET << std::endl;
}

//==== member functions by me (for better testing)=======================================

std::string	Character::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}

void	Character::pushToRecycleBin(AMateria *inventory)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_recycleBin[i] == NULL)
		{
			this->_recycleBin[i] = inventory;
			return ;
		}
	}
}