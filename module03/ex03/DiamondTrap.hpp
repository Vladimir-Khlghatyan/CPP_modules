#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string		_name;
		using			FragTrap::_hit_points;
		using			ScavTrap::_energy_points;
		using			FragTrap::_attack_damage;

	public:		
		DiamondTrap(void);									// Default constructor
		DiamondTrap(const std::string name);				// Parameterized constructor
		DiamondTrap(const DiamondTrap &other);				// Copy constructor
		DiamondTrap &operator=(const DiamondTrap &other);	// Copy assignment operator
		~DiamondTrap(void);									// Destructor

	public:
		using		ScavTrap::attack;
		void		whoAmI(void);

	public:
		using		ClapTrap::setHitPoints;
		using		ClapTrap::setEnergyPoints;
		using		ClapTrap::setAttackDamage;
		void		showAttributes(void);
		std::string	getClassName(void);
};

#endif