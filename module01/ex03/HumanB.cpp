#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->m_name = name;
	this->m_weapon = NULL;
}

HumanB::~HumanB()
{

}

void	HumanB::attack(void) const
{
	if (this->m_weapon != NULL and this->m_weapon->getType()!= "")
	{
		std::cout << YELLOW << m_name << WHITE << " attacks with their ";
		std::cout << PINK << m_weapon->getType() << RESET << std::endl;
	}
	else
	{
		std::cout << YELLOW << m_name << RED << " doesn't have a weapon to attack.";
		std::cout << RESET << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->m_weapon= &weapon;
}
