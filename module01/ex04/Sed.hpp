#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
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

class Sed
{
	public:

		Sed(std::string& inFile);
		~Sed();
		void	replace(std::string& s1, std::string& s2);

	private:
		
		std::string	m_inFile;
		std::string	m_outFile;
};

#endif