#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(void);								// Default constructor
		Character(std::string const &name);				// Parameterized constructor
		Character(const Character &other);				// Copy constructor
		Character &operator=(const Character &other);	// Copy assignment operator
		~Character(void);								// Destructor

	public:
		std::string const	&getName() const;
		void 				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		AMateria	*_recycleBin[100];

	public:
		std::string		getClassName(void);
		void			pushToRecycleBin(AMateria *inventory);
};

#endif