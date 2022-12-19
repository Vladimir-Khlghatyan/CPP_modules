#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Robert");
	ClapTrap b("Serj");
	ClapTrap c(a);
	
	b = a;	
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

	b.takeDamage(3);
	b.showAttributes();
	
	return (0);
}