#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cout << RED << "Please enter the number and names of the zombies (argv[1] and argv[2])!" << RESET << std::endl;
		return (0);
	}
	Zombie	*Horde = zombieHorde(atoi(av[1]), av[2]);
	for (int i = 0; i < atoi(av[1]) ; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}
