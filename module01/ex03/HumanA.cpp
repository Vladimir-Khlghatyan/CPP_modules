#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string name, Weapon& weapon) :m_name(name), m_weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) const
{
	std::cout << BLUE << m_name << RESET << " attacks with their ";
	std::cout << RED << m_weapon.getType() << RESET << std::endl;
}
