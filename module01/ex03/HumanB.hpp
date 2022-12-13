#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
	public:

		HumanB();
		HumanB(std:string name);
		~HumanB();
		void	attack(void) const;

	private:
		Weapon*	m_weapon;
		std::string	m_name;	
};

#endif