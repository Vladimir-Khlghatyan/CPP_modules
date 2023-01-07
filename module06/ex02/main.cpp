#include "Base.hpp"
#include "Derive.hpp"


Base	*generate(void)
{
	std::cout << YELLOW << "Random derive object was geredated!\n" << RESET << std::endl;
	std::srand(time(NULL));
	switch (std::rand() % 4)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
		default:
			return (new UnknownType);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type identify via adress   : " << GREEN << "A" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type identify via adress   : " << GREEN << "B" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type identify via adress   : " << GREEN << "C" << RESET << std::endl;
	else
		std::cout << RED << "Unknown type!" << RESET << std::endl;
}

void	identify(Base& p)
{
	try	{
		(void)dynamic_cast<A& >(p);
		std::cout << "Type identify via reference: " << GREEN << "A" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	try	{
		(void)dynamic_cast<B& >(p);
		std::cout << "Type identify via reference: " << GREEN << "B" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	try	{
		(void)dynamic_cast<C& >(p);
		std::cout << "Type identify via reference: " << GREEN << "C" << RESET << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
}

int	main(void)
{
	Base	*randomPtr = generate();
	Base	&randomRef = *randomPtr;

	(void)*randomPtr;
	(void)&randomRef;

	identify(randomPtr);
	identify(randomRef);

	delete randomPtr;
	return (0);
}
