#include "MateriaSource.hpp"

//==== constructors =====================================================================

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << GREEN << "Default constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = other._materias[i]->clone();
	std::cout << GREEN << "Copy constructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			if (this->_materias[i] != NULL)
			{
				delete this->_materias[i];
				this->_materias[i] = NULL;
			}
		for (int i = 0; i < 4; ++i)
			if (other._materias[i] != NULL)
				this->_materias[i] = other._materias[i]->clone();
		std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName() <<" class called.";
		std::cout << RESET << std::endl;
		return (*this);
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	std::cout << RED << "Destructor of " << this->getClassName() <<" class called.";
	std::cout << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (materia != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i] == NULL)
			{
				this->_materias[i] = materia;
				std::cout << BLUE << "MateriaSource learned." << RESET << std::endl;
				return ;
			}
		}
	}
	std::cout << YELLOW << "MateriaSource can't learn." << RESET << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materias[i] and type.compare(this->_materias[i]->getType()) == 0)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}

//==== member functions by me (for better testing)=======================================

std::string	MateriaSource::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}