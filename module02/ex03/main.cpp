#include "Point.hpp"

static const std::string	message(bool b)
{
	if (b)
		return ("The point (P) is \33[1;32minside\33[1;37m the triangle ABC.");
	return ("The point (P) is \33[1;31moutside\33[1;37m the triangle ABC.");
}

static void	print_test(Point const a, Point const b, Point const c, Point const point)
{
	static int	index;

	if (!index)
		std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;
	std::cout << GREEN << "INPUT" << ++index << ": ";
	std::cout << CYAN << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << CYAN << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << CYAN << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point.getX() << "; " << point.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT" << index << ": ";
	std::cout << WHITE << message(bsp(a, b, c, point)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;
}

int	main(void)
{
	Point a(-4.0f, 2.0f);
	Point b(6.0f, 6.0f);
	Point c(-7.5f, -5.75f);	

	print_test(a, b, c, Point(-2.5f, 2.0f));	
	print_test(a, b, c, Point(6.0f, 3.0f));
	print_test(a, b, c, Point(-4.5f, -1.5f));
	print_test(a, b, c, Point(2.0f, 4.0f));
	print_test(a, b, c, Point(-7.5f, -5.75f));
	print_test(a, b, c, Point(2.0f, -4.0f));
	print_test(a, b, c, Point(1.0f, 4.0f));
	print_test(a, b, c, Point(-9.0f, 7.0f));

	return (0);
}
