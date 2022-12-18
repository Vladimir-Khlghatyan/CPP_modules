#include "Point.hpp"

static bool check(Point const p1, Point const p2, Point const dot, Point const point)
{
	// We check whether the points "dot" and "point" are on the same side
	// of the line passing through the points "p1" and "p2"

	bool b1 = ((dot.getX() - p1.getX()) * (p2.getY() - p1.getY()) > \
		 	   (dot.getY() - p1.getY()) * (p2.getX() - p1.getX()));
	bool b2 = ((point.getX() - p1.getX()) * (p2.getY() - p1.getY()) > \
		       (point.getY() - p1.getY()) * (p2.getX() - p1.getX()));
	if (b1 and b2)
		return (true);
	b1 = ((dot.getX() - p1.getX()) * (p2.getY() - p1.getY()) < \
		 (dot.getY() - p1.getY()) * (p2.getX() - p1.getX()));
	b2 = ((point.getX() - p1.getX()) * (p2.getY() - p1.getY()) < \
		 (point.getY() - p1.getY()) * (p2.getX() - p1.getX()));
	if (b1 and b2)
		return (true);
	return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (check(a, b, c, point) and \
		check(b, c, a, point) and \
		check(a, c, b, point))
		return (true);
	return (false);
}
