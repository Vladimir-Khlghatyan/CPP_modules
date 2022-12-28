#include "PresidentialPardonForm.hpp"

//==== constructors =====================================================================

PresidentialPardonForm::PresidentialPardonForm(void) : \
	Form("President", 25, 5), \
	_target("")
{
	std::cout << GREEN << "Default constructor of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : \
	Form("President", 25, 5), \
	_target(target)
{
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : \
	Form("President", 25, 5), \
	_target(other._target)
{
	std::cout << GREEN << "Copy constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << BLUE << "Destructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (Form::GradeTooLowException());
	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}


const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

//==== member functions by me (for better testing)=======================================

const std::string	PresidentialPardonForm::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}
