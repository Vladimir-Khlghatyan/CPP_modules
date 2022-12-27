#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << WHITE << "\n_ TEST 1 ______________________________________________________" << RESET << std::endl;
	Bureaucrat	a;
	std::cout << a << std::endl;



	std::cout << WHITE << "\n_ TEST 2 ______________________________________________________" << RESET << std::endl;
	try	{
		Bureaucrat	b("Poghos", 100);
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}




	std::cout << WHITE << "\n_ TEST 3 ______________________________________________________" << RESET << std::endl;

	try	{
		Bureaucrat	c1("First", 5);
		Bureaucrat	c2(c1);
		std::cout << c2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}




	std::cout << WHITE << "\n_ TEST 4 ______________________________________________________" << RESET << std::endl;

	try	{
		Bureaucrat	d1;
		Bureaucrat	d2("First", 5);
		d1 = d2;
		std::cout << d1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}





	std::cout << WHITE << "\n_ TEST 5 ______________________________________________________" << RESET << std::endl;

	try	{
		Bureaucrat	e("Petros", 151);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}




	std::cout << WHITE << "\n_ TEST 6 ______________________________________________________" << RESET << std::endl;

	try	{
		Bureaucrat	f("Martiros", 0);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	
	return (0);
}