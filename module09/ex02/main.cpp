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

	PmergeMe pmm;
	
	try {
		pmm = PmergeMe(numbers);
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
		return 1;
	}
	

	// std::cout << "\nAFTER SORTING\n";
	// pmm.vectorPrint(10);
	// pmm.vectorCheckIfSorted();
	// pmm.listPrint();
	pmm.listPrint(10);
	// pmm.listCheckIfSorted();

	// pmm.vectorMergeInsertionSort(0, pmm.getVectorSize() - 1);
	// pmm.listMergeInsertionSort(0, pmm.getListSize() - 1);

	// std::cout << "\nBEFORE SORTING\n";
	// pmm.vectorPrint();
	// pmm.vectorCheckIfSorted();
	// pmm.listPrint();
	// pmm.listCheckIfSorted();

	return 0;
}

// ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./PmergeMe $ARG
// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
