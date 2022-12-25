#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:		
		Dog(void);							// Default constructor
		Dog(const Dog &other);				// Copy constructor
		Dog &operator=(const Dog &other);	// Copy assignment operator
		~Dog(void);							// Destructor

	public:
		void	makeSound() const;
		

	public:
		std::string	getClassName(void);

};

#endif