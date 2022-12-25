#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
        AMateria	*_materias[4];

	public:
		MateriaSource(void);									// Default constructor
		MateriaSource(const MateriaSource &other);				// Copy constructor
		MateriaSource &operator=(const MateriaSource &other);	// Copy assignment operator
		~MateriaSource(void);									// Destructor

	public:
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const &type);


	public:
		std::string		getClassName(void);
};

#endif