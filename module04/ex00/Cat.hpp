#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:		
		Cat(void);							// Default constructor
		Cat(const Cat &other);				// Copy constructor
		Cat &operator=(const Cat &other);	// Copy assignment operator
		~Cat(void);							// Destructor

	public:
		void	makeSound() const;
		

	public:
		std::string	getClassName(void);

};

#endif