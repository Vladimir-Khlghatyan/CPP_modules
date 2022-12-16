#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

class Zombie
{
	public:

		Zombie();
		Zombie(std::string name);
		~Zombie();
		
		void	announce(void) const;
		void	set_name(std::string name);

	private:
		std::string	m_name;

};

Zombie*	zombieHorde(int N, std::string name);

#endif
