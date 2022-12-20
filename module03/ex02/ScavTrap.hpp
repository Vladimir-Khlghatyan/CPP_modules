#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:		
		ScavTrap(void);								// Default constructor
		ScavTrap(const std::string name);			// Parameterized constructor
		ScavTrap(const ScavTrap &other);			// Copy constructor
		ScavTrap &operator=(const ScavTrap &other);	// Copy assignment operator
		~ScavTrap(void);							// Destructor

	public:		
		void	attack(const std::string& target);
		void	guardGate();

	public:
		std::string	getClassName(void);
};

#endif