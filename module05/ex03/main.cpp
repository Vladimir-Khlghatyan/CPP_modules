#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void	ftPrintLine(int n)
{
	std::cout << WHITE;
	for (int i = 0; i < n; i++)
		std::cout << "_";
	std::cout << RESET << std::endl;
}

int	main(void)
{
	
	try	{
		Intern	i;
		Form	*f;

		ftPrintLine(80);
		f = i.makeForm("ShrubberyCreationForm", "Balance");
		std::cout << *f << std::endl;
		delete f;

		ftPrintLine(80);
		f = i.makeForm("RobotomyRequestForm", "PnL");
		std::cout << *f << std::endl;
		delete f;

		ftPrintLine(80);
		f = i.makeForm("PresidentialPardonForm", "CashFlow");
		std::cout << *f << std::endl;
		delete f;

		ftPrintLine(80);
		f = i.makeForm("ankap", "ankap");
		std::cout << *f << std::endl;
		delete f;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
