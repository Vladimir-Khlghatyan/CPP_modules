#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//==== constructors =====================================================================

Intern::Intern(void)
{
	std::cout << GREEN << "Default constructor of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << GREEN << "Copy constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		//
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << BLUE << "Destructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

//==== Exception what() functions =======================================================
const char	*Intern::InternException::what() const throw()
{
	return ("EXCEPTION: The Intern was unable to create a form!");
}

//==== member functions by subject ======================================================

Form	*Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	Form *(Intern::*ptr_member_func[3])(const std::string &target) const = \
				{&Intern::makeP, &Intern::makeR, &Intern::makeSh};
	std::string	request[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(request[i]) == 0)
		{
			std::cout << GREEN << "Intern creates \"" << formName;
		std::cout <<"\" form." << RESET << std::endl;
			return ((this->*ptr_member_func[i])(formTarget));
		}
	}
	throw (InternException());
	return (NULL);
}

Form	*Intern::makeP(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeR(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeSh(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

//==== member functions by me (for better testing)=======================================

const std::string	Intern::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}