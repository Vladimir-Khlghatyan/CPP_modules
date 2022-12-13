#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA
{
	public:

		HumanA();
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack(void) const;

	private:
		Weapon&	m_weapon;
		std::string	m_name;	
};

#endif