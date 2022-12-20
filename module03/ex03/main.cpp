#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("Karen");
	std::cout << "---------------------" << std::endl;
	DiamondTrap b(a);
	std::cout << "---------------------" << std::endl;
	return (0);
}