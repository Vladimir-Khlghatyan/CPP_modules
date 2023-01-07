#include "Converter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	std::string	argumnet = av[1];
	Converter converter(argumnet);
	char	c;
	int		i;
	float	f;
	double	d;

	(void)c;
	(void)i;
	(void)f;
	(void)d;

	// std::cout << std::fixed << std::setprecision(1);
	c = static_cast<char>(converter);
	i = static_cast<int>(converter);
	f = static_cast<float>(converter);
	d = static_cast<double>(converter);
	return (0);
}