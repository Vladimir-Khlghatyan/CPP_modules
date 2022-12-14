#include "Bureaucrat.hpp"

void	ft_test1(void);
void	ft_test2(void);
void	ft_test3(void);
void	ft_test4(void);
void	ft_test5(void);
void	ft_test6(void);
void	ft_test7(void);
void	ft_test8(void);

int	main(void)
{
	ft_test1();
	ft_test2();
	ft_test3();
	ft_test4();
	ft_test5();
	ft_test6();
	ft_test7();
	ft_test8();
	return (0);
}


void	ft_test1(void)
{
	std::cout << WHITE << "\n_ TEST 1 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b;
		std::cout << b << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}


void	ft_test2(void)
{
	std::cout << WHITE << "\n_ TEST 2 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 100);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test3(void)
{
	std::cout << WHITE << "\n_ TEST 3 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b1("Aramik", 5);
		Bureaucrat	b2(b1);
		std::cout << b2 << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test4(void)
{
	std::cout << WHITE << "\n_ TEST 4 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b1;
		Bureaucrat	b2("Aramik", 8);
		b1 = b2;
		std::cout << b1 << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test5(void)
{
	std::cout << WHITE << "\n_ TEST 5 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 151);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test6(void)
{
	std::cout << WHITE << "\n_ TEST 6 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 0);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test7(void)
{
	std::cout << WHITE << "\n_ TEST 7 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 148);
		std::cout << b << std::endl;
		for (int i = 0; i < 5; i++)
			b.decrementGrade();
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test8(void)
{
	std::cout << WHITE << "\n_ TEST 8 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 5);
		std::cout << b << std::endl;
		for (int i = 0; i < 8; i++)
			b.incrementGrade();
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}