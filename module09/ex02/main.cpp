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

	int printCount = 10;
	pmm.vectorPrint(printCount);
	pmm.vectorCheckIfSorted();
	pmm.listPrint(printCount);
	pmm.listCheckIfSorted();

	struct timeval tv;
    gettimeofday(&tv, nullptr);
    long long vectorStartTime = tv.tv_sec * 1000000LL + tv.tv_usec;
	pmm.vectorMergeInsertionSort(0, pmm.getVectorSize() - 1);
	gettimeofday(&tv, nullptr);
    long long vectorEndTime = tv.tv_sec * 1000000LL + tv.tv_usec;
	std::cout << "Time to process a range of " << pmm.getVectorSize();
	std::cout << "elements with std::vector : " << vectorEndTime - vectorStartTime;
	std::cout << " milliseconds" << std::endl;



	pmm.listMergeInsertionSort(0, pmm.getListSize() - 1);

	pmm.vectorPrint(printCount);
	pmm.vectorCheckIfSorted();
	pmm.listPrint(printCount);
	pmm.listCheckIfSorted();


	return 0;
}

// ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./PmergeMe $ARG
// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
