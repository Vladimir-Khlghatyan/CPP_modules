#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <typeinfo>
# include "ICharacter.hpp"

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);								// Default constructor
		AMateria(std::string const &type);			// Parameterized constructor
		AMateria(const AMateria &other);			// Copy constructor
		AMateria &operator=(const AMateria &other);	// Copy assignment operator
		virtual ~AMateria(void);					// Destructor

	public:	
		std::string const	&getType() const; 		//Returns the materia type
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);

	public:
		std::string			getClassName(void);
};

#endif