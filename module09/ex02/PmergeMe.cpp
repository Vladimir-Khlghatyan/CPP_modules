#include "PmergeMe.hpp"

// ==== constructors ========================================================
PmergeMe::PmergeMe(const std::string &numbers)
{
	std::string non_const_numbers = numbers;
	try {
		this->fillDataBases(non_const_numbers);
	} catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	int i = 0;
	_vector.reserve(other._vector.size());
	for (std::list<int>::const_iterator it = other._list.begin(); it != other._list.end(); ++it)
	{
		_list.push_back(*it);
		_vector.push_back(other._vector[i++]);
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		int i = 0;
		_vector.clear();
		_list.clear();
		_vector.reserve(rhs._vector.size());
		for (std::list<int>::const_iterator it = rhs._list.begin(); it != rhs._list.end(); ++it)
		{
			_list.push_back(*it);
			_vector.push_back(rhs._vector[i++]);
		}		
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}


// ==== member functions =====================================================

void	PmergeMe::printVector(void) const
{
	if (_vector.empty() == true)
		return ;
	std::vector<int>::const_iterator it = _vector.begin();
	std::cout << *it;
	it++;
	for (; it != _vector.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void	PmergeMe::printList(void) const
{
	if (_list.empty() == true)
		return ;
	std::list<int>::const_iterator it = _list.begin();
	std::cout << *it;
	it++;
	for (; it != _list.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void	PmergeMe::fillDataBases(std::string &numbers)
{
	long long	num;
	
	size_t notAllowedCharPosition = numbers.find_first_not_of(" +0123456789"); // number must be a positive integer
	if (notAllowedCharPosition != std::string::npos)
		throw std::runtime_error("Error: invalid argument(s).");
	else
	{
		size_t spacePosition = numbers.find(' ');
		while (true)
		{
			std::stringstream ss(numbers.substr(0, spacePosition));
			ss >> num;
			if (num == 0 || num > INT_MAX) // number must be a positive integer
			{
				_vector.clear();
				_list.clear();
				throw std::runtime_error("Error: invalid argument(s).");
				return;
			}
			_list.push_back(static_cast<int>(num));
			_vector.push_back(static_cast<int>(num));
			numbers = numbers.substr(spacePosition + 1);
			if (spacePosition == std::string::npos)
				break ;
			spacePosition = numbers.find(' ');
		}
	}
}
