#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	// const AAnimal a; //error: cannot declare variable ‘a’ to be of abstract type ‘AAnimal’

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	std::cout << YELLOW << "\n== My tests =============================================" << RESET << std::endl;

	int		idx = 0;
	int		n = 4;
	AAnimal	*animals[n];
		
	while (idx < n / 2)
	{
		std::cout << YELLOW << "\n_ new Dog _" << RESET << std::endl;
		animals[idx++] = new Dog();
	}
	while (idx < n)
	{
		std::cout << YELLOW << "\n_ new Cat _" << RESET << std::endl;
		animals[idx++] = new Cat();
	}

	std::cout << YELLOW << "\n_ deleting all animals _" << RESET << std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];
	std::cout << YELLOW << "\n- new test ------------------------------------------------\n" << RESET << std::endl;

	std::cout << YELLOW << "_ new Dog _" << RESET << std::endl;
	Dog *dog = new Dog();
	dog->setBrainIdea(0, "The bone is delicious.");
	dog->setBrainIdea(1, "Meat tastes even better.");

	std::cout << YELLOW << "\n_ Dog's ideas _" << RESET << std::endl;
	std::cout << CYAN << "Dog's first idea is: " << GREEN << dog->getBrainIdea(0) << RESET << std::endl;
	std::cout << CYAN << "Dog's second idea is: " << GREEN << dog->getBrainIdea(1) << RESET << std::endl;

	std::cout << YELLOW << "\n_ deleting Dog _" << RESET << std::endl;
	delete dog;

	std::cout << YELLOW << "\n- new test ------------------------------------------------" << RESET << std::endl;

	std::cout << YELLOW << "\nCat basic; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Cat	basic;
	{
		std::cout << YELLOW << "\nCat tmp = basic; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
		Cat	tmp = basic;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
