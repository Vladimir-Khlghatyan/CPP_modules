#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:		
		WrongCat(void);								// Default constructor
		WrongCat(const WrongCat &other);			// Copy constructor
		WrongCat &operator=(const WrongCat &other);	// Copy assignment operator
		~WrongCat(void);							// Destructor

	public:
		void	makeSound() const;
		

	public:
		std::string	getClassName(void);

};

#endif