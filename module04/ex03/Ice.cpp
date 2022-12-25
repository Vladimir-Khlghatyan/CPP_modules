#include "Ice.hpp"

//==== constructors =====================================================================

Ice::Ice(void) : AMateria()
{
	this->_type = "ice";
	std::cout << GREEN << "Default constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	this->_type = other._type;
	std::cout << GREEN << "Copy constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName() <<" class called.";
		std::cout << RESET << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << RED << "Destructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

//==== member functions by subject ======================================================

Ice	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << GREEN << "*" << WHITE << " shoots an ice bolt at " << CYAN;
	std::cout << target.getName() << GREEN << " *" << RESET << std::endl;
}

//==== member functions by me (for better testing)=======================================

std::string	Ice::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}