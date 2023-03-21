#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::string numbers;

	for (int i = 1; i < ac; ++i)
	{
		numbers += av[i];
		if (i != ac - 1)
			numbers += " ";
	}	

	PmergeMe pmm(numbers);

	pmm.printVector();
	pmm.printList();
	return 0;
}