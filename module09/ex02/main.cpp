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

	pmm.vectorPrint();
	// pmm.listPrint();

	pmm.vectorMergeInsertionSort(0, ac - 2);
	// pmm.listMergeInsertionSort(0, ac - 2);

	pmm.vectorPrint();
	// pmm.listPrint();
	return 0;
}

// ./PmergeMe 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70
