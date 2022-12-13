#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define PINK	"\33[1;35m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;36m"
# define CYAN	"\33[1;37m"
# define WHITE	"\033[1;37m"
# define RESET	"\33[0;m"

class Zombie
{
	public:

		Zombie(std::string name);
		~Zombie();
		
		void	announce(void) const;

	private:
		std::string	m_name;

};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
