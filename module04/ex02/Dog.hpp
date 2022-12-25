#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain*	_brain;

	public:		
		Dog(void);							// Default constructor
		Dog(const Dog &other);				// Copy constructor
		Dog &operator=(const Dog &other);	// Copy assignment operator
		~Dog(void);							// Destructor

	public:
		void	makeSound() const;
		

	public:
		std::string			getClassName(void);
		void				setBrainIdea(int index, const std::string& idea);
		const std::string	&getBrainIdea(int index) const;

};

#endif