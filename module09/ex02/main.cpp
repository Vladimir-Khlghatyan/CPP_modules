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
	pmm.listPrint();

	pmm.vectorMergeInsertionSort(0, ac - 1);
	pmm.listInsertionSort(0, ac - 1);

	pmm.vectorPrint();
	pmm.listPrint();
	return 0;
}

// #include <list>
// #include <iostream>

// void    printList(std::list<int> & _list)
// {
//     for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// void listMerge(std::list<int> & _list, int start, int end)
// {
//     std::list<int>::iterator midIt = _list.begin();
//     std::advance(midIt, (start + end) / 2); // advance "midIt" by "(start + end) / 2" count position forward

//     std::list<int>::iterator leftIt = _list.begin();
//     std::advance(leftIt, start); // advance "leftIt" by "start" count position forward

//     std::list<int>::iterator rightIt = midIt;
//     // std::advance(rightIt, 1); // advance "rightIt" by 1 position forward

//     std::list<int>::iterator endIt = _list.begin();
//     std::advance(endIt, end + 1); // advance "endIt" by "end + 1" count position forward

//     std::list<int> tmpList;

//     // std::advance(midIt, 1);
//     while (leftIt != midIt && rightIt != endIt)
//     {
//         std::cout << "left: " << *leftIt << " right: " << *rightIt << std::endl;
//         if (*leftIt < *rightIt)
//             tmpList.push_back(*leftIt++);
//         else
//             tmpList.push_back(*rightIt++);
//         printList(tmpList);
//     }

//     // std::cout << "a: ";
//     // printList(tmpList);

//     while (leftIt != midIt)
//     {
//         tmpList.push_back(*leftIt++);
//         printList(tmpList);
//     }

//     while (rightIt != endIt)
//     {
//         tmpList.push_back(*rightIt++);
//         printList(tmpList);
//     }

//     // std::cout << "b: ";
//     // printList(tmpList);


//     leftIt = _list.begin();
//     std::advance(leftIt, start);

//     std::list<int>::iterator tmpIt = tmpList.begin();
//     while (leftIt != endIt)
//         *leftIt++ = *tmpIt++;
// }

// int main()
// {
//     std::list<int> myList;

//     myList.push_back(1);
//     myList.push_back(3);
//     myList.push_back(5);
//     myList.push_back(7);
//     myList.push_back(9);
//     myList.push_back(11);
//     myList.push_back(2);
//     myList.push_back(4);
//     myList.push_back(6);
//     myList.push_back(8);
//     myList.push_back(10);
//     myList.push_back(12);

//      printList(myList);

//      listMerge(myList, 0, 11);

//      printList(myList);

//     return 0;
// }