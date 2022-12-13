#include "Sed.hpp"

Sed::Sed(std::string& inFile): m_inFile(inFile)
{
	this->m_outFile = this->m_inFile + ".replace";
}

Sed::~Sed(void)
{

}

void	Sed::replace(std::string& s1, std::string& s2)
{
	std::string	content;
	size_t		position = 0;
	size_t		index = 0;

	std::ifstream	inFileStream(m_inFile);
	if (inFileStream.is_open())
	{
		if (std::getline(inFileStream, content, '\0'))
		{
			std::ofstream outFileStream(m_outFile);
			position = content.find(s1);
			while (position != std::string::npos)
			{
				outFileStream << content.substr(index, position - index);
				outFileStream << s2;
				index = position + s1.length();
				position = content.find(s1, position + 1);
			}
			outFileStream << content.substr(index);
			outFileStream.close();
		}
		else
			std::cerr << "Empty file found." << std::endl;
		inFileStream.close();
	}
	else
	{
		std::cerr << RED << "Unable to open the file." << RESET << std::endl;
		exit(1);
	}
}
