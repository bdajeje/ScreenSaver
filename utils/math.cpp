#include "math.hpp"

#include <stdlib.h>

namespace utils {

int random(int min, int max)
{
  return rand() % (max - min) + min;
}

bool pointInTriangle(const Point2D& p, const Point2D& a, const Point2D& b, const Point2D& c)
{
	auto sign = [&](const Point2D& a, const Point2D& b, const Point2D& c) -> bool {
		 return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
	};

	return sign(p, a, b) >= 0 && sign(p, b, c) >= 0 && sign(p, c, a) >= 0;
}

}
