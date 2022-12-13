#include "HumanB.hpp"

HumanB::HumanB()
{
	m_weapon = NULL;
}

HumanB::HumanB(std:string name)
{
	m_name = name;
	m_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack(void) const
{
	std::cout << BLUE << m_name << RESET << " attacks with their ";
	std::cout << RED << m_weapon->get_type() << RESET << std::endl;
}