#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_size = 0;
	m_index = 0;
}

PhoneBook::~PhoneBook() {}

static void	print_field(const std::string &str)
{
	if (str.length() > 10)
		std::cout << BLUE << str.substr(0, 9) << YELLOW << ".|" << RESET;
	else
		std::cout << BLUE << std::setw(10) << str << YELLOW << "|" << RESET;
}

void	PhoneBook::set_contact(std::string fields[5])
{
	m_contact[m_index].set_first_name(fields[0]);
	m_contact[m_index].set_last_name(fields[1]);
	m_contact[m_index].set_nick_name(fields[2]);
	m_contact[m_index].set_phone_number(fields[3]);
	m_contact[m_index].set_darkest_secret(fields[4]);
	m_index++;
	if (m_index > 7)
		m_index = 0;
	if (m_size < 8)
		m_size++;
}

void	PhoneBook::print_phonebook() const
{
	std::cout << YELLOW << "+----------+----------+----------+----------+" << std::endl;
	std::cout<< "|";
	std::cout << BLUE << std::setw(10) << "INDEX" << YELLOW << "|";
	std::cout << BLUE << std::setw(10) << "FIRST NAME" << YELLOW << "|";
	std::cout << BLUE << std::setw(10) << "LAST NAME" << YELLOW << "|";
	std::cout << BLUE << std::setw(10) << "NICKNAME" << YELLOW << "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		std::cout << "|" << BLUE << std::setw(10) << i << YELLOW "|";
		print_field(m_contact[i].get_first_name());
		print_field(m_contact[i].get_last_name());
		print_field(m_contact[i].get_nick_name());
		std::cout << YELLOW << "\n+----------+----------+----------+----------+" << std::endl;
	}
	std::cout << RESET;
}

void	PhoneBook::print_contact(int index) const
{
	std::cout << YELLOW << "Fist name: ";
	std::cout << BLUE << m_contact[index].get_first_name() << std::endl;
	std::cout << YELLOW << "Last name: ";
	std::cout << BLUE << m_contact[index].get_last_name() << std::endl;
	std::cout << YELLOW << "Nickname: ";
	std::cout << BLUE << m_contact[index].get_nick_name() << std::endl;
	std::cout << YELLOW << "Phone number: ";
	std::cout << BLUE << m_contact[index].get_phone_number() << std::endl;
	std::cout << YELLOW << "Darkest secret: ";
	std::cout << BLUE << m_contact[index].get_darkest_secret() << std::endl;
	std::cout << RESET;
}

int	PhoneBook::get_size() const
{
	return (m_size);
}
