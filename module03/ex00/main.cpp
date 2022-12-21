#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Robert");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	ClapTrap b("Serj");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	ClapTrap c(a);
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	b = a;
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	b.showAttributes();

	b.setEnergyPoints(5);
	b.showAttributes();

	b.attack("Nikol");
	b.showAttributes();

	b.setAttackDamage(2);
	b.showAttributes();

	for (int i = 0; i < 3; i++)
		b.attack("Nikol");
	b.showAttributes();

	for (int i = 0; i < 2; i++)
		b.attack("Nikol");
	b.showAttributes();

	b.setEnergyPoints(3);
	b.takeDamage(11);
	b.showAttributes();
	b.attack("Nikol");
	
	b.beRepaired(5);
	b.showAttributes();

	b.beRepaired(5);
	b.showAttributes();

	b.setEnergyPoints(0);
	b.beRepaired(1);
	b.showAttributes();

	b.takeDamage(3);
	b.showAttributes();
	
	return (0);
}