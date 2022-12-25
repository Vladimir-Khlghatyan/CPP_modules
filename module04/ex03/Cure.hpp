#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{

	public:
		Cure(void);							// Default constructor
		Cure(const Cure &other);			// Copy constructor
		Cure &operator=(const Cure &other);	// Copy assignment operator
		virtual ~Cure(void);				// Destructor

	public:	
		Cure	*clone() const;
		void	use(ICharacter& target);

	public:
		std::string			getClassName(void);
};

#endif