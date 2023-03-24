#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::string numbers;
	struct timeval tv;

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

	// print numbers before sorting
	std::cout << PINK << "Before [std::vecotr]: ";
	pmm.vectorPrint(10);
	std::cout << PINK << "Before [std::list]  : ";
	pmm.listPrint(10);
	// pmm.vectorCheckIfSorted();
	// pmm.listCheckIfSorted();


    // sorting numbers with std::vector
	gettimeofday(&tv, NULL);
    long long vectorStartTime = tv.tv_sec * 1000000LL + tv.tv_usec;
	pmm.vectorMergeInsertionSort(0, pmm.getVectorSize() - 1);
	gettimeofday(&tv, NULL);
    long long vectorEndTime = tv.tv_sec * 1000000LL + tv.tv_usec;

	// sorting numbers with std::list
	gettimeofday(&tv, NULL);
    long long listStartTime = tv.tv_sec * 1000000LL + tv.tv_usec;
	pmm.listMergeInsertionSort(0, pmm.getListSize() - 1);
	gettimeofday(&tv, NULL);
    long long listEndTime = tv.tv_sec * 1000000LL + tv.tv_usec;

	// print numbers after sorting
	std::cout << BLUE << "After  [std::vecotr]: ";
	pmm.vectorPrint(10);
	std::cout << BLUE << "After  [std::list]  : ";
	pmm.listPrint(10);
	// pmm.vectorCheckIfSorted();
	// pmm.listCheckIfSorted();

	// print messager about sorting duration with std::vector
	std::cout << GREEN << "Time to process a range of " << pmm.getVectorSize();
	std::cout << " elements with std::vector : ";
	std::cout << YELLOW << std::fixed << std::setw(8) << std::setprecision(3);
	std::cout << (vectorEndTime - vectorStartTime) / 1000.0;
	std::cout << " milliseconds" << RESET << std::endl;

	// print messager about sorting duration with std::list
	std::cout << GREEN << "Time to process a range of " << pmm.getListSize();
	std::cout << " elements with std::list   : ";
	std::cout << YELLOW << std::fixed << std::setw(8) << std::setprecision(3);
	std::cout << (listEndTime - listStartTime) / 1000.0;
	std::cout << " milliseconds" << RESET << std::endl;

	return 0;
}

// For linux:
// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./PmergeMe $ARG

// For OSX:
// ./PmergeMe `jot -r 3000 1 1000 | tr '\n' ' '`
// ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./PmergeMe $ARG
