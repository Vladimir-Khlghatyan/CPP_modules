#ifndef  PMERGEME_HPP
# define  PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <list>
# include <stdexcept>
# include <sstream>
# include <string>
# include <algorithm>
# include <iterator>
# include <climits>
# include <ctime>
# include <sys/time.h>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class  PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		int		 			_vectorThreshold;
		int 				_listThreshold;

	public:
		PmergeMe(void);								// Default constructor
		PmergeMe(const std::string &numbers);		// Parameterized constructor
		PmergeMe(const  PmergeMe &other);			// Copy constructor
		PmergeMe &operator=(const  PmergeMe &rhs);	// Copy assignment operator
		~ PmergeMe(void);							// Destructor

	public:
		void	vectorPrint(unsigned int printCount) const;
		void	vectorMergeInsertionSort(int start, int end);
		void	vectorCheckIfSorted(void);

		void	listPrint(unsigned int printCount) const;
		void	listMergeInsertionSort(int start, int end); // add implementation
		void	listCheckIfSorted(void);

		int		getVectorSize() const;
		int		getListSize() const;

	private:
		void	fillDataBases(std::string &numbers);

		void 	listInsertionSort(int start, int end);
		void 	listMerge(int start, int end); // add implementation

		void 	vectorInsertionSort(int start, int end);
		void 	vectorMerge(int start, int end);

};

#endif

// https://iq.opengenus.org/merge-insertion-sort/
