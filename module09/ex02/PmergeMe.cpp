#include "PmergeMe.hpp"

// ==== constructors ========================================================
PmergeMe::PmergeMe(const std::string &numbers) : _vectorThreshold(10), _listThreshold(10)
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
	_vectorThreshold = other._vectorThreshold;
	_listThreshold = other._listThreshold;
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
		_vectorThreshold = rhs._vectorThreshold;
		_listThreshold = rhs._listThreshold;
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

// ==== member functions (vector part) =======================================

void	PmergeMe::vectorPrint(void) const
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

void 	PmergeMe::vectorInsertionSort(int start, int end)
{
	int	i, j, tmp;
	for (i = start + 1; i <= end; ++i)
	{
		tmp = _vector[i];
		j = i;
		while (j > start && _vector[j - 1] > tmp)
		{
			_vector[j] = _vector[j - 1];
			--j;
		}
		_vector[j] = tmp;
	}
}

void PmergeMe::vectorMerge(int start, int end)
{
    int 				mid = (start + end) / 2;
    int 				i = start;
    int 				j = mid + 1;
    int 				k = 0;
    std::vector<int>    tmpVec(end - start + 1);

    while (i <= mid && j <= end)
    {
        if (_vector[i] < _vector[j])
			tmpVec[k++] = _vector[i++];
        else
			tmpVec[k++] = _vector[j++];
    }

    while (i <= mid)
		tmpVec[k++] = _vector[i++];

    while (j <= end)
		tmpVec[k++] = _vector[j++];

    for (int i = 0; i < k; i++)
        _vector[start + i] = tmpVec[i];
}

void	PmergeMe::vectorMergeInsertionSort(int start, int end)
{
    if (end - start < _vectorThreshold)
	{
		vectorInsertionSort(start, end);
		return;
    }

    vectorMergeInsertionSort(start, (start + end) / 2);
    vectorMergeInsertionSort((start + end) / 2 + 1, end);
    vectorMerge(start, end);
}

void	PmergeMe::vectorCheckIfSorted(void)
{
	if (_vector.empty() == true)
	{
		std::cout << PINK << "Vector is empty." << RESET << std::endl;
		return ;
	}
	std::vector<int>::const_iterator itTmp;
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		itTmp = it;
		std::advance(itTmp, 1);
		if (itTmp != _vector.end())
		{
			if (*it > *itTmp)
			{
				std::cout << PINK << "Vector is not sorted." << RESET << std::endl;
				return ;
			}
		}
	}
	std::cout << PINK << "Vector is sorted." << RESET << std::endl;
}

int	PmergeMe::getVectorSize() const
{
	return _vector.size();
}

// ==== member functions (list part) =========================================

void	PmergeMe::listPrint(void) const
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

void 	PmergeMe::listInsertionSort(int start, int end)
{
  std::list<int>::iterator itStart, it, jt, tt;
  int i, tmp;

  itStart = it = _list.begin();
  std::advance(itStart, start); // advance "itStart" by "start" count position forward
  std::advance(it, start + 1); // advance "it" by "start + 1" count position forward

  for (i = start + 1; i <= end; ++i)
  {
	tmp = *it;
	jt = it;
	while (jt != itStart  && *(--jt) > tmp)
	{
		tt = jt;
		++jt;
		*jt = *tt;
		--jt;
	}
	*jt = tmp;
	++it;
  }
}

void PmergeMe::listMerge(int start, int end)
{
    std::list<int>::iterator midIt = _list.begin();
    std::advance(midIt, (start + end) / 2); // advance "midIt" by "(start + end) / 2" count position forward

    std::list<int>::iterator leftIt = _list.begin();
    std::advance(leftIt, start); // advance "leftIt" by "start" count position forward

    std::list<int>::iterator rightIt = midIt;
    std::advance(rightIt, 1); // advance "rightIt" by 1 position forward

    std::list<int>::iterator endIt = _list.begin();
    std::advance(endIt, end + 1); // advance "endIt" by "end + 1" count position forward

    std::list<int>::iterator midNextIt = midIt;
    std::advance(midNextIt, 1); // advance "midNextIt" 1 position forward

    std::list<int> tmpList;

    while (leftIt != midNextIt && rightIt != endIt)
    {
        if (*leftIt < *rightIt)
            tmpList.push_back(*leftIt++);
        else
            tmpList.push_back(*rightIt++);
    }

    while (leftIt != midNextIt)
        tmpList.push_back(*leftIt++);

    while (rightIt != endIt)
        tmpList.push_back(*rightIt++);

    leftIt = _list.begin();
    std::advance(leftIt, start);

    std::list<int>::iterator tmpIt = tmpList.begin();
    while (leftIt != endIt)
        *leftIt++ = *tmpIt++;
}

void	PmergeMe::listMergeInsertionSort(int start, int end)
{
    if (end - start < _listThreshold)
	{
		listInsertionSort(start, end);
		return;
    }

    listMergeInsertionSort(start, (start + end) / 2);
    listMergeInsertionSort((start + end) / 2 + 1, end);
    listMerge(start, end);
}

void	PmergeMe::listCheckIfSorted(void)
{
	if (_list.empty() == true)
	{
		std::cout << PINK << "List is empty." << RESET << std::endl;
		return ;
	}
	std::list<int>::const_iterator itTmp;
	for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it)
	{
		itTmp = it;
		std::advance(itTmp, 1);
		if (itTmp != _list.end())
		{
			if (*it > *itTmp)
			{
				std::cout << PINK << "List is not sorted." << RESET << std::endl;
				return ;
			}
		}
	}
	std::cout << PINK << "List is sorted." << RESET << std::endl;
}

int	PmergeMe::getListSize() const
{
	return _list.size();
}

// ==== member functions (others) ============================================

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

