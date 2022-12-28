#include "ShrubberyCreationForm.hpp"

//==== constructors =====================================================================

ShrubberyCreationForm::ShrubberyCreationForm(void) : \
	Form("Shrubbery", 145, 137), \
	_target("")
{
	std::cout << GREEN << "Default constructor of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : \
	Form("Shrubbery", 145, 137), \
	_target(target)
{
	std::cout << GREEN << "Parameterized constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : \
	Form("Shrubbery", 145, 137), \
	_target(other._target)
{
	std::cout << GREEN << "Copy constructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	std::cout << GREEN << "Copy assignment operatorr of " << this->getClassName();
	std::cout <<" class called." << RESET << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << BLUE << "Destructor of " << this->getClassName();
	std::cout << " class called." << RESET << std::endl;
}

//==== member functions by subject ======================================================

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (Form::GradeTooLowException());

	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	ofs(filename.c_str());
	if (!ofs.is_open())
	{
		std::cout << RED << "Coulnd't open the output file" << RESET << std::endl;
		return ;
	}
	ofs << "                       .  ,****** **  ,                     " << std::endl;
	ofs << "            .  ** *** ***//*******//*****                   " << std::endl;
	ofs << "          * ,**/******/////*///***//////**                  " << std::endl;
	ofs << "       ,***//////////**(((//////**(((*****,*** ******,      " << std::endl;
	ofs << "       *//****//*/*******,*/(//(/****/*////*****////****    " << std::endl;
	ofs << "      *****///((***/////*/////////***///////*****((/*/**,.  " << std::endl;
	ofs << "   **.****//(((((((/*//////****////**(((///****(((/*****    " << std::endl;
	ofs << "     */(((***/////****////*//////*/////***/***((*/////****  " << std::endl;
	ofs << "    ,**(***/////////**/*((///(////**//****///****////#//****" << std::endl;
	ofs << "   **((((((/////////(((((/#((((((((((((/*/////****(%%##(***," << std::endl;
	ofs << " ,**((***((((((((/######(((((#(((*/*/*((((((((*%%###(****.  " << std::endl;
	ofs << " ***/((((%%#%#%&%#(((#%#(((%%((%%&#((((#***(%#%%##%%%%**    " << std::endl;
	ofs << "  *.***/(/(///%%#(%%%%%#%%*%%%&##(%#%%%*(%##%(*%%%%%* ,     " << std::endl;
	ofs << "         **(((((((%#####*%%%%%%##%%&(%(%/((((((**           " << std::endl;
	ofs << "            *, ,*, .*#&&#####&(/#((##((/.    *              " << std::endl;
	ofs << "                         &%(#%#((..#(/                      " << std::endl;
	ofs << "                          &#(#((##(#*                       " << std::endl;
	ofs << "                          &#((##(#                          " << std::endl;
	ofs << "                          &##(#(#                           " << std::endl;
	ofs << "                          ###(((*                           " << std::endl;
	ofs << "                         (#&#((**                           " << std::endl;
	ofs << "                        &&&#(#((#/                          " << std::endl;
	ofs << "                       &%##&(#((##*                         " << std::endl;
	ofs << "                     &&&&&&#(%(((##(.                       " << std::endl;
	ofs << "                     &#%##%%#&%#*%&##(                      " << std::endl;
	ofs.close();
}


const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

//==== member functions by me (for better testing)=======================================

const std::string	ShrubberyCreationForm::getClassName(void)
{
	std::string s = typeid(*this).name();
	s = s.substr(2);
	return (s);
}
