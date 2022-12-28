#include "Bureaucrat.hpp"
#include "Form.hpp"

void	ft_test1(void);
void	ft_test2(void);
void	ft_test3(void);
void	ft_test4(void);
void	ft_test5(void);
void	ft_test6(void);
void	ft_test7(void);
void	ft_test8(void);
void	ft_test9(void);
void	ft_test10(void);

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
	ft_test9();
	ft_test10();
	return (0);
}


void	ft_test1(void)
{
	std::cout << WHITE << "\n_ TEST 1 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Form f;
		std::cout << f << std::endl;
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
		Form	f("Balance", 10, 15);
		std::cout << f << std::endl;
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
		Form	f1("Balance", 75, 130);
		Form	f2(f1);
		std::cout << f2 << std::endl;
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
		Form	f1;
		Form	f2("Balance", 12, 63);
		f1 = f2;
		std::cout << f1 << std::endl;
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
		Form	f("Balance", 155, 10);
		std::cout << f << std::endl;

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
		Form	f("Balance", 10, 155);
		std::cout << f << std::endl;
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
		Form	f("Balance", 0, 10);
		std::cout << f << std::endl;

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
		Form	f("Balance", 10, 0);
		std::cout << f << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test9(void)
{
	std::cout << WHITE << "\n_ TEST 9 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 100);
		std::cout << b << std::endl;
		Form	f("Balance", 10, 15);
		std::cout << f << std::endl;

		b.signForm(f);
		f.beSigned(b);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test10(void)
{
	std::cout << WHITE << "\n_ TEST 10 _";
	for (int i = 0; i < 74; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat	b("Aramik", 100);
		std::cout << b << std::endl;
		Form	f("Balance", 130, 15);
		std::cout << f << std::endl;

		b.signForm(f);
		f.beSigned(b);
		b.signForm(f);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}