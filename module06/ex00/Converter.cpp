#include "Converter.hpp"

//==== constructors =====================================================================

Converter::Converter(void) : _argument("nan") {}

Converter::Converter(std::string const &argument) : _argument(argument) {}

Converter::Converter(const Converter &other) : _argument(other._argument) {}

Converter &Converter::operator=(const Converter &other)
{
	if (this != &other)
		this->_argument = other._argument;
	return (*this);
}

Converter::~Converter(void) {}

//==== scalar types overloading =========================================================

static int	ft_valid_argument(std::string argument)
{
	int	dot_cnt = 0;
	int	f_cnt = 0;
	int	e_cnt = 0;
	int	plus_cnt = 0;
	int	minus_cnt = 0;

	if (argument == "-inf"  or argument == "+inf"  or argument == "nan")
		return (2);
	if (argument == "-inff" or argument == "+inff" or argument == "nanf")
		return (3);
	for (unsigned int j = 0; j < argument.length(); j++)
	{
		if (j == 0 and (argument[j] == '-' or argument[j] == '+'))
			continue ;
		if (argument[j] == '.' and !dot_cnt and !f_cnt and !e_cnt and !plus_cnt and !minus_cnt)
		{
				dot_cnt++;
				continue ;
		}
		if (argument[j] == 'f' and !f_cnt and !e_cnt and !plus_cnt and !minus_cnt)
		{
				f_cnt++;
				continue ;
		}
		if ((argument[j] == 'e' or argument[j] == 'E') and !f_cnt and !e_cnt and !plus_cnt and !minus_cnt)
		{
				e_cnt++;
				continue ;
		}
		if (argument[j] == '+' and !f_cnt and !plus_cnt and !minus_cnt)
		{
				plus_cnt++;
				continue ;
		}
		if (argument[j] == '-' and !f_cnt and !plus_cnt and !minus_cnt)
		{
				minus_cnt++;
				continue ;
		}		
		if (!isdigit(argument[j]))
			return (0);
	}
	return (1);
}

Converter::operator char(void)
{
	char	c;
	int		i;

	if (_argument.length() == 1)
	{
		c = _argument[0];
		if (isalpha(c))
			std::cout << "  char: \'" << c << "\'" <<std::endl;
		else
		{
			std::istringstream(_argument) >> i;
			c = static_cast<char>(i);
			if (c < 0)
				std::cout << "  char: impossible" << std::endl;
			else if (isprint(c))
				std::cout << "  char: \'" << c << "\'" <<std::endl;
			else
				std::cout << "  char: Non displayable" << std::endl;
		}
		return (c);
	}
	if (ft_valid_argument(_argument) != 1)
	{
		std::cout << "  char: impossible" << std::endl;
		return (-1);
	}
	std::istringstream(_argument) >> i;
	if (i < CHAR_MIN or i > CHAR_MAX)
	{
		std::cout << "  char: Out of range" << std::endl;
		return (-1);
	}
	c = static_cast<char>(i);
	if (c < 0)
		std::cout << "  char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "  char: \'" << c << "\'" <<std::endl;
	else
		std::cout << "  char: Non displayable" << std::endl;
	return (c);
}

Converter::operator int(void)
{
	long long i;
	if (ft_valid_argument(_argument) != 1)
	{
		std::cout << "   int: impossible" << std::endl;
		return (-1);
	}
	std::istringstream(_argument) >> i;
	if (i < INT_MIN or i > INT_MAX)
	{
		std::cout << "   int: Out of range" << std::endl;
		return (-1);
	};
	std::cout << "   int: " << i <<std::endl;
	return (i);
}


Converter::operator float(void)
{
	double	float_min;
	double	float_max;
	double	f;

	if (ft_valid_argument(_argument) != 1)
	{
		if (ft_valid_argument(_argument) == 0)
			std::cout << " float: impossible" << std::endl;
		else if (ft_valid_argument(_argument) == 2)
			std::cout << " float: " << _argument << "f" << std::endl;
		else if (ft_valid_argument(_argument) == 3)
			std::cout << " float: " << _argument << std::endl;
		return (NAN);
	}

	// float_min = std::numeric_limits<float>::lowest();

	// std::numeric_limits<float>::min() does not give the smallest positive value that can be represented;
	// it gives the smallest normal single-precision floating point number.
	// C++11 added numeric_limits<float>::lowest(), which returns the lowest (negative) value possible for the type float.
	// Since the "lowest()" method is not allowed in the -std=c++98 standard, we will use a numeric value for a 64-bit system.
	float_min = -3.40282e+38; // 
	float_max = std::numeric_limits<float>::max();
	std::istringstream(_argument) >> f;
	if (f < float_min or f > float_max)
	{
		std::cout << " float: Out of range" << std::endl;
		return (NAN);
	};
	std::cout << " float: " << std::fixed << std::setprecision(1) << f << std::endl;
	return (f);
}

Converter::operator double(void)
{
	long double	double_min;
	long double	double_max;
	long double	d;

	if (ft_valid_argument(_argument) != 1)
	{
		if (ft_valid_argument(_argument) == 0)
			std::cout << "double: impossible" << std::endl;
		else if (ft_valid_argument(_argument) == 2)
			std::cout << "double: " << _argument << std::endl;
		else if (ft_valid_argument(_argument) == 3)
			std::cout << "double: " << _argument.substr(0, _argument.length() - 1) << std::endl;
		return (NAN);
	}

	// double_min = std::numeric_limits<double>::lowest();

	// std::numeric_limits<double>::min() does not give the smallest positive value that can be represented;
	// it gives the smallest normal single-precision floating point number.
	// C++11 added numeric_limits<double>::lowest(), which returns the lowest (negative) value possible for the type double.
	// Since the "lowest()" method is not allowed in the -std=c++98 standard, we will use a numeric value for a 64-bit system.

	double_min = -1.79769e+308;
	double_max = std::numeric_limits<double>::max();
	std::istringstream(_argument) >> d;
	if (d < double_min or d > double_max)
	{
		std::cout << "double: Out of range" << std::endl;
		return (NAN);
	};
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "f" << std::endl;
	return (d);
}
