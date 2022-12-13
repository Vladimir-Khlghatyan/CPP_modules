#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	m_name = name;
	std::cout << RESET << "Zombie named " << YELLOW << m_name << GREEN << " created." << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RESET << "Zombie named " << YELLOW << m_name << RED << " destroyed." << RESET << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << YELLOW << m_name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
