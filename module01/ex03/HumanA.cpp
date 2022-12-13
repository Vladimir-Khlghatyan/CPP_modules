#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : m_name(name), m_weapon(weapon) {}

HumanA::~HumanA()
{

}

void	HumanA::attack(void) const
{
	if (this->m_weapon.getType()!= "")
	{
		std::cout << YELLOW << m_name << WHITE << " attacks with their ";
		std::cout << PINK << m_weapon.getType() << RESET << std::endl;
	}
	else
	{
		std::cout << YELLOW << m_name << RED << " doesn't have a weapon to attack.";
		std::cout << RESET << std::endl;
	}
}
