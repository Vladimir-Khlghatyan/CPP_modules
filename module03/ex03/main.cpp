#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("Robert");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	DiamondTrap b("Serj");
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	DiamondTrap c(a);
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;
	b = a;
	std::cout << WHITE << "-------------------------------------------------------" << RESET << std::endl;

	b.whoAmI();
	b.guardGate();
	b.highFivesGuys();
	
	b.showAttributes();
	b.attack("Nikol");

	b.setEnergyPoints(5);

	b.attack("Nikol");
	b.showAttributes();

	b.setAttackDamage(21);
	b.showAttributes();

	for (int i = 0; i < 3; i++)
		b.attack("Nikol");
	b.showAttributes();

	for (int i = 0; i < 2; i++)
		b.attack("Nikol");
	b.showAttributes();

	b.setEnergyPoints(3);
	b.takeDamage(101);
	b.showAttributes();
	b.attack("Nikol");
	
	b.beRepaired(5);
	b.showAttributes();

	b.beRepaired(5);
	b.showAttributes();

	b.takeDamage(3);
	b.showAttributes();
	return (0);
}