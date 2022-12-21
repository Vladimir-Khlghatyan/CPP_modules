#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:		
		FragTrap(void);								// Default constructor
		FragTrap(const std::string name);			// Parameterized constructor
		FragTrap(const FragTrap &other);			// Copy constructor
		FragTrap &operator=(const FragTrap &other);	// Copy assignment operator
		~FragTrap(void);							// Destructor

	public:		
		void	attack(const std::string& target);
		void	highFivesGuys(void);

	public:
		std::string	getClassName(void);
};

#endif