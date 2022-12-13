#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string type)
{
	this->setType(type);
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType(void) const
{
	return (this->m_type);
}

void	Weapon::setType(const std::string newType)
{
	this->m_type = newType;
}