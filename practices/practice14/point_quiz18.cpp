#include "point_quiz18.h"

std::ostream& operator<<(std::ostream& out, const Point& p) {
	return out << "Point(" << p.m_x << ", " << p.m_y << ')';
}