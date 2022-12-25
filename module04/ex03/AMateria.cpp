#include "AMateria.hpp"

//==== constructors =====================================================================

AMateria::AMateria(void)
{
	this->_type = "";
	std::cout << GREEN << "Default constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
	std::cout << GREEN << "Copy constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
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

AMateria::~AMateria(void)
{
	std::cout << RED << "Destructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

//==== member functions by subject ======================================================

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}

//==== member functions by me (for better testing)=======================================

std::string	AMateria::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}