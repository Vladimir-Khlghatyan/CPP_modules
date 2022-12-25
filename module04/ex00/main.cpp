#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << YELLOW << "== Animal test =============================================\n" << RESET << std::endl;

	const Animal*	meta = new Animal();
	const Animal*	j	 = new Dog();
	const Animal*	i	 = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	std::cout << YELLOW << "== WrongAnimal test ========================================\n" << RESET << std::endl;

	const WrongAnimal*	w_meta = new WrongAnimal();
	const WrongAnimal*	w_i	 = new WrongCat();

	std::cout << std::endl;

	std::cout << w_i->getType() << " " << std::endl;

	std::cout << std::endl;
	
	w_i->makeSound(); //will output the generic wrong animal sound!
	w_meta->makeSound();

	std::cout << std::endl;

	delete w_meta;
	delete w_i;

	std::cout << std::endl;

	std::cout << YELLOW << "== Constructors test =======================================" << RESET << std::endl;
	
	std::cout << YELLOW << "\nDog d1; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Dog	d1;
	std::cout << YELLOW << "\nDog d2; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Dog	d2;
	std::cout << YELLOW << "\nDog d3(d1); \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Dog	d3(d1);
	std::cout << YELLOW << "\nd2 = d1; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	d2 = d1;

	std::cout << YELLOW << "\nCat c1; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Cat	c1;
	std::cout << YELLOW << "\nCat c2; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Cat	c2;
	std::cout << YELLOW << "\nCat c3(c1); \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	Cat	c3(c1);
	std::cout << YELLOW << "\nc2 = c3; \33[1;30m// line " << __LINE__ + 1 << " ⬇ " << RESET << std::endl;
	c2 = c3;
	std::cout << std::endl;

	return (0);
}
