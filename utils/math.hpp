#ifndef MATH_HPP
#define MATH_HPP

namespace utils {

struct Point2D {
	Point2D() = default;

	Point2D(int x, int y)
		: x {x}
		, y {y}
	{}

	int x {0};
	int y {0};
};

int random(int min, int max);

/* Find is a given point is inside a triangle
 * \param point - to test
 * \param a - first point of the triangle
 * \param b - second point of the triangle
 * \param c - third point of the triangle
 */
bool pointInTriangle(const Point2D& point, const Point2D& a, const Point2D& b, const Point2D& c);

} // utils

#endif // MATH_HPP
