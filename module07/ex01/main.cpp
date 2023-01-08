#include "iter.hpp"

template <typename T>
void	iter(T* array, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	myPrint(T& item)
{
	static size_t idx;
	std::cout << RESET << "item[" << idx << "]: ";
	std::cout << WHITE << item <<  RESET << std::endl;
	idx++;
}

int	main(void)
{
	// -- testing char -----------------------------------------------------
	char	char_arr[6] = "Barev";

	std::cout << YELLOW << "__ calling template function ";
	std::cout << CYAN << "\"iter\"" << YELLOW " for ";
	std::cout << PINK << "\"char\"" << YELLOW << " __" << std::endl;
	std::cout << BLACK << "// char arr[5] = \"Barev\";" << RESET << std::endl;
	iter(char_arr, 5, myPrint);


	// -- testing int ------------------------------------------------------
	int	int_arr[3] = {-42, 0, 42};

	std::cout << YELLOW << "\n__ calling template function ";
	std::cout << CYAN << "\"iter\"" << YELLOW " for ";
	std::cout << PINK << "\"int\"" << YELLOW << " __" << std::endl;
	std::cout << BLACK << "// int arr[3] = {-42, 0, 42};" << RESET << std::endl;
	iter(int_arr, 3, myPrint);


	// -- testing float ----------------------------------------------------
	float	float_arr[2] = {42.0f, 42.42f};

	std::cout << YELLOW << "\n__ calling template function ";
	std::cout << CYAN << "\"iter\"" << YELLOW " for ";
	std::cout << PINK << "\"float\"" << YELLOW << " __" << std::endl;
	std::cout << BLACK << "// float arr[2] = {42.0f, 42.42f};" << RESET << std::endl;
	iter(float_arr, 2, myPrint);


	// -- testing double ---------------------------------------------------
	double	double_arr[3] = {-4242.42, 42.042, 42.424242};

	std::cout << YELLOW << "\n__ calling template function ";
	std::cout << CYAN << "\"iter\"" << YELLOW " for ";
	std::cout << PINK << "\"double\"" << YELLOW << " __" << std::endl;
	std::cout << BLACK << "// double arr[3] = {-4242.42, 42.042, 42.424242};" << RESET << std::endl;
	iter(double_arr, 3, myPrint);


	// -- testing std::string ----------------------------------------------
	std::string	string_arr[4] = {"I", "love", "forty-two", "Yerevan"};

	std::cout << YELLOW << "\n__ calling template function ";
	std::cout << CYAN << "\"iter\"" << YELLOW " for ";
	std::cout << PINK << "\"std::string\"" << YELLOW << " __" << std::endl;
	std::cout << BLACK << "// std::string arr[4] = {\"I\", \"love\", \"forty-two\", \"Yerevan\"};" << RESET << std::endl;
	iter(string_arr, 4, myPrint);

	return (0);
}