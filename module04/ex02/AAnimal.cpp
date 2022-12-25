#include "AAnimal.hpp"

//==== constructors =====================================================================

AAnimal::AAnimal(void)
{
	this->_type = this->getClassName();
	std::cout << WHITE << "Default " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	this->_type = other._type;
	std::cout << WHITE << "Copy " << GREEN << "constructor" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << GREEN << "Copy assignment operator" << WHITE << " of ";
		std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Copy assignment operator" << WHITE << " of ";
	std::cout << BLUE << this->getClassName() << WHITE << " class called." << RESET << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << RED << "Destructor" << WHITE << " of " << BLUE << this->getClassName();
	std::cout << WHITE << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

const std::string	&AAnimal::getType(void) const
{
	return (this->_type);
}

//==== member functions by me (for better testing)=======================================

std::string	AAnimal::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}
