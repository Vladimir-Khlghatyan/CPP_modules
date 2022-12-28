#include "Bureaucrat.hpp"

//==== constructors =====================================================================

Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(150)
{
	std::cout << GREEN << "Default constructor of " << this->getClassName();
	std::cout <<" class called (" << _name << " created)." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int initGrade) : _name(name)
{
	if (initGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (initGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = initGrade;
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName();
	std::cout << " class called (" << _name << " created)." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << GREEN << "Copy constructor of " << this->getClassName();
	std::cout << " class called (" << _name << " copied)." << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// we don't change _name because it is constant
		this->_grade = other._grade;
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName();
	std::cout <<" class called (" << _name << " is assigned)." << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << BLUE << "Destructor of " << this->getClassName();
	std::cout << " class called (" << _name << " destroyed)." << RESET << std::endl;
}

//==== Exception what() functions =======================================================
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("EXCEPTION: Grade is too high (highest possible grade is 1)!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("EXCEPTION: Grade is too low (lowest possible grade is 150)!");
}

//==== member functions by subject ======================================================
const std::string	&Bureaucrat::getName(void) const
{
	return(this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	std::cout << CYAN << "Incrementing " << _name << "'s current grade by 1 (before ";
	std::cout << _grade << ", after " << _grade - 1 << ")." << RESET << std::endl;
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << CYAN << "Decrementing " << _name << "'s current grade by 1 (before ";
	std::cout << _grade << ", after " << _grade + 1 << ")." << RESET << std::endl;
	this->_grade++;
}

//==== member functions by me (for better testing)=======================================

const std::string	Bureaucrat::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}

//==== << overload ======================================================================

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << YELLOW << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET;
	return (o);
}
