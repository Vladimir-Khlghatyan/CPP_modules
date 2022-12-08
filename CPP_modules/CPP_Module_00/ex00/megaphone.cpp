
#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < ac; i++)
			for (unsigned long j = 0; j < strlen(av[i]); j++)
				std::cout << (char)toupper(av[i][j]);
	std::cout << std::endl;
	return (0);
}

// This is not an optimal implementation of the task,
// but the "new" and "delete" functions were used here.

// #include <iostream>
// #include <cstring>

// char	*ft_toupper(const char *str)
// {
// 	int	len = strlen(str);
// 	char *new_str = new char[len];
// 	if (!str || !new_str)
// 		return (NULL);
// 	for (int i = 0; i < len; i++)
// 		new_str[i] = toupper(str[i]);
// 	new_str[len] = '\0';
// 	return (new_str);
// }

// int	main(int ac, char **av)
// {
// 	char *uppercase_str;

// 	if (ac == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
// 	else
// 		for (int i = 1; i < ac; i++)
// 		{
// 			uppercase_str = ft_toupper(av[i]);
// 			std::cout << uppercase_str;
// 			delete uppercase_str;
// 		}
// 	std::cout << std::endl;
// 	return (0);
// }
