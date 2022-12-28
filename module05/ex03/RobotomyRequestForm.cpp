#include "RobotomyRequestForm.hpp"

//==== constructors =====================================================================

RobotomyRequestForm::RobotomyRequestForm(void) : \
	Form("Robotomy", 72, 45), \
	_target("")
{
	std::cout << GREEN << "Default constructor of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : \
	Form("Robotomy", 72, 45), \
	_target(target)
{
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : \
	Form("Robotomy", 72, 45), \
	_target(other._target)
{
	std::cout << GREEN << "Copy constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << BLUE << "Destructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (Form::GradeTooLowException());
	std::srand(time(NULL));	
	if (std::rand() % 2 == 0)
		std::cout << GREEN << _target << " has been robotomized successfully." << RESET << std::endl;
	else
		throw (Form::SuccessException());	
}


const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

//==== member functions by me (for better testing)=======================================

const std::string	RobotomyRequestForm::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}
