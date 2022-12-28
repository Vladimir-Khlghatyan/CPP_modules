#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	ft_test1(void);
void	ft_test2(void);
void	ft_test3(void);
void	ft_test4(void);
void	ft_test5(void);
void	ft_test6(void);
// void	ft_test7(void);
// void	ft_test8(void);
// void	ft_test9(void);
// void	ft_test10(void);

int	main(void)
{
	ft_test1();
	ft_test2();
	ft_test3();
	ft_test4();
	ft_test5();
	ft_test6();
	// ft_test7();
	// ft_test8();
	// ft_test9();
	// ft_test10();
	return (0);
}


void	ft_test1(void)
{
	std::cout << WHITE << "\n_ TEST 1 _";
	for (int i = 0; i < 75; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat b("Aramik", 50);
		ShrubberyCreationForm sh("Home");

		std::cout << b << std::endl;
		std::cout << sh << std::endl;

		b.executeForm(sh);
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
		Bureaucrat b("Aramik", 50);
		ShrubberyCreationForm sh("Home");

		std::cout << b << std::endl;
		std::cout << sh << std::endl;
		sh.beSigned(b);
		b.executeForm(sh);
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
		Bureaucrat b("Aramik", 20);
		RobotomyRequestForm r("Robin");

		std::cout << b << std::endl;
		std::cout << r << std::endl;

		b.executeForm(r);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	ft_test4(void)
{
	std::cout << WHITE << "\n_ TEST 4 _ (successs rate is 50%) ";
	for (int i = 0; i < 51; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;

	try	{
		Bureaucrat b("Aramik", 20);
		RobotomyRequestForm r("Robin");

		std::cout << b << std::endl;
		std::cout << r << std::endl;
		r.beSigned(b);
		b.executeForm(r);
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
		Bureaucrat b("Aramik", 1);
		PresidentialPardonForm p("Karen");

		std::cout << b << std::endl;
		std::cout << p << std::endl;

		b.executeForm(p);
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
		Bureaucrat b("Aramik", 1);
		PresidentialPardonForm p("Karen");

		std::cout << b << std::endl;
		std::cout << p << std::endl;

		p.beSigned(b);
		b.executeForm(p);
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

