#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <typeinfo>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"


class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;

	public:		
		ClapTrap(void);								// Default constructor
		ClapTrap(const std::string name);			// Parameterized constructor
		ClapTrap(const ClapTrap &other);			// Copy constructor
		ClapTrap &operator=(const ClapTrap &other);	// Copy assignment operator
		~ClapTrap(void);							// Destructor

	public:		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	public:
		void		showAttributes(void);
		void		setHitPoints(unsigned int amount);
		void		setEnergyPoints(unsigned int amount);
		void		setAttackDamage(unsigned int amount);
		std::string	getClassName(void);

};

#endif