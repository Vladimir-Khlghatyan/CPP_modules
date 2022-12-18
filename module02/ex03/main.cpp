#include "Point.hpp"

static const std::string	message(bool b)
{
	if (b)
		return ("The point (P) is \33[1;32minside\33[1;37m the triangle ABC.");
	return ("The point (P) is \33[1;31moutside\33[1;37m the triangle ABC.");
}

int	main(void)
{
	Point a(-4.0f, 2.0f);
	Point b(6.0f, 6.0f);
	Point c(-7.5f, -5.75f);

	Point point1(-2.5f, 2.0f);
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;
	std::cout << GREEN << "INPUT1: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point1.getX() << "; " << point1.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT1: ";
	std::cout << WHITE << message(bsp(a, b, c, point1)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	Point point2(6.0f, 3.0f);
	std::cout << GREEN << "INPUT2: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point2.getX() << "; " << point2.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT2: ";
	std::cout << WHITE << message(bsp(a, b, c, point2)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	Point point3(-4.5f, -1.5f);
	std::cout << GREEN << "INPUT3: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point3.getX() << "; " << point3.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT3: ";
	std::cout << WHITE << message(bsp(a, b, c, point3)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	Point point4(2.0f, 4.0f);
	std::cout << GREEN << "INPUT4: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point4.getX() << "; " << point4.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT4: ";
	std::cout << WHITE << message(bsp(a, b, c, point4)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	Point point5(-7.5f, -5.75f);
	std::cout << GREEN << "INPUT5: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point5.getX() << "; " << point5.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT5: ";
	std::cout << WHITE << message(bsp(a, b, c, point5)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	Point point6(2.0f, -4.0f);
	std::cout << GREEN << "INPUT6: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point6.getX() << "; " << point6.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT6: ";
	std::cout << WHITE << message(bsp(a, b, c, point6)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	Point point7(1.0f, 4.0f);
	std::cout << GREEN << "INPUT7: ";
	std::cout << BLUE << "A=(" << a.getX() << "; " << a.getY() << ") ";
	std::cout << BLUE << "B=(" << b.getX() << "; " << b.getY() << ") ";
	std::cout << BLUE << "C=(" << c.getX() << "; " << c.getY() << ") ";
	std::cout << YELLOW << "P=(" << point7.getX() << "; " << point7.getY() << ")" << std::endl;
	std::cout << GREEN << "OUTPUT7: ";
	std::cout << WHITE << message(bsp(a, b, c, point7)) << RESET << std::endl;
	std::cout << YELLOW << "-------------------------------------------------------" << RESET << std::endl;

	return (0);
}
