#include "Cure.hpp"

//==== constructors =====================================================================

Cure::Cure(void) : AMateria()
{
	this->_type = "cure";
	std::cout << GREEN << "Default constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	this->_type = other._type;
	std::cout << GREEN << "Copy constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other)
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

Cure::~Cure(void)
{
	std::cout << RED << "Destructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

//==== member functions by subject ======================================================

Cure	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << GREEN << "*" << WHITE << " heals " << CYAN << target.getName();
	std::cout << "'s" << WHITE << " wounds " << GREEN << "*" << RESET << std::endl;
}

//==== member functions by me (for better testing)=======================================

std::string	Cure::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(1);
	return (s);
}