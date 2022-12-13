#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:

		HumanB(std::string name);
		~HumanB();
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);

	private:
		
		std::string	m_name;
		Weapon*	m_weapon;
};

#endif