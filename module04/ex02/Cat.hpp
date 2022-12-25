#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;

	public:		
		Cat(void);							// Default constructor
		Cat(const Cat &other);				// Copy constructor
		Cat &operator=(const Cat &other);	// Copy assignment operator
		~Cat(void);							// Destructor

	public:
		void	makeSound() const;
		

	public:
		std::string			getClassName(void);
		void				setBrainIdea(int index, const std::string& idea);
		const std::string	&getBrainIdea(int index) const;

};

#endif