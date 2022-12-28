#include "Form.hpp"

//==== constructors =====================================================================

Form::Form(void) : \
	_name("Unnamed"), \
	_isSigned(false), \
	_signGrade(150), \
	_executeGrade(150)
{
	std::cout << GREEN << "Default constructor of " << this->getClassName();
	std::cout <<" class called (" << _name << " created)." << RESET << std::endl;
}

Form::Form(std::string const &name, int signGrade, int executeGrade) : \
	_name(name), \
	_isSigned(false), \
	_signGrade(signGrade), \
	_executeGrade(executeGrade)
{
	if (signGrade < 1 or executeGrade < 1)
		throw (Form::GradeTooHighException());
	if (signGrade > 150 or executeGrade > 150)
		throw (Form::GradeTooLowException());
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName();
	std::cout << " class called (" << _name << " created)." << RESET << std::endl;
}

Form::Form(const Form &other) : \
	_name(other._name), \
	_isSigned(other._isSigned), \
	_signGrade(other._signGrade), \
	_executeGrade(other._executeGrade)
{
	std::cout << GREEN << "Copy constructor of " << this->getClassName();
	std::cout << " class called (" << _name << " copied)." << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// we don't change _name, _signGrade and _executeGrade because these are constant
		this->_isSigned = other._isSigned;
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName();
	std::cout <<" class called (" << _name << " is assigned)." << RESET << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << BLUE << "Destructor of " << this->getClassName();
	std::cout << " class called (" << _name << " destroyed)." << RESET << std::endl;
}
//==== Exception what() functions =======================================================
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("EXCEPTION: Grade is too high (highest possible grade is 1)!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("EXCEPTION: Grade is too low (lowest possible grade is 150)!");
}

const char	*Form::UnsignedFormException::what() const throw()
{
	return ("EXCEPTION: An unsigned form can't be executed!");
}

const char	*Form::SuccessException::what() const throw()
{
	return ("EXCEPTION: Unsuccessful attempt at robotization!");
}


//==== member functions by subject ======================================================
const std::string	&Form::getName(void) const
{
	return(this->_name);
}

bool	Form::getIsSigned(void) const
{
	return(this->_isSigned);
}

int	Form::getSignGrade(void) const
{
	return(this->_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return(this->_executeGrade);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
	std::cout << CYAN << this->getClassName() << " " << _name;
	std::cout << " was signed by the bureaucrat " << b.getName() << ".";
	std::cout << RESET << std::endl;
}


//==== member functions by me (for better testing)=======================================

const std::string	Form::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}

//==== << overload ======================================================================

std::ostream &operator<<(std::ostream &o, const Form &rhs)
{
	o << YELLOW;
	o << "[Name: " << rhs.getName();
	o << "], [IsSigned: " << rhs.getIsSigned();
	o << "], [SignGrade: " << rhs.getSignGrade();
	o << "], [ExecuteGrade: " << rhs.getExecuteGrade();
	o << "]." << RESET;
	return (o);
}
