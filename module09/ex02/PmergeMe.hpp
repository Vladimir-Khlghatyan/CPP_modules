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
# include <climits>

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

	public:
		 PmergeMe(const std::string &numbers);			// Parameterized constructor
		 PmergeMe(const  PmergeMe &other);			// Copy constructor
		 PmergeMe &operator=(const  PmergeMe &rhs);	// Copy assignment operator
		~ PmergeMe(void);							// Destructor

	public:
		void	printVector(void) const;
		void	printList(void) const;

	private:
		void	fillDataBases(std::string &numbers);
};

#endif