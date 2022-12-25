#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{

	public:
		Ice(void);							// Default constructor
		Ice(const Ice &other);				// Copy constructor
		Ice &operator=(const Ice &other);	// Copy assignment operator
		virtual ~Ice(void);					// Destructor

	public:	
		Ice		*clone() const;
		void	use(ICharacter& target);

	public:
		std::string			getClassName(void);
};

#endif